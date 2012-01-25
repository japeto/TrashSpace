/*!
 * \file  defConstantes.h
 * \brief EN ESTA CLASE SE ESTABLECIERON TODAS LAS DEFINICIONES CONSTANTES 
 * 		QUE NO PUEDE SER ALTERADOS DURANTE LA EJECUCIÓN DE UN PROGRAMA 
 * 		Y QUE SE UTILIZAN COMO ATRIBUTOS DE APLICACION
 * \author Jefferson Amado Pe&ntilde;a Torres <jeffersonamado@gmail.com>
 *  \version   1.8
 * \date   2011 - Last Modified: 19/01/012
*/

#ifndef DEFCONSTANTES_H
#define DEFCONSTANTES_H
/** \def NAMEAPP
      \brief nombre de la Aplciacion
*/
#define NAMEAPP "TrashSpace"
/** \def VERSIONAPP
      \brief nombre de la Aplciacion
*/
#define VERSIONAPP "v1.0"
/** \def M_PI
      \brief Aproximacion del numero PI
*/
#ifndef M_PI
	#define M_PI            3.14159265f
#endif
/** \def NULL
      \brief NULL=0
*/
#ifndef NULL
	#define NULL            0
#endif

/** \def WIDTH
      \brief Ancho de la ventana
*/
#define WIDTH           800
/** \def HEIGHT
      \brief Alto de la ventana
*/
#define HEIGHT          600
/** \def GAME_WIDTH
      \brief Ancho de la ventana segunla coordenada X -ancho del campo de vista
*/
#define GAME_WIDTH      200     // X
/** \def GAME_HEIGHT
      \brief Alto de la ventana segunla coordenada Y -alto del campo de vista
*/
#define GAME_HEIGHT     200     // Y
/** \def GAME_DEPTH
      \brief profundidad de la ventana segunla coordenada Z
*/
#define GAME_DEPTH     -1000    // Z
/** \def FOV
      \brief Profundidad -field of view -Campo de vista hasta donde puede ver el juagdor
*/
#define FOV             10
/** \def LEVEL_TIME
      \brief Tiempo de juego para avanzar de nivel
*/
#define LEVEL_TIME      60000 // 1 minute/level
/** \def TITLE_TIME
      \brief 
*/
#define TITLE_TIME      1
/** \def MARGIN
      \brief Espacio entre los paneles de la aplicacion 
*/
#define MARGIN          5
/** \def MESH_SIZE
      \brief Producto cruz entre alto y ancho
*/
#define MESH_SIZE       40// should be a factor of GAME_WIDTH and GAME_HEIGHT
/** \def NUM_STARS
      \brief numero de estrellas en la aplicacion
*/
#define NUM_STARS       1000
/** \def STAR_SPREAD
      \brief propagacion de estrellas en la aplicacion
*/
#define STAR_SPREAD     4
/** \def MOVE_BY
      \brief Velocidad de la nave
*/
#define MOVE_BY         15
/** \def FOGEND_L1
      \brief Niebla principal
*/
#define FOGEND_L1       1.0
/** \def FOGEND_L2
      \brief Niebla principal
*/
#define FOGEND_L2       0.85
/** \def FOGEND_L3
      \brief Niebla principal
*/
#define FOGEND_L3       0.70
/** \def SPAWN_L1
      \brief Sombra principal
*/
#define SPAWN_L1        1000
/** \def SPAWN_L2
      \brief Sombra principal
*/
#define SPAWN_L2        500
/** \def SPAWN_L3
      \brief Sombra principal
*/
#define SPAWN_L3        200
/*! Define los tipos de objetos que se cargaran en la aplicacion */
enum objType{	
		PLANETA,
		MODULO,
		VEHICULO1,
		VEHICULO2,
		SATELITE,
		TELESCOPIOE,
		SATELITE1,
		ANTENA,
		VEHICULO3,
		BUSCADOR
		//NAVECOBRA,/*!< http://www.turbosquid.com/3d-models/cobra-mk-ii-fighter-space-3ds/256898 <br/> <img src="http://files.turbosquid.com/Preview/2010/12/05__17_14_00/pic3.jpg8355b9dc-8e3b-4d04-a5f3-6299c24ff818Larger.jpg" alt="" height="42" width="42" /> */
		//TRAJEGEMINI,/*!< http://www.nasa.gov/multimedia/3d_resources/assets/gemini_suit.html <br/> <img src="http://www.nasa.gov/images/content/473185main_gemini_suit_428-321.jpg" alt="" height="42" width="42" /> */
		//NAVEGHAWK,/*!< http://www.nasa.gov/multimedia/3d_resources/assets/global_hawk.html <br/> <img src="http://www.nasa.gov/images/content/473224main_global_hawk_428-321.jpg" alt="" height="42" width="42" /> */
		//HombreEspacial1,/*!< http://www.nasa.gov/multimedia/3d_resources/assets/mkiii_suit.html <br/> <img src="http://www.nasa.gov/images/content/473256main_mkiii_suit_428-321.jpg" alt="" height="42" width="42" /> */
		//HombreEspacial2,/*!< http://www.nasa.gov/multimedia/3d_resources/assets/aces.html <br/> <img src="http://www.nasa.gov/images/content/473065main_aces_428-321.jpg" alt="" height="42" width="42" /> */
		//HombreEspacial3,/*!< http://www.nasa.gov/multimedia/3d_resources/assets/emu.html <br/> <img src="http://www.nasa.gov/images/content/473157main_emu_428-321.jpg" alt="" height="42" width="42" /> */
		//MERCURY,/*!< http://www.nasa.gov/multimedia/3d_resources/assets/mercury_suit.html <br/> <img src="http://www.nasa.gov/images/content/473235main_mercury_suit_428-321.jpg" alt="" height="42" width="42" /> */
		//VAISSEAU/*!< http://www.turbosquid.com/3d-models/free-obj-mode-starship-ship/642303 <br/> <img src="http://files.turbosquid.com/Preview/2011/12/02__00_42_59/9-vaisseau.jpgdb1a8b5d-d650-414b-9aa9-85d1c9389eebLarge.jpg" alt="" height="12" width="12" /> */
		};

/** \def PLAYER_SIZE
      \brief Tama&ntilde;o espacio de juego para el jugador
*/
#define PLAYER_SIZE     1
/** \def PLAYER_STEP
      \brief Velocidad de avance del juagador
*/
#define PLAYER_STEP     2
/** \def LEAN_DECELL
      \brief inclinacion
*/
#define LEAN_DECELL	10
/** \def SENSITIVITY
      \brief Sensivilidad que posee los movimientos rapidos del mouse
*/
#define SENSITIVITY     70
/** \def PARTICLE_COUNT
      \brief Numero de particulas en la aplicacion antes de cambiar de nivel
*/
#define PARTICLE_COUNT  1000
/** \def P_HIT
      \brief Colision entre elementos
*/
#define P_HIT          -100
/** \def P_AVOID
      \brief espacio para evitar el choque
*/
#define P_AVOID         2

#endif //DEFCONSTANTES_H
//Jefferson Amado Pena Torres $(JAPeTo)
