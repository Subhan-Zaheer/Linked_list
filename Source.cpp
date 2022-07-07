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
	int insertatHead(int num);
	int insert(int num);
	int insertat_Index(int index, int num);
	int update_byIndex(int index, int num);
	int delete_head();
	int delete_byval(int num);
	int delete_byindex(int index);
	void display();
};

int linkList::update_byIndex(int index, int num) {
	
}
int linkList::delete_head() {
	node* temp = head;
	head = head->next;
	delete temp;
	return 1;
}
int linkList::delete_byindex(int index) {
	if (index == 0) {
		delete_head();
		return 1;
	}
	else {
		bool found = false;
		node* temp = head;
		node* temp1 = nullptr;
		for (int i = 0; i < index - 1; i++) {
			temp = temp->next;
		}
		temp1 = temp->next;
		temp->next = temp->next->next;
		delete temp1;
		return 1;
	}
}
int linkList::delete_byval(int num) {

	node* temp = head;
	bool n = false;
	if (temp == NULL) {

		cout << "\nLink list is empty." << endl;
		return 0;
	}
	else {

			if (head->data == num) {
				node* anotherTemp = head;
				head = head->next;
				delete anotherTemp;
				n = true;
				return 1;
			}
		while (temp->next != NULL) {

			if (temp->next->data == num) {
				node* anotherTemp = NULL;
				anotherTemp = temp->next;
				temp->next = temp->next->next;
				n = true;
				delete anotherTemp;
				return 1;
			}
			temp = temp->next;
		}
		if (n == false) {
			cout << "Value did not found." << endl;
			return 0;
		}
	}
}
int linkList::insertat_Index(int index, int num) {
	int counter = 0;
	node* newNode = new node;
	newNode->data = num;
	newNode->next = NULL;
	node* temp = head;
	if (index == 0)
		insert(num);
	else {
		for (int i = 0; i < index - 1; i++) {
			temp = temp->next;
		}
		newNode->next = temp->next;
		temp->next = newNode;
	}
	return 1;
}
int linkList::insertatHead(int num) {
	node* newNode = new node;
	newNode->data = num;
	newNode->next = NULL;
	node* temp = head;
	if (head == NULL) {
		head = newNode;
	}
	else if (head != NULL) {
		newNode->next = temp;
		head = newNode;
	}
	return 1;
}
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
	l1.insert(5);
	l1.insert(6);
	l1.display();
	cout << endl;
	cout << "Inserting 0 at head." << endl;
	l1.insertatHead(0);
	l1.display();
	cout << endl;
	cout << "Inserting 2 at index 2." << endl;
	l1.insertat_Index(2, 2);
	l1.display();
	cout << endl;
	cout << "Deleting value 6." << endl;
	l1.delete_byval(6);
	l1.display();
	cout << endl;
	cout << "Deleting head." << endl;
	l1.delete_head();
	l1.display();
	cout << endl;
	cout << "Deleting value at index 2." << endl;
	l1.delete_byindex(2);
	l1.display();
	cout << endl;

	return 0;
}









