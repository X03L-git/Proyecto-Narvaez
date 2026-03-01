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


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 1000


// Funciones:
// tokenizar(text)
// Output example: d1/4 e1/32 e2/2 e1/8 e1/16 e1/32 {e1/4 g1/4} e1/4 e1/8 c1/8 g1/32 c1/8 e1/32

#include "Algoritmo.h"



int noteDetector(char note, char sharp)
{
    int a = 0;
    if (sharp == '#')
    {
        a = 1;
    }
    else
    {
        a = 0;
    }

    if (note == 'c')
    {
        return 1 + a;
    }
    else if (note == 'd')
    {
        return 3 + a;
    }
    else if (note == 'e')
    {
        return 5;
    }
    else if (note == 'f')
    {
        return 6 + a;
    }
    else if (note == 'g')
    {
        return 8 + a;
    }
    else if (note == 'a')
    {
        return 10 + a;
    }
    else if (note == 'b')
    {
        return 12;
    }
}

        void digitalizer (char* tokens)
        {
            bool chordSearch = false;
            char aux_string[MAX];

            int total_pos = 0;
            int alt_pos = 0;
            int last_pos = 0;
            int end_pos = 0;
            char aux1 = 0;
            char aux2 = 0;
            int arraysimple[MAX];

            char note[MAX];



            int metadataChords[MAX][12];


            entrada Output_Translated;



            int counterChords = 0;

            bool calambreenlapija = false; // Le ha dado un calambre en la pija

            while (calambreenlapija != true) // Bucle para mirar cada posición por si hubiera notas
            {
                aux1 = tokens[total_pos];
                aux2 = tokens[total_pos + 1];

                if (aux1 == '{') // Encontramos "{"
                {
                    last_pos = total_pos; // Posición más reciente con un "["
                    chordSearch = true;
                }
                else if (aux1 == '}') // Encontramos "}"
                {
                    end_pos = total_pos;

                    counterChords = counterChords + 1;

                    int k = 0;
                    char aux1_chord = 0;
                    char aux2_chord = 0;

                    for (int j = last_pos + 1; j < end_pos; j++) // Copiamos parte con acorde en variable auxiliar
                    {
                        aux_string[k] = tokens[j];

                        k = k + 1;
                    }

                    for (int j = 0; j < strlen(aux_string); j++) // Imitamos el blucle grande pero a escala pequeña para los acordes (ahora no hay calambre en la pija)
                    {
                        aux1_chord = aux_string[j];
                        aux2_chord = aux_string[j + 1];

                        if (aux1_chord == 'a' || aux1_chord == 'b' || aux1_chord == 'c' || aux1_chord == 'd' || aux1_chord == 'e' || aux1_chord == 'f' || aux1_chord == 'g')
                        {
                            alt_pos = alt_pos + 1;
                            if (j == 0)
                            {
                                metadataChords[counterChords][j] = noteDetector(aux1_chord, aux2_chord);
                            }
                            if (j == 1)
                            {
                                metadataChords[counterChords][j] = noteDetector(aux1_chord, aux2_chord);
                            }
                            if (j == 2)
                            {
                                metadataChords[counterChords][j] = noteDetector(aux1_chord, aux2_chord);
                            }
                            if (j == 3)
                            {
                                metadataChords[counterChords][j] = noteDetector(aux1_chord, aux2_chord);
                            }
                            if (j == 4)
                            {
                                metadataChords[counterChords][j] = noteDetector(aux1_chord, aux2_chord);
                            }
                            if (j == 5)
                            {
                                metadataChords[counterChords][j] = noteDetector(aux1_chord, aux2_chord);
                            }
                            if (j == 6)
                            {
                                metadataChords[counterChords][j] = noteDetector(aux1_chord, aux2_chord);
                            }
                            if (j == 7)
                            {
                                metadataChords[counterChords][j] = noteDetector(aux1_chord, aux2_chord);
                            }
                            if (j == 8)
                            {
                                metadataChords[counterChords][j] = noteDetector(aux1_chord, aux2_chord);
                            }
                            if (j == 9)
                            {
                                metadataChords[counterChords][j] = noteDetector(aux1_chord, aux2_chord);
                            }
                            if (j == 10)
                            {
                                metadataChords[counterChords][j] = noteDetector(aux1_chord, aux2_chord);
                            }
                            if (j == 11)
                            {
                                metadataChords[counterChords][j] = noteDetector(aux1_chord, aux2_chord);
                            }
                            if (j == 12)
                            {
                                metadataChords[counterChords][j] = noteDetector(aux1_chord, aux2_chord);
                            }
                            int arraychord[MAX][6];
                            for (int i = 0; i < aux2; i++)
                            {
                                int auxarray[6];
                                for (j = 0; j < 6; j++)
                                {
                                    if (metadataChords[i][j] == 0)
                                    {
                                        metadataChords[i][j] = -1;
                                    }
                                }

                                int j = 0;
                                int aux = metadataChords[i][j];
                                int aux1 = metadataChords[counterChords][j + 1];
                                int aux2 = metadataChords[counterChords][j + 2];
                                int aux3 = metadataChords[counterChords][j + 3];
                                int aux4 = metadataChords[counterChords][j + 4];
                                int aux5 = metadataChords[counterChords][j + 5];

                                auxarray[0] = aux;
                                auxarray[1] = aux1;
                                auxarray[2] = aux2;
                                auxarray[3] = aux3;
                                auxarray[4] = aux4;
                                auxarray[5] = aux5;

                            }




                        }
                        chordSearch = false;



                    }





                if ((aux1 == 'a' || aux1 == 'b' || aux1 == 'c' || aux1 == 'd' || aux1 == 'e' || aux1 == 'f' || aux1 == 'g') && chordSearch == false)
                {
                    int arrays[MAX];
                    arraysimple[alt_pos] = noteDetector(aux1, aux2);
                    for (int i; i < aux1; i++)
                    {
                        int aux = arrays[i];
                        int auxarray[6];

                        auxarray[0] = aux;
                        auxarray[1] = -1;
                        auxarray[2] = -1;
                        auxarray[3] = -1;
                        auxarray[4] = -1;
                        auxarray[5] = -1;
                    }
                    alt_pos = alt_pos + 1;

                }



                // strcpy(chord, aux_string);

                if (total_pos == strlen(tokens)) // Si llegamos al final del output, parar el bucle
                {
                    calambreenlapija = true;
                }

                total_pos = total_pos + 1;

                    // Esta es la ÚNICA VARIABLE IMPORTANTE DE ESTE MALDITO CÓDIGO -> auxarray[6]
            }
        }








        }


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

        int main (){
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

        int array[6] ;

        for (int i = 0; i < 6; i++) {
            array[i] = -1;
        }

    bool chordSearch = false;
            char aux_string[MAX];

            int total_pos = 0;
            int alt_pos = 0;
            int last_pos = 0;
            int end_pos = 0;
            char aux1 = 0;
            char aux2 = 0;
            int arraysimple[MAX];

            char note[MAX];

    int auxarray[6];

            int metadataChords[MAX][12];


            entrada Output_Translated;



            int counterChords = 0;

            bool calambreenlapija = false; // Le ha dado un calambre en la pija

            while (calambreenlapija != true) // Bucle para mirar cada posición por si hubiera notas
            {
                aux1 = resultado[total_pos];
                aux2 = resultado[total_pos + 1];

                if (aux1 == '{') // Encontramos "{"
                {
                    last_pos = total_pos; // Posición más reciente con un "["
                    chordSearch = true;
                }
                else if (aux1 == '}') // Encontramos "}"
                {
                    end_pos = total_pos;

                    counterChords = counterChords + 1;

                    int k = 0;
                    char aux1_chord = 0;
                    char aux2_chord = 0;

                    for (int j = last_pos + 1; j < end_pos; j++) // Copiamos parte con acorde en variable auxiliar
                    {
                        aux_string[k] = resultado[j];

                        k = k + 1;
                    }

                    for (int j = 0; j < strlen(aux_string); j++) // Imitamos el blucle grande pero a escala pequeña para los acordes (ahora no hay calambre en la pija)
                    {
                        aux1_chord = aux_string[j];
                        aux2_chord = aux_string[j + 1];

                        if (aux1_chord == 'a' || aux1_chord == 'b' || aux1_chord == 'c' || aux1_chord == 'd' || aux1_chord == 'e' || aux1_chord == 'f' || aux1_chord == 'g')
                        {
                            alt_pos = alt_pos + 1;
                            if (j == 0)
                            {
                                metadataChords[counterChords][j] = noteDetector(aux1_chord, aux2_chord);
                            }
                            if (j == 1)
                            {
                                metadataChords[counterChords][j] = noteDetector(aux1_chord, aux2_chord);
                            }
                            if (j == 2)
                            {
                                metadataChords[counterChords][j] = noteDetector(aux1_chord, aux2_chord);
                            }
                            if (j == 3)
                            {
                                metadataChords[counterChords][j] = noteDetector(aux1_chord, aux2_chord);
                            }
                            if (j == 4)
                            {
                                metadataChords[counterChords][j] = noteDetector(aux1_chord, aux2_chord);
                            }
                            if (j == 5)
                            {
                                metadataChords[counterChords][j] = noteDetector(aux1_chord, aux2_chord);
                            }
                            if (j == 6)
                            {
                                metadataChords[counterChords][j] = noteDetector(aux1_chord, aux2_chord);
                            }
                            if (j == 7)
                            {
                                metadataChords[counterChords][j] = noteDetector(aux1_chord, aux2_chord);
                            }
                            if (j == 8)
                            {
                                metadataChords[counterChords][j] = noteDetector(aux1_chord, aux2_chord);
                            }
                            if (j == 9)
                            {
                                metadataChords[counterChords][j] = noteDetector(aux1_chord, aux2_chord);
                            }
                            if (j == 10)
                            {
                                metadataChords[counterChords][j] = noteDetector(aux1_chord, aux2_chord);
                            }
                            if (j == 11)
                            {
                                metadataChords[counterChords][j] = noteDetector(aux1_chord, aux2_chord);
                            }
                            if (j == 12)
                            {
                                metadataChords[counterChords][j] = noteDetector(aux1_chord, aux2_chord);
                            }
                            int arraychord[MAX][6];
                            for (int i = 0; i < aux2; i++)
                            {

                                for (j = 0; j < 6; j++)
                                {
                                    if (metadataChords[i][j] == 0)
                                    {
                                        metadataChords[i][j] = -1;
                                    }
                                }

                                int j = 0;
                                int aux = metadataChords[i][j];
                                int aux1 = metadataChords[counterChords][j + 1];
                                int aux2 = metadataChords[counterChords][j + 2];
                                int aux3 = metadataChords[counterChords][j + 3];
                                int aux4 = metadataChords[counterChords][j + 4];
                                int aux5 = metadataChords[counterChords][j + 5];

                                auxarray[0] = aux;
                                auxarray[1] = aux1;
                                auxarray[2] = aux2;
                                auxarray[3] = aux3;
                                auxarray[4] = aux4;
                                auxarray[5] = aux5;
                            }
                        }
                        chordSearch = false;
                    }

                if ((aux1 == 'a' || aux1 == 'b' || aux1 == 'c' || aux1 == 'd' || aux1 == 'e' || aux1 == 'f' || aux1 == 'g') && chordSearch == false)
                {
                    int arrays[MAX];
                    arraysimple[alt_pos] = noteDetector(aux1, aux2);
                    for (int i; i < aux1; i++)
                    {
                        int aux = arrays[i];
                        int auxarray[6];

                        auxarray[0] = aux;
                        auxarray[1] = -1;
                        auxarray[2] = -1;
                        auxarray[3] = -1;
                        auxarray[4] = -1;
                        auxarray[5] = -1;
                    }
                    alt_pos = alt_pos + 1;

                }

                // strcpy(chord, aux_string);

                if (total_pos == strlen(resultado)) // Si llegamos al final del output, parar el bucle
                {
                    calambreenlapija = true;
                }

                total_pos = total_pos + 1;

                    // Esta es la ÚNICA VARIABLE IMPORTANTE DE ESTE MALDITO CÓDIGO -> auxarray[6]

                }
                salida* salida_a_escribir = malloc (sizeof(salida));


                salida* otr_array = precondiciones (array, auxarray, salida_a_escribir);


                for (int i = 0; i < 6; i++) {
                    printf("%d ", array[i]);
                }


            }
    free(resultado);
            }


