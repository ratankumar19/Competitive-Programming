#include<map>
char* uniqueChar(char *str){
    map<char,int> m;
    string out ="";
    string temp(str);
     for(int i=0; i<temp.length(); i++){
         if(m[str[i]]==0)
         {
             out+=str[i];
         }
    m[str[i]]++;
  }
int n=out.length();
    char *ar = new char[n+1];
    
   for(int i=0;i<n;i++)
   {
       ar[i]=out[i];
   }
   return ar;
}
  


