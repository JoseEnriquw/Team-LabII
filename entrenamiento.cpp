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
const char *file_entrenamiento = "Datos/Entrenamientos.dat" ;
const char *file_usuario="Datos/Usuarios.dat";
//FUNCION PARA CARGAR UN NUEVO ENTRENAMIENTO
Entrenamiento nuevo_entrenamiento (){
    Fecha actual;
    actual=hoy();
    int error=0;
    Entrenamiento reg;
    int ID_usuarios, actividad;
    bool seguir=true;
    reg.ID=cantidad_entrenamiento() +1;
    cout <<"INGRESE ID DE USUARIO: ";
    cin>>ID_usuarios;
    reg.ID_usuarios=validar_ID_Usuario(ID_usuarios);//VALIDAMOS QUE EL ID DE USUARIO ESTE OK
    do{

            reg.fecha_de_entrenamiento= fecha_entrenamiento ();//CARGO LA FECHA
            error=validarfecha(reg.fecha_de_entrenamiento,actual);//VALIDO LA FECHA
    switch(error){
        case 1:
            cout<<"El a�o ingresado no es valido"<<endl;
            break;
        case 2:
            cout<<"El mes ingresado no es valido"<<endl;
            break;
        case 3:
            cout<<"El dia ingresado no es valido"<<endl;
            break;
        default:
            break;}}
            while (error!=0);
            cout<<endl;
    cout <<"ACTIVIDAD"<<endl;
    cin>> actividad;
    do{//VALIDAMOS LA ACTIVIDAD
            switch(actividad){
            case 1:
            case 2:
            case 3:
                   seguir=true;
                    break;
            case 4:
            case 5:
                   seguir=validar_actividad(ID_usuarios);//VALIDMAOS EL APTO MEDICO DEL USUARIO
                   if(seguir==false){
                   cout<<"No tiene el apto medico"<<endl;
                   anykey();
                   reg.ID=-1;
                   return reg;
                   }
                   break;
            default:
                    delline(7,APP_FORECOLOR,APP_BACKCOLOR);
                    delline(8,APP_FORECOLOR,APP_BACKCOLOR);
                    locate(1,7);
                    cout<<"Error al ingresar los datos, vuelva a intentarlo."<<endl;
                    cout << "Ingrese la actividad : ";
                    cin>>actividad;
                    break;
                 }
            } while (!seguir);
    reg.actividad=actividad;
    cout<<endl;
    cout <<"CALORIAS"<<endl;
    cin>> reg.calorias;
    while (reg.calorias<1){//VALIDAMOS LAS CALORIAS
                delline(13,APP_FORECOLOR,APP_BACKCOLOR);
                locate(1,13);
                cout<<"Error al ingresar los datos, vuelva a intentarlo."<<endl;
                cout<<endl;
                cout<<"Ingrese las calorias: ";
                cin>>reg.calorias;}
    cout<<endl;
    cout <<"TIEMPO"<<endl;
    cin>> reg.tiempo;
    while(reg.tiempo<1){//VALIDAMOS EL TIEMPO
              delline(13,APP_FORECOLOR,APP_BACKCOLOR);
              locate(1,13);
              cout<<"Error al ingresar los datos, vuelva a intentarlo."<<endl;
              cout<<endl;
              cout<<"Ingrese el tiempo en minutos";
              cin>>reg.tiempo;
              cout<<endl;
 }
    return reg;
 }
//FUNCION PARA CARGAR LA FECHA
Fecha fecha_entrenamiento (){
    Fecha reg;
    int x,y;
           x=1;
            y=3;
            delline(y,APP_FORECOLOR,APP_BACKCOLOR);
            locate(x,y);
            cout<<"INGRESE LA FECHA DE ENTRENAMIENTO: "<<endl;
            cin>>reg.dia;
            locate(x+=2,y+1);
            cin.ignore();
            cout<<"/";
            cin>>reg.mes;
            locate(x+=3,y+1);
            cin.ignore();
            cout<<"/";
            cin>>reg.anio;

    return reg;
}
//FUNCION PARA CONTAR LA CANT DE STRUCTS DE ENTRENAMIENTOS QUE TENEMOS EN ARCHIVO
int cantidad_entrenamiento(){
    FILE *p = fopen(file_entrenamiento, "rb");
    if (p == NULL){
        return 0;
    }
    int bytes, cant;
    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    cant = bytes / sizeof(Entrenamiento);
    return cant;
}
//FUNCION PARA GUARDAR EL ENTRENAMIENTO EN ARCHIVOS RECIBIENDO UN STRUCT
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
// FUNCION QUE DEVUELVE UN STRUCT DE ENTRENAMIENTO CON LOS DATOS CARGADOS EN ARCHIVOS SEGUN LA POSICION
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
//FUNCION PARA MOSTRAR UN ENTRENMAIENTO RECIBIENDO EL STRUCT
void mostrar_entrenamiento (Entrenamiento reg){
    cout << "ID   : " << reg.ID<< endl;
    cout << "ID USUARIO: "<<reg.ID_usuarios<<endl;
    cout << "Fecha de entrenamiento: ";
    mostrar_fecha_de_nacimiento(reg.fecha_de_entrenamiento);
    cout<<"Actividad: "<<reg.actividad<<endl;
    cout<<"Calorias: "<<reg.calorias<<endl;
    cout<<"Tiempo: "<<reg.tiempo<<endl;
    }
//FUNCION QUE RECIBE UN STRUCT Y UNA POSICION PARA GUARDAR SU MODIFICACION
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

