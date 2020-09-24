#include <iostream>
#include "entrenamiento.h"
#include "Funciones.h"
#include "Strucs.h"
#include <cstdio>
#include "ui.h"
#include <ctime>
#include "rlutil.h"
#include "backup.h"

using namespace std;
using namespace rlutil;

const char *fi_entrenamiento = "Datos/entrenamientos.dat" ;
const char *fi_usuario="Datos/Usuarios.dat";
const char *entrenamiento_bkp="Datos/Entrenamiento.bkp";
const char *usuario_bkp="Datos/Usuario.bkp";

///FUNCION PARA REALIZAR COPIA DE SEGURIDAD
void realizar_backup (){
    cls();
    char opcion;
    cout<<"Esta seguro que desea realizar la copia seguridad? \nPresione 'Y' para confirmar o cualquier otra letra para volver al menu."<<endl;
    cin>>opcion;
    cout<<endl;

     if(opcion=='y' || opcion=='Y'){

    Usuarios *v_usuario;
    Entrenamiento *v_entrenamiento;

    ///BACKUP DE USUARIOS
    int cant_usuario = cantidad_de_usuarios ();
    int cant_entre= cantidad_entrenamiento();
    v_usuario = (Usuarios *) malloc(cant_usuario *sizeof(Usuarios));
    if (v_usuario == NULL){
        free(v_usuario);
        return;
    }
    FILE *P;
    P=fopen (fi_usuario, "rb");
    if (P==NULL){
         cout<<"Error en archivos";
         free(v_usuario);
         return;
    }

    fread(v_usuario, sizeof(Usuarios), cant_usuario,P);
    fclose(P);

    P=fopen(usuario_bkp,"wb");
    if (P==NULL){
         cout<<"Error en archivos";
         free(v_usuario);
         return;
    }

    int cant=fwrite(v_usuario,sizeof(Usuarios),cant_usuario,P);
      if(cant==cant_usuario) cout<<"El backup del archivo Usuarios fue relizado con exito!!!!!"<<endl;

      else cout<<"Error!!!! No se pudo realizar el backup del archivo Usuarios."<<endl;

    fclose(P);
    free(v_usuario);

    anykey();

    ///BACKUP DE ENTRENAMIENTOS
       v_entrenamiento = (Entrenamiento *) malloc(cant_entre *sizeof(Entrenamiento));
    if (v_entrenamiento == NULL){
        free(v_entrenamiento);
        return;
    }

    P=fopen (fi_entrenamiento, "rb");
    if (P==NULL){
         cout<<"Error en archivos";
         free(v_entrenamiento);
         return;
    }

    fread(v_entrenamiento, sizeof(Entrenamiento), cant_entre,P);
    fclose(P);

    P=fopen(entrenamiento_bkp,"wb");
    if (P==NULL){
         cout<<"Error en archivos";
         free(v_entrenamiento);
         return;
    }

     cant=fwrite(v_entrenamiento,sizeof(Entrenamiento),cant_entre,P);
      if(cant==cant_entre) cout<<"El backup del archivo Entrenamiento fue relizado con exito!!!!!"<<endl;

      else cout<<"Error!!!! No se pudo realizar el backup del archivo Entrenamiento."<<endl;

    fclose(P);
    free(v_entrenamiento);

    anykey();



}

}
///FUNCION RESTAURAR COPIA DE SEGURIDAD
void restaurar_copia_seguridad(){
    cls();
    char opcion;
    cout<<"Esta seguro que desea restaurar los archivos? \nPresione 'Y' para confirmar o cualquier otra letra para volver al menu."<<endl;
    cin>>opcion;
    cout<<endl;
     if(opcion=='y' || opcion=='Y'){
 int cant_entre,cant_usuarios;
 Usuarios *v_usuario;
 Entrenamiento *v_entrenamiento;



    cant_usuarios=contar_registros(usuario_bkp);
    cant_entre=contar_registros(entrenamiento_bkp);
///RESTAURAR ARCHIVO USUARIOS
    v_usuario=(Usuarios *)malloc(cant_usuarios*sizeof(Usuarios));

    if (v_usuario == NULL){
        free(v_usuario);
        return;
    }

    FILE *P;
    P=fopen (usuario_bkp, "rb");
    if (P==NULL){
         cout<<"Error en archivos";
         free(v_usuario);
         return;
    }

    fread(v_usuario, sizeof(Usuarios), cant_usuarios,P);
    fclose(P);

    P=fopen(fi_usuario,"wb");
    if (P==NULL){
         cout<<"Error en archivos";
         free(v_usuario);
         return;
    }

    int cant=fwrite(v_usuario,sizeof(Usuarios),cant_usuarios,P);

    if(cant==cant_usuarios) cout<<"Se ha restaurado el archivo Usuarios con exito!!!!!"<<endl;

    else cout<<"Error!!!! No se pudo restaurar el archivo Usuarios."<<endl;

    fclose(P);
    free(v_usuario);

    anykey();

///RESTAURAR ARCHIVO ENTRENAMIENTOS

       v_entrenamiento=(Entrenamiento *)malloc(cant_entre*sizeof(Entrenamiento));

    if (v_entrenamiento == NULL){
        free(v_entrenamiento);
        return;
    }

    P=fopen (entrenamiento_bkp, "rb");
    if (P==NULL){
         cout<<"Error en archivos";
         free(v_entrenamiento);
         return;
    }

    fread(v_entrenamiento, sizeof(Entrenamiento), cant_entre,P);
    fclose(P);

    P=fopen(fi_entrenamiento,"wb");
    if (P==NULL){
         cout<<"Error en archivos";
         free(v_entrenamiento);
         return;
    }

    cant=fwrite(v_entrenamiento,sizeof(Entrenamiento),cant_entre,P);

    if(cant==cant_entre) cout<<"Se ha restaurado el archivo Entrenamiento con exito!!!!!"<<endl;

    else cout<<"Error!!!! No se pudo restaurar el archivo Entrenamiento."<<endl;

    fclose(P);
    free(v_entrenamiento);

    anykey();


}

}

///FUNCION PARA CONTAR REGISTROS DE BACKUP
int contar_registros(const char *a){
FILE *p = fopen(a, "rb");
    if (p == NULL){
        return 0;
    }
    int bytes, cant;
    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    if(a==entrenamiento_bkp)cant = bytes / sizeof(Entrenamiento);
    else cant = bytes / sizeof(Usuarios);

    return cant;
    }
