#include <cstdio>
#include <cmath>
#include <set>
using namespace std;

int main() {
	int n, a, b;

	while (scanf("%d", &n) != EOF) {
		set<int> checker;
		bool jolly = true;

		scanf("%d", &a);
		for (int i = 0; i < n - 1; i++) {
			scanf("%d", &b);
			a = abs(a - b);
			checker.insert(a);
			a = b;
		}

		if (checker.size() != n - 1)
			jolly = false;
		else if (checker.count(0) > 0)
			jolly = false;
		else if (checker.upper_bound(n - 1) != checker.end())
			jolly = false;

		if (jolly)
			printf("Jolly\n");
		else
			printf("Not jolly\n");
	}

	return 0;
}