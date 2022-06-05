#include "binary_tree.h"
#include <stack>

priortyqueue::priortyqueue() {
	this->head = NULL;
	this->size = 0;
}

priortyqueue::~priortyqueue() {
	while (!this->isEmpty())
		this->pop_tree();
}

void priortyqueue::add(string input, int p) {
	if (this->head == NULL) {
		this->head = new btree;
		this->head->leftnode = NULL;
		this->head->rightnode = NULL;
		this->head->prior = p;
		this->head->data = input;
	}
	else {
		btree* tmp1 = this->head;
		btree* tmp2 = new btree;
		tmp2->leftnode = NULL;
		tmp2->rightnode = NULL;
		tmp2->prior = p;
		tmp2->data = input;

		while (1) {
			if (tmp1->prior < tmp2->prior) {
				if (tmp1->rightnode == NULL) {
					tmp1->rightnode = tmp2;
					break;
				}
				tmp1 = tmp1->rightnode;
			}
			else {
				if (tmp1->leftnode == NULL) {
					tmp1->leftnode = tmp2;
					break;
				}
				tmp1 = tmp1->leftnode;
			}
		}
	}
	this->size++;
}

string priortyqueue::pop_tree() {
	if (this->head == NULL) {
		cout << "There isn`t exist node to delete." << endl;
		return "\0";
	}
	btree* delnode = this->head;
	btree* beforenode = NULL;

	while (delnode->rightnode != NULL) {
		beforenode = delnode;
		delnode = delnode->rightnode;
	}
	if (delnode->leftnode != NULL) {
		if (delnode == this->head)
			this->head = delnode->leftnode;
		else
			beforenode->rightnode = delnode->leftnode;
	}
	else {
		if (beforenode != NULL)
			beforenode->rightnode = NULL;
		else
			this->head = NULL;
	}
	string output = delnode->data;
	delete delnode;
	this->size--;
	return output;
}

void priortyqueue::opposite_inorder() {
	stack<btree*> store;
	btree* tmp = this->head;

	if (tmp == NULL)
		return;
	cout << "===================================opposite tree inorder===================================" << endl;
	while(1) {
		if (store.size() == 0 || store.top() != tmp) {
			while (tmp->rightnode != NULL) {
				store.push(tmp);
				tmp = tmp->rightnode;
			}
		}
		else
			store.pop();
		cout << this->getsize() + 1 - tmp->prior << ". " << tmp->data << endl;

		if (tmp->leftnode != NULL)
			tmp = tmp->leftnode;
		else {
			if (store.size() == 0)
				break;
			tmp = store.top();
		}
	} 
}

bool priortyqueue::isEmpty() {
	if (this->head == NULL)
		return true;
	return false;
}