#ifndef MODELOPARCIAL_H_INCLUDED
#define MODELOPARCIAL_H_INCLUDED
#include "estudiante.h"

class ModeloParcial{

public:
    void punto1();
    void punto2();
    void punto3();



  private:
        char _apellidos[50];
        char _nombres[50];
        int _legajo;



};

bool examenesAprobados(int leg);
std::string toStringModeloParcial(Estudiante reg);
int cantAprobadas(int leg);
int cantDesaprobadas(int leg);

#endif // MODELOPARCIAL_H_INCLUDED
