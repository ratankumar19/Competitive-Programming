 #include<bits/stdc++.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

int main()
{
     string st;
    vector<string> v;
   

    
    while(getline(cin,st,' '))
    {
         v.push_back(st);
    }
   
  
  
    map<string,int> m;
    
    for(int i=0;i<v.size();i++)
    {
        m[v[i]]+=1;
    }

    bool flag=false;
    for(auto it=m.begin();it!=m.end();it++)
    {
     
        
        if(it->second>1)
        {
        	flag=true;
            cout<<it->first<<" "<<it->second<<"\n";
        }
       
    }    
    
    if(!flag){
    	cout<<-1<<endl;
    }
	return 0;
}
