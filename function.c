#include<stdio.h>
#include<stdbool.h>
#include"interface.h"


Matrix* createMatrix(int row_number,int column_number){
    Matrix* matrix1=(Matrix*)malloc(sizeof(Matrix));
    (*matrix1).row_number = row_number;
    (*matrix1).column_number = column_number;
    (*matrix1).pData=(float*)malloc(column_number*row_number*sizeof(float));
    for(int i=0;i<(*matrix1).row_number;i++){
        for(int j=0;j<(*matrix1).column_number;j++){
            (*matrix1).pData[i*(*matrix1).column_number+j]=(float)i+j+2;
        }
    }
    return matrix1;
}
//
void deleteMatrix(Matrix* pmatrix1){
    if(judge_point_valid(pmatrix1)==false){
        printf("The matrix doesn't exist\n");
        return;
    }
    free((*pmatrix1).pData);
    free(pmatrix1);
}
//
void copyMatrix(const Matrix* const pmatrix1,Matrix* pmatrix2){
    if(judge_point_valid(pmatrix1)==false || judge_point_valid(pmatrix2)==false){
        printf("The matrix doesn't exist\n");
        return;
    }
    if(judge_twoMatrices_sameSize(pmatrix1,pmatrix2)==true){
        int column = (*pmatrix1).column_number;
        int row = (*pmatrix1).row_number;
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                (*pmatrix2).pData[i*column+j]=(*pmatrix1).pData[i*column+j];
            }
        }
    }else{
        printf("please input two matrices with same size\n");
    }
}
//
void addMatrices(const Matrix* const pmatrix1,const Matrix* const pmatrix2,Matrix* pmatrix3){
    if(judge_point_valid(pmatrix1)==false || judge_point_valid(pmatrix2)==false || judge_point_valid(pmatrix3)==false){
        printf("The matrix doesn't exist\n");
        return;
    }
    if(judge_twoMatrices_sameSize(pmatrix1,pmatrix2)==true && judge_twoMatrices_sameSize(pmatrix2,pmatrix3)==true){
        int column = (*pmatrix1).column_number;
        int row = (*pmatrix1).row_number;
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                (*pmatrix3).pData[i*column+j]=(*pmatrix2).pData[i*column+j]+(*pmatrix1).pData[i*column+j];
            }
        }
    }else{
        printf("please input three matrices with same size\n");
    }
}
//
void substractMatrices(const Matrix* const pmatrix1,const Matrix* const pmatrix2,Matrix* pmatrix3){
    if(judge_point_valid(pmatrix1)==false || judge_point_valid(pmatrix2)==false || judge_point_valid(pmatrix3)==false){
        printf("The matrix doesn't exist\n");
        return;
    }
    if(judge_twoMatrices_sameSize(pmatrix1,pmatrix2)==true){
        int column = (*pmatrix1).column_number;
        int row = (*pmatrix1).row_number;
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                (*pmatrix3).pData[i*column+j]=(*pmatrix1).pData[i*column+j]-(*pmatrix2).pData[i*column+j];
            }
        }
    }else{
        printf("please input three matrices with same size\n");
    }
}
//
void matrixAddScalar(Matrix* pmatrix1,float scalar){
    if(judge_point_valid(pmatrix1)==false){
        printf("The matrix doesn't exist\n");
        return;
    }
    int column = (*pmatrix1).column_number;
    int row = (*pmatrix1).row_number;
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            (*pmatrix1).pData[i*column+j]=(*pmatrix1).pData[i*column+j]+scalar;
        }
    }
}
//
void matrixSubstractScalar(Matrix* pmatrix1,float scalar){
    if(judge_point_valid(pmatrix1)==false){
        printf("The matrix doesn't exist\n");
        return;
    }
    int column = (*pmatrix1).column_number;
    int row = (*pmatrix1).row_number;
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            (*pmatrix1).pData[i*column+j]=(*pmatrix1).pData[i*column+j]-scalar;
        }
    }
}
//
void matrixMultipyScalar(Matrix* pmatrix1,float scalar){
    if(judge_point_valid(pmatrix1)==false){
        printf("The matrix doesn't exist\n");
        return;
    }
    int column = (*pmatrix1).column_number;
    int row = (*pmatrix1).row_number;
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            (*pmatrix1).pData[i*column+j]=(*pmatrix1).pData[i*column+j]*scalar;
        }
    }
}
//
void multipyMatrices(const Matrix* const pmatrix1,const Matrix* const pmatrix2,Matrix* pmatrix3){
    if(judge_point_valid(pmatrix1)==false || judge_point_valid(pmatrix2)==false || judge_point_valid(pmatrix3)==false){
        printf("The matrix doesn't exist\n");
        return;
    }
    if(judge_twoMatrices_canMultipy(pmatrix1,pmatrix2,pmatrix3)==true){
        int col1 = (*pmatrix1).column_number;
        int row1 = (*pmatrix1).row_number;
        int col2 = (*pmatrix2).column_number;
        int row2 = (*pmatrix2).row_number;
        int col3 = (*pmatrix3).column_number;
        int row3 = (*pmatrix3).row_number;
        for(int i=0;i<row3;i++){    
            for(int j=0;j<col3;j++){
                for(int k=0;k<col1;k++){
                    (*pmatrix3).pData[i*col3+j] += (*pmatrix1).pData[i*col1+k]*(*pmatrix2).pData[k*col2+j];
                }
            }
        }
    }else{
        printf("please input three matrices with valid size\n");
    }
}
//

