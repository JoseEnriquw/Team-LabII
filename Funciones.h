#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "Strucs.h"
Campo cargar_usuario();
bool guardar_usuario(Campo);
bool guardar_usuario(Campo,int);
Fecha cagar_fecha_de_nacimiento();
void mostrar_usuario(Campo);
void mostrar_fecha_de_nacimiento(Fecha);
void listar_todos_los_usuarios();
int buscar_usuario(int);
bool guardar_usuario(Campo);
void modificar_usuario();
Campo leer_Usuario(int);
void menu_principal();
void menu_de_usuario();
int cantidad_de_usuarios();
void baja_usuario();
void listar_usuarios_x_ID();
bool comparar(int);
Fecha hoy ();
int validarfecha(Fecha,Fecha);
int validaredad(Fecha,Fecha);
#endif // FUNCIONES_H_INCLUDED
