#include "Algoritmo.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define NUM_CUERDAS 6

const int lut[6][13] = {
    {5,6,7,8,9,10,11,12,1,2,3,4,5},
    {12,1,2,3,4,5,6,7,8,9,10,11,12},
    {8,9,10,11,12,1,2,3,4,5,6,7,8},
    {3,4,5,6,7,8,9,10,11,12,1,2,3},
    {10,11,12,1,2,3,4,5,6,7,8,9,10},
    {5,6,7,8,9,10,11,12,1,2,3,4,5}
};

salida* precondiciones (salida out, int in[6], salida* salida_a_escribir) {
    bool anterior_no_presionada_ninguna = false;//Si es el caso se priorizará las agudas
    bool anterior_solo = false;
    bool anterior_acorde = false;
    bool salida_solo = false;
    bool salida_acorde = false;
// No podemos comprobar si es silencio ->¡Tablatura!
    int array_1[6];

    for (int i = 0; i < 6; i++) {
        array_1[i] = out[i];
    }

    for (int i = 0; i < 6; i++) {
        if (array_1[i] > -1) {
            array_1[i] = 0;
        }
    }

    int sum = 0;

    for (int i = 0; i < 6; i++) {
        sum = sum + array_1[i];
    }

    if (sum > -5) {
        anterior_acorde = true;
    }

    if (sum == -5) {
        anterior_solo = true;
    }

    if (sum == -6) {
        anterior_no_presionada_ninguna = true;
    }

    int array_2[6];

    for (int i = 0; i < 6; i++) {
        array_1[i] = in[i];
    }

    for (int i = 0; i < 6; i++) {
        if (array_2[i] > 1) {
            array_2[i] = 1;
        }
    }

    sum = 0;

    for (int i = 0; i < 6; i++) {
        sum = sum + array_2[i];
    }

    if (sum == 1) {
        salida_solo = true;
    }

    if (sum > 1) {
        salida_acorde = true;
    }

    if (anterior_no_presionada_ninguna && salida_solo) {
        anterior_no_presionada_actual_simple (out, in, salida_a_escribir);
    }
    if (anterior_solo && salida_solo) {
        anterior_presionada_actual_simple (out, in, salida_a_escribir);
    }
    if (anterior_acorde && salida_solo) {
        anterior_acorde_actual_simple(out, in, salida_a_escribir);
    }
    if (anterior_no_presionada_ninguna && salida_acorde) {
        anterior_no_presionada_actual_simple (out, in, salida_a_escribir);
    }
    if (anterior_solo && salida_acorde) {
        anterior_presionada_actual_simple (out, in, salida_a_escribir);
    }
    if (anterior_acorde && salida_acorde) {
        anterior_acorde_actual_simple(out, in, salida_a_escribir);
    }

    return salida_a_escribir;

}

salida* anterior_no_presionada_actual_simple (salida out_anterior, entrada in, salida* salida_a_escribir) {
    bool matriz_de_coincidencias[6][13];
    int x = 0;
    int y = 0;

    int valor_a_guardar = 0;
    for (int i = 0; i < 6; i++) {
        if (in[i] > 0) {
            valor_a_guardar = in[i];
        }
    }

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 13; j++) {
            matriz_de_coincidencias[i][j] = (lut[i][j] == valor_a_guardar);
        }
    }

    int sum = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 13; j++) {
            if (matriz_de_coincidencias[i][j] == true){
                sum++;
            }
        }
    }

    int cont = 0;
    srand(time(NULL));
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 13; j++) {
            if (matriz_de_coincidencias[i][j] == true){
                cont ++;
                if (rand()%sum == 0){
                     x = i;
                     y = j;
                }
                if (cont == sum) {
                     x = i;
                     y = j;
                }
            }
        }
    }
    salida out;
    for (int i = 0; i < 6; i++) {
        out[i]= -1;
    }
    out[x] = y;

    for (int patata = 0; patata < 6; patata++) {
        *salida_a_escribir[patata] = out[patata];
    }

    return salida_a_escribir;
}


