/*
 * Functions.cpp
 *
 *  Last edited on: Nov 20, 2019
 *      Author: Elijah Weske
 *	
 *  Created by: Keith Perkins
 */

#include "./includes/Functions.h"
#include "./includes/Smalltalk.h"
#include "./includes/Smalltalk_American.h"
#include "./includes/ST_American_DonutEnthusiest.h"
#include "./includes/Smalltalk_Brit.h"
#include "./includes/Watch.h"
#include "./includes/constants.h"

//create a vector with appropriate numbers of Smalltalk_Brit,Smalltalk_American and ST_American_DonutEnthusiest
//objects using unique pointers. 
//Watches are given sequentially starting with first person in the vector until 
//all watches given or everyone has a watch (case where more watches than people)
//Since we are using c++11 returning this vector by value is fine since the 
//compiler will move the vector on return rather than recreate it (this means there is no copy penalty)
std::vector<std::unique_ptr<Smalltalk>> getPeople(int numBrit, int numAmerican,
		int numAmericanDonutEnthusiest, int numWatches) {
			
	//create a temp_vector to hold SmallTalk unique pointers
	std::vector<std::unique_ptr<Smalltalk>> temp_vector;
	
	//add Brits to temp_vector
	for (int i = 0; i < numBrit; i++) {
		temp_vector.push_back(std::unique_ptr<Smalltalk_Brit>(new Smalltalk_Brit(i)));
	}
	
	//add Americans to temp_vector
	for (int i = 0; i < numAmerican; i++) {
		temp_vector.push_back(std::unique_ptr<Smalltalk_American>(new Smalltalk_American(i)));
	}
	
	//add American Donut Enthusiest to temp_vector
	for (int i = 0; i < numbAmericanDonutEnthusiest; i++) {
		temp.push_back(std::unique_ptr<ST_American_DonutEnthusiest>(new ST_American_DonutEnthusiest(i)));
	}
	
	//total number of people for easy comparison with number of watches
	int numPeople = numBrit + numAmerican + numAmericanDonutEnthusiest;
	
	// if there are more watches than people, set watches to people.
	if (numWatches > numPeople){
		numWatches = numPeople;
	}
	
	//Watches are given sequentially starting with first person in the vector until 
	//all watches given or everyone has a watch (case where more watches than people)
	//create and give watches to everyone
	for (int i = 0; i < numPeople; i++){
		temp_vector[i]->giveWatch(new Watch());
	}
	
	//return the vector
	return temp_vector;
}
