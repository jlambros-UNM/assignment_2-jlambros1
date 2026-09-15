//This is code written by James Lambros
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "statistics.h"
int main(){
    int arraySize[3];
    printf("We want 3 arrays. How big do you want them?  ");
    for(int i = 0; i < 3; i++){
        scanf("%d", &arraySize[i]);
        //printf("\n");
        //printf("%d", i); I was doing i++ twice :P
    }
    /*This is a debugging for loop to verify that the loop above works
    for(int i; i < 3; i++){
        printf("Size = %d \n", arraySize[i]);
    } */
    for(int i = 0; i < 3; i++){
        float arrayTemp[arraySize[i]];
        printf("Fill out array %d which is %d long. \n", i, arraySize[i]);
        for(int j = 0; j < arraySize[i]; j++){
            scanf("%f", &arrayTemp[j]);
        }
        //float *(arrayPtr)[arraySize[i]] = &arrayTemp;  Kept getting "variable-sized object may not be initialized except with an empty initializer"
        printf("Done! \n");
        //Sum section
        //I need to find out how to pass arrays to functions. Should be pretty simple.
        float tempSum = arraysum(arraySize[i], arrayTemp);
        printf("Sum of this array is %f \n", tempSum);
        //Average section
        float tempAverage = arrayaverage(arraySize[i], tempSum);
        printf("Average of this array is %f \n", tempAverage);
        //Standard deviation section
        float tempDeviation = arraystd(arraySize[i], tempAverage, arrayTemp);
        printf("STD of the array is %f \n", tempDeviation);
        //Min and Max section
        float tempMin = arraymin(arraySize[i], arrayTemp);
        float tempMax = arraymax(arraySize[i], arrayTemp);
        printf("Min of this array is %f \n", tempMin);
        printf("Max of this array is %f \n", tempMax);
        float tempDiff = arraydiff(tempMin, tempMax);
        printf("Difference between the min and max of this array is %f \n", tempDiff);
    }
}
/* Sources
 * https://stackoverflow.com/questions/5636070/zero-an-array-in-c-code
 * https://stackoverflow.com/questions/64853119/if-i-declare-a-variable-inside-a-for-loop-in-c-will-it-be-created-multiple-time
 * https://www.mathsisfun.com/data/standard-deviation-formulas.html
 * https://www.geeksforgeeks.org/c/scanf-in-c/
 * Notes
 * In the main loop that my code runs in, I noticed that I would continuously get errors, where the array filling and sum were holding their past values.
 * This was due to me not initalizing j, k, d and tempSum to 0, and that would lead to them holding their past value and messing with the loop.
 */
