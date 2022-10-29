#include<stdio.h>
#include<stdbool.h>
#include"interface.h"

bool judge_columeAndRowNumber_invalid(int column_number,int row_number){
    bool flag = false;
    if(column_number<=0 || row_number<=0){
        flag = false;
    }else{
        flag = true;
    }
    return flag;
}

bool judge_twoMatrices_sameSize(const Matrix* const pmatrix1,const Matrix* const pmatrix2){
    bool flag = false;
    int col1 = (*pmatrix1).column_number;
    int row1 = (*pmatrix1).row_number;
    int col2 = (*pmatrix2).column_number;
    int row2 = (*pmatrix2).row_number;
    if(col1==col2 && row1==row2){
        flag = true;
    }else{
        flag = false;
    }
    return flag;
}

bool judge_twoMatrices_canMultipy(const Matrix* const pmatrix1,const Matrix* const pmatrix2,const Matrix* const pmatrix3){
    bool flag = false;
    int col1 = (*pmatrix1).column_number;
    int row1 = (*pmatrix1).row_number;
    int col2 = (*pmatrix2).column_number;
    int row2 = (*pmatrix2).row_number;
    int col3 = (*pmatrix3).column_number;
    int row3 = (*pmatrix3).row_number;
    if(col1==row2 && row1==row3 && col2==col3){
        flag = true;
    }else{
        flag = false;
    }
    return flag;
}

bool judge_point_valid(const Matrix* const pmatrix1){
    if(!pmatrix1){
        return false;
    }else{
        return true;
    }
}

