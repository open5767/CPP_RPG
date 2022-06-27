//
// Created by KAI on 2022/6/26.
//

#ifndef CPP_RPG_MONSTER_H
#define CPP_RPG_MONSTER_H

#endif //CPP_RPG_MONSTER_H

#include "iostream"

using namespace std;
class Monster
{
private:
    int HP, ATK, DEF;//血量、攻击力、防御力
    string NAME;//野怪
    string TALK;//台词
    int SCORE;//击杀野怪所得分数

public:
    void setmonster(int hp, int atk, int def, string name, string talk, int score);//设置野怪信息
    void Print();//输出野怪信息
    void subHP(int x);//血量减少

    int getHP();//查看血量
    int getATK();//查看攻击力
    int getDEF();//查看防御力
    int getScore();//查看分数
};