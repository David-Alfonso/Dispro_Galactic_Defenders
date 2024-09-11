/* Ruler 1         2         3         4         5         6         7        */

/********************************** Headers ***********************************/

/* ------------------------ Inclusion of Std Headers ------------------------ */

#include <stdio.h>   // Due to printf()
#include <string.h>  // Due to strlen()
#include <stdbool.h> // Due to type of variable "bool"

/* ------------------------ Inclusion of Own Headers ------------------------ */

#include "wall.h"
#include "functions.h"


/************************** Declarations of New Types *************************/

/* Attributes to show how the alien looks like: */

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