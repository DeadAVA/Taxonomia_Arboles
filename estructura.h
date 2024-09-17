/*Crear un porgrama en el que lea el archivo JSON, extraiga los nombres, nombre cientifico y familia en la que pertenece el arbol
Guardalos dinamicamente y crea un metodo para plantar y despalntar el arbol*/

#include <iostream>
#include <stdlib.h>
#include <nlohmann/json.hpp>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>

using json = nlohmann::json; //llamdo a la clase json 
using namespace std; //llamado a la clase std

/*Creamos la clase arbol*/
class Arbol
{
    public:
        Arbol(string n, string sn, string f); //Constructor con 3 parametros nombre, nombre cientifico y familia ala que pertenece
        ~Arbol(); // destructor del objeto arbol
        static vector<Arbol*>Crear(const string& ArchivoJSON); //Metodo el cual crea objetos de tipo arbol y las almacena en un vector
        static void Destruir(vector<Arbol*>& arboles); //Metodo el cual crea destruye de tipo arbol y libera la memoria del espacio que ocupo del vector
        string getName(){return name;} //un getter para el nombre de los arboles creados
        void imprimeDatos(); //metodo para imprimir los arboles
    private: //atributos encapsulados de modo privado
        string name; //nombre
        string scientify_name; //nombre cientifico
        string family; //familia
};

Arbol::Arbol(string n, string sn, string f) //Constructor
{
    name = n;
    scientify_name = sn;
    family = f;
    cout<<"SE CONSTRUYO CORRECTAMENTE UN ARBOL"<<endl;
}

Arbol::~Arbol() //Destructor
{
    cout<<"SE DESTRUYO TU ARBOL"<<endl;
}

vector<Arbol*> Arbol::Crear(const string& ArchivoJSON)
{
    vector<Arbol*> arboles; //vector de clase Arbol
    vector<string> nombres;
    vector<string> snombre;
    vector<string> familias;
    
    if(arboles.empty()) //comprobamos si el vector esta vacio
    {
        ifstream archivo(ArchivoJSON); //hacemos llamado al archivo para hacer su lectura
        if(!archivo) //si el archivo no se encuentra en la ruta
        {
            cerr << "No se pudo abrir el archivo para lectura" << endl; //mandara error
            return arboles; //retornamos el vector
        }
        //en caso de que si exista en la ruta
        json taxonomia; //hacemos una variable de tipo json y la llamamos taxonomia
        archivo>>taxonomia; // hacemos la lectura del archivo

        // Verificar si el JSON contiene el campo "trees"
        if (taxonomia.contains("trees") && taxonomia["trees"].is_array()) {
            // Recorrer cada objeto dentro del array "trees"
            for (const auto& arbol : taxonomia["trees"]) {
                // Asegurarse de que los campos existan y sean del tipo esperado
                if (arbol.contains("name") && arbol["name"].is_string()) {
                    string nombre = arbol["name"]; //guardanos el nombre de forma temporal
                    nombres.push_back(nombre); // y la insertamos en el vector nombres y hacemos lo mismo en las siguiente lineas de codigo
                }
                if (arbol.contains("scientific_name") && arbol["scientific_name"].is_string()) {
                    string nombreCientifico = arbol["scientific_name"];
                    snombre.push_back(nombreCientifico);
                }
                if (arbol.contains("family") && arbol["family"].is_string()) {
                    string familia = arbol["family"];
                    familias.push_back(familia);
                }
            } //Terminamos if
        } else { // si lo anterior no cumple la condicion, muestra error
            cout << "El JSON no contiene una lista de árboles válida" << endl;
        }
    }
    srand(time(NULL)); //generamos una semilla aleatoria
    int p = nombres.size(); //guardamo el tamaño del vector en una variable entera
    int rands = 0; //creamos una variable de tipo entera
    rands = rand()% p; //generamos un numero alreatoria de 0 al tamaño del vector
    string p1 , p2, p3; //creamos 3 variables de tipo string
    p1 = nombres[rands]; //elejimos un arbol de forma aletoria de un arbol de forma aleatoria
    p2 = snombre[rands];
    p3 = familias[rands];
    arboles.push_back(new Arbol(p1,p2,p3)); //lo guardamos en el vector de objetos, arboles
    
    return arboles; //retornamos el vector
}

void Arbol::Destruir(vector<Arbol*>& arboles)
{
    if(arboles.empty())
    {
        cout<<"NO HAY ARBOLES QUE TALAR"<<endl;
        return;
    }
    int alt = rand()% arboles.size();
    //Eliminamos el arbol
    cout<<"ARBOL TALADO: "<<arboles[alt]->getName()<<endl;
    delete arboles[alt];  // Liberar la memoria del objeto
    arboles.erase(arboles.begin() + alt);  // Eliminar el puntero del vector
}

void Arbol::imprimeDatos()
{
    cout<<"ARBOL CREADO"<<endl;
    cout<<"NOMBRE: "<<name<<endl;
    cout<<"NOMBRE CINETIFICO: "<<scientify_name<<endl;
    cout<<"FAMILIA QUE PERTENECE: "<<family<<endl;
    cout<<"-------------------------------------"<<endl;
}

void menu()
{
    int opt = 0;
    bool ciclo = true;
    vector<Arbol*> arboles; 
    while(ciclo)
    {
        cout<<"---------------MENU---------------"<<endl;
        cout<<"1. Plantar Arbol"<<endl;
        cout<<"2. Talar Arbol"<<endl;
        cout<<"3. Arboles plantados"<<endl;
        cout<<"4. Salir"<<endl;
        cout<<"----------------------------------"<<endl;
        cout<<"Elija una opcion: ";
        cin>>opt;

        switch (opt)
        {
        case 1:
            system("cls");
            {
                // Crear nuevos árboles y agregarlos al vector arboles
                vector<Arbol*> nuevosArboles = Arbol::Crear("taxonomia_arboles.json");
                arboles.insert(arboles.end(), nuevosArboles.begin(), nuevosArboles.end());
            }
            system("pause");
            system("cls");            
            break;
        case 2:
            system("cls");
            Arbol::Destruir(arboles);
            system("pause");
            system("cls"); 
            break;
        case 3:
            system("cls"); 
            // Mostrar los datos de los árboles
            for (Arbol* arbol : arboles) 
            {
                arbol->imprimeDatos();
            }
            system("pause");
            system("cls"); 
            break;
        case 4:
            ciclo = false;
            break;
        
        default:
            cout<<"Opcion no existente"<<endl;
            break;
        }
    }
}
