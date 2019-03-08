#include<bits/stdc++.h>
using namespace std;

class MinStack {
	stack<pair<int, int>> st;
public:
	MinStack() {}

	void push(int val) {
		int min = val;
		if (!st.empty()) {
			if (val > st.top().second) min = st.top().second; 
		}
		st.push({val, min});
	}

	int pop() {
		if (st.empty()) return -1;

		int val = st.top().first;
		st.pop();
		return val;
	}

	int min() {
		return (st.empty() ? -1 : st.top().second);
	}
};

int main() {
	MinStack min_st;

	min_st.push(2);
	min_st.push(3);
	min_st.push(4);
	min_st.push(1);
	min_st.push(2);

	cout << min_st.min() << endl;
	min_st.pop();
	cout << min_st.min() << endl;
	min_st.pop();
	cout << min_st.min() << endl;
	min_st.pop();
	cout << min_st.min() << endl;
	min_st.pop();

	return 0;
}
