#include <iostream>
using namespace std;
#include <cstdio>
#include "estudiante.h"
#include "examen.h"
#include "ModeloParcial.h"

int main()
{

    //listar_examenes();

    ModeloParcial reg;
    std::cout<< std::endl;
    std::cout<<" PUNTO 1"<< std::endl;
    std::cout<< std::endl;
    reg.punto1();
   std::cout<< std::endl;
    std::cout<<" PUNTO 2"<< std::endl;
    std::cout<< std::endl;
    reg.punto2();
    std::cout<< std::endl;
    std::cout<<" PUNTO 3"<< std::endl;
    std::cout<< std::endl;
    reg.punto3();

   //listar_estudiantes();
    //listar_examenes();
    std::cout<< std::endl;

    return 0;
}
