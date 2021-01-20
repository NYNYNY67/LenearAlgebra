#pragma once
#include <vector>
using namespace std;

// クラウト法によるLU分解
void Crout(const vector<vector<float>>&A, vector<vector<float>>&L, vector<vector<float>>&U);
