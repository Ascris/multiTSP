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

#include "ecritureFichier.h"

using namespace std;

ecritureFichier::ecritureFichier()
{

}

ecritureFichier::ecritureFichier(std::string ficName, std::vector< Solution >& champ_solution)
{
    ofstream fichier(ficName, ios::out | ios::trunc);  //déclaration du flux et ouverture du fichier
        
        if(fichier)  // si l'ouverture a réussi
        {
	    vector<Solution>::iterator it;
	    for(it= champ_solution.begin(); it != champ_solution.end(); ++it){
		fichier << (*it).get_objA() << " " << (*it).get_objB() << endl;
	    
	    }
                fichier.close();  // on referme le fichier
        }
        else  // sinon
	{
                std::cerr << "Erreur à l'ouverture !" << std::endl;
	}
}
