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

	static void printLinkedList(Node * head) {
		if (head == nullptr) {
			cout << "Lista Vazia." << endl;
			return;
		}

		Node *aux = head;
		while (aux) {
			cout << aux->val << (aux->next ? " " : "");
			aux = aux->next;
		}
		cout << endl;
	}
};

// Solution

void deleteMiddleNode(Node * head) {
	if (head == nullptr) return;

	if (head->next == nullptr) {
		delete head; head = nullptr;
		return;
	}

	Node *fast = head, *slow = head;

	while (fast and fast->next) {
		fast = fast->next->next;
		slow = slow->next;
	}

	fast = head;
	while (fast->next != slow) fast = fast->next;

	fast->next = slow->next;
	delete slow;
}

int main() {
	vector<int> a({1});
	Node * head = Node::buildLinkedList(a);
	
	Node::printLinkedList(head);
	deleteMiddleNode(head);
	Node::printLinkedList(head);
	
	return 0;
}
