#include "List.h"
void List::MakeEmptyList()
{
	if (head == nullptr)
	{
		return;
	}
	Node* next_to_delete = head;
	while (head->getNext() != nullptr)
	{
		next_to_delete = head->getNext();
		delete head;
		head = next_to_delete;
	}
	delete head;
}
void List::AddNodeToStart(Edge e)
{
	Node* nodeToAdd = new Node;
	nodeToAdd->setData(e);
	nodeToAdd->setNext(head);
	nodeToAdd->setPrev(nullptr);
	head = nodeToAdd;
}
void List::AddNodeToEnd(Edge e)
{
	Node* nodeToAdd = new Node;
	nodeToAdd->setData(e);
	if (head == nullptr) {
		nodeToAdd->setPrev(nullptr);
		nodeToAdd->setNext(nullptr);
		head = nodeToAdd;
		return;
	}
	else
	{
		Node* temp = head;
		while (temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}
		temp->setNext(nodeToAdd);
		nodeToAdd->setPrev(temp);
		nodeToAdd->setNext(nullptr);
	}
}
void List::deleteNode(int v)
{
	if (head == nullptr)
	{
		cout << "Invalid Input! head is nullptr.";
		exit(1);
	}
	else
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			if (temp->getData().getEdgeV() == v)
			{
				if (temp == head)
				{
					head = head->getNext();
					delete temp;
					return;
				}
				else if (temp->getNext() == nullptr)
				{
					temp->getPrev()->setNext(nullptr);
					delete temp;
					return;
				}
				else
				{
					temp->getPrev()->setNext(temp->getNext());
					temp->getNext()->setPrev(temp->getPrev());
					delete temp;
					return;
				}
			}
			temp = temp->getNext();
		}
		cout << "The Verticle is not found!" << endl;
	}
}
void List::PrintList() {
	if (this->isEmpty()) {
		cout << "This List is Empty!" << endl;
	}
	else {
		Node* temp = head;
		while (temp != nullptr) {
			cout << "(" << temp->getData().getEdgeU() << "," << temp->getData().getEdgeV() << ") " << temp->getData().getEdgeCapacity() << endl;
			temp = temp->getNext();
		}
	}
}
bool List::isOnTheList(int v)
{
	if (head == nullptr) {
		return false;
	}
	Node* temp = head;
	while (temp != nullptr) {
		if (temp->getData().getEdgeV() == v)
		{
			return true;
		}
		temp = temp->getNext();
	}
	return false;
}