salida* anterior_presionada_actual_simple (salida out_anterior, entrada in, salida* salida_a_escribir) {
    bool matriz_de_coincidencias[6][13];
    double matriz_de_distancias[6][13];
    salida out_a_dar;
    for (int i = 0; i < 6; i++) {
        out_a_dar[i]= -1;
    }


    for (int i = 0; i < 6; i++) {
        out_a_dar[i]= 0;
    }

    int valor_a_guardar = 0;
    for (int i = 0; i < 6; i++) {
        if (in[i] > 0) {
            valor_a_guardar = in[i];
        }
    }


    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 13; j++) {
            matriz_de_coincidencias[i][j] = (lut[i][j] == valor_a_guardar);
        }
    }

    int y_de_inicio = 0;
    int x_de_inicio = 0;

    for (int i = 0; i < 6; i++) {
        if (out_anterior[i] > -1) {
            x_de_inicio = i;
            y_de_inicio = out_anterior[i];
        }
    }

    double sumatorio_de_distancias = 0;

    if (matriz_de_coincidencias[x_de_inicio][y_de_inicio] == true) {
        out_a_dar[x_de_inicio]= y_de_inicio;
        for (int i = 0; i < 6; i++) {
            *salida_a_escribir[i] = out_a_dar[i];
        }

        return salida_a_escribir;
    }


    else {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 13; j++) {
                if (matriz_de_coincidencias[i][j] == true) {
                    matriz_de_distancias[i][j]= abs(i - x_de_inicio) * abs(i - x_de_inicio) +abs(y_de_inicio)*abs(y_de_inicio);//¡Pitágoras!
                    sumatorio_de_distancias = matriz_de_distancias[i][j] + sumatorio_de_distancias;
                }

            }
        }

        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 13; j++) {
                if (matriz_de_coincidencias[i][j] == true) {
                    matriz_de_distancias[i][j]= matriz_de_distancias[i][j]/sumatorio_de_distancias;
                }

            }
        }
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 13; j++) {
                if (matriz_de_coincidencias[i][j] == true) {
                    matriz_de_distancias[i][j] = floor(matriz_de_distancias[i][j]);
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 13; j++) {
                if (matriz_de_coincidencias[i][j] == true) {
                    sum = sum + matriz_de_distancias[i][j];
                }
            }
        }

        srand(time(NULL));
        int num_rand = rand()%sum;

        sum = 0;
        int sum_anterior = 0;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 13; j++) {
                if (matriz_de_coincidencias[i][j] == true) {
                    sum = sum + matriz_de_distancias[i][j];
                    if (num_rand >= sum_anterior && num_rand < sum) {
                        out_a_dar[i] = j;


                        for (int patata = 0; patata < 6; patata++) {
                            *salida_a_escribir[patata] = out_a_dar[patata];
                        }

                        return salida_a_escribir;
                    }
                    sum_anterior = sum;
                }
            }
        }
    }
}

