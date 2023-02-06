#pragma once
#include <queue>
#include "Element.h"
#include "Edge.h"
class MaxHeap {
private:
	Element* theHeap;
	int maxSize = MAXSIZE;
	int heapSize = 0;
	static int Left(int node) { return (2 * node + 1); }
	static int Right(int node) { return (2 * node + 2); }
	static int Parent(int node) { return (node - 1) / 2; }
	void fixHeap(int node);
public:
	void BuildHeap(Element* arr, int Size);
	bool IsEmpty() { return heapSize == 1; }
	int  getHeapSize() const { return heapSize; }
	Element Max() const { return theHeap[0]; }
	Element DeleteMax();
	void Insert(Element e);
	void IncreaseKey(int newKey, int Place);
	void SwapElements(Element& a, Element& b);
};