
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>

#include <GL/glut.h> 			//libreria grafica

#include "defConstantes.h"     		//Definiciones globales y constantes
#include "Camara.h"       		// 
#include "Player.h"       		// 
#include "ObstaculoList.h" 		//

#include "imageloader.h"  		//
using namespace std;

bool boundSphere = false;
bool testMode = false;

int width  = WIDTH;       		//
int height = HEIGHT;      		//

//
enum gameState { MENU, LEVEL, GAME_OVER, INSTRUCTIONS, CREDITS };
gameState state = MENU;

int level = 0;
int levelCounter = LEVEL_TIME;
int titleCounter = TITLE_TIME;

//
int starPos[NUM_STARS][2];
int tunnelSize = ( -GAME_DEPTH )*2;

//
float fogStart = 0.0;
float fogEnd   = 0.0;

//
bool mesh = false;
int margin = MARGIN;

//
GLfloat position[] = {0,0,0,0};
        
// Game speed (milliseconds)
int speedMove   = 100;
int speedCreate = 1000;

// Rotation
float xRot = 0.0;
float yRot = 0.0;
float xPrev = width/2;
float yPrev = height/2;
float planetAngle = 0;

// Texture
GLuint worldTexId;
GLuint menuTexId;
GLuint gameoverTexId;
GLuint sunTexId;
GLuint playTexId;
GLuint instructionTexId;
GLuint creditsTexId;
GLuint mainMenuTexId;
GLuint instructionsTexId;
GLuint creditsSTexId;

// Keyboard
bool* keyStates = new bool[256];

// Create Class Instances
Camara caMara;
Player juGador;
ObstaculoList listaOstaculos;


// Game values for Level 1
void setLevel1(){
	
glClearColor(90,90,90,0);
    state = LEVEL;
    level = 1;
    levelCounter = LEVEL_TIME;
    titleCounter = TITLE_TIME;
    
    // Start fog at 1/2 of play field for Level 1
    fogStart = -(GAME_DEPTH) * FOGEND_L1*0.50;
    fogEnd   = -(GAME_DEPTH) * FOGEND_L1;

    speedCreate = SPAWN_L1;

    // Clear level
    listaOstaculos.removeAll();
}

// Game values for Level 2
void setLevel2()
{
	glClearColor(0,90,0,0);
    state = LEVEL;
    level = 2;
    levelCounter = LEVEL_TIME;
    titleCounter = TITLE_TIME;
    
    // Start fog at 1/2 of play field for Level 2
    fogStart = -(GAME_DEPTH) * FOGEND_L2*0.50;
    fogEnd   = -(GAME_DEPTH) * FOGEND_L2;

    speedCreate = SPAWN_L2;
    
    // Clear level
    listaOstaculos.removeAll();
}

void setLevel3()
{	
	glClearColor(0,0,90,0);
    state = LEVEL;
    level = 3;
    levelCounter = LEVEL_TIME;
    titleCounter = TITLE_TIME;

    // Start fog at 1/2 of play field for Level 3
    fogStart = -(GAME_DEPTH) * FOGEND_L3*0.50;
    fogEnd   = -(GAME_DEPTH) * FOGEND_L3;

    speedCreate = SPAWN_L3;
    
    // Clear level
    listaOstaculos.removeAll();
}

void setLevel3Plus()
{
	glClearColor(90,0,0,0);
	state= LEVEL;
	level = level+1;
	levelCounter= LEVEL_TIME;
	titleCounter = TITLE_TIME;

	//fog constant
	fogStart = -(GAME_DEPTH) * FOGEND_L3*0.50;
    fogEnd   = -(GAME_DEPTH) * FOGEND_L3;

	speedCreate = SPAWN_L3/(level);

	// Clear level
    listaOstaculos.removeAll();
}

void resetLevel3Plus()
{
	state= LEVEL;
	level = level;
	levelCounter= LEVEL_TIME;
	titleCounter = TITLE_TIME;

	//fog constant
	fogStart = -(GAME_DEPTH) * FOGEND_L3*0.50;
    fogEnd   = -(GAME_DEPTH) * FOGEND_L3;

	speedCreate = SPAWN_L3/(level);
}

