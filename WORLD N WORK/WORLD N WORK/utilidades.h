    #pragma once
    #include <iostream>
	#include <conio.h>

	using namespace std;
    using namespace System;
    

	int menu() {
		while (1) {
			Console::Clear();
			int opcion = 0;
			bool end = false;
			cout << "1. Presentacion" << "\n";
			cout << "2. Instrucciones" << "\n";
			cout << "3. Creditos" << "\n";
			cout << "4. Comenzar juego" << "\n";
			cout << "5. Salir" << "\n";
	
			do {
				cin >> opcion;
			} while (opcion < 1 || opcion > 5);
			Console::Clear();
			switch (opcion) {
			case 1:
				cout << "Presentacion:" << endl;
				cout << "----------------" << endl;
				cout << "Hola, bienvenido a WORLD N WORK," << endl;
				cout << "en este juego te convertiras en un microempresario" << endl;
				cout << "A lo largo del juego mejoraras tu empresa de varias formas," << endl;
				cout << "en el encontraras aliados que te ayudaran.Existen" << endl;
				cout << "distintos tipos de aliados, los unirás a tu empresa," << endl;
				cout << "hacindola más fuerte y también creando puestos de trabajo" << endl;
				cout << "junto a la formalizacion de estos segun de que tipo sean" << endl;
				cout << "Innovaras tu empresa con cada nivel, mientras consigas todos" << endl;
				cout << "los aliados, esta mejorara." << endl;
				cout << "----------------" << endl;
				cout << "\nPresione una tecla para continuar...\n";
				_getch();
				break;
			case 2:
				cout << "Indicaciones:" << endl;
				cout << "----------------" << endl;
				cout << "1.-Utilizar las teclas direccionales para el movimiento" << endl;
				cout << "2.-Para disparar debes utilizar la tecla D" << endl;
				cout << "3.-Los aliados te suman una vida extra" << endl;
				cout << "4.-Los enemigos te restan una vida extra" << endl;
				cout << "4.-Al obtener a todos los aliados avanzas de nivel" << endl;
				cout << "----------------" << endl;
				cout << "\nPresione una tecla para continuar...\n";
				_getch();
				break;
			case 3:
				cout << "Creditos: " << endl;
				cout << "----------------" << endl;
				cout << "Matias Aliaga Aguirre" << endl;
				cout << "Alexander Moreno" << endl;
				cout << "\nPresione una tecla para continuar...\n";
				_getch();
				break;
			case 4:
				cout << "Ingrese el nivel de mapa quiere inciar (1, 2 o 3):";
				do
				{
					cin >> opcion;
					if (opcion < 1 || opcion > 3)
					{
						cout << "Aviso: Debe ingresar 1, 2 o 3 para iniciar el juego: " << endl;
					}
				} while (opcion < 1 || opcion > 3);

				return opcion;
				break;
			case 5:
				end = true;
				break;
			}
			if (end) break;
		}
		return -1;
	}

    void asignarPosicion(int x, int y) {
	    Console::SetCursorPosition(x, y);
    }

    void asignarColor(int codigoColor) {
        switch (codigoColor)
        {
        case 1: Console::ForegroundColor = ConsoleColor::Black; break;
        case 2: Console::ForegroundColor = ConsoleColor::DarkBlue; break;
        case 3: Console::ForegroundColor = ConsoleColor::DarkGreen; break;
        case 4: Console::ForegroundColor = ConsoleColor::DarkRed; break;
        case 5: Console::ForegroundColor = ConsoleColor::DarkMagenta; break;
        case 6: Console::ForegroundColor = ConsoleColor::DarkYellow; break;
        case 7: Console::ForegroundColor = ConsoleColor::Gray; break;
        case 8: Console::ForegroundColor = ConsoleColor::DarkGray; break;
        case 9: Console::ForegroundColor = ConsoleColor::Blue; break;
        case 10: Console::ForegroundColor = ConsoleColor::Green; break;
        case 11: Console::ForegroundColor = ConsoleColor::Cyan; break;
        case 12: Console::ForegroundColor = ConsoleColor::Red; break;
        case 13: Console::ForegroundColor = ConsoleColor::Magenta; break;
        case 14: Console::ForegroundColor = ConsoleColor::Yellow; break;
        case 15: Console::ForegroundColor = ConsoleColor::White; break;
        }
    }