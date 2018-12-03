//Agenda.cc

#include <list>
#include "Agenda.h"
#include <string>
#include <iostream>

using namespace std;


void Agenda::BuscarAlumno(int n){



for (int i = 0; i < 150; ++i)       //Se vacia vector posiciones
{
v[i]=-1;
}

switch(n){

case 1:{					//SE busca un alumno
int eleccion;
cout<<"Marque que desea introducir para buscar"<<endl;
cout<<"1. DNI"<<endl;
cout<<"2. Apellidos"<<endl;

cin>>eleccion;
string cad;
int j=0, posicion=0;
if(eleccion==1){
cout<<"Introduzca  dni a buscar"<<endl;
cin>>cad;
list<Alumno>::iterator i;      // "i" is an iterator for the list L


for(i=l.begin(); i != l.end(); ++i){
if((*i).ObtenerDNI() ==cad){                                   //Es privado asi que hay que llmarlo con el miembro
v[j]=posicion;
j++;
}
posicion++;
}
}
else{
cout<<"Introduzca  aoellidos a buscar"<<endl;
cin>>cad;
list<Alumno>::iterator i;      // "i" is an iterator for the list L


for(i=l.begin(); i != l.end(); ++i){
if((*i).ObtenerApellido() ==cad){                                   //Es privado asi que hay que llmarlo con el miembro
v[j]=posicion;
j++;
}
posicion++;
}
}

}break;

case 2:{
cout<<"Introduzca  equipo a buscar"<<endl;
int equipo
cin>>equipo;
list<Alumno>::iterator i;      // "i" is an iterator for the list L


for(i=l.begin(); i != l.end(); ++i){
if((*i).ObtenerEquipo() ==equipo){                                   //Es privado asi que hay que llmarlo con el miembro
v[j]=posicion;
j++;
}
posicion++;
}

}break;
}


}




void Agenda::MostrarAlumno(){
int eleccion;
cout<<"Marque que desea introducir para buscar"<<endl;
cout<<"1. Un alumno"<<endl;
cout<<"2. Un equipo"<<endl;
cout<<"3. Todos los alumnos "<<endl;

cin>>eleccion;

switch(eleccion){
case 1:{
BuscarAlumno(1);
if(v[1]!=-1){
cout<<"Se ha encontrado más de un alumno"<<endl;
cout<<"Se aconseja buscar por Dni"<<endl;
exit(-1);

}
if(v[0]==-1){
cout<<"No se ha encontrado coincidencias"<<endl;
exit(-1);
}
list<Alumno>::iterator i;
i=l.begin();
i=i+v[0];                   //el iterator se pone en la posicion dada por el valor que hay en v[0]

cout<<"Nombre: "<<(*i).ObtenerNombre()<<endl;
cout<<"Apellido: "<<(*i).ObtenerApellido()<<endl;
cout<<"DNI: "<<(*i).ObtenerDNI()<<endl;
cout<<"Fecha nacimiento: "<<(*i).ObtenerFechaNacimiento()<<endl;
cout<<"Telefono: "<<(*i).ObtenerTelefono()<<endl;
cout<<"Direccion: "<<(*i).ObtenerDireccion()<<endl;
cout<<"Curso Mayor: "<<(*i).ObtenerCursoMayor()<<endl;
cout<<"Email: "<<(*i).ObtenerEmail()<<endl;
cout<<"Equipo: "<<(*i).ObtenerEquipo()<<endl;
cout<<"LIder: "<<(*i).ObtenerLider()<<endl;

}break;

case 2:{
BuscarAlumno(2);
if(v[0]==-1){
cout<<"No se ha encontrado coincidencias"<<endl;
exit(-1);
}
list<Alumno>::iterator i;
for (int j = 0; v[j]!=-1; ++j){   //CAMBIAR QUE ESTO ESTA MAL
i=l.begin();
i=i+v[j];                   //el iterator se pone en la posicion dada por el valor que hay en v[0]

cout<<"Nombre: "<<(*i).ObtenerNombre()<<endl;
cout<<"Apellido: "<<(*i).ObtenerApellido()<<endl;
cout<<"DNI: "<<(*i).ObtenerDNI()<<endl;
cout<<"Fecha nacimiento: "<<(*i).ObtenerFechaNacimiento()<<endl;
cout<<"Telefono: "<<(*i).ObtenerTelefono()<<endl;
cout<<"Direccion: "<<(*i).ObtenerDireccion()<<endl;
cout<<"Curso Mayor: "<<(*i).ObtenerCursoMayor()<<endl;
cout<<"Email: "<<(*i).ObtenerEmail()<<endl;
cout<<"Equipo: "<<(*i).ObtenerEquipo()<<endl;
cout<<"LIder: "<<(*i).ObtenerLider()<<endl;

}



}break;

case 3:{
if (l.empty()){
cout<<"La lista esta vacia"<<<endl;
Exit(-1);
}


}break;
}


}
