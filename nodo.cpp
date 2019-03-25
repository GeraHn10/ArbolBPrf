
#include "nodo.h"



Nodo::Nodo(int min_llaves, bool hoja)
{
	this->grado = min_llaves;
	this->leaf = hoja;
	lista = new trs[2 * grado - 1];
	Pr = new Nodo *[2 * grado];
	keys = 0;
}


void Nodo::recorrer()
{

	int i = 0;
	for (i = 0; i < keys; i++)
	{
		if (leaf == false)
			Pr[i]->recorrer();

		std::cout << "Fecha: ";
		std::cout << lista[i].month << "/";
		std::cout << lista[i].year << std::endl;

		

	}
	if (leaf == false)
		Pr[i]->recorrer();
}

Nodo * Nodo::search(trs x)
{
	int i = 0;

	while (i < keys&&this->ordenar(lista[i], x))
		i++;

	if ((lista[i].year == x.year) &&
		(lista[i].month == x.month))
		return this;

	if (leaf == true)
		return NULL;

	return Pr[i]->search(x);

}

bool Nodo::ordenar(trs d1, trs d2)
{
	
	if (d1.year < d2.year)
		return true;
	if (d1.year == d2.year && d1.month < d2.month)
		return true;

	return false;
}

void Nodo::dividirLL(int i, Nodo * y)
{
	Nodo *n = new Nodo(y->grado, y->leaf);
	n->keys = grado - 1;

	for (int j = 0; j < grado - 1; j++)
	{
		n->lista[j] = y->lista[j + grado];
	}

	if (y->leaf == false) {
		for (int j = 0; j < grado; j++)
		{
			n->Pr[j] = y->Pr[j + grado];
		}
	}

	y->keys = grado - 1;

	for (int j = keys; j >= i + 1; j--)
	{
		Pr[j + 1] = Pr[j];
	}

	Pr[i + 1] = n;

	for (int j = keys - 1; j >= i; j--)
	{
		lista[j + 1] = lista[j];
	}

	lista[i] = y->lista[grado - 1];
	keys = keys + 1;

}

void Nodo::insertar(trs x)
{
	int i = keys - 1;
	if (leaf) {
		while (i >= 0 && this->ordenar(x, lista[i])) {
			lista[i + 1] = lista[i];
			i--;
		}
		lista[i + 1] = x;
		keys = keys + 1;
	}
	else {

		while (i >= 0 && this->ordenar(x, lista[i]))
			i--;

		if (Pr[i + 1]->keys == (2 * grado - 1)) {
			dividirLL(i + 1, Pr[i + 1]);

			if (this->ordenar(lista[i + 1], x))
				i++;
		}
		Pr[i + 1]->insertar(x);
	}


}

Nodo::~Nodo()
{
}

trs::trs()
{
}

trs::~trs()
{
}
