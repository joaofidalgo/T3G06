#pragma once
#include <string>

class Movie
{
private:
	std::string title;
	double cost;
	long rentedTimes;

public:
	Movie(std::string title, double cost);
	~Movie();

	std::string getTitle() const;
	long getRentedTimes() const { return rentedTimes; }
	double getCost() const { return cost; }
	void incrementRentedTimes();
};
