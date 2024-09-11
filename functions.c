#include <stdio.h>
#include <windows.h>

#include "functions.h"

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