include_directories(.)
include_directories(
	${wxWidgets_INCLUDE_DIRS})
#add_executable( 
#	Vec3f.h Vec3f.cpp
#	Tri.h Tri.cpp 
#	TexCoord2f.h TexCoord2f.cpp)
	
add_library(prim SHARED
	Vec3f.h Vec3f.cpp
	Tri.h Tri.cpp 
	TexCoord2f.h TexCoord2f.cpp)
	
install_targets(/lib prim)