//
void printString(char* s)
{
    glPushMatrix();
    char* p;
    for (p = s; *p; p++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p);
    glPopMatrix();
}

void drawMenu(){
	
    glDisable(GL_FOG);
    glDisable(GL_LIGHTING);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(1.0, 1.0, 1.0);	

    glEnable(GL_TEXTURE_2D);

	glBindTexture( GL_TEXTURE_2D, playTexId ); //carga de la texturas
	glBegin(GL_QUADS);
		glTexCoord2f( 0, 0 ); glVertex2f( width*.1, height*.05);
		glTexCoord2f( 1, 0 ); glVertex2f( width*.35, height*.05);
		glTexCoord2f( 1, 1 ); glVertex2f( width*.35, height*.25);
		glTexCoord2f( 0, 1 ); glVertex2f( width*.1, height*.25);
    glEnd();

	glBindTexture( GL_TEXTURE_2D, instructionTexId );//textura de instruccion
	glBegin(GL_QUADS);
		glTexCoord2f( 0, 0 ); glVertex2f( width*.375, height*.05);
		glTexCoord2f( 1, 0 ); glVertex2f( width*.625, height*.05);
		glTexCoord2f( 1, 1 ); glVertex2f( width*.625, height*.25);
		glTexCoord2f( 0, 1 ); glVertex2f( width*.375, height*.25);
    glEnd();

	glBindTexture( GL_TEXTURE_2D, creditsTexId ); //textura creditos
	glBegin(GL_QUADS);
		glTexCoord2f( 0, 0 ); glVertex2f( width*.65, height*.05);
		glTexCoord2f( 1, 0 ); glVertex2f( width*.9, height*.05);
		glTexCoord2f( 1, 1 ); glVertex2f( width*.9, height*.25);
		glTexCoord2f( 0, 1 ); glVertex2f( width*.65, height*.25);
    glEnd();
	
    glBindTexture( GL_TEXTURE_2D, menuTexId );	//textura de menu
    glBegin(GL_QUADS);
		glTexCoord2f( 0, 0 ); glVertex2f( 0, 0);
		glTexCoord2f( 1, 0 ); glVertex2f( width, 0);
		glTexCoord2f( 1, 1 ); glVertex2f( width, height);
		glTexCoord2f( 0, 1 ); glVertex2f( 0, height);
    glEnd();

    glDisable(GL_TEXTURE_2D);
}

void drawGameOver(){
	
    glDisable(GL_FOG);
    glDisable(GL_LIGHTING);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Points
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2i(width/2 - 40, height/2 - 18/2);
    char buffer[20];
    sprintf(buffer, "Score: %i", juGador.getPoints());
    printString(buffer);

    // Game Over Screen
    glEnable(GL_TEXTURE_2D);

	    glBindTexture( GL_TEXTURE_2D, mainMenuTexId ); //textura principal
		glBegin(GL_QUADS);
		glTexCoord3f( 0, 0, -5 ); glVertex2f( width*.375, height*.15);
		glTexCoord3f( 1, 0, -5 ); glVertex2f( width*.625, height*.15);
		glTexCoord3f( 1, 1, -5 ); glVertex2f( width*.625, height*.35);
		glTexCoord3f( 0, 1, -5 ); glVertex2f( width*.375, height*.35);
		glEnd();

		glBindTexture( GL_TEXTURE_2D, gameoverTexId ); //textura game over
		glBegin(GL_QUADS);
		glTexCoord3f( 0, 0, -5 ); glVertex2f( 0, 0);
		glTexCoord3f( 1, 0, -5 ); glVertex2f( width, 0);
		glTexCoord3f( 1, 1, -5 ); glVertex2f( width, height);
		glTexCoord3f( 0, 1, -5 ); glVertex2f( 0, height);
		glEnd();

    glDisable(GL_TEXTURE_2D);
}

