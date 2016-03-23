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

#ifndef CHAMPSOLUTION_H
#define CHAMPSOLUTION_H

#include <vector>
#include <iostream>

#include "Solution.h"

class champSolution
{
private:
    std::vector<Solution> champ_solutions;
    
public:
    champSolution();
    
    std::vector<Solution> getSolutions() const { return champ_solutions; };
    
    //ajoute une nouvelle solution au champ de solutions
    void ajoutSolution(const Solution& solution);
    
    //retourne la solution ayant le meilleur objectif
    Solution getBestSolution() const;
    

    /**************************
    * FONCTIONS DE DOMINATION
    ************************/
    
    //retourne vrai si la solution 1 domine la solution 2 selon les criteres maxA et maxB
    bool dominationSol(const Solution& sol1, const Solution& sol2, bool maxA, bool maxB);
    //retourne vrai si la solution 1 est dominante dans champ_solutions selon les criteres maxA et maxB 
    bool dominationComplete(const Solution& sol, bool maxA, bool maxB);

    //retourne vrai si la sol1 domine sol2
    bool dominateStrong(const Solution& sol1, const Solution& sol2);
    bool areIncomparable(const Solution& sol1, const Solution& sol2);
    /**
     * Retourne les solutions dominantes
     * @param maxA: si 1, maximise l'objectif A, sinon le minimise
     * @param maxB: si 1, maximise l'objectif B, sinon le minimise
     * @return un vecteur de solutions dominantes
     */
    std::vector<Solution> getFront(bool maxA, bool maxB);
    
    
    
    
    //fonctions d'affichage
    std::ostream& print(std::ostream& out) const;

    friend std::ostream& operator<<(std::ostream& out, const champSolution& c)
    { return c.print(out); }
};

#endif // CHAMPSOLUTION_H
