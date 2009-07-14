#include "EertXMLParse.h"

EertXMLParse::EertXMLParse(std::string filename) {
	std::cout<<"EertXMLParse Constructor Entry"<<std::endl;
	std::cout<<"Trying to parse "<<filename<<std::endl;
	parse(filename);
	std::cout<<"EertXMLParse Constructor Exit"<<std::endl;
}

void EertXMLParse::parse(std::string& filename) {
	std::ifstream ifs(filename.c_str());
	std::string line;
	std::string type;
	int i = 0;
	//global loop
	while(getline(ifs, line)) {
		std::cout<<line<<std::endl;
		//get rid of all blank 
		while(line.at(i) == ' ' || line.at(i) == '\t') i++;
		//read the type
		while(line.at(i) != ' ' && line.at(i) != '>' && line.at(i) != '\n') {
			//std::cout<<line.at(i)<<std::endl;
			type.push_back(line.at(i)); 
			i++;
		}
		
		std::cout<<"parse Type "<<type<<std::endl;
		if(!type.compare("<objIns")) {
			//parse an obj xml
			parseObjIns(line, i);
		} else if(!type.compare("<graphNode")) {
			GraphNode *tmp = parseGraphNode(line, i);
			currentNode.top()->insertChild(tmp);
			currentNode.push(tmp);
		} else if(!type.compare("</grpahNode>")) {
			currentNode.pop();
		} else if(!type.compare("<graphRoot")) {
			std::cout<<"Start prase graphRoot"<<std::endl;
			GraphRoot *tmp = parseGraphRoot(line, i);
			this->root = tmp;
			if(currentNode.empty()) {
				currentNode.push(tmp);
			} else {
				std::cout<<"Another GraphRoot has been assigned previously"<<std::endl;
				exit(-1);
			}
		} else if(!type.compare("</graphRoot>")) {
			break;
		}
		type.clear();
		i = 0;
	}
}

GraphNode* EertXMLParse::parseGraphNode(std::string& line, int& i) {
	std::string *parsedAttri;
	std::string *parsedValue;
	float posX, posY, posZ;
	float rotX, rotY, rotZ;
	
	while(true) {
		//std::cout<<"parseGraphNode1"<<std::endl;
		parsedAttri = new std::string;
		parsedValue = new std::string;
		while(line.at(i) == ' ' || line.at(i) == '\t') {
			if(line.at(i) == '\n') { 
				getline(*inputFileStream, curLine);
				i = 0;
			} else if(line.at(i) == '>') {
				return new GraphNode(currentNode.top(), 
					new Vec3f(posX, posY, posZ), 
					new Vec3f(rotX, rotY, rotZ));
			} else {
				i++;
			}
		}
		while(line.at(i) != '=') {
			parsedAttri->push_back(i);
			i++;
		}
		i++;
		if(line.at(i) == '>') {
			return new GraphNode(currentNode.top(), 
				new Vec3f(posX, posY, posZ), 
				new Vec3f(rotX, rotY, rotZ));
		}
		while(line.at(i) != ' ' || line.at(i) != '\n' || line.at(i) != '\t' || line.at(i) != '>') {
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
		while(line.at(i) != ' ' || line.at(i) != '>') {
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
	
	//eat the > 
	i++;
	
	return toRet;
}