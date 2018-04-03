/*
字符串匹配 Kunth-Morris-Pratt algorithm
Chen rigao 2018.4.3 
http://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html
参考阮一峰博客
*/
#include<iostream>
#include<string>
using namespace std;

void KmpMatcher(const string &T, const string &P);//声明匹配函数
void ComputerPrefixFunction(const string &P,int *next);//声明计算最大前缀函数,计算next数组

void KmpMatcher(const string &T, const string &P) //定义匹配函数
{
	int n = T.length();   //文本T长度
	int m = P.length();   //模式P长度
	int *next= new int[m];  //定义一个m长的int数组，next指向它。
	ComputerPrefixFunction(P,next);  //计算模式P的next数组
	int MatchNumber = 0;     //初始化匹配的长度为0
	for (int i = 0; i < n; i++) {           //从T的最开始遍历
		while (MatchNumber > 0 && P[MatchNumber] != T[i])  //当匹配的长度>0，且这个字符匹配不上时
			MatchNumber = next[MatchNumber - 1];   //按照前面计算的next数组，一次向右滑动的长度，用while时可能需要多次滑动，不能用if语句。
		if (P[MatchNumber] == T[i])  //如果这个字符匹配上时
			MatchNumber =MatchNumber+1;  // 匹配字符长度+1
		if (MatchNumber == m) {  //如果匹配的字符串长度等于模式P的长度
			cout << "Pattern occurs with shift: " << i - m+2 << endl;  //则输出匹配的位置，i-m+2，是因为数组从0开始计数，我们想要输出第几个开始匹配
		    MatchNumber = next[MatchNumber-1]; //继续匹配下去，直到为本T结束
		}
	}
}

void ComputerPrefixFunction(const string &P,int *next)  //计算模式P的最大前缀
{
	int m = P.length();
	next[0] = 0;//匹配上一个字符时，按照最大前缀定义，为空，则next[0]=0
	int k = 0; //匹配到的字符数量，初始化为0
	for (int q = 1; q < m; q++) {  //从P的第二个开始遍历到结束
		while (k > 0 && P[k] != P[q]) //跟上面函数 KmpMatcher 同理
			k = next[k-1];
		if (P[k] == P[q])
			k += 1;
		next[q] = k; //计算出匹配字符串长度的每个可能值，下一个不匹配后能匹配到的字符数
	}
	cout << "next[" << m << "] "; //测试用，输出了next数组，检验对错
	for (int i=0;i<m;i++)
		cout << next[i]<< " ";
	cout << endl;
}
//测试程序
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