#pragma once

#include <string>
#include <vector>
#include <ostream>

#include "Channel.h"
#include "Movie.h"
#include "Program.h"

class Box
{
private:
	std::string ownerPassword;
	std::vector<Channel*> channels;
	std::vector<Movie*> movies;
	std::vector<Movie*> viewedMovies;
	std::vector<std::vector<Program*> > recordedPrograms;
	std::vector<std::vector<Program*> > programsToBeRecorded;
	double spentMoney;

public:
	Box();
	~Box();

	void loadData();
	void saveData();

	void addToViewedMovies(Movie* movie);
	void addToMovies(Movie* movie);
	void addToChannels(Channel* name);
	void addToRecordedPrograms(int i, Program* name);
	bool removeMovie(std::string name);
	bool removeChannel(std::string name);
	void setmoneyspent(double spentMoney);

	std::vector<Movie*> getMovies();
	std::vector<Movie*> getViewedMovies();
	std::vector<Channel*> getChannels();
	std::vector<std::vector<Program*> >* getProgramsToBeRecorded();
	std::vector<std::vector<Program*> >* getRecordedPrograms();
	double getSpentMoney();
};

