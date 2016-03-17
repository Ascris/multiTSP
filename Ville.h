#ifndef VILLE_H
#define VILLE_H

#include <ostream>

class Ville {
    
private:
    int nb_ville;
    int x;
    int y;
    
public:
    Ville();
    Ville(int nb, int coord_x, int coord_y);
    
    //getters & setters
    int get_nb_ville() const { return nb_ville; };
    int get_x() const { return x; };
    int get_y() const { return y; };
    
    void set_nb_ville(int nb);
    void set_x(int new_x);
    void set_y(int new_y);
    
    std::ostream& print(std::ostream& out) const;

    friend std::ostream& operator<<(std::ostream& out, const Ville& v) { return v.print(out); }
    
};


#endif