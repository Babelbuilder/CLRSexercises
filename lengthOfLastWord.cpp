#include<iostream>
using namespace std;
#include<string>
int lengthOfLastWord(const char *s) {
    int n=0,num=0;
    if(s==0){
        return 0;
        num=0;
    }
    else if(s!=0&&*s=='\0'){
        return 0;
        num=0;
    }  
    else{
        while((*s)!='\0'){
            s++;
            num++;
         }
    }
    s--;
    while((*s)!=' '&&num>0){
        s--;
        n++;
        num--;
    }
    return n; 
 }

 int main(){
     const char *s="Hello world";
     cout<<lengthOfLastWord(s);
 }