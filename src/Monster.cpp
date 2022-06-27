//
// Created by KAI on 2022/6/26.
//

#include "Monster.h"
#include "string"
#include "iostream"

using namespace std;


void Monster::setmonster(int hp, int atk, int def, string name, string talk, int score)
{
    HP = hp;
    ATK = atk;
    DEF = def;
    NAME = name;
    TALK = talk;
    SCORE = score;
}

//输出野怪信息
void Monster::Print()
{
    cout << "怪物：" << NAME << endl;
    cout << "血量：" << HP << endl;
    cout << "攻击力：" << ATK << endl;
    cout << "防御力：" << DEF << endl;
    cout << "击杀可得分数：" << SCORE << endl << endl;
    cout << TALK << endl;
}

//血量减少
void Monster::subHP(int x)
{
    HP -= x;
    if (HP<0)
        HP = 0;
}

//查看血量
int Monster::getHP()
{
    return HP;
}

//查看攻击力
int Monster::getATK()
{
    return ATK;
}

//查看防御力
int Monster::getDEF()
{
    return DEF;
}

//查看分数
int Monster::getScore()
{
    return SCORE;
}