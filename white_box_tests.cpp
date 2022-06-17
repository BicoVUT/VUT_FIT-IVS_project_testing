//======== Copyright (c) 2021, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     White Box - Tests suite
//
// $NoKeywords: $ivs_project_1 $white_box_code.cpp
// $Author:     Filip Brna <xbrnaf00@stud.fit.vutbr.cz>
// $Date:       $2021-02-28
//============================================================================//
/**
 * @file white_box_tests.cpp
 * @author Filip Brna
 * 
 * @brief Implementace testu prace s maticemi.
 */

#include "gtest/gtest.h"
#include "white_box_code.h"
#include <vector>

//============================================================================//
// ** ZDE DOPLNTE TESTY **
//
// Zde doplnte testy operaci nad maticemi. Cilem testovani je:
// 1. Dosahnout maximalniho pokryti kodu (white_box_code.cpp) testy.
// 2. Overit spravne chovani operaci nad maticemi v zavislosti na rozmerech 
//    matic.
//============================================================================//

class MatrixSize : public ::testing::Test{
protected:
    Matrix m{};
};

TEST(BasicTest, MatrixConstructor){
    Matrix m{3,3};
    EXPECT_ANY_THROW(Matrix(-2,2));
    EXPECT_ANY_THROW(Matrix(2,-2));
    EXPECT_ANY_THROW(Matrix(-2,-2));
    EXPECT_ANY_THROW(Matrix(0,-2));
}

TEST(BasicTest, MatrixGetSet){
    Matrix m1{};
    EXPECT_EQ(m1.get(0,0) ,0);
    EXPECT_ANY_THROW(m1.get(5,1));
    EXPECT_FALSE(m1.set(5,5,1));
    EXPECT_FALSE(m1.set(std::vector<std::vector<double>> {
				{1, 2},
				{3, 4},
                }));
}

TEST(BasicTest, Matrix2x2GetSet){
    Matrix m1{2,2};
    EXPECT_TRUE(m1.set(1,1,1));
    EXPECT_EQ(m1.get(1,1) ,1);
    EXPECT_ANY_THROW(m1.get(5,1));
    EXPECT_FALSE(m1.set(5,5,1));
    EXPECT_FALSE(m1.set(std::vector<std::vector<double>> {
				{ 2, 4, 6, 8},
				{16, 8, 2, 20},
                {6, 4, 10, -4},
                {2, 2, 2, 2},
                }));
}

TEST(BasicTest, Matrix3x3GetSet){
    Matrix m1{3,3};
    EXPECT_TRUE(m1.set(2,2,3));
    EXPECT_EQ(m1.get(2,2) ,3);
    EXPECT_ANY_THROW(m1.get(5,1));
    EXPECT_FALSE(m1.set(5,5,1));
    EXPECT_FALSE(m1.set(std::vector<std::vector<double>> {
				{ 2, 4, 6, 8},
				{16, 8, 2, 20},
                {6, 4, 10, -4},
                {2, 2, 2, 2},
                }));
}

TEST(BasicTest, Matrix4x4GetSet){
    Matrix m1{4,4};
    EXPECT_TRUE(m1.set(2,3,4));
    EXPECT_EQ(m1.get(2,3) ,4);
    EXPECT_ANY_THROW(m1.get(6,2));
    EXPECT_FALSE(m1.set(5,5,1));
    EXPECT_FALSE(m1.set(std::vector<std::vector<double>> {
				{ 2, 4, 6, 8, 4},
				{16, 8, 2, 20, 5},
                {6, 4, 10, -4, 6},
                {2, 2, 2, 2, 8},
                {2, 2, 2, 2, 8},
                }));
}

TEST(BasicTest, Matrix3x2GetSet){
    Matrix m1{3,2};
    EXPECT_TRUE(m1.set(1,1,1));
    EXPECT_EQ(m1.get(1,1) ,1);
    EXPECT_ANY_THROW(m1.get(5,1));
}

TEST(BasicTest, MatrixEqual){
    Matrix m1{2,2};
    Matrix m2{};
    Matrix m3{};
    EXPECT_ANY_THROW(m1==m2);
    EXPECT_TRUE(m2==m3);
    m2.set(0,0,2);
    EXPECT_FALSE(m2==m3);
}