//FUNCION PARA MODIFICAR UN ENTRENAMIENTO
void modificar_entrenamiento () {
    int id;
    Entrenamiento reg;
    cout <<"INGRESAR ID DE ENTRENAMIENTO: ";
    cin>> id;
    reg =leer_entrenamiento(id-1);
    mostrar_entrenamiento(reg);
    cout << endl;
    cout<<"-------------------------------------------"<<endl;
    cout<<"Ingrese el tiempo en minutos: ";
    cin>>reg.tiempo;
    while(reg.tiempo<1){
             delline(10,APP_FORECOLOR,APP_BACKCOLOR);
             locate(1,10);
              cout<<"Error al ingresar los datos, vuelva a intentarlo."<<endl;
              cout<<"Ingrese el tiempo en minutos: ";
              cin>>reg.tiempo;
              cout<<endl;
    }
    cout<<"Ingrese las calorias: ";
    cin>>reg.calorias;
    while (reg.calorias<1){
              delline(12,APP_FORECOLOR,APP_BACKCOLOR);
              locate(1,12);
              cout<<"Error al ingresar los datos, vuelva a intentarlo."<<endl;

              cout<<"Ingrese las calorias: ";
              cin>>reg.calorias;
                  }
    bool grabo=guardar_modificacion_entrenamiento(reg,id-1);
    if (grabo){
            delline(1,APP_FORECOLOR,APP_OKCOLOR);
            locate(1,1);
            cout<<"Entrenamiento guardado correctamente."<<endl;
        }
    else{
            delline(1,APP_FORECOLOR,APP_ERRORCOLOR);
            locate(1,1);
            cout<<"El entrenamiento no se guard� correctamente."<<endl;
        }
    anykey();
    delline(1,APP_FORECOLOR,APP_BACKCOLOR);
    cls();
}

//FUNCION PARA LISTAR EL ENTRENAMIENTO POR ID!
void Listar_entrenamientos_por_ID (){
  int id;
  cls();
  cout<<"Ingrese el ID: ";
  cin>>id;
  cout<<endl;
       Entrenamiento reg=leer_entrenamiento(id-1);
       mostrar_entrenamiento(reg);
       anykey();
       cls();
  }

//FUNCION QUE LISTA TODOS LOS ENTRENAMIENTOS EN ARCHIVOS
void Listar_todos_los_entrenamientos (){
 Entrenamiento reg;
 FILE *P;
 P=fopen(file_entrenamiento, "rb");
 if (P==NULL){
    cout<<"No se pudo leer el archivo";
    return;
 }
 while (fread(&reg, sizeof(Entrenamiento),1, P)==1){
        int pos=buscar_usuario(reg.ID_usuarios);
        Usuarios aux=leer_Usuario(pos);
        if(aux.Estado==false) cout<<"Este usuario fue dado de baja:"<<endl;
        mostrar_entrenamiento(reg);
        cout<<endl;
    }
    fclose(P);
    anykey();
    cls();
 }
//FUNCION PARA VALIDAR QUE EL IDSUAURIO ESTE OK
int validar_ID_Usuario(int ID){
    int id;
    id=ID;
    while(comparar(id)==false){
            delline(1,APP_FORECOLOR,APP_BACKCOLOR);
            delline(2,APP_FORECOLOR,APP_BACKCOLOR);
            locate(1,1);
            cout<<"Error al ingresar los datos, vuelva a intentarlo."<<endl;
            cout<<"Ingrese el ID   : " ;
            cin>>id;
   }
    return id;
}
//FUNCION PARA VALIDAR QUE EL USUARIO TENGA EL APTO MEDICO OK
bool validar_actividad(int ID_usuarios){
   Usuarios reg;
   int pos;
   bool apto=false;
   pos=buscar_usuario (ID_usuarios);
   FILE *P;
   P=fopen(file_usuario, "rb");
   if (P==NULL){
       cout<<"Error en archivo";
       return apto;
   }
   fseek(P,pos*sizeof(Usuarios),0);
   fread(&reg, sizeof(Usuarios),1,P);
   apto=reg.Apto_medico;
   fclose(P);

   return apto;
}
//FUNCION PARA MOSTRAR LOS ENTRENAMIENTOS POR ID DE USUARIO
void Listar_entrenamiento_por_Usuarios (){
    Usuarios reg;
    int id_usuario;
    int pos;
    cout<<"Ingrese el ID de usuario: ";
    cin>>id_usuario;
    pos=buscar_usuario(id_usuario);
    if (pos==-1){
        cout<<"El usuario no existe"<<endl;
        return;
    }
    reg=leer_Usuario(pos);
    if (reg.Estado==true) Listar_entrenamientos_por_ID_Usuario (id_usuario);
    else  cout<<"El usuario fue dado de baja.";
    anykey();
    cls();
 }

//FUNCION PARA MOSTRAR TODOS LOS ENTRENAMIENTOS QUE TIENE UN USUARIO
void Listar_entrenamientos_por_ID_Usuario (int id_usuario){
    Entrenamiento reg;
    FILE *F;
    F=fopen(file_entrenamiento, "rb");
    if (F==NULL){
        cout<<"No se pudo leer el archivo";
        return;
    }
    while (fread(&reg, sizeof(Entrenamiento), 1,F)==1){
        if(reg.ID_usuarios==id_usuario){
                cout<<endl;
            mostrar_entrenamiento (reg);

          }
    }
    fclose(F);
    anykey();
    cls();
}
