#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

int subsetXOR(int arr[],int n, int k)
{
	int maxele = arr[0];
	for(int i = 1; i < n; ++i)
	{
		if(arr[i] > maxele)
			maxele = arr[i];
	}

	//Maximum possible XOR value
	int m = (1 << (int)(log2(maxele) + 1)) - 1;

	int dp[n+1][m+1];

	memset(dp,0,sizeof(dp));
	dp[0][0] = 1;

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 0; j <=m; ++j)
		{
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j ^ arr[i - 1]];
		}
	}

	return dp[n][k];

}

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	int k = 4;
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "Count of subset is" << subsetXOR(arr,n,k);
	getwchar();
	return 0;
}
