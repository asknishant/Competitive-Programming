//gkcs YT.

#include <bits/stdc++.h>
using namespace std;
#define mod 5

//modulus operator is only defined for integers not doubles.
//Defining method to calculate modular exponentiation really fast.(O(logN))
long modpow(int a,int b,int m){
    int res=1;
    if(b==0)    return 1;
    else if(b==1)    return a;
    else{
        if(b%2==0){
            res=modpow(a,b/2,m);
            return (res*res)%m;
        }else if(b%2!=0){
            res=modpow(a,b/2,m);
            return (res*a*res)%m;
        }
    }
}



//Calculating normal exponentiation.
int pow(int a,int b,int m){
    int res=1;
    if(b==0)    return 1;
    else if(b==1)   return a;
    else{
        if(b%2==0){
            res=pow(a,b/2,m);    //This calculates the first half of every recursion.eg:- a*a*a*a*...*a*a*a*a
            return res*res;  //mutiplying the two halves                                   //    N/2     N/2
        }else if(b%2!=0){
            res=pow(a,b/2,m);
            return res*a*res;   //      a*a*a*a*...a...*a*a*a*a
        }
    }
}

//More concise way is this

long long powerit(long long a, long b, long c)
{
    long result=1;
    while(b!=0)
    {
        if(b&01==1)//if b is odd
        {
            result*=a;
            if(result>=c)
                result%=c;
        }
        a=a*a;
        if(a>=c)
            a%=c;
        b>>=1;//b=b/2
    }
    return result;
}

int main(void){
    int a,b;
    cin>>a>>b;
    cout<<pow(a,b,mod);
    cout<<endl<<modpow(a,b,mod);

    return 0;
}
