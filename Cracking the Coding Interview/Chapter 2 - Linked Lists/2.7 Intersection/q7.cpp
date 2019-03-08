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

bool intersection(Node *l1, Node *l2) {
	if (l1 == nullptr and l2 == nullptr) return false;

	/* calcule both sizes */
	int s1 = 0, s2 = 0;
	Node *aux;

	aux = l1; while (aux) { aux = aux->next; s1++; }
	aux = l2; while (aux) { aux = aux->next; s2++; }

	/* removing first nodes from larger list */
	int k = abs(s1-s2);
	if (s1 > s2) while (k--) l1 = l1->next;
	else while (k--) l2 = l2->next;

	/* look for same node */
	while (l1 and l2) {
		if (l1 == l2) return true;
		l1 = l1->next;
		l2 = l2->next;
	}

	return false;
}

int main() {
	vector<int> a({7,1,6,1,7,8});
	Node * l1 = Node::buildLinkedList(a);
	vector<int> b({7,8});
	Node * l2 = Node::buildLinkedList(b);


	cout << (intersection(l1,l2) ? "Sim" : "Não") << endl;
	l2->next->next = l1->next->next->next;
	cout << (intersection(l1,l2) ? "Sim" : "Não") << endl;
	
	return 0;
}