salida* anterior_acorde_actual_simple (salida out_anterior, entrada in, salida* salida_a_escribir){
    bool matriz_de_coincidencias[6][13];
    double matriz_de_distancias[6][13];
    salida out_a_dar;
    for (int i = 0; i < 6; i++) {
        out_a_dar[i]= -1;
    }

    for (int i = 0; i < 6; i++) {
        out_a_dar[i]= 0;
    }

    int valor_a_guardar = 0;
    for (int i = 0; i < 6; i++) {
        if (in[i] > 0) {
            valor_a_guardar = in[i];
        }
    }


    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 13; j++) {
            matriz_de_coincidencias[i][j] = (lut[i][j] == valor_a_guardar);
        }
    }

    double sumatorio_y_de_inicio = 0;
    double sumatorio_x_de_inicio = 0;
    int contador = 0;

    for (int i = 0; i < 6; i++) {//Sólo cambia esto en relación a la del anterior

        if (out_anterior[i] > -1) {
            contador++;
            sumatorio_x_de_inicio = (double)i;
            sumatorio_y_de_inicio = (double)out_anterior[i];
        }
    }
    sumatorio_y_de_inicio = sumatorio_y_de_inicio/(double)contador;
    sumatorio_x_de_inicio = sumatorio_x_de_inicio/(double)contador;

    int y_de_inicio = floor (sumatorio_y_de_inicio);
    int x_de_inicio = floor (sumatorio_x_de_inicio);

    double sumatorio_de_distancias = 0;

    if (matriz_de_coincidencias[x_de_inicio][y_de_inicio] == true) {
        out_a_dar[x_de_inicio]= y_de_inicio;
        for (int patata = 0; patata < 6; patata++) {
            *salida_a_escribir[patata] = out_a_dar[patata];
        }

        return salida_a_escribir;
    }


    else {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 13; j++) {
                if (matriz_de_coincidencias[i][j] == true) {
                    matriz_de_distancias[i][j]= abs(i-x_de_inicio)*abs(i-x_de_inicio)+abs(y_de_inicio)*abs(y_de_inicio);//¡Pitágoras!
                    sumatorio_de_distancias = matriz_de_distancias[i][j] + sumatorio_de_distancias;
                }

            }
        }

        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 13; j++) {
                if (matriz_de_coincidencias[i][j] == true) {
                    matriz_de_distancias[i][j]= matriz_de_distancias[i][j]/sumatorio_de_distancias;
                }

            }
        }
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 13; j++) {
                if (matriz_de_coincidencias[i][j] == true) {
                    matriz_de_distancias[i][j] = floor(matriz_de_distancias[i][j]);
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 13; j++) {
                if (matriz_de_coincidencias[i][j] == true) {
                    sum = sum + matriz_de_distancias[i][j];
                }
            }
        }

        srand(time(NULL));
        int num_rand = rand()%sum;

        sum = 0;
        int sum_anterior = 0;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 13; j++) {
                if (matriz_de_coincidencias[i][j] == true) {
                    sum = sum + matriz_de_distancias[i][j];
                    if (num_rand >= sum_anterior && num_rand < sum) {
                        out_a_dar[i] = j;
                        for (int patata = 0; patata < 6; patata++) {
                            *salida_a_escribir[patata] = out_a_dar[patata];
                        }

                        return salida_a_escribir;
                    }
                    sum_anterior = sum;
                }
            }
        }
    }
}

