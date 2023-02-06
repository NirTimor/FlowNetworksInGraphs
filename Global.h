#pragma once
#include "Edge.h"
#include <fstream>
#include <string>
#include <sstream>
Edge* getData(int& NumofVerticals, int& NumofEdges, int& s , int& t);
void MarkEdgesWithoutParallelEdge(Edge* EdgesArr, int NumofVerticals, int NumofEdges);
int CorrectingEdgesArr(Edge* EdgesArr, int NumofVerticals, int NumofEdges);
