#ifndef MENU_H_
#define MENU_H_
#include <iostream>
#include <stdlib.h>
#include "tablero.h"
class Menu
{
private:
	int opcion;
	tablero *miTablero;

public:
	void menuPrincipal();
	Menu();
	~Menu();
};
#endif
 
