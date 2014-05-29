#pragma once
#include <string>
#include "Utilities.h"
#include "Date.h"

class Program
{
private:
	std::string name;
	ProgramType type;
	bool recorded;
	int duration;
	Date exhibitionDate;
	long rentedTimes;
public:
	Program(std::string name, ProgramType type, bool recorded, int duration);
	~Program();

	std::string getName();
	ProgramType getType() {
		return type;
	}
	bool getRecorded() {
		return recorded;
	}
	int getDuration() {
		return duration;
	}
	long getRentedTimes() const { return rentedTimes; }
	void incrementRentedTimes();

		friend std::ostream& operator << (std::ostream& out, const Program& program) {
		out << "Name: " << program.name << "\tType: " << getProgramTypeString(program.type) << "\tDuration: " << program.duration << " mins" << std::endl;
		return out;
	}
};

