#include <bits/stdc++.h>
using namespace std;

long long dac(int a, int b, int c);

int main(){
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);

	long long tmp = dac(a, b, c);

	printf("%lld\n", tmp);

	return 0;
}
long long dac(int a, int b, int c) {
	if (b == 0)
		return 1;

	if (b % 2) {
		long long tmp = dac(a, b / 2, c) % c;
		return (((tmp * tmp) % c) * a) % c;
	}
	else {
		long long tmp = dac(a, b / 2, c) % c;
		return (tmp * tmp) % c;
	}

}