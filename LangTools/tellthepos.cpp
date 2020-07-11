#include <bits/stdc++.h>
using namespace std;

struct student // create structure of students
{
  string name;
  int total_marks;
    int rank;
};
bool sortBy(student s1,student s2) //sort the the arr[] using total_marks 
{
    
    if(s1.total_marks == s2.total_marks){
         return s1.rank<s2.rank;

    }
  return (s1.total_marks > s2.total_marks) ;
}
int main()
{

 int n;
cin >> n;
student arr[n];
    int count =0;
for(int i=0;i<n;i++) // storing elements into structure arr[]
{
  string str;
  int m1,m2,m3;
  cin >> str;
  cin >> m1 >> m2 >> m3;
  arr[i].name = str;
  arr[i].total_marks = m1+m2+m3;
    arr[i].rank=++count;
        
}
sort(arr,arr+n,sortBy);
for(int i=0;i<n;i++)
{
  cout << i+1 << " " << arr[i].name << endl;
}


  return 0;
}
