#include<stdio.h>
int a[10], b[10], c[10], t, cnt, cnt1, AK[20][5],i,j,k;
#define bool int
#define true 1
#define false 0
struct AC
{
	int aa, bb, cc;
    bool f1, f2, f3;
}s[20];
int main()
{
	for (i = 0;; i++) {
		if (i == 16 || i == 82 || i == 211) {
			s[++cnt].aa=60;s[cnt].bb=120;s[cnt].cc=90;s[cnt].f1=true;s[cnt].f2=true;s[cnt].f3=true;
		}
		if (i == 141 || i == 241 || i == 267) {
			s[++cnt].aa = 48;s[cnt].bb=144;s[cnt].cc=30;s[cnt].f1=true;s[cnt].f2=true;s[cnt].f3=true;
		}
		if (i == 47 || i == 239) {
			s[++cnt].aa = 78;s[cnt].bb=150;s[cnt].cc=90;s[cnt].f1=true;s[cnt].f2=true;s[cnt].f3=true;
		}
		if (i == 120 || i == 182 || i == 309) {
			s[++cnt].aa = 60;s[cnt].bb=162;s[cnt].cc=18;s[cnt].f1=true;s[cnt].f2=true;s[cnt].f3=true;
		}
		for (j = 1; j <= 3; ++j) {
			if (a[j] != 0) {
				a[j]--;
			}
		}
		for (j = 1; j <= 8; ++j) {
			if (b[j] != 0) {
				b[j]--;
			}
		}
		for (j = 1; j <= 5; ++j) {
			if (c[j] == 1) {
				cnt1++;
			}
			if (c[j] != 0) {
				c[j]--;
			}
		}
        for (j = 1; j <= cnt; ++j){
            if(!s[j].f1) AK[j][1]++;
            if(!s[j].f2) AK[j][2]++;
        }
		for (j = 1; j <= cnt; ++j) {
			if (s[j].aa != 0) {
				for (k = 1; k <= 3; k++) {
					if (a[k] == 0 && s[j].f1) {
						a[k] = s[j].aa;
						s[j].f1 = false;
						break;
					}
				}
			}
			if (s[j].bb != 0) {
				for (k = 1; k <= 8; k++) {
					if (b[k] == 0 && !s[j].f1 && AK[j][1] == s[j].aa) {
						b[k] = s[j].bb;
						s[j].f2 = false;
						break;
					}
				}
			}
			if (s[j].cc != 0) {
				for (k = 1; k <= 5; ++k) {
					if (c[k] == 0 && !s[j].f2 && AK[j][2] == s[j].bb) {
						c[k] = s[j].cc;
						s[j].f3 = false;
						break;
					}
				}
			}
		}
		printf("第%d分钟各车间状态：\n",i);
		for (j = 1; j <= 3; ++j)
			printf("%3d%s", a[j], j == 3 ?" \n":"  ");
		for (j = 1; j <= 8; ++j)
			printf("%d%s", b[j], j == 8 ?"  \n":"  ");
		for (j = 1; j <= 5; ++j)
			printf("%d%s", c[j], j == 5 ?"  \n":"  ");
		puts("");
		if (cnt1 == 11) {
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}