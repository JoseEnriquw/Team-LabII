#include <iostream>
using namespace std;
#include "Funciones.h"
#include "Strucs.h"
#include <cstdio>
#include "ui.h"
#include <ctime>
#include "rlutil.h"
using namespace rlutil;
const char *file_usuario="Archivo.dat";


Usuarios cargar_usuario(){
    Usuarios reg;
    cls();
    char Perfil_de_actividad;
    int Apto_medico,ID;
    float altura,Peso;
    bool seguir=true;
    cout << "Ingrese el ID   : " ;
    cin>>ID;
    while(ID<1 || comparar(ID)){
            delline(1,APP_FORECOLOR,APP_BACKCOLOR);
            cout<<"Error al ingresar los datos, vuelva a intentarlo.";
            locate(1,2);
            cout << "Ingrese el ID   : " ;
            cin>>ID;
   }
    reg.ID=ID;
    cout<< endl;
    cin.ignore();
    cout << "Nombres  : ";
    cin.getline(reg.Nombres, 50);
    cout<< endl;
    while(reg.Nombres[0]=='\0'){
        delline(3,APP_FORECOLOR,APP_BACKCOLOR);
        cout<<"Error al ingresar los datos, vuelva a intentarlo.";
        locate(1,4);
        cout << "Nombres  : ";
        cin.getline(reg.Nombres, 50);
        cout<< endl;
    }
    cout << "Apellidos: ";
    cin.getline(reg.Apellidos, 50);
    cout<<endl;
    while(reg.Apellidos[0]=='\0'){
        delline(5,APP_FORECOLOR,APP_BACKCOLOR);
        cout<<"Error al ingresar los datos, vuelva a intentarlo.";
        locate(1,6);
        cout << "Apellidos  : ";
        cin.getline(reg.Apellidos, 50);
        cout<< endl;
    }
    cout << "Ingrese el perfil de actividad : ";
    cin>>Perfil_de_actividad;
    while(seguir){
            switch(Perfil_de_actividad){
            case 'A':
            case 'a':
            case 'B':
            case 'b':
            case 'C':
            case 'c':
            seguir=false;
            break;
            default:
            seguir=true;
            break;
            }
    if(seguir){
            delline(7,APP_FORECOLOR,APP_BACKCOLOR);
            cout<<"Error al ingresar los datos, vuelva a intentarlo.";
            locate(1,8);
            cout << "Ingrese el perfil de actividad : ";
            cin>>Perfil_de_actividad;
}
}

    reg.Perfil_de_actividad=Perfil_de_actividad;
    cout<<endl;
    reg.fecha_de_nacimiento=cagar_fecha_de_nacimiento();
    cout<<"Ingrese la altura en cms: ";
    cin>>altura;
    while(altura<1){
        delline(9,APP_FORECOLOR,APP_BACKCOLOR);
        cout<<"Error al ingresar los datos, vuelva a intentarlo.";
        locate(1,10);
        cout<<"Ingrese la altura en cms: ";
        cin>>altura;
   }
    reg.Altura=altura;
    cout<<endl;
    cout<<"Ingrese el Peso en kilogramos: ";
    cin>>Peso;
    while(Peso<1){
        delline(11,APP_FORECOLOR,APP_BACKCOLOR);
        cout<<"Error al ingresar los datos, vuelva a intentarlo.";
        locate(1,12);
        cout<<"Ingrese el Peso en kilogramos: ";
        cin>>Peso;
    }
    reg.Peso=Peso;
    cout<<endl;
    cout<<"Ingrese el apto medico(numero 0 o 1): ";
    cin>>Apto_medico;
    while(Apto_medico>1 || Apto_medico<0){
        delline(13,APP_FORECOLOR,APP_BACKCOLOR);
        cout<<"Error al ingresar los datos, vuelva a intentarlo.";
        locate(1,14);
        cout<<"Ingrese el apto medico(numero 0 o 1): ";
        cin>>Apto_medico ;
    }
    reg.Apto_medico=Apto_medico;
    cout<<endl;
    reg.Estado=1;
    cout<<endl;
return reg;
}

Fecha cagar_fecha_de_nacimiento(){
    Fecha nac,actual;
    int error;
    do{
        cout << "Ingrese la fecha de nacimiento: "<<endl;
        cout<<"Ingrese el dia:";
        cin>>nac.dia;
        cout<<endl;
        cout<<"Ingrese el mes:";
        cin>>nac.mes;
        cout<<endl;
        cout<<"Ingrese el año:";
        cin>>nac.anio;
        cout<<endl;
        actual=hoy();
        error=validarfecha(nac,actual);
    if(error==0){
        error=validaredad(nac,actual);
    }
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
          break;
    }
    anykey();
    cls();
}while(error!=0);
return nac;
}


