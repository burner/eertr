#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

#ifndef EERTXMLPARSE
#define EERTXMLPARSE
class EertXMLParse {
	private:
		void determineType(std::string line);
		void parseObjIns(std::string line);
	public:
		EertXMLParse(std::string filename);
};
#endif