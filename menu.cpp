#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "Strucs.h"
#include "Funciones.h"
using namespace std;
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;

void menu_principal(){
int opcion;

   do{
   cout<<"MENU PRINCIPAL"<<endl;
   cout<<"--------------------------"<<endl;
   cout<<"1) USUARIOS"<<endl;
   cout<<"2) ENTRENAMIENTOS"<<endl;
   cout<<"3) REPORTES"<<endl;
   cout<<"4) CONFIGURACION"<<endl;
   cout<<"--------------------------"<<endl;
   cout<<"0) SALIR DEL PROGRAMA"<<endl;
   cin>>opcion;
   switch(opcion){
   case 1:
       system("cls");
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
Campo reg;
do{
   cout<<"MENU DE USUARIO"<<endl;
   cout<<"--------------------------"<<endl;
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
   ///Completar!!!!!!
   //case 2:

   /// break;
   //case 3:

    ///break;

   case 4:
       listar_todos_los_usuarios();
    break;

   case 5:

    break;
   case 0:
    break;

    default:
    cout<<"Error!!!"<<endl;
    cout<<"Ingrese una opcion valida."<<endl;
    break;

   }



       }while(opcion!=0);

}
