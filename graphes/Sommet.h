#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <map>


using namespace std;
class Sommet
{
public:
	Sommet();
	~Sommet();
	Sommet(string n);
	int test;

	string getName();
	void setName(string N);
	void addVoisin(Sommet* Voisin);
	void afficherVoisins();
	Sommet* getVoisin();
	void addRelations(Sommet* Voisin, int poids);
	void ShowRelations();
	map<Sommet*, int> getRelations();
	bool hasRelations(Sommet *S);
	bool getVisite();
	void setVisite(bool b);


private:
	string name;
	bool visite = false;
	vector <Sommet*> ListVoisin;
	map<Sommet*, int> Relations;
	
};


