#include <iostream>
#include <string>
#include "ModeloParcial.h"
#include "examen.h"
#include "estudiante.h"


void ModeloParcial::punto1(){

    Estudiante reg;
    int pos=0;

    while(reg.LeerDeDisco(pos++))
    {

        if(examenesAprobados(reg.getLegajo())==true)
        {

         std::cout<<toStringModeloParcial(reg)<<std::endl;

        }

    }



}
void punto2() {}
void punto3() {}

///FUNCION GLOBAL

bool examenesAprobados(int leg)
{
    Examen aux;
    int pos=0;

    while(aux.LeerDeDisco(pos++))
    {

        if(aux.getLegajo()==leg && aux.getFecha().getAnio()==2022)
        {

            return false;

        }
    }

        return true;

}

std::string toStringModeloParcial(Estudiante aux){

  std::string cadena;


    cadena = std::to_string(aux.getLegajo())+ ", "+aux.getApellidos() + "," + aux.getNombres();

    return cadena;

}
