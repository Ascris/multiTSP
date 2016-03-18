#include "remplissageMatrice.h"

using namespace std;

remplissageMatrice::remplissageMatrice()
{

}

remplissageMatrice::remplissageMatrice(const Megalopole& megalopolis)
{
    
    int tailleMatrice= megalopolis.get_villes().size();
    nb_elem= tailleMatrice;
    const std::vector<Ville> villes= megalopolis.get_villes();
    Ville ville_i, ville_j;
    
    //declaration tableau dynamique
    distance= new double*[tailleMatrice];
    for (int i= 0; i<tailleMatrice; ++i){
	distance[i] = new double[tailleMatrice];
    }
	
	
    for(int i= 0; i<tailleMatrice; ++i){
	ville_i= villes[i];
	for(int j= 0; j<tailleMatrice; ++j){
	    ville_j= villes[j];
	    if(i == j) //distance de ville i a elle-meme
	    {
		distance[i][j]= 0;
	    }
	    else //ville i et j differentes
	    {
		int villeI_x= ville_i.get_x();
		int villeI_y= ville_i.get_y();
		int villeJ_x= ville_j.get_x();
		int villeJ_y= ville_j.get_y();
		
		double distanceij=sqrt((villeI_x-villeJ_x)*(villeI_x-villeJ_x)+(villeI_y-villeJ_y)*(villeI_y-villeJ_y));
		distance[i][j]= distanceij;
	    }
	}
    }
}

double remplissageMatrice::getDistance(int i, int j) const
{
    return distance[i][j];
}

void remplissageMatrice::affichage()
{
    for(int i= 0; i<nb_elem; ++i){
	for(int j= 0; j<nb_elem; ++j){
	    cout << distance[i][j] << " " ;
	}
	cout << endl;
    }
}
