#include "pch.h"
#include "Utility.h"
#include "FileLogger.h"
#include "Genetics.h"
#include "Simulation.h"

/*
#define std std::
#define cout std cout<<
#define endl cout'\n';
*/


int main()
{

	int nrOfGenerations = 100;
	int nrSubjects = 10;
	int nrInstructions = 5;
	int baseMutationChanche = 0;
	int defaultScore = 1;
	
	Simulation sim(nrOfGenerations, nrSubjects, nrInstructions, baseMutationChanche, defaultScore);
	sim.Simulate();

	for (int i = 0; i < sim.averageFitnessPerGen.size(); i++)
		std::cout << sim.averageFitnessPerGen[i] << ' ';
	
	std::getchar();
	return 0;
}
