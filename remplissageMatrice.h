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
    double get_distance(int i, int j) const { return distance[i][j]; };
    int get_nb_elem() const { return nb_elem; };
    
    //affichage de la matrice des distances
    void affichage();
    
    //fonctions de calcul sur la matrice
    double evaluationCout(std::vector<int> villes_ordonnees) const;
    
};

#endif