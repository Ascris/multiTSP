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
#include "Chemin.h"
#include "Solution.h"
#include "champSolution.h"

using namespace std;

int main(int argc, char **argv) {
    
    string fichierDataA= "../instances_TSP/kroA100.tsp";
    string fichierDataB= "../instances_TSP/kroB100.tsp";
    Megalopole megalopolisA, megalopolisB;
    chargementMegalopole loadMegalopoleA(fichierDataA, megalopolisA);
    chargementMegalopole loadMegalopoleB(fichierDataB, megalopolisB);
    remplissageMatrice matriceDistanceA100(megalopolisA);
    remplissageMatrice matriceDistanceB100(megalopolisB);
    
    int tailleA= megalopolisA.get_villes().size();
    Chemin testPath(tailleA);
    
    champSolution champ_solutions;
    
    double coutCheminA= matriceDistanceA100.evaluationCout(testPath.getChemin());
    double coutCheminB= matriceDistanceB100.evaluationCout(testPath.getChemin());
    cout << "Solution (A ; B) = (" << coutCheminA << " ; " << coutCheminB << ") = " << coutCheminA+coutCheminB << endl;
    
    int nb_swap= 6;
    for(int i= 0; i < nb_swap; ++i){
	testPath.random_swap_step();
	coutCheminA= matriceDistanceA100.evaluationCout(testPath.getChemin());
	coutCheminB= matriceDistanceB100.evaluationCout(testPath.getChemin());
	Solution sol_actuelle(coutCheminA, coutCheminB, testPath.getChemin());
	champ_solutions.ajoutSolution(sol_actuelle);
    }
    
    cout << "Champ Solutions Initial" << endl;
    cout << champ_solutions << endl;
    
    vector<Solution> front_criteres= champ_solutions.getFront(0, 0);
    vector<Solution>::iterator it_c;
    for(it_c= front_criteres.begin(); it_c != front_criteres.end(); ++it_c){
	cout << "Solution frontale avec criteres : " << *it_c << endl;
    }
    
    return 0;
}