#include<bits/stdc++.h>
using namespace std;
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n)
{
	unordered_map< int, int >m;
	for(int i=0;i<n;++i)
		m[arr[i]]=true;
	int max_length=1,start=arr[0],max_element = arr[0];
  	for(int k=1;k<n;++k)
    {
      if(arr[k] > max_element)
        max_element=arr[k];
    }
  	int a[max_element+1];
  	for(int i=0;i<(max_element+1);i++) a[i]=INT_MAX;
  	for(int i=0;i<n;i++)
     { a[arr[i]] = min(i,a[arr[i]]);}
	
  	for(int i=0;i<n;++i)
	{	int local_max=1,temp,temp_start;
		if(m[arr[i]] == true)
		{	m[arr[i]]=false;temp_start=arr[i];
			int j=1;
			while(m.find(arr[i]+j) != m.end())
			{	
				int temp=arr[i]+j;
				m[temp]=false;
				local_max++;
				j++;
			}
			int k=1;
			while(m.find(arr[i]-k) != m.end())
			{	
				temp=arr[i]-k;
				m[temp]=false;
				local_max++;
				temp_start=temp;
				k++;
			}

		}
		if(max_length < local_max){
			max_length = local_max;
			start=temp_start;
		}
		else if(max_length == local_max ){ start=arr[min(a[temp_start],a[start])];}
        }
		
	vector< int > final_seq;
	for(int i = 1; i <=max_length; i++ )
	{
		final_seq.push_back(start++);
	}
	return final_seq;	}
