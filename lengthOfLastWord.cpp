#include<iostream>
using namespace std;
#include<string>
int lengthOfLastWord(const char *s) {
    if(s==0)
        return 0;
    int num=0;
    while((*s)!=EOF){
        s++;
    }
    s--;
    while((*s)!=' '){
        num++;
    }
    return num;
 }

 int main(){
     char inputStr[]="Hello world";
     cout<<lengthOfLastWord(inputStr);
 }