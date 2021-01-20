#include "VecUtil.hpp"
#include "Gauss.hpp"
#include "LU.hpp"
#include "det.hpp"
#include "cond.hpp"

int main()
{
    /*
    // ベクトルの出力 clear!
    vector<float> V{1,2,3};
    cout << "ベクトルVの出力" << endl;
    PrintVec(V);

    // 行列の出力 clear!
    vector<vector<float>> A{{1,2,-2}, {1,-1,3}, {2,3,-5}};
    cout << "行列Aの出力" << endl;
    PrintMat(A);

    // ピボット選択 clear!
    vector<vector<float>> A{{1,2,-2}, {1,-1,3}, {2,3,-5}};
    Pivot(A, 0);
    cout << "行列Aの出力" << endl;
    PrintMat(A);

    // 前進消去 clear!
    vector<vector<float>> A{{1,2,-2}, {1,-1,3}, {2,3,-5}};
    vector<float> y{3,4,1};
    cout << "行列Aの出力(変換前)" << endl;
    PrintMat(A);

    ForwardErase(A, y);
    cout << "行列Aの出力(前進代入後)" << endl;
    PrintMat(A);
    cout << "ベクトルy(前進代入後)" << endl;
    PrintVec(y);

    // 後退代入 clear!
    vector<float> x(3, 0);
    BackSubstition(A, x, y);
    cout << "方程式の解" << endl;
    PrintVec(x);

    // ガウスの消去法により方程式を解く clear!
    vector<vector<float>> A{{1,2,-2}, {1,-1,3}, {2,3,-5}};
    vector<float> x(3, 0);
    vector<float> y{3,4,1};
    GaussJordan(A, x, y);
    PrintVec(x);

    // クラウト法LU分解 clear!
    vector<vector<float>> A{{2,2,3}, {2,3,4}, {1,1,2}};
    vector<vector<float>> L(3, vector<float>(3, 0));
    vector<vector<float>> U(3, vector<float>(3, 0));
    Crout(A, L, U);
    cout << "LU分解後 L" << endl;
    PrintMat(L);
    cout << "LU分解後 U" << endl;
    PrintMat(U);

    // LU分解によって方程式を解く clear!
    vector<vector<float>> A{{1,2,-2}, {1,-1,3}, {2,3,-5}};
    vector<vector<float>> L(3, vector<float>(3, 0));
    vector<vector<float>> U(3, vector<float>(3, 0));
    Crout(A, L, U);
    vector<float> x(3, 0);
    vector<float> y{3,4,1};
    LUSolve(L, U, x, y);
    PrintVec(x);


    // 行列式を求める clear!
    vector<vector<float>> A{{1, 3, 2}, {5, 4, 6}, {8 , 9, 7}};
    //vector<vector<float>> A{{1,2}, {4,-1}};
    float ret = det(A);
    cout << "行列式：" << ret << endl;
    */
    

}