salida* anterior_no_presionada_actual_acorde (salida out, entrada in, salida* salida_a_escribir) {
    bool matriz_de_coincidencias_1[6][13];
    int x_aproximada = 3;
    int y_aproximada = 2;

    int contador1 = 0;
    if (in[0]!= 0) {
        int i = 0;
        for (int j = 0; j < 13; j++) {
            if (lut[i][j]== in[0]) {
                contador1++;
                matriz_de_coincidencias_1[i][j] = true;
            }
        }

    }
    bool matriz_de_coincidencias_2[6][13];
    int contador2 = 0;
    if (in[1]!= 0) {
        int i = 1;
        for (int j = 0; j < 13; j++) {
            if (lut[i][j]== in[1]) {
                contador2++;
                matriz_de_coincidencias_2[i][j] = true;
            }
        }

    }
    bool matriz_de_coincidencias_3[6][13];
    int contador3 = 0;
    if (in[2]!= 0) {
        int i = 2;
        for (int j = 0; j < 13; j++) {
            if (lut[i][j]== in[2]) {
                contador3++;
                matriz_de_coincidencias_3[i][j] = true;
            }
        }
    }
    bool matriz_de_coincidencias_4[6][13];
    int contador4 = 0;
    if (in[3]!= 0) {
        int i = 3;
        for (int j = 0; j < 13; j++) {
            if (lut[i][j]== in[3]) {
                contador4++;
                matriz_de_coincidencias_4[i][j] = true;
            }
        }

    }
    bool matriz_de_coincidencias_5[6][13];
    int contador5 = 0;
    if (in[4]!= 0) {
        int i = 4;
        for (int j = 0; j < 13; j++) {
            if (lut[i][j]== in[4]) {
                contador5++;
                matriz_de_coincidencias_5[i][j] = true;
            }
        }

    }
    bool matriz_de_coincidencias_6[6][13];
    int contador6 = 0;
    if (in[5]!= 0) {
        int i = 5;
        for (int j = 0; j < 13; j++) {
            if (lut[i][j]== in[5]) {
                contador6++;
                matriz_de_coincidencias_6[i][j] = true;
            }
        }

    }
    int y = 0;
    //Cogemos en una posición alta aleatoria en el primer elemento disponible


    float array0[13];
    float array1[13];
    float array2[13];
    float array3[13];
    float array4[13];
    float array5[13];



    if (in[0] != 0) {
        //Busca la posición más cercana a la x e y aproximada3
        int patatin = 0;

        for (int patata = 0; patata < 13; patata++) {
            if (matriz_de_coincidencias_1[patatin][patata]== true) {
                array0[patatin] = abs(patatin-x_aproximada)*abs(patatin-x_aproximada) + abs(y_aproximada-patata)*abs(y_aproximada-patata) ;
            }
        }

        int n = contador1;

        for(int i = 0; i < n-1; i++) {
            for(int j = 0; j < n-i-1; j++) {
                if(array0[j] > array0[j+1]) {
                    int temp = array0[j];
                    array0[j] = array0[j+1];
                    array0[j+1] = temp;
                }
            }
        }

        *salida_a_escribir[0] = array0[0];
    }
    if (in[1] != 0) {
        //Busca la posición más cercana a la x e y aproximada3
        int patatin = 1;

        for (int patata = 0; patata < 13; patata++) {
            if (matriz_de_coincidencias_1[patatin][patata]== true) {
                array1[patatin] = abs(patatin-x_aproximada)*abs(patatin-x_aproximada) + abs(y_aproximada-patata)*abs(y_aproximada-patata) ;
            }
        }

        int n = contador2;

        for(int i = 0; i < n-1; i++) {
            for(int j = 0; j < n-i-1; j++) {
                if(array1[j] > array1[j+1]) {
                    int temp = array1[j];
                    array1[j] = array1[j+1];
                    array1[j+1] = temp;
                }
            }
        }
        *salida_a_escribir[1] = array1[0];
    }

    if (in[2] != 0) {
        //Busca la posición más cercana a la x e y aproximada3
        int patatin = 2;

        for (int patata = 0; patata < 13; patata++) {
            if (matriz_de_coincidencias_1[patatin][patata]== true) {
                array2[patatin] = abs(patatin-x_aproximada)*abs(patatin-x_aproximada) + abs(y_aproximada-patata)*abs(y_aproximada-patata) ;
            }
        }

        int n = contador2;

        for(int i = 0; i < n-1; i++) {
            for(int j = 0; j < n-i-1; j++) {
                if(array2[j] > array2[j+1]) {
                    int temp = array2[j];
                    array2[j] = array2[j+1];
                    array2[j+1] = temp;
                }
            }
        }
        *salida_a_escribir[2] = array2[0];
    }

    if (in[3] != 0) {
        //Busca la posición más cercana a la x e y aproximada3
        int patatin = 2;

        for (int patata = 0; patata < 13; patata++) {
            if (matriz_de_coincidencias_1[patatin][patata]== true) {
                array3[patatin] = abs(patatin-x_aproximada)*abs(patatin-x_aproximada) + abs(y_aproximada-patata)*abs(y_aproximada-patata) ;
            }
        }

        int n = contador3;

        for(int i = 0; i < n-1; i++) {
            for(int j = 0; j < n-i-1; j++) {
                if(array3[j] > array3[j+1]) {
                    int temp = array3[j];
                    array3[j] = array3[j+1];
                    array3[j+1] = temp;
                }
            }
        }
        *salida_a_escribir[3] = array3[0];
    }
    if (in[4] != 0) {
        //Busca la posición más cercana a la x e y aproximada3
        int patatin = 4;

        for (int patata = 0; patata < 13; patata++) {
            if (matriz_de_coincidencias_1[patatin][patata]== true) {
                array4[patatin] = abs(patatin-x_aproximada)*abs(patatin-x_aproximada) + abs(y_aproximada-patata)*abs(y_aproximada-patata) ;
            }
        }

        int n = contador4;

        for(int i = 0; i < n-1; i++) {
            for(int j = 0; j < n-i-1; j++) {
                if(array4[j] > array4[j+1]) {
                    int temp = array4[j];
                    array4[j] = array4[j+1];
                    array4[j+1] = temp;
                }
            }
        }
        *salida_a_escribir[4] = array4[0];
    }
    if (in[5] != 0) {
        //Busca la posición más cercana a la x e y aproximada3
        int patatin = 5;

        for (int patata = 0; patata < 13; patata++) {
            if (matriz_de_coincidencias_1[patatin][patata]== true) {
                array5[patatin] = abs(patatin-x_aproximada)*abs(patatin-x_aproximada) + abs(y_aproximada-patata)*abs(y_aproximada-patata) ;
            }
        }

        int n = contador5;

        for(int i = 0; i < n-1; i++) {
            for(int j = 0; j < n-i-1; j++) {
                if(array5[j] > array5[j+1]) {
                    int temp = array5[j];
                    array5[j] = array5[j+1];
                    array5[j+1] = temp;
                }
            }
        }
        *salida_a_escribir[5] = array5[0];
    }


    //TODO: añadir soporte para cejillas

}


