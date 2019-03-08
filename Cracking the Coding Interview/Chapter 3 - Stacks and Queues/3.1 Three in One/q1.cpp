template <class T>
class TreeStacks {
	int t1, t2, t3, b1, b2, b3, n;
	vector<T> arr;
public:
	TreeStacks(int n): n(n) {
		arr.resize(n);
		b1 = t1 = 0;
		b2 = t2 = n/3;
		b3 = t3 = 2*n/3;
	}

	bool pushTo1(T &t) {
		if (t1 != b2) {
			arr[t1] = t; t1++;
			return true;
		}
		return false;
	}

	T popFrom1() {
		if (t1 == b1) throw 'Pilha 1 vazia';
		t1--; return arr[t1+1];
	}

	/*same to others*/
}