#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

#include "all.h"

#define numLines 3
#define numColumns 7
#define numWalls 5
#define numBulletsUser 1000
#define numBulletsAliens 1000

void movingXderAliens(ALIEN_T arr[numLines][numColumns]);
void movingXizqAliens(ALIEN_T arr[numLines][numColumns]);
void movingYAliens(ALIEN_T arr[numLines][numColumns]);
void movingAliens(ALIEN_T arr[numLines][numColumns]);

void movingXderAliensArduino(ALIEN_T arr[numLines][numColumns]);
void movingXizqAliensArduino(ALIEN_T arr[numLines][numColumns]);
void movingYAliensArduino(ALIEN_T arr[numLines][numColumns]);

void movingUpBullet(BULLET_T *b,CANYON_T  *c ,ALIEN_T arr[numLines][numColumns],WALL_T ws[numWalls]);
void movingDownBullet(BULLET_T *b,CANYON_T *c, WALL_T ws[numWalls]);

void movingCanyonHor(CANYON_T *c, int x);

typedef enum {
  EVALUATING, 
  ACTING_USER, 
  MOVING_ALIENS, 
  MOVING_BULLETS_ALIENS, 
  MOVING_BULLETS_USER, 
  SHOOTING_ALIENS,
  SHOOTING_USER
} GAME_STATE_T;

typedef enum
{
  LEFT,
  RIGHT,
  DOWN
} MOVING_ALIENS_STATE_T;


typedef enum {
    BEGINNING_0,
    PLAYING_1,
    ENDING_2
} ALL_STATE_T;

ALIEN_T aliens[numLines][numColumns];
WALL_T walls[numWalls];
BULLET_T bulletsUser[numBulletsUser];
BULLET_T bulletsAliens[numBulletsAliens];
CANYON_T user;

