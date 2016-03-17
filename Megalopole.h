#ifndef MEGALOPOLE_H
#define MEGALOPOLE_H

#include <vector>

#include "Ville.h"

class Megalopole {
    
private:
    std::vector<Ville> villes;
    
public:
    Megalopole();
    Megalopole(const Ville& persepolis);
    
    //getters & setters
    std::vector<Ville> get_villes() const { return villes; };
    void set_villes(std::vector<Ville> Megalopolis);
    
    //ajouter/retirer des villes
    void ajout_ville(Ville persepolis);
    void retirer_ville(int id_ville);
    
    //operations sur les villes
    void permutation_villes(int id_ville_1, int id_ville_2);
    
    
    std::ostream& print(std::ostream& out) const;
    friend std::ostream& operator<<(std::ostream& out, const Megalopole& m) { return m.print(out); }
    
};


#endif