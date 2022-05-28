#include "tablero.h"
int ganadasJ1=0;
int ganadasJ2=0;
bool gameOver=false;
std::string tipoJuego;

tablero::tablero(){	
	this->turno = false;
}

void tablero::incializacionMatriz() {	
	char caracter = '*';	
	for(int i=0; i<6; i++) {
		for(int j=0; j<7; j++) {			
			this->matriz[i][j] = '*';
		}
	}	
}


void tablero::dibujarTablero(std::string tipoJuego) {	
	
	
	do {		
		if(tipoJuego == "maquina")
		{
			system("cls");
		std::cout << "\n\n\n";
		std::cout << "\tJUGADOR #1 = '0'                  MAQUINA = '1'\n\n\n";
		std::cout << "Columnas: \n\n";
		std::cout << "\t1 \t2 \t3 \t4 \t5 \t6 \t7 \n\n";
		for(int i=0; i<6; i++) {
			for (int j=0; j<7; j++) {
				std::cout << "\t" << this->matriz[i][j];
			}
			std::cout << "\n";
			
			}
		} else
		{
			system("cls");
			std::cout << "\n\n\n";
			std::cout << "\tJUGADOR #1 = '0'                  JUGADOR #2 = '1'\n\n\n";
			std::cout << "Partidas Ganadas J1 = " << ganadasJ1 <<"\t\t\t Partidas Ganadas J2 = " << ganadasJ2<<"\n\n";
			std::cout << "Columnas: \n\n";
			std::cout << "\t1 \t2 \t3 \t4 \t5 \t6 \t7 \n\n";
				for(int i=0; i<6; i++) {
					for (int j=0; j<7; j++) {
						std::cout << "\t" << this->matriz[i][j];
					}
					std::cout << "\n";
				}			
		}
		
		
		
		if(tipoJuego== "tradicional")
		{
			gameOver = this->ganadorTradicional();			
		if(gameOver == false) {
			bool lleno = this->tableroLleno();
			if(lleno == false) {
				if(tipoJuego == "tradicional") {
					this->juegoTradicional();
			}
					
			}else {
				std::cout << "\n\nOH ! Se acabado el tablero y nadie ha ganado  \n\n";
				gameOver = true;
			}							
		}				
			
		}
		else
		{
			gameOver = this->ganadorMaquina();
			if(gameOver == false)
			{
				if(tipoJuego == "maquina")
				{
					this->maquina();
				}
				else {
				std::cout << "\n\nOH ! Se acabado el tablero y nadie ha ganado  \n\n";
				gameOver = true;
				}					
			}
		}
								
	}while(!gameOver);		
}

void tablero::juegoTradicional() {
	
	int o;
	std::cout << "Que desea hacer?"<< std::endl;
	std::cout <<"1) Poner ficha"<<std::endl;
	std::cout <<"2) Suspender partida"<<std::endl;
	std::cout <<"3) Rendirse"<<std::endl;
	std::cout <<"4) Proponer tablas"<<std::endl;
	std::cin >> o;
	if(o==1)
	{
		if(turno == false) {
		turno = true;
	}else {
		turno = false;
	}
	
	std::cout <<"Turno del jugador: "<< turno << "\nDigita la columna donde quieres jugar: ";
	std::cin  >> this->columna;
				
		if(columna < 1 || columna > 7)
		{
			std::cout << "Jugada !!NO VALIDA!! \n";
			system("pause");
		}else {
		
				
		
			this->columna -= 1 ;
				this->ColumnaLlena();
			for(int i=6; i>=0; i--) {	
				if(matriz[i][columna] == '*') {			
					if(turno == false) {
						matriz[i][columna] = '0';				
						break;
					}else{					
					matriz[i][columna] = '1';												
					break;
					}
				}									
			}		
		}
	}
	
	if(o==2)
	{
		this->guardarPartida();
		gameOver = true;
	}
	if(o==3)
	{
		this->jugadorRendirse();
		gameOver = true;
	}
	if(o==4)
	{	this->tablas();
		bool empate = this->tablas();
		
		if(empate==true)
		{
			gameOver = true;
		}
		if(empate==false)
		{
			this->juegoTradicional();
		}
	}
								
}

