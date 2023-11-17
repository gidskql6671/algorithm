#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int fibo[21] = { 0 };

	fibo[0] = 0;
	fibo[1] = 1;

	int n;
	scanf("%d", &n);

	for (int i = 2; i <= n; i++)
		fibo[i] = fibo[i - 1] + fibo[i - 2];

	cout << fibo[n] << endl;

	return 0;
}