int main(void) {
  system("cls");
  
  ALL_STATE_T complete = BEGINNING_0;

  /************************** Declarations of New Types *************************/

  /******************************    Set Aliens    ******************************/

  // probably for generic lines do a %= in the inside if conditions
  // that should intercalate the aliens

  for(int i = 0; i < numLines; i++)
  {
    for(int j = 0; j < numColumns; j++)
    {
      if(i == 0)
      {
        setAlienImage(&aliens[i][j],&crab2);
        setAlienScore(&aliens[i][j],30);
      }if(i == 1)
      {
        setAlienImage(&aliens[i][j],&octo2);
        setAlienScore(&aliens[i][j],20);
      }
      if(i == 2)
      {
        setAlienImage(&aliens[i][j],&squid2);
        setAlienScore(&aliens[i][j],10);
      }
      setAlienPosition(&aliens[i][j],j*14,(i*5)+16);
      setAlienLife(&aliens[i][j], true);
    }
  }
  for(int i = 0; i < numLines; i++)
  {
    for(int j = 0; j < numColumns; j++)
    {
      drawAlien(&aliens[i][j]);
    }
  }

  /*******************************    Set Bullet    ******************************/
    


  for(int i=0;i<numBulletsUser;i++){
    setBulletAspect( &bulletsUser[i], &bullet );
    setBulletLife( &bulletsUser[i], false );
  }
  
  for(int i=0;i<numBulletsAliens;i++){
    setBulletAspect( &bulletsAliens[i], &bullet );
    setBulletLife( &bulletsAliens[i], false );
  }

  /*******************************    Set Walls    ******************************/

  for(int i = 0; i < numWalls; i++)
  {
    setWallImage(&walls[i],&wall0);
    setWallPosition(&walls[i],i*24+30,55);
  }
  
  for(int i = 0; i < numWalls; i++)
  {
    setWallLife(&walls[i],2);
  }
  
  /******************************    Set Canyons    *****************************/

    setCanyonImage(&user,&tanq);
    
    setCanyonPosition(&user,30,62);

    setCanyonLife(&user,true);
  
    drawCanyon(&user);


  /****************************    Moving Aliens    *****************************/

  double time_aliens = 1;
  double time_move_bullets = 0.6;
  double time_chose_bullets, aux_time_aliens, aux_time_shoot_aliens;
  double aux_time_bullets_aliens[numBulletsAliens] = {};
  double aux_time_bullets_user[numBulletsUser] = {};
  double aux_time_shoot_user;
  int aux_move_aliens = 0;
  char key;
  int lin=(numLines-1);
  int N=(numColumns-1);
  // YOU HAVE TO INITIATE THE SEED FOR THE RANDOM VALUE, IT'S NOT DONE
  int columnRandom;
  int aux_bullets_aliens = 0;
  int aux_bullets_user = 0;
  int aux = 0;
  int aux_move_bullets_aliens, aux_move_bullets_user;
  char OpBegin;
  int play = 1;
  int win = 0;

  GAME_STATE_T game = EVALUATING;
  
  aux_time_aliens =  (clock() * 1.0 / CLOCKS_PER_SEC);
  aux_time_shoot_aliens = aux_time_aliens;
  aux_time_shoot_user = aux_time_aliens;

  while(play == 1){
  	switch( complete )
  	{
  	case BEGINNING_0:
  		for(int i=0; name[i] != '\0';i++ )
       {
         positionCursor(35,33+i);
         printf("%s",name[i]);
       }
  		printf("\nCreate by:\n");
        printf("David Santiago Alfonso Monta�ez\n");
        printf("Jose Miguel Torres Aparicio\n");
        printf("Marco Antonio Mu�oz Ramirez\n");
        printf("Paula Elizabeth Riveros Cort�s\n");
        printf("Mariana Osorio V�squez\n");
        printf("Presione 'S' y enter para iniciar el juego");
        scanf("%s", &OpBegin);
        if(OpBegin==115||OpBegin==83){
              complete = PLAYING_1;
        }
        
  		for(int i=0; name[i] != '\0';i++ )
       {
         positionCursor(35,33+i);
         printf("                                                  ");
       }
        printf("\n                                                    \n");
  	  	printf("                                                       \n");
        printf("                                                      \n");
        printf("                                                      \n");
        printf("                                                      \n");
        printf("                                                      \n");
        printf("                                                      \n");
      break; 
    case PLAYING_1:
    while(user.life == true && aux_move_aliens < 145)
    {
    switch( game )
    {
      case EVALUATING:
        if((((clock() * 1.0)/CLOCKS_PER_SEC) - aux_time_aliens) >= time_aliens)
        {
          game = MOVING_ALIENS;
        }
        else if(kbhit())
        {
          game = ACTING_USER;
        }
        else if((((clock() * 1.0)/CLOCKS_PER_SEC) - aux_time_shoot_aliens) >= 3*time_aliens)
        {
          game = SHOOTING_ALIENS;
        }
        else if(aux_bullets_aliens > 0 || aux >= 1)
        {
          // THE TIME SHOULD BE GIVEN INSIDE OF THE BULLET_T ARRAY, AND THAT IS WHAT SHOULD BE ITERATED AND ASKED
          if(aux_bullets_aliens > 0) for(int i = 0; (((clock() * 1.0)/((double)(CLOCKS_PER_SEC))) - aux_time_bullets_aliens[i]) >= time_move_bullets && i < aux_bullets_aliens;i++)
          {
            if((((clock() * 1.0)/CLOCKS_PER_SEC) - aux_time_bullets_aliens[i]) >= time_move_bullets)
            {
              aux_move_bullets_aliens = i;
              game = MOVING_BULLETS_ALIENS;
            }
          }
          // THE EVALUATION OF THE AUX IS THE SAME AS EVALUATING THAT THE BULLET IS ALIVE
          // WATCHOUT FOR WHEN THE FIRST BULLET IS DEAD AND THE OTHERS ARE NOT
          // WHEN A BULLET DIES YOU HAVE TO REORDER THE ARRAY
          if(aux >= 1)
          {
            for(int i = 0; (((clock() * 1.0)/((double)(CLOCKS_PER_SEC))) - aux_time_bullets_user[i]) >= time_move_bullets && i < aux;i++)
            {
              if((((clock() * 1.0)/CLOCKS_PER_SEC) - aux_time_bullets_user[i]) >= time_move_bullets)
              {
                aux_move_bullets_user = i;
                game = MOVING_BULLETS_USER;
              }
            }
          }
        }
        else
        {
        	game = EVALUATING;
		    }
        break;

      case ACTING_USER:
        //El 161 y el 1 dependen de hasta donde se quiere que pueda ir el user
        // THE ERASE USER AND DRAW USER SHOULD BE INSIDE OF ALL THE CASES FOR FASTER PERFORMANCE
        eraseCanyon(&user);
        key = getch();
        if(key == 'a') 
        {
          if(user.pos[0] > 1) 
          {
            movingCanyonHor(&user, -1); 
            game = EVALUATING;
          }
        }
        if(key == 'd') 
        {
          if(user.pos[0] < 161) 
          {
            movingCanyonHor(&user,  1); 
            game = EVALUATING;
          }
        }
        if(key == 'w')
        {
          if((((clock() * 1.0)/CLOCKS_PER_SEC) - aux_time_shoot_user) >= 3*time_aliens)
          {
            aux_time_shoot_user =  (clock() * 1.0 / CLOCKS_PER_SEC);
            game = SHOOTING_USER;
          }
        }
        drawCanyon(&user);
        break;

      case MOVING_ALIENS:
        aux_move_aliens++;
        aux_time_aliens =  (double)(clock() * 1.0 / CLOCKS_PER_SEC);
        movingAliens(aliens);
        game = EVALUATING;
        break;

      case SHOOTING_ALIENS:
      	aux_time_shoot_aliens = clock() * 1.0 / CLOCKS_PER_SEC;
        aux_time_bullets_aliens[aux_bullets_aliens] =  (double)(clock() * 1.0 / CLOCKS_PER_SEC);
        columnRandom = rand() % (N+1);
        // THE ROW WHERE IT'S SHOT IT'S NOT RANDOM
        do
        {
          if(aliens[lin][columnRandom].life==true)
          {
          	setBulletPos(&bulletsAliens[aux_bullets_aliens],aliens[lin][columnRandom].pos_fire[0],aliens[lin][columnRandom].pos_fire[1]);
          }
          else
          {
            lin--;
          }
          if(lin<0)
          {
            lin=(numLines-1);
            columnRandom = rand() % (N+1);
          }
        }while(aliens[lin][columnRandom].life!=true);
        lin=(numLines-1);
        // THESE SHOULD BE INSIDE THE DO WHILE, WHERE THE POSITION IS GIVEN
        setBulletLife(&bulletsAliens[aux_bullets_aliens],true);
        drawBullet(&bulletsAliens[aux_bullets_aliens]);
        aux_bullets_aliens++;
        game = EVALUATING;
        break;
        
      case MOVING_BULLETS_ALIENS:
		    aux_time_bullets_aliens[aux_move_bullets_aliens] =  (double)(clock() * 1.0 / CLOCKS_PER_SEC);
        movingDownBullet(&bulletsAliens[aux_move_bullets_aliens],&user, walls);
        game = EVALUATING;
        break;

      case SHOOTING_USER:
      	if(aux >= (numBulletsUser - 1))
      	{
      	  aux = 0;
		    }
      	aux_time_bullets_user[aux] = (clock() * 1.0 / CLOCKS_PER_SEC);
		    setBulletLife(&bulletsUser[aux],true);
        setBulletPos(&bulletsUser[aux],user.pos_fire[0],user.pos_fire[1]);
        drawBullet(&bulletsUser[aux]);
      	++aux;
      	game = EVALUATING;
		    break;

      case MOVING_BULLETS_USER:
      	aux_time_bullets_user[aux_move_bullets_user] =  (clock() * 1.0 / CLOCKS_PER_SEC);
        movingUpBullet(&bulletsUser[aux_move_bullets_user],&user,aliens,walls);
        game = EVALUATING;
        break;
    }

    // THIS COULD BE DONE WHEN THE ALIEN IS DEAD IN THE FUNCTION MOVING ALIEN
    // IF THAT'S DONE, WE HAVE TO ADD WIN TO THE WHILE'S CONDITION
    for(int i = 0; i < numLines; i++)
    {
      for(int j = 0; j < numColumns; j++)
      {
      	if(aliens[i][j].life == false) win++;
      }
    }
    if(win == 21) 
    {
    	aux_move_aliens = 146;
	  }
    else if(win <= 21) // IT SHOULD BE JUST LESS THAN, NOT LESS OR EQUAL THAN
    {
      win = 0;
    }
  }

  complete = ENDING_2;
  break;

  case ENDING_2:
  	system("cls");
  	win = 0;
    // DO SEPARATE CASES FOR WINNING OR LOSING (ADVISED BY MAJO)
  	if(win == 21)
    {
      for(int i=0; Win[i] != '\0';i++ )
        {
          positionCursor(20,10+i);
          printf("%s",Win[i]);
        }	
    }
    else
    {
        for(int i=0; gameOver[i] != '\0';i++ )
        {
          positionCursor(20,10+i);
          printf("%s",gameOver[i]);
        }
    }
  	play = 0;
  	break;
    }
  }
  return 0;
}

