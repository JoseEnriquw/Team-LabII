#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "Strucs.h"
#include "Funciones.h"
using namespace std;
#include "ui.h"
#include "rlutil.h"
#include "Menu.h"
using namespace rlutil;

void menu_principal(){
int opcion;
cls();


   do{

   title("MENU PRINCIPAL",APP_TITLEFORECOLOR,APP_TITLEBACKCOLOR);

   cout<<endl<<endl;
   cout<<"1) USUARIOS"<<endl;
   cout<<"2) ENTRENAMIENTOS"<<endl;
   cout<<"3) REPORTES"<<endl;
   cout<<"4) CONFIGURACION"<<endl;
   cout<<"--------------------------"<<endl;
   cout<<"0) SALIR DEL PROGRAMA"<<endl;
   cin>>opcion;
   switch(opcion){
   case 1:
       cls();
       menu_de_usuario();
       break;

   case 2:

    break;

   case 3:

    break;

   case 4:

    break;


   case 0:

    break;

    ///Completar!!!!!
   default:
    cout<<"Error!!!"<<endl;
    cout<<"Ingrese una opcion valida."<<endl;
    break;

   }
   }while(opcion!=0);



}

void menu_de_usuario(){
int opcion;
bool grabo;
Usuarios reg;
do{
        cls();
   title("MENU DE USUARIO",APP_TITLEFORECOLOR,APP_TITLEBACKCOLOR);
   cout<<endl<<endl;
   cout<<"1) NUEVO USUARIO"<<endl;
   cout<<"2) MODIFICAR USUARIO"<<endl;
   cout<<"3) LISTAR USUARIO POR ID"<<endl;
   cout<<"4) LISTAR TODOS LOS USUARIOS"<<endl;
   cout<<"5) ELIMINAR USUARIO"<<endl;
   cout<<"--------------------------"<<endl;
   cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
   cin>>opcion;
   switch(opcion){
   case 1:
        reg=cargar_usuario();
        grabo=guardar_usuario(reg);
       if(grabo){
        cout<<"Usuario cargado y guardado correctamente"<<endl;
       }else{
       cout<<"Hubo un error, no se pudieron guardar los datos cargados"<<endl;
       }
   break;

   case 2:
       cls();
           modificar_usuario();
    break;
   case 3:
          listar_usuarios_x_ID();
    break;

   case 4:
       listar_todos_los_usuarios();
    break;

   case 5:
        baja_usuario();
    break;

   case 0:
    break;

    default:
    cout<<"Error!!!"<<endl;
    cout<<"Ingrese una opcion valida."<<endl;
    break;

   }



       }while(opcion!=0);
     cls();
}

void menu_de_entrenamiento(){
    int opcion;

do{
    switch(opcion){
case 1:

    break;
case 0:
    break;
default:
    msj("Error!!!Ingrese una opcion valida.",APP_FORECOLOR,APP_ERRORCOLOR,SCREEN_HEIGHT);
    break;


    }
}while(opcion!=0);
}
