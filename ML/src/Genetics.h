#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <chrono>


struct Instruction
{
	int in;
	int out;

	Instruction(int in_tmp, int out_tmp);
};



class Brain
{
public:

	int Operation(Instruction instruction, int out);
};




class Meth // Subject class
{
public:

	Brain v_brain;
	std::vector<Instruction> v_instructions;
	int v_nrOfInstructions;

	int v_score;
	int v_minScore;

	int generation = 0;


	Meth(int nrInstr, int defaultScore);


	void RandomizeInstructions();

	void MutateInstructions(int rateInOneThousand);


	int Calculate();

	/*
		int CalculateOverride(int override_t)
		{
			for (int i = 0; i < 500; i++)
				v_brain.Operation(v_instructions[i], override_t);
			return override_t;
		}
	*/

	// Debug
	void PrintInstructions();
};
