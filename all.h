#include <stdint.h>
#include <stdbool.h> // Due to type of variable "bool"
#include <stdint.h>


void positionCursor(int x, int y);
void die(char *(*)[], int);

#ifndef	ALIEN_H
#define ALIEN_H

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
ALIEN_T *           setAlienScore(ALIEN_T *, int);
ALIEN_T *            setAlienLife( ALIEN_T *, bool );

ALIEN_T *    setAlienImageArduino( ALIEN_T *, bool [8][12]);
ALIEN_T *    setAlienColorArduino( ALIEN_T *, char *);
ALIEN_T * setAlienPositionArduino( ALIEN_T *, int, int );

/* ------------------------ Performing Alien Actions ------------------------ */

void         drawAlien( ALIEN_T * );
void        eraseAlien( ALIEN_T * );

void  drawAlienArduino( ALIEN_T * );
void eraseAlienArduino( ALIEN_T * );

void killAlien( ALIEN_T * );

#endif /* ALIEN_H */

#ifndef	CANYON_H
#define CANYON_H

typedef struct CANYON_T CANYON_T;

/************************ Prototypes of Public Methods ************************/

/* Attributes to show how the alien looks like: */
struct CANYON_T {
	uint8_t        pos[2];      /*      Public position (x,y)    */
  uint8_t   pos_fire[2];      /*      Public pos of fire (x,y) */
	char           *color;      /*      Public color             */
	char      *(*image)[];      /*      Public aspect            */
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
CANYON_T *     setCanyonLife( CANYON_T *, bool);
CANYON_T *    setCanyonScore(CANYON_T *, int);

/* ------------------------ Performing Alien Actions ------------------------ */

void  drawCanyon( CANYON_T * );
void eraseCanyon( CANYON_T * );
void  killCanyon( CANYON_T * );

#endif /* CANYON_H */


void positionCursor(int x, int y);
void die(char *(*)[], int);



#ifndef	WALL_H
#define WALL_H

typedef struct WALL_T WALL_T;
struct WALL_T {
  int            pos[2];      /*      Private position (x,y)       */
  int       pos_fire[2];      /*      Private pos of fire (x,y)    */
  char           *color;      /*      Private color                */
  char            *name;      /*      Private name                 */
  char      *(*image)[];      /*      Private aspect               */
  int           size[2];      /*      Private size (width, height) */
  int              life;      /*      Private life                 */
  int             score;
  double         period;
};

/************************ Prototypes of Public Methods ************************/

/* ------------------------ Constructor & Destructor ------------------------ */

WALL_T * NewWall();
int       FreeWall( WALL_T * );

/* ------------------------ Setting Alien Attributes ------------------------ */

WALL_T *    setWallImage( WALL_T *, char *(*)[] );
WALL_T *    setWallColor( WALL_T *, char *);
WALL_T * setWallPosition( WALL_T *, int, int );
WALL_T *     setWallLife( WALL_T *, int);

/* ------------------------ Performing Alien Actions ------------------------ */

void drawWall( WALL_T * );
void eraseWall( WALL_T * );

#endif /* WALL_H */


#ifndef	BULLET_H
#define BULLET_H

/******************** Declaration of Class with Attributes ********************/

typedef struct BULLET_T BULLET_T;
struct BULLET_T {
	uint8_t        pos[2];      /*      Public position (x,y)    */
	char           *color;      /*      Public color             */
	char     *(*aspect)[];      /*      Public aspect            */
	uint8_t width, height;      /*      Private size             */
  bool             life;      /*      Public life              */
  double         period;
};
/************************ Prototypes of Public Methods ************************/

/* ------------------------ Constructor & Destructor ------------------------ */

BULLET_T * New_Bullet();
int       Free_Bullet( BULLET_T * );

/* ------------------------ Setting Bullet Attributes ------------------------ */

BULLET_T *   setBulletAspect( BULLET_T *, char *(*)[] );
BULLET_T *    setBulletColor( BULLET_T *, int );
BULLET_T *      setBulletPos( BULLET_T *, int, int );
BULLET_T *     setBulletLife( BULLET_T * , bool );
BULLET_T *        killBullet( BULLET_T *);

/* ------------------------ Performing Bullet Actions ------------------------ */

void  drawBullet( BULLET_T * );
void eraseBullet( BULLET_T * );


#endif /* BULLET_H */


/* 4 x 11 */
static char *crab2[] = {
". #.   .# .",
"#.#*###*#.#",
"*#########*",
" .*     *. ",
""
};

/* 4 x 11 */
static char *crab[] = {
"  *.   .*  ",
" .#*###*#. ",
"#*#######*#",
"* *.. ..* *",
""
};

/* 4 x 8 */
static char *squid2[] = {
"    .##.  ",
"  .#*##*#.",
"  **#**#**",
"  .*.**.*.",
""
};

/* 4 x 8 */
static char *squid[] = {
"    .##.  ",
"  .#*##*#.",
"  *#*##*#*",
"  *.    .*",
""
};

/* 4 x 12 */
static char *octo2[] = {
" ...####... ",
"###**##**###",
"***##**##***",
"..** ** **..",
""
};

/* 4 x 12 */
static char *octo[] = {
" ...####... ",
"###**##**###",
"**###**###**",
" *#. ** .#* ",
""
};

/* 7 x 22 */
static char *tanq[] = {
"   .   ",
"#######",
""
};

/* 5 x 22 */
static char *wall0[] = {
" .########.",
"############",
"####*  *####",
"###      ###",
""
};

/* 5 x 22 */
static char *wall1[] = {
"  . ### #   ",
".##.#####  .",
"####*  *####",
"###      ###",
""
};

/* 5 x 22 */
static char *wall2[] = {
"     #.     ",
" .#.#**##   ",
" ##*    *#.#",
"###      ###",
""
};
 /* 7 x 28 */
static char *ovni[] = {
"      █████████████",       // 1
"   ███████████████████",    // 2
"  ███  ███  █  ███  ███",   // 3
"█████████████████████████", // 4
"   ████     █     ████",    // 5
"     █             █",      // 6
""
};

/* 8 x 22 */
static char *pop[] = {
"  ▄    ▄    ▄ ", // 1
"    ■  ▄  ■   ", // 2
"    ■  ▀  ■   ", // 3
"  ▄    ▄    ▄  ", // 4
""
};

static char *bullet[] = {
".",
"#",
"#",
"*",
""
};

static char *name[] = {
"       #####  #####   ###   #####  ######         ",
"      ##      #    # #   # #       #              ",
"       ####   #####  ##### #       ###            ",
"           ## #      #   # #       #              ",  
"       #####  #      #   #  #####  ######         ",
"                                                  ",
"# ##    # #     #  ###  ####  ##### #####   ##### ",
"# # #   # #     # #   # #   # #     #    # ##     ",
"# #  #  #  #   #  ##### #   # ###   #####   ####  ",
"# #   # #   # #   #   # #   # #     #    #      ##",
"# #    ##    #    #   # ####  ##### #     # ##### ",
""
};

static char *gameOver[] = {
"       #####    ###  ##   ##  ######         ",
"      ##       #   # # # # #  #              ",
"      ## ###   ##### #  #  #  ###            ",
"      ##   ##  #   # #     #  #              ",  
"       #####   #   # #     #  ######         ",
"                                             ",
"       ######   #     #  ##### #####         ",
"      #      #  #     #  #     #    #        ",
"      #      #   #   #   ###   #####         ",
"      #      #    # #    #     #    #        ",
"       ######      #     ##### #     #       ",
"                                             ",
""
};

static char *Win[] = {
"    ##             ##   ##  ####    ##  ##   ",
"     ##           ##    ##  ## ##   ##  ##   ",
"      ##   ###   ##     ##  ##  ##  ##  ##   ",
"       ##  # #  ##      ##  ##   ## ##       ",  
"        #### ####       ##  ##    ####  ##   ",
"                                             ",
""
};