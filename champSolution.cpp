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

#include "champSolution.h"

using namespace std;

champSolution::champSolution()
{
    
}

void champSolution::ajoutSolution(const Solution& solution)
{
    champ_solutions.push_back(solution);
}

Solution champSolution::getBestSolution() const
{
    Solution tmp_best_sol= champ_solutions[0];
    for(unsigned int i= 1; i < champ_solutions.size(); ++i){
	if(champ_solutions[i].get_obj() > tmp_best_sol.get_obj()){
	    tmp_best_sol= champ_solutions[i];
	};
    }
    
    return tmp_best_sol;
}

bool champSolution::isDominating(const Solution& sol)
{
    bool res= true;
    for(unsigned int i= 0; i < champ_solutions.size(); ++i){
	if(champ_solutions[i].get_objA() > sol.get_objA()) return false;
	if(champ_solutions[i].get_objB() > sol.get_objB()) return false;
    }
    return res;
}

void champSolution::supprAllWeakSolutions()
{
    for(unsigned int i= 0; i < champ_solutions.size(); ++i){
	if(!isDominating(champ_solutions[i])){
	    champ_solutions.erase(champ_solutions.begin()+i);
	    cout << "Suppression du faible : " << champ_solutions[i] << endl;
	}
    }
}


ostream& champSolution::print(ostream& out) const
{
    for(unsigned int i= 0; i < champ_solutions.size(); ++i){
	out << champ_solutions[i] << endl;
    }
    
    return out;
}
