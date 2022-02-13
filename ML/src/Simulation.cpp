#include "pch.h"
#include "Simulation.h"

Simulation::Simulation(int nrGens, int nrSubjects, int nrInstructions, int mutationChance, int subjDefaultScore)
{
	v_nrGenerations = nrGens;
	v_nrOfSubjects = nrSubjects;
	v_nrOfInstructionsPerSubj = nrInstructions;
	v_baseMutationChance = mutationChance;



	for (int i = 0; i < v_nrOfSubjects; i++)
	{
		v_subjects.push_back(Meth(v_nrOfInstructionsPerSubj, subjDefaultScore));
		v_fitnesess.push_back(-71);
	}

	logger.InitLog(v_nrGenerations, v_nrOfSubjects);
}


void Simulation::Simulate()
{
	for (int i = 0; i < v_nrGenerations; i++)
	{
		std::cout << "Generation " << i + 1 << ":\n";

		CalculateFitnesses();
		PrintSubjFitnesses();
		ReplicateSubjects();

		int avg = Utility::AlgebricMedian(v_fitnesess);

		averageFitnessPerGen.push_back(avg);
		std::cout << '\n';


		logger.LogGen(i, avg);
	}
}

void Simulation::CalculateFitnesses()
{
	v_maxFitness = INT32_MIN;
	for (int i = 0; i < v_nrOfSubjects; i++)
	{
		v_subjects[i].v_score = v_subjects[i].v_minScore;
		v_fitnesess[i] = v_subjects[i].Calculate();
		if (v_fitnesess[i] >= v_maxFitness)
			v_maxFitness = v_fitnesess[i];
	}
}

void Simulation::ReplicateSubjects()
{
	for (int i = 0; i < v_nrOfSubjects; i++)
	{
		if (v_fitnesess[i] >= v_maxFitness / 2)
			v_subjects[i].MutateInstructions(v_baseMutationChance + v_maxFitness - v_fitnesess[i]);
		else
			v_subjects[i].RandomizeInstructions();
		v_subjects[i].generation++;
	}
}


void Simulation::PrintSubjInstructions()
{
	for (int i = 0; i < v_nrOfSubjects; i++)
	{
		std::cout << i << ":\n ";
		v_subjects[i].PrintInstructions();
		std::cout << '\n';
	}
	std::cout << '\n';
}

void Simulation::PrintSubjFitnesses()
{
	std::cout << "Fitnesess:\n";
	for (int i = 0; i < v_nrOfSubjects; i++)
	{
		std::cout << ' ' << i << ": ";
		std::cout << v_fitnesess[i] << '\n';
	}
	std::cout << '\n';
}