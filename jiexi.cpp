#include<iostream>
#include<vector>
using namespace std;
typedef struct {
    unsigned int uiElementLength;
    unsigned int uiElementValue;
}ELEMENT_STRU;

void Decode(unsigned int uiIutputLen, unsigned char aInputByte[],
               unsigned int uiElementNum, ELEMENT_STRU astElement[])
{

    if(!aInputByte || !astElement)
        return;
    if(uiElementNum==0||uiIutputLen==0)
        return;

    vector<int> vec;

    unsigned int i = 0;
    unsigned int temp = 0;
    int temp1 = 0x80;
    unsigned int j = 0,k = 0;
    int sum = 0;

    int bittemp = 0;

    for(i = 0;i<uiIutputLen;i++) {
        temp = aInputByte[i];
        for(j = 0;j<8;j++) {

            bittemp = (temp&temp1);

            bittemp = (bittemp>>7);

            vec.push_back(bittemp);
            temp = (temp<<1);
        }   
    }

    int size = vec.size();
    for(i=0;i<uiElementNum;i++) {
        temp = 0;
        for(j=0;j<astElement[i].uiElementLength;j++) {
            if(astElement[i].uiElementLength<1 && \
                astElement[i].uiElementLength>31)
                return;
            if(k>size) { 
                break;
            }
            temp = (temp<<1)+vec[k];
            k++;

        }
        if(k>size&&temp!=0) {
            astElement[i].uiElementValue = temp;
            break;
        } else if(k>size&&temp==0){
            break;
        }
        astElement[i].uiElementValue = temp;
    }

    return;
}

int main(){
    unsigned int uiIntputLe=0;
    unsigned char aInputByt[3];
    unsigned int uiElementNu;
    ELEMENT_STRU astElemen[2];
    cin>>uiIntputLe;
    cin>>aInputByt[0];
    cin>>aInputByt[1];
    cin>>aInputByt[2];
    cin>>uiElementNu;
    cin>>astElemen[0].uiElementLength;
    cin>>astElemen[1].uiElementLength;
    Decode(uiIntputLe,aInputByt,uiElementNu, astElemen);
    cout<<astElemen[0].uiElementValue<<astElemen[1].uiElementValue<<endl;
    return 0;
}