#include "Agenda.h"
#include "Alumno.h"


#ifndef PROFESOR_H
#define PROFESOR_H

class Profesor{
private:
	int rol_;
	Agenda *p_;
public:
	inline void AsignarPuntero(Agenda *a){p_=a;}
	
	
	void Iniciar_Sesion();
	void CargarFicheroAlumnos();
	void GuardarFicheroAlumnos();
	inline void InsertarRol(int rol){rol_ = rol;}

	
};

#endif
