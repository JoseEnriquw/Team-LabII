#include <iostream>
#include "Funciones.h"
#include "Strucs.h"
#include <cstdio>
#include "ui.h"
#include <ctime>
#include "rlutil.h"
using namespace std;
using namespace rlutil;
const char *fil_usuario="Datos/Usuarios.dat";

///FUNCION CARGAR STRUCT DE USUARIO
Usuarios cargar_usuario(){
    Usuarios reg;
    cls();
    char Perfil_de_actividad;
    int Apto_medico,ID;
    float altura,Peso;
    bool seguir=true;
    cout << "Ingrese el ID   : " ;
    cin>>ID;
    while(ID<1 || comparar(ID)){//LLAMA A FUNCION COMPARAR ID
            delline(1,APP_FORECOLOR,APP_BACKCOLOR);
            delline(2,APP_FORECOLOR,APP_BACKCOLOR);
            locate(1,1);
            cout<<"Error al ingresar los datos, vuelva a intentarlo."<<endl;
            cout <<"Ingrese el ID   : " ;
            cin>>ID;
   }
    reg.ID=ID;
    cout<< endl;
    cin.ignore();
    cout <<"Nombres  : ";
    cin.getline(reg.Nombres, 50);
    cout<< endl;
    ///VALIDAMOS QUE EL NOMBRE NO CONTENGA ESPACIO VACIO
    while(reg.Nombres[0]=='\0'){
        delline(3,APP_FORECOLOR,APP_BACKCOLOR);
        delline(4,APP_FORECOLOR,APP_BACKCOLOR);
        locate(1,3);
        cout<<"Error al ingresar los datos, vuelva a intentarlo."<<endl;
        cout <<"Nombres  : ";
        cin.getline(reg.Nombres, 50);
        cout<<endl;
    }
    cout <<"Apellidos: ";
    cin.getline(reg.Apellidos, 50);
    cout<<endl;
    ///VALIDAMOS QUE EL APELLIDO NO TENGA ESPACIO VACIO
    while(reg.Apellidos[0]=='\0'){
        delline(5,APP_FORECOLOR,APP_BACKCOLOR);
        delline(6,APP_FORECOLOR,APP_BACKCOLOR);
        locate(1,5);
        cout<<"Error al ingresar los datos, vuelva a intentarlo."<<endl;
        cout<<"Apellidos  : ";
        cin.getline(reg.Apellidos, 50);
        cout<<endl;
    }
    cout<<"Ingrese el perfil de actividad : ";
    cin>>Perfil_de_actividad;
    while(seguir){
            switch(Perfil_de_actividad){ ///VALIDAMOS QUE LA OPCION ESTE DENTRO DE LAS POSIBLES
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
            delline(8,APP_FORECOLOR,APP_BACKCOLOR);
            locate(1,7);
            cout<<"Error al ingresar los datos, vuelva a intentarlo."<<endl;
            cout<<"Ingrese el perfil de actividad : ";
            cin>>Perfil_de_actividad;
             }
}

    reg.Perfil_de_actividad=Perfil_de_actividad;
    cout<<endl;
    ///VALIDAMOS LA FECHA DE NAC
    reg.fecha_de_nacimiento=cagar_fecha_de_nacimiento();
    if(reg.fecha_de_nacimiento.anio==0){
            reg.Estado=false;
        return reg;
    }
    cout<<"Ingrese la altura en cms: ";
    cin>>altura;
    ///VALIDAMOS LA ALTURA
    while(altura<1){
        delline(9,APP_FORECOLOR,APP_BACKCOLOR);
        delline(10,APP_FORECOLOR,APP_BACKCOLOR);
        locate(1,9);
        cout<<"Error al ingresar los datos, vuelva a intentarlo."<<endl;
        cout<<"Ingrese la altura en cms: ";
        cin>>altura;
   }
    reg.Altura=altura;
    cout<<endl;
    cout<<"Ingrese el Peso en kilogramos: ";
    cin>>Peso;
    ///VALIDAMOS EL PESO
    while(Peso<1){
        delline(11,APP_FORECOLOR,APP_BACKCOLOR);
        delline(12,APP_FORECOLOR,APP_BACKCOLOR);
        locate(1,11);
        cout<<"Error al ingresar los datos, vuelva a intentarlo."<<endl;
        cout<<"Ingrese el Peso en kilogramos: ";
        cin>>Peso;
    }
    reg.Peso=Peso;
    cout<<endl;
    cout<<"Ingrese 1 si posee el apto medico, 0 sino lo tiene: ";
    cin>>Apto_medico;
    while(Apto_medico>1 || Apto_medico<0){
        delline(13,APP_FORECOLOR,APP_BACKCOLOR);
        delline(14,APP_FORECOLOR,APP_BACKCOLOR);
        locate(1,13);
        cout<<"Error al ingresar los datos, vuelva a intentarlo."<<endl;
        cout<<"Ingrese 1 si posee el apto medico, 0 sino lo tiene: ";
        cin>>Apto_medico;
    }
    reg.Apto_medico=Apto_medico;
    cout<<endl;
    reg.Estado=1;
    cout<<endl;
return reg;
}

