
#include <iostream>


using namespace std;

struct node_t {
	node_t* l;
	node_t* r;
	int v;
};

node_t* add(int v, node_t*& n) {
	return n ? add(v, (v < n->v ? n->l : n->r)) : n = new node_t{ 0, 0, v };
}

void rm(node_t*& v) {
	return v ? rm(v->l), rm(v->r), delete v : void();
}

void print(node_t* n, size_t o = 0) {
	if (!n) {
		cout << "---\n";
		return;
	}
	cout << n->v << "\n";
	for (size_t i = 0; i < o; ++i) {
		putchar(' ');
	}
	cout << "L: ";
	print(n->l, o + 3);
	for (size_t i = 0; i < o; ++i) {
		putchar(' ');
	}
	cout << "R: ";
	print(n->r, o + 3);
}

node_t* find(node_t* n, int v) {
	if (!n) {
		return nullptr;
	}
	else if (n->v == v) {
		return n;
	}
	return v < n->v ? find(n->l, v) : find(n->r, v);
}

bool is_child(node_t* n, int v) {
	return find(n, v) != nullptr;
}

bool fu(node_t* n, int a, int b) {
	node_t* x = find(n, b);
	return x == nullptr ? false : is_child(x, a);
}

int main() {

	size_t n;
	cout << "Enter vertex count: ";
	cin >> n;
	cout << "\n Enter node";
	int* arr = new int[n];
	for (size_t i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	node_t* tr = nullptr;
	for (size_t i = 0; i < n; ++i) {
		add(arr[i], tr);
	}
	print(tr);
	cout << "\n";

	int a, b;
	cin >> a >> b;

	cout << (fu(tr, a, b)
		? "A is child of B"
		: "A is not chlid of B");

	rm(tr);
	delete[] arr;

}