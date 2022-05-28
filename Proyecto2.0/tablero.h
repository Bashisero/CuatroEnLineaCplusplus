#ifndef TABLERO_H_
#define TABLERO_H_
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>


class tablero  
	{
		
	public: 
		char matriz[6][7];
		std::vector <std::string> lineas;
		std::vector <std::vector<char*> > miMatriz;
		int columna;
		int fila;	
		bool turno;	
		tablero();
		void incializacionMatriz();
		~tablero();
		bool jugadorRendirse();
		void dibujarTablero(std::string tipoJuego);	
		void juegoTradicional();		
		bool ganadorTradicional();
		void maquina();
		void guardarPartida();
		bool ganadorMaquina();
		bool tableroLleno();
		bool ColumnaLlena();
		void cargarPartida();
		bool tablas();
};
#endif

