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
    vector<vector<float>> Mat2;
    vector<vector<float>> Mat3;

    virtual void SetUp()
    {
        printf("TestFix:SetUp\n");
        Mat2 = vector<vector<float>>{{1,2}, {4,-1}};
        Mat3 = vector<vector<float>>{{1,2,-2}, {1,-1,3}, {2,3,-5}};
    }

    virtual void TearDown()
    {
        printf("TestFix::TearDown\n");
    }
};

TEST_F(TestFix, PivotTest)
{
    vector<vector<float>> ExpectedMat2{{4,-1}, {1,2}};
    vector<vector<float>> ExpectedMat3{{2,3,-5}, {1,-1,3}, {1,2,-2}};
    Pivot(Mat2, 0);
    Pivot(Mat3, 0);
    EXPECT_EQ(ExpectedMat2, Mat2);
    EXPECT_EQ(ExpectedMat3, Mat3);
}