salida* anterior_presionada_actual_acorde (salida out, entrada in, salida* salida_a_escribir) {
    bool matriz_de_coincidencias_1[6][13];
    //Lo único que cambia frente a la anterior
    int otra_x = 0;
    int otra_y = 0;

    for (int i = 0; i < 6; i++) {
        if (out[i] != -1) {
            otra_y = out[i];
            otra_x = i;
        }
    }


    int x_aproximada = otra_x;
    int y_aproximada = otra_y;

    int contador1 = 0;
    if (in[0]!= 0) {
        int i = 0;
        for (int j = 0; j < 13; j++) {
            if (lut[i][j]== in[0]) {
                contador1++;
                matriz_de_coincidencias_1[i][j] = true;
            }
        }

    }
    bool matriz_de_coincidencias_2[6][13];
    int contador2 = 0;
    if (in[1]!= 0) {
        int i = 1;
        for (int j = 0; j < 13; j++) {
            if (lut[i][j]== in[1]) {
                contador2++;
                matriz_de_coincidencias_2[i][j] = true;
            }
        }

    }
    bool matriz_de_coincidencias_3[6][13];
    int contador3 = 0;
    if (in[2]!= 0) {
        int i = 2;
        for (int j = 0; j < 13; j++) {
            if (lut[i][j]== in[2]) {
                contador3++;
                matriz_de_coincidencias_3[i][j] = true;
            }
        }
    }
    bool matriz_de_coincidencias_4[6][13];
    int contador4 = 0;
    if (in[3]!= 0) {
        int i = 3;
        for (int j = 0; j < 13; j++) {
            if (lut[i][j]== in[3]) {
                contador4++;
                matriz_de_coincidencias_4[i][j] = true;
            }
        }

    }
    bool matriz_de_coincidencias_5[6][13];
    int contador5 = 0;
    if (in[4]!= 0) {
        int i = 4;
        for (int j = 0; j < 13; j++) {
            if (lut[i][j]== in[4]) {
                contador5++;
                matriz_de_coincidencias_5[i][j] = true;
            }
        }

    }
    bool matriz_de_coincidencias_6[6][13];
    int contador6 = 0;
    if (in[5]!= 0) {
        int i = 5;
        for (int j = 0; j < 13; j++) {
            if (lut[i][j]== in[5]) {
                contador6++;
                matriz_de_coincidencias_6[i][j] = true;
            }
        }

    }
    int y = 0;
    //Cogemos en una posición alta aleatoria en el primer elemento disponible


    float array0[13];
    float array1[13];
    float array2[13];
    float array3[13];
    float array4[13];
    float array5[13];



    if (in[0] != 0) {
        //Busca la posición más cercana a la x e y aproximada3
        int patatin = 0;

        for (int patata = 0; patata < 13; patata++) {
            if (matriz_de_coincidencias_1[patatin][patata]== true) {
                array0[patatin] = abs(patatin-x_aproximada)*abs(patatin-x_aproximada) + abs(y_aproximada-patata)*abs(y_aproximada-patata) ;
            }
        }

        int n = contador1;

        for(int i = 0; i < n-1; i++) {
            for(int j = 0; j < n-i-1; j++) {
                if(array0[j] > array0[j+1]) {
                    int temp = array0[j];
                    array0[j] = array0[j+1];
                    array0[j+1] = temp;
                }
            }
        }

        *salida_a_escribir[0] = array0[0];
    }
    if (in[1] != 0) {
        //Busca la posición más cercana a la x e y aproximada3
        int patatin = 1;

        for (int patata = 0; patata < 13; patata++) {
            if (matriz_de_coincidencias_1[patatin][patata]== true) {
                array1[patatin] = abs(patatin-x_aproximada)*abs(patatin-x_aproximada) + abs(y_aproximada-patata)*abs(y_aproximada-patata) ;
            }
        }

        int n = contador2;

        for(int i = 0; i < n-1; i++) {
            for(int j = 0; j < n-i-1; j++) {
                if(array1[j] > array1[j+1]) {
                    int temp = array1[j];
                    array1[j] = array1[j+1];
                    array1[j+1] = temp;
                }
            }
        }
        *salida_a_escribir[1] = array1[0];
    }

    if (in[2] != 0) {
        //Busca la posición más cercana a la x e y aproximada3
        int patatin = 2;

        for (int patata = 0; patata < 13; patata++) {
            if (matriz_de_coincidencias_1[patatin][patata]== true) {
                array2[patatin] = abs(patatin-x_aproximada)*abs(patatin-x_aproximada) + abs(y_aproximada-patata)*abs(y_aproximada-patata) ;
            }
        }

        int n = contador2;

        for(int i = 0; i < n-1; i++) {
            for(int j = 0; j < n-i-1; j++) {
                if(array2[j] > array2[j+1]) {
                    int temp = array2[j];
                    array2[j] = array2[j+1];
                    array2[j+1] = temp;
                }
            }
        }
        *salida_a_escribir[2] = array2[0];
    }

    if (in[3] != 0) {
        //Busca la posición más cercana a la x e y aproximada3
        int patatin = 2;

        for (int patata = 0; patata < 13; patata++) {
            if (matriz_de_coincidencias_1[patatin][patata]== true) {
                array3[patatin] = abs(patatin-x_aproximada)*abs(patatin-x_aproximada) + abs(y_aproximada-patata)*abs(y_aproximada-patata) ;
            }
        }

        int n = contador3;

        for(int i = 0; i < n-1; i++) {
            for(int j = 0; j < n-i-1; j++) {
                if(array3[j] > array3[j+1]) {
                    int temp = array3[j];
                    array3[j] = array3[j+1];
                    array3[j+1] = temp;
                }
            }
        }
        *salida_a_escribir[3] = array3[0];
    }
    if (in[4] != 0) {
        //Busca la posición más cercana a la x e y aproximada3
        int patatin = 4;

        for (int patata = 0; patata < 13; patata++) {
            if (matriz_de_coincidencias_1[patatin][patata]== true) {
                array4[patatin] = abs(patatin-x_aproximada)*abs(patatin-x_aproximada) + abs(y_aproximada-patata)*abs(y_aproximada-patata) ;
            }
        }

        int n = contador4;

        for(int i = 0; i < n-1; i++) {
            for(int j = 0; j < n-i-1; j++) {
                if(array4[j] > array4[j+1]) {
                    int temp = array4[j];
                    array4[j] = array4[j+1];
                    array4[j+1] = temp;
                }
            }
        }
        *salida_a_escribir[4] = array4[0];
    }
    if (in[5] != 0) {
        //Busca la posición más cercana a la x e y aproximada3
        int patatin = 5;

        for (int patata = 0; patata < 13; patata++) {
            if (matriz_de_coincidencias_1[patatin][patata]== true) {
                array5[patatin] = abs(patatin-x_aproximada)*abs(patatin-x_aproximada) + abs(y_aproximada-patata)*abs(y_aproximada-patata) ;
            }
        }

        int n = contador5;

        for(int i = 0; i < n-1; i++) {
            for(int j = 0; j < n-i-1; j++) {
                if(array5[j] > array5[j+1]) {
                    int temp = array5[j];
                    array5[j] = array5[j+1];
                    array5[j+1] = temp;
                }
            }
        }
        *salida_a_escribir[5] = array5[0];
    }


    //TODO: añadir soporte para cejillas

}


