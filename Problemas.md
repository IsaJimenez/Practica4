A lo largo de esta primera entrega hemos tenido algún que otro problema o inconveniente que hemos podido solucionar. 
A continuación, presentaremos los diversos problemas encontrados durante un sprint y otro.

# Primera Entrega

## Primer Sprint
Hasta el primer sprint que se realizó el viernes 30 de Noviembre a pesar de que solo se llevó a cabo la creación del repositorio deGitHub y la carpeta para almacenar el código de nuestro programa, uno de los  problema que se nos presentaron fue que tuvimos que cambiar la asignación de una de las tareas asignada a César, uno de los miembros del grupo, debido a que por falta de ordenador no iba a poder realizarla, por lo que decidimos dejar la función que se le asignó al principio de la primera entrega para la segunda entrega.Esta modificación hizo que las prioridades que teniamos en nuestro Product Backlog cambiasen ligeramente y que el Burndown Chart que teniamos pensado realizar  en la primera entrega cambiase de horas totales asignadas en dicha primera entrega.

## Segundo Sprint 
En los dias previos al  segundo sprint que tuvo lugar el miércoles 5 de Diciembre, otros de los problemas  antes de este sprint fue que habia fallos en el alumno.h , debido a variables mal esritas , lo que nos hizo tener que revisarlo de nuevo y resubirlo.
Además, al realizar algunas de las funciones empleando un tiempo distinto al estimado, nos dimos cuenta que había que modificar de nuevo las horas totales de nuestro Burndown Chart.

## Tercer Sprint 
En nuestro último sprint de la primera entrega que tuvo lugar el Sábado 8 de Diciembre, tuvimos algunos problemas, ya que  nos dimos cuenta que el Burndown Chart del 2º Sprint estaba mal hecho(se explica con detalle en un Marckdown que esta en la carpeta con el mismo nombre),luego lo rehicimos y lo subimos junto con el tercer Burndown Chart de la 1ª entrega.
Otro problema fue que decidimos cambiar el diagrama de clases con respecto el nombre de algunas variables y funciones para que asi fuese más fácil su comprension y aplicación, así como la cardinalidad de dicho diagrama que tenía un fallo entre Agenda y Alumno.
También ,tuvimos que cambiar los diagramas de secuencia de todas nuestras funciones debido a que tenían algunos fallos.
Por último, nos dimos cuenta que para usar el puntero de la clase Profesor, necesitabamos 2 funciones auxiliares (AsignarPuntero y RetornarPuntero),asi que decidimos crearlas dentro de la clase profesor y añadirlas al diagrama de clases

# Segunda Entrega

A lo largo de esta segunda entrega hemos tenido como problemas:

## Primer Sprint
En el primer sprint que se realizó el miércoles 12 Diciembre, nos dimos cuenta que para usar el puntero de la clase Profesor,solo  necesitábamos como  función auxiliar,AsignarPuntero, y no la de  RetornarPuntero, ya que  quien hace uso de las funciones de la clase Agenda será un objeto de dicha clase que creemos, y no el puntero.Asi que decidimos borrar  esta función auxiliar tanto de la clase profesor como del diagrama de clases.

## Segundo Sprint

No tuvimos ningún problema en el segundo sprint que tuvo lugar el Viernes  14 de Diciembre.

## Tercer Sprint

En nuestro último sprint de la segunda entrega que tuvo lugar el Domingo 16 de Diciembre, nos dimos cuenta que en la función mostrar era mas conveniente comprobar si la lista estaba vacía antes de comenzar a pedirle al usuario que desea mostrar , en vez de comprobarlo solo cuando el usuario pide mostar todos los alumnos. Además, este cambio tuvimos que incorporarlo al diagrama de secuencia de la funcion Mostrar.
El último problema que tuvimos fue que cuando ya teniamos todo el código hecho, decidimos que pablo, uno de los miembros del grupo, hiciese un makefile de nuestra aplicación y pusiese dicho código más bonito visualmente. Sin embargo, algo paso con la subida a github que se subió un documento dañado , asi que se tuvo que volver a retocar y subir de nuevo en la tarde del Domingo 16.





