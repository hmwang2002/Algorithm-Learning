#include <iostream>

using namespace std;

int main()
{
	int n, x;
	cin >> n;
	long res = 0;
	long sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		res += x * sum;
		sum += x;
	}
	printf("%ld", res);
	return 0;
}