include_directories(.)
include_directories(
	${wxWidgets_INCLUDE_DIRS})
add_executable(EERTR 
	main.cpp
	Vec3f.h Vec3f.cpp
	Tri.h Tri.cpp 
	TexCoord2f.h TexCoord2f.cpp
	ObjLoader.h ObjLoader.cpp 
	GraphNode.h GraphNode.cpp
	Obj.h 
	Eertr.h Eertr.cpp
	EertrWindow.h EertrWindow.cpp
	Timer.h Timer.cpp
	#ESDLRender.h ESDLRender.cpp
	#ESDLEditorRender.h ESDLEditorRender.cpp
	#EEditor.h EEditor.cpp
	#EEditorFrame.h EEditorFrame.cpp
	#EEditorSDLPanel.h EEditorSDLPanel.cpp
	)
target_link_libraries(EERTR
	${wxWidgets_LIBRARIES})
