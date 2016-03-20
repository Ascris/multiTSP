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
    
    int nb_swap= 8;
    for(int i= 0; i < nb_swap; ++i) {
	testPath.random_swap_step();
	coutCheminA= matriceDistanceA100.evaluationCout(testPath.getChemin());
	coutCheminB= matriceDistanceB100.evaluationCout(testPath.getChemin());
	Solution sol_actuelle(coutCheminA, coutCheminB);
	champ_solutions.ajoutSolution(sol_actuelle);
// 	cout << "Solution (A ; B) = (" << coutCheminA << " ; " << coutCheminB << ") = " << coutCheminA+coutCheminB << endl;
    }
    
    cout << "Champ Solutions AVANT suppression" << endl;
    cout << champ_solutions << endl;

    
    champ_solutions.supprAllWeakSolutions();
    
    cout << "Champ Solutions après suppression" << endl;
    cout << champ_solutions << endl;
    
    return 0;
}