///FUNCION CARGAR FECHA DE NAC
Fecha cagar_fecha_de_nacimiento(){
    Fecha nac,actual;
    int error,x,y;

    do{
            x=1;
            y=9;
            delline(y,APP_FORECOLOR,APP_BACKCOLOR);
            locate(x,y);
            cout<<"Ingrese la fecha de nacimiento: ";
            cin>>nac.dia;
            locate(x+=34,y);
            cin.ignore();
            cout<<"/";
            cin>>nac.mes;
            locate(x+=3,y);
            cin.ignore();
            cout<<"/";
            cin>>nac.anio;
            cout<<endl;



        actual=hoy();
        error=validarfecha(nac,actual);///LLAMAMOS A LA FUNCION PARA QUE NOS VALIDE LA FECHA

    if(error==0){
        error=validaredad(nac,actual);/// SI DA OK, LLAMAMOS A LA FUNCION PARA VALIDAR LA EDAD
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
          cout<<"Menor de edad, vuelva a ingresar los datos"<<endl;
           anykey();
          nac.anio=0;
          return nac;
          break;
    default:
          break;
    }
       anykey();
       delline(y+2,APP_FORECOLOR,APP_BACKCOLOR);


}while(error!=0);
 locate(1,y+2);
return nac;
}

///FUNCION PARA VALIDAR LA FECHA INGRESADA VS LA FECHA ACTUAL
int validarfecha(Fecha nac,Fecha actual){
    int error=0;
    bool anio;
    if(nac.anio>actual.anio || nac.anio<1920 || (nac.anio==actual.anio && nac.mes==actual.mes && nac.dia>actual.dia) || (nac.anio==actual.anio && nac.mes>actual.mes) )error=1;
    else{
    switch(nac.mes){
    case 1:
        if(nac.dia<1 || nac.dia>31)error=3;
        break;
    case 2:
        ///VALIDAR AÑO BISIESTO
        anio=anio_bisiesto(nac.anio);

        if(anio){ if(nac.dia<1 || nac.dia>29)error=3;}
        else { if(nac.dia<1 || nac.dia>28)error=3;}

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

 }
 return error;
 }

///FUNCION GUARDAR USUARIO QUE RECIBE UN STRUCT USUARIO
bool guardar_usuario(Usuarios reg){
    bool grabo;
    FILE *f;
    f = fopen(fil_usuario, "ab");
    if (f == NULL){
        return false;
    }
    grabo = fwrite(&reg, sizeof(Usuarios), 1, f);
    fclose(f);
    return grabo;
}
///FUNCION GUARDAR USUARIO RECIBIENDO UN STRUCT REG Y LA POSICION DE ESTE EN EL ARCHIVO
bool guardar_usuario(Usuarios reg,int pos){
    bool grabo;
    FILE *f;
    f = fopen(fil_usuario, "rb+");
    if (f == NULL){
        return false;
    }
    fseek(f,pos*sizeof(Usuarios),SEEK_SET);
    grabo = fwrite(&reg, sizeof(Usuarios), 1, f);
    fclose(f);
    return grabo;
}

///FUNCION MOSTRAR USUARIO RECIBE UN STRUCT DE USUARIO
void mostrar_usuario(Usuarios reg){
if(reg.Estado){ // SI EL ESTADO ES TRUE LO MUESTRA
    cout << "ID   : " << reg.ID << endl;
    cout << "Apellidos: "<<reg.Apellidos<<endl;
    cout << "Nombres  : "<<reg.Nombres<<endl;
    cout << "Perfil de actividad : " << reg.Perfil_de_actividad << endl;
    cout << "Fecha de nacimiento: ";
    mostrar_fecha_de_nacimiento(reg.fecha_de_nacimiento); //LLAMA A FUNCION FECHA DE NAC
    cout<<" Altura: "<<reg.Altura<<endl;
    cout<<"Peso: "<<reg.Peso<<endl;
    cout<<"Apto medico: "<<reg.Apto_medico<<endl;
    cout<<"Estado: "<<reg.Estado<<endl;
}
else{
    cout<<"El usuario no se encuentra o fue dado de baja"<<endl;
}
}
/// FUNCION PARA MOSTRAR LA FECHA BONITA :D
void mostrar_fecha_de_nacimiento(Fecha nac){
    cout<<nac.dia<<" / "<<nac.mes<<" / "<<nac.anio<<endl;
}
///FUNCION PARA MOSTRAR TODOS LOS USUARIOS
void listar_todos_los_usuarios(){
      int cant=cantidad_de_usuarios();//LLAMO A LA FUNCION CANTIDAD DE USUARIOS PARA SABER CUANTOS REGISTROS TENGO
      cls();
      for(int i=0;i<cant;i++){
            Usuarios reg=leer_Usuario(i);//LLAMO A LEER USUARIO Y LE PASO LA POSICION

            if(reg.Estado){
            cout<<"Usuario #"<<i+1<<":"<<endl<<endl;
            mostrar_usuario(reg);//SI EL ESTADO ES TRUE LA MUESTRO
            }
            cout<<endl;
    }
    anykey();
}


///FUNCION BUSCAR USUARIO POR IDUSUARIO
int buscar_usuario(int ID_buscado){
    Usuarios reg;
    FILE *f;
    int pos=0;
    f = fopen(fil_usuario, "rb");
    if (f == NULL){
        return -1;
    }
    while(fread(&reg, sizeof(Usuarios), 1, f)){
        if (ID_buscado == reg.ID){
          fclose(f);
          return pos;//DEVUELVE LA POSICION
        }
        pos++;
    }
    fclose(f);
    return -1;
}

///FUNCION DE MODIFICAR USUARIO
void modificar_usuario(){
    int ID,pos;
    FILE *p;
    cout<<"Ingrese el ID del Usuario que desea modificar."<<endl;
    cin>>ID;
    pos=buscar_usuario(ID);//LAMO A LA FUNCION BUSCAR USUARIO Y LE PASO EL ID
    Usuarios reg = leer_Usuario(pos);// LE ASIGNO A REG LO QUE TENGA EL ARCHIVO EN ESA POSICION
    if(pos>=0 && reg.Estado){
        delline(2,APP_FORECOLOR,APP_BACKCOLOR);
        title("Usuario a modificar ",APP_TITLEFORECOLOR,APP_TITLEBACKCOLOR);
        cout << endl << endl;
        mostrar_usuario(reg);//MUESTRO EL USUARIO A MODIFICAR
        cout << endl;
        cout<<"-------------------------------------------"<<endl;
        cout<<"Ingrese el Peso en kilogramos: ";
        cin>>reg.Peso;
    while(reg.Peso<1){ //VALIDAMOS EL PESO
        delline(13,APP_FORECOLOR,APP_BACKCOLOR);
        delline(14,APP_FORECOLOR,APP_BACKCOLOR);
        locate(1,13);
        cout<<"Error al ingresar los datos, vuelva a intentarlo."<<endl;
        cout<<"Ingrese el Peso en kilogramos: ";
        cin>>reg.Peso;
        cout<<endl;
    }
     bool seguir=1;
        cout << "Ingrese el perfil de actividad : ";
        cin>>reg.Perfil_de_actividad;
        while(seguir){ //VALIDMAOS EL PERFIL DE ACTIVIDAD
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
            delline(16,APP_FORECOLOR,APP_BACKCOLOR);
            locate(1,15);
            cout<<"Error al ingresar los datos, vuelva a intentarlo."<<endl;
            cout << "Ingrese el perfil de actividad : ";
            cin>>reg.Perfil_de_actividad;
}
    }
    cout<<endl;
    cout<<"Ingrese el apto medico(numero 0 o 1): ";
    cin>>reg.Apto_medico;
    while(reg.Apto_medico>1 || reg.Apto_medico<0){// VALIDAMOS EL APTO MEDICO
        delline(17,APP_FORECOLOR,APP_BACKCOLOR);
        delline(18,APP_FORECOLOR,APP_BACKCOLOR);
        locate(1,17);
        cout<<"Error al ingresar los datos, vuelva a intentarlo."<<endl;
        cout<<"Ingrese el apto medico(numero 0 o 1): ";
        cin>>reg.Apto_medico ;
    }
    cout<<endl;
    bool grabo=guardar_usuario(reg,pos);// MANDAMOS A GUARDAR CON EL STRUCT DE REGISTRO MODIFICADO Y LA POSICION
    if (grabo){
            delline(19,APP_FORECOLOR,APP_OKCOLOR);
            locate(1,19);
            cout<<"Usuario guardado correctamente."<<endl;
       }
        else{
           cout<<endl<<endl<<"El participante no se guardó correctamente."<<endl;
            delline(19,APP_FORECOLOR,APP_ERRORCOLOR);
            locate(1,19);
       }
    }else{
            delline(4,APP_FORECOLOR,APP_OKCOLOR);
            locate(1,4);
           cout<<"No existe este usuario."<<endl;

    }
    anykey();
    delline(4,APP_FORECOLOR,APP_BACKCOLOR);
}
///FUNCION PARA LEER USUARIOS RECIBIENDO LAPOSICION
Usuarios leer_Usuario(int pos){
    Usuarios reg;
    FILE *p=fopen(fil_usuario,"rb");
    if(p==NULL){
            reg.ID==0;
            return reg;
    }
    fseek(p,pos*sizeof(Usuarios),SEEK_SET);
    fread(&reg,sizeof(Usuarios),1,p);
    fclose(p);
    return reg; //DEVUELVE EL STRUCT CARGADO CON LOS DATOS EN ESA POSICION
}
///FUNCION PARA SABER LA CANTIDAD DE USUARIOS QUE TENEMOS EN ARCHIVO
int cantidad_de_usuarios(){
  Usuarios reg;
  int cant=0;
  FILE *p;
  p=fopen(fil_usuario,"rb");
  if (p == NULL){
        cout << "No se puede leer el archivo.";
        return 0;
    }
  while(fread(&reg, sizeof(Usuarios), 1, p))cant++;
  return cant;
}
///FUNCION PARA DAR LA BAJA DE USUARIO
void baja_usuario(){
    int ID,pos;
    char opcion;
    FILE *p;
    cls();
    cout<<"Ingrese el ID del Usuario que desea dar de baja."<<endl;
    cin>>ID;
    pos=buscar_usuario(ID);//BUSCAMOS LA POSICION EN ARCHIVOS
    if(pos>=0){

        Usuarios reg = leer_Usuario(pos);//LE ASIGNAMOS A REG LO QUE TENGA ESE STRCUT
        cls();
        cout<<"Esta seguro que desea eliminar al usuario:"<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        mostrar_usuario(reg);
        cout<<endl<<"Presione 'Y' para confirmar o cualquier otra letra para volver al menu."<<endl;
        cin>>opcion;
        cout<<endl;

        if(opcion=='y' || opcion=='Y'){
        reg.Estado=false;//LE CAMBIAMOS EL ESTADO
        bool grabo=guardar_usuario(reg,pos);// Y LO GUARDAMOS
        if(grabo){
        delline(16,APP_FORECOLOR,APP_OKCOLOR);
       gotoxy(1,16);
        cout<<"Se elimino el usuario correctamente."<<endl;
    }   else {
        delline(16,APP_FORECOLOR,APP_ERRORCOLOR);
        gotoxy(1,16);
        cout<<"No se pudo eliminar el usuario."<<endl;
    }

    }

    }
       else{
       cout<<"No existe el participante."<<endl;
    }
       anykey();
       delline(16,APP_FORECOLOR,APP_BACKCOLOR);

}
///FUNCION PARA LISTAR EL USUARIO SEGUN EL ID
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
///FUNCION PARA VER SI EL USUARIO SE ENCUENTRA CON UN BOOL
bool comparar(int id){
    bool a=true;
    int pos=buscar_usuario(id);
    if(pos==-1){
        a=false;
        return a;
    }
    return a;
}


///FUNCION DE FECHA DEL SISTEMA
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

///FUNCION PARA VALIDAR QUE LA EDAD SEA MAYOR A 13
 int validaredad(Fecha nac,Fecha actual){
     int error=0,edad;
     if(nac.mes<actual.mes) edad=actual.anio-nac.anio;
        else if(nac.mes==actual.mes && nac.dia<=actual.dia) edad=actual.anio-nac.anio;
        else edad=actual.anio-nac.anio-1;
     if(edad<13)error=4;
     return error;
 }

 bool anio_bisiesto(int anio){
 bool resultado;

 resultado=(anio%4==0 && anio>=2000);

 return resultado;
 }
