struct cc
{
    map<int, int> compress, decompress;
    int c = 0;
    int add(int x)
    {
        if (!compress.count(x))
        {
            compress[x] = c++;
        }
        return compress[x];
    }
    void init(vector<int> a)
    {
        sort(all(a));
        for (auto it : a)
        {
            int x = add(it);
            decompress[x] = it;
        }
    }
}