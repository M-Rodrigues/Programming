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

int sumLists(Node *n1, Node *n2) {
	int sum = 0, base = 1;

	while (n1 != nullptr or n2 != nullptr) {
		if (n1 == nullptr) {
			sum += base*n2->val; n2 = n2->next;
		} else if (n2 == nullptr) {
			sum += base*n1->val; n1 = n1->next;
		} else {
			sum += base*(n1->val + n2->val);
			n1 = n1->next; n2 = n2->next;
		}
		base *= 10;
	}

	return sum;
}

Node * buildList(int n) {
	if (n ==  0) return nullptr;

	int val = n;
	Node *head, *aux;

	while (n != 0) {
		if (n == val) {
			head = new Node(n%10);
			aux = head;
		} else {
			aux->next = new Node(n%10);
			aux = aux->next;
		}
		n /= 10;
	}

	return head;
}

int main() {
	vector<int> a({7,1,6});
	Node * n1 = Node::buildLinkedList(a);
	vector<int> b({5,9,2});
	Node * n2 = Node::buildLinkedList(b);

	Node::printLinkedList(n1);
	Node::printLinkedList(n2);

	cout << sumLists(n1, n2) << endl;

	Node::printLinkedList(buildList(sumLists(n1, n2)));

	return 0;
}
