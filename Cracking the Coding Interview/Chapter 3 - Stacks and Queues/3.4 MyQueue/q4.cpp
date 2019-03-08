#include<bits/stdc++.h>
using namespace std;

class MyQueue {
	stack<int> q, aux;
public:
	MyQueue();
	void add(int);
	int front();
	int remove();
};

MyQueue::MyQueue() {};

void MyQueue::add(int x) { q.push(x); };

int MyQueue::front() { 
	if (q.empty()) throw "Fila Vazia";

	while (!q.empty()) {
		aux.push(q.top()); q.pop();
	}

	int ans = aux.top();

	while (!aux.empty()) {
		q.push(aux.top()); aux.pop();
	}

	return ans;
};

int MyQueue::remove() {
	if (q.empty()) throw "Fila Vazia";

	while (!q.empty()) {
		aux.push(q.top()); q.pop();
	}

	int ans = aux.top(); aux.pop();

	while (!aux.empty()) {
		q.push(aux.top()); aux.pop();
	}

	return ans;
};