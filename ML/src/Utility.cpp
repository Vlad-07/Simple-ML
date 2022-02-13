#include "pch.h"
#include "Utility.h"


int Utility::AlgebricMedian(std::vector<int> numbers)
{
	if (numbers.size() == 0) return INT32_MIN;

	int sum = 0;
	
	for (int i = 0; i < numbers.size(); i++)
		sum += numbers[i];

	return floor(sum / numbers.size());
}