#include "Sommet.h"
string Sommet::getName()
{
	return name;
}

void Sommet::setName(string N)
{
	name = N;
}

void Sommet::addVoisin(Sommet* Voisin)
{
	if (find(ListVoisin.begin(),ListVoisin.end(),Voisin) == ListVoisin.end())
	{
		ListVoisin.push_back(Voisin);
		Voisin->ListVoisin.push_back(this);
	}
	
}





void Sommet::afficherVoisins()
{
	// la virgule tu connait.
	for (int i = 0;  i < ListVoisin.size();  i++)
	{
		if (i == ListVoisin.size()-1)
		{
			cout << ListVoisin[i]->getName() << endl;
		}
		else
		{
			cout << ListVoisin[i]->getName() + ",";
		}
		
		
	}
}

Sommet* Sommet::getVoisin()
{
	return ListVoisin[0];
}

void Sommet::addRelations(Sommet* Voisin, int poids)
{
	if (find(ListVoisin.begin(), ListVoisin.end(), Voisin) != ListVoisin.end()) {
		Relations.insert(pair<Sommet*, int>(Voisin, poids));
		Voisin->Relations.insert(pair<Sommet*, int>(this, poids));
	}
	else
	{
		
		addVoisin(Voisin);
		addRelations(Voisin, poids);
	}
	
}

void Sommet::ShowRelations()
{
	for (pair<Sommet*,int> it : Relations)
	{
		cout << "Relation entre Sommet " << this->getName() << "-" << it.first->getName() <<"  "<< it.second << endl;
	}
}

map<Sommet*, int> Sommet::getRelations()
{
	return Relations;
}

bool Sommet::hasRelations(Sommet* S)
{
	if (auto itr = Relations.find(S) != Relations.end()) {

		return true;
	}
	return false;
}

bool Sommet::getVisite()
{
	return visite;
}

void Sommet::setVisite(bool b)
{
	visite = b;
}






Sommet::Sommet()
{
}

Sommet::~Sommet()
{
}

Sommet::Sommet(string n)
{
	name = n;
}
