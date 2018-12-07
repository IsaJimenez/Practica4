//Agenda.cc
#include <algorithm>
#include <list>
#include "Agenda.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

 bool ordenaDNI(Alumno b,Alumno c){
    return b.ObtenerDNI()>c.ObtenerDNI();
 }
  bool ordenaCurso(Alumno b,Alumno c){
    return b.ObtenerCursoMayor()>c.ObtenerCursoMayor();
 }
  bool ordenaNombre(Alumno b,Alumno c){
    return b.ObtenerNombre()>c.ObtenerNombre();
 }
  bool ordenaApellido(Alumno b,Alumno c){
    return b.ObtenerApellidos()>c.ObtenerApellidos();
 }



void Agenda::Buscar_Alumno(int n){
		


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
   			
      int posicion=0;
      int j=0;

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
  		   	   cout<<"Introduzca  apellidos a buscar"<<endl;
                cin>>cad;
                list<Alumno>::iterator i;      // "i" is an iterator for the list L
 				
 				
                for(i=l.begin(); i != l.end(); ++i){
     				 if((*i).ObtenerApellidos() ==cad){                                   //Es privado asi que hay que llmarlo con el miembro
      					v[j]=posicion;
      					j++;
      				}
      				posicion++;
     			 }
  		   }

     }break;

   case 2:{
   				cout<<"Introduzca  equipo a buscar"<<endl;
   				int equipo;
   				int posicion=0;
                int j=0;
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




void Agenda::Mostrar_Alumno(){
int eleccion;             
cout<<"Marque que desea introducir para buscar"<<endl;
cout<<"1. Un alumno"<<endl;
cout<<"2. Un equipo"<<endl;
cout<<"3. Todos los alumnos "<<endl;

cin>>eleccion;

	switch(eleccion){
        case 1:{
        	Buscar_Alumno(1);
        	if(v[1]!=-1){
        		cout<<"Se ha encontrado más de un alumno"<<endl;
        		cout<<"Se aconseja buscar por Dni"<<endl;
        		break;
        		cout<<endl;

        	}
        	 if(v[0]==-1){
            	cout<<"No se ha encontrado coincidencias"<<endl;
            	break;
        		cout<<endl;

            }
        	list<Alumno>::iterator i; 
        	
           i=l.begin() ;

           cout<<"Alumno buscado "<<endl;
          
          for (int k = 0; k<v[0]; ++k) {
                i++;
            
          }              //el iterator se pone en la posicion dada por el valor que hay en v[0]
          
            cout<<"Nombre: "<<(*i).ObtenerNombre()<<endl;
            cout<<"Apellido: "<<(*i).ObtenerApellidos()<<endl;
            cout<<"DNI: "<<(*i).ObtenerDNI()<<endl;
            cout<<"Fecha nacimiento: "<<(*i).ObtenerFechaNacimiento()<<endl;
            cout<<"Telefono: "<<(*i).ObtenerTelefono()<<endl;
            cout<<"Direccion: "<<(*i).ObtenerDireccion()<<endl;
            cout<<"Curso Mayor: "<<(*i).ObtenerCursoMayor()<<endl;
            cout<<"Email: "<<(*i).ObtenerEmail()<<endl;
            cout<<"Equipo: "<<(*i).ObtenerEquipo()<<endl;
            cout<<"LIder: "<<(*i).ObtenerLider()<<endl<<endl;

        }break;
        
        case 2:{
            Buscar_Alumno(2);
            if(v[0]==-1){
            	cout<<"No se ha encontrado coincidencias"<<endl;
            	break;
        		cout<<endl;
            }
            list<Alumno>::iterator i; 

            cout<<"El equipo buscado consta de los sigueintes alumnos"<<endl;
        	for (int  j = 0; v[j]!=-1; ++j){
              i=l.begin() ;
          
             for (int k = 0; k<v[j]; ++k){
                i++;
              }
            
            cout<<"Nombre: "<<(*i).ObtenerNombre()<<endl;
            cout<<"Apellido: "<<(*i).ObtenerApellidos()<<endl;
            cout<<"DNI: "<<(*i).ObtenerDNI()<<endl;
            cout<<"Fecha nacimiento: "<<(*i).ObtenerFechaNacimiento()<<endl;
            cout<<"Telefono: "<<(*i).ObtenerTelefono()<<endl;
            cout<<"Direccion: "<<(*i).ObtenerDireccion()<<endl;
            cout<<"Curso Mayor: "<<(*i).ObtenerCursoMayor()<<endl;
            cout<<"Email: "<<(*i).ObtenerEmail()<<endl;
            cout<<"Equipo: "<<(*i).ObtenerEquipo()<<endl;
            cout<<"LIder: "<<(*i).ObtenerLider()<<endl<<endl;

        	}
        	
        	

        }break;

        case 3:{
        	
        	if (l.empty()){
        		cout<<"La lista esta vacia"<<endl;
        		break;
        		cout<<endl;
        	}
        	
  			ofstream f("Alumnos.md"); 

        	cout<<"Marque en qué orden lo quieres"<<endl;

			 cout<<"1. Por 	DNI"<<endl;
			 cout<<"2. Por curso"<<endl;
			 cout<<"3. Por orden alfabetico de nombre "<<endl;
			 cout<<"4. Por orden alfabetico de apellido"<<endl;
			
			cin>>eleccion;
			if(eleccion==1){l.sort(ordenaDNI);}
			if(eleccion==2){l.sort(ordenaCurso);}
			if(eleccion==3){l.sort(ordenaNombre);}
			if(eleccion==4){l.sort(ordenaApellido);}

        	cout<<"Marque en qué orden lo quieres"<<endl;

			 cout<<"1. Ascendente"<<endl;
			 cout<<"2. Descenente"<<endl;

			 cin>>eleccion;

			 if(eleccion==1){l.reverse();}

        	list<Alumno>::iterator i; 

        	 for(i=l.begin(); i != l.end(); ++i){
     		cout<<"Nombre: "<<(*i).ObtenerNombre()<<endl;
            cout<<"Apellido: "<<(*i).ObtenerApellidos()<<endl;
            cout<<"DNI: "<<(*i).ObtenerDNI()<<endl;
            cout<<"Fecha nacimiento: "<<(*i).ObtenerFechaNacimiento()<<endl;
            cout<<"Telefono: "<<(*i).ObtenerTelefono()<<endl;
            cout<<"Direccion: "<<(*i).ObtenerDireccion()<<endl;
            cout<<"Curso Mayor: "<<(*i).ObtenerCursoMayor()<<endl;
            cout<<"Email: "<<(*i).ObtenerEmail()<<endl;
            cout<<"Equipo: "<<(*i).ObtenerEquipo()<<endl;
            cout<<"LIder: "<<(*i).ObtenerLider()<<endl<<endl;


f<<"Nombre: "<<(*i).ObtenerNombre()<<endl;
            f<<"Apellido: "<<(*i).ObtenerApellidos()<<endl;
            f<<"DNI: "<<(*i).ObtenerDNI()<<endl;
            f<<"Fecha nacimiento: "<<(*i).ObtenerFechaNacimiento()<<endl;
            f<<"Telefono: "<<(*i).ObtenerTelefono()<<endl;
            f<<"Direccion: "<<(*i).ObtenerDireccion()<<endl;
            f<<"Curso Mayor: "<<(*i).ObtenerCursoMayor()<<endl;
           f<<"Email: "<<(*i).ObtenerEmail()<<endl;
            f<<"Equipo: "<<(*i).ObtenerEquipo()<<endl;
            f<<"LIder: "<<(*i).ObtenerLider()<<endl<<endl;

            
      				}
      			
 	f.close();

        }break;
	}


}

void Agenda::Insertar_Alumno(){
	string aux1;
	int aux2;
	Alumno alumno;
	list<Alumno>::iterator i;


	while(status == 0){

		//DNI
		cout<<"Introduzca su DNI: ";
		cin >> aux1;
		alumno.IntroduceDNI(aux1);

		for(i = l.begin(); i != l.end(); ++i)·{
			if( (*i).ObtenerDNI() == aux1 ){
				cout<<"Ya existe ese DNI en nuestra base de datos. Se cancelará la insercion";
				status = 1;
			}
		}

		cout<<"Se ha introducido el DNI correctamente"<<endl;

		//Email
		cout<<"Introduzca su email: ";
		cin >> aux1;
		alumno.IntroduceEmail(aux1);

		for(i = l.begin(); i != l.end(); ++i)·{
			if( (*i).ObtenerDNI() == aux1 ){
				cout<<"Ya existe ese email en nuestra base de datos. Se cancelará la insercion";
				status = 1;
			}
		}

		cout<<"Se ha introducido el email correctamente"<<endl;


		//Nombre
		cout<<"Introduzca su nombre: ";
		cin>>aux1;
		alumno.IntroduceNombre(aux1);
		cout<<"Se ha introducido el nombre correctamente"<<endl;


		//Apellidos
		cout<<"Introduzca sus apellidos: ";
		cin>>aux1;
		alumno.IntroduceApellidos(aux1);
		cout<<"Se han introducido los apellidos correctamente"<<endl;


		//FechaNacimiento
		cout<<"Introduzca su fecha de nacimiento: ";
		cin>>aux1;
		alumno.IntroduceFechaNacimiento(aux1);
		cout<<"Se ha introducido la fecha de nacimiento correctamente"<<endl;


		//Telefono
		cout<<"Introduzca su telefono: ";
		cin>>aux2;
		alumno.IntroduceTelefono(aux2);
		cout<<"Se ha introducido el telefono correctamente"<<endl;


		//Direccion
		cout<<"Introduzca su direccion: ";
		cin>>aux1;
		alumno.IntroduceDireccion(aux1);
		cout<<"Se ha introducido la direccion correctamente"<<endl;


		//CursoMayor
		cout<<"Introduzca el curso mayor donde se encuentre matriculado: ";
		cin>>aux2;
		alumno.IntroduceNombre(aux2);
		cout<<"Se ha introducido el curso mayor correctamente"<<endl;


		//Equipo y lider
		cout<<"Quiere introducir equipo y lider (1 -> SI | 2 -> NO)?: ";
		cin>>aux2;
		if(aux1 == 1){
			cout<<"Introduzca su equipo: ";
			cin>>aux2;
			alumno.IntroduceEquipo(aux2);
			cout<<"Se ha introducido el equipo correctamente"<<endl;

			int eq_aux = aux2;

			cout<<"Es lider de ese equipo o no (1 -> SI | 2 -> NO)?: ";
			cin>>aux2;
			if(aux2 == 1){
				alumno.IntroduceLider(true);


				for(i = l.begin(); i != l.end(); ++i)·{
					if( ((*i).ObtenerEquipo() == eq_aux) && ((*i).ObtenerLider() == true) ){
						cout<<"Ya existe lider para ese quipo. Se procede a establecer este alumno como no lider para ese equipo";
						cout<<"Si quiere cambiar el lider de ese quipo, en el menu principal seleccione modificar"<<endl;
						alumno.IntroduceLider(false);
					}
				}
			}
			if(aux2 == 2){alumno.IntroduceLider(false);}


		}


	}
	if(status == 1){cout<<"Se cancelo la insercion"<<endl<<endl;}
	else{
		l.push_back(alumno);
		cout<"Se completo la insercion"<<endl<<endl;
	}
}
