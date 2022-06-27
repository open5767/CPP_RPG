//
// Created by KAI on 2022/6/26.
//

#ifndef CPP_RPG_ROLE_H
#define CPP_RPG_ROLE_H

#endif //CPP_RPG_ROLE_H

#include "SKill.h"
#include "fstream"
#include "string"
#include "cstdlib"

using namespace std;

class Role
{
private:
    int HP;//角色血量
    int RS;//角色体力
    int ATK;//角色攻击力
    int DEF;//角色防御力
    int Score;//角色得分
    string Sex;//角色性别
    string Name;//玩家姓名
    string Profession;//角色职业
    Skill *S;//技能

public:
    string getSex();//查看性别
    string getName();//查看姓名
    string getProfession();//查看职业
    int getHP();//查看血量
    int getRS();//查看体力
    int getATK();//查看攻击力
    int getDEF();//查看防御力
    int getScore();//查看分数
    string getSkillname(int x);
    int getSkillATK(int x);//查看技能伤害
    int getSkillRS(int x);//查看技能消耗能量

    explicit Role(int hp = 100, int rs = 100, int atk = 20, int def = 10, string sex = "0", string name = "0", string profession = "0");
    ~Role();
    void setData(int hp, int rs, int atk, int def, string sex, string name, string profession);//设置信息
    void hpsub(int x); //血量减少
    void rssub(int x); //能量减少
    void addScore(int x);//分数增加
    void printfm();//输出法师技能
    void printfw();//输出剑客技能
    void getSkill(int x);
    void Skillchangename(int x,string y);
    void Skillchangeatk(int x,int y);
    void Skillchangers(int x,int y);
};