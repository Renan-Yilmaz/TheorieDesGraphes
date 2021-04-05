#include "Graphes.h"

Graphes::Graphes()
{
}

Graphes::~Graphes()
{
}

void Graphes::addSommet(vector<Sommet*> S)
{
	for (int i = 0; i < S.size(); i++)
	{
		listSommet.push_back(S[i]);
	}		
}

Sommet* Graphes::getSommet(int index)
{
	if (index <= listSommet.size())
	{
		return listSommet[index];
	}
	else
	{
		cout << "INVALID INDEX" << endl;
	}
	
}

void Graphes::ShowGraphSommet()
{
	cout << "Sommet du Graph : ";
	for (int i = 0; i < listSommet.size(); i++)
	{
		cout << listSommet[i]->getName() << " ";
	}
	cout << endl;
}

void Graphes::ShowAllRelations()
{
	for (int i = 0; i < listSommet.size(); i++)
	{
		listSommet[i]->ShowRelations();
	}
	cout << endl;
}

void Graphes::AlgoDijkstra(Sommet* Start, Sommet* End)
{
	cout << "Depart : " << Start->getName() << endl;
	cout << "Arriver : " << End->getName() << endl;
	
	Sommet* currentSommet =Start;
	map<string, int> AllPath;
	string chemin = Start->getName();
	int poids = 0;
	currentSommet->setVisite(true);
	for (pair<Sommet*,int> it :currentSommet->getRelations())
	{

		cout << "Sommet en cours de visite : " << currentSommet->getName() << " poids en cours : " << poids << endl;
		currentSommet->ShowRelations();
		if (it.first ==End && !currentSommet->getVisite())
		{
			chemin += it.first->getName();
			poids += it.second;
			AllPath.insert(pair<string, int>(chemin, poids));
			currentSommet->setVisite(true);
			poids = 0;
			chemin = Start->getName();
			currentSommet = Start;
		}
		else
		{
			if (!it.first->getVisite())
			{
				poids += it.second;
				chemin += it.first->getName();
				currentSommet->setVisite(true);
				currentSommet = it.first;
				
			}
		}
	}

	for (pair<string,int> it : AllPath)
	{
		cout << it.first << " poids : " << it.second << endl;
	}

}
