#include "Agenda.h"
#include "Alumno.h"


#ifndef PROFESOR_H
#define PROFESOR_H

class Profesor{
private:
	int rol_;
	Agenda *p_;
public:
	inline void AsignarPuntero(Agenda a){p_=&a;}
	inline Agenda* RetornarPuntero(){return p_;}
	
	void Iniciar_Sesion();
	void CargarFicheroAlumnos();
	inline void InsertarRol(int rol){rol_ = rol;};

	
};

#endif