void drawInstructions(){
	glDisable(GL_FOG);
    glDisable(GL_LIGHTING);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(1.0, 1.0, 1.0);	

    glEnable(GL_TEXTURE_2D);
    glBindTexture( GL_TEXTURE_2D, instructionsTexId );	//textura instruccion
    glBegin(GL_QUADS);
		glTexCoord2f( 0, 0 ); glVertex2f( 0, 0);
		glTexCoord2f( 1, 0 ); glVertex2f( width, 0);
		glTexCoord2f( 1, 1 ); glVertex2f( width, height);
		glTexCoord2f( 0, 1 ); glVertex2f( 0, height);
    glEnd();

    glDisable(GL_TEXTURE_2D);
}

void drawCredits()
{
	glDisable(GL_FOG);
    glDisable(GL_LIGHTING);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(1.0, 1.0, 1.0);	

    glEnable(GL_TEXTURE_2D);
    glBindTexture( GL_TEXTURE_2D, creditsSTexId );	//textura creditos
    glBegin(GL_QUADS);
		glTexCoord2f( 0, 0 ); glVertex2f( 0, 0);
		glTexCoord2f( 1, 0 ); glVertex2f( width, 0);
		glTexCoord2f( 1, 1 ); glVertex2f( width, height);
		glTexCoord2f( 0, 1 ); glVertex2f( 0, height);
    glEnd();

    glDisable(GL_TEXTURE_2D);
}

void drawStars(){
	
    glDisable(GL_LIGHTING);
    glDisable(GL_FOG);

    // Stars
    for (int i = 0; i < NUM_STARS; i++)
    {
        glPushMatrix();
        glTranslatef( starPos[i][0], starPos[i][1], GAME_DEPTH );
        glBegin(GL_QUADS);
        glVertex2f( -0.5, -0.5);
        glVertex2f( +0.5, -0.5);
        glVertex2f( +0.5, +0.5);
        glVertex2f( -0.5, +0.5);
        glEnd();
        glPopMatrix();
    }
    glEnable(GL_FOG);
    glEnable(GL_LIGHTING);
}

void drawLight(){
	
    glPushMatrix();
    glEnable(GL_LIGHTING);
    GLfloat ambientLight[] = { 0.1, 0.1, 0.1, 1 };
    glLightModelfv( GL_LIGHT_MODEL_AMBIENT, ambientLight );

    glEnable(GL_LIGHT0);
    GLfloat lightColor0[] = { 0.6, 0.5, 0.1 };
    GLfloat lightPos0[] = { 0,-.25,1, 0.0 };
	glLightfv( GL_LIGHT0, GL_DIFFUSE, lightColor0 );
    glLightfv( GL_LIGHT0, GL_POSITION, lightPos0 );
}

void drawFog(){
	
    GLfloat fogColor[3] = { 0.0, 0.0, 0.0 };
    glEnable(GL_FOG);
    glFogfv( GL_FOG_COLOR, fogColor);
    glFogi( GL_FOG_MODE, GL_LINEAR);
    glFogi( GL_FOG_START, fogStart);
    glFogi( GL_FOG_END, fogEnd);
    glPopMatrix();
}

void drawPanels(){

    if (mesh){
        margin = PLAYER_SIZE + 5;
    }else{ // Resizable glass panels
        // Top Panel:
        glPushMatrix();
        glTranslatef( GAME_WIDTH/2, GAME_HEIGHT + margin, -tunnelSize/2 + 50 );
        glScalef( GAME_WIDTH + margin*2, 1.0, tunnelSize );
        glColor4f( 0.9, 0.95, 1.0, 0.2 );
        glutSolidCube(1);
        glPopMatrix();

        // Bottom Panel:
        glPushMatrix();
        glTranslatef( GAME_WIDTH/2, -margin, -tunnelSize/2 + 50 );
        glScalef( GAME_WIDTH + margin*2, 1.0, tunnelSize );
        glColor4f( 0.9, 0.95, 1.0, 0.2 );
        glutSolidCube(1);
        glPopMatrix();

        // Left Panel:
        glPushMatrix();
        glTranslatef( -margin, GAME_HEIGHT/2, -tunnelSize/2 + 50 );
        glScalef(1.0, GAME_HEIGHT + margin*2, tunnelSize);
        glColor4f(0.9, 0.95, 1.0, 0.2);
        glutSolidCube(1);
        glPopMatrix();

        // Right Panel:
        glPushMatrix();
        glTranslatef(GAME_WIDTH + margin, GAME_HEIGHT/2, -tunnelSize/2 + 50);
        glScalef(1.0, GAME_HEIGHT + margin*2, tunnelSize);
        glColor4f(0.9, 0.95, 1.0, 0.2);
        glutSolidCube(1);
        glPopMatrix();
    }
}

