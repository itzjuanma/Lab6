// Lab6_1334816.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stdio.h> 
#include <string>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

struct Nodo {
    string dato;
    Nodo* siguiente;
};


void PilaPokemones(Nodo*& pila, string n) {
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;
};


void sacarPilaPokemones(Nodo*& pila, string& n) {
    Nodo* aux = pila;
    n = aux->dato;
    pila = aux->siguiente;
    delete aux;
};

void mostrarPilaPokemones(Nodo*& pila) {

    Nodo* a = pila;
    while (a != NULL) {
        std::cout << "           - Pokemon " << a->dato << "\n";
        a = a->siguiente;
    }
};


//LEER ARCHIVO DE POKEMONES
void read_csv_words(Nodo*& pila, string csvPath)
{
    string delimiter = "-";
    fstream file;


    file.open(csvPath, ios::in);

    if (!file) {
        cout << "El archivo ingresado no existe.\n" << endl;
    }

    string line, word, temp, lastWord;

    while (getline(file, line, '\n')) {
        // read an entire row and
        // store it in a string variable 'line'
    // used for breaking words
        stringstream s(line);

        while (getline(s, word, ',')) {
            string nombreCancion = word.substr(0, word.find(delimiter));
            string artista = word.substr(word.find("-") + 1);
            if (nombreCancion == "") {
                cout << "El archivo contiene un espacio vacio, una o mas canciones no se agregaron a la playlist\n";
            }
            else {
                PilaPokemones(pila, word);
            }

        }
    }
    file.close();

};


//ORDENAMIENTO POR SELECTION 

/*void Ordenamientos::Selection(int valores[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (valores[min] > valores[j])
                min = j;
        }

        int aux = valores[i];
        valores[i] = valores[min];
        valores[min] = aux;
    }
    for (int i = 0; i < n; i++)
    {
        Console::WriteLine(valores[i]);
    }
}
*/


//ORDENAMIENTO SHELL

/*void Ordenamientos::Shell(int valores[], int n)
{
	for (int gap = n/2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i++)
		{
			int Temp = valores[i];
			int j;
			for (j = i; j >= gap && valores[j - gap] > Temp; j -= gap)
				valores[j] = valores[j - gap];
			valores[j] = Temp;
		}
	}
	for (int i = 0; i < n; i++)
	{
		Console::WriteLine(valores[i]);
	}
}*/


//ORDENAMIENTO BUBBLE

void bubbleSortPokemonesPila(Nodo*& pila, string optOrder) {
    Nodo* a = pila;
    Nodo* b = pila;
    string delimiter = "-";
    int sizePila = 0;
    while (a != NULL) {
        sizePila = sizePila + 1;
        a = a->siguiente;
    }

    vector<string> listaNationalNumber(sizePila);
    vector<string> listaGeneracion(sizePila);


    for (int i = 0; i < sizePila; i++) {
        string word = b->dato;
        string nationalNumber = word.substr(0, word.find(delimiter));
        string generacion = word.substr(word.find("-") + 1);

        listaNationalNumber[i] = nationalNumber;
        listaGeneracion[i] = generacion;
        b = b->siguiente;
    }

    string aux, auxArt;
    int x, j;
    for (x = 0; x < sizePila; x++) {
        for (j = 0; j < sizePila - x - 1; j++) {

            string nationalNumber = listaNationalNumber[j].substr(listaNationalNumber[j].find("-") + 1);
            if (listaNationalNumber[j] > listaGeneracion[j + 1]) {
                aux = listaGeneracion[j];
                listaGeneracion[j] = listaGeneracion[j + 1];
                listaGeneracion[j + 1] = aux;

                auxArt = listaNationalNumber[j];
                listaNationalNumber[j] = listaNationalNumber[j + 1];
                listaNationalNumber[j + 1] = auxArt;

            }
        }
    }



    // 


    //EXPORTAR ARCHIVO ORDENADO
    int write_csv(Nodo * &pila, string csvPath) {
        std::ofstream myFile(csvPath);
        Nodo* a = pilaPokemones;
        while (a != NULL) {
            myFile << a->dato;
            myFile << "\n";
            a = a->siguiente;
        }
        std::cout << "\nSe Genero el Archivo Con el Nuevo Orden de Pokemones Correctamente " << csvPath << "\n";
        myFile.close();
        return 0;

    }


    int main() {

        cout << "ORDENAMIENTO DE POKEMONES \n\n";
        cout << "Insertar Nombre de Archivo CSV para Cargar Lista de Pokemones: \n\n";
        cout << "[ pokemones.csv ] \n\n";
        getline(std::cin, pathCSV, '\n');
        pila = NULL;
        read_csv_words(pilaPokemones, pathCSV);
        cout << "\n\nArchivo anadido correctamente, presione ENTER para Continuar";
        cin.get();
        system("cls");


        int menuprincipal = 0;
        cout << "[ 1 ] Ordenar Archivo por National Number \n";
        cout << "[ 2 ] Ordenar Archivo por Generacion \n";
        cout << "[ 3 ] Visualizar Lista de Pokemones \n";
        if (menuPrincipal == "1") {
            system("cls");

            cout << "POKEMONES: Ordenando por National Number \n";
            bubbleSortPokemonesPila(pila, opc2);

            cout << "\n\nPresione ENTER para regresar al menu de POKEMONES";
            cin.get();
            system("cls");
        }
    

         else if (menuPrincipal == "2") {
            system("cls");

            cout << "POKEMONES: Ordenando por Generacion \n";
            bubbleSortPokemonesPila(pila, opc2);

            cout << "\n\nPresione ENTER para regresar al menu de POKEMONES";
            cin.get();
            system("cls");
        }
    
         else if (menuPrincipal == "3") {
             system("cls");

             cout << "POKEMONES: Mostrar  \n";
             cout << "La playlist Elegida es: \n\n";
             mostrarPilaPokemones(pila);
             cout << "\n\nPresione ENTER para regresar al menu de POKEMONES";
             cin.get();
             system("cls");
         }
