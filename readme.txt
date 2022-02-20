--------------------------------------------------------
|                                                      |
|           Nicolás Millar - Manuel Yáñez              |
|                                                      |
--------------------------------------------------------

Proyecto semestral de Sistemas Operativos que consiste en un juego multijugador (Entre 2 a 4 jugadores) llamado "You're too slow" utilizando diversas herramientas aprendidas en el semestre, entre ellas semáforos y tuberías.
A continuación algunas instrucciones para su uso, solicitadas por el profesor para la entrega.


(Aclaración: Todas las instrucciones se describen entre comillas)

- Para compilar el proyecto, simplemente utilice en consola el comando "make".
- Para poder ejecutar los dos archivos del proyecto, primero debe tener permisos de administrador, 
para eso utilice el comando "sudo su" para pasar a usuario root, luego ejecute primero server con
"./server" y seleccione la cantidad de jugadores que querrá, una vez seleccionado, server le mostrará
la matriz resultante.
- Luego, ejecute en una terminal diferente "./client" también como usuario root (usando "sudo su") y 
seleccione su jugador (entre 1 y 4), repita este paso el mismo número de veces que cantidad de jugadores.
- Por el momento, sólo tenemos que cada jugador envíe coordenadas al servidor, si un jugador envía más 
tarde las coordenadas, recibirá un mensaje de "muy lento".

Notas:
- Server sólo muestra la matriz, debido a varios problemas, no tuvimos el tiempo para implementar algo para
ir modificandola o hacer que el jugador adivine el número.
- Server imprime directamente los números que va recibiendo mediante las tuberías, prueba de comunicación de
cliente a servidor, a su vez, el hecho de que un jugador reciba un mensaje de "muy lento" demuestra la comunicación
de servidor a cliente.
- Recordar que para ejecutar ambos archivos, se debe haber usado previamente "sudo su", si no, al seleccionar cantidad
de jugadores en server dirá que no tiene permisos para crear las tuberías, deteniendo la ejecución del programa.
- Debido a problemas con el Makefile a la hora de compilar server.c, eliminamos el uso de semáforos, ya que para
compilar algo con semáforos se debía utilizar el flag "-lpthread" y fué un flag que por motivos que desconocemos no
quería aplicarse en el Makefile.
