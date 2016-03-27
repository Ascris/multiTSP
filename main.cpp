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
#include "ecritureFichier.h"
#include "algorithm.h"

//chrono
#include "ChronoCHARLOT.hpp"


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
    
    //generation 500 chemins aleatoires (chemin de base + permutation de 2 villes = new chemin)
    double coutCheminA;
    double coutCheminB;
    int nb_swap= 500;
    for(int i_ville1= 1; i_ville1 < tailleA; ++i_ville1){
	for(int i_ville2= i_ville1+1; (i_ville2 < tailleA) && (i_ville2 < nb_swap); ++i_ville2){
	    testPath.swap_cities(i_ville1, i_ville2);
	    coutCheminA= matriceDistanceA100.evaluationCout(testPath.getChemin());
	    coutCheminB= matriceDistanceB100.evaluationCout(testPath.getChemin());
	    Solution sol_actuelle(coutCheminA, coutCheminB, testPath.getChemin());
	    champ_solutions.ajoutSolution(sol_actuelle);
	}
    }
    
    int maxA= 0, maxB= 0;
    vector<Solution> all_solutions= champ_solutions.getSolutions();
    vector<Solution> offlinePareto= champ_solutions.getFront(maxA, maxB);
    vector<Solution> onlinePareto= champ_solutions.buildingFront(maxA, maxB);
    
    /*
    //Verification offline/online
    vector<Solution>::iterator it_c;
    for(it_c= offlinePareto.begin(); it_c != offlinePareto.end(); ++it_c){
	cout << "Offline : " << *it_c << endl;
    }
    
    cout << "************************************" << endl;
    
    for(it_c= onlinePareto.begin(); it_c != onlinePareto.end(); ++it_c){
	cout << "Online : " << *it_c << endl;
    }
    */
    ecritureFichier allSolOffline("allSol500_KroAB.txt", all_solutions);
    
//     ecritureFichier allSolOffline("offline500_KroAB.txt", all_solutions);
    ecritureFichier outputOfflinePareto("offlinePareto500_KroAB.txt", offlinePareto);
    
//     ecritureFichier all_sol_online("online500_KroAB.txt", all_solutions);
    ecritureFichier outputOnlinePareto("onlinePareto500_KroAB.txt", onlinePareto);
    
    //*****************************************
    //tester des chemins avec une fonction de voisinage - utiliser matriceA100... (remplissageMatrice)
    
    champSolution champ_PLS;
    vector<Solution> PLS;
    Chemin voisin;
    int nb_ite= 0, nb_voisins= 500, nb_sol= 0;
    vector<Solution> front_offline= champ_solutions.getFront(maxA, maxB);
    vector<Solution>::iterator parc_sol;
    
    
    Chrono chronoPLS;
    chronoPLS.start();
    
//     while(voisin != testPath && nb_ite < nb_voisins){
	while(nb_ite < nb_voisins){
	cout << "iteration voisin : " << nb_ite << endl;
	nb_sol= 0;
	for(parc_sol= front_offline.begin(); parc_sol != front_offline.end(); ++parc_sol){
	    //si une solution a un voisin ameliorant, on le prend en compte
	    voisin= algorithm::voisinage(matriceDistanceA100, matriceDistanceB100, parc_sol->get_path());
	    if(!(voisin != parc_sol->get_path())) break;
	    double cout_A= matriceDistanceA100.evaluationCout(voisin.getChemin());
	    double cout_B= matriceDistanceB100.evaluationCout(voisin.getChemin());
	    Solution nouveau_voisin(cout_A, cout_B, voisin);
// 	    cout << cout_A << "---" << cout_B << endl;
	    
	    
	    champ_solutions.ajoutSolution(nouveau_voisin);
	    PLS= champ_solutions.buildingFront(maxA, maxB);
// 	    cout << "iteration " << nb_ite << " solution interne : " << nb_sol << endl;
	    ++nb_sol;
	}
	++nb_ite;
    }
    chronoPLS.stop();
    cout << "temps ecoule pour " << nb_voisins << " voisins : " << chronoPLS.getDuration() << endl;
    
    PLS= champ_PLS.getSolutions();
    ecritureFichier PLS_fic("PLS500_KroAB.txt", PLS);
    
    return 0;
}