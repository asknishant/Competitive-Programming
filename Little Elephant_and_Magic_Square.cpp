/*
Codeforeces 259B
Little Elephant and Magic Square.
status-accepted.
by-asknishant
*/

#include<bits/stdc++.h>
using namespace std;

int main(void){
    
    int a,b,c,d,e,f,g,h,i;
    cin>>a>>b>>c>>d>>e>>f>>g>>h>>i;
    
    int sum=(a+b+c+d+e+f+g+h+i)/2;
    
    a = sum-(b+c);
    e = sum-(d+f);
    i = sum-(g+h);
    
    cout<<a<<" "<<b<<" "<<c<<"\n";
    cout<<d<<" "<<e<<" "<<f<<"\n";
    cout<<g<<" "<<h<<" "<<i<<"\n";
    return 0;
}
