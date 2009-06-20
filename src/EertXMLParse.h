#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include "ObjIns.h"
#include "GraphRoot.h"
#include "GraphNode.h"

#ifndef EERTXMLPARSE
#define EERTXMLPARSE
class EertXMLParse {
	private:
		GraphRoot *root;
		GraphNode *current;
		std::ifstream *inputFileStream;
		std::string curLine;
		void parse(std::string& line);
		ObjIns* parseObjIns(std::string& line, int& i);
		GraphRoot* parseGraphRoot(std::string& line, int& i);
		GraphNode* parseGraphNode(std::string& line, int& i);
	public:
		EertXMLParse(std::string filename);
};
#endif