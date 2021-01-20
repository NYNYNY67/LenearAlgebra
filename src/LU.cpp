#include "LU.hpp"

// クラウト法によるLU分解
void Crout(const vector<vector<float>>&A, vector<vector<float>>&L, vector<vector<float>>&U)
{
    int n = A.size();

    // L, Uを初期化
    L = vector<vector<float>>(n, vector<float>(n, 0));
    U = vector<vector<float>>(n, vector<float>(n, 0));
    // Lの対角は1
    for (int i=0; i<n; i++) L[i][i] = 1;

    for (int i=0; i<n; i++)
    {
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
