#include "Box.h"
#include "Utilities.h"

#include <iostream>
#include <string>
#include <fstream>

Box::Box()
{
	channels.clear();
	movies.clear();
	viewedMovies.clear();
	recordedPrograms.clear();
	programsToBeRecorded.clear();
	spentMoney = 0;
}


Box::~Box()
{
}

void Box::loadData()
{
	// START reading movies
	std::ifstream fin;
	fin.open("data/movies.txt");
	if (!fin) {
		std::cout << "Could not open movies.txt" << std::endl;
		std::cin.get();
		exit(-1);
	}

	int numMovies;
	fin >> numMovies;
	for (int i = 0; i < numMovies; i++) {
		std::string movieTitle;
		fin >> movieTitle;

		movies.push_back(new Movie(movieTitle, 10));
	}
	fin.close();
	// STOP reading movies

	// START reading channels
	fin.open("data/channels.txt");
	if (!fin) {
		std::cout << "Could not open channels.txt" << std::endl;
		std::cin.get();
		exit(-1);
	}

	int  numChannels;
	fin >> numChannels;
	for (int i = 0; i < numChannels; i++) {
		std::string channelName;
		fin >> channelName;

		channels.push_back(new Channel(channelName));
	}
	fin.close();
	// STOP reading channels

	// START reading programs to be recorded
	fin.open("data/toBeRecorded.txt");
	if (!fin) {
		std::cout << "Could not open toBeRecorded.txt" << std::endl;
		std::cin.get();
		exit(-1);
	}

	for (unsigned int i = 0; i < channels.size(); i++) {
		int numToBeRecorded;
		fin >> numToBeRecorded;

		std::vector<Program*> temp;
		for (int j = 0; j < numToBeRecorded; j++) {
			int duration, type, hour, min;
			std::string title;

			fin >> duration >> min >> hour >> type >> title;
			temp.push_back(new Program(title, (ProgramType)type, 0, duration));
		}
		programsToBeRecorded.push_back(temp);
	}
	fin.close();
	// STOP reading programs to be recorded

	// START reading programs recorded
	fin.open("data/recorded.txt");
	if (!fin) {
		std::cout << "Could not open recorded.txt" << std::endl;
		std::cin.get();
		exit(-1);
	}

	for (unsigned int i = 0; i < channels.size(); i++) {
		int numRecorded;
		fin >> numRecorded;

		std::vector<Program*> temp;
		for (int j = 0; j < numRecorded; j++) {
			int duration, type, min, hour;
			std::string title;

			fin >> duration >> min >> hour >> type >> title;
			temp.push_back(new Program(title, (ProgramType)type, 1, duration));
		}
		recordedPrograms.push_back(temp);
	}
	fin.close();
	// STOP reading programs recorded
}

void Box::saveData()
{
	// START saving movies
	std::ofstream fout;
	fout.open("data/movies.txt");
	if (!fout) {
		std::cout << "Could not open movies.txt" << std::endl;
		std::cin.get();
		exit(-1);
	}

	fout << getMovies().size() << std::endl;
	for (unsigned int i = 0; i < getMovies().size(); i++)
		fout << getMovies()[i]->getTitle() << std::endl;
	fout.close();
	// STOP saving movies

	// START saving channels
	fout.open("data/channels.txt");
	if (!fout) {
		std::cout << "Could not open channels.txt" << std::endl;
		std::cin.get();
		exit(-1);
	}

	fout << getChannels().size() << std::endl;
	for (unsigned int i = 0; i < getChannels().size(); i++)
		fout << getChannels()[i]->getName() << std::endl;
	fout.close();
	// STOP saving channels

	// START saving programs to be recorded
	fout.open("data/toBeRecorded.txt");
	if (!fout) {
		std::cout << "Could not open toBeRecorded.txt" << std::endl;
		std::cin.get();
		exit(-1);
	}

	for (unsigned int i = 0; i < channels.size(); i++) {
		fout << (*getProgramsToBeRecorded())[i].size() << std::endl;

		for (unsigned int j = 0; j < (*getProgramsToBeRecorded())[i].size(); j++) {
			Program* program = (*getProgramsToBeRecorded())[i][j];

			fout << program->getDuration() << " " << 0 << " " << 0 << " " << program->getType() << " " << program->getName() << std::endl;
		}
	}
	fout.close();
	// STOP saving programs to be recorded

	// START saving programs recorded
	fout.open("data/recorded.txt");
	if (!fout) {
		std::cout << "Could not open recorded.txt" << std::endl;
		std::cin.get();
		exit(-1);
	}

	for (unsigned int i = 0; i < channels.size(); i++) {
		fout << (*getRecordedPrograms())[i].size() << std::endl;

		for (unsigned int j = 0; j < (*getRecordedPrograms())[i].size(); j++) {
			Program* program = (*getRecordedPrograms())[i][j];

			fout << program->getDuration() << " " << 0 << " " << 0 << " " << program->getType() << " " << program->getName() << std::endl;
		}
	}
	fout.close();
	// STOP saving programs recorded

	//START saving viewed programs
	fout.open("data/viewedMovies.txt");
	if (!fout) {
		std::cout << "Could not open viewedMovies.txt" << std::endl;
		std::cin.get();
		exit(-1);
	}

	fout << getViewedMovies().size() << std::endl;
	for (unsigned int i = 0; i < getViewedMovies().size(); i++)
		fout << getViewedMovies()[i]->getTitle() << std::endl;
	fout.close();
	//STOP saving viewed programs
}

void Box::addToViewedMovies(Movie* movie) {
	viewedMovies.push_back(movie);
}

void Box::addToMovies(Movie* movie) {
	movies.push_back(movie);
}
void Box::addToRecordedPrograms(int i, Program* program){
	recordedPrograms[i].push_back(program);
}
bool Box::removeMovie(std::string name){

	for (std::vector<Movie*>::const_iterator itr = movies.begin(); itr != movies.end(); itr++)
	if (ToLower((*itr)->getTitle()).compare(ToLower(name)) == 0) {
		std::cout << (*itr)->getTitle() << " Successfully Deleted";
		movies.erase(itr);
		return true;
	}
	return false;
}

std::vector<Movie*> Box::getMovies()
{
	return movies;
}

std::vector<std::vector<Program*> >* Box::getProgramsToBeRecorded()
{
	return &programsToBeRecorded;
}

std::vector<Movie*> Box::getViewedMovies()
{
	return viewedMovies;
}

std::vector<Channel*> Box::getChannels()
{
	return channels;
}

bool Box::removeChannel(std::string name)
{
	for (std::vector<Channel*>::const_iterator itr = channels.begin(); itr != channels.end(); itr++)
	if (ToLower((*itr)->getName()).compare(ToLower(name)) == 0) {
		std::cout << (*itr)->getName() << " Successfully Deleted";
		channels.erase(itr);
		return true;
	}
	return false;
}

void Box::addToChannels(Channel* name)
{
	channels.push_back(name);

	std::vector<Program*> temp;
	getProgramsToBeRecorded()->push_back(temp);
	getRecordedPrograms()->push_back(temp);
}

std::vector<std::vector<Program*> >* Box::getRecordedPrograms()
{
	return &recordedPrograms;
}

void Box::setmoneyspent(double spentMoney){

	this->spentMoney += spentMoney;
}

double Box::getSpentMoney(){

	return spentMoney;
}
