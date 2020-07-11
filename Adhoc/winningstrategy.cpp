 #include <bits/stdc++.h>
	using namespace std;
     
    int main(){
    	int n;
    	cin >> n;
    	int * input = new int[n];
    	for (int i = 0; i < n; ++i)
    	{
    		cin >> input[i];
    	}
     
    	int total_cost =0;
     
    	for (int i = 0; i < n; i++)
    	{
    		int diff = abs(input[i] - (i+1)) ;
    		if(diff <= 2){
    			total_cost += diff;
    		}
    		else{
    			cout << "NO" << endl;
    			return 0;
    		}
    	}
    	total_cost /= 2;
     
    	cout << "YES" << endl;
    	cout << total_cost << endl;
    	return 0;
    }