void drawStats()
{
    glDisable(GL_LIGHTING);
    glDisable(GL_FOG);

    glPushMatrix();

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(1.0, 1.0, 1.0);

    // Level
    char buffer[20];
    glRasterPos2i( 1, height - 18);
    sprintf(buffer, "Level %i", level);
    printString(buffer);

    if (titleCounter != 0)
    {
        glColor3f(1,1,1);
        glRasterPos2i(width/2 - 40, height/2 - 18);
        printString(buffer);
        titleCounter -= 1;
    }
	
    // Lives, Health & Score
    glRasterPos2i( 1, 1);
    sprintf(buffer, "Lives: %i", juGador.getLives());
    printString(buffer);
    sprintf(buffer, "    Health: %i", juGador.getHealth());
    printString(buffer);
    sprintf(buffer, "    Score: %i", juGador.getPoints());
    printString(buffer);
    
    if (testMode)
    {
        glRasterPos2i( width/2 - 10, 0);
        sprintf(buffer, "TEST MODE");
        printString(buffer);
    }

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective( caMara.fov, width/height, caMara.zNear, caMara.zFar );
    glMatrixMode(GL_MODELVIEW);

    glPopMatrix();

    glEnable(GL_FOG);
    glEnable(GL_LIGHTING);
}
    
void keyOperations (void){  
    if (keyStates['s']||keyStates['S']){
        if (juGador.getYPos() > -margin + PLAYER_SIZE){
            juGador.Move(0,-PLAYER_STEP);   
            caMara.translate(0,-PLAYER_STEP,0);
            if(juGador.getXLean()>=15)
                juGador.setXLean(15);	//velocidad de bajada
            else
                juGador.setXLean(juGador.getXLean()+3);
        }
    } 
    if (keyStates['w'] || keyStates['W']){
        if (juGador.getYPos() < GAME_HEIGHT + margin - PLAYER_SIZE){
            juGador.Move(0,PLAYER_STEP); 
            caMara.translate(0,PLAYER_STEP,0);
            if(juGador.getXLean()<=-15)
                juGador.setXLean(-15); //velocidad de subida
            else
                juGador.setXLean(juGador.getXLean()-3);
        }  
    }
	if (keyStates['d']|| keyStates['D']) {
        if (juGador.getXPos() < GAME_WIDTH + margin - PLAYER_SIZE){
            juGador.Move(PLAYER_STEP,0); 
            caMara.translate(PLAYER_STEP,0,0);
			if(juGador.getZLean()<=-55)
                juGador.setZLean(-55);
            else
                juGador.setZLean(juGador.getZLean()-3);
        }
	}
	if (keyStates['a']||keyStates['A']) { 
        if (juGador.getXPos() > -margin + PLAYER_SIZE){
            juGador.Move(-PLAYER_STEP,0); 
            caMara.translate(-PLAYER_STEP,0,0);
            if(juGador.getZLean()>=55)
                juGador.setZLean(55);
            else
                juGador.setZLean(juGador.getZLean()+3);
        }
	}  
    juGador.Lean();

  if (testMode){
    if (keyStates['r']){
	   juGador.setYspin(juGador.getYSpin()+5);
	}

    // Enable 'bounding' spheres used for collision
	if (keyStates['1']) 
	{
        boundSphere = true;
	}

    // Enable 'bounding' spheres used for collision
	if (keyStates['2']) 
	{
        boundSphere = false;
	} 

    // Extend the play area
	if (keyStates['3']) 
	{
        static bool increasing = true;
        if (increasing && margin < 100)                     // max size
            margin += 5;
        else if (!increasing && margin > (PLAYER_SIZE + 5)) // min size
            margin -= 5;
        else if (increasing)
            increasing = false;
        else
            increasing = true;
	}

    // Select glass or mesh panel
    if (keyStates['4'])
    {
        mesh = !mesh;
    }
  }

    if (keyStates['+'])
    {
        if (caMara.cz > -6) caMara.translate(0.0, 0.0,-1.0);
    }

    if (keyStates['-'])
    {
        if (caMara.cz < 20) caMara.translate(0.0, 0.0, 1.0);
    }
    
    if (keyStates['~'])
    {
        testMode = !testMode;
    }

	if(keyStates[27])
	{
	    exit(0);
	}

} 
 