void movingCanyonHor(CANYON_T *c, int x)
{
  // IT SHOULD BE JUST + NOT += AND IT SHOULD BE A GET
  setCanyonPosition(c,c->pos[0]+=x,c->pos[1]);
}

void movingUpBullet(BULLET_T *b, CANYON_T *c, ALIEN_T arr[numLines][numColumns], WALL_T ws[numWalls] ){
  typedef enum {MOVIENDO} MOVING_BULLET_STATE_T;
  static MOVING_BULLET_STATE_T state = MOVIENDO;
  switch( state )
  {
    case MOVIENDO:
      if(b->life == true)
      {
        eraseBullet(b);
        if(b->pos[1]<=20){ killBullet(b);}
        if(b->life == true)
        {
          --b->pos[1];
          drawBullet(b);	
        }
      }
      for(int i=0;i<numLines;i++){
        for(int j=0;j<numColumns;j++){
          if(arr[i][j].life==true &&
          b->pos[0]>=arr[i][j].pos[0] &&
          b->pos[0]<=arr[i][j].pos[0]+11 &&
          b->pos[1]==arr[i][j].pos_fire[1] && // THE ALIEN CAN'T COMMIT SUICIDE
		  b->life == true)
          {
            // SAME CORRECTION AS IN MOVING CANYON HORIZONTAL
            setCanyonScore(c,c->score += aliens[i][j].score);
            positionCursor(180,62);
            printf("SCORE: %d",c->score);
            killAlien(&aliens[i][j]);
            eraseBullet(b);
            killBullet(b);
          }
        }
      }
      for(int i=0;i<numWalls;i++){
          if(ws[i].life>=-1 &&
          b->pos[0]>=ws[i].pos[0] &&
          b->pos[0]<=ws[i].pos[0]+11 &&
          b->pos[1]>=ws[i].pos[1] &&
          b->pos[1]<=ws[i].pos[1]+3 &&
		  b->life == true) 
          {
            setWallLife(&ws[i],ws[i].life-1);
            eraseBullet(b);
            killBullet(b);
          }
      }
  }
}

