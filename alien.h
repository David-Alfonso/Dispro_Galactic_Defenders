/* Ruler 1         2         3         4         5         6         7        */

#ifndef	ALIEN_H
#define ALIEN_H

/********************************** Headers ***********************************/

/* ------------------------ Inclusion of Std Headers ------------------------ */

#include <stdint.h>
#include <stdbool.h> // Due to type of variable "bool"



/******************** Declaration of Class with Attributes ********************/

typedef struct ALIEN_T ALIEN_T;
struct ALIEN_T {
	int               pos[2];      /*      Private position (x,y)       */
  int          pos_fire[2];      /*      Private pos of fire (x,y)    */
	char              *color;      /*      Private color                */
  char               *name;      /*      Private name                 */
	char         *(*image)[];      /*      Private aspect               */
	bool imageArduino[8][12];      /*      Private aspect               */
	int              size[2];      /*      Private size (width, height) */
  bool                life;      /*      Private life                 */
  int                score;
  double            period;
};

/************************ Prototypes of Public Methods ************************/

/* ------------------------ Constructor & Destructor ------------------------ */

ALIEN_T * New_Alien();
int       Free_Alien( ALIEN_T * );

/* ------------------------ Setting Alien Attributes ------------------------ */

ALIEN_T *           setAlienImage( ALIEN_T *, char *(*)[] );
ALIEN_T *           setAlienColor( ALIEN_T *, char *);
ALIEN_T *        setAlienPosition( ALIEN_T *, int, int );

ALIEN_T *    setAlienImageArduino( ALIEN_T *, bool [8][12]);
ALIEN_T *    setAlienColorArduino( ALIEN_T *, char *);
ALIEN_T * setAlienPositionArduino( ALIEN_T *, int, int );

/* ------------------------ Performing Alien Actions ------------------------ */

void         drawAlien( ALIEN_T * );
void        eraseAlien( ALIEN_T * );

void  drawAlienArduino( ALIEN_T * );
void eraseAlienArduino( ALIEN_T * );

#endif /* ALIEN_H */