#include "pch.h"
#include "juego.h"

int main()
{
    Console::SetWindowSize(60, 40);
    Console::SetBufferSize(60, 40);
    Console::CursorVisible = false;
    srand(time(NULL));
    int o = menu();
    if (o != -1) {
        jugar(o);
        system("pause>0");
    }
    return 0;
}