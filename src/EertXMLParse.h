#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <stack>
#include "ObjIns.h"
#include "GraphRoot.h"
#include "GraphNode.h"

#ifndef EERTXMLPARSE
#define EERTXMLPARSE
class EertXMLParse {
	private:
		GraphRoot *root;
		std::stack<GraphNode*> currentNode;
		std::ifstream *inputFileStream;
		std::string curLine;
		void parse(std::string& filename);
		ObjIns* parseObjIns(std::string& line, int& i);
		GraphRoot* parseGraphRoot(std::string& line, int& i);
		GraphNode* parseGraphNode(std::string& line, int& i);
	public:
		EertXMLParse(std::string filename);
		void print();
};
#endif