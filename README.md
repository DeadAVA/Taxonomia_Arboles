# Taxonomia_Arboles
En este codigo utilizamos la libreria nlohman para la lectura de archivos .JSON e hicimos uso del paradigma Porgramacion Orientada a objetos en C++.
Antes de empezar para poder utilizar este codigo necesitas instalar la la libreria nlhoman para la lectura de jsons.


/*Falta desarrollar*/
# Instalacion de la libreria
Descargamos el archivo .zip y lo descomprimos en otra carpeta, una vez descomprimida buscamos el archivo nlhoman y no metemos dentro de la carpeta del mingw

/*CAMBIAR ESTO*/
<h2>Diseñe e implemente las clases (atributos y métodos) que permitan generar objetos tipo
hospital, habitación y paciente (clases: Hospital, Habitacion y Paciente). El programa final
debe incluir la funcionalidad siguiente:</h2>

a) Solicitar al usuario la cantidad de habitaciones con que cuenta el hospital. Generar y
almacenar los objetos de la clase Habitacion en un atributo de la clase Hospital,
mediante una estructura dinámica (vector).

b) Al instanciar una habitación, aleatoriamente generar su número de camas (1-3).
Mediante una estructura dinámica (vector), referenciando a apuntadores de objetos tipo
Paciente (puede indicar NULL como apuntador inicial: cama.push_back(NULL)).

c) Desplegar la información del hospital antes de iniciar la simulación de ingreso/egreso
de pacientes, indicar “DISPONIBLE” cuando el apuntador al objeto Persona sea NULL
(if(cama[i] == NULL)).

![imagen](https://user-images.githubusercontent.com/107895779/198505741-d5144405-c91c-4718-9a9a-389942049dea.png)


