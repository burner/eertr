#include <iostream>
#include <fstream>
#include <stdlib.h>

#ifndef EERTXMLPARSE
#define EERTXMLPARSE
class EertXMLParse {
	private:
		void determineType(std::string line);
		void parseObj(std::string line);
	public:
		EertXMLParse(std::string filename);
};
#endif