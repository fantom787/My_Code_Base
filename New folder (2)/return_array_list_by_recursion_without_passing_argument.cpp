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
	for (int i = 0; i < vec1.size(); i++)
	{
		cout << vec1[i] << " ";
	}
	cout << "\n";
}

vi find_all_index(vi vec1, int target, int index)
{
	vi list;
	if (index == vec1.size())
	{
		return list;
	}
	if (vec1[index] == target)
	{
		list.push_back(index);
	}
	vi prevlist = find_all_index(vec1, target, index + 1);
	list.insert(list.end(),all(prevlist));
	return list;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	vi vec1 = {1, 3, 7, 5, 3, 8, 3, 9, 3, 7, 1, 3};
	display(vec1);
	display(find_all_index(vec1, 3, 0));

	return 0;
}