#include "Megalopole.h"

Megalopole::Megalopole()
{
    villes= std::vector<Ville>();
}

Megalopole::Megalopole(const Ville& persepolis)
{
    villes.push_back(persepolis);
}

void Megalopole::set_villes(std::vector< Ville > Megalopolis)
{

}

void Megalopole::ajout_ville(Ville persepolis)
{
    villes.push_back(persepolis);
}

void Megalopole::retirer_ville(int id_ville)
{

}

void Megalopole::permutation_villes(int id_ville_1, int id_ville_2)
{

}

std::ostream& Megalopole::print(std::ostream& out) const
{
    for(int i= 0; i<villes.size(); ++i){
	out << villes[i] << std::endl;
    }
    return out;
}
