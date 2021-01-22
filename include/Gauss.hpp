#pragma once
#include <vector>
using namespace std;

// ガウスの消去法によって方程式を解く
void GaussJordan(vector<vector<float>> A, vector<float> &x, vector<float> y);
// 前進消去
void ForwardErase(vector<vector<float>> &A, vector<float> &y, bool pivot=true);
// 後退代入
void BackSubstition(const vector<vector<float>> &A, vector<float> &x, const vector<float> &y);
// 前進代入 O(n^2)
void FrontSubstition(const vector<vector<float>> &A, vector<float> &x, const vector<float> &y);