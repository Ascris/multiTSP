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

#ifndef SOLUTION_H
#define SOLUTION_H

#include <ostream>

class Solution
{
private:
    double obj;
    double objB;
    double objA;

public:
    Solution();
    Solution(double obja, double objb);
    
    double get_objA() const { return objA; };
    double get_objB() const { return objB; };
    double get_obj() const { return obj; };
    
    
    std::ostream& print(std::ostream& out) const;

    friend std::ostream& operator<<(std::ostream& out, const Solution& s)
    { return s.print(out); }
};

#endif // SOLUTION_H
