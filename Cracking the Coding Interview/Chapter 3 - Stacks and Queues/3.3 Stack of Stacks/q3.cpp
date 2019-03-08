#include<bits/stdc++.h>
using namespace std;

class StackOfStacks {
	int stackSize;
	stack<stack<int>*> sts;

	stack<int>* lastStack();
	bool fullSize(stack<int>*);
public:
	StackOfStacks(int);
	void push(int);
	int pop();
};

StackOfStacks::StackOfStacks(int n): stackSize(n) {};

void StackOfStacks::push(int x) {
	stack<int> *st = lastStack();

	if (st == nullptr or fullSize(st)) {
		st = new stack<int>;
		st->push(x);
		sts.push(st);
	} else {
		st->push(x);
	}
};

int StackOfStacks::pop() {
	stack<int> *st = lastStack();

	if (st == nullptr) return -1;
	int x = st->top(); st->pop();
	return x;
}

stack<int> * StackOfStacks::lastStack() {
	if (sts.empty()) return nullptr;
	return sts.top();
}

bool StackOfStacks::fullSize(stack<int> *s) {
	return s->size() == stackSize;
}