TEST(BasicTest, Matrix2x2Equal){
    Matrix m1{1,2};
    Matrix m2{2,2};
    Matrix m3{2,2};
    EXPECT_ANY_THROW(m1==m2);
    m2.set(std::vector<std::vector<double>> {
				{1, 2},
				{3, 4},
                });
    m3.set(std::vector<std::vector<double>> {
				{1, 2},
				{3, 4},
                });
    EXPECT_TRUE(m2==m3);
    m2.set(0,0,2);
    EXPECT_FALSE(m2==m3);
}

TEST(BasicTest, Matrix3x3Equal){
    Matrix m1{1,2};
    Matrix m2{3,3};
    Matrix m3{3,3};
    EXPECT_ANY_THROW(m1==m2);
    m2.set(std::vector<std::vector<double>> {
				{1, 2, 3},
				{3, 4, 5},
                {3, 4, 5},
                });

    m3.set(std::vector<std::vector<double>> {
				{1, 2, 3},
				{3, 4, 5},
                {3, 4, 5},
                });
    EXPECT_TRUE(m2==m3);
    m2.set(0,0,2);
    EXPECT_FALSE(m2==m3);
}

TEST(BasicTest, Matrix4x4Equal){
    Matrix m1{3,2};
    Matrix m2{4,4};
    Matrix m3{4,4};
    EXPECT_ANY_THROW(m1==m2);
    m2.set(std::vector<std::vector<double>> {
				{1, 2, 3, 4},
				{8, 4, 1, 10},
                {3, 2, 5, -2},
                {1, 1, 1, 1},
                });
    m3.set(std::vector<std::vector<double>> {
				{1, 2, 3, 4},
				{8, 4, 1, 10},
                {3, 2, 5, -2},
                {1, 1, 1, 1},
                });
    EXPECT_TRUE(m2==m3);
    m2.set(0,0,2);
    EXPECT_FALSE(m2==m3);
}

TEST(BasicTest, Matrix3x2Equal){
    Matrix m1{2,2};
    Matrix m2{3,2};
    Matrix m3{3,2};
    EXPECT_ANY_THROW(m1==m2);
    m2.set(std::vector<std::vector<double>> {
				{1, 2},
				{7, 4},
                {5, 9},
                });
    m3.set(std::vector<std::vector<double>> {
				{1, 2},
				{7, 4},
                {5, 9},
                });
    EXPECT_TRUE(m2==m3);
    m2.set(0,0,2);
    EXPECT_FALSE(m2==m3);
}

TEST(BasicTest, MatrixPlus){
    Matrix m1{};
    Matrix m2{};
    Matrix m3{2,2};
    m2.set(0,0,1);
    Matrix result = m1+m2;
    EXPECT_EQ(result.get(0,0),1);
    EXPECT_ANY_THROW(Matrix result2 = m2+m3);
}
TEST(BasicTest, Matrix2x2Plus){
    Matrix m1{2,2};
    Matrix m2{2,2};
    Matrix m3{3,3};
    EXPECT_ANY_THROW(Matrix result2 = m2+m3);
    m1.set(std::vector<std::vector<double>> {
				{1, 2},
				{3, 4},
                });
    m2.set(std::vector<std::vector<double>> {
				{2, 4},
				{6, 8},
                });
    Matrix result = m1+m1;
    EXPECT_TRUE(result==m2);
    m1.set(0,1,1);
    result = m1+m1;
    EXPECT_FALSE(result==m2);    
}
TEST(BasicTest, Matrix3x3Plus){
    Matrix m1{3,3};
    Matrix m2{3,3};
    Matrix m3{1,2};
    EXPECT_ANY_THROW(Matrix result2 = m2+m3);
    m1.set(std::vector<std::vector<double>> {
				{1, 2, 3},
				{3, 4, 5},
                {3, 4, 5},
                });
    m2.set(std::vector<std::vector<double>> {
				{2, 4, 6},
				{6, 8, 10},
                {6, 8, 10},
                });
    Matrix result = m1+m1;
    EXPECT_TRUE(result==m2);
    m1.set(0,1,1);
    result = m1+m1;
    EXPECT_FALSE(result==m2);
}
TEST(BasicTest, Matrix4x4Plus){
    Matrix m1{4,4};
    Matrix m2{4,4};
    Matrix m3{2,2};
    EXPECT_ANY_THROW(Matrix result2 = m2+m3);
    m1.set(std::vector<std::vector<double>> {
				{1, 2, 3, 4},
				{8, 4, 1, 10},
                {3, 2, 5, -2},
                {1, 1, 1, 1},
                });
    m2.set(std::vector<std::vector<double>> {
				{ 2, 4, 6, 8},
				{16, 8, 2, 20},
                {6, 4, 10, -4},
                {2, 2, 2, 2},
                });
    Matrix result = m1+m1;
    EXPECT_TRUE(result==m2);
    m1.set(0,1,1);
    result = m1+m1;
    EXPECT_FALSE(result==m2);
}
TEST(BasicTest, Matrix3x2Plus){
    Matrix m1{3,2};
    Matrix m2{3,2};
    Matrix m3{2,2};
    EXPECT_ANY_THROW(Matrix result2 = m2+m3);
    m1.set(std::vector<std::vector<double>> {
				{1, 2},
				{3, 4},
                {5, 6},
                });
    m2.set(std::vector<std::vector<double>> {
				{2, 4},
				{6, 8},
                {10, 12},
                });
    Matrix result = m1+m1;
    EXPECT_TRUE(result==m2);
    m1.set(0,1,1);
    result = m1+m1;
    EXPECT_FALSE(result==m2);
}

