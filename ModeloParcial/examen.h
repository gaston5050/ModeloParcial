#ifndef EXAMEN_H_INCLUDED
#define EXAMEN_H_INCLUDED
#include <string>
#include "fecha.h"
#include <sstream>

class Examen{
   public:
   int getID();
   int getLegajo();
   listar_examenes();
   int getIDMateria();
   Fecha getFecha();
   float getNota();
   void setID(int ID);
   void setLegajo(int legajo);
   void setIDMateria(int IDMateria);
   void setFecha(Fecha fecha);
   void setNota(float nota);
   std::string toString();
   bool LeerDeDisco(int nroRegistro);
   bool GuardarEnDisco();
   bool GuardarEnDisco(int nroRegistro);

   private:
   int _id;
   int _legajo;
   int _idmateria;
   Fecha _fecha;
   float _nota;
};

int cantidad_registros_examenes();
bool guardar_examenes(Examen aux);
void listar_examenes();
int buscar_examen(int idExamen);

#endif // EXAMEN_H_INCLUDED
