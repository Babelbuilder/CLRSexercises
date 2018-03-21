#include<iostream>
#include<vector>
using namespace std;
vector<double> & Merge(vector<double> &left,vector<double> &right){
    int left_num=left.size();
    int right_num=right.size();
    int total=left_num+right_num;
    int l=0,r=0;
    vector<double> result;
    for (int i=0;i<total;i++){
        if(l<left_num&&r<right_num){
            if(left[l]<=right[r]){
                result.push_back(left[l]);
                l++;
            }
            else {
                result.push_back(right[r]);
                r++;
            }
        }
        else if(l<left_num){
            for(;l<left_num;l++)
            result.push_back(left[l]);
            break;
        }    
        else if(r<right_num){
            for(;r<right_num;r++)
            result.push_back(right[r]);
            break;
        }
        else break;
    }
    return result;
}

vector<double> & MergeSort(vector<double> & input){
    int num=input.size();
    vector<double> left,right,left_order,right_order;
    if(num>1){
        for (int i=0;i<num/2;i++)
        left.push_back=input[i];
        for (int i=num/2-1;i<num;i++)
        right.push_back=input[i];
        left_order=MergeSort(left);
        right_order=MergeSort(right);
        return Merge(left_order,right_order);
    }
        
    else {
        return input;
    }
}

int main(){
    vector<double> disorder,order;
    double element=0;
    cout<<"Input the number:"<<endl;
    while(cin>>element){
        disorder.push_back(element);
    }
    int num=disorder.size();
    cout<<"disorder:";
    for (auto i : disorder)
        cout<<i<<" ";
    cout<<endl;
    order=MergeSort(disorder);
    cout<<"order:";
    for (auto i : order)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}