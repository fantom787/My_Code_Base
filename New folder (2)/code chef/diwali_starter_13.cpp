// not accepted
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
/*

#accepted 
void solve()
{
	ll p, a, b, c, x, y, ans = 0;
	cin >> p >> a >> b >> c >> x >> y;
	ll anar = (x * a) + b;
	ll charkari = (y * a) + c;
	ans = min(anar, charkari);
	ans = p / ans;
	cout << ans << endl;
}
*/

void solve()
{
	int p, a, b, c, x, y, ans = 0;
	cin >> p >> a >> b >> c >> x >> y;
	int anar = (x * a) + b;
	int charkari = (y * a) + c;
	if (charkari > anar)
	{
		ans = p / anar;
		ans += (p % anar) / charkari;
		if (p % anar >= 2)
		{
			ans += 1;
		}
	}
	else if (charkari < anar)
	{
		ans = p / charkari;
		if (p % charkari >= 2)
		{
			ans += 1;
		}
	}
	else
	{
		ans = p / anar;
	}
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	while (n--)
	{
		solve();
	}

	return 0;
}

/*
Chef has allocated himself a budget of P rupees to buy Diwali crackers. There are only 3 types of crackers available in the market and each type of cracker can be bought any number of times.

Fuljhari, where each costs a rupees
Anar, where each costs b rupees
Chakri, where each costs c rupees
The crackers have the following interesting properties:-

A Fuljhari can be lit on its own
To light an Anar, you will need x Fuljharis
To light a Chakri, you will need y Fuljharis
What's the maximum total of Anars and Chakris that Chef can light up with his given budget.

Input Format
First line of input will contain T, the number of test cases. Then the test cases follow.
Each test case contains of a single line of input, six integers P, a, b, c, x and y.
Output Format
For each test case, output in a single line the maximum total of Anars and Chakris Chef can light up.

Constraints
1≤T≤105
1≤P,a,b,c,x,y≤109
Sample Input 1 
3
100 5 5 10 4 8
16 2 2 2 1 1
55 1 2 3 4 5
Sample Output 1 
4
4
9
Explanation
Test case 1:

Chef will buy 16 Fuljhari's and 4 Anar's which in total costs him 16⋅5+4⋅5=100 rupees.
Next, he uses 16 Fuljhari's to light 164=4 Anar's.
Since all the Fuljhari's are over, he can't light up any Chakri's.
So in total, he is able to light up 4+0=4 Anar's and Chakri's.
There is no other allocation giving a better answer than this.
Test case 2:

Chef will buy 4 Fuljhari's, 2 Anar's and 2 Chakri's which in total costs him 4⋅2+2⋅2+2⋅2=16 rupees.
Next, he uses 2 Fuljhari's to light 21=2 Anar's.
Next, he uses 2 Fuljhari's to light 21=2 Chakri's.
So in total, he is able to light up 2+2=4 Anar's and Chakri's.
The other possible allocation could be buying 4 Fuljhari's, 3 Anar's, and 1 Chakri.
*/