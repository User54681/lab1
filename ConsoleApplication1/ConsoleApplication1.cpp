#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::vector;

int main() {
	int n, m, q, type, card;
	char player;

	cin >> n >> m >> q;

	int* a = new int[n + q] {};
	int* b = new int[m + q] {};
	int* c = new int[q]{};

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}

	for (int i = 0; i < q; ++i) {
		int* d = new int[n + m + 2*q];
		cin >> type >> player >> card;
		if (type == 1) {
			if (player == 'a') a[n + i] = card;
			else b[n + i] = card;
		}
		if (type == -1) {
			if (player == 'a') for (int j = 0; j < n + q; ++j) if (a[j] == card) a[j] = 0;
			if (player =='b') for (int j = 0; j < m + q; ++j) if (b[j] == card) b[j] = 0;
		}
		for (int i = 0; i < n + q; ++i) {
			d[i] = a[i];
		}
		for (int i = n+q; i < n + m + 2*q; ++i) {
			d[i] = b[i];
		}
		int cnt = 0;
		for (int i = 0; i < n + m + 2 * q; ++i) {
			bool check = true;
			for (int j = i + 1; j < n + m + 2 * q; ++j) if (d[i] == d[j]) check = false;
			if (check) cnt++;
		}
		delete[]d;
		c[i] = cnt;
	}

	for (int i = 0; i < q; ++i) cout << c[i] << " ";

	delete[]a;
	delete[]b;
	delete[]c;
}

