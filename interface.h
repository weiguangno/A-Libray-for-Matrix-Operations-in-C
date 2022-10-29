#include<stdio.h>
#include<stdbool.h>
#include <stdlib.h>

typedef struct Matrix
{
    int row_number;
    int column_number;
    float * pData;
} Matrix;

Matrix* createMatrix(int column_number,int row_number);
void deleteMatrix(Matrix* pmatrix1);
void copyMatrix(const Matrix* const pmatrix1,Matrix* pmatrix2);
void addMatrices(const Matrix* const pmatrix1,const Matrix* const pmatrix2,Matrix* pmatrix3);
void substractMatrices(const Matrix* const pmatrix1,const Matrix* const pmatrix2,Matrix* pmatrix3);
void matrixAddScalar(Matrix* pmatrix1,float scalar);
void matrixSubstractScalar(Matrix* pmatrix1,float scalar);
void matrixMultipyScalar(Matrix* pmatrix1,float scalar);
void multipyMatrices(const Matrix* const pmatrix1,const Matrix* const pmatrix2,Matrix* pmatrix3);
// void multipyMatrices_ijk(const Matrix* const pmatrix1,const Matrix* const pmatrix2,Matrix* pmatrix3);
// void multipyMatrices_ikj(const Matrix* const pmatrix1,const Matrix* const pmatrix2,Matrix* pmatrix3);
// void multipyMatrices_jik(const Matrix* const pmatrix1,const Matrix* const pmatrix2,Matrix* pmatrix3);
// void multipyMatrices_jki(const Matrix* const pmatrix1,const Matrix* const pmatrix2,Matrix* pmatrix3);
// void multipyMatrices_kij(const Matrix* const pmatrix1,const Matrix* const pmatrix2,Matrix* pmatrix3);
// void multipyMatrices_kji(const Matrix* const pmatrix1,const Matrix* const pmatrix2,Matrix* pmatrix3);
float minimalValueOfMatrix(const Matrix* const pmatrix1);
float maximalValueOfMatrix(const Matrix* const pmatrix1);
void showMatrix(const Matrix* const pmatrix1);

bool judge_columeAndRowNumber_invalid(int column_number,int row_number);
bool judge_twoMatrices_sameSize(const Matrix* const pmatrix1,const Matrix* const pmatrix2);
bool judge_twoMatrices_canMultipy(const Matrix* const pmatrix1,const Matrix* const pmatrix2,const Matrix* const pmatrix3);
bool judge_point_valid(const Matrix* const pmatrix1);
