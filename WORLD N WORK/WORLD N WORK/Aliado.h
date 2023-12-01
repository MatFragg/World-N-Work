#pragma once
#pragma once
#include "mapa.h"
#include "personaje.h"

struct aliado {
	int x;
	int y;
	int dir;
	bool dir2;
	char c = 'O';
};

aliado** spawnAliados(aliado** arr, int n) {
	aliado** newArr = new aliado * [n + 1];
	for (int i = 0; i < n; i++) {
		newArr[i] = arr[i];
	}
	aliado* e = new aliado();
	do {
		e->x = rand() % 54 + 5;
		e->y = rand() % 28 + 1;
		e->dir = 1;
		e->dir2 = rand() % 2;

	} while (mapa[e->y][e->x] == 1);
	newArr[n] = e;
	delete[]arr;
	return newArr;
}

aliado** deleteAliado(aliado** arr, int& n, int j) {
	aliado** newArr = new aliado * [n - 1];
	aliado* temp = NULL;
	bool ok = false;
	for (int i = 0; i < n; i++) {
		if (i == j) {
			asignarPosicion(arr[i]->x, arr[i]->y);
			cout << " ";
			temp = arr[i];
			ok = true;
		}
		else newArr[i - ok] = arr[i];
	}
	delete temp;
	delete[]arr;
	n--;
	return newArr;
}

void moverAliados(aliado**& arr, int n) {
	for (int i = 0; i < n; i++) {
		asignarPosicion(arr[i]->x, arr[i]->y);
		cout << " ";
		if (arr[i]->dir2) {
			if (mapa[arr[i]->y][arr[i]->x + arr[i]->dir] == 1) {
				arr[i]->dir *= -1;
			}
			arr[i]->x += arr[i]->dir;
		}
		else {
			if (mapa[arr[i]->y + arr[i]->dir][arr[i]->x] == 1) {
				arr[i]->dir *= -1;
			}
			arr[i]->y += arr[i]->dir;
		}
		asignarColor(10);
		asignarPosicion(arr[i]->x, arr[i]->y);
		cout << arr[i]->c;
	}
}

bool tocarAliado(Personaje*& p1, aliado**& arr, int& n) {
	for (int i = 0; i < n; i++) {
		int y = arr[i]->y, x = arr[i]->x;
		if (y >= p1->y && y < p1->y + 1 && x >= p1->x && x < p1->x + 2) {
			p1->vidas++;
			arr = deleteAliado(arr, n, i);
			return true;
		}
	}
	return false;
}