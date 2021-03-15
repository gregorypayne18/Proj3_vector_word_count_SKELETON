#include "../includes/array_functions.h"
#include "../includes/utilities.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace constants;
using namespace KP;


bool openFile(std::fstream& myfile, const std::string& myFileName,std::ios_base::openmode mode){ //("text.txt")
	myfile.open(myFileName.c_str(), mode);

	if (!myfile.is_open()){
		return false;
	}

	std::string line;
	while (!myfile.eof()){
		getline(myfile, line);
	}
	return true;
}

void closeFile(std::fstream& myfile){
	if (myfile.is_open()){
		myfile.close();
	}
}

int writetoFile(std::vector<constants::entry>  &entries, const std::string &outputfilename){

	if (entries.size() == 0){
		return FAIL_NO_ARRAY_DATA;
	}

	if (does_file_exist(outputfilename) == false){
		return FAIL_FILE_DID_NOT_OPEN;
	}

	std::ofstream myOutputFile;
	myOutputFile.open(outputfilename.c_str());

	if (!myOutputFile.is_open()){
		return FAIL_FILE_DID_NOT_OPEN;
	}

	std::string data;
	for (int i = 0; i < entries.size(); i++){
		data = entries[i].word + "   " + intToString(entries[i].number_occurences);
		myOutputFile << data << std::endl;
	}

	if (myOutputFile.is_open()){
		myOutputFile.close();
	}

	return SUCCESS;
}

