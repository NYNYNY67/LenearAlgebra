#include "det.hpp"

float det(vector<vector<float>> A)
{
    float ret=1;
    int n = A.size();
    vector<float> tmp(n, 0);
    ForwardErase(A, tmp, false);
    for (int i=0; i<n; i++) ret *= A[i][i];
    return ret;
}
