#include <stdio.h>

typedef struct{
    float xPoints[10];
    float yPoints[10];
    float xBar;
    float yBar;
} dataSet;

void populateMeans(dataSet *dSPtr);
void correctSystematicErrorByVal(dataSet dS);
void correctSystematicErrorByRef(dataSet *dSPtr);

int main(){
    dataSet myDataSet;

    float myXPoints[10] = {0,1,2,3,4,5,6,7,8,9};
    float myYPoints[10] = {2.1,2.4,2.9,3.1,3.6,3.9,4.5,4.8,5.2,5.5};

    for(int i = 0;i<10; i++){
        myDataSet.xPoints[i] = myXPoints[i];
    }
    for(int i = 0;i<10; i++){
        myDataSet.yPoints[i] = myYPoints[i];
    }

    populateMeans(&myDataSet);

    printf("Before Function:\n");
    printf("y\t");
    for(int i = 0;i<10; i++){
        printf("%0.1f\t", myDataSet.yPoints[i]);
    }
    printf("\nx\t");
    for(int i = 0;i<10; i++){
        printf("%0.1f\t", myDataSet.xPoints[i]);
    }
    printf("\n");

    correctSystematicErrorByVal(myDataSet);
    //correctSystematicErrorByRef(&myDataSet);

    printf("\nAfter Function:\n");
    printf("y\t");
    for(int i = 0;i<10; i++){
        printf("%0.1f\t", myDataSet.yPoints[i]);
    }
    printf("\nx\t");
    for(int i = 0;i<10; i++){
        printf("%0.1f\t", myDataSet.xPoints[i]);
    }

    printf("\ny bar: %.3f\n", myDataSet.yBar);
    printf("x bar: %.3f\n", myDataSet.xBar);
    return 0;

}

void populateMeans(dataSet *dSPtr){
    float total = 0;
    for(int i = 0; i < 10; i++){
        total+=dSPtr->xPoints[i];
    }
    dSPtr->xBar = total/10;

    total = 0;
    for(int i = 0; i < 10; i++){
        total+=dSPtr->yPoints[i];
    }
    dSPtr->yBar = total/10;
}

void correctSystematicErrorByVal(dataSet dS){
    for(int i = 0;i<10; i++){
        dS.yPoints[i] -=2;
    }
    populateMeans(&dS);
    printf("Within Function:\n");
    printf("y\t");
    for(int i = 0;i<10; i++){
        printf("%0.1f\t", dS.yPoints[i]);
    }
    printf("\nx\t");
    for(int i = 0;i<10; i++){
        printf("%0.1f\t", dS.xPoints[i]);
    }
}

void correctSystematicErrorByRef(dataSet *dSPtr){
    for(int i = 0;i<10; i++){
        dSPtr->yPoints[i] -=2;
    }
    populateMeans(dSPtr);
    printf("Within Function:\n");
    printf("y\t");
    for(int i = 0;i<10; i++){
        printf("%0.1f\t", dSPtr->yPoints[i]);
    }
    printf("\nx\t");
    for(int i = 0;i<10; i++){
        printf("%0.1f\t", dSPtr->xPoints[i]);
    }
}
