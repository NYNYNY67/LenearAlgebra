#pragma once
#include <vector>
using namespace std;

// クラウト法によるLU分解
void Crout(vector<vector<float>>A, vector<vector<float>>&L, vector<vector<float>>&U, vector<int> &P, bool pivot=true);
// LU分解された方程式を解く O(n^2)
void LUSolve(vector<vector<float>> L, vector<vector<float>> U, vector<float> &x, vector<float> y);
