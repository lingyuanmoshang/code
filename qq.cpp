#include <cstring>
#include <iostream>
using namespace std;

class String
{
	char* str;
	int size;

public:
	String();
	String(const char* s);
	String(const String& s);
	~String();
	String& operator=(const char* s);
	String& operator=(const String& s);
	String operator+(String& s);
	String& operator+=(String& s);
	char& operator[](int n);
	bool operator==(String& s);
	bool operator<(String& s);
	friend istream& operator>>(istream& in, String& s);
	friend ostream& operator<<(ostream& out, String& s);
	int Length();
};

String::String() { str = new char[1]; str[0] = '\0'; size = 0; }
String::String(const char* s)
{
	size = strlen(s);
	str = new char[size + 1];
	strcpy(str, s);
}
String::String(const String& s)
{
	size = strlen(s.str);
	str = new char[size + 1];
	strcpy(str, s.str);
}
String::~String() { cout << "Îö¹¹ÁË"<<str << endl; delete[] str; size = 0; }
String& String::operator=(const char* s)
{
	size = strlen(s);
	delete[] str;
	str = new char[size+1];
	strcpy(str, s);
	return *this;
}

String& String::operator=(const String& s)
{
	if (&s == this)
		return *this;
	delete[]str;
	size = strlen(s.str);
	str = new char[size + 1];
	strcpy(str, s.str);
	return *this;
}

String String::operator+(String& s)
{
	char* temp = new char[size + s.size + 1];
	strcpy(temp, str);
	strcat(temp, s.str);
	return String(temp);
}
String& String::operator+=(String& s)
{
	size += s.size;
	char* temp = new char[size + 1];
	strcpy(temp, str);
	strcat(temp, s.str);
	delete[] str;
	str = temp;
	return *this;
}

char& String::operator[](int n) { return str[n]; }

bool String::operator==(String& s)
{
	return strcmp(str, s.str) == 0;
}
bool String::operator<(String& s)
{
	return strcmp(str, s.str) < 0;
}

int String::Length()
{
	return size;
}
ostream& operator<<(ostream& out, String& s)
{
	out << s.str;
	return out;
}

istream& operator>>(istream& in, String& s)
{
	s.str=new char[100000];
	in >> s.str;
	return in;
}

int main()
{
	String s1("Help!"), s2("Good!"), s3(s2), s4, s5;
	cout << "s1=" << s1 << endl;
	s1 += s1;
	cout << "s1=" << s1 << endl;
	s3 = "Hello!";
	cout << "s3=" << s3 << endl;
	s3 = s2;
	cout << "s3=" << s3 << endl;
	s3 += s2;
	cout << "s3=" << s3 << endl;
	s3+=s3;
	cout << "s3=" << s3 << endl;
	cin >> s4;
	cout << "s4=" << s4 << endl;
	s5 = s3 + s4;
	cout << "s5=" << s5 << endl;
	s5[0] = 'g';
	cout << "s5=" << s5 << endl;
	cout << "strlen(s5)=" << s5.Length() << endl;
	cout << boolalpha << (s3 == s1) << endl;
	cout << boolalpha << (s3 < s1) << endl;
	return 0;
}
