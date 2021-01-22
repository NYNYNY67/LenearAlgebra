#include "Gauss.hpp"
#include "Pivot.hpp"
#include "VecUtil.hpp"
#include <complex>

// ガウスの消去法によって方程式を解く
void GaussJordan(vector<vector<float>> A, vector<float> &x, vector<float> y)
{
    // 前進消去
    ForwardErase(A, y, true);
    // 後退代入
    BackSubstition(A, x, y);
}

// 前進消去 O(n^3)
void ForwardErase(vector<vector<float>> &A, vector<float> &y, bool pivot)
{
    int n = A.size();

    for (int i=0; i<n; i++)
    {
        if (pivot)
        {
            int prow = Pivot(A, i);
            Exchange<vector<vector<float>>>(A, i, prow);
            Exchange<vector<float>>(y, i, prow);
        }

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


