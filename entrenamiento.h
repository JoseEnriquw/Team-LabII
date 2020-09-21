#ifndef ENTRENAMIENTO_H_INCLUDED
#define ENTRENAMIENTO_H_INCLUDED
#include "Strucs.h"


Entrenamiento nuevo_entrenamiento ();
bool guardar_entrenamiento ( Entrenamiento);
void modificar_entrenamiento ();
void Listar_entrenamientos_por_ID ();
//void Listar_entrenamiento_por_Usuarios ();
void Listar_todos_los_entrenamientos ();
Fecha fecha_entrenamiento ();
int generacion_de_ID ();
Entrenamiento leer_entrenamiento(int pos);
void mostrar_entrenamiento (Entrenamiento reg);
bool guardar_modificacion_entrenamiento (Entrenamiento reg,int pos)
int buscar_entrenamiento(int ID)
#endif // ENTRENAMIENTO_H_INCLUDED
