#include "Gauss.hpp"

// ガウスの消去法によって方程式を解く
void GaussJordan(vector<vector<float>> A, vector<float> &x, vector<float> y)
{
    // 前進消去
    ForwardErase(A, y);
    // 後退代入
    BackSubstition(A, x, y);
}

// 前進消去 O(n^3)
void ForwardErase(vector<vector<float>> &A, vector<float> &y, bool pivot)
{
    int n = A.size();
    for (int i=0; i<n; i++)
    {
        // ピボット選択
        if (pivot) Pivot(A, i);
        for (int j=i+1; j<n; j++)
        {
            float scale = A[j][i] / A[i][i];
            for (int k=i; k<n; k++)
            {
                A[j][k] -= scale * A[i][k];
            }
            y[j] -= scale * y[i];
        }
    }
}

// ピボット選択, k番目の係数を対象とする O(n)
void Pivot(vector<vector<float>> &A, int k)
{
    int n=A.size();
    int row=k;
    float max_a=A[k][k];
    for (int i=k+1; i<n; i++)
    {
        if (A[i][k]>max_a)
        {
            max_a = A[i][k];
            row = i;
        }
    }
    vector<float> tmp(n);
    tmp = A[row];
    A[row] = A[k];
    A[k] = tmp;
}

// 後退代入 O(n^2)
void BackSubstition(const vector<vector<float>> &A, vector<float> &x, const vector<float> &y)
{
    int n=A.size();
    for (int i=n-1; i>=0; i--)
    {
        x[i] = y[i];
        for (int j=i+1; j<n; j++) x[i] -= A[i][j]*x[j];
        x[i] /= A[i][i];
    }
}

// 前進代入 O(n^2)
void FrontSubstition(const vector<vector<float>> &A, vector<float> &x, const vector<float> &y)
{
    int n=A.size();
    for (int i=0; i<n; i++)
    {
        x[i] = y[i];
        for (int j=0; j<i; j++) x[i] -= A[i][j]*x[j];
        x[i] /= A[i][i];
    }
}

// LU分解された方程式を解く O(n^2)
// LUx = y をxについて解く
void LUSolve(const vector<vector<float>> &L, const vector<vector<float>> &U, vector<float> &x, const vector<float> &y)
{
    int n=L.size();
    vector<float> tmp(n, 0); // tmp = Ux　とする。
    FrontSubstition(L, tmp, y);
    BackSubstition(U, x, tmp);
}
