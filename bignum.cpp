#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
using namespace::std;
class BigInteger
{
	friend BigInteger big_abs(const BigInteger& a);
	friend ostream& operator << (ostream& out, const BigInteger& a);
	friend istream& operator >> (istream& out, BigInteger& a);
	friend bool operator > (const BigInteger& a, const BigInteger& b);
	friend bool operator < (const BigInteger& a, const BigInteger& b);
	friend bool operator >= (const BigInteger& a, const BigInteger& b);
	friend bool operator <= (const BigInteger& a, const BigInteger& b);
	friend bool operator == (const BigInteger& a, const BigInteger& b);
	friend BigInteger operator + (const BigInteger& a, const BigInteger& b);
	friend BigInteger operator - (const BigInteger& a, const BigInteger& b);
	friend BigInteger operator * (const BigInteger& a, const BigInteger& b);
	friend BigInteger operator / (const BigInteger& a, const BigInteger& b);
	friend BigInteger operator % (const BigInteger& a, const BigInteger& b);
	friend BigInteger operator ^ (const BigInteger& a, const BigInteger& b);
private:
	string integer;
	bool positive;
	static string big_add(const string& a, const string& b);
	static string big_sub(const string& a, const string& b);
	static string big_mul(const string& a, const string& b);
	static string big_div(const string& a, const string& b, string& remainder_ret);
	static int big_cmp(const string& a, const string& b);
public:
	BigInteger(string _integer = "0", bool _positive = true)
	{
		setInteger(_integer, _positive);
	}
	BigInteger(long long _integer)
	{
		setInteger(_integer);
	}
	BigInteger(const BigInteger& _integer)
	{
		setInteger(_integer.integer, _integer.positive);
	}
	void setInteger(string _integer = "0", bool _positive = true);
	void setInteger(long long _integer);
};
BigInteger big_abs(const BigInteger& a)
{
	BigInteger res(a.integer, true);
	return res;
}
int BigInteger::big_cmp(const string& a, const string& b)
{
	if (a.size() > b.size())
	{
		return 1;
	}
	else if (a.size() < b.size())
	{
		return -1;
	}
	else
	{
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] > b[i])
			{
				return 1;
			}
			else if (a[i] < b[i])
			{
				return -1;
			}
		}
		return 0;
	}
}
string BigInteger::big_add(const string& a, const string& b)
{
	string res(a.size() > b.size() ? a.size() + 1 : b.size() + 1, '0');
	int ai = (int)a.size() - 1;
	int bi = (int)b.size() - 1;
	int i = (int)res.size() - 1;
	int acc = 0;
	while (ai >= 0 && bi >= 0)
	{
		int tmp = a[ai--] - '0' + b[bi--] - '0' + acc;
		res[i--] = tmp % 10 + '0';
		acc = tmp / 10;
	}
	while (ai >= 0)
	{
		int tmp = a[ai--] - '0' + acc;
		res[i--] = tmp % 10 + '0';
		acc = tmp / 10;
	}
	while (bi >= 0)
	{
		int tmp = b[bi--] - '0' + acc;
		res[i--] = tmp % 10 + '0';
		acc = tmp / 10;
	}
	if (acc != 0)
	{
		res[0] += acc;
	}
	return res[0] == '0' ? res.substr(1) : res;
}
string BigInteger::big_sub(const string& a, const string& b)
{
	string res(a.size(), '0');
	int ai = (int)a.size() - 1;
	int bi = (int)b.size() - 1;
	int i = (int)res.size() - 1;
	int bor = 0;
	while (ai >= 0 && bi >= 0)
	{
		int ta = a[ai--] - '0' - bor;
		int tb = b[bi--] - '0';
		if (ta < tb)
		{
			bor = 1;
			ta += 10;
		}
		else
		{
			bor = 0;
		}
		res[i--] = ta - tb + '0';
	}
	while (ai >= 0)
	{
		int ta = a[ai--] - '0' - bor;
		int tb = 0;
		if (ta < tb)
		{
			bor = 1;
			ta += 10;
		}
		else
		{
			bor = 0;
		}
		res[i--] = ta - tb + '0';
	}
	for (int i = 0; i < res.size(); i++)
	{
		if (res[i] != '0')
		{
			return res.substr(i);
		}
	}
	return "0";
}
string BigInteger::big_mul(const string& a, const string& b)
{
	if (a == "0" || b == "0")
		return string("0");
	int m = (int)a.length();
	int n = (int)b.length();
	vector<int> pos(m + n, 0);
	for (int i = m - 1; i >= 0; i--)
	{
		for (int j = n - 1; j >= 0; j--)
		{
			int p1 = i + j, p2 = i + j + 1;
			int mul = (a[i] - '0') * (b[j] - '0');
			int sum = mul + pos[p2];
			pos[p1] += sum / 10;
			pos[p2] = sum % 10;
		}
	}
	string res;
	for (int p : pos)
	{
		if (!(p == 0 && res.empty()))
		{
			res.append(1, p + '0');
		}
	}
	return res;
}
string BigInteger::big_div(const string& a, const string& b, string& remainder_ret)
{
	string res(a.size(), '0');
	string remainder = "";
	for (int i = 0; i < res.size(); )
	{
		if (remainder == "0" && a[i] == '0')
		{
			i++;
			continue;
		}
		int len = 1;
		while (i + len <= a.size() && BigInteger::big_cmp(remainder + a.substr(i, len), b) < 0)
		{
			len++;
		}
		string cur = remainder + a.substr(i, len);
		if (i + len > a.size())
		{
			remainder = cur;
			break;
		}
		for (int j = 9; j > 0; j--)
		{
			string tmp = "0";
			tmp[0] += j;
			if (big_cmp(big_mul(tmp, b), cur) <= 0)
			{
				res[i + len - 1] = tmp[0];
				remainder = big_sub(cur, big_mul(tmp, b));
				if (remainder == "0")
				{
					remainder = "";
				}
				break;
			}
		}
		i += len;
	}
	if (remainder == "")
	{
		remainder = "0";
	}
	remainder_ret = remainder;
	for (int i = 0; i < res.size(); i++)
	{
		if (res[i] != '0')
		{
			return res.substr(i);
		}
	}
	return "0";
}
bool operator > (const BigInteger& a, const BigInteger& b)
{
	if (a.positive && !b.positive)
	{
		return true;
	}
	else if (!a.positive && b.positive)
	{
		return false;
	}
	else if (a.positive && b.positive)
	{
		if (BigInteger::big_cmp(a.integer, b.integer) > 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (BigInteger::big_cmp(a.integer, b.integer) < 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
bool operator < (const BigInteger& a, const BigInteger& b)
{
	if (a.positive && !b.positive)
	{
		return false;
	}
	else if (!a.positive && b.positive)
	{
		return true;
	}
	else if (a.positive && b.positive)
	{
		if (BigInteger::big_cmp(a.integer, b.integer) < 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (BigInteger::big_cmp(a.integer, b.integer) > 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
bool operator >= (const BigInteger& a, const BigInteger& b)
{
	return !(a < b);
}
bool operator <= (const BigInteger& a, const BigInteger& b)
{
	return !(a > b);
}
bool operator == (const BigInteger& a, const BigInteger& b)
{
	if (a.positive == b.positive && a.integer == b.integer)
	{
		return true;
	}
	else
	{
		return false;
	}
}
ostream& operator << (ostream& out, const BigInteger& a)
{
	if (!a.positive)
	{
		out << "-";
	}
	out << a.integer;
	return out;
}
istream& operator >> (istream& in, BigInteger& a)
{
	string str;
	in >> str;
	a.setInteger(str);
	return in;
}
BigInteger operator + (const BigInteger& a, const BigInteger& b)
{
	BigInteger res;
	if (a.positive && b.positive)
	{
		res.setInteger(BigInteger::big_add(a.integer, b.integer), true);
	}
	else if (!a.positive && !b.positive)
	{
		res.setInteger(BigInteger::big_add(a.integer, b.integer), false);
	}
	else
	{
		if (big_abs(a) == big_abs(b))
		{
			res.setInteger(0);
		}
		else if (big_abs(a) > big_abs(b))
		{
			res.setInteger(BigInteger::big_sub(a.integer, b.integer), a.positive);
		}
		else
		{
			res.setInteger(BigInteger::big_sub(b.integer, a.integer), b.positive);
		}
	}
	return res;
}
BigInteger operator - (const BigInteger& a, const BigInteger& b)
{
	BigInteger b_neg(b.integer, !b.positive);
	return a + b_neg;
}
BigInteger operator * (const BigInteger& a, const BigInteger& b)
{
	if (a.integer == "0" || b.integer == "0")
	{
		return BigInteger(0);
	}
	return BigInteger(BigInteger::big_mul(a.integer, b.integer), a.positive == b.positive ? true : false);
}
BigInteger operator / (const BigInteger& a, const BigInteger& b)
{
	if (big_abs(a) < big_abs(b))
	{
		return BigInteger(0);
	}
	string remainder;
	return BigInteger(BigInteger::big_div(a.integer, b.integer, remainder), a.positive == b.positive ? true : false);
}
BigInteger operator % (const BigInteger& a, const BigInteger& b)
{
	if (big_abs(a) < big_abs(b))
	{
		return BigInteger(a);
	}
	string remainder;
	BigInteger::big_div(a.integer, b.integer, remainder);
	return BigInteger(remainder, a.positive);
}
BigInteger operator ^ (const BigInteger& a, const BigInteger& b)
{
	if (a.integer == "1" && b == BigInteger(-1))
	{
		return BigInteger(a);
	}
	if (a.integer == "0" || !b.positive)
	{
		return BigInteger(0);
	}
	if (b.integer == "0")
	{
		return BigInteger(1);
	}
	if (a.integer == "1")
	{
		return b % BigInteger(2) == BigInteger(0) ? BigInteger(1) : BigInteger("1", a.positive);
	}
	if (b == BigInteger(1))
	{
		return BigInteger(a);
	}
	return b % BigInteger(2) == BigInteger(0) ? (a * a) ^ (b / BigInteger(2)) : a * ((a * a) ^ (b / BigInteger(2)));
}
void BigInteger::setInteger(string _integer, bool _positive)
{
	if (_integer == "0")
	{
		this->integer = _integer;
		this->positive = true;
		return;
	}
	if (_integer[0] == '-')
	{
		this->positive = false;
		this->integer = _integer.substr(1);
	}
	else
	{
		this->integer = _integer;
		this->positive = _positive;
	}
}
void BigInteger::setInteger(long long _integer)
{
	if (_integer >= 0)
	{
		this->positive = true;
	}
	else
	{
		this->positive = false;
		_integer = -_integer;
	}
	stringstream ss;
	ss << _integer;
	this->integer = ss.str();
}
int main()
{
	/*     * 构造函数分为以下2种, 并且可以使用setInteger成员函数重新设置大整数, 可混合使用        (1) 使用string            string a = "-101";            BigInteger bi_a(a);            bi_a.setInteger("1024");            string b = "7777"            BigInteger bi_b(b);        (2) 使用整数            BigInteger bi_a(-101);            BigInteger bi_b(65533);            bi_b.setInteger(234);     * 大整数运算包含加减乘除，求余，求次方，注意:由于优先级的问题，求次方的时候加括号，例如(a ^ b)     *      * 支持 > < >= <= == 的比较     *     * 可以使用big_abs()函数求绝对值     */
	string a = "-24";
	int b = 123;
	BigInteger ba(a);
	BigInteger bb(b);
	cout << "a = " << ba << ", " << "b = " << bb << endl;
	cout << "a + b = " << ba + bb << endl;
	cout << "a - b = " << ba - bb << endl;
	cout << "a * b = " << ba * bb << endl;
	cout << "a / b = " << ba / bb << endl;
	cout << "b / a = " << bb / ba << endl;
	cout << "b % abs(a) = " << bb % ba << endl;
	ba.setInteger(-2);
	bb.setInteger("11");
	cout << "a = " << ba << ", " << "b = " << bb << endl;
	cout << "a ^ b = " << (ba ^ bb) << endl; //求次方需加括号，否则会报错
	cout << "b ^ abs(a) = " << (bb ^ big_abs(ba)) << endl; //求次方需加括号，否则会报错
	cout << "b ^ 3 = " << (bb ^ BigInteger(3)) << endl; //求次方需加括号，否则会报错
	ba.setInteger("1023142141414141");
	bb.setInteger("1241414");
	cout << "a = " << ba << ", " << "b = " << bb << endl;
	cout << "a + b = " << ba + bb << endl;
	cout << "a - b = " << ba - bb << endl;
	cout << "a * b = " << ba * bb << endl;
	cout << "a / b = " << ba / bb << endl;
	cout << "b / a = " << bb / ba << endl;
	cout << "a % b = " << ba % bb << endl;
	return 0;
}