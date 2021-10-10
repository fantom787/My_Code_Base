// https://leetcode.com/problems/flipping-an-image/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void display(vector<vector<int>> &image)
{
    for (int i = 0; i < image.size(); i++)
    {
        for (int j = 0; j < image[i].size(); j++)
        {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

vector<vector<int>> flipAndInvertImage(vector<vector<int>> &image)
{
    for (int i = 0; i < image.size(); i++)
    {
        for (int j = 0; j < (image[i].size()+1) / 2; j++)
        {
            int temp = image[i][j] ^ 1;
            image[i][j] = image[i][image[i].size() - 1 - j] ^ 1;
            image[i][image[i].size() - 1 - j] = temp;
        }
    }
    return image;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<vector<int>> image = {{1, 1, 0},
                                 {1, 0, 1},
                                 {0, 0, 0}};
    display(image);
    image = flipAndInvertImage(image);
    display(image);
    return 0;
}