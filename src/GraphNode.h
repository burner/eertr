#include <vector>
#include <string>
#include "prim/Vec3f.h"
#include "ObjIns.h"
#ifndef GRAPHNODE
#define GRAPHNODE
class GraphNode {
	protected:
		//SceneGraph variable
		std::vector<GraphNode*> childs;
		std::vector<ObjIns*> objects;

		//Object Varibale
		Vec3f *position;
		Vec3f *rotation;
		ObjIns *mesh;

	public:
		GraphNode *parent;
		GraphNode(GraphNode *parent, Vec3f *position, Vec3f *rotation, ObjIns *mesh);
		GraphNode(GraphNode *parent, Vec3f *position, Vec3f *rotation);
		GraphNode();
		~GraphNode();
		void insertChild(GraphNode *child);
		void removeChild(GraphNode *child);
		void insertObjIns(ObjIns *obj);
		void print();
		virtual void render();
};
#endif
