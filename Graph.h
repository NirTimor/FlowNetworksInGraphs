#pragma once
#include "Heap.h"
#include "List.h"
#include <vector>
#include "Global.h"
class Graph {
private:
	List* TheGraph;
	int GraphSize = UNINITIALIZED;
	int* d;
	int* p;
	bool* isVisited;
	int maxFlow;
	vector<int> GroupA;
	vector<int> GroupB;
public:
	int getGraphSize() const { return this->GraphSize; }
	void InitilizeGraph(int VerticlesSize, Edge* EdgesArr, int EdgesArrSize);
	List* getTheGraph() const { return this->TheGraph; }
	int GetMaxFlow() const { return this->maxFlow; }
	void MakeEmptyGraph(int n);
	bool IsAdjacent(int u, int v) const;
	List  GetAdjList(int u) const;
	int getEdgeCapacity(int u, int v) const;
	void AddEdge(int u, int v, int Capacity);
	void RemoveEdge(int u, int v);
	void setDArrToInfinity();
	void setParentsArrToMinusOne();
	void setIsVisitedToFalse();
	void SimpleBFS(int s);
	bool BFSForFF(int s, int t);
	void FordFulkersonWithBFS(int s, int t);
	void GreedyFoldFulkerson(int s, int t);
	bool Dijkstra(int s, int t);
	void DeleteGraphLists(List list);
	int Min(int x, int y);
	vector<int> getGroupA() const { return this->GroupA; }
	vector<int> getGroupB() const { return this->GroupB; }
	~Graph();
};