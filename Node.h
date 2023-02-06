#pragma once
#include "Edge.h"
class Node {
private:
	Edge data;
	Node* next;
	Node* prev;
public:
	Node() :next(nullptr), prev(nullptr) {}
	Node* getNext() const { return this->next; }
	Node* getPrev() const { return this->prev; }
	Edge&  getData() { return data; }
	void setNext(Node* node) { this->next = node; }
	void setPrev(Node* node) { this->prev = node; }
	void setData(Edge _data) {
		this->data.setEdgeU(_data.getEdgeU());
		this->data.setEdgeV(_data.getEdgeV());
		this->data.setEdgeCapacity(_data.getEdgeCapacity());
		this->data.setEdgeFlow(_data.getEdgeFlow());
	}
};
