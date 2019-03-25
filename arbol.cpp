#pragma once
#include "btree.h"

using namespace std;

btree::btree(int size)
{
	menor = size;
	root = NULL;
}

void btree::importar(int x)
{
	std::ifstream file("data.dat", std::ifstream::in | std::ifstream::binary);
	if (!file) {

		cout << "error" << endl;
	}
	else {
		std::cout << std::endl;
		innvoice t;

		file.seekg(0, std::ifstream::beg);
		file.read(reinterpret_cast<char*>(&t), sizeof(innvoice));

		trs trans;
		trans.month = t.month;
		trans.year = t.year;

		std::cout << "Fecha:";
		std::cout << trans.month << "/";
		std::cout << trans.year << "   ";
		std::cout << t.code << "" << std::endl;

		this->insert(0, trans);
		for (int i = 0; i < x - 1; i++)
		{
			file.read(reinterpret_cast<char*>(&t), sizeof(innvoice));


			trans.month = t.month;
			trans.year = t.year;

			std::cout << "Fecha:";
			std::cout << trans.month << "/";
			std::cout << trans.year << "   ";
			std::cout << t.code << "" << std::endl;
			this->insert(i + 1, trans);
		}
		file.close();
	}
}

void btree::recorrer()
{
	if (root != NULL)
		root->recorrer();
}

Nodo * btree::buscar(trs x)
{
	return (root == NULL) ? NULL : root->search(x);
}

bool  btree::buscar(trs y, int code)
{
	trs x;
	x.month = y.month;
	x.year = y.year;

	Nodo* t = buscar(x);
	if (t == NULL)
		return false;
	int i = 0;
	for (i = 0; i < t->keys; i++)
	{
		if ((t->lista[i].year == x.year) &&
			(t->lista[i].month == x.month)) {

			std::ifstream file("data.dat", std::ifstream::in | std::ifstream::binary);
			//	file ? std::cout << "Creado con exito" : std::cout << "Error al crear";
			//	std::cout << std::endl;
			innvoice trans;

			for (unsigned int z = 0; z < t->lista[i].ld.size(); z++)
			{
				file.seekg(sizeof(innvoice)*t->lista[i].ld.at(z));
				file.read(reinterpret_cast<char*>(&trans), sizeof(innvoice));

				if (trans.code == code) {
					file.close();
					return true;
				}
			}

			file.close();

		}

	}

	return false;
}

void btree::mesp(trs x)
{
	Nodo* v = this->buscar(x);
	if (v == NULL)
		return;

	int i = 0;
	for (i = 0; i < v->keys; i++)
	{
		if ((v->lista[i].year == x.year) &&
			(v->lista[i].month == x.month)) {

			std::ifstream file("data.dat", std::ifstream::in | std::ifstream::binary);
			//	file ? std::cout << "Creado con exito" : std::cout << "Error al crear";
			//	std::cout << std::endl;
			innvoice trans;
			std::cout << std::endl;
			std::cout << "Fecha a Imprimir: " << x.month << "/" << x.year << std::endl;
			for (unsigned int z = 0; z < v->lista[i].ld.size(); z++)
			{
				file.seekg(sizeof(innvoice)*v->lista[i].ld.at(z));
				file.read(reinterpret_cast<char*>(&trans), sizeof(innvoice));
				std::cout << std::endl;
				std::cout << "Dia: " << trans.day << std::endl;
				std::cout << "Mes: " << trans.month << std::endl;
				std::cout << "Año: " << trans.year << std::endl;
				std::cout << "Codigo: " << trans.code << std::endl;
			}

			file.close();

		}
	}

}

void btree::insert(int pos, trs y)
{
	y.ld.push_back(pos);

	Nodo* v = this->buscar(y);
	if (v != NULL) {
		int z = 0;
		for (z = 0; z < v->keys; z++)
		{
			if ((v->lista[z].year == y.year) &&
				(v->lista[z].month == y.month))
				break;
		}
		v->lista[z].ld.push_back(pos);
		return;

	}

	if (root == NULL) {
		root = new Nodo(menor, true);
		root->lista[0] = y;
		root->keys = 1;
	}
	else {
		if (root->keys == (2 * menor - 1)) {
			Nodo* s = new Nodo(menor, false);
			s->Pr[0] = root;
			s->dividirLL(0, root);

			int i = 0;
			if (root->ordenar(s->lista[0], y))
				i++;

			s->Pr[i]->insertar(y);

			root = s;
		}
		else
			root->insertar(y);
	}
}

bool btree::bs(trs y, int code)
{


	std::ifstream file("data.dat", std::ifstream::in | std::ifstream::binary);
	innvoice t;

	file.seekg(0, std::ifstream::beg);
	file.read(reinterpret_cast<char*>(&t), sizeof(innvoice));

	trs trans;
	trans.month = t.month;
	trans.year = t.year;

	while (!file.eof()) {
		if (y.month == t.month && y.year == t.year && code == t.code) {
			file.close();
			return true;
		}

		file.read(reinterpret_cast<char*>(&t), sizeof(innvoice));

	}

	file.close();
	return false;
}


btree::~btree()
{
}