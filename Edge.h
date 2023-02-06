#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
#include <stdbool.h>
#define MAXSIZE 100
#define UNINITIALIZED -1
using namespace std;
class Edge {
private:
	int u;
	int v;
	int Capacity;
	int CurrentFlow;
	bool isNegativeEdgeExist;
public:
	Edge() { u = UNINITIALIZED; v = UNINITIALIZED; Capacity = INT32_MAX; CurrentFlow = 0; isNegativeEdgeExist = false; }
	int  getEdgeU()  { return u; }
	int  getEdgeV()  { return v; }
	int  getEdgeCapacity()  { return Capacity; }
	int  getEdgeFlow()  { return CurrentFlow; }
	int  getisNegativeEdgeExist()  { return isNegativeEdgeExist; }
	void setEdgeU(int newU) { u = newU; }
	void setEdgeV(int newV) { v = newV; }
	void setEdgeCapacity(int newWeight) { Capacity = newWeight; }
	void setEdgeFlow(int newFlow) { CurrentFlow = newFlow; }
	void setisNegativeEdgeExist(bool b) { isNegativeEdgeExist = b; }
};

