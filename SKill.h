//
// Created by KAI on 2022/6/26.
//

#ifndef CPP_RPG_SKILL_H
#define CPP_RPG_SKILL_H

#endif //CPP_RPG_SKILL_H

#include <string>
using namespace std;
class Skill
{
private:
    string s;//技能名称
    int A, H;//技能伤害

public:
    void set(string x, int y, int z);//设置技能信息
    void printSkillInfo();//输出技能

    int geta();//查看技能伤害
    int geth();//查看技能消耗能量
    string getSkillName();//查看技能名称
};