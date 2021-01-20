#pragma once
#include <vector>
using namespace std;

// ガウスの消去法によって方程式を解く
void GaussJordan(vector<vector<float>> A, vector<float> &x, vector<float> y);
// 前進消去
void ForwardErase(vector<vector<float>> &A, vector<float> &y, bool pivot=true);
// ピボット選択, k番目の係数を対象とする O(n)
void Pivot(vector<vector<float> > &A, int k);
// 後退代入
void BackSubstition(const vector<vector<float>> &A, vector<float> &x, const vector<float> &y);
// LU分解された方程式を解く O(n^2)
void LUSolve(const vector<vector<float>> &L, const vector<vector<float>> &U, vector<float> &x, const vector<float> &y);