bool tablero::ganadorTradicional() {
	
	bool estado = false;
	
	//********//Verticales\\***********
	//vertical | jugador #1
	for(int i=6; i>=0; i--) {
		for(int j=6; j>=0; j--) {
			if(matriz[i][j] == '0') {
				if(matriz[i-1][j] == '0') {
					if(matriz[i-2][j] == '0') {
						if(matriz[i-3][j] == '0') {
							std::cout << "\n\n\tAcaba de ganar el Jugador #1 (0)\n\n";
							std::cout << "Felicitaciones !!!!!";
							std::cout << "\n\n";
							estado = true;
							ganadasJ1 +=1;
						}
					}	
				}
			}
		}
	}
	//vertical | jugador #2
	for(int i=6; i>=0; i--) {
		for(int j=6; j>=0; j--) {
			if(matriz[i][j] == '1') {
				if(matriz[i-1][j] == '1') {
					if(matriz[i-2][j] == '1') {
						if(matriz[i-3][j] == '1') {
							std::cout << "\n\n\tAcaba de ganar el Jugador #2 (1)\n\n";
							std::cout << "Felicitaciones !!!!!";
							std::cout << "\n\n";
							estado = true;
							ganadasJ2 +=1;
						}
					}	
				}
			}
		}
	}
	//********//Horizontales\\***********
    //horizontal --- jugador #1
    for(int i=6; i>=0; i--) {
		for(int j=6; j>=0; j--) {
			if(matriz[i][j] == '0') {
				if(matriz[i][j-1] == '0') {
					if(matriz[i][j-2] == '0') {
						if(matriz[i][j-3] == '0') {
							std::cout << "\n\n\tAcaba de ganar el Jugador #1 (0)\n\n";
							std::cout << "Felicitaciones !!!!!";
							std::cout << "\n\n";
							estado = true;
							ganadasJ1 +=1;
						}
					}	
				}
			}
		}
	}
	
	//horizontal --- jugador 2
	
	for(int i=6; i>=0; i--) {
		for(int j=6; j>=0; j--) {
			if(matriz[i][j] == '1') {
				if(matriz[i][j-1] == '1') {
					if(matriz[i][j-2] == '1') {
						if(matriz[i][j-3] == '1') {
							std::cout << "\n\n\tAcaba de ganar el Jugador #2 (1)\n\n";
							std::cout << "Felicitaciones !!!!!";
							std::cout << "\n\n";
							estado = true;
							ganadasJ2 +=1;
						}
					}	
				}
			}
		}
	}
	//********//Diagonales normales\\**********
	//diagonal /  jugador #1
	
	for(int i=6; i>=0; i--) {
		for(int j=6; j>=0; j--) {
			if(matriz[i][j] == '0') {
				if(matriz[i-1][j+1] == '0') {
					if(matriz[i-2][j+2] == '0') {
						if(matriz[i-3][j+3] == '0') {
						
							std::cout << "\n\n\tAcaba de ganar el Jugador #1 (0)\n\n";
							std::cout << "Felicitaciones !!!!!";
							std::cout << "\n\n";
							estado = true;
							ganadasJ1 +=1;
							
						}
					}	
				}
			}
		}
	}
 //Diagonal \ jugador #2
 
 for(int i=6; i>=0; i--) {
		for(int j=6; j>=0; j--) {
			if(matriz[i][j] == '1') {
				if(matriz[i-1][j+1] == '1') {
					if(matriz[i-2][j+2] == '1') {
						if(matriz[i-3][j+3] == '1') {
							std::cout << "\n\n\tAcaba de ganar el Jugador #2 (1)\n\n";
							std::cout << "Felicitaciones !!!!!";
							std::cout << "\n\n";
							estado = true;
							ganadasJ2 +=1;
						}
					}	
				}
			}
		}
	}
	
	//********// Diagonles contrarias\\**********
	
	//diagonal /  jugador #1
	
	for(int i=6; i>=0; i--) {
		for(int j=6; j>=0; j--) {
			if(matriz[i][j] == '0') {
				if(matriz[i+1][j+1] == '0') {
					if(matriz[i+2][j+2] == '0') {
						if(matriz[i+3][j+3] == '0') {
						
							std::cout << "\n\n\tAcaba de ganar el Jugador #1 (0)\n\n";
							std::cout << "Felicitaciones !!!!!";
							std::cout << "\n\n";
							estado = true;
							ganadasJ1 +=1;
							
						}
					}	
				}
			}
		}
	}
 //Diagonal / jugador #2
 
 for(int i=6; i>=0; i--) {
		for(int j=6; j>=0; j--) {
			if(matriz[i][j] == '1') {
				if(matriz[i+1][j+1] == '1') {
					if(matriz[i+2][j+2] == '1') {
						if(matriz[i+3][j+3] == '1') {
							std::cout << "\n\n\tAcaba de ganar el Jugador #2 (1)\n\n";
							std::cout << "Felicitaciones !!!!!";
							std::cout << "\n\n";
							estado = true;
							ganadasJ2 +=1;
						}
					}	
				}
			}
		}
	} 
	return estado;
}