// void multipyMatrices_ijk(const Matrix* const pmatrix1,const Matrix* const pmatrix2,Matrix* pmatrix3){
//     if(judge_point_valid(pmatrix1)==false || judge_point_valid(pmatrix2)==false || judge_point_valid(pmatrix3)==false){
//         printf("The matrix doesn't exist\n");
//         return;
//     }
//     if(judge_twoMatrices_canMultipy(pmatrix1,pmatrix2,pmatrix3)==true){
//         int col1 = (*pmatrix1).column_number;
//         int row1 = (*pmatrix1).row_number;
//         int col2 = (*pmatrix2).column_number;
//         int row2 = (*pmatrix2).row_number;
//         int col3 = (*pmatrix3).column_number;
//         int row3 = (*pmatrix3).row_number;
//         for(int i=0;i<row3;i++){    
//             for(int j=0;j<col3;j++){
//                 for(int k=0;k<col1;k++){
//                     (*pmatrix3).pData[i*col3+j] += (*pmatrix1).pData[i*col1+k]*(*pmatrix2).pData[k*col2+j];
//                 }
//             }
//         }
//     }else{
//         printf("please input three matrices with valid size\n");
//     }
// }
// //////
// void multipyMatrices_ikj(const Matrix* const pmatrix1,const Matrix* const pmatrix2,Matrix* pmatrix3){
//     if(judge_point_valid(pmatrix1)==false || judge_point_valid(pmatrix2)==false || judge_point_valid(pmatrix3)==false){
//         printf("The matrix doesn't exist\n");
//         return;
//     }
//     if(judge_twoMatrices_canMultipy(pmatrix1,pmatrix2,pmatrix3)==true){
//         int col1 = (*pmatrix1).column_number;
//         int row1 = (*pmatrix1).row_number;
//         int col2 = (*pmatrix2).column_number;
//         int row2 = (*pmatrix2).row_number;
//         int col3 = (*pmatrix3).column_number;
//         int row3 = (*pmatrix3).row_number;
//         for(int i=0;i<row3;i++){    
//             for(int k=0;k<col1;k++){
//                 for(int j=0;j<col3;j++){
//                     (*pmatrix3).pData[i*col3+j] += (*pmatrix1).pData[i*col1+k]*(*pmatrix2).pData[k*col2+j];
//                 }
//             }
//         }
//     }else{
//         printf("please input three matrices with valid size\n");
//     }
// }
// //
// void multipyMatrices_jik(const Matrix* const pmatrix1,const Matrix* const pmatrix2,Matrix* pmatrix3){
//     if(judge_point_valid(pmatrix1)==false || judge_point_valid(pmatrix2)==false || judge_point_valid(pmatrix3)==false){
//         printf("The matrix doesn't exist\n");
//         return;
//     }
//     if(judge_twoMatrices_canMultipy(pmatrix1,pmatrix2,pmatrix3)==true){
//         int col1 = (*pmatrix1).column_number;
//         int row1 = (*pmatrix1).row_number;
//         int col2 = (*pmatrix2).column_number;
//         int row2 = (*pmatrix2).row_number;
//         int col3 = (*pmatrix3).column_number;
//         int row3 = (*pmatrix3).row_number;
//         for(int j=0;j<col3;j++){
//             for(int i=0;i<row3;i++){    
//                 for(int k=0;k<col1;k++){             
//                     (*pmatrix3).pData[i*col3+j] += (*pmatrix1).pData[i*col1+k]*(*pmatrix2).pData[k*col2+j];
//                 }
//             }
//         }
//     }else{
//         printf("please input three matrices with valid size\n");
//     }
// }
// //
// void multipyMatrices_jki(const Matrix* const pmatrix1,const Matrix* const pmatrix2,Matrix* pmatrix3){
//     if(judge_point_valid(pmatrix1)==false || judge_point_valid(pmatrix2)==false || judge_point_valid(pmatrix3)==false){
//         printf("The matrix doesn't exist\n");
//         return;
//     }
//     if(judge_twoMatrices_canMultipy(pmatrix1,pmatrix2,pmatrix3)==true){
//         int col1 = (*pmatrix1).column_number;
//         int row1 = (*pmatrix1).row_number;
//         int col2 = (*pmatrix2).column_number;
//         int row2 = (*pmatrix2).row_number;
//         int col3 = (*pmatrix3).column_number;
//         int row3 = (*pmatrix3).row_number;
//         for(int j=0;j<col3;j++){    
//             for(int k=0;k<col1;k++){
//                 for(int i=0;i<row3;i++){
//                     (*pmatrix3).pData[i*col3+j] += (*pmatrix1).pData[i*col1+k]*(*pmatrix2).pData[k*col2+j];
//                 }
//             }
//         }
//     }else{
//         printf("please input three matrices with valid size\n");
//     }
// }
// //
// void multipyMatrices_kij(const Matrix* const pmatrix1,const Matrix* const pmatrix2,Matrix* pmatrix3){
//     if(judge_point_valid(pmatrix1)==false || judge_point_valid(pmatrix2)==false || judge_point_valid(pmatrix3)==false){
//         printf("The matrix doesn't exist\n");
//         return;
//     }
//     if(judge_twoMatrices_canMultipy(pmatrix1,pmatrix2,pmatrix3)==true){
//         int col1 = (*pmatrix1).column_number;
//         int row1 = (*pmatrix1).row_number;
//         int col2 = (*pmatrix2).column_number;
//         int row2 = (*pmatrix2).row_number;
//         int col3 = (*pmatrix3).column_number;
//         int row3 = (*pmatrix3).row_number;
//         for(int k=0;k<col1;k++){
//             for(int i=0;i<row3;i++){
//                 for(int j=0;j<col3;j++){
//                     (*pmatrix3).pData[i*col3+j] += (*pmatrix1).pData[i*col1+k]*(*pmatrix2).pData[k*col2+j];
//                 }
//             }
//         }
//     }else{
//         printf("please input three matrices with valid size\n");
//     }
// }
// //
// void multipyMatrices_kji(const Matrix* const pmatrix1,const Matrix* const pmatrix2,Matrix* pmatrix3){
//     if(judge_point_valid(pmatrix1)==false || judge_point_valid(pmatrix2)==false || judge_point_valid(pmatrix3)==false){
//         printf("The matrix doesn't exist\n");
//         return;
//     }
//     if(judge_twoMatrices_canMultipy(pmatrix1,pmatrix2,pmatrix3)==true){
//         int col1 = (*pmatrix1).column_number;
//         int row1 = (*pmatrix1).row_number;
//         int col2 = (*pmatrix2).column_number;
//         int row2 = (*pmatrix2).row_number;
//         int col3 = (*pmatrix3).column_number;
//         int row3 = (*pmatrix3).row_number;    
//         for(int k=0;k<col1;k++){
//             for(int j=0;j<col3;j++){
//                 for(int i=0;i<row3;i++){
//                     (*pmatrix3).pData[i*col3+j] += (*pmatrix1).pData[i*col1+k]*(*pmatrix2).pData[k*col2+j];
//                 }
//             }
//         }
//     }else{
//         printf("please input three matrices with valid size\n");
//     }
// }
//////
//

