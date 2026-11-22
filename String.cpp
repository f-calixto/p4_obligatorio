#include "String.h"
#include <iostream>
using namespace std;

String :: String(){
    cadena = new char[1];
    cadena[0] = '\0';
}

String :: String (const char * cad){
    int largo = strlen(cad);
    cadena = new char[largo + 1];
    strcpy(cadena, cad);
}

String :: String (char * cad){
    int largo = strlen(cad);
    cadena = new char[largo + 1];
    strcpy(cadena, cad);
}

String :: String (const String &otro){
    int largo = strlen(otro.cadena);
    cadena = new char[largo + 1];
    strcpy(cadena, otro.cadena);
}

String :: ~String (){
    delete [] cadena;
}

String String :: operator=(const String &otro){
    if(this != &otro){
        delete [] cadena;
        int largo = strlen(otro.cadena);
        cadena = new char[largo + 1];
        strcpy(cadena, otro.cadena);
    }
    return (*this);
}

bool String :: operator==(const String &otro){
    if(strcmp(cadena, otro.cadena) == 0)
        return true;
    else
        return false;
}

bool String :: operator<(const String &otro){
    return (strcmp(cadena, otro.cadena) < 0);
}

bool String :: operator>(const String &otro){
    return (strcmp(cadena, otro.cadena) > 0);
}

String String :: operator+(const String &otro){
    int largo = strlen(cadena) + strlen(otro.cadena);
    char * aux = new char[largo + 1];

    strcpy(aux, cadena);
    strcat(aux, otro.cadena);

    String resultado(aux);

    delete [] aux;
    return resultado;
}

bool String :: mismoLargo(String x){
    return (strlen(cadena) == strlen(x.cadena));
}

void String::aMinuscula()
{
    int i = 0;
    while(cadena[i] != '\0')
    {
        if (cadena[i] >= 'A' && cadena[i] <= 'Z')
        {
            cadena[i] = cadena[i] + ('a' - 'A');
        }
        i++;
    }
}

void  String :: print(){
    cout << cadena;
}

void String::scan() {
    char aux[256];

    cin >> ws;
    cin.getline(aux, 256);

    delete [] cadena;

    int largo = strlen(aux);
    cadena = new char[largo + 1];
    strcpy(cadena, aux);
}

bool String::comienzaCon(String &frase){
    return (strncmp(cadena, frase.cadena, strlen(frase.cadena)) == 0);
}
