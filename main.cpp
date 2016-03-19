#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "Ville.h"
#include "Megalopole.h"
#include "chargementMegalopole.h"
#include "remplissageMatrice.h"

using namespace std;

int main(int argc, char **argv) {
    
    string fichierDataA= "../instances_TSP/kroA100.tsp";
    string fichierDataB= "../instances_TSP/kroB100.tsp";
    Megalopole megalopolisA, megalopolisB;
    chargementMegalopole loadMegalopoleA(fichierDataA, megalopolisA);
    chargementMegalopole loadMegalopoleB(fichierDataB, megalopolisB);
    
    remplissageMatrice matriceDistanceA100(megalopolisA);
    remplissageMatrice matriceDistanceB100(megalopolisB);
    
    vector<int> indice_villes;
    for(unsigned int i= 0; i < megalopolisA.get_villes().size(); ++i){
	indice_villes.push_back(i);
    }
    double coutCheminA= matriceDistanceA100.computePath(indice_villes);
    cout << "Le chemin de taille " << indice_villes.size() << " coute : " << coutCheminA << endl;
    
    double best_path= coutCheminA;
    for(unsigned int k= 1; k < indice_villes.size(); ++k){
	for(unsigned int l= 1; k < indice_villes.size(); ++l){
	    matriceDistanceA100.swapVilles(indice_villes, k, l);
	    if(best_path < matriceDistanceA100.computePath(indice_villes)){
		
	    };
	}
    }
    
    coutCheminA= matriceDistanceA100.computePath(indice_villes);
    cout << "Nouveau chemin de taille " << indice_villes.size() << " coute : " << coutCheminA << endl;
    
    
    return 0;
}