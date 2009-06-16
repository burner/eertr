#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include "ObjIns.h"

#ifndef EERTXMLPARSE
#define EERTXMLPARSE
class EertXMLParse {
	private:
		std::ifstream *inputFileStream;
		std::string curLine;
		void determineType(std::string line);
		ObjIns* parseObjIns(std::string line, int& i);
	public:
		EertXMLParse(std::string filename);
};
#endif