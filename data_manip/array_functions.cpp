
#include "../includes/array_functions.h"
#include "../includes/utilities.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace constants;
namespace KP{


void clear(std::vector<constants::entry>  &entries){
	entries.clear();
}


int getSize(std::vector<constants::entry>  &entries){
		return entries.size();
}

std::string getWordAt(std::vector<constants::entry>  &entries, int i){
	if (i < entries.size()){
		return entries[i].word;
}
	else{
		return entries[entries.size() - 1].word;
	}
}

int getNumbOccurAt(std::vector<constants::entry>  &entries,int i){
	if (i < entries.size()){
		return entries[i].number_occurences;
}
	else{
		return entries[entries.size() - 1].number_occurences;
	}
}


bool processFile(std::vector<constants::entry>  &entries,std::fstream &myfstream){
	if (myfstream.is_open() == false){
		return false;
	}
	std::string line;
		while (!myfstream.eof()){
			processLine(entries, line);
		}

	}



void processLine(std::vector<constants::entry>  &entries,std::string &myLine){
		std::stringstream sstream(myLine);
		std::string tempWord;
		while (getline(sstream, tempWord, CHAR_TO_SEARCH_FOR)){
			processToken(entries, tempWord);
		}
	}



void processToken(std::vector<constants::entry>  &entries,std::string &token){
	strip_unwanted_chars(token);
	if (token.empty()){
		return;
	}
	for (int i=0; i<entries.size(); i++){
		if(entries[i].word == token){
			entries[i].number_occurences += 1;
		}
		else{
			constants::entry newEntry;
			newEntry.word = token;
			newEntry.number_occurences = 1;
			entries.push_back(newEntry);
		}
	}
}

void sort(std::vector<constants::entry>  &entries, constants::sortOrder so){
	//NONE,ASCENDING, DESCENDING, NUMBER_OCCURRENCES

	switch(so){

	case NONE:
		break;

	case ASCENDING:
		// sort(entries.word.begin(), entries.word.end())
		break;

	case DESCENDING:
		// sort(entries.word.begin(), entries.word.end())
		break;

	case NUMBER_OCCURRENCES:
		// sort(entries.number_occurences.begin(), entries.number_occurences.end())
		break;

	default:
		break;

}
	return;
}
}

	//entries[i].number_occurences with some sorting function/loop


