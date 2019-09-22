#include <stdio.h>
#define bool int
#define true 1
#define false 0
int a[10], b[10], c[10], t, cnt, cnt1, AK[20][10], i, j, k;
struct AC
{
	int aa, bb, cc;
	bool f1, f2, f3;
} s[20];
int main()
{
	for (i = 1; i <= 49; ++i){
		s[i].aa = 60;s[i].bb = 120;s[i].cc = 90;s[i].f1 = s[i].f2 = s[i].f3 = true;
	}
	for (i = 0;; i++)
	{
		for (j = 1; j <= 3; ++j)
		{
			if (a[j] != 0)
			{
				a[j]--;
			}
		}
		for (j = 1; j <= 8; ++j)
		{
			if (b[j] != 0)
			{
				b[j]--;
			}
		}
		for (j = 1; j <= 5; ++j)
		{
			if (c[j] != 0)
			{
				c[j]--;
			}
		}
		for (j = 1; j <= 49; ++j)
		{
			if (!s[j].f1)
				AK[j][1]++;
			if (!s[j].f2)
				AK[j][2]++;
			if (!s[j].f3)
				AK[j][3]++;
		}
		for (j = 1; j <= 49; ++j)
		{
			if (s[j].aa != 0)
			{
				cnt1++;
				for (k = 1; k <= 3; k++)
				{
					if (a[k] == 0 && s[j].f1)
					{
						a[k] = s[j].aa;
						s[j].f1 = false;
						break;
					}
				}
			}
			if (s[j].bb != 0)
			{
				for (k = 1; k <= 8; k++)
				{
					if (b[k] == 0 && !s[j].f1 && AK[j][1] == s[j].aa)
					{
						b[k] = s[j].bb;
						s[j].f2 = false;
						break;
					}
				}
			}
			if (s[j].cc != 0)
			{
				for (k = 1; k <= 5; ++k)
				{
					if (c[k] == 0 && !s[j].f1 && !s[j].f2 && AK[j][2] == s[j].bb)
					{
						c[k] = s[j].cc;
						s[j].f3 = false;
						break;
					}
				}
			}
		}
		printf("第%d分钟各车间状态：\n", i);
		for (j = 1; j <= 3; ++j)
			printf("%d%s", a[j], j == 3 ? "  \n" : "  ");
		for (j = 1; j <= 8; ++j)
			printf("%d%s", b[j], j == 8 ? "  \n" : "  ");
		for (j = 1; j <= 5; ++j)
			printf("%d%s", c[j], j == 5 ? "  \n" : "  ");
		printf("CNT=%d\n",cnt1);
		puts("");
		for (j = 1; j <= 49; ++j)
		{
			if (s[j].f1 == false && s[j].f2 == false && s[j].f3 == false)
			{
				bool flag = 1;
				for (k = 1; k <= 3; ++k)
					if (a[k])
						flag = 0;
				for (k = 1; k <= 8; ++k)
					if (b[k])
						flag = 0;
				for (k = 1; k <= 5; ++k)
					if (c[k])
						flag = 0;
				if (flag)
				{
					printf("%d\n", i);
					return 0;
				}
			}
		}
	}
	return 0;
}