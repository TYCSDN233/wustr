#include<iostream>
#include<cstring>
#include"wustr"
using namespace std;


int main()
{
	wustr str;
	wustr str2 = ("sfffff");
	
	cout<< str2.size()<<endl;
	cout<<str.empty()<<endl;

	wustr str3;

	str3 = str+str2;


	cin>>str3;
	cout<<str3;

	
	return 0;
}
