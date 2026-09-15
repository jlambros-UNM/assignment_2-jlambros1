//This is code written by James Lambros
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "statistics.h"
//I probably need to pass a pointer for the array, not sure I can access it this way.
//Turns out I can just pass arrayTemp directly
float arraysum(int size, float *array){
    float tempSum = 0;
    for(int i = 0; i < size; i++){  //Step through the array and sum the components
        tempSum = tempSum + array[i];
    }
    return tempSum;
}

float arrayaverage(int size, float sum){
    float tempAverage = sum / size;
    return tempAverage;
}
//Same for this, probably need a pointer for the array
float arraystd(int size ,float average, float *array){ //This loop needs the average, size of the array, and the array itself
    float tempDeviationHolder = 0;
    float tempDeviation = 0;
    //https://www.mathsisfun.com/data/standard-deviation-formulas.html
    for(int i = 0; i < size; i++){
        tempDeviationHolder = (array[i] - average);
        tempDeviationHolder = tempDeviationHolder * tempDeviationHolder;
        tempDeviationHolder = (tempDeviationHolder / size);
        tempDeviation = tempDeviation + tempDeviationHolder;
    }
    tempDeviation = sqrt(tempDeviation); //Squaring outside the loop since it was the easiest method.
    return tempDeviation;
}
//I need the array and the size of the array. Should be pretty simple for min and max, just assume that the first number is the min/max. Compare it to the next number, and replace the min/max if needed.
float arraymin(int size, float *array){
    float tempMin = array[0];
    //For this loop, I was considering to make i start at 1 to skip the first number, but I decided against this because what if there is an array of 1 element?
    for(int i = 0; i < size; i++){
        if(array[i] < tempMin){
            tempMin = array[i];
        }
    }
    return tempMin;
}
float arraymax(int size, float *array){
    float tempMax = array[0];
    for(int i = 0; i < size; i++){
        if(tempMax < array[i]){
            tempMax = array[i];
        }
    }
    return tempMax;
}
//This function provides the difference between the min and max. Needs to be the ABS, so order really doesn't matter.
float arraydiff(float min, float max){
    float tempDiff = max - min;
    return abs(tempDiff);
}


//This loop calculates the sum, square and do division before I take the square root outside the loop
