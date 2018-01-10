#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void display(int *a);
void swap(int *x,int *y);
int main()
{
    int ch;
    static int b=3,y=3;
    int a[4][4]={
                    {1,4,15,7},
                    {8,10,2,11},
                    {14,3,6,13},
                    {12,9,5, },
                };
    display(a);
    while(1)
    {
        ch=getch();
        switch(ch)
        {
            case 72:
                system("cls");
                if(b<0)
                {
                    b=3;
                }
                printf("%d\n",b);
                swap(&a[b-1][y],&a[b][y]);
                b=b-1;
                display(a);
                break;
            case 75:
                system("cls");
                if(y<0)
                {
                    y=3;
                }
                swap(&a[b][y-1],&a[b][y]);
                y=y-1;

                display(a);
                break;
            case 77:
                system("cls");
                if(y>3)
                {
                    y=0;
                }
                swap(&a[b][y+1],&a[b][y]);
                y=y+1;

                display(a);
                break;
            case 80:
                system("cls");
                if(b>3)
                {
                    b=0;
                }
                swap(&a[b+1][y],&a[b][y]);
                b=b+1;

                display(a);
                break;
        }

    }
    return 0;
}
void display(int *a)
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("%d\t",*(a+i*4+j));
        }
        printf("\n");
    }
}
void swap(int *x,int *y)
{
    int t;
    t=*x;
    *x=*y;
    *y=t;
}
