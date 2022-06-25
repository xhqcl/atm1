#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#define NUM 1001
void denglu();
void shezhi();
void enter();
void enter2();
void tuichu();
void zhuanzhang();
void chaxun();
void qukuan();
void cunkuan();
void xiugai();
void load();

int j=0,k;

struct yonghu
{
char ID[20];
char key[20];
int account;
}user[NUM];
void main()
{
enter();//进入界面 
}
//主函数结束
void enter()//一级菜单函数
{
int a;
load();
system("cls");
printf(" \t\t\t      ATM模拟系统\n");
printf(" \t\t\t  *******************\n");
printf("\t\t\t  |欢迎使用本银行系统|\n");
printf(" \t\t\t  ********************\n");
printf("\n\n");
printf("\t\t\t ****您将有以下选择****\n");
printf("\n\n");
printf(" \t\t\t  ++++++++++++++++++++\n");
printf(" \t\t\t  +      1.开户      +\n");
printf(" \t\t\t  +      2.登录      +\n");
printf(" \t\t\t  +      3.退出      +\n");
printf(" \t\t\t  +      4.英文      +\n");
printf(" \t\t\t  ++++++++++++++++++++\n");
printf("\n\n");
printf(" \t\t\t   |请输入您的操作号| \n\n\t\t\t\t  ");
    scanf("%d",&a);
  switch(a)
{
case 1:system("cls");//清屏
shezhi();
break;
    case 2:system("cls");
denglu();
        break;
case 3:system("cls");
        tuichu();
break;
default:printf("\t\t\t\t无此操作项\n请重新选择\n");
system("pause");
system("cls");
enter();
}
}
void load()
{
FILE *fp;
    int i;
if((fp=fopen("data.txt","r"))==NULL)
    {
        printf("不能打开文件\n");
        return;
    }
    for(i=0;!feof(fp);i++)
    {
        fread(&user[i],sizeof(struct yonghu),1,fp);
    }
    fclose(fp);
    system("cls");
    printf("文件读取成功\n");
}
void save()      
{
    FILE *fp;
    if((fp=fopen("data.txt","w"))==NULL)
    {
        printf("无法打开文件\n");
        exit(0);
    }
    fwrite(user,sizeof(struct yonghu),NUM,fp);
    printf("文件写入完成\n");
    fclose(fp);
}
void shezhi()
{
char ch;
if(user[1000].account!=0)
{
j=user[1000].account;
}
printf("\n\n\t\t\t\t请设置您的卡号:\n\t\t\t\t  ");
scanf("%s",user[j].ID);
    printf("\n\t\t\t\t请设置您的密码:\n\t\t\t\t  ");
        scanf("%s",user[j].key);
          user[j].account=0;
    printf("卡号：%s \n余额：%4d\n",user[j].ID,user[j].account);
user[1000].account=++j;
save();
printf("\n\n\t\t\t\t恭喜您注册成功!");
printf("\n\n\n");
system("pause");
printf("\t\t\t\t按回车键返回上一级\n");
    printf("\n\n\n");
system("cls");
ch=getchar();//用来接收最后的回车符
if(ch=='\n')
{
       enter();
}
}
void tuichu()
{
printf("\t\t\t**********谢谢**********\n");
    printf("\t\t\t******感谢您的使用******\n");
    printf("\t\t\t******欢迎下次光临******\n");
    printf("\t\t\t**********再见**********\n");
    exit(0);
}
void denglu()
{
int i,n,m;
char  id[20],kw[20];
printf("\t\t    连续输错账号或密码三次，将返回主菜单\n");

for(i=0;i<3;i++)
{
printf("请输入登录账号\n");
scanf("%s",id);
for(k=0;k<NUM-1;k++)
{
if(strcmp(id,user[k].ID)==0)
{
m=1;
break;
}
else
m=0;
}
if(m==0)
{
printf("该账号不存在,剩余输入次数%d\n",2-i);
if((2-i)==0)
{
printf("账号输入错误3次，即将返回菜单......\n");
system("pause");
enter();
}
}

if(m==1)
{
printf("请输入登录密码\n");
for(n=0;n<3;n++)
{
scanf("%s",kw);
if(strcmp(kw,user[k].key)==0)
{
system("cls");
enter2();
}
else
{
printf("密码输入错误,剩余输入次数%d\n",2-n);
if((2-n)==0)
{
printf("密码输入错误3次，即将返回菜单......\n");
system("pause");
enter();
}
}
}
}
}
}
void enter2()
{
int n;
do
{
printf("\n\n\n");
printf(" \t\t\t+++++++++++++++++++++++++++++\n");
printf(" \t\t\t+  A T M 系 统 个 人 界 面  +\n");
printf(" \t\t\t+     您 有 以 下 选 择     +\n");
printf(" \t\t\t+++++++++++++++++++++++++++++\n");
printf(" \t\t\t    ++++++++++++++++++++\n");
printf(" \t\t\t    #     1.  查询     #\n");
printf(" \t\t\t    #     2.  取款     #\n");
    printf(" \t\t\t    #     3.  转账     #\n");
printf(" \t\t\t    #     4.  存款     #\n");
printf(" \t\t\t    #     5.修改密码   #\n");
printf(" \t\t\t    #     6.返回目录   #\n");
printf(" \t\t\t    ++++++++++++++++++++\n\n\t\t\t\t  ");
scanf("%d",&n);
    switch(n)
{
case 1:system("cls");
chaxun();
break;
    case 2:system("cls");
qukuan();
        break;
case 3:system("cls");
        zhuanzhang();
break;
case 4:system("cls");
        cunkuan();
break;
case 5:system("cls");
        xiugai();
break;
    case 6:system("cls");
        enter();
break;
default:printf("\t\t\t\t无此操作项\n\n");
system("pause");
system("cls");
}
}while(n>4&&n<0);
}


