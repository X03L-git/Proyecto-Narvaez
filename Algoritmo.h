//
// Created by carlos on 2/28/26.
//

#ifndef ALGORITMO_ALGORITMO_H
#define ALGORITMO_ALGORITMO_H

typedef int salida[6];
typedef int entrada[6];//

salida* precondiciones (salida out, int in[6], salida* salida_a_escribir);

salida* anterior_no_presionada_actual_simple (salida out, entrada in, salida* salida_a_escribir);

salida* anterior_presionada_actual_simple (salida out, entrada in, salida* salida_a_escribir);

salida* anterior_acorde_actual_simple (salida out, entrada in, salida* salida_a_escribir);

salida *anterior_no_presionada_actual_acorde(salida out, entrada in, salida *salida_a_escribir);

salida* anterior_presionada_actual_acorde (salida out, entrada in, salida* salida_a_escribir);

salida* anterior_acorde_actual_acorde (salida out, entrada in, salida* salida_a_escribir);




#endif //ALGORITMO_ALGORITMO_H