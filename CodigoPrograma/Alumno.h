

//Alumno.h
#include <string>
using namespace std;

#ifndef ALUMNO_H
#define ALUMNO_H

class Alumno{
	
	private:
			string nombre_;
			string apellidos_;
			string DNI_;
			string fechaNacimiento_;
			int telefono_;
			string direccion_;
			int cursoMayor_;
			string email_;
			int equipo_;
			bool lider_;

	public:
			inline void  InsertarNombre(string nombre){ nombre_=nombre;}
			inline string ObtenerNombre(){return nombre_;}
			inline void InsertarApellidos(string apellidos){apellidos_=apellidos;}
			inline string ObtenerApellidos(){return apellidos_;}
			inline void InsertarDNI(string DNI){DNI_=DNI;}
			inline string ObtenerDNI(){return DNI_;}
			inline void InsertarFechaNacimiento(string fecha){fechaNacimiento_=fecha;}
			inline string ObtenerFechaNacimiento(){return fechaNacimiento_;}
			inline void InsertarTelefono(int telefono){telefono_=telefono;}
			inline int ObtenerTelefono(){return telefono_;}
			inline void InsertarDireccion(string direccion){direccion_=direccion;}
			inline string ObtenerDireccion(){return direccion_;}
			inline void InsertarCursoMayor(int  curso){cursoMayor_=curso;}
			inline int  ObtenerCursoMayor(){return cursoMayor_;}
			inline void  InsertarEmail(string email){email_=email;}
			inline string ObtenerEmail(){return email_;}
			inline void InsertarEquipo(int equipo){equipo_=equipo;}
			inline int ObtenerEquipo(){return equipo_;}
			inline void InsertarLider(bool lider){lider_=lider;}
			inline bool ObtenerLider(){return lider_;}


};

#endif