#include "Program.h"


Program::Program(std::string name, ProgramType type, bool recorded, int duration)
{
	this->name = name;
	this->type = type;
	this->recorded = recorded;
	this->duration = duration;
}


Program::~Program()
{
}

std::string Program::getName(){
	return name;
}

void Program::incrementRentedTimes()
{
	rentedTimes++;
}
