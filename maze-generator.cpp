#include <iostream>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include <windows.h>
using namespace std;
int g[47][61]={},w[2000][2]={};
int wall=2,m=0;
void do_maze(int a)
{

    int x=w[a][0],y=w[a][1],sx=0,sy=0,cont=0;
    if(x%2==0)
    {
        if(g[x+1][y]==0)
        {
            cont++;
            sx=x+1;
            sy=y;
        }
        if(g[x-1][y]==0)
        {
            cont++;
            sx=x-1;
            sy=y;
        }
    }
    else
    {
        if(g[x][y+1]==0)
        {
            cont++;
            sx=x;
            sy=y+1;
        }
        if(g[x][y-1]==0)
        {
            cont++;
            sx=x;
            sy=y-1;
        }
    }
    if(cont==1)
    {
        g[x][y]=1;
        g[sx][sy]=1;
        w[a][0]=0;w[a][1]=0;
        wall--;
        m--;
        for(int j=1;j<5;j++)
           {
                switch(j)
                {
                    case 1:
                    {
                        if(g[sx+1][sy]==0&&sx+1<45)
                        {
                            for(int i=0;i<2000;i++)
                            {
                                if(w[i][0]==0&&w[i][1]==0)
                                {
                                    w[i][0]=sx+1;w[i][1]=sy;
                                    wall++;
                                    m++;
                                    i=2001;
                                }
                            }
                        }
                        break;
                    }
                    case 2:
                    {
                        if(g[sx-1][sy]==0&&sx-1>0)
                        {
                            for(int i=0;i<2000;i++)
                            {
                                if(w[i][0]==0&&w[i][1]==0)
                                {
                                    w[i][0]=sx-1;w[i][1]=sy;
                                    wall++;
                                    m++;
                                    i=2001;
                                }
                            }
                        }
                        break;
                    }
                    case 3:
                    {
                        if(g[sx][sy+1]==0&&sy+1<60)
                        {
                            for(int i=0;i<200;i++)
                            {
                                if(w[i][0]==0&&w[i][1]==0)
                                {
                                    w[i][0]=sx;w[i][1]=sy+1;
                                    wall++;
                                    m++;
                                    i=2001;
                                }
                            }
                        }
                        break;
                    }
                    case 4:
                    {
                        if(g[sx][sy-1]==0&&sy-1>0)
                        {
                            for(int i=0;i<2000;i++)
                            {
                                if(w[i][0]==0&&w[i][1]==0)
                                {
                                    w[i][0]=sx;w[i][1]=sy-1;
                                    wall++;
                                    m++;
                                    i=2001;
                                }
                            }
                        }
                        break;
                    }
                }
            }
        }
    else
    {
        wall--;
        m--;
        w[a][0]=0;w[a][1]=0;
    }



}
int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    srand(time(NULL));
    w[0][0]=1;w[0][1]=2;w[1][0]=2;w[1][1]=1;
    g[1][1]=1;
    while(wall>0)
    {
        if(m>=0)
        {
            m=0;
        }
        int a=0;
        a= rand()%(wall-m+1);
        if(w[a][0]!=0&&w[a][1]!=0)
        {
            do_maze(a);
        }
    }
    g[45][60]=1;
    g[1][0]=1;
    for(int i=0;i<47;i++)
        {
            for(int j=0;j<61;j++)
            {
                if(g[i][j]==0)
                    {
                      SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                      cout<<"¢i¢i";
                    }

                else
                   {
                       SetConsoleTextAttribute(hConsole,0);
                       cout<<"¢i¢i";
                   }
            }
            cout<<endl;
        }
}
