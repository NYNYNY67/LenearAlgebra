#include <vector>
#include <gtest/gtest.h>
#include "VecUtil.hpp"
#include "Gauss.hpp"
#include "LU.hpp"
#include "det.hpp"
#include "cond.hpp"

using namespace std;

class TestFix : public ::testing::Test
{
protected:
    vector<float> Vec2;
    vector<float> Vec3;
    vector<vector<float>> Mat2;
    vector<vector<float>> Mat3;

    virtual void SetUp()
    {
        printf("TestFix:SetUp\n");
        Vec2 = vector<float>{-1, -6};
        Vec3 = vector<float>{3, 4, 1};
        Mat2 = vector<vector<float>>{{1, 2}, {4, -1}};
        Mat3 = vector<vector<float>>{{1, 2, -2}, {1, -1, 3}, {2, 3, -5}};
    }

    virtual void TearDown()
    {
        printf("TestFix::TearDown\n");
    }
};

// ピボット選択のテスト
TEST_F(TestFix, PivotTest)
{
    // 期待される結果
    vector<vector<float>> ExpectedMat2{{4, -1}, {1, 2}};
    vector<vector<float>> ExpectedMat3{{2, 3, -5}, {1, -1, 3}, {1, 2, -2}};
    // ピボット選択の実行
    Pivot(Mat2, 0);
    Pivot(Mat3, 0);
    // 結果をテスト
    EXPECT_EQ(ExpectedMat2, Mat2);
    EXPECT_EQ(ExpectedMat3, Mat3);
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
    ForwardErase(Mat2, Vec2, false);
    ForwardErase(Mat3, Vec3, false);
    // 結果をテスト
    EXPECT_EQ(ExpectedMat2, Mat2);
    EXPECT_EQ(ExpectedVec2, Vec2);
    EXPECT_EQ(ExpectedMat3, Mat3);
    EXPECT_EQ(ExpectedVec3, Vec3);
}