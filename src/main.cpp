#include "Eertr.h"
#include "EertXMLParse.h"

int main() {
	EertXMLParse parse("testEertXml.xet");
	Eertr *er = new Eertr(800, 1200);
	er->run();
	return 1;
}