#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	char op;
	int val;
	Node *left, *right;

	Node(int x): val(x), left(nullptr), right(nullptr) {}
	Node(char x, Node* l, Node* r): op(x), left(l), right(r) {}

	bool isLeaf() { return left == nullptr and right == nullptr; }
	double compute(double x, double y) {
		if (op == '+') return x+y;
		if (op == '-') return x-y;
		if (op == '*') return x*y;
		if (op == '/') return x/y;
	}
};

int hasOps(char c1, char c2, const string &s) {
	for (int i = s.size()-1; i > 0; i--) {
		if (s[i] == c1 or s[i] == c2) return i;
	}
	return -1;
}

Node * buildEquationTree(string s) {
	int i; Node *ans;

	if (hasOps('+','-',s) != -1) {
		i = hasOps('+','-',s);
	} else if (hasOps('*','/',s) != -1) {
		i = hasOps('*','/',s);
	} else {
		int x = stoi(s);
		return new Node(x);
	}
	
	return new Node(
			s[i], 
			buildEquationTree(s.substr(0,i)),
			buildEquationTree(s.substr(i+1,s.size()-i-1)));
}

double solve(Node* n) {
	if (n->left == nullptr and n->right == nullptr) return (double)n->val;

	double n1 = solve(n->left);
	double n2 = solve(n->right);

	return n->compute(n1,n2); 
}

int main() {
	string s = "2*3+5/6*3+15";
	
	Node *head = buildEquationTree(s);
	double result = solve(head);
	
	cout << result << endl;
	
	return 0;
}
