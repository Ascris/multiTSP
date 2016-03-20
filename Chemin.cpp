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

void Chemin::random_swap_step()
{
    int rand_step_1= rand() % path.size() + 1;
    int rand_step_2= rand() % path.size() +1;
    swap_step(rand_step_1, rand_step_2);
}
