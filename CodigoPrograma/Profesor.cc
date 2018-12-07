#include <list>
#include "Profesor.h"
#include "Alumno.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>

using namespace std;

void Profesor::Iniciar_Sesion(){

string dnip;
string contrap;
int rol;

cout<<"Introduzca Dni"<<endl;
cin>>dnip;
cout <<"Introduzca contraseña"<<endl;
cin>>contrap;

char dni[9];
char contra [9];


ifstream f1("profesores.bin",ios::binary);

    
 while(f1.read((char *) &(dni),sizeof(dni))){                         
	f1.read((char *) &(contra),sizeof(contra));
	f1.read((char *) &(rol),sizeof(rol));
                                  
	if(strcmp(dni,dnip.c_str())==0 && strcmp(contra,contrap.c_str())==0){
		cout<<"Correcto"<<endl;
		cout<<"Bienvenido"<<endl;
		InsertarRol(rol);
	}
 }

f1.close();
}


void Profesor::CargarFicheroAlumnos(){

	//Se abre el fichero binario de los alumnos "alumnos.bin"
		//Si existe eñ fichero binario, se vuelca el fichero binario en la lista de la clase Agenda del objeto marcado por el puntero p_. Finalmente se muestra por pantalla un mensaje de correcto
		//Si no existe tal fichero, se muestra un mensaje de que la lista esta vacía


	fstream f;

	//Declaramos un contador para llevar la cuenta de cuantos alumons tenemos en el fichero binario
		int contador = 0;

	//Creacion de variables auxiliares para leer un alumno del fichero binario
		char DNI_aux[20];
		char email_aux[20];
		char nombre_aux[20];
		char apellidos_aux[20];
		char fechaNacimiento_aux[20];
		int telefono_aux;
		char direccion_aux[20];
		int cursoMayor_aux;
		int equipo_aux;
		bool lider_aux;

	//Declaro un objeto alumno auxiliar
		Alumno alumno;

	//Declaro una lista de alumnos auxiliar
		list <Akumno> lista;


	f.open("alumnos.bin", ios::in | ios::binary);//Compruebo si se ha podido abrir

	if( f.is_open() ){ //Se ha podido abrir

		//Se procede a leer una a una, todo el contenido de un alumno
		while(f.read((char *) &(DNI_aux),sizeof(DNI_aux))){ 
			f.read((char *) &(email_aux),sizeof(email_aux));
			f.read((char *) &(nombre_aux),sizeof(nombre_aux));
			f.read((char *) &(apellidos_aux),sizeof(apellidos_aux));
			f.read((char *) &(fechaNacimiento_aux),sizeof(fechaNacimiento_aux));
			f.read((char *) &(telefono_aux),sizeof(telefono_aux));
			f.read((char *) &(direccion_aux),sizeof(direccion_aux));
			f.read((char *) &(cursoMayor_aux),sizeof(cursoMayor_aux));
			f.read((char *) &(equipo_aux),sizeof(equipo_aux));
			f.read((char *) &(lider_aux),sizeof(lider_aux));


			//Una vez obtenidos los campos de un alumno, procedo a introducirlo en un objeto auxiliar de la clase Alumno
			alumno.InsertarDNI(DNI_aux);
			alumno.InsertarEmail(email_aux);
			alumno.InsertarNombre(nombre_aux);
			alumno.InsertarApellidos(apellidos_aux);
			alumno.InsertarFechaNacimiento(fechaNacimiento_aux);
			alumno.InsertarTelefono(telefono_aux);
			alumno.InsertarDireccion(direccion_aux);
			alumno.InsertarCursoMayor(cursoMayor_aux);
			alumno.InsertarEquipo(equipo_aux);
			alumno.InsertarLider(lider_aux);

			//Introducimos alumno en lista
			lista.push_back(alumno);

			//Finalmente aumentamos el contador en una unidad
			contador++;
		}
		//Al acabar de leer todos los alumnos se copia nuestra lista auxiliar en la lista que usarán el resto de métodos de nuestro programa
		(*p_)InsertarLista(lista);
		//Por último, se cierra el fichero
		f.close();

	}
	else{

		cout<<"La lista de alumnos se encuentra vacía"<endl;

	} //No se ha podido abrir


}