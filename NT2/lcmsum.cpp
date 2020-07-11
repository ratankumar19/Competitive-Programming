#include<bits/stdc++.h>
using namespace std;
#define n1 1000002 
#define ll long long int 
  
ll phi[n1 + 2], ans[n1 + 2]; 

void ETF() 
{ 
    for (int i = 1; i <= n1; i++) { 
        phi[i] = i; 
    } 
  
    for (int i = 2; i <= n1; i++) { 
        if (phi[i] == i) { 
            phi[i] = i - 1; 
            for (int j = 2 * i; j <= n1; j += i) { 
                phi[j] = (phi[j] * (i - 1)) / i; 
            } 
        } 
    } 
} 
void func(long long m)
{
     ETF(); 
  
    for (int i = 1; i <= n1; i++) { 
  
      
        for (int j = i; j <= n1; j += i) { 
            ans[j] += (i * phi[i]); 
        } 
    } 
  
    ll answer = ans[m]; 
    answer = (answer + 1) * m; 
    answer = answer / 2; 
    cout<<answer; 
}
