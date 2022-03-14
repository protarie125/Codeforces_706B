#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using vi = vector<int>;

int canBuy(const vi& xs, int n, int m) {
	if (m < xs[0]) {
		return 0;
	}

	if (xs[n - 1] <= m) {
		return n;
	}

	auto left = 0;
	auto right = n - 1;
	auto mid = (left + right) / 2;
	while (left < right) {
		if (xs[mid] <= m) {
			left = mid + 1;
		}
		else {
			right = mid;
		}

		mid = (left + right) / 2;
	}

	return left;
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	cin >> n;

	auto xs = vi(n);
	for (int i = 0; i < n; ++i) {
		cin >> xs[i];
	}
	sort(xs.begin(), xs.end());

	int q;
	cin >> q;
	while (0 < (q--)) {
		int m;
		cin >> m;

		cout << canBuy(xs, n, m) << '\n';
	}

	return 0;
}