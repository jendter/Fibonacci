//
//  main.c
//  Fibonacci
//
//  Created by Josh Endter on 6/10/15.
//  Copyright (c) 2015 Josh Endter. All rights reserved.
//

#include <stdio.h>

//Declare functions
int fibonacci(int previousNumber, int previousPreviousNumber);
int recursiveValueFibonacci(int remainingSteps, int previousNumber, int previousPreviousNumber);
int recursiveReferenceFibonacci(int remainingSteps, int *previousnumber, int *previousPreviousNumber);

int main(int argc, const char * argv[]) {
    
    int finalAmountOfNumbers = 20;
    int previousPreviousNumber = 1;
    int previousNumber = 0;
    int latestNumber = 0;
    
    for (int counter = 0; counter < finalAmountOfNumbers; counter++) {
        
        
        printf("%d ", latestNumber);
        
        latestNumber = fibonacci(previousNumber, previousPreviousNumber);
        
        previousPreviousNumber = previousNumber;
        previousNumber = latestNumber;
        
    }
    
    // Version 2 (Recursive)
    printf("\n\n");
    
    finalAmountOfNumbers = 10;
    previousPreviousNumber = 1;
    previousNumber = 0;
    latestNumber = 0;
    
    int recursiveFibonacciNumber = recursiveValueFibonacci(finalAmountOfNumbers, previousNumber, previousPreviousNumber);
    
    printf("%d", recursiveFibonacciNumber);
    
    //Version 3 (Recursive Pass By Reference)
    printf("\n\n");
    
    finalAmountOfNumbers = 13;
    previousPreviousNumber = 1;
    previousNumber = 0;
    latestNumber = 0;
    
    int recursiveReferenceFibonacciNumber = recursiveReferenceFibonacci(finalAmountOfNumbers, &previousNumber, &previousPreviousNumber);
    
    printf("%d", recursiveReferenceFibonacciNumber);
    
    return 0;
}


int fibonacci(int previousNumber, int previousPreviousNumber) {
    return previousNumber + previousPreviousNumber;
}

int recursiveValueFibonacci(int remainingSteps, int previousNumber, int previousPreviousNumber) {
    
    int latestNumber = fibonacci(previousNumber, previousPreviousNumber);
    previousPreviousNumber = previousNumber;
    previousNumber = latestNumber;
    
    --remainingSteps;
    
    if (remainingSteps == 0) {
        return previousPreviousNumber;
    } else {
        return recursiveValueFibonacci(remainingSteps, previousNumber, previousPreviousNumber);
    }
    
    
}

int recursiveReferenceFibonacci(int remainingSteps, int *previousNumber, int *previousPreviousNumber) {
    int latestNumber = fibonacci(*previousNumber, *previousPreviousNumber);
    *previousPreviousNumber = *previousNumber;
    *previousNumber = latestNumber;
    
    --remainingSteps;
    
    if (remainingSteps == 0) {
        return *previousPreviousNumber;
    } else {
        return recursiveReferenceFibonacci(remainingSteps, previousNumber, previousPreviousNumber);
    }

}