void movingDownBullet(BULLET_T *b,CANYON_T *c, WALL_T ws[numWalls] ){
  typedef enum {MOVIENDO} MOVING_BULLET_STATE_T;
  static MOVING_BULLET_STATE_T state = MOVIENDO;
  switch( state ){
    case MOVIENDO:
      if(b->life == true)
      {
        eraseBullet(b);
        if(b->pos[1]>=64){killBullet(b);}
        if(b->life == true)
        {
          setBulletPos(b,b->pos[0],++b->pos[1]);
          drawBullet(b);	
        }
      }
      for(int i=0;i<numWalls;i++){
          if(ws[i].life>=-1 &&
          b->pos[0]>=ws[i].pos[0] &&
          b->pos[0]<=ws[i].pos[0]+11 &&
          b->pos[1]>=ws[i].pos[1]-3 &&
          b->pos[1]<=ws[i].pos[1]  &&
		  b->life == true)
          {
            setWallLife(&ws[i],ws[i].life-1);
            eraseBullet(b);
            killBullet(b);
          }
      }
      if(c->life>=true &&
        b->pos[0]>=c->pos[0] &&
        b->pos[0]<=c->pos[0]+6 &&
        b->pos[1]>=c->pos[1]-3 &&
        b->pos[1]<=c->pos[1]) 
        {
          killCanyon(c);
          eraseBullet(b);
          killBullet(b);
        }
  }
}

void movingAliens(ALIEN_T arr[numLines][numColumns])
{
  int MaxHor = 24;
  int MaxVer = 24;
  static int aux = 0;
  static int prev = -1; // it has to start in a value less than aux' initial value
  static MOVING_ALIENS_STATE_T state = RIGHT;
  switch( state )
  {
    case RIGHT:
    if(aux<MaxHor && aux > prev)
    {
      movingXderAliens(arr);
      prev = aux;
      aux++;
      state = RIGHT;
    }
    if(aux==MaxHor)
    {
      prev = aux;
      aux--;
      state = DOWN;
    }
    break;

    case LEFT:
    movingXizqAliens(arr);
    if(aux>0 && aux < prev)
    {
      prev = aux;
      aux--;
      state = LEFT;
    }
    if(aux==0)
    {
      prev = aux;
      aux++;
      state = DOWN;
    }
    break;

    case DOWN:
    movingYAliens(arr);
    if(aux<MaxHor && aux > prev)
    {
      state = RIGHT;
    }

    if(aux>0 && aux < prev)
    {
      state = LEFT;
    }
    break;
  }
  
}

