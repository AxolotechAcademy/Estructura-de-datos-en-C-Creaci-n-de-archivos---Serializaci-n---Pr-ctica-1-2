#ifndef MANEJADORDEARCHIVOS_H
#define MANEJADORDEARCHIVOS_H

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

#define NOMBRE_ARCHIVO "archivo.bin"

#include "Pokemon.h"

class ManejadorDeArchivos{
    private:
    
    public:
        ManejadorDeArchivos();
        ~ManejadorDeArchivos();

        void mostrarTodo();
        void crear(Pokemon *pokemon);
        void buscar(char nombre[20]);
};

ManejadorDeArchivos::ManejadorDeArchivos(){

}

ManejadorDeArchivos::~ManejadorDeArchivos(){

}

void ManejadorDeArchivos::crear(Pokemon *miPokemon){
    ofstream archivo(NOMBRE_ARCHIVO, ios::app|ios::binary);
    archivo.write((char *)miPokemon,sizeof(Pokemon));
    archivo.close();
}

void ManejadorDeArchivos::mostrarTodo(){
    Pokemon *miPokemon = new Pokemon();

    ifstream archivo(NOMBRE_ARCHIVO, ios::binary);

    if(!archivo.good()){
        cout << "El archivo no existe" << endl;
    } else {
        while(archivo.read((char *)miPokemon,sizeof(Pokemon))){
            cout << endl;
            miPokemon->mostrar();
            cout << endl;
        }
    }

    archivo.close();
}

void ManejadorDeArchivos::buscar(char nombre[20]){
    Pokemon *miPokemon = new Pokemon();
    bool encontrado = false;

    ifstream archivo(NOMBRE_ARCHIVO, ios::binary);

    if(!archivo.good()){
        cout << "El archivo no existe" << endl;
    } else {
        while(archivo.read((char *)miPokemon,sizeof(Pokemon))){
            if(strcmp(miPokemon->nombre,nombre)== 0){
                cout << endl;
                miPokemon->mostrar();
                cout << endl;
                encontrado = true;
            }
        }

        if(!encontrado){
            cout << endl << "No se encontro el registro" << endl;
        }
    }

    archivo.close();
}

#endif