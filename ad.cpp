#include<iostream>
#include<cstring>
using namespace std;

class String
{
private:
	char *data;
	int size;
public:
	String();
	String(char *s);
	String(const String &s);
	~String(){delete[]data;}
	char& operator[](int index){return data[index];}
	String operator+(String &s);
	String &operator+=(String &s);
	String& operator=(const String &s);
	String& operator=(const char *s);
	bool operator==(String&s);
	bool operator<(String &s);
	int Length(){return size;}
    friend ostream& operator <<(ostream &out,String &s);
    friend istream &operator>>(istream &in, String &str);
};
String::String()
{
	size=0;
	data=new char[1];
	data[0]=0;
}
String::String(char *s)
{
	size=strlen(s);
	data=new char[size+1];
	strcpy(data,s);
}
String::String(const String &s)
{
	size=s.size;
	data=new char[size+1];
	strcpy(data,s.data);
}
String String::operator+(String &s)
{
	char *temp=new char[size+s.size+1];
	strcpy(temp,data);
	strcat(temp,s.data);
	return String(temp);
}
String &String::operator+=(String &s)
{
	char *temp=new char[size+s.size+1];
    strcpy(temp,data);
    strcat(temp,s.data);
    delete[]data;
	data=new char[size+s.size+1];
	strcpy(data,temp);
	delete[]temp;
    size=s.size+size;
	return *this;
}
String& String::operator=(const String &s)
{
	delete[]data;
	size=s.size;
	data=new char[size+1];
	strcpy(data,s.data);
	return *this;
}
String& String::operator=(const char *s)
{
    if(data!=NULL)
        delete[]data;
    size=strlen(s);
    data=new char[size+1];
    strcpy(data,s);
    return *this;
}
bool String::operator==(String &s)
{
	return(strcmp(data,s.data)==0);
}

bool String::operator<(String &s)
{
	return(strcmp(data,s.data)<0);
}
ostream& operator<<(ostream &out,String &s)
{
	for(int i=0;s[i];i++)
		out<<s[i];
	return out;
}
istream& operator>>(istream &in,String &s)
{
	in>>s.data;
	s.size=strlen(s.data);
	return in;
}
int main()
{
	String s1("Help!"),s2("Good!"),s3(s2),s4,s5;
    cout<<"s1="<<s1<<endl;
    s3="Hello!";
    cout<<"s3="<<s3<<endl;
    s3=s2;
    cout<<"s3="<<s3<<endl;
    s3+=s2;
    cout<<"s3="<<s3<<endl;
    s3+=s3;
    cout<<"s3="<<s3<<endl;
    cin>>s4;
    s4+=s4;
    cout<<"s4="<<s4<<endl;
    s5=s3+s4;
    cout<<"s5="<<s5<<endl;
    s5[0]='g';
    cout<<"s5="<<s5<<endl;
    cout<<"strlen(s5)"<<s5.Length()<<endl;
    cout<<boolalpha<<(s3==s1)<<endl;
    cout<<boolalpha<<(s3<s1)<<endl;
	return 0;
}