bool tablero::jugadorRendirse()
{
	
	if(turno == false)
	{
		std::cout<<"gana jugador #2"<<std::endl;
		
		ganadasJ2 +=1;
		
	}else{
		std::cout<<"gana jugador #1"<<std::endl;
		
		ganadasJ1 +=1;
	}
}

bool tablero::tableroLleno() {
	
	bool estado = false;
	
	for(int j=0; j<7; j++) {
		if((matriz[0][j] == '1') || (matriz[0][j] == '0')) {
			estado = true;
			
		}else {
			estado = false;
			break;
		}
	}
	
	return estado;
}

bool tablero::ColumnaLlena(){
	
	bool estado = true;
	
	int contador = 1;
	if((matriz[0][columna] == '0') || (matriz[0][columna] == '1')) {
		contador = 7;
	}
	if((contador == 7)) {
		if(turno == 1) {
			turno = 1;
		}else {
			turno = 0;
		}
		std::cout<<"No hay espacio para colocar la ficha"<<std::endl;
        system("pause");
        if(turno == false) {
		turno = true;
	}else {
		turno = false;
	}
        estado = false;   
	}
	
	//	std::cout << "estado : " << estado << std::endl;	
	return estado;
}

bool tablero::ganadorMaquina()
{
	bool estado = false;
	
	//********//Verticales\\***********
	//vertical | jugador #1
	for(int i=6; i>=0; i--) {
		for(int j=6; j>=0; j--) {
			if(matriz[i][j] == '0') {
				if(matriz[i-1][j] == '0') {
					if(matriz[i-2][j] == '0') {
						if(matriz[i-3][j] == '0') {
							std::cout << "\n\n\tAcaba de ganar el Jugador #1 (0)\n\n";
							std::cout << "Felicitaciones !!!!!";
							std::cout << "\n\n";
							estado = true;
						}
					}	
				}
			}
		}
	}
	//vertical | jugador #2
	for(int i=6; i>=0; i--) {
		for(int j=6; j>=0; j--) {
			if(matriz[i][j] == '1') {
				if(matriz[i-1][j] == '1') {
					if(matriz[i-2][j] == '1') {
						if(matriz[i-3][j] == '1') {
							std::cout << "\n\n\tAcaba de ganar la maquina (1)\n\n";
							std::cout << "\n\n";
							estado = true;
						}
					}	
				}
			}
		}
	}
	//********//Horizontales\\***********
    //horizontal --- jugador #1
    for(int i=6; i>=0; i--) {
		for(int j=6; j>=0; j--) {
			if(matriz[i][j] == '0') {
				if(matriz[i][j-1] == '0') {
					if(matriz[i][j-2] == '0') {
						if(matriz[i][j-3] == '0') {
							std::cout << "\n\n\tAcaba de ganar el Jugador #1 (0)\n\n";
							std::cout << "Felicitaciones !!!!!";
							std::cout << "\n\n";
							estado = true;
						}
					}	
				}
			}
		}
	}
	
	//horizontal --- jugador 2
	
	for(int i=6; i>=0; i--) {
		for(int j=6; j>=0; j--) {
			if(matriz[i][j] == '1') {
				if(matriz[i][j-1] == '1') {
					if(matriz[i][j-2] == '1') {
						if(matriz[i][j-3] == '1') {
							std::cout << "\n\n\tAcaba de ganar la maquina (1)\n\n";
							std::cout << "\n\n";
							estado = true;
						}
					}	
				}
			}
		}
	}
	//********//Diagonales normales\\**********
	//diagonal /  jugador #1
	
	for(int i=6; i>=0; i--) {
		for(int j=6; j>=0; j--) {
			if(matriz[i][j] == '0') {
				if(matriz[i-1][j+1] == '0') {
					if(matriz[i-2][j+2] == '0') {
						if(matriz[i-3][j+3] == '0') {
						
							std::cout << "\n\n\tAcaba de ganar el Jugador #1 (0)\n\n";
							std::cout << "Felicitaciones !!!!!";
							std::cout << "\n\n";
							estado = true;
							
						}
					}	
				}
			}
		}
	}
 //Diagonal \ jugador #2
 
 for(int i=6; i>=0; i--) {
		for(int j=6; j>=0; j--) {
			if(matriz[i][j] == '1') {
				if(matriz[i-1][j+1] == '1') {
					if(matriz[i-2][j+2] == '1') {
						if(matriz[i-3][j+3] == '1') {
							std::cout << "\n\n\tAcaba de ganar la maquina (1)\n\n";
							std::cout << "\n\n";
							estado = true;
						}
					}	
				}
			}
		}
	}
	
	//********// Diagonles contrarias\\**********
	
	//diagonal /  jugador #1
	
	for(int i=6; i>=0; i--) {
		for(int j=6; j>=0; j--) {
			if(matriz[i][j] == '0') {
				if(matriz[i+1][j+1] == '0') {
					if(matriz[i+2][j+2] == '0') {
						if(matriz[i+3][j+3] == '0') {
						
							std::cout << "\n\n\tAcaba de ganar el Jugador #1 (0)\n\n";
							std::cout << "Felicitaciones !!!!!";
							std::cout << "\n\n";
							estado = true;
							
						}
					}	
				}
			}
		}
	}
 //Diagonal / jugador #2
 
 for(int i=6; i>=0; i--) {
		for(int j=6; j>=0; j--) {
			if(matriz[i][j] == '1') {
				if(matriz[i+1][j+1] == '1') {
					if(matriz[i+2][j+2] == '1') {
						if(matriz[i+3][j+3] == '1') {
							std::cout << "\n\n\tAcaba de ganar la maquina (1)\n\n";
							std::cout << "\n\n";
							estado = true;
						}
					}	
				}
			}
		}
	} 
	return estado;
}


