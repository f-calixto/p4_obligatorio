#ifndef FECHA_H
#define FECHA_H

class Fecha{
	private:
		int dia;
		int mes;
		int anio;
	public:
            //CONSTRUCTORES
                Fecha();                //Constructor
                Fecha(int, int, int);   //Constructor comun
                Fecha(const Fecha &);   // Constructor copia
			//GETTERS
                int GetDia();
                int GetMes();
                int GetAnio();
			//SOBRECARGA
                bool operator ==(const Fecha &);    //Verifica si las fechas son iguales               // fecha x, y = x == y;
                bool operator<(const Fecha &);      //Verifica si una fecha es menor a otra            // fecha x, y = x < y;
                Fecha operator++();                 //Suma 1 dia                                       // fecha x, ++x;
                Fecha operator+(int x);             //Suma x cantidad de dias                          // fecha x = x + 10;
                int operator-(const Fecha &);       //Diferencia de dias entre dos fechas              // int diferencia = fecha x + fecha y;
            //OPERACIONES
                bool esValida();                    //Verifica si una fecha es valida
};

#endif // FECHA_H
