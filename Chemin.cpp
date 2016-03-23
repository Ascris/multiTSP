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

#include "Chemin.h"

Chemin::Chemin()
{

}

Chemin::Chemin(const std::vector< int >& chemin)
{
    for(unsigned int i= 0; i < chemin.size(); ++i){
	path.push_back(chemin[i]);
    }
}

Chemin::Chemin(int taille)
{
    for(int i= 1; i <= taille; ++i){
	path.push_back(i);
    }
}



void Chemin::swap_step(int step1, int step2)
{
    int tmp= path[step1];
    path[step1]= path[step2];
    path[step2]= tmp;
    
}

bool Chemin::isOnTheWay(int ville)
{
    return (std::find(path.begin(), path.end(), ville) != path.end());
}


void Chemin::swap_cities(int ville1, int ville2)
{
    int ind_v1= -1, ind_v2= -1;
    if(isOnTheWay(ville1) && isOnTheWay(ville2)) //les villes sont bien sur le chemin
    {
	for(unsigned int i= 0; i < path.size(); ++i){
	    if(ville1 == path[i]) ind_v1= i;
	    if(ville2 == path[i]) ind_v2= i;
	}
	swap_step(ind_v1, ind_v2);
	
    } else {
	std::cerr << "Erreur : " << ville1 << " ou " << ville2 << " n'est pas presente dans le chemin !" << std::endl;
    }
}


void Chemin::random_swap_step()
{
    int rand_step_1= rand() % path.size() + 1;
    int rand_step_2= rand() % path.size() + 1;
    swap_step(rand_step_1, rand_step_2);
}

std::ostream& Chemin::print(std::ostream& out) const
{
    for(unsigned int i= 0; i < path.size(); ++i){
	out << path[i] << " ";
    }
    return out;
}

