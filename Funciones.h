#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "Strucs.h"
Usuarios cargar_usuario();
bool guardar_usuario(Usuarios);
bool guardar_usuario(Usuarios,int);
Fecha cagar_fecha_de_nacimiento();
void mostrar_usuario(Usuarios);
void mostrar_fecha_de_nacimiento(Fecha);
void listar_todos_los_usuarios();
int buscar_usuario(int);
bool guardar_usuario(Usuarios);
void modificar_usuario();
Usuarios leer_Usuario(int);

int cantidad_de_usuarios();
void baja_usuario();
void listar_usuarios_x_ID();
bool comparar(int);
Fecha hoy ();
int validarfecha(Fecha,Fecha);
int validaredad(Fecha,Fecha);
#endif // FUNCIONES_H_INCLUDED
