#pragma once
#include <iostream>
#include <string>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>
#include "Sommet.h"
#include "Graphes.h"
#include "Source.h"

using namespace std;

int RandomInt() {
	
	return rand() % 100 + 1;
}
int main() {
	srand(time(NULL));
	/*Creation des sommets*/
	Sommet A("A");
	Sommet B("B");
	Sommet C("C");
	Sommet D("D"); 
	Sommet E("E"); 

	
	A.addRelations(&B, RandomInt());
	A.addRelations(&C, RandomInt());
	A.addRelations(&D, RandomInt());
	B.addRelations(&C, RandomInt());
	C.addRelations(&D, RandomInt());
	A.addRelations(&E, RandomInt());
	C.addRelations(&D, RandomInt());
	Graphes leGraphe;
	vector <Sommet*> S = { &A,&B,&C,&D,&E };
	leGraphe.addSommet(S);
	leGraphe.ShowGraphSommet();
	leGraphe.ShowAllRelations();

	leGraphe.AlgoDijkstra(&A, &D);
	return 0;
}