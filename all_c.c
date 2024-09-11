/* Ruler 1         2         3         4         5         6         7        */

/********************************** Headers ***********************************/

/* ------------------------ Inclusion of Std Headers ------------------------ */

#include <stdio.h>   // Due to printf()
#include <string.h>  // Due to strlen()
#include <stdbool.h> // Due to type of variable "bool"
#include <stdint.h>
#include <stdlib.h>
#include <windows.h> //Due to positionCursor() that uses COORD

/* ------------------------ Inclusion of Own Headers ------------------------ */

#include "all.h"

void positionCursor(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void die(char *(*aspect)[], int quantity)
{
  while( *(*aspect)[quantity] != '\0' )
  {
    *(*aspect)[quantity] = '\0';
    quantity--;
  }
}

/* Attributes to show how the alien looks like: */

ALIEN_T * setAlienImage( ALIEN_T *alien, char *(*looking)[] )
{

alien->image = looking;

alien->size[0]  = strlen( (*alien->image)[0] );
alien->size[1] = 0;
while( *(*alien->image)[alien->size[1]] != '\0' )
{
  alien->size[1]+=1;
}

return alien;

} /* setAlienImage */

ALIEN_T * setAlienPosition( ALIEN_T *alien, int x, int y )
{
alien->pos[0] = x;
alien->pos[1] = y;
alien->pos_fire[0]=x+5;
alien->pos_fire[1]=y+3;

return alien;

} /* setAlienPosition */

ALIEN_T *    setAlienColor( ALIEN_T *alien, char *color)
{
  alien->color = color;
  return alien;
} /* setAlienColor */

ALIEN_T * setAlienLife( ALIEN_T * alien, bool life ){
  alien->life = life;
  return alien;
} /* setAlienLife */

void killAlien(ALIEN_T * alien){
  setAlienLife(alien, false);
} /* killAlien */

ALIEN_T * setAlienScore(ALIEN_T *alien, int score)
{
  alien->score = score;
  return alien;
} /* setAlienScore */

void drawAlien( ALIEN_T *alien )
{
  int i = 0;
  for(i=0; *(*alien->image)[i] != '\0';i++ )
  {
     if(alien->life==true){
       positionCursor(alien->pos[0],alien->pos[1]+i);
       printf("%s",(*alien->image)[i]);
     }
  }
} /* drawAlien */

void eraseAlien( ALIEN_T *alien )
{
  int i = 0;
  char *borrar= "            ";
  for(i=0; *(*alien->image)[i] != '\0';i++ )
  {
    positionCursor(alien->pos[0],alien->pos[1]+i);
    printf("%s",borrar);
  }
} /* eraseAlien */



/************************** Declarations inside Arduino *************************/


ALIEN_T * setAlienImageArduino( ALIEN_T *alien, bool looking[8][12] )
{

for(int i = 0; i < 8;i++)
{
  for(int j = 0; j < 12; j++)
  {
    alien->imageArduino[i][j] = looking[i][j];
  }
}

alien->size[0]  = 12;
alien->size[1]   = 8;

return alien;

} /* setAlienImage */

ALIEN_T * setAlienPositionArduino( ALIEN_T *alien, int x, int y )
{
alien->pos[0] = x;
alien->pos[1] = y;

return alien;

} /* setAlienPosition */

ALIEN_T *    setAlienColorArduino( ALIEN_T *alien, char *color)
{
  alien->color = color;
  return alien;
} /* setAlienColor */

void drawAlienArduino( ALIEN_T *alien )
{
  //myGLCD.setColor(0, 255, 0); //Toca hacer algo con alien->color
  int squareW = 10;
  int squareH = 10;
  for(int i=0; i < alien->size[1]; i++ )
  {
    for(int j = 0; j < alien->size[0];j++)
    {
      if(alien->imageArduino[i][j])
     {
       //myGLCD.fillRect(alien->pos[0]+j*squareW,alien->pos[1]+i*squareH,alien->pos[0]+((j+1)*squareW),alien->pos[1]+((i+1)*squareH));
     }
    }
  }
} /* drawAlienArduino */

void eraseAlienArduino( ALIEN_T *alien )
{
  //myGLCD.setColor(0, 255, 0); //Definir el color de fondo
  int squareW = 10;
  int squareH = 10;
  for(int i=0; i < alien->size[1]; i++ )
  {
    for(int j = 0; j < alien->size[0];j++)
    {
      //myGLCD.fillRect(alien->pos[0],alien->pos[1],alien->pos[0]+squareW,alien->pos[1]+squareH);
    }
  }
} /* eraseAlien */



/* CANYON */




CANYON_T * setCanyonImage( CANYON_T *canyon, char *(*looking)[] )
{

canyon->image = looking;

canyon->size[0]  = strlen( (*canyon->image)[0] );
canyon->size[1] = 0;
while( *(*canyon->image)[canyon->size[1]] != '\0' )
{
  canyon->size[1]+=1;
}

return canyon;

} /* setCanyonImage */

CANYON_T * setCanyonPosition( CANYON_T *canyon, int x, int y )
{
canyon->pos[0] = x;
canyon->pos[1] = y;
canyon->pos_fire[0]=x+4;
canyon->pos_fire[1]=y-3;

return canyon;

} /* setCanyonPosition */

CANYON_T *    setCanyonColor( CANYON_T *canyon, char *color)
{
  canyon->color = color;
  return canyon;
} /* setCanyonColor */

CANYON_T *    setCanyonScore(CANYON_T * canyon, int score)
{
  canyon->score = score;

  return canyon;
} /* setCanyonScore */

void drawCanyon( CANYON_T *canyon )
{
  int i = 0;
  for(i=0; *(*canyon->image)[i] != '\0';i++ )
  {
    positionCursor(canyon->pos[0],canyon->pos[1]+i);
    printf("%s",(*canyon->image)[i]);
  }
} /* drawCanyon */

void eraseCanyon( CANYON_T *canyon )
{
  int i = 0;
  char *borrar = "         ";
  for(i=0; *(*canyon->image)[i] != '\0';i++ )
  {
    positionCursor(canyon->pos[0],canyon->pos[1]+i);
    printf("%s",borrar);
  }
} /* eraseCanyon */

CANYON_T * setCanyonLife( CANYON_T * canyon, bool life ){
  canyon->life = life;
  return canyon;
} /* setCanyonLife */


void  killCanyon(CANYON_T * canyon)
{
  setCanyonLife(canyon, false);
}/* killCanyon */



/*  WALL  */




WALL_T * setWallImage( WALL_T *wall, char *(*looking)[] )
{

wall->image = looking;

wall->size[0]  = strlen( (*wall->image)[0] );
wall->size[1] = 0;
while( *(*wall->image)[wall->size[1]] != '\0' )
{
  wall->size[1]+=1;
}

return wall;

} /* setWallImage */

WALL_T * setWallPosition( WALL_T *wall, int x, int y )
{
wall->pos[0] = x;
wall->pos[1] = y;

return wall;

} /* setWallPosition */

void drawWall( WALL_T *wall )
{
  int i = 0;
  for(i=0; *(*wall->image)[i] != '\0';i++ )
  {
    positionCursor(wall->pos[0],wall->pos[1]+i);
    printf("%s",(*wall->image)[i]);
  }
} /* drawWall */

void eraseWall( WALL_T *wall )
{
  int i = 0;
  char *borrar= "            ";
  for(i=0; *(*wall->image)[i] != '\0';i++ )
  {
    positionCursor(wall->pos[0],wall->pos[1]+i);
    printf("%s",borrar);
  }
} /* eraseAlien */

WALL_T * setWallLife(WALL_T *wall, int life)
{
  wall->life = life;
  if(wall->life <= -1)
    eraseWall(wall);
  if(wall->life == 0)
  {
    eraseWall( wall );
    setWallImage( wall, &wall2 );
    drawWall( wall );
  }
  if(wall->life == 1)
  {
    eraseWall( wall );
    setWallImage( wall, &wall1 );
    drawWall( wall );
  }
  if(wall->life >= 2)
  {
    eraseWall( wall );
    setWallImage( wall, &wall0 );
    drawWall( wall );
  }
  return wall;
} /* setWallLife */

/* Ruler 1         2         3         4         5         6         7        */

/********************************** Headers ***********************************/

/* ------------------------ Inclusion of Std Headers ------------------------ */

#include <stdio.h>  // Due to printf()
#include <string.h> // Due to strlen()
#include <stdbool.h> // Due to type of variable "bool"

/* ------------------------ Inclusion of Own Headers ------------------------ */



/************************** Declarations of New Types *************************/

/* Attributes to show how the alien looks like: */



BULLET_T *   setBulletAspect( BULLET_T * bullet, char *(*image)[]  ){
  bullet->aspect=image;
  return bullet;
}/*Set_Bullet_Aspect*/

BULLET_T *   setBulletPos( BULLET_T *bullet, int x, int y){
  bullet->pos[0] =x;
  bullet->pos[1] =y;
  return bullet;
}/*Set_Bullet_Aspect*/

BULLET_T * setBulletLife( BULLET_T * bullet, bool life ){
  bullet->life = life;
  return bullet;
}

BULLET_T * killBullet(BULLET_T * bullet)
{
  setBulletLife(bullet, false);
  return bullet;
} /* killBullet */

void drawBullet( BULLET_T * bullet){
  int i = 0;
  for(i=0; *(*bullet->aspect)[i] != '\0';i++ )
  {
    if(bullet->life==true){
      positionCursor(bullet->pos[0],bullet->pos[1]+i);
      printf("%s",(*bullet->aspect)[i]);
    }
  }
}

void eraseBullet( BULLET_T *bullet)
{
int i = 0;
  char *borrar= " ";
  for(i=0; *(*bullet->aspect)[i] != '\0';i++ )
  {
    positionCursor(bullet->pos[0],bullet->pos[1]+i);
    printf("%s",borrar);
  }
} /* eraseAlien */