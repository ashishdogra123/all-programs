#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void driver(int m,int y);
void display(int mon,int year,int r,int z);
int main()
{
    int m,y;
    int ch;
    printf("Enter the Month and Year.\t");
    scanf("%d%d",&m,&y);
    driver(m,y);
    while(1)
    {
        ch=getch();
        switch(ch)
        {

            case 72:
                system("cls");
                y=y-1;
                driver(m,y);
                break;
            case 75:
                system("cls");
                m=m-1;
                driver(m,y);
                break;
            case 77:
                system("cls");
                m=m+1;
                driver(m,y);
                break;
            case 80:
                system("cls");
                y=y+1;
                driver(m,y);
                break;
            case 91:
                exit(1);
                break;
        }
    }
    return 0;
}
void display(int mon,int year,int r,int z)
{
    int a[6][7];
    int m=0,i,j,k;
    char d[7][4]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
    printf("\n");
    for(i=0;i<7;i++)
    {
        printf("%s\t",&d[i][0]);
    }
    printf("\n");
    for(k=0;k<z;k++)
    {
        printf("\t");
    }
    for(i=0;i<6;i++)
    {
        for(j=z;j<7;j++)
        {
            m++;
            a[i][j]=m;
            if(a[i][j]>28)
            {
                if(mon==2&&year==1&&a[i][j]>29)
                {
                    break;
                }
                else if(mon==2&&year==0&&a[i][j]>28)
                {
                    break;
                }
                else if(a[i][j]>30+r)
                {
                    break;
                }
            }
            printf("%d\t",a[i][j]);
        }
        z=0;
        printf("\n");
    }
}
void driver(int m,int y)
{
    int t=0,p=0,q=0,r=0,i,n,o,tdm,tdy,td,tot,z;
    int d=1;
    n=y-2001;
    int a[n];
    for(i=0;i<n;i++)
    {
        a[i]=i+1;
        if(a[i]%4==0||(a[i]%100==0&&a[i]%400==0))
        {
            p++;
        }
    }
    tdy=n*365+p;
    o=m-1;
    int b[o];
    for(i=0;i<o;i++)
    {
        b[i]=i+1;
        if((b[i]<=7&&b[i]%2==1)||(b[i]>7&&b[i]%2==0))
        {
            q++;
        }
    }
    if((m<=7&&m%2==1)||(m>7&&m%2==0))
    {
        r++;
    }
    if(y%4==0||(y%100==0&&y%400==0))
    {
        t++;
    }
    tdm=(o-1)*30+q+28+t;
    if(t==0)
    {
        tdm=tdm%365;
    }
    if(t==1)
    {
        tdm=tdm%366;
    }
    if(tdm<0)
    {
        tdm=0;
    }
    if(m==2&&t==0)
    {
        tdm=tdm+2;
    }
    if(m==2&&t==1)
    {
        tdm=tdm+1;
    }
    td=d-1;
    printf("tdy=%d\t,tdm=%d\t,td=%d",tdy,tdm,td);
    tot=tdy+tdm+td;
    z=tot%7;
    printf("\n\n");
    printf("\t\t  ");
    m=m%12;
    if(m==1)
        printf("JANUARY ");
    if(m==2)
        printf("FEBRUARY ");
    if(m==3)
        printf("MARCH ");
    if(m==4)
        printf("APRIL ");
    if(m==5)
        printf("MAY ");
    if(m==6)
        printf("JUNE ");
    if(m==7)
        printf("JULY ");
    if(m==8)
        printf("AUGUST ");
    if(m==9)
        printf("SEPTEMBER ");
    if(m==10)
        printf("OCTOBER ");
    if(m==11)
        printf("NOVEMBER ");
    if(m==0)
        printf("DECEMBER ");
    printf(" %d",y);
    printf("\n");
    display(m,t,r,z);
}
