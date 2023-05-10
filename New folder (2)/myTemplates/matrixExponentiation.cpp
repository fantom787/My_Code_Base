struct Matrix
{
    vector<vector<int>> mat;
    int n_row, n_col;
    Matrix() {}
    Matrix(vector<vector<int>> val)
    {
        mat = val;
        n_row = sz(val);
        n_col = sz(val[0]);
    }
    static Matrix identity_matrix(int n)
    {
        vector<vector<int>> val(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            val[i][i] = 1;
        }
        return val;
    }
    Matrix operator*(const Matrix &other) const
    {
        int n = n_row, m = other.n_col;
        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int temp = 0;
                for (int k = 0; k < n_col; k++)
                {
                    temp += mat[i][k] * other.mat[k][j];
                    temp %= MOD;
                }
                ans[i][j] = temp;
            }
        }
        return move(Matrix(move(ans)));
    }
    inline bool is_sq()
    {
        return n_row == n_col;
    }
};
Matrix matpow(Matrix a, int pow)
{
    Matrix ans = Matrix::identity_matrix(a.n_col);
    while (pow)
    {
        if (pow & 1)
        {
            ans = a * ans;
        }
        a = a * a;
        pow >>= 1;
    }
    return ans;
}
Matrix matExpo(Matrix id, Matrix b, int n)
{
    Matrix ans = matpow(id, n);
    ans = ans * b;
    return ans;
}