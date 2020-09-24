#include <iostream>
#include "entrenamiento.h"
#include "Funciones.h"
#include "Strucs.h"
#include <cstdio>
#include "ui.h"
#include <ctime>
#include "rlutil.h"

using namespace std;
using namespace rlutil;

void realizar_backup (){
    cls();
    Usuarios *v_usuario;
    Entrenamiento *v_entrenamiento;
    int cant_usuario = cantidad_de_usuarios ();
    int cant_entre= cantidad_entrenamiento();
    v_usuario = (Usuarios *) malloc(sizeof(Usuarios) * cant_usuario);
    if (v_usuario == NULL){
        free(v_usuario);
        return;
    }
    FILE *P;
    P=fopen ("usuarios.bkp", "ab");
    if (P==NULL){
         cout<<"Error en archivos";
         free(v_usuario);
         return;
    }
    fwrite(&v_usuario, sizeof(Usuarios), 1, P);
    fread(&v_usuario, sizeof(Usuarios), cant_usuario,P);
    for (int i=0; i<cant_usuario; i++){
        mostrar_usuario (v_usuario[i]);

    }
    fclose(P);
    free(v_usuario);

    /*
    v_entrenamiento= (Entrenamiento *) malloc(sizeof(Entrenamiento) * cant_entre);
    if (v_entrenamiento == NULL){
        free(v_entrenamiento);
        return;
    }

    */


}

