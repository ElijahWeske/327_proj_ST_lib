/*
 * Functions.cpp
 *
 *  Last edited on: Nov 20, 2019
 *      Author: Elijah Weske
 *	
 *  Created on: Nov 5, 2017
 *  	Created by: Keith Perkins
 */

#include "./includes/Functions.h"
#include "./includes/Smalltalk_American.h"
#include "./includes/ST_American_DonutEnthusiest.h"
#include "./includes/Smalltalk_Brit.h"
#include "./includes/Watch.h"
#include "./includes/constants.h"

//create a vector with a brit,american, donut enthusiest using unique pointers
//use c++11 and then returning by value is fine since the compiler will move the vector
//on return rather than recreate it(if using C++11).
std::vector<std::unique_ptr<Smalltalk>> getPeople(int numBrit, int numAmerican,
		int numAmericanDonutEnthusiest, int numWatches) {
			
	//create a vector to hold SmallTalk unique pointers
	std::vector<std::unique_ptr<Smalltalk>> temp_vector;
	
	//add brits to vector
	for (int i = 0; i < numBrit; i++) {
		temp_vector.push_back(std::unique_ptr<Smalltalk_Brit>(new Smalltalk_Brit(i)));
	}
	
	//add americans  to vector
	for (int i = 0; i < numAmerican; i++) {
		temp_vector.push_back(std::unique_ptr<Smalltalk_American>(new Smalltalk_American(i)));
	}
	
	//add american donut "enthusiest"  to vector
	for (int i = 0; i < numbAmericanDonutEnthusiest; i++) {
		temp.push_back(std::unique_ptr<ST_American_DonutEnthusiest>(new ST_American_DonutEnthusiest(i)));
	}
	
	//create some watches (as long as num watches <= num people)	
	//then give the watches away to first NUM_WATCHES people in the vector
	//keep in mind that you are responsible for deleting any pointers to 
	//watches allocated on the heap when you are finished using the vector you return 
	//from this function(see Smalltalk header for hints)
	int numPeople = numBrit + numAmerican + numAmericanDonutEnthusiest;
	
	if (numWatches > numPeople){
		numWatches = numPeople;
	}
	
	for (int i = 0; i < (int)temp_vector.size(); i++){
		temp_vector[i]->giveWatch(new Watch());
	}
	
	//return your vector
	return temp_vector;
}
