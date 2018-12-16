
#include "Alumno.h"
#include "Agenda.h"
#include "Profesor.h"

#include <string>
#include <iostream>



int main(){
Profesor p;
Agenda a;

cout<<"Antes de iniciar sesion debe identificarse"<<endl;
p.InsertarRol(0);
p.Iniciar_Sesion();
	
    if(p.ObtenerRol()==1||p.ObtenerRol()==2){
		
		p.AsignarPuntero(&a);
		p.CargarFicheroAlumnos();   
	}
   else{
   	cout<<"Lo sentimos, no tiene permiso para acceder a la Base de Datos"<<endl;
   	return -1;
   }

int eleccion;

do{
	cout<<endl<<"-------------------------"<<endl;
	cout<<"Que desea hacer:"<<endl;

	cout<<"1.- Insertar Alumno "<<endl;
	cout<<"2.- Mostrar Alumno"<<endl;
	cout<<"3.- Modificar Alumno "<<endl;
	cout<<"4.- Borrar Alumno"<<endl;
	cout<<"5.- Guardar Base de datos"<<endl;
	cout<<"6.- Copia Seguridad "<<endl;
	cout<<"7.- Salir de la aplicación "<<endl;
	cout<<endl<<"- Su eleccion: ";
	cin>>eleccion;
	cout<<"-------------------------"<<endl<<endl;
	switch(eleccion){
		case 1:{
				a.Insertar_Alumno();
		}break;

		case 2:{
				a.Mostrar_Alumno();
		}break;

		case 3:{
				a.Modificar_Alumno();
		}break;

		case 4:{
				a.Borrar_Alumno();
		}break;

		case 5:{
				p.GuardarFicheroAlumnos();
		}break;

		case 6:{
				p.Copia_Seguridad();
		}break;

	}

}while(eleccion<7);

p.Salir_Aplicacion();
				

		




}