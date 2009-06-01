#include "ESDLRender.h"

#ifndef ESDLEDITORRENDER
#define ESDLEDITORRENDER
class ESDLEditorRender : public ESDLRender {
	public:
		ESDLEditorRender(int x, int y);
		bool run();
};
#endif