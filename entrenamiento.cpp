#include <iostream>
#include "entrenamiento.h"
#include "Funciones.h"
#include "Strucs.h"
#include <cstdio>

#include <ctime>


using namespace std;

const char *file_entrenamiento = "entrenamiento.dat" ;


Entrenamiento nuevo_entrenamiento (){
 actual=hoy();
 int error=0;
 Entrenamiento reg;
 //Fecha date;
 int ID;
 cout <<"INGRESE ID DE USUARIO: "<<endl;
 cin>> reg.ID_usuarios;
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
 cout <<"CALORIAS"<<endl;
 cin>> reg.calorias;
 while (reg.calorias<1){
              //  delline(13,APP_FORECOLOR,APP_BACKCOLOR);
               // locate(1,13);
                cout<<"Error al ingresar los datos, vuelva a intentarlo."<<endl;
                cout<<endl;
                cout<<"Ingrese las calorias: ";
                cin>>reg.calorias;}
 cout <<"TIEMPO"<<endl;
 cin>> reg.tiempo;
 while(reg.tiempo<1){
             // delline(13,APP_FORECOLOR,APP_BACKCOLOR);
             // locate(1,13);
              cout<<"Error al ingresar los datos, vuelva a intentarlo."<<endl;
              cout<<endl;
              cout<<"Ingrese el tiempo en minutos";
              cin>>reg.tiempo;
 }
// ID=generacion_de_ID();
 cout << "ID";
 cout<< ID;
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

/*int generacion_de_ID (){
    int ID=0;
    FILE *P;
    P=fopen(file_entrenamiento, "rb");
    if (ID!=0){
        if (P==NULL){
        cout<<"ID NO GENERADO";
        anykey();
        return -1 ; }
      }

    Entrenamiento reg;
    while (fread(&reg, sizeof(Entrenamiento),1,P)==1) {
     ID=reg.ID;
        }
    ID++;
    return ID;
}
*/
bool guardar_entrenamiento ( Entrenamiento reg){
    bool grabo;
    FILE *P;
    P = fopen(file_entrenamiento, "ab");
    if (P == NULL){
        return false; }
    grabo = fwrite(&reg, sizeof(Entrenamiento), 1,P);
    fclose(P);
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
    cout<<" Actividad: "<<reg.actividad<<endl;
    cout<<"Calorias: "<<reg.calorias<<endl;
    cout<<"Tiempo: "<<reg.tiempo<<endl;
    }

bool guardar_modificacion_entrenamiento (Entrenamiento reg,int pos){
    bool grabo=true;
    FILE *P;
    P = fopen(file_usuario, "rb+");
    if (P == NULL){
        return false;
    }
    fseek(P,pos*sizeof(Entrenamiento),SEEK_SET);
    grabo = fwrite(&reg, sizeof(Entrenamiento), 1, P);
    fclose(P);
    return grabo;
}



void modificar_entrenamiento () {
 int id;
 cout <<"INGRESAR ID DE ENTRENAMIENTO: ";
 cin>> id;

 Entrenamiento reg =leer_entrenamiento(id);
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
        bool grabo=guardar_modificacion_entrenamiento(reg,pos);
       if (grabo){
            cout<<"Entrenamiento guardado correctamente."<<endl;
        }
        else{
           cout<<endl<<endl<<"El entrenamiento no se guardó correctamente."<<endl;
        }
        anykey();
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
          }
}

void Listar_todos_los_entrenamientos (){
 Entrenamiento reg;
 FILE *P
 P=fopen(file_entrenamiento, "rb");
 if (P==NULL){
    cout<<"No se pudo leer el archivo";
    return
 }
 while (fread(&reg, sizeof(Entrenamiento),1, P)==1){
    mostrar_entrenamiento(reg);
    cout<<endl;}
    fclose(P)

 }


