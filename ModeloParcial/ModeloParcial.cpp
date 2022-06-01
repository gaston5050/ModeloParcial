#include <iostream>
#include <iomanip>
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
void ModeloParcial::punto2() {

    Estudiante reg;
    int pos=0;
    while(reg.LeerDeDisco(pos++)){
    if(pos==1){
    std::cout << std::left;
    std::cout<< std::setw(10)<<"LEGAJO ";
    std::cout<< std::setw(15)<<"NOMBRES ";
    std::cout<< std::setw(15)<<"APELLIDOS ";
    std::cout<< std::setw(20)<<"CANT. APROBADAS";
    std::cout<< std::setw(30)<<"CANT DESAPROBADAS ";
    std::cout<<std::endl;
    }
    std::cout << std::left;
    std::cout<< std::setw(10)<<reg.getLegajo();
    std::cout<< std::setw(15)<<reg.getNombres();
    std::cout<< std::setw(20)<<reg.getApellidos();
    std::cout<< std::setw(30)<< cantAprobadas(reg.getLegajo());
    std::cout<< std::setw(30)<<cantDesaprobadas(reg.getLegajo());
    std::cout<<std::endl;


}


}
void ModeloParcial::punto3() {


    Estudiante reg;
    int vecMateriaRendida[60]={};

        int pos=0;

        while( reg.LeerDeDisco(pos++)){

            contadoraVecesRindio(reg.getLegajo(), vecMateriaRendida);


        }


           std::cout << std::left;
       std::cout<< std::setw(10)<<"MATERIA ";
      std::cout<< std::setw(15)<<"CANTIDAD DE ALUMNOS QUE CURSARON MAS DE UNA VEZ"<<std::endl;


      int cont =0;
int materias=60;
        for(int i=0;i<materias;i++){

    if(vecMateriaRendida[i]!=0){
    std::cout<< std::setw(10)<<i+1;
    std::cout<< std::setw(5)<<vecMateriaRendida[i] <<std::endl;
    cont ++;
    }
        }
         std::cout<< std::setw(10)<<"TOTAL ";
      std::cout<< std::setw(15)<<cont<<std::endl;


 }







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

int cantAprobadas(int leg){

    Examen reg;
    int pos=0, contApro=0;
    while(reg.LeerDeDisco(pos++)){


        if(reg.getLegajo()==leg && reg.getNota()>=6){



            contApro++;
        }

    }
    return contApro;

}
int cantDesaprobadas(int leg){

    Examen reg;
    int pos=0, contDesapro=0;
    while(reg.LeerDeDisco(pos++)){


        if(reg.getLegajo()==leg && reg.getNota()<6){



            contDesapro++;
        }

    }
    return contDesapro;

}

void contadoraVecesRindio(int leg, int vec[]){

        Examen aux;
        int examenesPorMateria[60]={};
        int pos=0, i=0;


            while (aux.LeerDeDisco(pos)){

                if(aux.getLegajo()==leg){

                        if(aux.getNota()!=0 && aux.getFecha().getAnio()>=2018 && aux.getFecha().getAnio()<=2022){
                                examenesPorMateria[aux.getIDMateria()-1]++;
                        }

                }


                pos++;

            }



        int materias=60;

        for(int i=0;i<materias;i++){

                        if(examenesPorMateria[i]>=2){

                            vec[i]++;

                        }
        }
}


