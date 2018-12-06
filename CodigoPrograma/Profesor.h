#ifndef PROFESOR_H
#define PROFESOR_H

class Profesor{
private:
	int rol_;
	Agenda *puntero_;
public:
	void CargarFicheroAlumnos();
	inline void InsertarRol(int rol){rol_ = rol;};
};
