Hay dos formas de ejecutar le programa.

Método 1. Usando cmake:

Abrir la terminal de Mac o Linux, dirigirse a la carpeta PA_proyecto y ejecutar:

% mkdir build; cd build 
% cmake ../
% make
% ./PA_Proyecto 

Método 2. Compilando directamente con g++:

Abrir la terminal de Mac o Linux, dirigirse a la carpeta PA_proyecto y ejecutar:

% g++ -std=c++17  main.cpp -o exe
% ./exe

Archivos generados:
- Carpeta "build"
- Ejecutable "exe"

Se pueden eliminar al finalizar la ejecución.