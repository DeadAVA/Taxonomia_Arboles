# Taxonomía de Árboles

Programa en C++ que lee un catálogo de árboles desde un archivo JSON (nombre, nombre científico, familia, clase y orden) y los modela dinámicamente como objetos, con operaciones para "plantar" y "desplantar" (crear/destruir) árboles en memoria.

> C++ program that reads a tree catalog from a JSON file (common name, scientific name, family, class and order), models each entry as a dynamic object, and supports "planting"/"uprooting" (creating/destroying) trees in memory.

## Qué hace

- Lee `taxonomia_arboles.json`, un catálogo de árboles con su clasificación taxonómica.
- Por cada entrada crea un objeto `Arbol` (constructor/destructor con mensajes de creación y destrucción).
- Expone un menú interactivo para listar, plantar y desplantar árboles del catálogo cargado.
- Usa el paradigma de programación orientada a objetos y manejo manual de memoria (`vector<Arbol*>`).

## Dependencias

- Compilador C++ (MinGW en Windows).
- [`nlohmann/json`](https://github.com/nlohmann/json) — librería header-only para parsear JSON.

### Instalación de la librería (Windows / MinGW)

1. Descarga el release de `nlohmann/json` (incluido en este repo como `json-develop.zip`) y descomprímelo.
2. Copia la carpeta `nlohmann` dentro del directorio `include` de tu instalación de MinGW, de modo que quede accesible como `#include <nlohmann/json.hpp>`.

## Compilar y ejecutar

```bash
g++ Taxonomia/PracticaTaxonomia.cpp -o taxonomia
./taxonomia
```

## Estructura

```
Taxonomia_Arboles/
└── Taxonomia/
    ├── PracticaTaxonomia.cpp   # Punto de entrada
    ├── estructura.h            # Clase Arbol + menú interactivo
    └── taxonomia_arboles.json  # Catálogo de árboles
```

## Contexto

Proyecto académico centrado en lectura de JSON y POO en C++.

---

## English summary

Academic C++ exercise that parses a JSON tree catalog with `nlohmann/json` and models each record as an `Arbol` (Tree) object, demonstrating OOP, dynamic memory management, and file-based data loading through an interactive menu.
