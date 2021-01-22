#include <vector>
#include <gtest/gtest.h>
#include "VecUtil.hpp"
#include "Gauss.hpp"
#include "LU.hpp"
#include "det.hpp"
#include "cond.hpp"
#include "Pivot.hpp"

using namespace std;

// テストで使う共用サンプルデータを定義
class TestFix : public ::testing::Test
{
protected:
    vector<int> IntVec2;
    vector<int> IntVec3;
    vector<vector<int>> IntMat2;
    vector<vector<int>> IntMat3;
    vector<float> FloatVec2;
    vector<float> FloatVec3;
    vector<vector<float>> FloatMat2;
    vector<vector<float>> FloatMat3;

    virtual void SetUp()
    {
        printf("TestFix:SetUp\n");
        IntVec2 = vector<int>{-1, -6};
        IntVec3 = vector<int>{3, 4, 1};
        IntMat2 = vector<vector<int>>{{1, 2}, {4, -1}};
        IntMat3 = vector<vector<int>>{{1, 2, -2}, {1, -1, 3}, {2, 3, -5}};
        FloatVec2 = vector<float>{-1, -6};
        FloatVec3 = vector<float>{3, 4, 1};
        FloatMat2 = vector<vector<float>>{{1, 2}, {4, -1}};
        FloatMat3 = vector<vector<float>>{{1, 2, -2}, {1, -1, 3}, {2, 3, -5}};
    }

    virtual void TearDown()
    {
        printf("TestFix::TearDown\n");
    }
};

// 汎用関数のテスト
TEST_F(TestFix, UtilTest)
{   cout << "ベクトルの出力テスト" << endl;
    PrintVec<vector<int>>(IntVec2);
    cout << "行列の出力テスト" << endl;
    PrintMat<vector<vector<float>>>(FloatMat3);
    // 要素入れ替えテスト
    Exchange<vector<vector<int>>>(IntMat3, 0, 2);
    vector<vector<int>> ExpectedMat{{2, 3, -5}, {1, -1, 3}, {1, 2, -2}};
    EXPECT_EQ(ExpectedMat, IntMat3);
}


// ピボット選択のテスト
TEST_F(TestFix, PivotTest)
{
    // 期待される結果
    vector<vector<float>> ExpectedMat2{{4, -1}, {1, 2}};
    vector<vector<float>> ExpectedMat3{{2, 3, -5}, {1, -1, 3}, {1, 2, -2}};
    // ピボット選択の実行
    int p2 = Pivot(FloatMat2, 0);
    int p3 = Pivot(FloatMat3, 0);
    Exchange(FloatMat2, 0, p2);
    Exchange(FloatMat3, 0, p3);
    // 結果をテスト
    EXPECT_EQ(ExpectedMat2, FloatMat2);
    EXPECT_EQ(ExpectedMat3, FloatMat3);
}

// 前進消去のテスト
TEST_F(TestFix, ForwardErase)
{
    // 期待される結果
    vector<vector<float>> ExpectedMat2{{1, 2}, {0 ,-9}};
    vector<float> ExpectedVec2{-1, -2};
    vector<vector<float>> ExpectedMat3{{1, 2, -2}, {0, -3, 5}, {0, 0, -8.0f/3.0f}};
    vector<float> ExpectedVec3{3, 1, -16.0f/3.0f};
    // 前進消去の実行
    ForwardErase(FloatMat2, FloatVec2, false);
    ForwardErase(FloatMat3, FloatVec3, false);
    // 結果をテスト
    EXPECT_EQ(ExpectedMat2, FloatMat2);
    EXPECT_EQ(ExpectedVec2, FloatVec2);
    EXPECT_EQ(ExpectedMat3, FloatMat3);
    EXPECT_EQ(ExpectedVec3, FloatVec3);
}


// 後退代入のテスト
TEST_F(TestFix, BackSubstition)
{
    vector<float> ExpectedVec3{1, 3, 2};
    ForwardErase(FloatMat3, FloatVec3, false);
    vector<float> ans{0, 0, 0}; // 解となるベクトルの初期化
    BackSubstition(FloatMat3, ans, FloatVec3);
    EXPECT_EQ(ExpectedVec3, ans);
}


// ガウスの消去法のテスト
TEST_F(TestFix, GaussJordan)
{
    vector<float> ExpectedVec{1, 3, 2};
    vector<float> X(3, 0); // 解となるベクトルの初期化
    GaussJordan(FloatMat3, X, FloatVec3);
    EXPECT_EQ(ExpectedVec, X);
}


// クラウト法LU分解のテスト
TEST_F(TestFix, Crout)
{
    vector<int> P;
    vector<vector<float>> ExpectedL{{1, 0}, {0.25f, 1}};
    vector<vector<float>> ExpectedU{{4, -1}, {0, 2.25f}};
    vector<vector<float>> L;
    vector<vector<float>> U;
    Crout(FloatMat2, L, U, P, true);
    EXPECT_EQ(ExpectedL, L);
    EXPECT_EQ(ExpectedU, U);
}


// LU分解による連立方程式の解
TEST_F(TestFix, LUSolve)
{
    vector<float> ExpectedVec{1, 3, 2};
    vector<vector<float>> L(3, vector<float>(3, 0));
    vector<vector<float>> U(3, vector<float>(3, 0));
    vector<int> P;
    Crout(FloatMat3, L, U, P, false);
    vector<float> x(3, 0);
    vector<float> y{3, 4, 1};
    LUSolve(L, U, x, y);
    EXPECT_EQ(ExpectedVec, x);
}


// 行列式のテスト
