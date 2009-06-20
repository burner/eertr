#include "EertXMLParse.h"

void EertXMLParse::parse(std::string& line) {
	std::string type;
	int i = 0;
	//get rid of all blank 
	while(line.at(i) == ' ' || line.at(i) == '\t') i++;
	//read the type
	while(line.at(i) != ' ' || line.at(i) != '>') {
		type.push_back(line.at(i)); 
		i++;
	}
	
	if(type.compare("<objIns")) {
		//parse an obj xml
		parseObjIns(line, i);
	} else if(type.compare("<graphNode")) {
		this->current->insertChild(parseGraphNode(line, i));
		this->current = this->current->parent;
	} else if(type.compare("</grpahNode")) {
	
	} else if(type.compare("<graphRoot")) {
		this->root = parseGraphRoot(line, i);
	} else if(type.compare("</graphRoot")) {
	
	}
}

GraphNode* EertXMLParse::parseGraphNode(std::string& line, int& i) {
	std::string *parsedAttri;
	std::string *parsedValue;
	float posX, posY, posZ;
	float rotX, rotY, rotZ;
	
	while(true) {
		parsedAttri = new std::string;
		parsedValue = new std::string;
		while(line.at(i) == ' ' || line.at(i) == '\t') {
			if(line.at(i) == '\n') { 
				getline(*inputFileStream, curLine);
				i = 0;
			}
			if(line.at(i) == '/') break;
			else i++;
		}
		if(line.at(i) == '/') break;
		while(line.at(i) != '=') {
			parsedAttri->push_back(i);
			i++;
		}
		i++;
		while(line.at(i) != ' ') {
			parsedValue->push_back(i);
			i++;
		}

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
	}
	delete(parsedAttri);
	delete(parsedValue);
	
	return new GraphNode(this->current, 
		new Vec3f(posX, posY, posZ), 
		new Vec3f(rotX, rotY, rotZ));
}

GraphRoot* EertXMLParse::parseGraphRoot(std::string& line, int& i) {
	std::string *parsedAttri;
	std::string *parsedValue;
	float posX, posY, posZ;
	float rotX, rotY, rotZ;
	
	while(true) {
		parsedAttri = new std::string;
		parsedValue = new std::string;
		while(line.at(i) == ' ' || line.at(i) == '\t') {
			if(line.at(i) == '\n') { 
				getline(*inputFileStream, curLine);
				i = 0;
			}
			if(line.at(i) == '/') break;
			else i++;
		}
		if(line.at(i) == '/') break;
		while(line.at(i) != '=') {
			parsedAttri->push_back(i);
			i++;
		}
		i++;
		while(line.at(i) != ' ') {
			parsedValue->push_back(i);
			i++;
		}

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
	}
	delete(parsedAttri);
	delete(parsedValue);
	
	return new GraphRoot(new Vec3f(posX, posY, posZ), 
		new Vec3f(rotX, rotY, rotZ));
}

ObjIns* EertXMLParse::parseObjIns(std::string& line, int& i) {
	//these member will be used to store things parsed
	ObjIns *toRet = new ObjIns();
	std::string *parsedAttri;
	std::string *parsedValue;
	float posX, posY, posZ;
	float rotX, rotY, rotZ;
	
	while(true) {
		parsedAttri = new std::string;
		parsedValue = new std::string;
		while(line.at(i) == ' ' || line.at(i) == '\t') {
			if(line.at(i) == '\n') { 
				getline(*inputFileStream, curLine);
				i = 0;
			}
			if(line.at(i) == '/') break;
			else i++;
		}
		if(line.at(i) == '/') break;
		while(line.at(i) != '=') {
			parsedAttri->push_back(i);
			i++;
		}
		i++;
		while(line.at(i) != ' ') {
			parsedValue->push_back(i);
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
	
	return toRet;
}