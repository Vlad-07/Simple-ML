#pragma once
#include "Utility.h"
#include "Genetics.h"
#include "FileLogger.h"

class Simulation
{
public:

	FileLogger logger;


	std::vector<Meth> v_subjects;
	std::vector<int> v_fitnesess;

	std::vector<int> averageFitnessPerGen;

	int v_maxFitness;

	int v_nrGenerations;
	int v_nrOfSubjects;
	int v_nrOfInstructionsPerSubj;
	int v_baseMutationChance;

	Simulation(int nrGens, int nrSubjects, int nrInstructions, int mutationChance, int subjDefaultScore);


	void Simulate();

	void CalculateFitnesses();

	void ReplicateSubjects();


	// Debug
	void PrintSubjInstructions();

	void PrintSubjFitnesses();
};