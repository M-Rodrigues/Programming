#include<bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<
#define gcd(x, y) __gcd((x), (y))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e3+5;

class No {
public:
	int key;
	No *prox;
};

class LinkedList {
	No *inicio;
public:
	LinkedList() {
		inicio = NULL;
	}
	~LinkedList() {
		No *atual = inicio;
		while (inicio) {
			atual = inicio->prox;
			free(inicio);
			inicio = atual;
		}
	}

	void inserir(int x) {
		No *atual = inicio;
		if (atual == NULL) {
			inicio = new No;

			inicio->prox = NULL;
			inicio->key = x;
		} else {
			while (atual->prox) {
				atual = atual->prox;
			}

			atual->prox = new No;
			atual = atual->prox;

			atual->key = x;
			atual->prox = NULL;
		}
	}

	void remover(int x) {
		No *atual = inicio, *ant = NULL;

		while (atual && atual->key != x) {
			ant = atual;
			atual = atual->prox;
		}

		if (atual) {
			if (ant != NULL)
				ant->prox = atual->prox;
			else
				inicio = atual->prox;
			delete atual;
		}
	}

	void impressao() {
		if (!inicio) printf("Lista Vazia!\n");
		else {
			No *atual = inicio;
			while (atual) {
				printf("%d ",atual->key);
				atual = atual->prox;
			}
			printf("\n");
		}
	}
};

class Stack {
	No *topo;
public:
	Stack(){
		topo = NULL;
	}
	~Stack() {
		No *atual = topo;
		while (atual) {
			topo = atual->prox;
			delete atual;
			atual = topo;
		}
	}

	void push(int x) {
		No *atual = new No;
		
		atual->key = x;
		atual->prox = topo;
		topo = atual;
	}

	bool top(int &res) {
		if (topo) {
			res = topo->key;
			return true;
		} else{
			cout << "Pilha vazia!" << endl;
			return false;
		}
	}
	
	bool pop() {
		No *atual = topo;

		if (atual) {
			topo = atual->prox;
			delete atual;
			return true;
		} else {
			cout << "Pilha vazia!" << endl;
			return false;
		}
	}
};


int main() {
	cout << "\nLista Encadeada!\n" << endl;
	LinkedList l;

	l.inserir(2);
	l.inserir(12);
	l.inserir(7);

	l.impressao();

	l.remover(12);
	l.remover(2);
	l.remover(5);

	l.impressao();

	cout << "\nPilha!\n" << endl;
	Stack p;
	int x;

	p.push(2);
	p.push(84);
	p.push(3);


	if (p.top(x)) cout << "Topo da pilha: " << x << endl;
	p.pop();
	if (p.top(x)) cout << "Topo da pilha: " << x << endl;
	p.pop();
	if (p.top(x)) cout << "Topo da pilha: " << x << endl;
	p.pop();
	if (p.top(x)) cout << "Topo da pilha: " << x << endl;

	return 0;
}

