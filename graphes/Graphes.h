#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Sommet.h"

using namespace std;
class Graphes
{
public:
	Graphes();
	~Graphes();
	void addSommet(vector<Sommet*> S);
	Sommet* getSommet(int index);
	void ShowGraphSommet();
	void ShowAllRelations();
	void AlgoDijkstra(Sommet* Start, Sommet* End);

private:
vector <Sommet*> listSommet;

};




