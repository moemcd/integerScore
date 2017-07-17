//
//  main.c
//  hw05
//
//  Created by Morgan  McDowell on 3/10/17.
//  Copyright © 2017 Morgan  McDowell. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//function declarations
long long int getNum ();
long long int checkNum(long long int);
long long int checkPrime(long long int);
long long int getLength(long long int);
long long int largestNum(long long int);
long long int smallestNum(long long int);
long long int getScore(long long int, long long int, long long int, long long int, long long int);
void printResults(long long int, long long int);

int main(void)
{
    //local variables
    long long int num;
    long long int check;
    long long int prime;
    long long int length;
    long long int big;
    long long int small;
    long long int score;
    
    //statements to check input
    num = getNum();
    check = checkNum(num);
    
    //check if num is negative
    while (check == 0)
    {
        printf("\nError! Positive values only!!\n\n");
        num = getNum();
        check = checkNum(num);
    }
    
    //statements to calculate score
    prime = checkPrime(num);
    length = getLength(num);
    big = largestNum(num);
    small = smallestNum(num);
    score = getScore(num, length, prime, small, big);
    
    //print results
    printResults(num, score);
    
    return 0;
}

long long int getNum()
{
    long long int num;
    printf("Enter your number: ");
    scanf("%lld", &num);
    return num;
}

long long int checkNum(long long int num)
{
    if (num <= 0)
        return 0;
    else
        return 1;
}

long long int getLength(long long int num)
{
    long long int length = 0;
    
    while (num > 0)
    {
        length ++;
        num =  num/10;
    }
    
    return length;
}

long long int checkPrime(long long int num)
{
    int i;
        for (i = 2; i < num; i++)
        {
            if (num % i == 0 && i != num)
                return 0;
        }
        return 1;
}

long long int largestNum(long long int num)
{
    long long int big  = -1;
    long long int singleDig;
    
    while (num > 0)
    {
        singleDig = num % 10;
        
        num = num / 10;
        
        if (big < singleDig)
            big = singleDig;
    }
    
    return big;
}

long long int smallestNum(long long int num)
{
    long long int small  = 10;
    long long int singleDig;
    
    while (num > 0)
    {
        singleDig = num % 10;
        
        num = num / 10;
        
        if (small > singleDig)
            small = singleDig;
    }
    
    return small;
}

long long int getScore(long long int num, long long int length, long long int prime, long long int small, long long int big)
{
    long long int singleDig;
    long long int score = 0;
    long long int i;
    
    while (num > 0)
    {
        for (i = length; i > 0; --i)
        {
            singleDig = num % 10;
            score += pow(singleDig, i);
            num /= 10;
        }
    }
    
    if (prime == 1)
        score = score + big;
    else if (prime ==0)
        score = score - small;
    
    return score;
}

void printResults(long long int num, long long int score)
{
    printf("\nThe final result of the input %lld is: %lld\n", num, score);
}

