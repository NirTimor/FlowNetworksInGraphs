#include "Graph.h"
#include "Global.h"
int main() {
	int NumofVerticies = UNINITIALIZED;
	int NumofEdgesGiven = UNINITIALIZED;
	int i = 0;
	int s = UNINITIALIZED;
	int x = UNINITIALIZED;
	int t = UNINITIALIZED;
	int NewNumofEdges;
	Graph G;
	Graph H;
	Edge* EdgesArr = getData(NumofVerticies, NumofEdgesGiven,s,t);
	MarkEdgesWithoutParallelEdge(EdgesArr, NumofVerticies, NumofEdgesGiven);
	NewNumofEdges = CorrectingEdgesArr(EdgesArr, NumofVerticies, NumofEdgesGiven);
	// until this point we have the Edges Array Correctly with capacities and flows.
	G.MakeEmptyGraph(NumofVerticies);
	H.MakeEmptyGraph(NumofVerticies);
	G.InitilizeGraph(NumofVerticies, EdgesArr, NewNumofEdges);
	H.InitilizeGraph(NumofVerticies, EdgesArr, NewNumofEdges);
	G.FordFulkersonWithBFS(s, t);
	H.GreedyFoldFulkerson(s, t);
	x = G.GetMaxFlow();
	G.SimpleBFS(s);
	H.SimpleBFS(s);
	cout << "BFS Method:" << endl;
	cout << "Max flow = " << x << endl;
	cout << "Min cut:S = ";
	for (auto i : G.getGroupA())
		if (i != 0)  { cout << i << ", "; }
	cout << "\b\b";
	cout << ". ";
	cout << "T = ";
	for (auto i : G.getGroupB())
		if (i != 0) { cout << i << ", "; }
	cout << "\b\b";
	cout << " ";
	cout << endl;
	cout << "Greedy Method:" << endl;
	cout << "Max flow = " << x << endl;
	cout << "Min cut:S = ";
	for (auto i : H.getGroupA())
		if (i != 0) { std::cout << i << ", "; }
	cout << "\b\b";
	cout << ". ";
	cout << "T = ";
	for (auto i : H.getGroupB())
		if (i != 0) { std::cout << i << ", "; }
	cout << "\b\b";
	return 0;
};