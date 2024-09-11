/* Ruler 1         2         3         4         5         6         7        */

#ifndef	WALL_H
#define WALL_H

/********************************** Headers ***********************************/

/* ------------------------ Inclusion of Std Headers ------------------------ */

#include <stdint.h>
#include <stdbool.h> // Due to type of variable "bool"



/******************** Declaration of Class with Attributes ********************/

typedef struct WALL_T WALL_T;
struct WALL_T {
	int            pos[2];      /*      Private position (x,y)       */
  int       pos_fire[2];      /*      Private pos of fire (x,y)    */
	char           *color;      /*      Private color                */
  char            *name;      /*      Private name                 */
	char      *(*image)[];      /*      Private aspect               */
	int           size[2];      /*      Private size (width, height) */
  bool             life;      /*      Private life                 */
  int             score;
  double         period;
};

/************************ Prototypes of Public Methods ************************/

/* ------------------------ Constructor & Destructor ------------------------ */

WALL_T * NewWall();
int       FreeWall( WALL_T * );

/* ------------------------ Setting Alien Attributes ------------------------ */

WALL_T * setWallImage( WALL_T *, char *(*)[] );
WALL_T *    setWallColor( WALL_T *, char *);
WALL_T * setWallPosition( WALL_T *, int, int );

/* ------------------------ Performing Alien Actions ------------------------ */

void drawWall( WALL_T * );

#endif /* ALIEN_H */
