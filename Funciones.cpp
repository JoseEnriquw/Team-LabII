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

Campo cargar_usuario(){
    Campo reg;

    char Perfil_de_actividad;
    int Apto_medico,ID;
    float altura,Peso;

    cout << "Ingrese el ID   : " ;
    cin>>ID;
    while(ID<1 || comparar(ID)){
    cout<<"Error al ingresar los datos, vuelva a intentarlo."<<endl;
    cout << "Ingrese el ID   : " ;
    cin>>ID;

    }

    reg.ID=ID;
    cout<< endl;
    cin.ignore();
    cout << "Nombres  : ";
    cin.getline(reg.Nombres, 50);
    cout<< endl;
    cout << "Apellidos: ";
    cin.getline(reg.Apellidos, 50);
    cout<<endl;
    cout << "Ingrese el perfil de actividad : ";
    cin>>Perfil_de_actividad;
    while(Perfil_de_actividad!='A' || Perfil_de_actividad!='a' || Perfil_de_actividad!='B' || Perfil_de_actividad!='b' || Perfil_de_actividad!='c' || Perfil_de_actividad!='C'){
          cout<<"Error al ingresar los datos, vuelva a intentarlo."<<endl;
          cout << "Ingrese el perfil de actividad : ";
          cin>>Perfil_de_actividad;

    }

    reg.Perfil_de_actividad=Perfil_de_actividad;
    cout<<endl;
    cout << "Ingrese la fecha de nacimiento: "<<endl;
    reg.fecha_de_nacimiento=cagar_fecha_de_nacimiento();
    cout<<"Ingrese la altura en cms: ";
    cin>>altura;

    while(altura<1){
    cout<<"Error al ingresar los datos, vuelva a intentarlo."<<endl;
    cout<<"Ingrese la altura en cms: ";
    cin>>altura;

    }
    reg.Altura=altura;
    cout<<endl;

    cout<<"Ingrese el Peso en kilogramos: ";
    cin>>Peso;

    while(Peso<1){
    cout<<"Error al ingresar los datos, vuelva a intentarlo."<<endl;
    cout<<"Ingrese el Peso en kilogramos: ";
    cin>>Peso;

    }
    reg.Peso=Peso;
    cout<<endl;
    cout<<"Ingrese el apto medico(numero 0 o 1): ";
    cin>>Apto_medico;
    while(Apto_medico>1 || Apto_medico<0){
    cout<<"Error al ingresar los datos, vuelva a intentarlo."<<endl;
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
    cin>>nac.dia;
    rlutil::locate(3,1);
    cout << "/";
    rlutil::anykey();

    cin>>nac.mes;
    rlutil::locate(6,1);
    cout << "/";
    rlutil::anykey();
    cin>>nac.anio;

   actual=hoy();
   error=validarfecha(nac,actual);
    cout<<error<<endl;

    switch(error){
case 1:
    cout<<"El año ingresado no es valido"<<endl;
    break;

case 2:
    cout<<"El mes ingresado no es valido"<<endl;
    break

    case 3:
    cout<<"El dia ingresado no es valido"<<endl;
    break;

    case 4:
    cout<<"Menor de edad"<<endl;
    break;
    default:
        break;
    }
}while(error!=0);


return nac;
}


bool guardar_usuario(Campo reg){
    bool grabo;
    FILE *f;
    f = fopen(file_usuario, "ab");
    if (f == NULL){
        return false;
    }
    grabo = fwrite(&reg, sizeof(Campo), 1, f);
    fclose(f);
    return grabo;
}

bool guardar_usuario(Campo reg,int pos){
    bool grabo;
    FILE *f;
    f = fopen(file_usuario, "rb+");
    if (f == NULL){
        return false;
    }
    fseek(f,pos*sizeof(Campo),SEEK_SET);
    grabo = fwrite(&reg, sizeof(Campo), 1, f);
    fclose(f);
    return grabo;
}


void mostrar_usuario(Campo reg){



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

    for(int i=0;i<cant;i++){

      Campo reg=leer_Usuario(i);
      mostrar_usuario(reg);
      cout<<endl;
    }
}



int buscar_usuario(int ID_buscado){
    Campo reg;
    FILE *f;
    int pos=0;
    f = fopen(file_usuario, "rb");
    if (f == NULL){
        return -1;
    }
    while(fread(&reg, sizeof(Campo), 1, f)){
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

if(pos>=0){

    cout << endl << "Usuario a modificar: " << endl;
        cout << "---------------------------" << endl;
        Campo reg = leer_Usuario(pos);
        mostrar_usuario(reg);
        cout << endl;

        cout<<" Ingrese el nuevo peso: ";
        cin>>reg.Peso;
        cout<<endl;

        cout<<"Ingrese el nuevo Perfil de Atividad: ";
        cin>>reg.Perfil_de_actividad;
        cout<<endl;

        cout<<"Ingrese el nuevo Apto Medico: ";
        cin>>reg.Apto_medico;
        cout<<endl;

        bool grabo=guardar_usuario(reg,pos);

       /* if (guardar_usuario(reg, pos) == true){
            msj("Usuario guardado correctamente.", APP_FORECOLOR, APP_OKCOLOR);
            return true;
        }
        else{
            msj("El participante no se guardó correctamente.", APP_FORECOLOR, APP_ERRORCOLOR);
            return true;

        }*/

}else{

cout<<"No existe el participante."<<endl;
}


}

Campo leer_Usuario(int pos){
Campo reg;

 FILE *p=fopen(file_usuario,"rb");
if(p==NULL){
    reg.ID==0;
    return reg;
}
   fseek(p,pos*sizeof(Campo),SEEK_SET);
  fread(&reg,sizeof(Campo),1,p);

  fclose(p);
  return reg;
}

int cantidad_de_usuarios(){

  Campo reg;
  int cant=0;
  FILE *p;

  p=fopen(file_usuario,"rb");

 if (p == NULL){
        cout << "No se puede leer el archivo.";
        return 0;
    }
    while(fread(&reg, sizeof(Campo), 1, p))cant++;

  return cant;

}

void baja_usuario(){
int ID,pos;
FILE *p;


cout<<"Ingrese el ID del Usuario que desea dar de baja."<<endl;
cin>>ID;

pos=buscar_usuario(ID);

if(pos>=0){
        Campo reg = leer_Usuario(pos);
        reg.Estado=false;

        bool grabo=guardar_usuario(reg,pos);

        cout<<"Se elimino el usuario"<<endl;
}else{

cout<<"No existe el participante."<<endl;
}

}

void listar_usuarios_x_ID(){
int id,pos;


cout<<"Ingrese el ID: ";
cin>>id;
cout<<endl;

pos=buscar_usuario(id);
if(pos==-1)cout<<"No se encontro el Usuario buscado."<<endl;
else{

    Campo reg=leer_Usuario(pos);
     system("cls");
     mostrar_usuario(reg);
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

 if(nac.anio>actual.anio || nac.anio<1920)error=1;

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

    if(error==0){

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
