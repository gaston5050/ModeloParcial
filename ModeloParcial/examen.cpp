#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#include "examen.h"

int Examen::getID(){
   return _id;
}
int Examen::getLegajo(){
   return _legajo;
}
int Examen::getIDMateria(){
   return _idmateria;
}
Fecha Examen::getFecha(){
   return _fecha;
}
float Examen::getNota(){
   return _nota;
}
void Examen::setID(int ID){
   _id = ID;
}
void Examen::setLegajo(int legajo){
   _legajo = legajo;
}
void Examen::setIDMateria(int IDMateria){
   _idmateria = IDMateria;
}
void Examen::setFecha(Fecha fecha){
   _fecha = fecha;
}
void Examen::setNota(float nota){
   _nota = nota;
}
std::string Examen::toString(){
    std::string cadena;

    cadena = std::to_string(_id) + "," + std::to_string(_legajo) + "," + std::to_string(_idmateria) + "," + _fecha.toString() + "," +std::to_string(_nota);
    return cadena;
}
bool Examen::LeerDeDisco(int nroRegistro){
    FILE *p = fopen("examenes.dat", "rb");
    if (p == NULL){
        return false;
    }
    fseek(p, nroRegistro * sizeof(Examen), SEEK_SET);
    bool ok = fread(this, sizeof(Examen), 1, p);
    fclose(p);
    return ok;
}
bool Examen::GuardarEnDisco(){
    FILE *p = fopen("examenes.dat", "ab");
    if (p == NULL){
        return false;
    }
    bool guardo = fwrite(this, sizeof(Examen), 1, p);
    fclose(p);
    return guardo;
}
bool Examen::GuardarEnDisco(int nroRegistro){
    FILE *p = fopen("examenes.dat", "rb+");
    if (p == NULL){
        return false;
    }
    fseek(p, nroRegistro * sizeof(Examen), SEEK_SET);
    bool guardo = fwrite(this, sizeof(Examen), 1, p);
    fclose(p);
    return guardo;
}

/// Funciones globales para gestionar Examen

int cantidad_registros_examenes(){
    FILE *p = fopen("examenes.dat", "rb");
    if (p == NULL){
        return 0;
    }
    size_t bytes;
    int cant_reg;

    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    cant_reg = bytes / sizeof(Examen);
    return cant_reg;
}

void listar_examenes(){
    Examen aux;
    int i = 0;
    int cantExamenes = cantidad_registros_examenes();
    cout << "LISTADO DE EXAMENES" << endl;
    cout << "----------------------------------" << endl;

    for(i=0; i<cantExamenes; i++){
        aux.LeerDeDisco(i);

        cout << aux.toString() << endl;
    }
    cout << "----------------------------------" << endl;
    cout << "Total: " << cantExamenes << " registros.";
}

int buscar_examen(int idExamen){
    Examen aux;
    int i = 0;
    int cantExamenes = cantidad_registros_examenes();
    for(i=0; i<cantExamenes; i++){
        aux.LeerDeDisco(i);
        if(aux.getID() == idExamen){
            return i;
        }
    }
    return -1;
}