void chaxun()
{
char ch;
printf("\t\t\t******欢迎使用查询服务******\n");
printf("\t\t\t     您的余额为%d元\n\n",user[k].account);
system("pause");
    system("cls");
printf("\n\n\n");
ch=getchar();//用来接收最后的回车符
if(ch=='\n')
{
enter2();
}
}
void qukuan()
{
int i,x;
char a,ch;
printf(" \t\t\t+++++++++++++++++++++++++++++++\n");
printf(" \t\t\t+  本银行最低取款金额为100元  +\n");
    printf(" \t\t\t+       您卡号的余额为        +\n");
printf(" \t\t\t+       %d元                  +\n",user[k].account);
printf(" \t\t\t+    请选择你要提取的金额:    +\n");
printf(" \t\t\t+    1: 100元     2:200元     +\n");
printf(" \t\t\t+    3.500元      4:1000元    +\n");
printf(" \t\t\t+    5:2000元     6:5000元    +\n");
printf(" \t\t\t+        7: 自定义金额        +\n");
printf(" \t\t\t+++++++++++++++++++++++++++++++\n\n\t\t\t\t      ");
scanf("%d",&i);
if(i==1)   
{
    x=100;
}
else
if(i==2)
{
    x=200;
}
else
if(i==3)
{
    x=500;
}
else
if(i==4)
{
    x=1000;
}
else
if(i==5)
{
    x=2000;
}
else
if(i==6)
{
    x=5000;
}
else
if(i==7)
{
printf("\t\t\t\t请输入自定义的金额:\n\t\t\t\t  ");
scanf("%d",&x);
}
if(x<=user[k].account)
{
user[k].account=user[k].account-x;
printf(" \t\t\t\t您取了%d元钱\n",x);
            printf(" \t\t\t\t您的余额为%d元\n",user[k].account);
}
       else if(x>user[k].account)
{
printf("\t\t\t\t您卡里的余额不足\n");
printf("\t\t\t\t请重新输入提取金额:\n");
}
printf(" \t\t\t\t请选择是否继续取款\n");
    printf(" \t\t\t\t是:Y          否:N\n\n\t\t\t\t  ");
scanf("%s",&a);
if(a=='Y')
{
save();
qukuan();
}
else
if(a=='N')
{
save();
system("pause");//冻结屏幕
system("cls");
printf("\n\n\n");
}
else
{
save();
system("pause");//冻结屏幕
system("cls");
printf("\n\n\n");
}
ch=getchar();//用来接收最后的回车符
if(ch=='\n')
{
system("cls");
enter2();
        }
}


void cunkuan()
{
int a;
printf("\t\t\t\t请输入存入账户的金额:\n\n\t\t\t\t  ");
scanf("%d",&a);
user[k].account=user[k].account+a;
save();
printf(" \t\t\t\t您的余额为%d元\n",user[k].account);
system("pause");//冻结屏幕
system("cls");
printf("\n\n\n");
enter2();
}


void xiugai()
{
printf("\t\t\t\t请输入新的密码\n\t\t\t\t  ");
scanf("%s",user[k].key);
save();
    system("pause");//冻结屏幕
system("cls");
printf("\n\n\n");
enter2();
}


void zhuanzhang()
{
int a,b,c,x;
char kahao[20];
printf("\t\t\t       请输入转账卡号:\n\t\t\t\t  ");
scanf("%s",kahao);
for(a=0;a<NUM-1;a++)
{
if(!strcmp(kahao,user[a].ID))
{
printf("\t\t\t\t  卡号正确\n\n");
break;
}
}
if(strcmp(kahao,user[a].ID))
{
printf("\t\t\t\t  卡号不存在\n\n");
system("pause");
zhuanzhang();
}
printf("\t\t\t\t请输入转账金额\n\t\t\t\t    ");
scanf("%d",&x);
if(x>user[k].account)
{
printf("\t\t\t\t您卡里的余额不足\n");
printf("\t\t\t\t请重新输入提取金额:\n");
}
else
{
user[k].account=user[k].account-x;
user[a].account=user[a].account+x;
save();
}
system("pause");//冻结屏幕
system("cls");
printf("\n\n\n");
enter2();
}

