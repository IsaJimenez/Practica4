//agenda.h

#include <algorithm>
#include <list>
#include "Alumno.h"


using namespace std;

#ifndef AGENDA_H
#define AGENDA_H

class Agenda : public Alumno {
private:
	list<Alumno>l;
	int v[150];
public:
	inline void InsertarLista(list<Alumno>aux){l=aux; }
	void Buscar_Alumno(int n);
	void Mostrar_Alumno();
    void Insertar_Alumno();
    void Borrar_Alumno();
	inline list<Alumno> ObtenerLista(){return l;}
};



#endif