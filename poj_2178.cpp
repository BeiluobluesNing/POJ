//
//  poj_2178.cpp
//  algorithm_poj
//
//  Created by 宁沛荣 on 2017/12/7.
//  Copyright © 2017年 宁沛荣. All rights reserved.
//

#include "poj_2178.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// prev HP_H, prev N, magic_info
pair<pair<int,int>,pair<char,int> > back[52][101][10];
// turn HP_H N
int tbl[52][101][10];   //回合数 怪兽最初位置 英雄血量 英雄 怪兽此时血量
int damages[10];        //伤害量
int N, HP_H, MP_H, HP_M, N_M, V, dH;

void mom_turn(int prev_t, int prev_hp, int prev_pos,int h_hp, int pos, int mom_hp,char magic, int magic_param){
    pos = max(0, pos-V);
    if(pos == 0){
        h_hp -= (mom_hp-1) / HP_M+1;        //M_damage = k = (mom_hp-1) / HP_M+1
        if(h_hp <= 0) return;
    }
    int &next_mom_hp = tbl[prev_t+1][h_hp][pos];
    if(next_mom_hp != -1 && next_mom_hp <= mom_hp)  //是否之前被计算过
        return;
    next_mom_hp = mom_hp;
    back[prev_t+1][h_hp][pos] = make_pair(make_pair(prev_hp,prev_pos),
                                          make_pair(magic,magic_param));
}

//int main(void){
//    cin >> N >> HP_H >> MP_H >> HP_M >> N_M >> V >> dH;
//    for(int i=0;i<N;i++)
//        cin >> damages[i];
//    memset(tbl, -1, sizeof(tbl));           //初始化，其余情况为-1
//    tbl[0][HP_H][N-1] = HP_M * N_M;         //回合数 怪兽最初位置 英雄血量 英雄 怪兽此时血量
//    int ans_turn = -1, ans_hp = 0, ans_pos = 0;
//    for(int t=0;t<MP_H; t++){
//        for(int hp = 1; hp <= HP_H; hp++){
//            for(int pos =0; pos<N;pos++){
//                if(tbl[t][hp][pos] == -1) continue;
//                int mom_hp = tbl[t][hp][pos];
//                if(mom_hp <= damages[pos]){
//                    // do_lightning
//                    ans_turn = t;
//                    ans_hp   = hp;
//                    ans_pos  = pos;
//                    break;
//                }
//                mom_turn(t, hp, pos, hp, pos, mom_hp-damages[pos], 'L', 0);
//                mom_turn(t, hp, pos, min(HP_H,hp+dH), pos, mom_hp, 'H', 0);
//                for(int i=0;i<N;i++)
//                    mom_turn(t, hp, pos, hp, i, mom_hp, 'T', i+1);
//            }
//            if(ans_turn != -1)
//                break;
//        }
//        if(ans_turn != -1)
//            break;
//    }
//    if(ans_turn == -1){
//        cout << "DEFEATED" << endl;
//    }else{
//        cout << "VICTORIOUS" << endl;
//        vector<pair<char,int> > v;
//        while(ans_turn != 0){
//            pair<pair<int,int>,pair<char,int> > info = back[ans_turn][ans_hp][ans_pos];
//            v.push_back(info.second);
//            ans_turn--;
//            ans_hp  = info.first.first;
//            ans_pos = info.first.second;
//        }
//        for(int i=(int)v.size()-1; i>=0;i--){
//            if(v[i].first == 'T')
//                cout << "T " << v[i].second << endl;
//            else 
//                cout << v[i].first << endl;
//        }
//        cout << "L" << endl;
//    }
//}
