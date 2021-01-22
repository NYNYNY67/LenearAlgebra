#include "Pivot.hpp"
#include <complex>

// ピボット選択, row番目の係数を対象とする O(n)
int Pivot(const vector<vector<float>> &A, int row)
{
    int n = A.size();
    int selected = row;
    float max_a = A[row][row];
    for(int i=row+1; i<n; i++)
    {
        if (max_a<std::abs(A[i][row]))
        {
            max_a = A[i][row];
            selected = i;
        }
    }
    return selected;
}
