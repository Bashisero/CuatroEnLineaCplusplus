//#include "popout.h"
//
//int ganadasJ1pop=0;
//int ganadasJ2pop=0;
//bool gameOver = false;
//std::string tipoJuegoPop;
//
//void popout::incializacionMatrizPop()
//{
//	this->incializacionMatriz();
//}
//
//void popout::dibujarTableroPop(std::string tipoJuego)
//{
//	this->dibujarTablero(tipoJuegoPop);
//}
//
//void popout::juegoPop()
//{
//	int o;
//	std::cout << "Que desea hacer?"<< std::endl;
//	std::cout <<"1) Poner ficha"<<std::endl;
//	std::cout <<"2) Suspender partida"<<std::endl;
//	std::cout <<"3) Rendirse"<<std::endl;
//	std::cout <<"4) Retirar ficha"<<std::endl;
//	std::cin >> o;
//	if(o==1)
//	{
//		if(turno == false) {
//		turno = true;
//	}else {
//		turno = false;
//	}
//	
//	std::cout <<"Turno del jugador: "<< turno << "\nDigita la columna donde quieres jugar: ";
//	std::cin  >> this->columna;
//				
//		if(columna < 1 || columna > 7)
//		{
//			std::cout << "Jugada !!NO VALIDA!! \n";
//			system("pause");
//		}else {
//		
//				
//		
//			this->columna -= 1 ;
//				this->ColumnaLlena();
//			for(int i=6; i>=0; i--) {	
//				if(matriz[i][columna] == '*') {			
//					if(turno == false) {
//						matriz[i][columna] = '0';				
//						break;
//					}else{					
//					matriz[i][columna] = '1';												
//					break;
//					}
//				}									
//			}		
//		}
//	}
//	
//	if(o==2)
//	{
//		this->guardarPartida();
//		gameOver = true;
//	}
//	if(o==3)
//	{
//		this->jugadorRendirse();
//		gameOver = true;
//	}	
//	if(o==4)
//	{
//		if(turno == false) {
//		turno = true;
//		}else {
//			turno = false;
//	}
//	
//	std::cout <<"Turno del jugador: "<< turno << "\nDigita la columna donde quieres jugar: ";
//	std::cin  >> this->columna;
//	if(columna < 1 || columna > 7)
//		{
//			std::cout << "Jugada !!NO VALIDA!! \n";
//			system("pause");
//		}else {
//		
//		
//		}
//	}
//}
//

