#ifndef ENTRENAMIENTO_H_INCLUDED
#define ENTRENAMIENTO_H_INCLUDED
#include "Strucs.h"


Entrenamiento nuevo_entrenamiento ();
bool guardar_entrenamiento ( Entrenamiento);
void modificar_entrenamiento ();
void Listar_entrenamientos_por_ID ();
void Listar_todos_los_entrenamientos ();
Fecha fecha_entrenamiento ();
Entrenamiento leer_entrenamiento(int );
void mostrar_entrenamiento (Entrenamiento );
bool guardar_modificacion_entrenamiento (Entrenamiento ,int );
int validar_ID_Usuario(int );
bool validar_actividad(int);
int cantidad_entrenamiento();
void Listar_entrenamientos_por_ID_Usuario (int );
void Listar_entrenamiento_por_Usuarios ();

#endif // ENTRENAMIENTO_H_INCLUDED
