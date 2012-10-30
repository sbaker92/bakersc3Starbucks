#include "Starbucks.h"

class bakersc3Starbucks : public Starbucks {
public:
	virtual void build(Entry* c, int n);
    virtual Entry* getNearest(double x, double y);
};

class Node{
public:
	Node();
	Node(Entry* entry);

	Entry* data;
	Node* left;
	Node* right;
};

class Tree{
public: 
	Node* root;
};

Entry* chooseMid(Entry* stores, int n);
Node* insertX(Entry* toAdd, Node* root);
Node* insertY(Entry* toAdd, Node* root);
Node* treeBuilder(Entry* arr, int n);

Entry* nearest(double x, double y, Entry* arr, int n);