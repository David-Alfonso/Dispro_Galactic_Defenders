/* Ruler 1         2         3         4         5         6         7        */

/********************************** Headers ***********************************/

/* ------------------------ Inclusion of Std Headers ------------------------ */

#include <stdio.h>   // Due to printf()
#include <string.h>  // Due to strlen()
#include <stdbool.h> // Due to type of variable "bool"

/* ------------------------ Inclusion of Own Headers ------------------------ */

#include "alien.h"
#include "functions.h"



/************************** Declarations of New Types *************************/

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

return alien;

} /* setAlienPosition */

ALIEN_T *    setAlienColor( ALIEN_T *alien, char *color)
{
  alien->color = color;
  return alien;
} /* setAlienColor */

void drawAlien( ALIEN_T *alien )
{
  int i = 0;
  for(i=0; *(*alien->image)[i] != '\0';i++ )
  {
    positionCursor(alien->pos[0],alien->pos[1]+i);
    printf("%s",(*alien->image)[i]);
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