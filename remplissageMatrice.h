#ifndef REMPLISSAGE_MATRICE_H
#define REMPLISSAGE_MATRICE_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ostream>
#include <math.h>

#include "Megalopole.h"

class remplissageMatrice {
private:
    double** distance;
    int nb_elem;
    
public:
    remplissageMatrice();
    remplissageMatrice(const Megalopole& megalopolis);
    
    //getters & setters 
    double getDistance(int i, int j) const { return distance[i][j]; };
    
    //affichage de la matrice des distances
    void affichage();
    
    //fonctions de calcul sur la matrice
    double evaluationCout(std::vector<int> villes_ordonnees);
    
};

#endif