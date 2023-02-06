#include "Graph.h"
void Graph::MakeEmptyGraph(int n) {
	GraphSize = n + 1;
	TheGraph = new List[GraphSize];
	d = new int[GraphSize];
	p = new int[GraphSize];
	isVisited = new bool[GraphSize];
	maxFlow = 0;
	GroupA.resize(GraphSize);
	GroupB.resize(GraphSize);
}
void Graph::InitilizeGraph(int VerticlesSize, Edge* EdgesArr, int EdgesArrSize) {
	for (int i = 0; i < (EdgesArrSize); i++) {
		TheGraph[EdgesArr[i].getEdgeU()].AddNodeToEnd(EdgesArr[i]);
	}
}
bool Graph::IsAdjacent(int u, int v) const {
	if (u > (GraphSize + 1) || u < 1) {
		cout << " Invalid Input!" << endl;
		exit(1);
	}
	return TheGraph[u].isOnTheList(v);
}
List Graph::GetAdjList(int u) const {
	return TheGraph[u];
}
int Graph::getEdgeCapacity(int u, int v) const {
	Node* temp = TheGraph[u].getHead();
	while(temp->getData().getEdgeV() != v) {
		temp = temp->getNext();
	}
	return temp->getData().getEdgeCapacity();
}
void Graph::AddEdge(int u, int v, int Capacity) { // need to check , if we want non directed graph maybe dont add the other edge but maybe we do need it because its residual graph
	Edge newEdge, reverseNewEdge;
	newEdge.setEdgeU(u);
	newEdge.setEdgeV(v);
	newEdge.setEdgeCapacity(Capacity);
	reverseNewEdge.setEdgeU(v);
	reverseNewEdge.setEdgeV(u);
	reverseNewEdge.setEdgeCapacity(Capacity);
	TheGraph[u].AddNodeToEnd(newEdge);
	TheGraph[v].AddNodeToEnd(reverseNewEdge);
}
void Graph::RemoveEdge(int u, int v) {
	TheGraph[u].deleteNode(v);
	TheGraph[v].deleteNode(u);
}
bool Graph::BFSForFF(int s, int t) {
	queue<int> q;
	q.push(s);
	for (int i = 0; i < GraphSize; i++) {
		if (i == s) {
			p[i] = -1;
			d[i] = 0;
		}
		else {
			p[i] = -1;
			d[i] = INT32_MAX;
		}
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		Node* temp = TheGraph[u].getHead();
		while (temp != nullptr) {
			if (d[temp->getData().getEdgeV()] == INT32_MAX && (temp->getData().getEdgeCapacity() > temp->getData().getEdgeFlow())) {
				d[temp->getData().getEdgeV()] = d[temp->getData().getEdgeU()] + 1;
				p[temp->getData().getEdgeV()] = temp->getData().getEdgeU();
				q.emplace(temp->getData().getEdgeV());
			}
			temp = temp->getNext();
		}
	}
	return (d[t] != INT32_MAX);
}
void Graph::FordFulkersonWithBFS(int s, int t) {
	int u, v;
	int curr;
	while (BFSForFF(s, t)) {
		int path_flow = INT32_MAX;
		Node* temp;
		v = t;
		while (p[v] != -1) {
			u = p[v];
			temp = TheGraph[u].getHead();
			while (temp->getData().getEdgeV() != v) {
				temp = temp->getNext();
			}
			path_flow = Min(path_flow, (temp->getData().getEdgeCapacity()-temp->getData().getEdgeFlow()));
			v = u;
		}
		v = t;
		while (p[v] != -1) {
			u = p[v];
			temp = TheGraph[u].getHead();
			while (temp->getData().getEdgeV() != v) {
				temp = temp->getNext();
			}
			temp->getData().setEdgeFlow((temp->getData().getEdgeFlow()) + path_flow);
			curr = temp->getData().getEdgeFlow();
			temp = TheGraph[v].getHead();
			while (temp->getData().getEdgeV() != u) {
				temp = temp->getNext();
			}
			temp->getData().setEdgeFlow(-curr);
			v = u;
		}
			maxFlow += path_flow;
	}
}
void Graph::DeleteGraphLists(List list) {
	Node* currentNode = list.getHead();
	while (currentNode != nullptr) {
		Node* nextNode = currentNode->getNext();
		delete currentNode;
		currentNode = nextNode;
	}
}
void Graph::setIsVisitedToFalse() {
	for (int i = 0; i < GraphSize; i++) {
		isVisited[i] = false;
	}
}
void Graph::setParentsArrToMinusOne() {
	for (int i = 0; i < GraphSize; i++) {
		p[i] = -1;
	}
}
void Graph::setDArrToInfinity() {
	for (int i = 0; i < GraphSize; i++) {
		d[i] = INT32_MAX;
	}
}
bool Graph::Dijkstra(int s, int t){
	Element* Elementsarr = new Element[GraphSize];
	for (int i = 0; i < GraphSize; i++) {
		if (i == s) {
			Elementsarr[i].setDistance(0);
			Elementsarr[i].setVertex(i);
		}
		else {
			Elementsarr[i].setDistance(-1);
			Elementsarr[i].setVertex(i);
		}
	}
	MaxHeap Q;
	Q.BuildHeap(Elementsarr, GraphSize - 1);
	int u,v;
	Node* temp;
	for (int i = 1; i < GraphSize; i++) {
		if (i == s) {
			d[i] = INT32_MAX;
			p[i] = -1;
		}
		else {
			d[i] = -1;
			p[i] = -1;
		}
	}
	while (!Q.IsEmpty()) {
		u = Q.Max().getVertex();
		Q.DeleteMax();
		temp = TheGraph[u].getHead();
		while(temp != nullptr) {
			if (d[temp->getData().getEdgeV()] < Min(d[u], (temp->getData().getEdgeCapacity() - temp->getData().getEdgeFlow())) && temp->getData().getEdgeCapacity() > temp->getData().getEdgeFlow()) {
				d[temp->getData().getEdgeV()] = Min(d[u],(temp->getData().getEdgeCapacity() - temp->getData().getEdgeFlow()));
				p[temp->getData().getEdgeV()] = u;
				Q.IncreaseKey(d[temp->getData().getEdgeV()], temp->getData().getEdgeV());
			}
			temp = temp->getNext();
		}
	}
	if (d[t] != -1) { 
		return true; 
	}
		return false;
}
void Graph::SimpleBFS(int s) {
	queue<int> q2;
	q2.push(s);
	isVisited[s] = true;
	for (int i = 0; i < GraphSize; i++) {
		if (i == s) {
			p[i] = -1;
			d[i] = 0;
		}
		else
		{
			p[i] = -1;
			d[i] = INT32_MAX;
		}
	}
	while (!q2.empty()) {
		int u = q2.front();
		q2.pop();
		Node* temp = TheGraph[u].getHead();
		while (temp != nullptr) {
			if (d[temp->getData().getEdgeV()] == INT32_MAX && (temp->getData().getEdgeCapacity() > temp->getData().getEdgeFlow())) {
				d[temp->getData().getEdgeV()] = d[temp->getData().getEdgeU()] + 1;
				q2.emplace(temp->getData().getEdgeV());
			}
			temp = temp->getNext();
		}
	}
	for (int i = 1; i < GraphSize; i++) {
			if (d[i] != INT32_MAX) {
				GroupA.insert(GroupA.begin(), i);
			}
			else {
				GroupB.insert(GroupB.begin(), i);
			}
	}
		sort(GroupA.begin(), GroupA.end());
		sort(GroupB.begin(), GroupB.end());
}
void Graph::GreedyFoldFulkerson(int s, int t) {
		int u, v;
		int curr;
	while(Dijkstra(s, t)) {
		int path_flow = INT32_MAX;
		Node* temp;
		v = t;
		while (p[v] != -1) {
			u = p[v];
			temp = TheGraph[u].getHead();
			while (temp->getData().getEdgeV() != v) {
				temp = temp->getNext();
			}
			path_flow = Min(path_flow, (temp->getData().getEdgeCapacity() - temp->getData().getEdgeFlow()));
			v = u;
		}
		v = t;
		while (p[v] != -1) {
			u = p[v];
			temp = TheGraph[u].getHead();
			while (temp->getData().getEdgeV() != v) {
				temp = temp->getNext();
			}
			temp->getData().setEdgeFlow((temp->getData().getEdgeFlow()) + path_flow);
			curr = temp->getData().getEdgeFlow();
			temp = TheGraph[v].getHead();
			while (temp->getData().getEdgeV() != u) {
				temp = temp->getNext();
			}
			temp->getData().setEdgeFlow(-curr);
			v = u;
		}
		maxFlow += path_flow;
	}
}
int Graph::Min(int x, int y) {
	if (x < y) { return x; }
	return y;
}
Graph::~Graph() {
	for (int i = 0; i < GraphSize; i++) {
		DeleteGraphLists(TheGraph[i]);
	}
	delete[] TheGraph;
	delete[] isVisited;
	delete[] p;
	delete[] d;
};