///metodo display de GLUT para crear los graficos
void display(void){
	keyOperations(); 
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0,0,0,0);
    glPushMatrix();

    switch (state){
        case MENU:
            juGador.setLives(3);
            juGador.setHealth(3);
            juGador.setPoints(0);
            drawMenu();            
        break;
		case INSTRUCTIONS:			
			drawInstructions();
		break;
		case CREDITS:
			drawCredits();
		break;
        case LEVEL:
            //Establece la caMaraara
			caMara.view();
            // Mueve la vista de la caMaraara segun el mouse
            glTranslatef(juGador.getXPos(), juGador.getYPos(), caMara.dz+5.0);
            glRotatef(xRot*SENSITIVITY, 1.0, 0.0, 0.0);
            glRotatef(yRot*SENSITIVITY, 0.0, 1.0, 0.0);
            glTranslatef(-juGador.getXPos(), -juGador.getYPos(), -(caMara.dz+5.0));
            //Habilitar la luz
            drawLight();
            //Habilitar la profundidad
            drawFog();
            //Dibujar las estrellas
            drawStars();
            // Dibujar paneles y espacio de la ventana
            drawPanels();
            // Dibujar los obstaculos
            listaOstaculos.drawAll(level, boundSphere);
            // Dibujar jugador
            juGador.draw(boundSphere);
            // Dibujar texto en pantalla
            drawStats();
			glEnd();
        break;
        case GAME_OVER:
        
			cout<<"game over";
            drawGameOver();

        break;
    }
    
    glPopMatrix();
    glutSwapBuffers();
}

///Metodo GLUT para repintar
void reshape(int w, int h){
    xPrev = xPrev / width  * w;
    yPrev = yPrev / height * h;
    width = w;
    height = h;
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective( caMara.fov, w/h, caMara.zNear, caMara.zFar );
    glMatrixMode(GL_MODELVIEW);
    caMara.view();
}

///Funciones para las teclas especiales
void specialKey(int key, int x, int y){
    switch (key){
        case GLUT_KEY_F1:
            setLevel1();
        break;
        case GLUT_KEY_F2:
            setLevel2();
        break;
        case GLUT_KEY_F3:
            setLevel3();
        break;
        case GLUT_KEY_F4:
            state = GAME_OVER;
        break;
    }
    glutPostRedisplay();
}

void keyPressed (unsigned char key, int x, int y){  
	 keyStates[key] = true; // Set the state of the current key to pressed  
}  
void keyUp (unsigned char key, int x, int y) {
	keyStates[key] = false; // Set the state of the current key to not pressed  
}  

///Funciones del mouse
void mouse(int x, int y){
/*    float xDiff = (x - xPrev)/height;
    float yDiff = (y - yPrev)/width;
    xPrev = x;
    yPrev = y;
    xRot += (float) yDiff;
    yRot += (float) xDiff;*/
}

