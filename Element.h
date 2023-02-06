#pragma once
class Element { 
private:
	int Vertex; // The Value 
	int Distance; // The Key ( Heap is sorted by Key . Maximum Priority Queue)
public:
	int getVertex() const { return this->Vertex; }
	void setVertex(int x) { this->Vertex = x; }
	int getDistance() const { return this->Distance; }
	void setDistance(int x) { this->Distance = x; }
};
