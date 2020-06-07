
/*
Find the closest pair from two sorted arrays

Given two sorted arrays and a number x, find the pair whose sum is closest to x and the pair has an element from each array.

We are given two arrays ar1[0…m-1] and ar2[0..n-1] and a number x, we need to find the pair ar1[i] + ar2[j] such that absolute value of (ar1[i] + ar2[j] – x) is minimum.
*/

//https://www.geeksforgeeks.org/given-two-sorted-arrays-number-x-find-pair-whose-sum-closest-x/

#include<bits/stdc++.h>

using namespace std;

int main(void){
    
    
    int ar1[] = {1, 4, 5, 7};
    int ar2[] = {10, 20, 30, 40};
    int x=38;  //cin>>x;
    int j=3;
    int i=0;
    int min=10000;
    int a=0,b=0;
    while(i < 4 && j>=0){
        if(abs((ar1[i]+ar2[j]) - x) < min){
            min = (abs(ar1[i] + ar2[j])-x);
            a=ar1[i];
            b=ar2[j];
        }
        
        if((ar1[i]+ar2[j]) > x){
            j--;
        }else if(ar1[i] + ar2[j] < x){
            i++;
        }
        
    }
    
    
    cout<<a<< " " <<b;
    return 0;
}