///metodo que maneja los eventos del mouse
void click(int button, int stat, int x, int y){

	if (state == MENU){
		if (x>width*.1&&x<width*.35&&y<height*.95&&y>height*.75&&button == GLUT_LEFT_BUTTON && stat == GLUT_UP){       
			setLevel1();
		}
		if (x>width*.375&&x<width*.625&&y<height*.95&&y>height*.75&&button == GLUT_LEFT_BUTTON && stat == GLUT_UP){   
			state=INSTRUCTIONS;
		}
		if (x>width*.65&&x<width*.9&&y<height*.95&&y>height*.75&&button == GLUT_LEFT_BUTTON && stat == GLUT_UP){   
			state=CREDITS;
		}
	}else if (state == GAME_OVER) {
		if(x>width*.375&&x<width*.625&&y<height*.85&&y>height*.65&&button == GLUT_LEFT_BUTTON && stat == GLUT_UP){   
			state=MENU;
		}
	}else if (state == INSTRUCTIONS){
		if(button == GLUT_LEFT_BUTTON && stat == GLUT_UP)
			state=MENU;
	}else if (state == CREDITS){
		if(button == GLUT_LEFT_BUTTON && stat == GLUT_UP)
			state=MENU;
	}
    // Wheel down - Zoom in
    if (button == 4){
        if (caMara.cz > 0) caMara.translate(0.0, 0.0,-1.0);
    } // Wheel up - Zoom out
    else if (button == 3){
        if (caMara.cz < 40) caMara.translate(0.0, 0.0, 1.0);
    }
    glutPostRedisplay();
}

///Metodo que mantiene los obstaculos en movimiento y su velocidad depende del nivel
void moveTimer(int value){
	planetAngle+=.5;
    if (state == LEVEL && !listaOstaculos.isEmpty()){

        listaOstaculos.moveAll(level);			//mueve los obstaculos
		if(listaOstaculos.CollidesAll(&juGador)){ //pueba de colision
            juGador.addPoints(P_HIT);
											//perdida de vida por colision
            if (juGador.getHealth() > 1){
                juGador.setHealth(juGador.getHealth()-1);
            }else{
                juGador.setHealth(3);		//restablece la salud
                if (juGador.getLives() > 0){	//prueba de muerte
                    juGador.setLives(juGador.getLives()-1);//muriendose
                    switch (level){
                        case 1:
                            setLevel1();
                        break;
                        case 2:
                            setLevel2();
                        break;
                        case 3:
                            setLevel3();
						default:
							resetLevel3Plus();
                        break;
                    }
                }else{
					state = GAME_OVER;	//fin del juego
                }
            }
        }
        juGador.addPoints(P_AVOID);

		// Cuando los obstaculos deben desaparecer
		if (state == LEVEL && !listaOstaculos.isEmpty() && listaOstaculos.getFirst()->getZPos() > 50){
			listaOstaculos.remove();
		}
        glutPostRedisplay();
    }

    // Actualiza el caMarabio de nivel
    if (state == LEVEL){
        levelCounter -= speedMove;
        if (levelCounter <= 0){
            switch (level){
                case 1:
                    setLevel2();
                break;
                case 2:
                    setLevel3();
                break;
				default:
					setLevel3Plus();
                break;
            }
        }
    }
    glutTimerFunc(speedMove, moveTimer, 0);
}
///Metodo que permite crear un obstaculo segun un intervalo de tiempo en una posicion cualquiera
void createTimer(int value){
    if (state == LEVEL)    {
        listaOstaculos.insert( rand() % GAME_WIDTH/2, rand() % GAME_HEIGHT/2, GAME_DEPTH, level );
    }
    glutTimerFunc(speedCreate, createTimer, 0);
}

