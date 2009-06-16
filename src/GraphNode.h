#include <vector>
#include "Vec3f.h"
#include "ObjIns.h"
#ifndef GRAPHNODE
#define GRAPHNODE
class GraphNode {
	private:
		GraphNode *parent;
	protected:
		//SceneGraph variable
		std::vector<GraphNode*> childs;

		//Object Varibale
		Vec3f *position;
		Vec3f *rotation;
		ObjIns *mesh;

	public:
		GraphNode(GraphNode *parent, Vec3f *position, Vec3f *rotation, ObjIns *mesh);
		GraphNode(GraphNode *parent, Vec3f *position, Vec3f *rotation);
		GraphNode();
		~GraphNode();
		void insertChild(GraphNode *child);
		void removeChild(GraphNode *child);
		void render();
};
#endif
