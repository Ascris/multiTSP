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

#include "algorithm.h"

Chemin algorithm::voisinage(const remplissageMatrice& megA, const remplissageMatrice& megB, const Chemin& path)
{
    Chemin test(path);
    double cout_chemin_initialA= megA.evaluationCout(path.getChemin());
    double cout_chemin_initialB= megB.evaluationCout(path.getChemin());
    
    int elem= megA.get_nb_elem();
    double cout_cheminA, cout_cheminB;
    for(int i= 0; i < elem; ++i){
	for(int j= i+1; j < elem; ++j){
	    test.swap_step(i, j);
	    cout_cheminA= megA.evaluationCout(test.getChemin());
	    cout_cheminB= megB.evaluationCout(test.getChemin());
	    
	    //amelioration sur A ou sur B prise en compte (voisin dominant sur un axe)
	    if(cout_cheminA > cout_chemin_initialA || cout_cheminB > cout_chemin_initialB) return test;
	}
    }
    
    return path;
}