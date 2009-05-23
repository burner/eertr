#include <vector>
#include "Vec3f.h"
#include "Obj.h"
#ifndef GRAPHNODE
#define GRAPHNODE
class GraphNode {
	private:
		//SceneGraph variable
		std::vector<GraphNode*> childs;
		GraphNode *parent;

		//Object Varibale
		Vec3f *position;
		Vec3f *rotation;
		Obj *mesh;

	public:
		GraphNode(GraphNode *parent, Vec3f *position, Vec3f *rotation, Obj *mesh);
		~GraphNode();
		void insertChild(GraphNode *child);
		void removeChild(GraphNode *child);
		void render();
};
#endif
