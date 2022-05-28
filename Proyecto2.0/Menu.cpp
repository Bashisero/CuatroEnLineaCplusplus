#include "Menu.h"

Menu::Menu(){
	this->miTablero = new tablero();
}

void Menu::menuPrincipal() {
	
	bool salir = false;
	
	do {		
		system("cls");
		
		std::cout << "\t\tBienvenido al juego CUATRO EN LINEA \n\n";
		std::cout << "Elige el tipo de juego que deseas \n";
		std::cout << "1. Cuatro en linea tradicional \n";
		std::cout << "2. Pop 10 \n";
		std::cout << "3. Pop 20 \n";
		std::cout << "4. Salir \n\n";  
		
		std::cout << "Digite su opcion: ";
		std::cin  >> this->opcion;
		
		switch(this->opcion) {
			case 1: {
				int opc;
				system("cls");
				std::cout << "Elige el tipo de juego que deseas \n";
				std::cout << "1. Jugador VS Jugador \n";
				std::cout << "2. Jugador VS Maquina \n";
				std::cout << "3. Cargar partida guardada \n";
				std::cout << "Digite su opcion: ";
				std::cin >>opc;
				if(opc == 1)
				{
				this->miTablero->incializacionMatriz();
				this->miTablero->dibujarTablero("tradicional");
				std::cout << "\n\n";				
				system("pause");
				}
				else if (opc== 2)
				{
				this->miTablero->incializacionMatriz();
				this->miTablero->dibujarTablero("maquina");
				std::cout << "\n\n";				
				system("pause");
				}
				else if (opc == 3)
				{
				this->miTablero->cargarPartida();
				this->miTablero->dibujarTablero("guardada");
				std::cout << "\n\n";
				system("pause");

				}
				break;
			}
			
			case 2: {
				break;
			}
			
			case 3: {
				
				break;
			}
			
			case 4: { // salir
				std::cout << "\nGracias por haber jugado \n\n";				
				salir = true;
				exit(0);
				break;
			}
			
			default: { // Opcion Incorrecta
				std::cout << "\nOpcion incorrecta, Intenta de nuevo \n";
				system("pause");
				break;
			}			
		}
		
	}while(!salir);
	
}

// Destructor
Menu::~Menu() {
}

