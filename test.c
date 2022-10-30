#include<stdio.h>
#include<stdbool.h>
#include <stdlib.h>
#include<time.h>
#include"interface.h"
#define deleteMatrix(x) (deleteMatrix(x),x=NULL)

int main(){
    Matrix* pmatrix1 = createMatrix(3,4);
    Matrix* pmatrix2 = createMatrix(5,2);
    Matrix* pmatrix3 = createMatrix(1,3);
    Matrix* pmatrix4 = createMatrix(6,3);
    Matrix* pmatrix5 = createMatrix(2,3);
    Matrix* pmatrix6 = createMatrix(3,4);
    Matrix* pmatrix7 = createMatrix(3,4);
    Matrix* pmatrix8 = createMatrix(3,4);
    Matrix* pmatrix9 = createMatrix(3,4);
    Matrix* pmatrix10 = createMatrix(5,3);

    // clock_t start, end;


printf("~~~~~1\n");
    addMatrices(pmatrix1,pmatrix6,pmatrix7);
    showMatrix(pmatrix1);showMatrix(pmatrix6);showMatrix(pmatrix7);
printf("~~~~~2\n");
    addMatrices(pmatrix1,pmatrix2,pmatrix3);
    showMatrix(pmatrix1);showMatrix(pmatrix2);showMatrix(pmatrix3);
printf("~~~~~3\n");
    substractMatrices(pmatrix1,pmatrix8,pmatrix9);
    showMatrix(pmatrix1);showMatrix(pmatrix8);showMatrix(pmatrix9);
printf("~~~~~4\n");    
    substractMatrices(pmatrix1,pmatrix2,pmatrix3);
    showMatrix(pmatrix1);showMatrix(pmatrix2);showMatrix(pmatrix3);
printf("~~~~~5\n");
    matrixAddScalar(pmatrix2,10.0);
    showMatrix(pmatrix2);
printf("~~~~~6\n");
    matrixSubstractScalar(pmatrix3,10.0);
    showMatrix(pmatrix3);
printf("~~~~~7\n");
    matrixMultipyScalar(pmatrix4,10.0);
    showMatrix(pmatrix4);
printf("~~~~~8\n");
    multipyMatrices(pmatrix2,pmatrix5,pmatrix10);
    showMatrix(pmatrix2);showMatrix(pmatrix5);showMatrix(pmatrix10);
printf("~~~~~9\n");
    showMatrix(pmatrix10);
    delete(pmatrix10);
    showMatrix(pmatrix10);
    printf("min = %f\n",minimalValueOfMatrix(pmatrix10));
    printf("max = %f\n",maximalValueOfMatrix(pmatrix10));
printf("~~~~~\n");



    // start = clock();
    // for(int i=0;i<10000000;i++){
    //     multipyMatrices_ijk(pmatrix2,pmatrix5,pmatrix10);
    // }
    // end = clock();
    // printf("ijk = %lf\n",(double)(end - start)/CLOCKS_PER_SEC);
    // start = clock();
    // for(int i=0;i<10000000;i++){
    //     multipyMatrices_ikj(pmatrix2,pmatrix5,pmatrix10);
    // }
    // end = clock();
    // printf("ikj = %lf\n",(double)(end - start)/CLOCKS_PER_SEC);
    // start = clock();
    // for(int i=0;i<10000000;i++){
    //     multipyMatrices_jik(pmatrix2,pmatrix5,pmatrix10);
    // }
    // end = clock();
    // printf("jik = %lf\n",(double)(end - start)/CLOCKS_PER_SEC);
    // start = clock();
    // for(int i=0;i<10000000;i++){
    //     multipyMatrices_jki(pmatrix2,pmatrix5,pmatrix10);
    // }
    // end = clock();
    // printf("jki = %lf\n",(double)(end - start)/CLOCKS_PER_SEC);
    // start = clock();
    // for(int i=0;i<10000000;i++){
    //     multipyMatrices_kij(pmatrix2,pmatrix5,pmatrix10);
    // }
    // end = clock();
    // printf("kij = %lf\n",(double)(end - start)/CLOCKS_PER_SEC);
    // start = clock();
    // for(int i=0;i<10000000;i++){
    //     multipyMatrices_kji(pmatrix2,pmatrix5,pmatrix10);
    // }
    // end = clock();
    // printf("kji = %lf\n",(double)(end - start)/CLOCKS_PER_SEC);

    return 0;
}
