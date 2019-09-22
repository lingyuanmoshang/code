#include<stdio.h>
int a[10],wait,b[10],c[10],x,y,z,cnt,i,j,k;
bool f1[10],f2[10],f3[10];
int main(){
    for(i=15;;i+=15){
        x=y=z=0;
        if(i<=735){
            wait++;
            printf("等待队列+1\n");
        }
        printf("\n现在的时间是%d,现在等待队列中有%d人\n",i,wait);
        for(j=1;j<=5;++j){
            if(c[j]+15>=270){
                c[j]=0,cnt++;
                f3[j]=1;
            }
            else if(c[j]+15<270&&c[j]>=180) {
                c[j]+=15,z++;
            }
        }
        for(j=1;j<=8;++j){
            if(b[j]+15>=180&&z==5){
                b[j]=180;
                y++;
            }
            else if(b[j]>=60&&b[j]+15<180){
                b[j]+=15,y++;
            }
            else if(b[j]+15>=180&&z<5){
                for(k=1;k<=5;++k){
                    if(c[k]==0&&!f3[k]){
                        c[k]=b[j]+15;
                        b[j]=0;
                        f2[j]=1;
                        z++;
                        break;
                    }
                }
            }
        }
        for(j=1;j<=3;++j){
            if(a[j]+15>=60&&y>=8){
                a[j]=60;
                x++;
            }
            else if(a[j]>0&&a[j]+15<60){
                a[j]+=15,x++;
                continue;
            }
            else if(a[j]+15>=60&&y<8){
                for(k=1;k<=8;++k){
                    if(b[k]==0&&!f2[k]){
                        b[k]=a[j]+15;
                        a[j]=0;
                        f1[j]=1;
                        y++;
                        break;
                    }
                }
            }
        }
        if(wait>0){
            if(x<3) {
                for(j=1;j<=3;++j){
                    if(a[j]==0&&wait>0&&!f1[j]){
                        a[j]=15;
                        wait--;
                        x++;
                    }
                }
            }
        }
        printf("现在A车间状态:\n");
        for(int j=1;j<=3;++j)
            printf("第%d个车间:%d%s",j,a[j],j==3?"\n\n":"    ");
        printf("现在B车间状态:\n");
        for(int j=1;j<=8;++j)
            printf("第%d个车间:%d%s",j,b[j],j==8?"\n\n":"    ");
        printf("现在C车间状态:\n");
        for(int j=1;j<=5;++j)
            printf("第%d个车间:%d%s",j,c[j],j==5?"\n\n":"    ");
        printf("总共已来%d辆车,已完成%d辆,等待队列中还有%d辆\n",(i>=735?735:i)/15,cnt,wait);
        printf("-----------------------------------------------------------------------------------------\n");
        for(int j=1;j<=10;++j)
        	f1[j]=f2[j]=f3[j]=0;
        if(cnt==49){
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}