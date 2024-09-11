/* Ruler 1         2         3         4         5         6         7        */

#ifndef	CANYON_H
#define CANYON_H

/********************************** Headers ***********************************/

/* ------------------------ Inclusion of Std Headers ------------------------ */

#include <stdint.h>



/******************** Declaration of Class with Attributes ********************/

typedef struct CANYON_T CANYON_T;

/************************ Prototypes of Public Methods ************************/

/* Attributes to show how the alien looks like: */
struct CANYON_T {
	uint8_t        pos[2];      /*      Public position (x,y)    */
  uint8_t   pos_fire[2];      /*      Public pos of fire (x,y) */
	char           *color;      /*      Public color             */
	char     *(*image)[];      /*      Public aspect            */
	int           size[2];      /*      Private size             */
  bool             life;      /*      Public life              */
  int             score;
};

/* ------------------------ Constructor & Destructor ------------------------ */

CANYON_T * newCanyon();
int       freeCanyon( CANYON_T * );

/* ------------------------ Setting Alien Attributes ------------------------ */

CANYON_T *    setCanyonImage( CANYON_T *, char *(*)[] );
CANYON_T *    setCanyonColor( CANYON_T *canyon, char *color);
CANYON_T * setCanyonPosition( CANYON_T *, int, int );

/* ------------------------ Performing Alien Actions ------------------------ */

void  drawCanyon( CANYON_T * );
void eraseCanyon( CANYON_T * );

#endif /* CANYON_H */
