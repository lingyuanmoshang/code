#include<iostream>
#include<istream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define ull unsigned long long
const int base1 = 233;
const int base2 = 23;
const int mod1 = 1000007;
const int mod2 = 100007;
const int maxn = 1000005;
char a[maxn],b[maxn];
int getval(char ch)
{
	return ch;
}
vector<int>p[mod1+2];
int main()
{
	int n;
	while (cin >> n)
	{
	    memset(p,0,sizeof(p));
		while (n--)
		{
			cin >> a;
			gets(b);
			int sum1 = 0, sum2 = 0;
			sum1 = getval(b[0]) % mod1;
			sum2 = getval(b[0]) % mod2;
			for (int i = 1; i < strlen(b); ++i)
			{
				sum1 = (sum1 * base1 + getval(b[i])) % mod1;
				sum2 = (sum2 * base2 + getval(b[i])) % mod2;
			}
			if (a[0] == 'a')
			{
				p[sum1].push_back (sum2);
			}
			else
			{
				bool f = false;
				for (int i = 0; i < p[sum1].size(); ++i)
				{
					if (sum2 == p[sum1][i])
					{
						f = true;
						cout << "yes" << endl;
						break;
					}
				}
				if (!f)
					cout << "no" << endl;
			}
		}
	}
	return 0;
}
