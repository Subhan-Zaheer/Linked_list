#include<iostream>
using namespace std;

class node {
public:
	int data;
	node* next;
	node() {
		data = 0;
		next = NULL;
	}
};

class linkList {
	node* head;
public:
	linkList() {
		head = NULL;
	}
	int insert(int num);
	void display();
};
void linkList::display() {
	node* temp = head;
	while (temp != NULL) {
		cout << temp->data << "->";
		temp = temp->next;
	}
}
int linkList::insert(int num) {
	node *newNode = new node;
	newNode->data = num;
	newNode->next = NULL;
	node * temp = head;
	if (head == NULL) {
		head = newNode;
	}
	else if (head != NULL) {
		while (temp->next != NULL) {

			temp = temp->next;
		}
		temp->next = newNode;
	}
	return 0;
}

int main() {
	
	linkList l1;
	l1.insert(1);
	l1.insert(2);
	l1.insert(3);
	l1.insert(4);
	l1.display();
	
	return 0;
}









