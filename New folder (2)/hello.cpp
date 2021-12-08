#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
void display(vi vec1)
{
	for (auto it : vec1)
	{
		cout << it << " ";
	}
	cout << endl;
}

vector<int> findEvenNumbers(vector<int> &digits)
{
	unordered_map<int, int> s;
	for (auto it : digits)
	{
		s[it]++;
	}
	vector<int> ans;
	for (int i = 100; i < 999; i++)
	{
		unordered_map<int, int> p = s;
		int flag = 0;
		if (!(i % 2))
		{
			string temp = to_string(i);
			for (int j = 0; j < temp.size(); j++)
			{
				int t = temp[j] - '0';
				if (p.find(t) == p.end())
				{
					break;
				}
				else
				{
					p[t]--;
					if (p[t] == 0)
					{
						p.erase(t);
					}
					flag++;
				}
			}
			if (flag == 3)
			{
				ans.push_back(i);
			}
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	vi vec1 = {2, 1, 3, 0};

	return 0;
}