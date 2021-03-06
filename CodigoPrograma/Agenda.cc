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

	if (l.empty()){
        		cout<<"La lista esta vacia"<<endl;
        		return ;
        		cout<<endl;
    }

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
	int status=0;
	string aux1;
	int aux2;
	Alumno alumno;
	list<Alumno>::iterator i;


	

		//DNI
		cout<<"Introduzca su DNI: ";
		cin >> aux1;
		

		for(i = l.begin(); i != l.end(); ++i){
			if( (*i).ObtenerDNI() == aux1 ){
				cout<<"Ya existe ese DNI en nuestra base de datos. Se cancelará la insercion"<<endl<<endl;
				return ;
			}
		}
		alumno.InsertarDNI(aux1);

		cout<<"Se ha introducido el DNI correctamente"<<endl;

		//Email
		cout<<"Introduzca su email: ";
		cin >> aux1;
		

		for(i = l.begin(); i != l.end(); ++i){
			if( (*i).ObtenerEmail() == aux1 ){
				cout<<"Ya existe ese email en nuestra base de datos. Se cancelará la insercion"<<endl<<endl;
				return ;
			}
		}
		alumno.InsertarEmail(aux1);
		cout<<"Se ha introducido el email correctamente"<<endl;


		//Nombre
		cout<<"Introduzca su nombre: ";
		cin.ignore();
		getline(cin,aux1);
		alumno.InsertarNombre(aux1);
		cout<<"Se ha introducido el nombre correctamente"<<endl;


		//Apellidos
		cout<<"Introduzca sus apellidos: ";
		cin>>aux1;
		alumno.InsertarApellidos(aux1);
		cout<<"Se han introducido los apellidos correctamente"<<endl;


		//FechaNacimiento
		cout<<"Introduzca su fecha de nacimiento: ";
		cin>>aux1;
		alumno.InsertarFechaNacimiento(aux1);
		cout<<"Se ha introducido la fecha de nacimiento correctamente"<<endl;


		//Telefono
		cout<<"Introduzca su telefono: ";
		cin>>aux2;
		alumno.InsertarTelefono(aux2);
		cout<<"Se ha introducido el telefono correctamente"<<endl;


		//Direccion
		cout<<"Introduzca su direccion: ";
		cin.ignore();
		getline(cin,aux1);
		alumno.InsertarDireccion(aux1);
		cout<<"Se ha introducido la direccion correctamente"<<endl;


		//CursoMayor
		cout<<"Introduzca el curso mayor donde se encuentre matriculado: ";
		cin>>aux2;
		alumno.InsertarCursoMayor(aux2);
		cout<<"Se ha introducido el curso mayor correctamente"<<endl;


		//Equipo y lider
		cout<<"Quiere introducir equipo y lider (1 -> SI | 2 -> NO)?: ";
		cin>>aux2;
		if(aux2 == 1){
			cout<<"Introduzca su equipo: ";
			cin>>aux2;
			alumno.InsertarEquipo(aux2);
			cout<<"Se ha introducido el equipo correctamente"<<endl;

			int eq_aux = aux2;

			cout<<"Es lider de ese equipo o no (1 -> SI | 2 -> NO)?: ";
			cin>>aux2;
			if(aux2 == 1){
				
				for(i = l.begin(); i != l.end(); ++i){
					if( ((*i).ObtenerEquipo() == eq_aux) && ((*i).ObtenerLider() == true) ){
						
						status=1;
					}	
				}
				  if(status==1){
				  	cout<<"Ya existe lider para ese quipo. Se procede a establecer este alumno como no lider para ese equipo"<<endl;
					cout<<"Si quiere cambiar el lider de ese quipo, en el menu principal seleccione modificar"<<endl;
				  	alumno.InsertarLider(false);
				  }
				  else{
				  	alumno.InsertarLider(1);
					}
			}
			else{alumno.InsertarLider(false);}
		}
		
		else{
			alumno.InsertarEquipo(0);
			alumno.InsertarLider(false);
		}

	

		l.push_back(alumno);
		cout<<"Se completo la insercion"<<endl<<endl;
	
}




void Agenda::Borrar_Alumno(){
	if (l.empty()){
        		cout<<"La lista esta vacia"<<endl;
        		return ;
        		cout<<endl;
        	}

int eleccion;             
cout<<"Marque que desea introducir para buscar y borrar"<<endl;
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
        		return ;
        		cout<<endl;

        	}
        	 if(v[0]==-1){
            	cout<<"No se ha encontrado coincidencias "<<endl;
            	return ;
        		cout<<endl;

            }
        	list<Alumno>::iterator i; 
        	
           i=l.begin() ;

          
          
          for (int k = 0; k<v[0]; ++k) {
                i++;
            
          }              
          
          l.erase(i);
          cout<<"Alumno borrado"<<endl;

        }break;
        
        case 2:{
        	
           int borrados=0;
           Buscar_Alumno(2);

            if(v[0]==-1){
            	cout<<"No se ha encontrado coincidencias"<<endl;
            	return ;
        		cout<<endl;
            }
            list<Alumno>::iterator i; 

            
        	for (int  j = 0; v[j]!=-1; ++j){
              i=l.begin() ;
          
             for (int k = 0; k<(v[j]-borrados); ++k){    //Hay que tener en cuenta que cuando elimino el primer
                i++;										//miembro del equipo, la lista pasa un hueco para delante
                										//luego si el segundo memnro a eliminar es la posicion 6 en 
              }											//la lista, ahora será la poscion 6-el numero de borrados que haya habido por delante
            
            l.erase(i);
            
            borrados++;  

             cout<<"Alumno/s borrado/s"<<endl;      
   }
          
        	
        	

        }break;

        case 3:{
        	
        l.clear();
         cout<<"Se han borrado todos los alumnos"<<endl;
       }break;
    }
 }


