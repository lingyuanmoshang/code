#include<iostream>
#include<cstring>
using namespace std;
class String
{
private:
	char* p;
	int size_;
public:
	String() {
		p = new char[1];
		*p = '\0';
		size_ = 0;
	}
	String(const String& s) {
		size_ = s.size_;
		p = new char[size_ + 1];
		strcpy(p, s.p);
	}
	String(const char* const cstr)
	{
		if (cstr == NULL) {
			size_ = 0;
			p = new char[1];
			memset(p, 0, size_ + 1);
			if (p == NULL) return;
		}
		else {
			size_ = strlen(cstr);
			p = new char[size_ + 1];
			memset(p, 0, size_ + 1);
			if (p == NULL) return;
			strncpy(p, cstr, size_);
		}
	}
	String operator+(const String& rhs) {
		String newString;
		if (size_ > 0 || rhs.size_ > 0) {
			char* temp = new char[size_ + rhs.size_ + 1];
			strcpy(temp, p);
			strcat(temp, rhs.p);
			delete newString.p;
			newString.p = temp;
			newString.size_ = size_ + rhs.size_;
		}
		return newString;
	}
	String& operator +=(const String& s) {
		size_ = s.size_ + size_;
		char* str = new char[size_ + 1];
		strcpy(str, p);
		strcat(str, s.p);
		delete[]p;
		p = new char[size_ + 1];
		strcpy(p, str);
		delete[]str;
		return *this;
	}
	String& operator=(const String& s) {
		if (this == &s)
			return *this;
		if (p != NULL) {
			delete[]p;
			p = NULL;
		}
		size_ = s.size_;
		p = new char[size_ + 1];
		strcpy(p, s.p);
		return *this;
	}
	String& operator =(const char* s) {
		if (p != NULL) {
			delete[] p;
		}
		size_ = strlen(s);
		p = new char[size_ + 1];
		strcpy(p, s);
		return *this;
	}
	~String() {
		if (p != NULL) {
			delete[] p;
			p = NULL;
			size_ = 0;
		}
	}
	const char* getdata() const {
		return p;
	}
	char& operator [](int i) {
		return p[i];
	}
	const char& operator [](int i) const {
		return p[i];
	}
	friend ostream& operator <<(ostream& out, String& s) {
		out << s.getdata();
		return out;
	}
	friend istream& operator>>(istream& is, String& str) {
		cin >> str.p;
		str.size_ = strlen(str.p);
		return is;
	}
	friend bool operator >(const String& left, const String& right) {
		int i = 0;
		while (left[i] == right[i] && left[i] != '\0' && right[i] != '\0') {
			i++;
		}
		return left[i] - right[i] > 0 ? true : false;
	}
	friend bool operator <(const String& left, const String& right) {
		int i = 0;
		while (left[i] == right[i] && left[i] != '\0' && right[i] != '\0') {
			i++;
		}
		return left[i] - right[i] < 0 ? true : false;
	}
	friend bool operator ==(const String& left, const String& right) {
		int i = 0;
		while (left[i] == right[i] && left[i] != '\0' && right[i] != '\0') {
			i++;
		}
		return left[i] == right[i] ? true : false;
	}
	int Length() { return size_; }
};
int main()
{
	String s1("Help!"), s2("Good!"), s3(s2), s4, s5;
	cout << "s1=" << s1 << endl;
	s3 = "Hello!";
	cout << "s3=" << s3 << endl;
	s3 = s2;
	cout << "s3=" << s3 << endl;
	s3 += s2;
	cout << "s3=" << s3 << endl;
	cin >> s4;
	s5 = s3 + s4;
	cout << "s5=" << s5 << endl;
	s5[0] = 'g';
	cout << "s5=" << s5 << endl;
	s1 += s1;
	cout << "s1=" << s1 << endl;
	cout << "strlen(s5)" << s5.Length() << endl;
	cout << boolalpha << (s3 == s1) << endl;
	cout << boolalpha << (s3 < s1) << endl;
	return 0;
}
