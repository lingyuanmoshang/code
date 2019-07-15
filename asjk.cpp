#include <iostream>
#include<cstring>
using namespace std;
class String {
private:
	char* s;
public:
	String() { s = new char[1]; s[0] = '\0'; }
	String(const char* str) {
		s = new char[strlen(str) + 1];
		strcpy(s, str);

	}
	int Length() { return strlen(s); }
	friend istream& operator>>(istream& in, String& p) { in >> p.s; return in; }
	friend ostream& operator<<(ostream& out, String& p) {
		out << p.s;
		return out;
	}
	~String() { if (s != NULL) delete[] s; }
	String(const String& str) { s = new char[strlen(str.s) + 1]; strcpy(s, str.s); }
	String operator+(const String& str) {
		char* p;
		p = new char[strlen(s) + strlen(str.s) + 1];
		strcpy(p, s);
		strcat(p, str.s);
		return String(p);
	}
	void Show() {
		cout << s << endl;
	}

	String& operator+=(const String& str) {
		char* p;
		p = new char[strlen(s) + strlen(str.s) + 1];
		strcpy(p, s);
		strcat(p, str.s);

		s = new char[strlen(p) + 1];
		strcpy(s, p);
		return *this;
	}
	char& operator[](int i) {
		if (i < strlen(s) && i >= 0)
			return s[i];
	}
	bool operator==(const String& str) {
		if (strlen(s) == strlen(str.s))
		{
			int i;
			for (i = 0; i < strlen(s); i++)
			{
				if (s[i] != str.s[i])
				{
					break;
				}
			}
			if (i == strlen(s))
				return 1;

		}
		else return 0;
	}
	bool operator==(String &p)
	{
		return(strcmp(s, p.s) == 0);
	}
	String& operator=(const char* p) {
		delete[]s;
		s = new char[strlen(p) + 1];
		strcpy(s, p);
		return *this;
	}
	String& operator=(const String& p) {
		if (&p != this)
		{
			delete[]s;
			s = new char[strlen(p.s) + 1];
			strcpy(s, p.s);
		}
		return *this;
	}
	bool operator<(String p)
	{
		if (strcmp(s, p.s) < 0)
			return true;
		else
			return false;
	}

};

int main()
{
	String s1("Help!"), s2("Good!"), s3(s2), s4, s5;
	s4 = s1 + s2;
	s4.Show();
	s1 += s2;
	s1.Show();
	cout << s1[0];
	if (s1 == s4)
		s1.Show();
	cout << "s1=" << s1 << endl;
	s3 = "Hello!";
	cout << "s3=" << s3 << endl;
	s3 = s2;
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
	s5 = "sdasdad";
	return 0;
}

