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
};