#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <iostream>
#include "Funciones.h"
#include "Strucs.h"
#include <cstdio>
#include "rlutil.h"
#include <ctime>

using namespace rlutil;

Usuarios cargar_usuario();
bool guardar_usuario(Usuarios);
bool guardar_usuario(Usuarios,int);
Fecha cagar_fecha_de_nacimiento();
void mostrar_usuario(Usuarios);
void mostrar_fecha_de_nacimiento(Fecha);
void listar_todos_los_usuarios();
int buscar_usuario(int);
void modificar_usuario();
Usuarios leer_Usuario(int);

int cantidad_de_usuarios();
void baja_usuario();
void listar_usuarios_x_ID();
bool comparar(int);
Fecha hoy ();
int validarfecha(Fecha,Fecha);
int validaredad(Fecha,Fecha);
bool anio_bisiesto(int);


#endif // FUNCIONES_H_INCLUDED