bool guardar_usuario(Usuarios reg){
    bool grabo;
    FILE *f;
    f = fopen(file_usuario, "ab");
    if (f == NULL){
        return false;
    }
    grabo = fwrite(&reg, sizeof(Usuarios), 1, f);
    fclose(f);
    return grabo;
}

bool guardar_usuario(Usuarios reg,int pos){
    bool grabo;
    FILE *f;
    f = fopen(file_usuario, "rb+");
    if (f == NULL){
        return false;
    }
    fseek(f,pos*sizeof(Usuarios),SEEK_SET);
    grabo = fwrite(&reg, sizeof(Usuarios), 1, f);
    fclose(f);
    return grabo;
}


void mostrar_usuario(Usuarios reg){
if(reg.Estado){
    cout << "ID   : " << reg.ID << endl;
    cout << "Apellidos: "<<reg.Apellidos<<endl;
    cout << "Nombres  : "<<reg.Nombres<<endl;
    cout << "Perfil de actividad : " << reg.Perfil_de_actividad << endl;
    cout << "Fecha de nacimiento: ";
    mostrar_fecha_de_nacimiento(reg.fecha_de_nacimiento);
    cout<<" Altura: "<<reg.Altura<<endl;
    cout<<"Peso: "<<reg.Peso<<endl;
    cout<<"Apto medico: "<<reg.Apto_medico<<endl;
    cout<<"Estado: "<<reg.Estado<<endl;
}
else{
    cout<<"El usuario no se encuentra o fue dado de baja"<<endl;
}
}

void mostrar_fecha_de_nacimiento(Fecha nac){
    cout<<nac.dia<<" / "<<nac.mes<<" / "<<nac.anio<<endl;
}

void listar_todos_los_usuarios(){
      int cant=cantidad_de_usuarios();
      cls();
      for(int i=0;i<cant;i++){
      Usuarios reg=leer_Usuario(i);
      if(reg.Estado)mostrar_usuario(reg);
      cout<<endl;
    }
    anykey();
}



int buscar_usuario(int ID_buscado){
    Usuarios reg;
    FILE *f;
    int pos=0;
    f = fopen(file_usuario, "rb");
    if (f == NULL){
        return -1;
    }
    while(fread(&reg, sizeof(Usuarios), 1, f)){
        if (ID_buscado == reg.ID){
          fclose(f);
          return pos;
        }
        pos++;
    }
    fclose(f);
    return -1;
}


void modificar_usuario(){
int ID,pos;
FILE *p;
cout<<"Ingrese el ID del Usuario que desea modificar."<<endl;
cin>>ID;
pos=buscar_usuario(ID);
Usuarios reg = leer_Usuario(pos);
if(pos>=0 && reg.Estado){
        delline(2,APP_FORECOLOR,APP_BACKCOLOR);
        title("Usuario a modificar ",APP_TITLEFORECOLOR,APP_TITLEBACKCOLOR);
        cout << endl << endl;
        mostrar_usuario(reg);
        cout << endl;
        cout<<"-------------------------------------------"<<endl;
        cout<<"Ingrese el Peso en kilogramos: ";
        cin>>reg.Peso;
while(reg.Peso<1){
        delline(13,APP_FORECOLOR,APP_BACKCOLOR);
        locate(1,13);
        cout<<"Error al ingresar los datos, vuelva a intentarlo."<<endl;
        cout<<"Ingrese el Peso en kilogramos: ";
        cin>>reg.Peso;
        cout<<endl;
    }
     bool seguir=1;
    cout << "Ingrese el perfil de actividad : ";
    cin>>reg.Perfil_de_actividad;
    while(seguir){
        switch(reg.Perfil_de_actividad){
        case 'A':
        case 'a':
        case 'B':
        case 'b':
        case 'C':
        case 'c':
        seguir=false;
        break;
        default:
        seguir=true;
        break;
    }
  if(seguir){
            delline(15,APP_FORECOLOR,APP_BACKCOLOR);
            locate(1,15);
            cout<<"Error al ingresar los datos, vuelva a intentarlo."<<endl;
            cout << "Ingrese el perfil de actividad : ";
            cin>>reg.Perfil_de_actividad;
}
    }
    cout<<endl;
    cout<<"Ingrese el apto medico(numero 0 o 1): ";
    cin>>reg.Apto_medico;
    while(reg.Apto_medico>1 || reg.Apto_medico<0){
        delline(17,APP_FORECOLOR,APP_BACKCOLOR);
        locate(1,17);
        cout<<"Error al ingresar los datos, vuelva a intentarlo."<<endl;
        cout<<"Ingrese el apto medico(numero 0 o 1): ";
        cin>>reg.Apto_medico ;
    }
    cout<<endl;
    bool grabo=guardar_usuario(reg,pos);
    if (grabo){
            cout<<"Usuario guardado correctamente."<<endl;
       }
        else{
           cout<<endl<<endl<<"El participante no se guardó correctamente."<<endl;
       }
}else{
cout<<endl<<endl<<"No existe este usuario."<<endl;
}
anykey();
}

