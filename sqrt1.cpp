#include<iostream>
using namespace std;
int int_sqrt_helper(int, int, int);
int int_sqrt(int x); 
/*������*/ 
int main()
{
	int i;
	cout<<"We will output the number and its int-sqrt."<<endl ;
	for(i=i;i<100;i++)
   		cout<<i<<"\t\t\t\t"<<int_sqrt(i)<<endl;
   	system("pause");
}
/*��ʹ�� square > x ��������С�� number=2n+1*/ 
int int_sqrt_helper(int square, int n, int x)
{
	square=n*n;
	if(square>x)
		return (2*n+1);
	else
		int_sqrt_helper(square, n+1, x);
}
/* ��Ǹ�����������ƽ���� */ 
int int_sqrt(int x)
{
	return ((int_sqrt_helper(0,0,x)-1)/2)-1;
}
