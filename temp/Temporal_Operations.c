#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 1000


// Funciones:
// tokenizar(text)
// Output example: d1/4 e1/32 e2/2 e1/8 e1/16 e1/32 {e1/4 g1/4} e1/4 e1/8 c1/8 g1/32 c1/8 e1/32


void saveSystem()
{
    int
    saveSystemSimple();
}


int isSustained(char sharp)
{
    if (sharp == '#')
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

int noteDetector(char note, char sharp)
{
    int a = isSustained(sharp);

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
        return 5 + a;
    }
    else if (note == 'f')
    {
        return 7 + a;
    }
    else if (note == 'g')
    {
        return 9 + a;
    }
    else if (note == 'a')
    {
        return 11 + a;
    }
    else if (note == 'b')
    {
        return 13 + a;
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
    int notes[MAX];

    char note[MAX];

    /*
    struct metaSimple
    {
        int dataNote;
        int pos;

    } metadataSimple[MAX];
*/

    struct meta // Metadatos de las posiciones en el acorde
    {
        int dataNote0;
        int dataNote1;
        int dataNote2;
        int dataNote3;
        int dataNote4;
        int dataNote5;
        int dataNote6;

        int pos;

    } metadataChords[MAX];


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

                if (aux1 == 'a' || aux1 == 'b' || aux1 == 'c' || aux1 == 'd' || aux1 == 'e' || aux1 == 'f' || aux1 == 'g')
                {
                    noteDetector(aux1_chord, aux2_chord);
                    alt_pos = alt_pos + 1;
                }


                /*
                int b = 0;
                char c[MAX];
                aux2 = aux_string[j];

                c[0] = aux_string[j];
                b = b + 1;


                while (aux2 != ' ')
                {

                }
*/

            }
            chordSearch = false;
        }


        if ((aux1 == 'a' || aux1 == 'b' || aux1 == 'c' || aux1 == 'd' || aux1 == 'e' || aux1 == 'f' || aux1 == 'g') && chordSearch == false)
        {
            notes[alt_pos] = noteDetector(aux1, aux2);

            alt_pos = alt_pos + 1;
        }



        // strcpy(chord, aux_string);

        if (total_pos == strlen(tokens)) // Si llegamos al final del output, parar el bucle
        {
            calambreenlapija = true;
        }

        total_pos = total_pos + 1;
    }
}