///Metodo que inicializa la libreria OpenGl
void init(void){
	
	cout<<"Jefferson Amado Peña Torres\n";
	// Initialise global variables
	for(int key =0; key!=256; key++){
		keyStates[key] = false; // Set the state of the current key to not pressed  
	}
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);
    
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_FOG);
    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_BLEND);
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

    //Load
    Image* image = loadBMP("./images/pantalla1.bmp");
    glGenTextures( 1, &menuTexId );
    glBindTexture( GL_TEXTURE_2D, menuTexId );
    gluBuild2DMipmaps( GL_TEXTURE_2D, GL_RGB, image->width, image->height,
                       GL_RGB, GL_UNSIGNED_BYTE, image->pixels );
    
    // Load 
    image = loadBMP("./images/pantalla2.bmp");
    glGenTextures( 1, &gameoverTexId );
    glBindTexture( GL_TEXTURE_2D, gameoverTexId );
    gluBuild2DMipmaps( GL_TEXTURE_2D, GL_RGB, image->width, image->height,
                       GL_RGB, GL_UNSIGNED_BYTE, image->pixels );
   
	// Load 
    image = loadBMP("./images/boton1.bmp");
    glGenTextures( 1, &playTexId );
    glBindTexture( GL_TEXTURE_2D, playTexId );
    gluBuild2DMipmaps( GL_TEXTURE_2D, GL_RGB, image->width, image->height,
                       GL_RGB, GL_UNSIGNED_BYTE, image->pixels );

	// Load 
    image = loadBMP("./images/boton2.bmp");
    glGenTextures( 1, &instructionTexId );
    glBindTexture( GL_TEXTURE_2D, instructionTexId );
    gluBuild2DMipmaps( GL_TEXTURE_2D, GL_RGB, image->width, image->height,
                       GL_RGB, GL_UNSIGNED_BYTE, image->pixels );

	// Load 
    image = loadBMP("./images/boton3.bmp");
    glGenTextures( 1, &creditsTexId );
    glBindTexture( GL_TEXTURE_2D, creditsTexId );
    gluBuild2DMipmaps( GL_TEXTURE_2D, GL_RGB, image->width, image->height,
                       GL_RGB, GL_UNSIGNED_BYTE, image->pixels );

	// Load 
    image = loadBMP("./images/boton4.bmp");
    glGenTextures( 1, &mainMenuTexId );
    glBindTexture( GL_TEXTURE_2D, mainMenuTexId );
    gluBuild2DMipmaps( GL_TEXTURE_2D, GL_RGB, image->width, image->height,
                       GL_RGB, GL_UNSIGNED_BYTE, image->pixels );

	//Intrucciones
    image = loadBMP("./images/pantalla3.bmp");
    glGenTextures( 1, &instructionsTexId );
    glBindTexture( GL_TEXTURE_2D, instructionsTexId );
    gluBuild2DMipmaps( GL_TEXTURE_2D, GL_RGB, image->width, image->height,
                       GL_RGB, GL_UNSIGNED_BYTE, image->pixels );

	//Autor
    image = loadBMP("./images/japeto.bmp");
    glGenTextures( 1, &creditsSTexId );
    glBindTexture( GL_TEXTURE_2D, creditsSTexId );
    gluBuild2DMipmaps( GL_TEXTURE_2D, GL_RGB, image->width, image->height,
                       GL_RGB, GL_UNSIGNED_BYTE, image->pixels );

	
	// Load sun texture
	//http://www.turbosquid.com/FullPreview/Index.cfm/ID/557319
    image = loadBMP("./images/Sun.bmp");
    glGenTextures( 1, &sunTexId );
    glBindTexture( GL_TEXTURE_2D, sunTexId );
    gluBuild2DMipmaps( GL_TEXTURE_2D, GL_RGB, image->width, image->height,
                       GL_RGB, GL_UNSIGNED_BYTE, image->pixels );
    delete image;
}

int main(int argc, char** argv)
{
    srand( time(NULL) );

    for (int i = 0; i < NUM_STARS; i++){
        starPos[i][0] = rand() % (STAR_SPREAD*GAME_WIDTH)  - (STAR_SPREAD*GAME_WIDTH/2 + GAME_WIDTH/2);
        starPos[i][1] = rand() % (STAR_SPREAD*GAME_HEIGHT) - (STAR_SPREAD*GAME_HEIGHT/2+ GAME_HEIGHT/2);
    }  
    // GLUT 
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutCreateWindow(NAMEAPP);

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

	glutKeyboardUpFunc(keyUp);
	glutKeyboardFunc(keyPressed);

    glutSpecialFunc(specialKey);
    glutPassiveMotionFunc(mouse);
    glutMouseFunc(click);
    
    glutTimerFunc(speedMove, moveTimer, 0);
    glutTimerFunc(speedCreate, createTimer, 0);
    glutMainLoop();

    exit(0);
}
