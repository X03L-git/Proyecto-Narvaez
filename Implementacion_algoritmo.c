#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Algoritmo.h"

#define TAMANNO_BUFFER 64

typedef struct lista {
    char buffer[TAMANNO_BUFFER];
    char* prox;
}lista;





//TODO: Asegurarse de acordes y quitar el corchete final
//TODO: quitar comillas y mantener los corchetes de los acordes.
//todo Input example: ['\\meter<"4/4">', '\\meter<"4/4">', '\\meter<"4/4">', '\\meter<"4/4">', 'd1/4', 'e1/32', 'e2/2', 'e1/8', 'e1/16', 'e1/32', {'e1/4', 'g1/4'}, 'e1/4', 'e1/8', 'c1/8', 'g1/32', 'c1/8', 'e1/32']

//todo Output example: d1/4 e1/32 e2/2 e1/8 e1/16 e1/32 {e1/4 g1/4} e1/4 e1/8 c1/8 g1/32 c1/8 e1/32












char* tokenizar (char* texto_de_entrada) {
    int tamanno = strlen(texto_de_entrada);
    int contador = 0;
    int contador_de_texto = 0;
    bool condicion = true;

    char* texto_de_salida = malloc (sizeof(char) * tamanno);

    while (contador_de_texto < tamanno) {

        while (texto_de_entrada[contador_de_texto] != ',' && texto_de_entrada[contador_de_texto] != '\0') {
            //Recorremos los tokens separados por comas
            if (texto_de_entrada[contador_de_texto+2] == 92) {
                char a = 10;
                while (a != ',' && a != '\0') {
                    a = texto_de_entrada[contador_de_texto];
                    contador_de_texto++;
                }
            }
            char patatin = texto_de_entrada[contador_de_texto];

            if (patatin != 39  && patatin != '[' && patatin != ']' && patatin != ',') {
                texto_de_salida[contador] = texto_de_entrada[contador_de_texto];
                contador++;

            }

            condicion = true;
            contador_de_texto++;
        }
        contador_de_texto ++;

    }

    //Acúerdate de que los corchetes

    return texto_de_salida;

}

int main () {
    FILE* fptr = fopen("patata", "r");
    fseek(fptr, 0L, SEEK_END);
    int fin = ftell(fptr);
    fseek(fptr, 0L, SEEK_SET);
    int inicio = ftell(fptr);


    int offset = fin-inicio;
    fclose(fptr);

    char* texto = malloc (sizeof(char) * offset);
    fgets(texto, 0, fptr);

    char* resultado = tokenizar(texto);
    free(texto);
    printf("%s", resultado);

    int array[6];
    for (int i = 0; i < 6; i++) {
        array[i] = -1;
    }

    int array_2[6] ;

    for (int i = 0; i < 6; i++) {
        array[i] = 0;
    }
    salida* salida_a_escribir = malloc (sizeof(salida));

    salida* otr_array = precondiciones (array, array_2, salida_a_escribir);

    for (int i = 0; i < 6; i++) {
        printf("%d ", array[i]);
    }





















    free(resultado);
}