void Agenda::Modificar_Alumno(){

  if (l.empty()){
   cout<<"La lista esta vacia"<<endl;
   return ;
   cout<<endl;
  }

  Buscar_Alumno(1);

  if(v[1]!=-1){
    cout<<"Se ha encontrado más de un alumno"<<endl;
    cout<<"Se aconseja buscar por Dni"<<endl;
    return ;
    cout<<endl;
  }

  if(v[0]==-1){
    cout<<"No se ha encontrado coincidencias "<<endl;
    return ;
    cout<<endl;
  }

  list<Alumno>::iterator i; 
        	
  i=l.begin() ;
  for (int k = 0; k<v[0]; ++k) {
   i++;  
  }  


  int eleccion;             
  cout<<endl<<"Marque que desea cambiar"<<endl;
  cout<<"1. Nombre"<<endl;
  cout<<"2. Apellidos"<<endl;
  cout<<"3. DNI"<<endl;
  cout<<"4. Email"<<endl;
  cout<<"5. Fecha Nacimiento"<<endl;
  cout<<"6. Telefono"<<endl;
  cout<<"7. Direccion"<<endl;
  cout<<"8. CursoMayor"<<endl;
  cout<<"9. Equipo"<<endl;
  cout<<"10. Lider"<<endl;

  cin>>eleccion;

  int status=0;
  string aux1;
  int aux2;
  list<Alumno>::iterator j; 

  switch(eleccion){
   case 1:{
     cout<<"Introduzca nuevo nombre: ";
  		cin.ignore();
  		getline(cin,aux1);
	 	 (*i).InsertarNombre(aux1);
	 	 cout<<"Se ha introducido el nombre correctamente"<<endl;
	 }break;

	 case 2:{
      cout<<"Introduzca sus nuevos apellidos: ";
		  cin>>aux1;
		  (*i).InsertarApellidos(aux1);
		  cout<<"Se han introducido los apellidos correctamente"<<endl;
	 }break;

    case 3:{
      cout<<"Introduzca su nuevo DNI: ";
		  cin >> aux1;
		
	   for(j = l.begin(); j != l.end(); ++j){
		      if( (*j).ObtenerDNI() == aux1 ){
		     cout<<"Ya existe ese DNI en nuestra base de datos. Se cancelará la insercion"<<endl<<endl;
		      return ;
		    }
		  }
		  (*i).InsertarDNI(aux1);

		  cout<<"Se ha introducido el DNI correctamente"<<endl;
	 }break;

    case 4:{
     cout<<"Introduzca su nuevo email: ";
		  cin >> aux1;
		
		  for(j= l.begin(); j != l.end(); ++j){
			 if( (*j).ObtenerEmail() == aux1 ){
				  cout<<"Ya existe ese email en nuestra base de datos. Se cancelará la insercion"<<endl<<endl;
				  return ;
			 }
		  }
		  (*i).InsertarEmail(aux1);
		  cout<<"Se ha introducido el email correctamente"<<endl;
	 }break;

    case 5:{
      cout<<"Introduzca su nueva fecha de nacimiento: ";
		  cin>>aux1;
		  (*i).InsertarFechaNacimiento(aux1);
		  cout<<"Se ha introducido la fecha de nacimiento correctamente"<<endl;
	 }break;

	 case 6:{
      cout<<"Introduzca su nuevo telefono: ";
		  cin>>aux2;
		  (*i).InsertarTelefono(aux2);
		  cout<<"Se ha introducido el telefono correctamente"<<endl;
	 }break;

	 case 7:{
      cout<<"Introduzca su nueva direccion: ";
		  cin.ignore();
		  getline(cin,aux1);
		  (*i).InsertarDireccion(aux1);
		  cout<<"Se ha introducido la direccion correctamente"<<endl;
	 }break;

	 case 8:{
      cout<<"Introduzca el nuevo curso mayor donde se encuentre matriculado: ";
		  cin>>aux2;
		  (*i).InsertarCursoMayor(aux2);
		  cout<<"Se ha introducido el curso mayor correctamente"<<endl;
	 }break;

	 case 9:{
      cout<<"Introduzca su nuevo equipo: ";
		  cin>>aux2;
		  (*i).InsertarEquipo(aux2);
		  cout<<"Se ha introducido el equipo correctamente"<<endl;
		  (*i).InsertarLider(false);
		  cout<<"Por defecto  se establece que no es lider"<<endl;
		  cout<<"Si quiere cambiar el lider de ese quipo, en el menu principal seleccione modificar"<<endl;
	 }break;

	 case 10:{
      int eq_aux = (*i).ObtenerEquipo();
      cout<<eq_aux<<endl;

		  cout<<"Es lider de ese equipo o no (1 -> SI | 2 -> NO)?: ";
		  cin>>aux2;
		  if(aux2 == 1){
				
			 for(j = l.begin(); j != l.end(); ++j){  
				  if( ((*j).ObtenerEquipo() == eq_aux) && ((*j).ObtenerLider() == true) ){	 
				  status=1;
				  }	
			 }
			 if(status==1){
				  cout<<"Ya existe lider para ese quipo. Se procede a establecer este alumno como no lider para ese equipo"<<endl;
				  cout<<"Si quiere cambiar el lider de ese quipo, en el menu principal seleccione modificar"<<endl;
				  (*i).InsertarLider(false);
			 }
			 else{
				  (*i).InsertarLider(1);
			 }
		  }
		  else{(*i).InsertarLider(false);}
	 }break;   
  }
  cout<<endl<<"Alumn@ modificad@ correctamente"<<endl;
}