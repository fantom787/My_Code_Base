 auto issq = [&](int num) -> bool
    {
        int l = 0;
        int h = 1e9;
        int ans = l;
        while (l <= h)
        {
            int mid = (l + h) / 2;
            if (mid * mid <= num)
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }
        return (ans * ans) == num;
    };