#pragma once
#pragma once
#include <iostream>
#include <list>
#include "trs.h"
#include <fstream>
struct innvoice {
	int code;
	char name[25];
	char invoice_code[12];
	char date[12];
	short int day;
	short int month;
	short int year;
	char payment_type[12];
	double total;
	char business_type[20];
	char business_name[60];
};




class Nodo
{
public:
	Nodo(int min_llaves, bool hoja);
	void recorrer();
	Nodo* search(trs x);

	bool ordenar(trs d1, trs d2);
	trs *lista;
	int grado;
	Nodo** Pr;
	int keys;
	bool leaf;
	void dividirLL(int i, Nodo* y);
	void insertar(trs t);
	~Nodo();
};