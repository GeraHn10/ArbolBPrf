#pragma once
#pragma once
#include "Nodo.h"
#include "trs.h"
#include <fstream>
class btree
{
public:
	Nodo* root;
	int menor;
	btree(int);
	void importar(int);
	void recorrer();
	Nodo* buscar(trs);
	bool buscar(trs, int);
	void mesp(trs );
	void insert(int, trs );
	bool bs(trs , int);
	~btree();
};
