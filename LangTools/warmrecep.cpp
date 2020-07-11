#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int *starting = new int[n];
    int *ending = new int[n];
    for(int i=0;i<n;i++)
        cin>>starting[i];
    for(int i=0;i<n;i++)
        cin>>ending[i];
    int countMax = 0;
    for(int i=0;i<n;i++){
        int countM = 0;
        int start = starting[i];
        for(int j=0;j<n;j++){
            if(start<=ending[j]&&start>=starting[j]&&i!=j)
                countM++;
        }
        if(countM>countMax)
            countMax = countM;
    }
    cout<<countMax+1;
}
