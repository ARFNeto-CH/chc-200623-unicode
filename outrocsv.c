#define _CRT_SECURE_NO_WARNINGS

#include <fcntl.h> 
#include <io.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <windows.h>

int main(int argc, char** argv)
{
    const int Unicode = _O_U16TEXT;
    const int Non_Unicode = _O_TEXT;
    int console = _fileno(stdout);
    if (console < 0)
    {
        fprintf(stderr, "saida provavelmente rediredirecionada\n");
        return -1;
    };  // if()
    SetConsoleOutputCP(65'001);
    wchar_t pagina[160];
    for (int i = 0; i < 160; i += 1)
    {
        pagina[i] = 0x2b00 + i;
    };
    HANDLE CON = GetStdHandle(STD_OUTPUT_HANDLE);
    _setmode(console, Unicode);
    for (int i = 0; i < 160; i += 1)
    {
        wprintf(L"%4X%4c  ", pagina[i], pagina[i]);
        if ((1+i)% 8 == 0) wprintf(L"\n");
    };
    wprintf(L"\n");
    _setmode(console, Non_Unicode);
    printf("printf() normal\n");

    return 0;
};

//  fim