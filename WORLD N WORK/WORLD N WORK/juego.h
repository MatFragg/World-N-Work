    #pragma once

#include <conio.h>
#include <Windows.h>
#include "bala.h"
#include "enemigos.h"
#include "mapa.h"
#include "Aliado.h"

void text(int i) {
    Console::Clear();
    Console::SetCursorPosition(18, 20);
    switch (i) {
    case 1:
        cout << "Nivel 1";
        break;
    case 2:
        cout << "Nivel 2";
    
       
        break;
    case 3:
        cout << "Nivel 3";
  
        break;
    }

    getch();
}

void hud(int kills, int shots, int deaths, int lives) {
    Console::Clear();

    Console::SetCursorPosition(20, 18);
    cout << "Enemigos eliminados: " << kills;
    Console::SetCursorPosition(20, 19);
    cout << "Numero de disparos: " << shots;
    Console::SetCursorPosition(20, 20);
    cout << "Muertes: " << deaths;
    Console::SetCursorPosition(20, 21);
    cout << "Vidas restantes: " << lives;
    _getch();

}

void jugar(int nivel) {
    int nivelPartida = nivel;
    int kills = 0;
    int shots = 0;
    int deaths = 0;
   
    Personaje* personaje = new Personaje();
    for (int i = nivel; i <= 3; i++) {
        kills -= 5 * nivelPartida;

        text(nivelPartida);

        generarMapa(nivelPartida);

        int posX = 1;
        int posY = 25;
        int nEnemigos = 0;
        int nAliados = 4 + nivelPartida;
        int tick = 0;
        
        enemigo** arrEnemigos = new enemigo * [0];
        aliado** arrAliados = new aliado * [0];

        for (int i = 0; i < nAliados; i++) {
            arrAliados = spawnAliados(arrAliados, i);
        }

        Bala* balas;
        int numBalas;

        balas = new Bala[MAX_BALAS];
        numBalas = 0;

                
        dibujarPersonaje(personaje, posX, posY);


        bool ok = false;

        while (1) {
            if (tick > 4) tick = 0;
            else tick++;
            if (kbhit()) {
                char tecla = getch();

                //if (tecla == DERECHA && mapa[posY][posX+3] != 1) {
                if (tecla == DERECHA && mapa[posY][posX + 1] != 1) {
                    borrarPersonaje(personaje, posX, posY);
                    personaje->dir = 1;
                    posX++;
                }

                if (tecla == IZQUIERDA && mapa[posY][posX - 1] != 1)
                {
                    borrarPersonaje(personaje, posX, posY);
                    personaje->dir = 3;
                    posX--;
                }
                //if (tecla == ARRIBA && (mapa[posY - 1][posX] != 1 && mapa[posY - 1][posX + 1] != 1 && mapa[posY - 1][posX + 2] != 1))
                if (tecla == ARRIBA && (mapa[posY - 1][posX] != 1))
                {
                    borrarPersonaje(personaje, posX, posY);
                    personaje->dir = 2;
                    posY--;
                }
                //if (tecla == ABAJO && (mapa[posY + 3][posX] != 1 && mapa[posY + 3][posX + 1] != 1 && mapa[posY + 3][posX + 2] != 1))
                if (tecla == ABAJO && (mapa[posY + 1][posX] != 1 ))
                {
                    borrarPersonaje(personaje, posX, posY);
                    personaje->dir = 4;
                    posY++;
                }

                if (tecla == 'D' || tecla == 'd')
                {
                    shots++;
                    disparar(personaje, numBalas, balas);
                }
            }

            moverBala(mapa, numBalas, balas, arrEnemigos, nEnemigos);

            dibujarPersonaje(personaje, posX, posY);
            while (nEnemigos < 5 * nivelPartida) {
                kills++;
                arrEnemigos = spawnEnemigos(arrEnemigos, nEnemigos);
                nEnemigos++;
            }
            if (tick % 2) moverEnemigos(arrEnemigos, nEnemigos);

            if (tick == 0) moverAliados(arrAliados, nAliados);

            if (tocarEnemigo(personaje, arrEnemigos, nEnemigos)) {
                deaths++;
                borrarPersonaje(personaje, posX, posY);
                posX = 1;
                posY = 25;
            }
            tocarAliado(personaje, arrAliados, nAliados);
            if (nAliados <= 0) {
                ok = true;

                nivelPartida++;
                break;
            }

            if (personaje->vidas <= 0) break;
            Sleep(50);
        }

        if (!ok) {
            Console::Clear();
            asignarColor(12);
            asignarPosicion(15, 25);
            cout << "GAME OVER";
            Sleep(1000);
            hud(kills, shots, deaths, personaje->vidas);
            break;
        }
        if (nivelPartida > 3) hud(kills, shots, deaths, personaje->vidas);
        delete personaje;
        delete[]balas;
    }
}
