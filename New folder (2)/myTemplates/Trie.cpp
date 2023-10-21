struct Node
{
    const static int N = 26; // change this according to ur need
    Node *child[N];
    char data;
    int pre = 0;
    int end = 0;
    Node(char d)
    {
        data = d;
        for (int i = 0; i < N; i++)
        {
            child[i] = nullptr;
        }
    }
    Node *next(int b, char d)
    {
        if (child[b] == nullptr)
        {
            child[b] = new Node(d);
        }
        return child[b];
    }
};
class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node('\0');
    }
    void insert(string s)
    {
        Node *temp = root;
        for (auto it : s)
        {
            int x = it - 'a'; // change this according to ur need
            temp = temp->next(x, it);
            temp->pre++;
        }
        temp->end++;
    }
    void del(string s)
    {
        Node *temp = root;
        for (auto it : s)
        {
            int x = it - 'a'; // change this according to ur need
            temp = temp->next(x, it);
            temp->pre--;
        }
        temp->end--;
    }
    int findxor(string s)
    {
        int ans = 0;
        Node *temp = root;
        for (int i = 0, j = 39; i < 40; i++, j--)
        {
            int mask = (1ll << j);
            if (temp->child[(s[i] - '0') ^ 1] && temp->child[(s[i] - '0') ^ 1]->pre)
            {
                ans += mask;
                temp = temp->child[(s[i] - '0') ^ 1];
            }
            else if (temp->child[(s[i] - '0')])
            {
                temp = temp->child[(s[i] - '0')];
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};

// https://codeforces.com/contest/706/submission/227964061