//
float minimalValueOfMatrix(const Matrix* const pmatrix1){
    if(judge_point_valid(pmatrix1)==false){
        printf("The matrix doesn't exist\n");
        return;
    }
    int col1 = (*pmatrix1).column_number;
    int row1 = (*pmatrix1).row_number;
    float min = (*pmatrix1).pData[0];
    for(int i=0;i<row1;i++){
        for(int j=0;j<col1;j++){
            if((*pmatrix1).pData[i*col1+j]<=min){
                min = (*pmatrix1).pData[i*col1+j];
            }
        }
    }
    return min;
}
//
float maximalValueOfMatrix(const Matrix* const pmatrix1){
    if(judge_point_valid(pmatrix1)==false){
        printf("The matrix doesn't exist\n");
        return;
    }
    int col1 = (*pmatrix1).column_number;
    int row1 = (*pmatrix1).row_number;
    float max = (*pmatrix1).pData[0];
    for(int i=0;i<row1;i++){
        for(int j=0;j<col1;j++){
            if((*pmatrix1).pData[i*col1+j]>=max){
                max = (*pmatrix1).pData[i*col1+j];
            }
        }
    }
    return max;
}
//
void showMatrix(const Matrix* const pmatrix1){
    if(judge_point_valid(pmatrix1)==false){
        printf("The matrix doesn't exist\n");
        return;
    }
    int column = (*pmatrix1).column_number;
    int row = (*pmatrix1).row_number;
    printf("Matrix:\n");
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            printf("%f\t",(*pmatrix1).pData[i*column+j]);
        }
        printf("\n");
    }
}
//