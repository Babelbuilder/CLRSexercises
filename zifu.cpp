#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    std::cout<<"input_string="<<endl;
    string instr;
    int current=0;
    int largest=0;
    int str_num=0;
    int n=0;
    string output;
    cin>>instr;
    str_num=instr.size();
    for (int i=0;i<str_num;i++){
        if(instr[i]>='0'&&instr[i]<='9'){
        current++;
        }
        else if((instr[i]<='0'||instr[i]>='9')&&current>=largest){
                largest=current;
                current=0; 
                n=i; 
        }
         for(int j=n-largest;j<=n-1;j++){
             //cout<<j<<endl; 
            output[j-(n-largest)]=instr[j];
            }
    }
    std::cout<<output<<","<<largest<<endl;
    return 0;
}