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

bool isPalindrome(Node * head) {
	/* empty lists or single-value lists */
	if (head == nullptr or head->next == nullptr) 
		return true;
	
	Node *fast, *slow;
	fast = slow = head;
	stack<Node*> st;

	/* stacking half of the list */
	int size = 0;
	while (fast and fast->next) {
		st.push(slow);

		size+=2;
		
		fast = fast->next->next;
		slow = slow->next;

		if (fast and fast->next == nullptr) size++;
	}

	/* skiping the middle element, if the size is odd */
	if (size%2 == 1) slow = slow->next;


	/* checking second half */
	while (!st.empty()) {
		if (st.top()->val != slow->val) return false;
		st.pop(); slow = slow->next;
	}
	return true;
}

int main() {
	vector<int> a({7,1,6,1,7,8});
	Node * head = Node::buildLinkedList(a);

	Node::printLinkedList(head);
	cout << (isPalindrome(head) ? "Sim" : "Não")  << endl;

	return 0;
}
