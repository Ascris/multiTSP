#include "Ville.h"

Ville::Ville()
    :nb_ville(0), x(0), y(0)
{

}

Ville::Ville(int nb, int coord_x, int coord_y)
    :nb_ville(nb), x(coord_x), y(coord_y)
{

}

void Ville::set_nb_ville(int nb)
{
    nb_ville= nb;
}

void Ville::set_x(int new_x)
{
    x= new_x;
}

void Ville::set_y(int new_y)
{
    y= new_y;
}

std::ostream& Ville::print(std::ostream& out) const
{
    out << "id=" << nb_ville << " coord (" << x << " ; " << y << ")";
    return out;
}
