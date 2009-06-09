#include "EertXMLParse.h"

void EertXMLParse::determineType(std::string line) {
	std::string type;
	int i = 0;
	//get rid of all blank 
	while(line.at(i) == ' ' || line.at(i) == '\t') i++;
	//get rid of the <
	if(line.at(i) == '<') i++;
	//read the type
	while(line.at(i) != ' ') type.push_back(line.at(i));
	
	if(type.compare("objIns")) {
		//parse an obj xml
		parseObjIns(line);
	} else if(type.compare("graphNode")) {
	
	} else if(type.compare("graphRoot")) {
	
	}
}

void EertXMLParse::parseObjIns(std::string line) {

}