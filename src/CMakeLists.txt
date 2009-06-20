include_directories(.)
add_subdirectory(prim)
#add_subdirectory(editor)
include_directories(
	${wxWidgets_INCLUDE_DIRS}
)
add_executable(EERTR 
	main.cpp
	ObjLoader.h ObjLoader.cpp 
	GraphNode.h GraphNode.cpp
	Obj.h Obj.cpp
	GraphRoot.h GraphRoot.cpp
	ObjIns.h ObjIns.cpp
	Eertr.h Eertr.cpp
	EertrWindow.h EertrWindow.cpp
	Timer.h Timer.cpp
	Camera.h Camera.cpp
	EertXMLParse.h EertXMLParse.cpp
)
target_link_libraries(EERTR
	${wxWidgets_LIBRARIES}
	prim
)

