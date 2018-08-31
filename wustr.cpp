#include<iostream>
#include<cstring>
#include<string>
using namespace std;


class wustr
{
private:
	char* buff;
public:
	wustr();
	wustr(const char* str);
	wustr(const wustr& str);
	
	~wustr();
	
	int size() const;
	bool empty() const;

	void clear();
	
	void append(const char* str);
	void insert(const char* str, int n);	
	void remove(const char* str);
	void replace(const char* old, const char* newstr);	
	const char* c_str() const;
	int to_int() const;
	float to_float() const;

	wustr operator + (const wustr& str) const;
	wustr operator = (const wustr& str);	
	char operator [](int index);
	bool operator == (const wustr& str);
	bool operator != (const wustr& str);
	bool operator > (const wustr& str);
	operator int();
	operator float();

	friend istream& operator>>(istream& in, wustr& str);
	friend ostream& operator<<(ostream& out,const wustr& str);
};

ostream& operator<<(ostream& out,const wustr& str)
{
	out<<str.buff;
	out<<'\n';
}

istream& operator>>(istream& in, wustr& str)
{
	char* input_buff = new char[1001];
	int size = 1000;
	int cnt = 0;
	char chr;

	input_buff = new char[size + 1];

	while(1)
	{
		chr = in.get();
	
		if(chr == '\n')break;

		input_buff[cnt++]=chr;	

		if(size == cnt)
		{
			size += 100;
			char* temp_buff = new char[size+1];	
			memcpy(temp_buff,input_buff, cnt);
			delete []input_buff;
			input_buff = temp_buff;
		}
	}

	input_buff[cnt]='\0';

	delete []str.buff;
	str.buff = input_buff;

	return in;
}

wustr::wustr()
{
	buff = new char[1];
	buff[0] = '\0';
}


wustr::wustr(const char* str)
{
	buff = new char[strlen(str)+1];
	strcpy(buff,str);
}


wustr::wustr(const wustr& str)
{
	buff = new char[strlen(str.buff)+1];	
}

wustr::~wustr()
{
	delete []buff;
}


int wustr::size() const
{
	return strlen(buff);
}

bool wustr::empty() const
{
	return (buff[0]== '\0');
}	


void wustr::clear()
{
	buff[0] = '\0';	
}


wustr wustr:: operator = (const wustr& str)
{
	delete []buff;
	buff = new char[strlen(str.buff)+1];
	strcpy(buff,str.buff);

	return *this;
}


wustr wustr::operator + (const wustr& str)  const
{
	wustr tmp;
	delete tmp.buff;
	tmp.buff = new char[strlen(this->buff)+strlen(str.buff)+2];
	strcpy(tmp.buff,buff);
	strcat(tmp.buff,str.buff);

	return tmp.buff;
}
