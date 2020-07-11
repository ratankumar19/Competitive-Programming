#include <iostream>
#include <string>
using namespace std;
void help(string strNum,string op)
{
   int l=strNum.length();
    if(strNum.length()==0)
    {
        cout<<op<<"\n";
        return;
    }
    
    if(strNum[0]=='2')
    {
       help(strNum.substr(1),op+'a');
         help(strNum.substr(1),op+'b');
         help(strNum.substr(1),op+'c');
        
    /*
         help(strNum.substr(0,l-1),op+char(97));
         help(strNum.substr(0,l-1),op+char(98));
         help(strNum.substr(0,l-1),op+char(99));*/
    }
    
    if(strNum[0]=='3')
    {
       help(strNum.substr(1),op+'d');
         help(strNum.substr(1),op+'e');
         help(strNum.substr(1),op+'f');
    }
    
    if(strNum[0]=='4')
    {
       help(strNum.substr(1),op+'g');
         help(strNum.substr(1),op+'h');
         help(strNum.substr(1),op+'i');
    }
    
    
    if(strNum[0]=='5')
    {
       help(strNum.substr(1),op+'j');
         help(strNum.substr(1),op+'k');
         help(strNum.substr(1),op+'l');
    }
    
    if(strNum[0]=='6')
    {
       help(strNum.substr(1),op+'m');
         help(strNum.substr(1),op+'n');
         help(strNum.substr(1),op+'o');
    }
    
    if(strNum[0]=='7')
    {
       help(strNum.substr(1),op+'p');
         help(strNum.substr(1),op+'q');
         help(strNum.substr(1),op+'r');
        help(strNum.substr(1),op+'s');
    }
    
    if(strNum[0]=='8')
    {
       help(strNum.substr(1),op+'t');
         help(strNum.substr(1),op+'u');
         help(strNum.substr(1),op+'v');
    }
    
    if(strNum[0]=='9')
    {
       help(strNum.substr(1),op+'w');
         help(strNum.substr(1),op+'x');
         help(strNum.substr(1),op+'y');
        help(strNum.substr(1),op+'z');
    }
}



void printKeypad(int num)
{
    string op="";
    
    string strNum = to_string(num);
help(strNum,op);
      
}
