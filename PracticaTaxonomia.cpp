/*Crear un porgrama en el que lea el archivo JSON, extraiga los nombres, nombre cientifico y familia en la que pertenece el arbol
Guardalos dinamicamente y crea un metodo para plantar y despalntar el arbol*/

#include <iostream>
#include <stdlib.h>
#include <nlohmann/json.hpp>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>

#include "estructura.h"

using json = nlohmann::json;
using namespace std;

int main()
{
    menu();
    return 0;
}