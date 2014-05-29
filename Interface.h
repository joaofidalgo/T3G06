#pragma once

#include "Box.h"

class Interface
{
private:
	Box* box;
public:
	Interface();
	~Interface();

	void start();
	void listMovies();
	void listUnviewedMovies();
	void listViewedMovies();
	void listChannels();
	void listProgramsToBeRecorded();
	void listPrograms(std::vector<std::vector<Program*> > programs);
	void listRecordedPrograms();
	void recordPrograms();
	void managePrograms(std::vector<std::vector<Program*> > programs);
	void sortBy();
	void Settings();
	void rentMovies();
	void manageMovies();
	void manageChannels();
	bool savePassword(std::string password);
};

