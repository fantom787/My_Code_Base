#include <iostream>
using namespace std;

void processArr(int m, int a[][m])
{
	cout << "element at index 1,1 is " << a[1][1];
}
int main()
{
	int arr[2][2];
	arr[0][0] = 0;
	arr[0][1] = 1;
	arr[1][0] = 2;
	arr[1][1] = 3;

	processArr(arr);
	return 0;
}