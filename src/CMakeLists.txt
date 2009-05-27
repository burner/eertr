include_directories(.)
link_directories(
	${GTKMM_LIBARY_DIRS})
include_directories(
	${GTKMM_INCLUDE_DIRS})
add_executable(EERTR Vec3f.h Vec3f.cpp Tri.h Tri.cpp ObjLoader.h ObjLoader.cpp main.cpp GraphNode.cpp GraphNode.h Obj.h EEditor.h EEditor.cpp ESDLRender.h ESDLRender.cpp)
target_link_libraries(EERTR
	${GTKMM_LIBRARIES})
