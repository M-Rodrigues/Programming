#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int val;
	Node *next;
	
	Node(int v): val(v), next(nullptr) {};
	
	static Node * buildLinkedList(const vector<int> &A) {
		Node * head = nullptr, * aux = nullptr;

		for (int i = 0; i < A.size(); i++) {
			if (i == 0) {
				head = new Node(A[i]);
				aux = head;
			} else {
				aux->next = new Node(A[i]);
				aux = aux->next;
			}
		}
		return head;
	}
};


// solution
Node * kthToLast(Node * head, int k) {
	int size = 0;
	Node *aux = head;

	while (aux) size++, aux = aux->next;

	size -= k;

	if (size < 0) return nullptr;

	aux = head;
	while (size--) aux = aux->next;

	return aux;
}

int main() {
	vector<int> a({2,5,3,1});
	Node * head = Node::buildLinkedList(a);

	cout << kthToLast(head, 5)->val << endl;
	return 0;
}