void tablero::maquina()
{
	if(turno == false) {
		turno = true;
	}else {
		turno = false;
	}
	
	if(turno == false) 
	{		
		std::cout <<"Turno del jugador: "<< turno << "\nDigita la columna donde quieres jugar: ";
		std::cin  >> this->columna;
				
		if(columna < 1 || columna > 7)
		{
			std::cout << "Jugada !!NO VALIDA!! \n";
			system("pause");
		}else {
			this->columna -= 1;
			this->ganadorMaquina();
			this->ColumnaLlena();
			for(int i=6; i>=0; i--) {	
				if(matriz[i][columna] == '*') 
					{			
						if(turno == false)
						{
							//system("pause");
							matriz[i][columna] = '0';				
							break;
						}
					}									
			}		
		}
   }else
   {
   		for (int i=6;i>=0;i--)
   		{
   			srand(time(0));
			int col = rand() %(7-1);
			if(matriz[i][col] == '*')
			{
				if(turno == true)
				{	
					
					std::cout<<"Turno de la maquina"<< std::endl;
					system("pause");
					matriz[i][col] = '1';
					break;
				}
			 
			}
   		}
	}
}

void tablero::guardarPartida()
{
	std::ofstream tableroGuardado;
	tableroGuardado.open("tablero.txt",std::ios::out); //Acá´se abre el archivo de la ultima partida
	
	if(tableroGuardado.fail())
	{
		std::cout << "No se pudo abrir el archivo "<< std::endl;
		exit(1);
	}
	
	for(int i=0; i<6; i++)
	{
		for(int j=0; j<7; j++)
		{			
			tableroGuardado << this->matriz[i][j];
		}tableroGuardado << std::endl;
	}
}

void tablero::cargarPartida()
{
	std::ifstream tablero;
	std::string texto;
	
	std::vector <std::string> lineas;

	tablero.open("tablero.txt",std::ios::in);
	std::cout<<std::endl;
	
	if(tablero.fail())	
	{
		std::cout<<"No se pudo abrir el archivo";
		exit(1);	
	}
	
	//Aqui se llena la matriz con la partida guardada
	for(int i=0;i<6;i++){	
		for(int j=0;j<7;j++){
			matriz[i][j]=lineas[i][j]-'0';
		}
	}
			
}

bool tablero::tablas()
{
	bool estado = false; 
	int option;
	if(this->turno==false)
	{	
		this->turno=true;
		std::cout<<"Desea aceptar tablas?"<<std::endl;
		std::cout<<"1) si"<<std::endl;
		std::cout<<"2) no"<<std::endl;
		std::cout<<"Ingrese la opcion: ";
		std::cin>>option;
		
		if(option==1)
		{
			estado=true;
		}
		else
		{	
			this->turno=true;
			estado=false;
		}
	}
	if(this->turno==true)
	{
		this->turno=false;
		std::cout<<"Desea aceptar tablas?"<<std::endl;
		std::cout<<"1) si"<<std::endl;
		std::cout<<"2) no"<<std::endl;
		std::cout<<"Ingrese la opcion: ";
		std::cin>>option;
		
		if(option==1)
		{
			estado=true;
		}
		else
		{	
			this->turno=false;
			estado=false;
		}
	}
	return estado;
}

// Destructor
tablero::~tablero() {	
}