Usuarios leer_Usuario(int pos){
        Usuarios reg;
        FILE *p=fopen(file_usuario,"rb");
        if(p==NULL){
            reg.ID==0;
            return reg;
}
    fseek(p,pos*sizeof(Usuarios),SEEK_SET);
    fread(&reg,sizeof(Usuarios),1,p);
    fclose(p);
    return reg;
}

int cantidad_de_usuarios(){
  Usuarios reg;
  int cant=0;
  FILE *p;
  p=fopen(file_usuario,"rb");
  if (p == NULL){
        cout << "No se puede leer el archivo.";
        return 0;
    }
  while(fread(&reg, sizeof(Usuarios), 1, p))cant++;
  return cant;
}

void baja_usuario(){
    int ID,pos;
    FILE *p;
    cls();
    cout<<"Ingrese el ID del Usuario que desea dar de baja."<<endl;
    cin>>ID;
    pos=buscar_usuario(ID);
if(pos>=0){
        Usuarios reg = leer_Usuario(pos);
        reg.Estado=false;
        bool grabo=guardar_usuario(reg,pos);
        cout<<"Se elimino el usuario"<<endl;
}else{
    cout<<"No existe el participante."<<endl;
}
}

void listar_usuarios_x_ID(){
    int id,pos;
    cls();
    cout<<"Ingrese el ID: ";
    cin>>id;
    cout<<endl;
    pos=buscar_usuario(id);
if(pos==-1)cout<<"No se encontro el Usuario buscado."<<endl;
else{
    Usuarios reg=leer_Usuario(pos);
    mostrar_usuario(reg);
    anykey();
}
}
bool comparar(int id){
    bool a=true;
    int pos=buscar_usuario(id);
    if(pos==-1){
        a=false;
        return a;
    }
    return a;
}



Fecha hoy () {
    time_t t;
    t = time (NULL);
    struct tm *f;
    f= localtime (&t);
    Fecha aux;
    aux.anio= f-> tm_year +1900;
    aux.mes= f->tm_mon +1;
    aux.dia= f->tm_mday;
    return aux;
 }

int validarfecha(Fecha nac,Fecha actual){
    int error=0;
    if(nac.anio>actual.anio || nac.anio<1920 || (nac.anio==actual.anio && nac.mes==actual.mes && nac.dia>actual.dia) || (nac.anio==actual.anio && nac.mes>actual.mes) )error=1;
    else{
    switch(nac.mes){
    case 1:
        if(nac.dia<1 || nac.dia>31)error=3;
        break;
    case 2:
        if(nac.dia<1 || nac.dia>29)error=3;
        break;
    case 3:
        if(nac.dia<1 || nac.dia>31)error=3;
        break;
    case 4:
        if(nac.dia<1 || nac.dia>30)error=3;
        break;
    case 5:
        if(nac.dia<1 || nac.dia>31)error=3;
        break;
    case 6:
        if(nac.dia<1 || nac.dia>30)error=3;
        break;
    case 7:
        if(nac.dia<1 || nac.dia>31)error=3;
        break;
    case 8:
        if(nac.dia<1 || nac.dia>31)error=3;
        break;
    case 9:
        if(nac.dia<1 || nac.dia>30)error=3;
        break;
    case 10:
        if(nac.dia<1 || nac.dia>31)error=3;
        break;
    case 11:
        if(nac.dia<1 || nac.dia>30)error=3;
        break;
    case 12:
        if(nac.dia<1 || nac.dia>31)error=3;
        break;
    default:
        error=2;
        break;
    }
   return error;
 }
 }

 int validaredad(Fecha nac,Fecha actual){
     int error=0,edad;
     if(nac.mes<actual.mes) edad=actual.anio-nac.anio;
        else if(nac.mes==actual.mes && nac.dia<=actual.dia) edad=actual.anio-nac.anio;
        else edad=actual.anio-nac.anio-1;
     if(edad<13)error=4;
     return error;
 }
