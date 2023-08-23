const int sPFN = 1e5 + 10;
vector<int> sPF(N, INF);
void runSPF()
{
    iota(all(sPF), 0ll);
    for (int i = 2; i < sPFN; i++)
    {
        if (sPF[i] != i)
        {
            continue;
        }
        for (int j = i * i; j < sPFN; j++)
        {
            if (sPF[j] != j)
            {
                continue;
            }
            sPF[j] = i;
        }
    }
}