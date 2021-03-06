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

champSolution::champSolution(const champSolution& ch)
{
    champ_solutions= ch.getSolutions();
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

bool champSolution::dominationSol(const Solution& sol1, const Solution& sol2, bool maxA, bool maxB)
{
    if(0 == maxA) //on veut minimiser l'objectif A
    {
	if(0 == maxB)//on veut minimiser l'objectif B
	{
	    return (sol1.get_objA() < sol2.get_objA() && sol1.get_objB() < sol2.get_objB());
	} else //on veut maximiser l'objectif B
	{
	    return (sol1.get_objA() < sol2.get_objA() && sol1.get_objB() > sol2.get_objB());
	}
    } else //on veut maximiser l'objectif A
    {
	if(0 == maxB) //on veut minimiser l'objectif B
	{
	    return (sol1.get_objA() > sol2.get_objA() && sol1.get_objB() < sol2.get_objB());
	} else //on veut maximiser l'objectif B
	{
	    return (sol1.get_objA() > sol2.get_objA() && sol1.get_objB() > sol2.get_objB());
	}
    }
}

bool champSolution::dominationComplete(const Solution& sol, bool maxA, bool maxB)
{
    bool res= true;
    for(unsigned int i= 0; i < champ_solutions.size(); ++i){
	//si ne serait-ce qu'une solution du champ des solution domine complètement "sol", sol n'est pas dominante
	if(dominationSol(champ_solutions[i], sol, maxA, maxB)) return false;
    }
    
    return res;
}

bool champSolution::areIncomparable(const Solution& sol1, const Solution& sol2)
{
    return (((sol1.get_objA() > sol2.get_objA()) && (sol1.get_objB() < sol2.get_objB())) || 
	    ((sol1.get_objA() < sol2.get_objA()) && (sol1.get_objB() > sol2.get_objB())));
}

vector< Solution > champSolution::getFront(bool maxA, bool maxB)
{
    vector<Solution>::iterator it;
    vector<Solution> front;
    for(it= champ_solutions.begin(); it != champ_solutions.end(); ++it){
	if(dominationComplete(*it, maxA, maxB)){
	    front.push_back(*it);
	} else {
	    
	}
    }
    return front;
}

std::vector<Solution> champSolution::addSolSupprAllWeaks(vector<Solution> front, const Solution& sol, bool maxA, bool maxB)
{
    std::vector<Solution> res;
    for(unsigned int i= 0; i < front.size(); ++i){
	if(dominationSol(sol, front[i], maxA, maxB)){
// 	    solution dominee, pas d'ajout
	} else {
	    res.push_back(front[i]);
	}
    }
    res.push_back(sol);
    
    return res;
}


bool champSolution::wouldBeDominated(const vector< Solution >& ens_sol, const Solution& sol, int maxA, int maxB)
{
    bool res= false;
    for(unsigned int i= 0; i < ens_sol.size(); ++i){
	if(dominationSol(ens_sol[i], sol, maxA, maxB)) return true;
    }
    
    return res;
}

vector< Solution > champSolution::buildingFront(bool maxA, bool maxB)
{
    vector<Solution> front;
    vector<Solution>::iterator it;
    for(it= champ_solutions.begin(); it != champ_solutions.end(); ++it){
	if(front.empty()) front.push_back(*it);
	if(!wouldBeDominated(front, *it, maxA, maxB)) //la solution it peut etre ajoutee au front
	{
// 	    front.push_back(*it);
	    //supprimer les solutions devenues faibles !
	    front= addSolSupprAllWeaks(front, (*it), maxA, maxB);
	}
	
    }
    
    return front;
}



ostream& champSolution::print(ostream& out) const
{
    for(unsigned int i= 0; i < champ_solutions.size(); ++i){
	out << champ_solutions[i] << endl;
    }
    
    return out;
}
