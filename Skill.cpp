//
// Created by KAI on 2022/6/26.
//

#include "Role.h"
#include "Monster.h"
#include "SKill.h"
#include "iostream"
using namespace std;

//设置数据
void Skill::set(string x, int y, int z)
{
    s = x;
    A = y;
    H = z;
}

//查看技能名称
string Skill::getSkillName()
{
    return s;
}


//查看技能伤害
int Skill::geta()
{
    return A;
}

//查看技能消耗能量
int Skill::geth()
{
    return H;
}

//输出技能
void Skill::printSkillInfo()
{
    cout << "技能名称：  " << s << endl;
    cout << "攻击力：    " << A << endl;
    cout << "消耗能量：  " << H << endl;
}
