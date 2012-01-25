/** @mainpage TrashSpace
*<img src="../../images/pantalla1.bmp" alt="" height="42" width="42" />
* @author <strong>Jefferson Amado Pe&ntilde;a Torres</strong> (JAPeTo)
*
* @section app TrashSpace
* TrashSpace 
* 
* @section cls Clases elaboradas por JAPeTo para la aplicacion
* - source/Camara.h   
* - source/Camara.cpp*        
* - source/Obstaculo.h
* - source/Obstaculo.cpp*        
* - source/Player.h
* - source/Player.cpp*
* - source/ObstaculoList.h
* - source/ObstaculoList.cpp*    
* - source/defConstantes.h
* - source/TrashSpace.cpp*
* 
* @section utl Archivos_utilizados
* - source/imageloader.h* 
* - source/objLoader/glm.h
* - source/objLoader/glm.c
* 
* @section dir Directorios de la aplicacion
* - <b>images/</b><br/>Imagenes que utilizo como textura en pantalla completa
* - <b>doc/</b><br/>Contiene la documentacion de la aplicacion
* - <b>obj/</b><br/>Contiene los archivos Wavefront(.obj)
* - <b>source/</b><br/>Contiene los archivos fuentes headers (.h) y los sources (.cpp)
* 
* @section alg Algoritmos importantes
* <b>
* La "bola de delimitación" (o "disco" o "esfera") de un objeto geométrico es el círculo más pequeño en una esfera (en el espacio 3D),
* que contiene el objeto. También se le llama la "esfera de expansión mínima" del objeto. 
* En cualquier dimensión, la bola de delimitación de un objeto lineal geométrica (definida por su conjunto de vértices) es único,
* y se especifica por un punto central C y un radio R. Dado un conjunto S de puntos, hay una bola única de delimitación que contiene S .
* 
* Es fácil probar que un punto está dentro de una bola de delimitación de verificar que está dentro de la distancia R del centro de C.
* Además, dos bolas, por ejemplo B1 y B2, son disjuntos si la distancia entre sus centros es mayor que la suma de sus radios,
* es decir: d (C1, C2)> R1 + R2. Por lo tanto, estas pruebas básicas son muy simples y eficientes, 
* sin importar cuál es la dimensión de los objetos involucrados. 
* Este no es el caso de los contenedores lineales, donde el número de pruebas de la desigualdad aumenta con la dimensión del espacio. 
* Por otro lado, es más difícil de precompute la bola de delimitación de un conjunto de puntos ya que las expresiones de segundo grado están implicados.
* </b>
* <br/>
* ver ObstaculoList<br/>
* ver Camara<br/>
* <hr>
* @section sht Pantallasos
* @verbinclude sht
* <hr>
* <img src="http://www.univalle.edu.co/imagenes/logounivalle261x31.gif" alt="" height="42" width="42" /><br/>
* <center><b>[Santiago de Cali]<br/>
* [Escuela de ingenieria de sistemas y computacion]<br/>
* [Universidad del valle]<br/>
* [2012]</b><br/></center>
* <h1>Elaborado por:<font color="#F00">JA</font><font color="#0F0">Pe</font><font color="#00F">To</font></h1>
*/
