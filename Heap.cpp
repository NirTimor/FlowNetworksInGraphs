#include "Heap.h"
void MaxHeap::SwapElements(Element& a, Element& b) { //Swap Elements
	Element newE;
	newE.setDistance(a.getDistance());
	newE.setVertex(a.getVertex());
	a.setDistance(b.getDistance());
	a.setVertex(b.getVertex());
	b.setDistance(newE.getDistance());
	b.setVertex(newE.getVertex());
}
void MaxHeap::IncreaseKey(int newKey, int Place) {
	int i;
	for (i = 0; i < heapSize; i++) {
		if (theHeap[i].getVertex() == Place) {
			theHeap[i].setDistance(newKey);
			while (i != 0 && theHeap[Parent(i)].getDistance() < theHeap[i].getDistance())
			{
				SwapElements(theHeap[i], theHeap[Parent(i)]);
				i = Parent(i);
			}
			return;
		}
	}
	cout << "Invalid Input! The key is not on the Heap.";
	exit(1);
}
void MaxHeap::Insert(Element e) {
	if (heapSize == MAXSIZE) {
		cout << "Invalid Input! Heap is FULL";
		exit(1);
	}
	else {
		int i = heapSize;
		heapSize++;
		while ((i > 0) && ((theHeap[Parent(i)]).getDistance() < (e.getDistance()))) // checks if my parent is bigger than item to insert.
		{
			theHeap[i].setDistance(theHeap[Parent(i)].getDistance());
			theHeap[i].setVertex(theHeap[Parent(i)].getVertex());
			i = Parent(i);
		}
		theHeap[i].setDistance(e.getDistance());
		theHeap[i].setVertex(e.getVertex());
	}
}
void MaxHeap::fixHeap(int node) {
	int Max;
	int left = Left(node);
	int right = Right(node);
	if ((left < heapSize) && (theHeap[left].getDistance()) > (theHeap[node].getDistance()))
	{
		Max = left;
	}
	else
	{
		Max = node;
	}
	if ((right < heapSize) && (theHeap[right].getDistance()) > (theHeap[Max].getDistance()))
	{
		Max = right;
	}
	if (Max != node)
	{
		SwapElements(theHeap[node], theHeap[Max]);
		fixHeap(Max);
	}
}
Element MaxHeap::DeleteMax() {
	if (heapSize < 1) {
		cout << "Invalid Input! Heap is Empty.";
		exit(1);
	}
	else {
		Element Max;
		Max.setDistance(theHeap[0].getDistance());
		Max.setVertex(theHeap[0].getVertex());
		heapSize--;
		theHeap[0].setDistance(theHeap[heapSize].getDistance());
		theHeap[0].setVertex(theHeap[heapSize].getVertex());
		fixHeap(0);
		return Max;
	}
}
void MaxHeap::BuildHeap(Element* arr, int Size) {
	theHeap = new Element[Size];
	int i;
	for (i = 0; i < Size; i++) {
		theHeap[i].setDistance(arr[i + 1].getDistance());
		theHeap[i].setVertex(arr[i + 1].getVertex());
	}
	heapSize = Size;
	for (i = (Size/2)-1; i>=0; i--) {
		fixHeap(i);
	}
}


