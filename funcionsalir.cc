//Funcion copia de seguridad
#include <list>
#include "Agenda.h"
#include "Profesor.h"
#include "Alumno.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <stdlib.h>
void Agenda::Salir_de_la_Aplicacion(){
	//Declaro una lista de alumnos auxiliar y le instroduzco la lista de la clase Agenda
	list <Alumno>lista;
	lista=(*p_).ObtenerLista();

	//Declaro un ietrador de tipo  lista de alumnos 
	list<Alumno>::iterator i;

	//Creo un nuevo fichero binario
	ofstream f("alumnos.bin",ios::binary);

	//Creacion de variables auxiliares para escribir un alumno en el fichero binario
	        string aux;
			int n;
            char aux1[20];
			bool lider_aux;

   for(i = lista.begin(); i != lista.end(); ++i){
			aux=(*i).ObtenerDNI();
			strcpy(aux1,aux.c_str());
			f.write((char *) &(aux1),sizeof(aux1));

			aux=(*i).ObtenerEmail();
			strcpy(aux1,aux.c_str());
			f.write((char *) &(aux1),sizeof(aux1));

			aux=(*i).ObtenerNombre();
			strcpy(aux1,aux.c_str());
			f.write((char *) &(aux1),sizeof(aux1));

			aux=(*i).ObtenerApellidos();
			strcpy(aux1,aux.c_str());
			f.write((char *) &(aux1),sizeof(aux1));

			aux=(*i).ObtenerFechaNacimiento();
			strcpy(aux1,aux.c_str());
			f.write((char *) &(aux1),sizeof(aux1));

			n=(*i).ObtenerTelefono();
			f.write((char *) &(n),sizeof(n));

			aux=(*i).ObtenerDireccion();
			strcpy(aux1,aux.c_str());
			f.write((char *) &(aux1),sizeof(aux1));

			n=(*i).ObtenerCursoMayor();
			f.write((char *) &(n),sizeof(n));

			n=(*i).ObtenerEquipo();
			f.write((char *) &(n),sizeof(n));

			lider_aux=(*i).ObtenerLider();
			f.write((char *) &(lider_aux),sizeof(lider_aux));

    }
    

f.close();

cout<<"Se ha guardado con éxito los alumnos en el fichero binario"<<endl<<endl;
cout<<"Se procede a la salida de la aplicación"<<endl<<endl;
exit(0);
}
