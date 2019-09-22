#include<stdio.h>
#define bool int
#define true 1
#define false 0
int a[10], b[10], c[10], d[10], e[10], t, cnt, cnt1, AK[20][10],i,j,k;
struct AC
{
	int aa, bb, cc, dd, ee;
    bool f1, f2, f3, f4, f5;
}s[20];
int main()
{
	for (i = 0;; i++) { 
		cnt1=0;
		if (i == 16) {
			s[++cnt].aa =60;s[cnt].bb=0;s[cnt].cc=90;s[cnt].dd=240;s[cnt].ee=420;s[cnt].f1=true;s[cnt].f2=false;s[cnt].f3=true;s[cnt].f4=true;s[cnt].f5=true;
		}
		if( i == 47) {
			s[++cnt].aa = 78;s[cnt].bb=150;s[cnt].cc=90;s[cnt].dd=0;s[cnt].ee=0;s[cnt].f1=true;s[cnt].f2=true;s[cnt].f3=true;s[cnt].f4=false;s[cnt].f5=false;
		}
		if (i == 88) {
			s[++cnt].aa = 60;s[cnt].bb=120;s[cnt].cc=90;s[cnt].dd=0;s[cnt].ee=0;s[cnt].f1=true;s[cnt].f2=true;s[cnt].f3=true;s[cnt].f4=false;s[cnt].f5=false;
		}
		if (i == 120) {
			s[++cnt].aa= 60;s[cnt].bb=162;s[cnt].cc=0;s[cnt].dd=0;s[cnt].ee=0;s[cnt].f1=true;s[cnt].f2=true;s[cnt].f3=false;s[cnt].f4=false;s[cnt].f5=false;
		}
		if (i == 141) {
			s[++cnt].aa = 48;s[cnt].bb=144;s[cnt].cc=0;s[cnt].dd=288;s[cnt].ee=0;s[cnt].f1=true;s[cnt].f2=true;s[cnt].f3=false;s[cnt].f4=true;s[cnt].f5=false;
		}
		if (i == 182) {
			s[++cnt].aa = 60;s[cnt].bb=162;s[cnt].cc=18;s[cnt].dd=0;s[cnt].ee=0;s[cnt].f1=true;s[cnt].f2=true;s[cnt].f3=true;s[cnt].f4=false;s[cnt].f5=false;
		}
		if (i == 211) {
			s[++cnt].aa = 60;s[cnt].bb=120;s[cnt].cc=90;s[cnt].dd=240;s[cnt].ee=420;s[cnt].f1=true;s[cnt].f2=true;s[cnt].f3=true;s[cnt].f4=true;s[cnt].f5=true;
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
			if (c[j] != 0) {
				c[j]--;
			}
		}
		for (j = 1; j <= 3; ++j) {
			if (d[j] != 0) {
				d[j]--;
			}
		}
		for (j = 1; j <= 2; ++j) {
			if (e[j] != 0) {
				e[j]--;
			}
		}
        for (j = 1; j <= cnt; ++j){
            if(!s[j].f1) AK[j][1]++;
            if(!s[j].f2) AK[j][2]++;
			if(!s[j].f3) AK[j][3]++;
			if(!s[j].f4) AK[j][4]++;
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
					if (c[k] == 0 && !s[j].f1 && !s[j].f2 && AK[j][2] == s[j].bb) {
						c[k] = s[j].cc;
						s[j].f3 = false;
						break;
					}
				}
			}
			if (s[j].dd != 0) {
				for (k = 1; k <= 5; ++k) {
					if (d[k] == 0 && !s[j].f3 && !s[j].f2 && !s[j].f1 && AK[j][3] == s[j].cc) {
						d[k] = s[j].dd;
						s[j].f4 = false;
						break;
					}
				}
			}
			if (s[j].ee != 0) {
				for (k = 1; k <= 5; ++k) {
					if (e[k] == 0 && !s[j].f4 && !s[j].f3 && !s[j].f2 && !s[j].f1 && AK[j][4] == s[j].dd) {
						e[k] = s[j].ee;
						s[j].f5 = false;
						break;
					}
				}
			}
		}
		printf("第%d分钟各车间状态：\n",i);
		for (j = 1; j <= 3; ++j)
			printf("%d%s", a[j], j == 3 ?"  \n":"  ");
		for (j = 1; j <= 8; ++j)
			printf("%d%s", b[j], j == 8 ?"  \n":"  ");
		for (j = 1; j <= 5; ++j)
			printf("%d%s", c[j], j == 5 ?"  \n":"  ");
		for (j = 1; j <= 3; ++j)
			printf("%d%s", d[j], j == 3 ?"  \n":"  ");
		for (j = 1; j <= 2; ++j)
			printf("%d%s", e[j], j == 2 ?"  \n":"  ");
		puts("");
		if(cnt==7) {
			for(j=1;j<=cnt;++j) {
				if(s[j].f1==false&&s[j].f2==false&&s[j].f3==false&&s[j].f4==false&&s[j].f5==false) {
					bool flag=1;
					for (k = 1; k <= 3; ++k)
						if(a[k]) flag=0;
					for (k = 1; k <= 8; ++k)
						if(b[k]) flag=0;
					for (k = 1; k <= 5; ++k)
						if(c[k]) flag=0;
					for (k = 1; k <= 3; ++k)
						if(d[k]) flag=0;
					for (k = 1; k <= 2; ++k)
						if(e[k]) flag=0;
					if(flag) {
						printf("%d\n",i-16);
						return 0;
					}
				}
			}
		}
	}
	return 0;
}