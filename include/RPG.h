//
// Created by KAI on 2022/6/26.
//

#ifndef CPP_RPG_RPG_H
#define CPP_RPG_RPG_H

#endif //CPP_RPG_RPG_H

#include "Role.h"
#include "Monster.h"
#include "iostream"
#include "algorithm"
#include "string"
#include "fstream"
#include "iomanip"
#include "windows.h"

using namespace std;

class RPG {
private:
    Role R;
    Monster M[10];

public:
    void Set(int hp, int rs, int atk, int def, string sex, string name, string profession);

    void Gaming(string x);//开始游戏
    void printSkill();//查看技能列表
    void changeInfo(int x);//修改技能信息
    void printSkillInfo(int x);//输出技能信息
    void Rank(string x, int y);//游戏中排名
    void Rank();//主菜单排名
    void tip();//小贴士
};