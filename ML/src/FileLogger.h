#pragma once
#include <fstream>
#include <string>
#include <chrono>
#include <ios>

class FileLogger
{
public:
	std::string v_fileName = "log.txt";

	int version = 1;
	int v_nrOfSubjects = 0;



	FileLogger();

	FileLogger(std::string fileName);


	void InitLog(int nrOfGenerations, int subjNr);

	void LogGen(int gen, int avgFitness);

	void ClearLog();
};