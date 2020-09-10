#include <iostream>
using namespace std;
#include "Funciones.h"
#include "Strucs.h"
#include <cstdio>
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;
const char *file_usuario="Archivo.dat";

Campo cargar_usuario(){
    Campo reg;

    cout << "Ingrese el ID   : " ;
    cin>>reg.ID;
    cout<< endl;
    cin.ignore();
    cout << "Nombres  : ";
    cin.getline(reg.Nombres, 50);
    cout<< endl;
    cout << "Apellidos: ";
    cin.getline(reg.Apellidos, 50);
    cout<<endl;
    cout << "Ingrese el perfil de actividad : ";
    cin>>reg.Perfil_de_actividad;
    cout<<endl;
    cout << "Ingrese la fecha de nacimiento: "<<endl;
    reg.fecha_de_nacimiento=cagar_fecha_de_nacimiento();
    cout<<"Ingrese la altura en cms: ";
    cin>>reg.Altura;
    cout<<endl;
    cout<<"Ingrese el Peso en kilogramos: ";
    cin>>reg.Peso;
    cout<<endl;
    cout<<"Ingrese el apto medico: ";
    cin>>reg.Apto_medico;
    cout<<endl;
    cout<<"Ingrese el estado: ";
    cin>>reg.Estado;
    cout<<endl;

return reg;
}

Fecha cagar_fecha_de_nacimiento(){
 Fecha nac;

 cin>>nac.dia;
 cin>>nac.mes;
cin>>nac.anio;

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






