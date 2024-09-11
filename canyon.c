/* Ruler 1         2         3         4         5         6         7        */

/********************************** Headers ***********************************/

/* ------------------------ Inclusion of Std Headers ------------------------ */

#include <stdio.h>  // Due to printf()
#include <string.h> // Due to strlen()
#include <stdbool.h> // Due to type of variable "bool"

/* ------------------------ Inclusion of Own Headers ------------------------ */

#include "canyon.h"
#include "functions.h"


/************************** Declarations of New Types *************************/

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

} /* setAlienImage */

CANYON_T * setCanyonPosition( CANYON_T *canyon, int x, int y )
{
canyon->pos[0] = x;
canyon->pos[1] = y;

return canyon;

} /* setAlienPosition */

CANYON_T *    setCanyonColor( CANYON_T *canyon, char *color)
{
  canyon->color = color;
  return canyon;
} /* setAlienColor */

void drawCanyon( CANYON_T *canyon )
{
  int i = 0;
  for(i=0; *(*canyon->image)[i] != '\0';i++ )
  {
    positionCursor(canyon->pos[0],canyon->pos[1]+i);
    printf("%s",(*canyon->image)[i]);
  }
} /* drawAlien */

void eraseCanyon( CANYON_T *canyon )
{
  int i = 0;
  char *borrar = "         ";
  for(i=0; *(*canyon->image)[i] != '\0';i++ )
  {
    positionCursor(canyon->pos[0],canyon->pos[1]+i);
    printf("%s",borrar);
  }
} /* drawAlien */