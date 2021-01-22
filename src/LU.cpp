#include "LU.hpp"
#include "Gauss.hpp"
#include "VecUtil.hpp"
#include "Pivot.hpp"

// クラウト法によるLU分解
void Crout(vector<vector<float>>A, vector<vector<float>>&L, vector<vector<float>>&U, vector<int> &P, bool pivot)
{
    int n = A.size();

    // L, Uを初期化
    L = vector<vector<float>>(n, vector<float>(n, 0));
    U = vector<vector<float>>(n, vector<float>(n, 0));
    P.resize(n);
    for (int i=0; i<n; i++) P[i]=i;

    // Lの対角は1
    for (int i=0; i<n; i++) L[i][i] = 1;

    for (int i=0; i<n; i++)
    {
        if (pivot)
        {
            int prow = Pivot(A, i);
            Exchange<vector<vector<float>>>(A, prow, i);
            Exchange<vector<int>>(P, prow, i);
        }
        
        for (int j=0; j<i; j++)
        {
            L[i][j] = A[i][j];
            for (int k=0; k<j; k++)
            {
                L[i][j] -= L[i][k] * U[k][j];
            }
            L[i][j] /= U[j][j];
        }

        for (int j=i; j<n; j++)
        {
            U[i][j] = A[i][j];
            for (int k=0; k<i; k++)
            {
                U[i][j] -= L[i][k] * U[k][j];
            }
        }
    }
}

// LU分解された方程式を解く O(n^2)
// LUx = y をxについて解く
void LUSolve(vector<vector<float>> L, vector<vector<float>> U, vector<float> &x, vector<float> y)
{
    int n=L.size();
    vector<float> tmp(n, 0); // tmp = Ux　とする。
    ForwardErase(L, y, false);
    for (int i=0; i<n; i++) tmp[i] = y[i] / L[i][i];
    BackSubstition(U, x, tmp);
}
