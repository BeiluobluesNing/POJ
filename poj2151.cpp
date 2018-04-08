//
//  main.cpp
//  algorithm_poj
//
//  Created by 宁沛荣 on 2017/12/7.
//  Copyright © 2017年 宁沛荣. All rights reserved.
//

#include<iostream>
#include<stdio.h>
#define rep(i,a,b) for(int i=int(a);i<=int(b);i++)
using namespace std;
double p[1000][30];     //输入每个队队每个题目的概率
double dp[30][30];      //前i道题目作出j题概率，中间变量
int N,T,M;

int main(){
    //要求算出所有队伍能计算出一题同时，冠军全解的概率
    while(scanf("%d %d %d",&M,&T,&N)!=EOF){           //M为总题数，T为队伍数目，N为预期第一名能做题目数
        if(M==0 && T==0 && N==0)
            break;

        rep(i,1,T)  //for(int i =1; i<T; i++)
            rep(j,1,M)//for(int j =1; j<M; j++)
                scanf("%lf",&p[i][j]);        //第i队伍作出第题目的概率

        double pa=1.0;
        double pb=1.0;
        rep(k,1,T){     //for(int k =1 ;k<T;k++)
            dp[0][0]=1;     //初始化
            rep(i,1,M)      //for(int i =1;i<M; i++)
            rep(j,0,i)      //for(int j =0;i<i; i++)
            {
                dp[i][j] = dp[i-1][j]*(1.0-p[k][i]);        //前i道题目作出j道的概率
                        //等于前i-1题作出j题概率*k队的第i题做不出概率
                if(j)       //j不为0的话
                    dp[i][j]+=dp[i-1][j-1]*p[k][i];
                        //等于加上前i-1道题目做出j-1加上第i道题目作出的概率
            }
            double suma,sumb;       //suma即p(A)
            suma=sumb=0;
            rep(i,1,N-1)    //for(int i =1;i<N-1; i++)
                sumb+=dp[M][i],suma+=dp[M][i];
            rep(i,N,M)      ////for(int i =N;i<M; i++)
                suma+=dp[M][i];
            pa*=suma;
            pb*=sumb;
        }
        printf("%.3f\n",pa-pb);
    }
}

//
//            for(int i = 1; i<M;i++)
//                for(int j = 0;j < i ;j++)
//                {
//                    dp[i][j] = dp[i-1][j] * (1.0 - p[k][i]);
//                    if(j)
//                        dp[i][j]+=dp[i-1][j-1]*p[k][i];
//
//                }
//