void movingXderAliens(ALIEN_T arr[numLines][numColumns])
{
  int moving = 3;
  
  for(int i = 0; i < numLines; i++)
  {
    for(int j = 0; j < numColumns; j++)
    {
      eraseAlien(&arr[i][j]);
    }
  }

  for(int i = 0; i < numLines; i++)
  {
    for(int j = 0; j < numColumns; j++)
    {
      setAlienPosition(&arr[i][j],arr[i][j].pos[0]+moving,arr[i][j].pos[1]);
    }
  }

  for(int i = 0; i < numLines; i++)
  {
    for(int j = 0; j < numColumns; j++)
    {
      drawAlien(&arr[i][j]);
    }
  }
}

void movingXizqAliens(ALIEN_T arr[numLines][numColumns])
{
  int moving = -3;
  
  for(int i = 0; i < numLines; i++)
  {
    for(int j = 0; j < numColumns; j++)
    {
      eraseAlien(&arr[i][j]);
    }
  }

  for(int i = 0; i < numLines; i++)
  {
    for(int j = 0; j < numColumns; j++)
    {
      setAlienPosition(&arr[i][j],arr[i][j].pos[0]+moving,arr[i][j].pos[1]);
    }
  }

  for(int i = 0; i < numLines; i++)
  {
    for(int j = 0; j < numColumns; j++)
    {
      drawAlien(&arr[i][j]);
    }
  }
}

void movingYAliens(ALIEN_T arr[numLines][numColumns])
{
  int moving = 5;
  
  for(int i = 0; i < numLines; i++)
  {
    for(int j = 0; j < numColumns; j++)
    {
      eraseAlien(&arr[i][j]);
    }
  }

  for(int i = 0; i < numLines; i++)
  {
    for(int j = 0; j < numColumns; j++)
    {
      setAlienPosition(&arr[i][j],arr[i][j].pos[0],arr[i][j].pos[1]+moving);
    }
  }

  for(int i = 0; i < numLines; i++)
  {
    for(int j = 0; j < numColumns; j++)
    {
      drawAlien(&arr[i][j]);
    }
  }
}

void movingXderAliensArduino(ALIEN_T arr[numLines][numColumns])
{
  int moving = 50;
  
  for(int i = 0; i < numLines; i++)
  {
    for(int j = 0; j < numColumns; j++)
    {
      eraseAlienArduino(&arr[i][j]);
    }
  }

  for(int i = 0; i < numLines; i++)
  {
    for(int j = 0; j < numColumns; j++)
    {
      setAlienPosition(&arr[i][j],arr[i][j].pos[0]+moving,arr[i][j].pos[1]);
    }
  }

  for(int i = 0; i < numLines; i++)
  {
    for(int j = 0; j < numColumns; j++)
    {
      drawAlienArduino(&arr[i][j]);
    }
  }
}

void movingXizqAliensArduino(ALIEN_T arr[numLines][numColumns])
{
  int moving = -50;
  
  for(int i = 0; i < numLines; i++)
  {
    for(int j = 0; j < numColumns; j++)
    {
      eraseAlienArduino(&arr[i][j]);
    }
  }

  for(int i = 0; i < numLines; i++)
  {
    for(int j = 0; j < numColumns; j++)
    {
      setAlienPosition(&arr[i][j],arr[i][j].pos[0]+moving,arr[i][j].pos[1]);
    }
  }

  for(int i = 0; i < numLines; i++)
  {
    for(int j = 0; j < numColumns; j++)
    {
      drawAlienArduino(&arr[i][j]);
    }
  }
}

void movingYAliensArduino(ALIEN_T arr[numLines][numColumns])
{
  int moving = 50;
  
  for(int i = 0; i < numLines; i++)
  {
    for(int j = 0; j < numColumns; j++)
    {
      eraseAlienArduino(&arr[i][j]);
    }
  }

  for(int i = 0; i < numLines; i++)
  {
    for(int j = 0; j < numColumns; j++)
    {
      setAlienPosition(&arr[i][j],arr[i][j].pos[0],arr[i][j].pos[1]+moving);
    }
  }

  for(int i = 0; i < numLines; i++)
  {
    for(int j = 0; j < numColumns; j++)
    {
      drawAlienArduino(&arr[i][j]);
    }
  }
}
