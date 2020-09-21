#ifndef STRUCS_H_INCLUDED
#define STRUCS_H_INCLUDED
struct Fecha{
    int dia;
    int mes;
    int anio;
};

struct Usuarios{
   int ID;
   char Nombres[50];
   char Apellidos[50];
   char Perfil_de_actividad;
   Fecha fecha_de_nacimiento;
   float Altura;
   float Peso;
   bool Apto_medico;
   bool Estado;
};

struct Entrenamiento{
    int ID;
    int ID_usuarios;
    Fecha fecha_de_entrenamiento;
    int actividad;
    float calorias;
    int tiempo;
};


#endif // STRUCS_H_INCLUDED
