int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    vector<int> spf = sieve(1e6 + 1), pref(1e6 + 1);
    spf[1] = -1;
    pref[0] = pref[1] = 0;

    fori(2, 1e6, 1)
    {
        pref[i] = pref[i - 1];
        if (spf[i] != i)
            continue;

        string s = to_string(i);
        if (count(s.begin(), s.begin(), '0'))
            continue;

        bool flag = true;

        while (s.size() > 1)
        {
            s = s.substr(1);
            if (spf[stoll(s)] != stoll(s))
            {
                flag = false;
                break;
            }
        }

        pref[i] += flag;
    }

    while (t--)
    {
        int n;
        cin >> n;

        cout << pref[n] << "\n";
    }

    return 0;
}