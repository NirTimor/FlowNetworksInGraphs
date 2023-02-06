#pragma once
#include "Node.h"
using namespace std;
class List {
private:
    Node* head = nullptr;
public:
    bool isEmpty() { return this->head == nullptr; }
    void MakeEmptyList();
    void AddNodeToStart(Edge e);
    void AddNodeToEnd(Edge e);
    void deleteNode(int v);
    void PrintList();
    bool isOnTheList(int v);
    Node* getHead() const { return this->head; }
};
