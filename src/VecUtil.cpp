# include "VecUtil.hpp"

void PrintVec(vector<float>V)
{
    for (int i=0; i<V.size(); i++)
    {
        cout << V[i] << " ";
    }
    cout << endl;
}

void PrintMat(vector<vector<float>>A)
{
    for (int i=0; i<A.size(); i++)
    {
        for (int j=0; j<A[0].size(); j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}