TEST(BasicTest, MatrixMul){
    Matrix m1{};
    Matrix m2{};
    Matrix m3{2,2};
    m2.set(0,0,1);
    Matrix result_with_matrix = m1*m2;
    ASSERT_EQ(result_with_matrix.get(0,0),0);
    EXPECT_ANY_THROW(Matrix result_with_matrix_bad = m2*m3);
    Matrix result_with_number = m2*2;
}

TEST(BasicTest, Matrix2x2Mul){
    Matrix m1{2,2};
    Matrix m2{2,2};
    Matrix m3{3,3};
    Matrix result_of_m1_mul_m2{2,2};
    Matrix result_of_m1_mul_number{2,2};
    m1.set(std::vector<std::vector<double>> {
				{1, 2},
				{1, 1},
                });
    m2.set(std::vector<std::vector<double>> {
				{2, 4},
				{6, 8},
                });
    result_of_m1_mul_m2.set(std::vector<std::vector<double>> {
				{14, 20},
				{8, 12},
                });
    result_of_m1_mul_number.set(std::vector<std::vector<double>> {
				{3, 6},
				{3, 3},
                });
    Matrix result_with_matrix = m1*m2;
    EXPECT_TRUE(result_with_matrix==result_of_m1_mul_m2);
    EXPECT_ANY_THROW(Matrix result_with_matrix_bad = m2*m3);
    Matrix result_with_number = m1*3;
    EXPECT_TRUE(result_with_number==result_of_m1_mul_number);
}

TEST(BasicTest, Matrix3x3Mul){
    Matrix m1{3,3};
    Matrix m2{3,3};
    Matrix m3{2,2};
    Matrix result_of_m1_mul_m2{3,3};
    Matrix result_of_m1_mul_number{3,3};
    m1.set(std::vector<std::vector<double>> {
				{1, 2, 3},
				{3, 4, 5},
                {3, 4, 5},
                });
    m2.set(std::vector<std::vector<double>> {
				{2, 4, 6},
				{6, 8, 10},
                {6, 8, 10},
                });
    result_of_m1_mul_m2.set(std::vector<std::vector<double>> {
				{32, 44, 56},
				{60, 84, 108},
                {60, 84, 108},
                });
    result_of_m1_mul_number.set(std::vector<std::vector<double>> {
				{3, 6, 9},
				{9, 12, 15},
                {9, 12, 15},
                });
    Matrix result_with_matrix = m1*m2;
    EXPECT_TRUE(result_with_matrix==result_of_m1_mul_m2);
    EXPECT_ANY_THROW(Matrix result_with_matrix_bad = m2*m3);
    Matrix result_with_number = m1*3;
    EXPECT_TRUE(result_with_number==result_of_m1_mul_number);
}

