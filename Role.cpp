//
// Created by KAI on 2022/6/26.
//

#include "Role.h"
#include "iostream"
#include "algorithm"
#include "cstdlib"
#include "iomanip"

using namespace std;
ifstream in;
ofstream out;

string str, s[6];
int a[6], b[6];

//构造函数
Role::Role(int hp, int rs, int atk, int def, string sex, string name, string profession)
{
    HP = hp;//角色血量
    RS = rs;//角色体力
    ATK = atk;//角色攻击力
    DEF = def;//角色防御力
    Sex = sex;//角色性别
    Name = name;//玩家姓名
    Profession = profession;//角色职业
    S = new Skill[6];
    in.open("D:\\CPP_RPG\\Skillname.txt");
    if (in)
    {
        int i = 0;
        while (getline(in, str))
        {
            s[i++] = str;
        }
    }
    in.close();

    in.open("D:\\CPP_RPG\\Skillnature.txt");
    if (in)
    {
        for (int j = 0; j < 6; j++)
            in >> a[j] >> b[j];
    }
    in.close();

    for (int i = 0; i < 6; i++)
        S[i].set(s[i], a[i], b[i]);
}

//设置信息
void Role::setData(int hp, int rs, int atk, int def, string sex, string name, string profession)
{
    HP = hp;//角色血量
    RS = rs;//角色体力
    ATK = atk;//角色攻击力
    DEF = def;//角色防御力
    Sex = sex;//角色性别
    Name = name;//玩家姓名
    Profession = profession;//角色职业
    S = new Skill[6];
    in.open("D:\\CPP_RPG\\Skillname.txt");
    if (in)
    {
        int i = 0;
        while (getline(in, str))
        {
            s[i++] = str;
        }
    }
    in.close();

    in.open("D:\\CPP_RPG\\Skillnature.txt");
    if (in)
    {
        for (int j = 0; j < 6; j++)
            in >> a[j] >> b[j];
    }
    in.close();

    for (int i = 0; i < 6; i++)
        S[i].set(s[i], a[i], b[i]);
}

Role::~Role()
{
    delete[] S;
}

//查看技能伤害
int Role::getSkillATK(int x)
{
    if (x == 6)
        return ATK;
    return S[x].geta();
}

//查看技能消耗能量
int Role::getSkillRS(int x)
{
    if (x == 6)
        return 0;
    return S[x].geth();
}

//查看技能名称
string Role::getSkillname(int x)
{
    return S[x].getSkillName();
}

//血量减少
void Role::hpsub(int x)
{
    HP -= x;
    if (HP<0)
        HP = 0;
}
//能量减少
void Role::rssub(int x)
{
    RS -= x;
    if (RS<0)
        RS = 0;
}

//分数增加
void Role::addScore(int x)
{
    Score += x;
}

//打印法师技能
void Role::printfm()
{
    int j = 4;
    cout << endl << "法师技能——" << endl;
    for (int i = 3; i<6; i++)
    {
        cout << j++ << ":" << endl;
        S[i].printSkillInfo();
    }
}

//打印剑客技能
void Role::printfw()
{
    int j = 1;
    cout << "剑客技能——" << endl;
    for (int i = 0; i<3; i++)
    {
        cout << j++ << ":";
        S[i].printSkillInfo();
    }
}

//获得技能属性
void Role::getSkill(int x)
{
    S[x].printSkillInfo();
}

//查看分数
int Role::getScore()
{
    return Score;
}

//查看性别
string Role::getSex()
{
    return Sex;
}

//查看姓名
string Role::getName()
{
    return Name;
}

//查看职业
string Role::getProfession()
{
    return Profession;
}

//查看血量
int Role::getHP()
{
    return HP;
}

//查看体力
int Role::getRS()
{
    return RS;
}

//查看攻击力
int Role::getATK()
{
    return ATK;
}

//查看防御力
int Role::getDEF()
{
    return DEF;
}

//修改技能攻击力
void Role::Skillchangeatk(int x,int y)
{
    a[x] = y;
    out.open("D:\\CPP_RPG\\Skillnature.txt");
    if (out)
    {
        for (int j = 0; j < 6; j++)
            out << a[j] << b[j];
    }
    out.close();
    cout << "恭喜你！修改成功！下局游戏才能生效哦！" << endl;
}

//修改技能能量
void Role::Skillchangers(int x, int y)
{
    b[x] = y;
    out.open("D:\\CPP_RPG\\Skillnature.txt");
    if (out)
    {
        for (int j = 0; j < 6; j++)
            out << a[j] << b[j];
    }
    out.close();
    cout << "恭喜你！修改成功！下局游戏才能生效哦！" << endl;
}

//修改技能名称
void Role::Skillchangename(int x, string y)
{
    s[x] = y;
    out.open("D:\\CPP_RPG\\Skillname.txt");
    if (out)
    {
        for (int i = 0; i < 6; i++)
            out << s[i] << endl;
    }
    out.close();
    cout << "恭喜你！修改成功！下局游戏才能生效哦！" << endl;
}