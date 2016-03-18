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
    
    string fichierData= "../instances_TSP/kroA100.tsp";
    Megalopole megalopolis;
    chargementMegalopole loadMegalopole(fichierData, megalopolis);
    
    remplissageMatrice matriceDistance(megalopolis);
    
    //affichage des villes
    cout << "Affichage villes" << endl;
    cout << megalopolis << endl;

    //affichage matrice de distances
    matriceDistance.affichage();
    
    return 0;
}