TEST(BasicTest, Matrix4x4Mul){
    Matrix m1{4,4};
    Matrix m2{4,4};
    Matrix m3{2,2};
    Matrix result_of_m1_mul_m2{4,4};
    Matrix result_of_m1_mul_number{4,4};
    m1.set(std::vector<std::vector<double>> {
				{1, 2, 3, 4},
				{8, 4, 1, 10},
                {3, 2, 5, -2},
                {1, 1, 1, 1},
                });
    m2.set(std::vector<std::vector<double>> {
				{ -2, 4, 6, -8},
				{16, 8, -2, 20},
                {6, -4, 10, -4},
                {2, 2, 2, -2},
                });
    result_of_m1_mul_m2.set(std::vector<std::vector<double>> {
				{56, 16, 40, 12},
				{74, 80, 70, -8},
                {52, 4, 60, 0},
                {22, 10, 16, 6},
                });
    result_of_m1_mul_number.set(std::vector<std::vector<double>> {
				{3, 6, 9, 12},
				{24, 12, 3, 30},
                {9, 6, 15, -6},
                {3, 3, 3, 3},
                });
    Matrix result_with_matrix = m1*m2;
    EXPECT_TRUE(result_with_matrix==result_of_m1_mul_m2);
    EXPECT_ANY_THROW(Matrix result_with_matrix_bad = m2*m3);
    Matrix result_with_number = m1*3;
    EXPECT_TRUE(result_with_number==result_of_m1_mul_number);
}


TEST(BasicTest, MatrixSolveEqualation){
    Matrix m1{};
    m1.set(0,0,1);
    std::vector<double> result;
    result = m1.solveEquation({3});
    EXPECT_EQ(result[0],3);
}

TEST(BasicTest, Matrix2x2SolveEqualation){
    Matrix m1{2,2};
    m1.set(std::vector<std::vector<double>> {
				{1, 1},
				{1, 1},
                });
    std::vector<double> b = {1,2};
    std::vector<double> result;
    EXPECT_ANY_THROW(result = m1.solveEquation(b));
    m1.set(std::vector<std::vector<double>> {
				{1, 2},
				{3, 4},
                });
    result = m1.solveEquation(b);
    EXPECT_EQ(result[0],0);
    EXPECT_EQ(result[1],0.5);
    b = {1,2,3};
    EXPECT_ANY_THROW(m1.solveEquation(b));
}

TEST(BasicTest, Matrix3x3SolveEqualation){
    Matrix m1{3,3};
    m1.set(std::vector<std::vector<double>> {
				{1, 1, 2},
				{1, 1, 1},
                {1, 1, 1},
                });
    std::vector<double> b = {1,2,1};
    std::vector<double> result;
    EXPECT_ANY_THROW(result = m1.solveEquation(b));
    m1.set(2,1,2);
    result = m1.solveEquation(b);
    EXPECT_EQ(result[0],4);
    EXPECT_EQ(result[1],-1);
    EXPECT_EQ(result[2],-1);
    b = {1,2,3,4};
    EXPECT_ANY_THROW(m1.solveEquation(b));
}

TEST(BasicTest, Matrix4x4SolveEqualation){
    Matrix m1{4,4};
    m1.set(std::vector<std::vector<double>> {
				{1, 1, 2, 1},
				{1, 1, 1, 1},
                {1, 2, 1, 1},
                {1, 1, 1, 1},
                });
    std::vector<double> b = {1,2,1,1};
    std::vector<double> result;
    EXPECT_ANY_THROW(result = m1.solveEquation(b));
    m1.set(std::vector<std::vector<double>> {
				{1, 5, 2, 1},
				{2, 4, 1, 1},
                {1, 2, 1, 1},
                {5, 1, -1, 5},
                });
    b = {5,4,3,-6};
    result = m1.solveEquation(b);
    EXPECT_EQ(result[0],3);
    EXPECT_EQ(result[1],-1);
    EXPECT_EQ(result[2],5);
    EXPECT_EQ(result[3],-3);
    b = {1,2,3,4,5};
    EXPECT_ANY_THROW(m1.solveEquation(b));
}

TEST(BasicTest, Matrix3x2SolveEqualation){
    Matrix m1{3,2};
    Matrix m2{3,4};
    Matrix m3{4,2};
    Matrix m4{3,5};
    m1.set(std::vector<std::vector<double>> {
				{1, 2},
				{3, 4},
                {1, 1},
                });
    std::vector<double> b = {1,2};
    std::vector<double> result;
    EXPECT_ANY_THROW(m1.solveEquation(b));
    EXPECT_ANY_THROW(m2.solveEquation(b));
    EXPECT_ANY_THROW(m3.solveEquation(b));
    EXPECT_ANY_THROW(m4.solveEquation(b));
}


