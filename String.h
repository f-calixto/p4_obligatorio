#ifndef STRING_H
#define STRING_H

#include <string.h>

    //Incluye:
    // strcpy //copia
    // strlen //largo
    // strcat //concatena
    // strcmp //compara
    //...

class String{

    private:
        char * cadena;

    public:
        //CONSTRUCTORES Y DESTRUCTOR
        String ();                    // Constructor por defecto
        String (char *);              // Constructor común
        String (const String &);      //Constructor copia
        ~String ();                   // Destructor


        //SOBRECARGA DE OPERADORES
        String operator=(const String &);       //Asigna un String a otro, copia        (strcpy)
        bool operator==(const String &);        //Devuelve si son iguales o no          (strcmp)
        bool operator<(const String &);         // Verifica si es menor que otro string (strcmp)
        bool operator>(const String &);         // Verifica si es mayor que otro string (strcmp)
        String operator+(const String &);       // Concatatena dos string               (strcat)

        //METODOS
        bool mismoLargo(String);      // Compara el largo del objeto implícito con  el del string recibido por parámetro
        void aMinuscula();            // Transforma un String a letra minúscula, esto sirve para comparaciones
        void print();                 //Muesta un string en pantalla
        bool comienzaCon(String &frase); //devuelve true si ambos string coinciden en los primeros n caracteres

};


#endif // STRING_H_INCLUDED
