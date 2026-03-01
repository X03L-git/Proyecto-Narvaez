

import skimage.io as io
#from skimage.color import rgb2gray, rgba2rgb ## added
import matplotlib.pyplot as plt
import numpy as np
from skimage.exposure import histogram
from matplotlib.pyplot import bar
from skimage.color import rgb2gray
from skimage.filters import threshold_otsu, gaussian, median
from skimage.morphology import opening, closing, dilation, erosion, skeletonize, disk
# `square` (used for structuring elements) is deprecated; use footprint_rectangle
from skimage.morphology import footprint_rectangle

# wrapper that behaves like the old `square` and accepts a single int
# (or numpy int); the newer footprint_rectangle requires a shape tuple.
def square(size):
    # allow scalar or 1-element iterables
    if isinstance(size, (np.integer, int)):
        sz = int(size)
        return footprint_rectangle((sz, sz))
    # if a tuple/list already provided, forward it
    return footprint_rectangle(size)

# provide compatibility wrappers named like the old functions so that
# existing code (including notebooks) can remain unchanged without
# triggering FutureWarnings.

def binary_opening(img, footprint):
    return opening(img, footprint)

def binary_closing(img, footprint):
    return closing(img, footprint)

def binary_dilation(img, footprint):
    return dilation(img, footprint)

def binary_erosion(img, footprint):
    return erosion(img, footprint)
from skimage.feature import canny
from skimage.transform import resize


def show_images(images, titles=None):
    n_ims = len(images)
    if titles is None:
        titles = ['(%d)' % i for i in range(1, n_ims + 1)]
    fig = plt.figure()
    n = 1
    for image, title in zip(images, titles):
        a = fig.add_subplot(1, n_ims, n)
        if image.ndim == 2:
            plt.gray()
        plt.imshow(image)
        a.set_title(title)
        plt.axis('off')
        n += 1
    fig.set_size_inches(np.array(fig.get_size_inches()) * n_ims)
    plt.show()


def showHist(img):
    plt.figure()
    imgHist = histogram(img, nbins=256)

    bar(imgHist[1].astype(np.uint8), imgHist[0], width=0.8, align='center')


def gray_img(img):
    '''
    img: rgb image (o rgba)
    return: gray image, pixel values 0:255
    '''
    # Si ya es escala de grises (2D), retornarla normalizada
    if len(img.shape) == 2:
        return img
    
    img_copy = np.copy(img)
    # Si es RGBA (4 canales), convertir a RGB
    if len(img_copy.shape) == 3 and img_copy.shape[2] == 4:
        img_copy = img_copy[:, :, :3]
    
    gray = rgb2gray(img_copy)
    gray = gray * 255
    return gray



def otsu(img):
    '''
    Otsu with gaussian
    img: gray image
    return: binary image, pixel values 0:1
    '''
    blur = gaussian(img)
    otsu_bin = 255*(blur > threshold_otsu(blur))
    return (otsu_bin/255).astype(np.int32)


def get_gray(img):
    img_copy = np.copy(img)
    # Si ya es escala de grises (2D), retornarla tal cual
    if len(img_copy.shape) == 2:
        return img_copy
    # Si es RGBA (4 canales), convertir a RGB
    if len(img_copy.shape) == 3 and img_copy.shape[2] == 4:
        img_copy = img_copy[:, :, :3]
    # Convertir a escala de grises si tiene canales
    if len(img_copy.shape) == 3:
        gray = rgb2gray(img_copy)
        return gray
    return img_copy


def get_thresholded(img, thresh):
    return 1*(img > thresh)


def histogram(img, thresh):
    hist = (np.ones(img.shape) - img).sum(dtype=np.int32, axis=1)
    _max = np.amax(hist)
    hist[hist[:] < _max * thresh] = 0
    return hist


def get_line_indices(hist):
    indices = []
    prev = 0
    for index, val in enumerate(hist):
        if val > 0 and prev <= 0:
            indices.append(index)
        prev = val
    return indices


def get_region_lines_indices(self, region):
    indices = get_line_indices(histogram(region, 0.8))
    lines = []
    for line_index in indices:
        line = []
        for k in range(self.thickness):
            line.append(line_index+k)
        lines.append(line)
    self.rows.append([np.average(x) for x in lines])
