#include "pch.h"
#include "Genetics.h"

#pragma region Instruction

Instruction::Instruction(int in_tmp, int out_tmp)
{
	in = in_tmp;
	out = out_tmp;
}

#pragma endregion


#pragma region Brain

int Brain::Operation(Instruction instruction, int out)
{
	switch (instruction.in)
	{
	case 1:
		//			cout out << " + 2 = ";
		out += 2;
		//			cout  out << '\n';
		break;
	case 2:
		//			cout out << " - 1 = ";
		out -= 1;
		//			cout out << '\n';
		break;
	case 3:
		//			cout out << " * 2 = ";
		out *= 2;
		//			cout out << '\n';
		break;
	case 4:
		//			cout out << " / 2 = ";
		out /= 2;
		//			cout out << '\n';
		break;
	case 5:
		//			cout out << " ^ 2 = ";
		out *= out;
		//			cout out << '\n';
		break;
	case 6:
		//			cout out << " = 0\n";
		out = 0;
		break;
	default:
		break;
	}

	return out;
}

#pragma endregion


#pragma region Meth

Meth::Meth(int nrInstr, int defaultScore)
{
	v_nrOfInstructions = nrInstr;
	v_minScore = defaultScore;

	for (int i = 0; i < v_nrOfInstructions; i++)
		v_instructions.push_back(Instruction(0, 0));

	RandomizeInstructions();
}



void Meth::RandomizeInstructions()
{
	std::default_random_engine generator;
	std::uniform_int_distribution<int> randomEngine(1, 6);
	generator.seed(std::chrono::system_clock::now().time_since_epoch().count());

	for (int i = 0; i < v_nrOfInstructions; i++)
		v_instructions[i].in = randomEngine(generator);
}

void Meth::MutateInstructions(int rateInOneThousand)
{
	std::default_random_engine generator;
	std::uniform_int_distribution<int> randomEngine(1, 1000);
	generator.seed(std::chrono::system_clock::now().time_since_epoch().count());

	if (randomEngine(generator) <= rateInOneThousand)
	{
		std::uniform_int_distribution<int> randomEngine2(1, v_nrOfInstructions - 1);
		std::uniform_int_distribution<int> randomEngine3(1, 6);

		v_instructions[randomEngine2(generator)].in = randomEngine3(generator);
	}
}


int Meth::Calculate()
{
	for (int i = 0; i < v_nrOfInstructions; i++)
		v_score = v_brain.Operation(v_instructions[i], v_score);
	return v_score;
}


void Meth::PrintInstructions()
{
	std::cout << "Instructions:\n ";
	for (int i = 0; i < v_nrOfInstructions; i++)
		std::cout << v_instructions[i].in;
	std::cout << '\n';
}

#pragma endregion