TEST(BasicTest, MatrixTranspose){
    Matrix m1{};
    Matrix m2{};
    EXPECT_EQ(m1.transpose(),m2);
}

TEST(BasicTest, Matrix2x2Transpose){
    Matrix m1{2,2};
    m1.set(std::vector<std::vector<double>> {
				{1, 2},
				{3, 4},
                });
    m1 = m1.transpose();
    Matrix m2{2,2};
    m2.set(std::vector<std::vector<double>> {
				{1, 3},
				{2, 4},
                });
    for (auto row = 0; row <= 1; row++){
        for (auto col = 0; col <= 1; col++){
            EXPECT_EQ( m1.get(row,col), m2.get(row, col));
        }
    }
}

TEST(BasicTest, Matrix3x3Transpose){
    Matrix m1{3,3};
    m1.set(std::vector<std::vector<double>> {
				{1, 2, 3},
				{3, 4, 5},
                {3, 4, 5},
                });
    m1 = m1.transpose();
    Matrix m2{3,3};
    m2.set(std::vector<std::vector<double>> {
				{1, 3, 3},
				{2, 4, 4},
                {3, 5, 5},
                });
    for (auto row = 0; row <= 2; row++){
        for (auto col = 0; col <= 2; col++){
            EXPECT_EQ( m1.get(row,col), m2.get(row, col));
        }
    }
}

TEST(BasicTest, Matrix4x4Transpose){
    Matrix m1{4,4};
    m1.set(std::vector<std::vector<double>> {
				{1, 2, 3, 4},
				{8, 4, 1, 10},
                {3, 2, 5, -2},
                {1, 1, 1, 1},
                });
    m1 = m1.transpose();
    Matrix m2{4,4};
    m2.set(std::vector<std::vector<double>> {
				{1, 8, 3, 1},
				{2, 4, 2, 1},
                {3, 1, 5, 1},
                {4, 10, -2, 1},
                });
    for (auto row = 0; row <= 3; row++){
        for (auto col = 0; col <= 3; col++){
            EXPECT_EQ( m1.get(row,col), m2.get(row, col));
        }
    }
}

TEST(BasicTest, Matrix3x2Transpose){
    Matrix m1{3,2};
    m1.set(std::vector<std::vector<double>> {
				{1, 2},
				{3, 4},
                {5, 6},
                });
    m1 = m1.transpose();        
    Matrix m2{2,3};
    m2.set(std::vector<std::vector<double>> {
				{1, 3, 5},
				{2, 4, 6},
                });
    for (auto row = 0; row <= 1; row++){
        for (auto col = 0; col <= 2; col++){
            EXPECT_EQ( m1.get(row,col), m2.get(row, col));
        }
    }
} 
TEST(BasicTest, MatrixInverse){
    Matrix m1{};
    m1.set(0,0,1);
    EXPECT_ANY_THROW(m1.inverse());
}

TEST(BasicTest, Matrix2x2Inverse){
    Matrix m1{2,2};
    m1.set(std::vector<std::vector<double>> {
				{1, 1},
                {1,1},
                });
    EXPECT_ANY_THROW(m1.inverse()); 
    m1.set(std::vector<std::vector<double>> {
				{5, 2},
                {-7,-3},
                });
    Matrix m2{2,2};
    m2.set(std::vector<std::vector<double>> {
				{3, 2},
                {-7,-5},
                });
    EXPECT_EQ(m1.inverse(),m2);
}

TEST(BasicTest, Matrix3x3Inverse){
    Matrix m1{3,3};
    m1.set(std::vector<std::vector<double>> {
				{1, 0, -2},
                {-2, 0, 3},
				{1, -1, -3},
                });
    Matrix m2{3,3};
    m2.set(std::vector<std::vector<double>> {
				{-3,-2,0},
				{3,1,-1}, 
                {-2,-1,0}, 
                });
    EXPECT_EQ(m1.inverse(),m2);
}

TEST(BasicTest, Matrix4x4Inverse){
    Matrix m1{4,4};
    EXPECT_ANY_THROW(m1.inverse());
}
/*** Konec souboru white_box_tests.cpp ***/
