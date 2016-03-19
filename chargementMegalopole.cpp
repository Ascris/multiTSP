/*
 * Copyright 2016 <copyright holder> <email>
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 */

#include "chargementMegalopole.h"

using namespace std;

chargementMegalopole::chargementMegalopole()
{

}

chargementMegalopole::chargementMegalopole(std::string fichierData, Megalopole& megalopolis)
{
    //fichier à prendre en compte
    ifstream fichier(fichierData);
    if(fichier)
    {
	string ligne;
	int nbLignes = 0;
	bool get_cities= false;
	int taille_instance= 0;
	while(getline(fichier, ligne)){
	    int tailleLigne = 0;
	    istringstream line(ligne);
	    string mot;
	    
	    while(line >> mot){
		if("NODE_COORD_SECTION" == mot) get_cities= true;
		++tailleLigne;
	    }
	    
	    if(2 == tailleLigne){
		bool dimension_ok= false;
		istringstream ligne_dim(ligne);
		string dim;
		while(ligne_dim >> dim){
		    if(dimension_ok){
			taille_instance= stoi(mot);
			dimension_ok= false;
		    }
		    if("DIMENSION:" == dim) dimension_ok= true;
		}
	    } else if (3 == tailleLigne && get_cities)
	    {
		int nb_ville, x, y, nbMots=0;
		
		istringstream line(ligne);
		string mot;
		while(line >> mot){
		    if(0 == nbMots) nb_ville= stoi(mot);
		    else if(1 == nbMots) x= stoi(mot);
		    else y= stoi(mot);
		    ++nbMots;
		}
		
		
		//creation ville et ajout dans la liste
		Ville persepolis(nb_ville, x, y);
		megalopolis.ajout_ville(persepolis);
	    
	    }
	}
    } else 
    {
	cerr << "Erreur ouverture fichier" << endl;
    } //fin lecture fichier

}
