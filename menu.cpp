#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "Strucs.h"
#include "Funciones.h"
//agregadas 21/9:
#include "entrenamiento.h"
#include "ui.h"
#include <ctime>
#include "rlutil.h"
using namespace std;
using namespace rlutil;

#include "Menu.h"


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
        Menu_entrenamientos ();
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
        return;
        break;
        default:
        cout<<"Error!!!"<<endl;
        cout<<"Ingrese una opcion valida."<<endl;
        break;
   }
 }while(opcion!=0);
        cls();
}

void Menu_entrenamientos () {
   bool guardo;
   Entrenamiento  reg;
   int opcion, id;

   do{
   title("MENU ENTRENAMIENTOS",APP_TITLEFORECOLOR,APP_TITLEBACKCOLOR);
   cout<<endl<<endl;
   cout<<"1) NUEVO ENTRENAMIENTO"<<endl;
   cout<<"2) MODIFICAR ENTRENAMIENTO"<<endl;
   cout<<"3) LISTAR ENTRENAMIENTO POR ID"<<endl;
   cout<<"4) LISTAR ENTRENAMIENTO POR ID USUARIOS"<<endl;
   cout<<"5) LISTAR TODOS LOS ENTRENAMIENTOS"<<endl;
   cout<<"--------------------------"<<endl;
   cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
   cin>> opcion;
   cls();
   switch (opcion){
   case 1: reg=nuevo_entrenamiento ();
           guardo=guardar_entrenamiento(reg);
           if (guardo) {
                cout<<endl<<"EL ENTRENAMIENTO SE GUARDO CORRECTAMENTE"<<endl;
           }
           else {
               cout <<"NO SE GUARDO EL ENTRENAMIENTO"<<endl;
           }

            id=generacion_de_ID();
           cout<<endl <<"Y su ID es:"<< id<<endl;

           anykey();
            cls();
           break;
   case 2: modificar_entrenamiento ();
           break;
   case 3: Listar_entrenamientos_por_ID ();
           break;
//   case 4: Listar_entrenamiento_por_Usuarios ();
         //  break;
   case 5: Listar_todos_los_entrenamientos ();
           break;
   case 0:
           break;
   default: cout<< "OPCION INVALIDA"<<endl;
           break;
   }
}while(opcion!=0);
}

