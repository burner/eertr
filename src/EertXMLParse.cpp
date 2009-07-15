#include "EertXMLParse.h"

EertXMLParse::EertXMLParse(std::string filename) {
	std::cout<<"EertXMLParse Constructor Entry"<<std::endl;
	std::cout<<"Trying to parse "<<filename<<std::endl;
	parse(filename);
	std::cout<<"EertXMLParse Constructor Exit"<<std::endl;
}

void EertXMLParse::parse(std::string& filename) {
	this->inputFileStream = new std::ifstream(filename.c_str());
	std::string line;
	std::string type;
	type.clear();
	int i = 0;
	//global loop
	getline(*this->inputFileStream, line);
	while(true) {
		//eat blanks and tabs
		std::cout<<line<<std::endl;
		//new line
		if(line.size() == (unsigned)i-1) {
			getline(*this->inputFileStream, line);
			i = 0;
			continue;
		}

		if(line.at(i) == ' ' || line.at(i) == '\t') {
			std::cout<<i<<" "<<line.at(i)<<" ";
			i++;
			continue;
		}
		
		while(line.at(i) != ' ' && line.at(i) != '>') {
			type.push_back(line.at(i));
			i++;
		}
		
		std::cout<<"parse Type "<<type<<std::endl;
		if(0 == type.compare("<objIns")) {
			std::cout<<"parse ObjIns in"<<std::endl;
			parseObjIns(line, i);
			std::cout<<"parse ObjIns out"<<std::endl;
		} else if(0 == type.compare("<graphNode")) {
			std::cout<<"parse GraphNode in"<<std::endl;
			GraphNode *tmp = parseGraphNode(line, i);
			currentNode.top()->insertChild(tmp);
			currentNode.push(tmp);
			std::cout<<"parse GraphNode out"<<std::endl;
		} else if(0 == type.compare("</grpahNode>")) {
			currentNode.pop();
		} else if(0 == type.compare("<graphRoot")) {
			std::cout<<"prase graphRoot in"<<std::endl;
			GraphRoot *tmp = parseGraphRoot(line, i);
			this->root = tmp;
			if(currentNode.empty()) {
				currentNode.push(tmp);
			} else {
				std::cout<<"Another GraphRoot has been assigned previously"<<std::endl;
				exit(-1);
			}
			i++;
			std::cout<<"prase graphRoot out"<<std::endl;
		} else if(0 == type.compare("</graphRoot>")) {
			break;
		}
		
		//next round
		type.clear();
	}
}

GraphNode* EertXMLParse::parseGraphNode(std::string& line, int& i) {
	std::string *parsedAttri;
	std::string *parsedValue;
	float posX, posY, posZ;
	float rotX, rotY, rotZ;
	
	while(true) {
		std::cout<<"parseGraphNode1"<<std::endl;
		parsedAttri = new std::string;
		parsedValue = new std::string;
		
		
		
		
		
		
		
		
		
		
		
		

		if(parsedAttri->compare("posX")) {
			posX = (float)atof(parsedValue->c_str());
		} else if(parsedAttri->compare("posY")) {
			posY = (float)atof(parsedValue->c_str());
		} else if(parsedAttri->compare("posZ")) {
			posZ = (float)atof(parsedValue->c_str());
		} else if(parsedAttri->compare("rotX")) {
			rotX = (float)atof(parsedValue->c_str());
		} else if(parsedAttri->compare("rotY")) {
			rotY = (float)atof(parsedValue->c_str());
		} else if(parsedAttri->compare("rotZ")) {
			rotZ = (float)atof(parsedValue->c_str());
		}
		delete(parsedAttri);
		delete(parsedValue);
		
		if(line.at(i) == '>') {
			return new GraphNode(currentNode.top(), 
				new Vec3f(posX, posY, posZ), 
				new Vec3f(rotX, rotY, rotZ));
		}
	}
	delete(parsedAttri);
	delete(parsedValue);
	
	return new GraphNode(currentNode.top(), 
		new Vec3f(posX, posY, posZ), 
		new Vec3f(rotX, rotY, rotZ));
}

GraphRoot* EertXMLParse::parseGraphRoot(std::string& line, int& i) {
	//std::cout<<"parseGraphRoot1"<<std::endl;
	i++;
	return new GraphRoot(new Vec3f(0.0, 0.0, 0.0), 
		new Vec3f(0.0, 0.0, 0.0));
}

ObjIns* EertXMLParse::parseObjIns(std::string& line, int& i) {
	//these member will be used to store things parsed
	ObjIns *toRet = new ObjIns();
	std::string *parsedAttri;
	std::string *parsedValue;
	float posX, posY, posZ;
	float rotX, rotY, rotZ;
	std::cout<<line.at(i)<<std::endl;
	while(true) {
		parsedAttri = new std::string;
		parsedValue = new std::string;
		
		if(line.size() == (unsigned)i-1) {
			getline(*this->inputFileStream, line);
			i = 0;
			continue;
		}

		if(line.at(i) == ' ' || line.at(i) == '\t') {
			std::cout<<i<<" "<<line.at(i)<<" ";
			i++;
			continue;
		}
		
		while(line.at(i) != '=') {
			parsedAttri->push_back(line.at(i));
			i++;
		}

		i++;

		while(line.at(i) != ' ' && line.at(i) != '\t') {
			parsedValue->push_back(line.at(i));
			i++;
		}

		if(parsedAttri->compare("name")) {
			toRet->name = new std::string(*parsedValue);
		} else if(parsedAttri->compare("associatedObj")) {
			toRet->associatedObj = new std::string(*parsedValue);
		} else if(parsedAttri->compare("posX")) {
			posX = (float)atof(parsedValue->c_str());
		} else if(parsedAttri->compare("posY")) {
			posY = (float)atof(parsedValue->c_str());
		} else if(parsedAttri->compare("posZ")) {
			posZ = (float)atof(parsedValue->c_str());
		} else if(parsedAttri->compare("rotX")) {
			rotX = (float)atof(parsedValue->c_str());
		} else if(parsedAttri->compare("rotY")) {
			rotY = (float)atof(parsedValue->c_str());
		} else if(parsedAttri->compare("rotZ")) {
			rotZ = (float)atof(parsedValue->c_str());
		}
		delete(parsedAttri);
		delete(parsedValue);
	}
	delete(parsedAttri);
	delete(parsedValue);

	toRet->loc = new Vec3f(posX, posY, posZ);
	toRet->rot = new Vec3f(rotX, rotY, rotZ);
	
	//std::cout<<"after objins parse"<<std::endl;
	
	//eat the > 
	i++;
	
	return toRet;
}