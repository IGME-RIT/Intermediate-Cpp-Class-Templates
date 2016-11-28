/*
Class Templates
(c) 2016
Author: David Erbelding
Written under the supervision of David I. Schwartz, Ph.D., and
supported by a professional development seed grant from the B. Thomas
Golisano College of Computing & Information Sciences
(https://www.rit.edu/gccis) at the Rochester Institute of Technology.
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.
This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <iostream>
#include <string>
#include <vector>
#include "../header/pair.h"


// Start of main function
int main() 
{
    {
        // Creating an object from a template class is easy:
        // use <types> to declare the type you want it to be.

        // The types can be the same:
        Pair<int, int> testPair = Pair<int, int>(2, 3);                                         // This is a template class, (class created by a template) not to be confused
        std::cout << testPair << std::endl;                                                     // with class template (template used to create the class)
                                                                                                // The first time a template class is used, the compiler has to create a
        // or different.                                                                        // class definition, after that, it reuses the previous one.
        Pair<int, std::string> testPair2 = Pair<int, std::string>(6, "Help, I'm trapped in a computer!");
        std::cout << testPair2 << std::endl;
    }
    std::cin.get();


    {
        // We can also create compound templated objects. Avoid doing this if possible. (It's quite ugly)
        Pair<Pair<int, std::string>, Pair<int, std::string>> compoundObject = Pair<Pair<int, std::string>, Pair<int, std::string>>(Pair<int, std::string>(4, "five"), Pair<int, std::string>(6, "seven"));


        // Some common ways to help reduce the eye-melting ugliness:
        // Use a macro to replace a longer type definition:
        #define IntString Pair<int, std::string>
        Pair<IntString, IntString> betterCompoundObject = Pair<IntString, IntString>(IntString(8, "nine"), IntString(10, "eleven"));


        // Do it again:
        #define IntStringPair Pair<IntString, IntString>
        IntStringPair evenBetterCompoundObject = IntStringPair(IntString(12, "thirteen"), IntString(14, "fifteen"));


        // Alternatively, use the auto keyword.
        // The auto keyword tells the compiler to figure out the type automatically.
        auto bestCompoundObject = Pair<IntString, IntString>(IntString(16, "seventeen"), IntString(18, "nineteen"));

        // Print out our objects using the << overload to see if they work:
        std::cout << compoundObject << std::endl;
        std::cout << betterCompoundObject << std::endl;
        std::cout << evenBetterCompoundObject << std::endl;
        std::cout << bestCompoundObject << std::endl;
    }
    std::cin.get();




    {
        // The Standard Template Library aka the STL is a core set of class templates that are standardized for all compilers.
        // vector is one of the most commonly used templates in the library.
        std::vector<IntString> candy;   // Creating a vector of pairs of ints and strings


        // vector is very similar to using an array, but resizes automatically to fit the data we put into it.
        // Add things like this:
        candy.push_back(IntString(3, "snickers"));
        candy.push_back(IntString(2, "kit-kat"));
        candy.push_back(IntString(7, "jolly-rancher"));
        
        // We can get the current number of elements in the vector with size()
        int size = candy.size();

        // vector overrides the [] operator to let you get things out just like an array:
        for (int i = 0; i < size; i++)
        {
            std::cout << candy[i] << std::endl; // Loop and print everything in the vector
        }

        // There are many other things that can be done with vector, and the STL, but that's all for this example.
    }
    std::cin.get();

    return 0;   // End Program.
}