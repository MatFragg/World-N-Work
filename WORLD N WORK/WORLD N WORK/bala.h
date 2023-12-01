#pragma once
#include "conio.h"
#include "iostream"
#include "mapa.h"
#include "utilidades.h"
#include "enemigos.h"

using namespace System;
using namespace std;


const int MAX_BALAS = 100;

struct Bala {
    int x;
    int y;
    int dir;
    char caracter = '*';
   
};

void dibujarBala(Bala* bala, int posX, int posY) {

    bala->x = posX;
    bala->y = posY;
    asignarPosicion(bala->x, bala->y);
    cout << bala->caracter;
}

void borrarBala(Bala* bala, int posX, int posY) {
    bala->x = posX;
    bala->y = posY;
    asignarPosicion(bala->x, bala->y);
    cout << " ";
}

bool tocarBala(Bala* b, enemigo**& arr, int &n) {
    for (int i = 0; i < n; i++) {
        if (b->x == arr[i]->x && b->y == arr[i]->y) {
            arr = deleteEnemigo(arr, n, i);
            return true;
        }
    }
    return false;
}

void moverBala(int** mapa, int& numBalas, Bala* &balas,enemigo** &arrEnemigos,int &nEnemigos) {
    
    for (int i = 0; i < numBalas; i++) {
        Bala* bala = &balas[i];
        bool ok;
        borrarBala(bala, bala->x, bala->y);

        switch (bala->dir) {
        case 1: ok = mapa[bala->y][bala->x + 1] == 1; break;
        case 2: ok = mapa[bala->y - 1][bala->x] == 1; break;
        case 3: ok = mapa[bala->y][bala->x - 1] == 1; break;
        case 4: ok = mapa[bala->y + 1][bala->x] == 1; break;
        }

        if (ok) {
            asignarPosicion(bala->x, bala->y);
            asignarColor(1);

            for (int j = i; j < numBalas - 1; j++) {
                balas[j] = balas[j + 1];
            }

            numBalas--;
        }
        else {
            switch (bala->dir) {
            case 1: bala->x++; break;
            case 2: bala->y--; break;
            case 3: bala->x--; break;
            case 4: bala->y++; break;
            }

            if (bala->x >= COLUMNAS || tocarBala(bala, arrEnemigos, nEnemigos)) {
                borrarBala(bala, bala->x, bala->y);
                
                numBalas--;
            }
            else {
                asignarPosicion(bala->x, bala->y);
                asignarColor(15);
                dibujarBala(bala, bala->x, bala->y);
            }
        }
    }
}

void disparar(Personaje* personaje, int &numBalas, Bala* &balas) {
    if (numBalas < MAX_BALAS) {
        Bala nuevaBala;
        nuevaBala.x = personaje->x;
        nuevaBala.y = personaje->y;
        nuevaBala.dir = personaje->dir;
        balas[numBalas] = nuevaBala;
        numBalas++;
    }
}