salida* anterior_acorde_actual_acorde (salida out, entrada in, salida* salida_a_escribir) {
    bool matriz_de_coincidencias_1[6][13];
    //Lo único que cambia frente a la anterior
    int sumatorio_x = 0;
    int sumatorio_y = 0;
    int contador = 0;

    for (int i = 0; i < 6; i++) {
        if (out[i] != -1) {
            sumatorio_x = out[i]+ sumatorio_x;
            sumatorio_y = i+sumatorio_y;
            contador++;
        }
    }


    int x_aproximada = sumatorio_x/contador;
    int y_aproximada = sumatorio_y/contador;

    int contador1 = 0;
    if (in[0]!= 0) {
        int i = 0;
        for (int j = 0; j < 13; j++) {
            if (lut[i][j]== in[0]) {
                contador1++;
                matriz_de_coincidencias_1[i][j] = true;
            }
        }

    }
    bool matriz_de_coincidencias_2[6][13];
    int contador2 = 0;
    if (in[1]!= 0) {
        int i = 1;
        for (int j = 0; j < 13; j++) {
            if (lut[i][j]== in[1]) {
                contador2++;
                matriz_de_coincidencias_2[i][j] = true;
            }
        }

    }
    bool matriz_de_coincidencias_3[6][13];
    int contador3 = 0;
    if (in[2]!= 0) {
        int i = 2;
        for (int j = 0; j < 13; j++) {
            if (lut[i][j]== in[2]) {
                contador3++;
                matriz_de_coincidencias_3[i][j] = true;
            }
        }
    }
    bool matriz_de_coincidencias_4[6][13];
    int contador4 = 0;
    if (in[3]!= 0) {
        int i = 3;
        for (int j = 0; j < 13; j++) {
            if (lut[i][j]== in[3]) {
                contador4++;
                matriz_de_coincidencias_4[i][j] = true;
            }
        }

    }
    bool matriz_de_coincidencias_5[6][13];
    int contador5 = 0;
    if (in[4]!= 0) {
        int i = 4;
        for (int j = 0; j < 13; j++) {
            if (lut[i][j]== in[4]) {
                contador5++;
                matriz_de_coincidencias_5[i][j] = true;
            }
        }

    }
    bool matriz_de_coincidencias_6[6][13];
    int contador6 = 0;
    if (in[5]!= 0) {
        int i = 5;
        for (int j = 0; j < 13; j++) {
            if (lut[i][j]== in[5]) {
                contador6++;
                matriz_de_coincidencias_6[i][j] = true;
            }
        }

    }
    int y = 0;
    //Cogemos en una posición alta aleatoria en el primer elemento disponible


    float array0[13];
    float array1[13];
    float array2[13];
    float array3[13];
    float array4[13];
    float array5[13];



    if (in[0] != 0) {
        //Busca la posición más cercana a la x e y aproximada3
        int patatin = 0;

        for (int patata = 0; patata < 13; patata++) {
            if (matriz_de_coincidencias_1[patatin][patata]== true) {
                array0[patatin] = abs(patatin-x_aproximada)*abs(patatin-x_aproximada) + abs(y_aproximada-patata)*abs(y_aproximada-patata) ;
            }
        }

        int n = contador1;

        for(int i = 0; i < n-1; i++) {
            for(int j = 0; j < n-i-1; j++) {
                if(array0[j] > array0[j+1]) {
                    int temp = array0[j];
                    array0[j] = array0[j+1];
                    array0[j+1] = temp;
                }
            }
        }

        *salida_a_escribir[0] = array0[0];
    }
    if (in[1] != 0) {
        //Busca la posición más cercana a la x e y aproximada3
        int patatin = 1;

        for (int patata = 0; patata < 13; patata++) {
            if (matriz_de_coincidencias_1[patatin][patata]== true) {
                array1[patatin] = abs(patatin-x_aproximada)*abs(patatin-x_aproximada) + abs(y_aproximada-patata)*abs(y_aproximada-patata) ;
            }
        }

        int n = contador2;

        for(int i = 0; i < n-1; i++) {
            for(int j = 0; j < n-i-1; j++) {
                if(array1[j] > array1[j+1]) {
                    int temp = array1[j];
                    array1[j] = array1[j+1];
                    array1[j+1] = temp;
                }
            }
        }
        *salida_a_escribir[1] = array1[0];
    }

    if (in[2] != 0) {
        //Busca la posición más cercana a la x e y aproximada3
        int patatin = 2;

        for (int patata = 0; patata < 13; patata++) {
            if (matriz_de_coincidencias_1[patatin][patata]== true) {
                array2[patatin] = abs(patatin-x_aproximada)*abs(patatin-x_aproximada) + abs(y_aproximada-patata)*abs(y_aproximada-patata) ;
            }
        }

        int n = contador2;

        for(int i = 0; i < n-1; i++) {
            for(int j = 0; j < n-i-1; j++) {
                if(array2[j] > array2[j+1]) {
                    int temp = array2[j];
                    array2[j] = array2[j+1];
                    array2[j+1] = temp;
                }
            }
        }
        *salida_a_escribir[2] = array2[0];
    }

    if (in[3] != 0) {
        //Busca la posición más cercana a la x e y aproximada3
        int patatin = 2;

        for (int patata = 0; patata < 13; patata++) {
            if (matriz_de_coincidencias_1[patatin][patata]== true) {
                array3[patatin] = abs(patatin-x_aproximada)*abs(patatin-x_aproximada) + abs(y_aproximada-patata)*abs(y_aproximada-patata) ;
            }
        }

        int n = contador3;

        for(int i = 0; i < n-1; i++) {
            for(int j = 0; j < n-i-1; j++) {
                if(array3[j] > array3[j+1]) {
                    int temp = array3[j];
                    array3[j] = array3[j+1];
                    array3[j+1] = temp;
                }
            }
        }
        *salida_a_escribir[3] = array3[0];
    }
    if (in[4] != 0) {
        //Busca la posición más cercana a la x e y aproximada3
        int patatin = 4;

        for (int patata = 0; patata < 13; patata++) {
            if (matriz_de_coincidencias_1[patatin][patata]== true) {
                array4[patatin] = abs(patatin-x_aproximada)*abs(patatin-x_aproximada) + abs(y_aproximada-patata)*abs(y_aproximada-patata) ;
            }
        }

        int n = contador4;

        for(int i = 0; i < n-1; i++) {
            for(int j = 0; j < n-i-1; j++) {
                if(array4[j] > array4[j+1]) {
                    int temp = array4[j];
                    array4[j] = array4[j+1];
                    array4[j+1] = temp;
                }
            }
        }
        *salida_a_escribir[4] = array4[0];
    }
    if (in[5] != 0) {
        //Busca la posición más cercana a la x e y aproximada3
        int patatin = 5;

        for (int patata = 0; patata < 13; patata++) {
            if (matriz_de_coincidencias_1[patatin][patata]== true) {
                array5[patatin] = abs(patatin-x_aproximada)*abs(patatin-x_aproximada) + abs(y_aproximada-patata)*abs(y_aproximada-patata) ;
            }
        }

        int n = contador5;

        for(int i = 0; i < n-1; i++) {
            for(int j = 0; j < n-i-1; j++) {
                if(array5[j] > array5[j+1]) {
                    int temp = array5[j];
                    array5[j] = array5[j+1];
                    array5[j+1] = temp;
                }
            }
        }
        *salida_a_escribir[5] = array5[0];
    }


    //TODO: añadir soporte para cejillas

}
