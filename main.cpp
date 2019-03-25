#pragma once

#include <iostream>
#include "btree.h"
#include <time.h>
using namespace std;
int main()
{
	time_t start, end;
	
	
	cout << "----------------------------------------" << endl;
	cout << "Bienvendio Arbol b" << endl;
	cout << "Ingrese Orden del Arbol" << endl;
	int ord;
	cin >> ord;
		btree b(ord);
		cout << "Ingrese total de registros a importar" << endl;
		int totr;
		cin >> totr;	
		b.importar(totr);
	
	trs t;
	t.month = 11;
	t.year = 2006;
	double time_taken;
	char c[30];
	cout << "Ingrese Comando" << endl;
	cin >> c;
	while (strcmp(c, "salir") != 0) {

		if (strcmp(c, "recorrer") == 0) {
			b.recorrer();

		}

		if (strcmp(c, "bnorm") == 0) {
			int command;
			cout << "Ingrese Mes:" << endl;
			cin >> command;
			t.month = command;
			cout << "Ingrese Año:" << endl;
			cin >> command;
			t.year = command;
			cout << "Ingrese Codigo:" << endl;
			cin >> command;
			time(&start);
			if (b.buscar(t, command))
				cout << "Si lo encontro" << endl;
			time(&end);
			time_taken = double(end - start)*60;
			cout << "Tiempo invertido : " << fixed
				<< time_taken;
			cout << " sec " << endl;

		}

		if (strcmp(c, "bsec") == 0) {
			short int command;
			cout << "Ingrese Mes:" << endl;
			cin >> command;
			t.month = command;
			cout << "Ingrese Año:" << endl;
			cin >> command;
			t.year = command;
			cout << "Ingrese Codigo:" << endl;
			cin >> command;
			time(&start);
			if (b.bs(t, command))
				cout << "Si lo encontro" << endl;
			time(&end);
			time_taken = double(end - start);
			cout << "Tiempo invertido : " << fixed
				<< time_taken;
			cout << " sec " << endl;

		}

		if (strcmp(c, "listar") == 0) {
			short int command;
			
			cout << "Ingrese Mes:" << endl;
			cin >> command;
			t.month = command;
			cout << "Ingrese Año:" << endl;
			cin >> command;
			t.year = command;
			b.mesp(t);
		}
		cout << "Ingrese Comando" << endl;
		cin >> c;
	}


return 0;
		}
	

