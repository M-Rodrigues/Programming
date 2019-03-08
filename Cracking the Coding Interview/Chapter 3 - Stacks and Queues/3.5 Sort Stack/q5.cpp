#include<bits/stdc++.h>
using namespace std;


void sortStack(stack<int> &st) {
	stack<int> aux;
	bool sorted;

	do {
		sorted = true;
		
		/* partial sort */
		int x = st.top(); st.pop();
		while (!st.empty()) {
			if (st.top() >= x) {
				aux.push(x);
				x = st.top();
			} else {
				sorted = false;
				aux.push(st.top());
			}
			st.pop();
		}
		aux.push(x);

		/* moving back to the main stack */
		while (!aux.empty()) {
			st.push(aux.top());
			aux.pop();
		}

	} while (!sorted);
}


int main() {
	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	st.push(6);

	sortStack(st);

	while (!st.empty()) {
		cout << st.top() << endl; st.pop();
	}

	return 0;
}
