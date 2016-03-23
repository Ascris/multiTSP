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

#ifndef CHEMIN_H
#define CHEMIN_H

#include <stdlib.h>
#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>

class Chemin
{
private:
    std::vector<int> path;
    
public:
    Chemin();
    Chemin(const std::vector<int>& chemin);
    Chemin(int taille);
    
    std::vector<int> getChemin() const { return path; };
    int get_extremite_A() const { return path[0]; };
    int get_extremite_B() const { return path[path.size()-1]; };
    
    //retourne vrai si la ville se trouve sur le chemin
    bool isOnTheWay(int ville);
    
    //operations sur le chemin a parcourir
    void swap_step(int step1, int step2);
    //echange les places de deux villes dans le chemin
    void swap_cities(int ville1, int ville2);
    
    //echange deux villes au hasard dans le chemin
    void random_swap_step();
    
};

#endif // CHEMIN_H
