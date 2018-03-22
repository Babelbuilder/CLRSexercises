#include<iostream>
#include<string>
#include<vector>
using namespace std;
string reverse(const string &sentence)
{
    vector<string> re;
    string res;
    string mid;
    if(sentence.size()==0)
        return sentence;
    else{
        int key=sentence.size();
        //cout<<key<<endl;
        for(int i=sentence.size()-1;i>=0;i--){
            //cout<<i<<endl;
            if(sentence[i]==' '&&i>0){
                mid.clear();
                for(int j=i+1;j<key;j++){
                    mid+=sentence[j]; 
                }
               re.push_back(mid);
               key=i;
               //cout<<key<<endl; 
            }
            else if(i==0){
                mid.clear();
                for(int j=i;j<key;j++){
                    mid+=sentence[j]; 
                }
               re.push_back(mid);
            }
        
        }
    }
    for(int n=0;n<re.size()-1;n++)
        res+=(re[n]+' ');   
    res+=re[re.size()-1];
    return res;  
}

int main()
{
    // string input="you should gou to the badroom";
    string input;
    getline(cin,input);
    //cout<<input.size()<<endl;
    cout<<reverse(input)<<endl;
    return 0;
}