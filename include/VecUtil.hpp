// いろんな型のベクトルに適用できる関数等を宣言

#pragma once
#include <vector>
#include <iostream>
using namespace std;

template <typename Vec>
void PrintVec(Vec V)
{
    for (int i=0; i<V.size(); i++)
    {
        cout << V[i] << " ";
    }
    cout << endl;
}

template <typename Mat>
void PrintMat(Mat M)
{
    for (int i=0; i<M.size(); i++)
    {
        for (int j=0; j<M[0].size(); j++)
        {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

template <typename Vec>
void Exchange(Vec &V, int i, int j)
{
    auto tmp = V[i];
    V[i] = V[j];
    V[j] = tmp;    
}
