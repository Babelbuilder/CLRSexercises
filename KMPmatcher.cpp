/*
�ַ���ƥ�� Kunth-Morris-Pratt algorithm
Chen rigao 2018.4.3 
http://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html
�ο���һ�岩��
*/
#include<iostream>
#include<string>
using namespace std;

void KmpMatcher(const string &T, const string &P);//����ƥ�亯��
void ComputerPrefixFunction(const string &P,int *next);//�����������ǰ׺����,����next����

void KmpMatcher(const string &T, const string &P) //����ƥ�亯��
{
	int n = T.length();   //�ı�T����
	int m = P.length();   //ģʽP����
	int *next= new int[m];  //����һ��m����int���飬nextָ������
	ComputerPrefixFunction(P,next);  //����ģʽP��next����
	int MatchNumber = 0;     //��ʼ��ƥ��ĳ���Ϊ0
	for (int i = 0; i < n; i++) {           //��T���ʼ����
		while (MatchNumber > 0 && P[MatchNumber] != T[i])  //��ƥ��ĳ���>0��������ַ�ƥ�䲻��ʱ
			MatchNumber = next[MatchNumber - 1];   //����ǰ������next���飬һ�����һ����ĳ��ȣ���whileʱ������Ҫ��λ�����������if��䡣
		if (P[MatchNumber] == T[i])  //�������ַ�ƥ����ʱ
			MatchNumber =MatchNumber+1;  // ƥ���ַ�����+1
		if (MatchNumber == m) {  //���ƥ����ַ������ȵ���ģʽP�ĳ���
			cout << "Pattern occurs with shift: " << i - m+2 << endl;  //�����ƥ���λ�ã�i-m+2������Ϊ�����0��ʼ������������Ҫ����ڼ�����ʼƥ��
		    MatchNumber = next[MatchNumber-1]; //����ƥ����ȥ��ֱ��Ϊ��T����
		}
	}
}

void ComputerPrefixFunction(const string &P,int *next)  //����ģʽP�����ǰ׺
{
	int m = P.length();
	next[0] = 0;//ƥ����һ���ַ�ʱ���������ǰ׺���壬Ϊ�գ���next[0]=0
	int k = 0; //ƥ�䵽���ַ���������ʼ��Ϊ0
	for (int q = 1; q < m; q++) {  //��P�ĵڶ�����ʼ����������
		while (k > 0 && P[k] != P[q]) //�����溯�� KmpMatcher ͬ��
			k = next[k-1];
		if (P[k] == P[q])
			k += 1;
		next[q] = k; //�����ƥ���ַ������ȵ�ÿ������ֵ����һ����ƥ�����ƥ�䵽���ַ���
	}
	cout << "next[" << m << "] "; //�����ã������next���飬����Դ�
	for (int i=0;i<m;i++)
		cout << next[i]<< " ";
	cout << endl;
}
//���Գ���
int main() 
{
	string T("bbc abcdab abcdabcdabde");
	cout <<"T "<<T << endl;
	string P = "abcd";
	cout << "P "<<P << endl;
	KmpMatcher(T, P);
	while (1);
	return 0;
}