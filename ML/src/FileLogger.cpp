#include "pch.h"
#include "FileLogger.h"

FileLogger::FileLogger()
{}

FileLogger::FileLogger(std::string fileName)
{
	v_fileName = fileName;
}



void FileLogger::InitLog(int nrOfGenerations, int subjNr)
{
	ClearLog();

	v_nrOfSubjects = subjNr;

	auto time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	uint8_t buffSize = 30;
	char* buffer = new char[buffSize];
	ctime_s(buffer, buffSize, &time);

	std::ofstream out(v_fileName, std::ios::app);

	out << "Version: " << version << '\n';
	out << "Generations: " << nrOfGenerations << '\n';
	out << "Subjects: " << v_nrOfSubjects << '\n';
	out << "Time: " << buffer << '\n';

	delete[] buffer;
}

void FileLogger::LogGen(int gen, int avgFitness)
{
	std::ofstream out(v_fileName, std::ios::app);

	out << avgFitness << '\n';
}

void FileLogger::ClearLog()
{
	std::ofstream out(v_fileName);
	out.close();
}