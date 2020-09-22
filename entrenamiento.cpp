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
const char *file_entrenamiento = "entrenamiento.dat" ;


Entrenamiento nuevo_entrenamiento (){
 Fecha actual;
 actual=hoy();
 int error=0;
 Entrenamiento reg;
 int ID,ID_usuarios;
 cout <<"INGRESE ID DE USUARIO: ";
 cin>>ID_usuarios;
 reg.ID_usuarios=validar_ID_Usuario(ID_usuarios);


do{ cout <<"FECHA DE ENTRENAMIENTO"<<endl;
 reg.fecha_de_entrenamiento= fecha_entrenamiento ();
 error=validarfecha(reg.fecha_de_entrenamiento,actual) ;
 switch(error){
    case 1:
          cout<<"El año ingresado no es valido"<<endl;
          break;
    case 2:
          cout<<"El mes ingresado no es valido"<<endl;
          break;
    case 3:
          cout<<"El dia ingresado no es valido"<<endl;
          break;
    case 4:
          cout<<"Menor de edad"<<endl;
          break;
    default:
          break;}}
          while (error!=0);
 cout <<"ACTIVIDAD"<<endl;
 cin>> reg.actividad;
 //falta validad actividad
 cout <<"CALORIAS"<<endl;
 cin>> reg.calorias;
 while (reg.calorias<1){
                delline(13,APP_FORECOLOR,APP_BACKCOLOR);
                locate(1,13);
                cout<<"Error al ingresar los datos, vuelva a intentarlo."<<endl;
                cout<<endl;
                cout<<"Ingrese las calorias: ";
                cin>>reg.calorias;}
 cout <<"TIEMPO"<<endl;
 cin>> reg.tiempo;
 while(reg.tiempo<1){
              delline(13,APP_FORECOLOR,APP_BACKCOLOR);
              locate(1,13);
              cout<<"Error al ingresar los datos, vuelva a intentarlo."<<endl;
              cout<<endl;
              cout<<"Ingrese el tiempo en minutos";
              cin>>reg.tiempo;
 }
           reg.ID=0;

 return reg;
 }

Fecha fecha_entrenamiento (){
 Fecha reg;
 cout<<"DIA: ";
 cin>> reg.dia;
 cout<<"MES: ";
 cin>> reg.mes;
 cout<<"ANIO: ";
 cin>> reg.anio;
 return reg;
}

int generacion_de_ID (){
    int ID=0;
    FILE *P;
    Entrenamiento reg;

    P=fopen(file_entrenamiento, "rb+");

    if (P==NULL){
        return -1 ;
        }

    while (fread(&reg, sizeof(Entrenamiento),1,P)==1) {
     ID++;
     reg.ID=ID;
        }
    fseek(P,(ID-1)*sizeof(Entrenamiento),SEEK_SET);
    fwrite(&reg,sizeof(Entrenamiento),1,P);
    fclose(P);
    return ID;
}

bool guardar_entrenamiento ( Entrenamiento reg){
    bool grabo;
    FILE *P;
    P = fopen(file_entrenamiento, "ab");
    if (P == NULL){
        return false; }
    grabo = fwrite(&reg, sizeof(Entrenamiento), 1,P);
    fclose(P);
    anykey();
    cls();
    return grabo;
}

Entrenamiento leer_entrenamiento(int pos){
Entrenamiento reg;

 FILE *P=fopen(file_entrenamiento,"rb");
if(P==NULL){
    reg.ID==0;
    return reg;
}
  fseek(P,pos*sizeof(Entrenamiento),SEEK_SET);
  fread(&reg,sizeof(Entrenamiento),1,P);
  fclose(P);
  return reg;
}

void mostrar_entrenamiento (Entrenamiento reg){
    cout << "ID   : " << reg.ID<< endl;
    cout << "ID USUARIO: "<<reg.ID_usuarios<<endl;
    cout << "Fecha de entrenamiento: ";
    mostrar_fecha_de_nacimiento(reg.fecha_de_entrenamiento);
    cout<<"Actividad: "<<reg.actividad<<endl;
    cout<<"Calorias: "<<reg.calorias<<endl;
    cout<<"Tiempo: "<<reg.tiempo<<endl;

    }

bool guardar_modificacion_entrenamiento (Entrenamiento reg,int pos){
    bool grabo=true;
    FILE *P;
    P = fopen(file_entrenamiento, "rb+");
    if (P == NULL){
        return false;
    }
    fseek(P,pos*sizeof(Entrenamiento),SEEK_SET);
    grabo = fwrite(&reg, sizeof(Entrenamiento), 1, P);
    fclose(P);
    anykey();
    cls();
    return grabo;

}



void modificar_entrenamiento () {
 int id;
 Entrenamiento reg;
 cout <<"INGRESAR ID DE ENTRENAMIENTO: ";
 cin>> id;

        reg =leer_entrenamiento(id);
        mostrar_entrenamiento(reg);
        cout << endl;
        cout<<"-------------------------------------------"<<endl;
        cout<<"Ingrese el tiempo en minutos";
        cin>>reg.tiempo;
        while(reg.tiempo<1){
             // delline(13,APP_FORECOLOR,APP_BACKCOLOR);
             // locate(1,13);
              cout<<"Error al ingresar los datos, vuelva a intentarlo."<<endl;
              cout<<endl;
              cout<<"Ingrese el tiempo en minutos";
              cin>>reg.tiempo;
    }
        cout<<"Ingrese las calorias: ";
        cin>>reg.calorias;
        while (reg.calorias<1){
              //  delline(13,APP_FORECOLOR,APP_BACKCOLOR);
               // locate(1,13);
                cout<<"Error al ingresar los datos, vuelva a intentarlo."<<endl;
                cout<<endl;
                cout<<"Ingrese las calorias: ";
                cin>>reg.calorias;
                  }
        bool grabo=guardar_modificacion_entrenamiento(reg,id);
       if (grabo){
            cout<<"Entrenamiento guardado correctamente."<<endl;
        }
        else{
           cout<<endl<<endl<<"El entrenamiento no se guardó correctamente."<<endl;
        }
        anykey();
        cls();
}


void Listar_entrenamientos_por_ID (){
  int id,pos;
  cls();
  cout<<"Ingrese el ID: ";
  cin>>id;
  cout<<endl;
       Entrenamiento reg=leer_entrenamiento(id);
       mostrar_entrenamiento(reg);
       anykey();
       cls();
          }


void Listar_todos_los_entrenamientos (){
 Entrenamiento reg;
 FILE *P;
 P=fopen(file_entrenamiento, "rb");
 if (P==NULL){
    cout<<"No se pudo leer el archivo";
    return;
 }
 while (fread(&reg, sizeof(Entrenamiento),1, P)==1){
    mostrar_entrenamiento(reg);
    cout<<endl;
    }
    fclose(P);
    anykey();
    cls();

 }

 int validar_ID_Usuario(int ID){
int id;
id=ID;
 while(comparar(id)==false ){
            delline(1,APP_FORECOLOR,APP_BACKCOLOR);
            delline(2,APP_FORECOLOR,APP_BACKCOLOR);
            locate(1,1);
            cout<<"Error al ingresar los datos, vuelva a intentarlo."<<endl;
            cout << "Ingrese el ID   : " ;
            cin>>id;
   }
    return id;


 }
