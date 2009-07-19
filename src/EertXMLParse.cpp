#include "EertXMLParse.h"

EertXMLParse::EertXMLParse(std::string filename) {
	std::cout<<"Trying to parse "<<filename;
	parse(filename);
	std::cout<<" done"<<std::endl;
}

void EertXMLParse::print() {
	std::cout<<"Printing szene"<<std::endl;
	this->root->print();
	std::cout<<"Printing szene done"<<std::endl;
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
		//std::cout<<line<<std::endl;
		//new line
		//std::cout<<"lineSize "<<line.size()<<" i "<<i<<std::endl;
		if(line.size() <= (unsigned)i) {
			getline(*this->inputFileStream, line);
			i = 0;
			continue;
		}

		if(line.at(i) == ' ' || line.at(i) == '\t') {
			//std::cout<<i<<" "<<line.at(i)<<" ";
			i++;
			continue;
		}
		
		while(line.at(i) != ' ' && line.at(i) != '>') {
			type.push_back(line.at(i));
			i++;
		}
		
		//std::cout<<"parse Type "<<type<<std::endl;
		if(0 == type.compare("<objIns")) {
			//std::cout<<"parse ObjIns in"<<std::endl;
			currentNode.top()->insertObjIns(parseObjIns(line, i));
			//std::cout<<"parse ObjIns out"<<std::endl;
		} else if(0 == type.compare("<graphNode")) {
			//std::cout<<"parse GraphNode in"<<std::endl;
			GraphNode *tmp = parseGraphNode(line, i);
			currentNode.top()->insertChild(tmp);
			currentNode.push(tmp);
			//std::cout<<"parse GraphNode out"<<std::endl;
		} else if(0 == type.compare("</graphNode")) {
			i++;
			currentNode.pop();
		} else if(0 == type.compare("<graphRoot")) {
			//std::cout<<"prase graphRoot in"<<std::endl;
			GraphRoot *tmp = parseGraphRoot(line, i);
			this->root = tmp;
			if(currentNode.empty()) {
				currentNode.push(tmp);
			} else {
				std::cout<<"Another GraphRoot has been assigned previously"<<std::endl;
				exit(-1);
			}
			i++;
			//std::cout<<"prase graphRoot out"<<std::endl;
		} else if(0 == type.compare("</graphRoot")) {
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
	parsedAttri = new std::string;
	parsedValue = new std::string;
	
	bool nextTime = true;
	while(true && nextTime) {
		if(line.size() == (unsigned)i-1) {
			getline(*this->inputFileStream, line);
			i = 0;
			continue;
		}

		if(line.at(i) == ' ' || line.at(i) == '\t') {
			//std::cout<<i<<" "<<line.at(i)<<" ";
			i++;
			continue;
		}
		
		while(line.at(i) != '=') {
			parsedAttri->push_back(line.at(i));
			i++;
		}

		i++;
		
		//std::cout<<"lineSize "<<line.size()<<std::endl;
		while(line.size() > (unsigned)i && line.at(i) != ' ' && line.at(i) != '\t' && line.at(i) != '>' ) {
			parsedValue->push_back(line.at(i));
			i++;
		}

		if(line.size() <= (unsigned)i) {
			getline(*this->inputFileStream, line);
			i = 0;
		} else {
			if(line.at(i) == '>')
				nextTime = false;
		}

		if(0 == parsedAttri->compare("posX")) {
			posX = (float)atof(parsedValue->c_str());
		} else if(0 == parsedAttri->compare("posY")) {
			posY = (float)atof(parsedValue->c_str());
		} else if(0 == parsedAttri->compare("posZ")) {
			posZ = (float)atof(parsedValue->c_str());
		} else if(0 == parsedAttri->compare("rotX")) {
			rotX = (float)atof(parsedValue->c_str());
		} else if(0 == parsedAttri->compare("rotY")) {
			rotY = (float)atof(parsedValue->c_str());
		} else if(0 == parsedAttri->compare("rotZ")) {
			rotZ = (float)atof(parsedValue->c_str());
		}
		parsedAttri->clear();
		parsedValue->clear();
	}
	delete(parsedAttri);
	delete(parsedValue);
	
	i++;
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
	//std::cout<<line.at(i)<<std::endl;
	parsedAttri = new std::string;
	parsedValue = new std::string;
	bool nextTime = true;
	while(true && nextTime) {
		if(line.size() <= (unsigned)i) {
			getline(*this->inputFileStream, line);
			i = 0;
			continue;
		}

		if(line.at(i) == ' ' || line.at(i) == '\t') {
			//std::cout<<i<<" "<<line.at(i)<<" ";
			i++;
			continue;
		}
		
		while(line.at(i) != '=') {
			parsedAttri->push_back(line.at(i));
			i++;
		}

		i++;
		
		//std::cout<<"lineSize "<<line.size()<<std::endl;
		while(line.size() > (unsigned)i &&line.at(i) != ' ' && line.at(i) != '\t' && line.at(i) != '/') {
			parsedValue->push_back(line.at(i));
			i++;
		}
		if(line.size() > (unsigned)i) {
			if(line.at(i) == '/')
				nextTime = false;
		}

		if(0 == parsedAttri->compare("name")) {
			toRet->name = new std::string(*parsedValue);
		} else if(0 == parsedAttri->compare("associatedObj")) {
			toRet->associatedObj = new std::string(*parsedValue);
		} else if(0 == parsedAttri->compare("posX")) {
			posX = (float)atof(parsedValue->c_str());
		} else if(0 == parsedAttri->compare("posY")) {
			posY = (float)atof(parsedValue->c_str());
		} else if(0 == parsedAttri->compare("posZ")) {
			posZ = (float)atof(parsedValue->c_str());
		} else if(0 == parsedAttri->compare("rotX")) {
			rotX = (float)atof(parsedValue->c_str());
		} else if(0 == parsedAttri->compare("rotY")) {
			rotY = (float)atof(parsedValue->c_str());
		} else if(0 == parsedAttri->compare("rotZ")) {
			rotZ = (float)atof(parsedValue->c_str());
			break;
		}
		parsedAttri->clear();
		parsedValue->clear();
	}
	delete(parsedAttri);
	delete(parsedValue);

	toRet->loc = new Vec3f(posX, posY, posZ);
	toRet->rot = new Vec3f(rotX, rotY, rotZ);
	
	//std::cout<<"after objins parse"<<std::endl;
	
	//eat the > 
	i+=3;
	
	return toRet;
}