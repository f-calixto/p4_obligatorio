#include "Fecha.h"

Fecha :: Fecha(){ //Constructor
	dia = 1;
	mes = 1;
	anio = 2000;
}

Fecha :: Fecha(int d, int m, int a){ //Constructor comun
	dia = d;
	mes = m;
	anio = a;
}

Fecha :: Fecha(const Fecha &copia){ // Constructor copia
	dia = copia.dia;
	mes = copia.mes;
	anio = copia.anio;
}

int Fecha :: GetDia(){
	return dia;
}

int Fecha :: GetMes(){
	return mes;
}

int Fecha :: GetAnio(){
	return anio;
}

bool Fecha :: operator ==(const Fecha &otra){
    bool igual = true;
    if(dia != otra.dia || mes != otra.mes || anio != otra.anio)
        igual = false;
    return igual;
}

bool Fecha::operator<(const Fecha &otra){
    bool menor = false;
    if(anio < otra.anio)
        menor = true;
    else
        if(anio == otra.anio){
            if(mes < otra.mes)
                menor = true;
        else
            if(mes == otra.mes){
                if(dia < otra.dia)
                    menor = true;
        }
    }
    return menor;
}

Fecha Fecha :: operator ++(){
    switch (mes){
    case 2:
        if (dia == 28){
            dia = 1;
            mes = mes + 1;
        }else
            dia = dia + 1;
    break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (dia == 30){
            dia = 1;
            mes = mes + 1;
        } else
            dia = dia + 1;
    break;
    default:
        if (dia == 31){
            dia = 1;
            mes = mes + 1;
        }else
            dia = dia + 1;
    break;
    return (*this);
}
}

Fecha Fecha :: operator +(int x){
    switch (mes){
    case 2:
        if (dia + x > 28){
            dia = (dia + x) - 28;
            mes = mes + 1;
        }else
            dia = dia + x;
    break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (dia + x > 30){
            dia = (dia + x) - 30;
            mes = mes + 1;
        } else
            dia = dia + x;
    break;
    default:
        if (dia + x > 31){
            dia = (dia + x) - 31;
            mes = mes + 1;
        }else
            dia = dia + x;
    break;
}
    return (*this);
}


int Fecha::operator-(const Fecha &otra) {
    int dias1 = dia;
    int dias2 = otra.dia;

    for (int i = 1; i < mes; i++) {
        switch (i) {
            case 2:
                dias1 += 28;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                dias1 += 30;
                break;
            default:
                dias1 += 31;
                break;
        }
    }

    for (int i = 1; i < otra.mes; i++) {
        switch (i) {
            case 2:
                dias2 += 28;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                dias2 += 30;
                break;
            default:
                dias2 += 31;
                break;
        }
    }

    dias1 += anio * 365;
    dias2 += otra.anio * 365;

    return dias1 - dias2;
}




bool Fecha::esValida(){
    bool valida = true;
    if (mes < 1 || mes > 12)
        valida = false;

    if (dia < 1)
        valida = false;

    if (mes == 2)
    {
        if (dia > 28)
            valida = false;
    }
    else if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        if (dia > 30)
            valida = false;
    }
    else
    {
        if (dia > 31)
            valida = false;
    }

    return valida;
}


