#include <list>
#include "Profesor.h"
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