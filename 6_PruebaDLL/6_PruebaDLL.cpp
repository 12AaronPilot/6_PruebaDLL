// 6_PruebaDLL.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <Windows.h>
#include <string>


int main()
{
    puts("Cargando  DLL");
    //Cargar la dll
    HINSTANCE mydll = LoadLibrary(L"6_dll.dll");

    //Comprobar si cargó la dll
    if (mydll != NULL)
    {
        puts("Se cargo la DLL :)");
        typedef const char* (*GetCodenameFunc)();
        GetCodenameFunc getcodename = reinterpret_cast<GetCodenameFunc>(GetProcAddress(mydll, "GetCodename"));
        if (getcodename != NULL)
        {
            const char* mensaje = getcodename();
            std::cout << "desde la DLL" << mensaje << "\n";
        }
        else
        {
            puts("No se encontro la funcion :(");
        }


        //Cargar la funcion sumar
        typedef double (*sumarFunc)(double a, double b);
        sumarFunc sumar = reinterpret_cast<sumarFunc>(GetProcAddress(mydll, "sumar"));
        if (sumar != NULL)
        {
            std::cout << "prueba de suma:" << sumar (3.1416, 1.414);
            std::cout << "\n";
        }

        FreeLibrary(mydll);
    }
    else
    {
        puts("No se pudo cargar la DLL :(");
    }


    //Concatenacion de strings
    std::string string1 = "Hola soy";
    std::string string2 = "AaronMP";

    std::string s = string1 + " " + string2;

    std::cout << s << std::endl;


    return 0;
}
