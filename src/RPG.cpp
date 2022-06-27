//
// Created by KAI on 2022/6/26.
//

#include "RPG.h"
#include "ctime"
#include "iostream"
#include "cstdlib"

int a;
string b;
using namespace std;

ifstream in1;
fstream out1;

struct player
{
    string n;
    int s;
}p[4];

bool cmp(struct player x, struct player y)
{
    return x.s > y.s;
}

void RPG::Set(int hp, int rs, int atk, int def, string sex, string name, string profession)
{
    R.setData(hp, rs, atk, def, sex, name, profession);
}

void RPG::Gaming(string x)
{
    Monster M[10];
    M[0].setmonster(60, 11, 11, "猪小怪", "你好！", 10);
    M[1].setmonster(60, 11, 11, "小皮皮", "（— —）", 10);
    M[2].setmonster(60, 11, 11, "捣蛋猪", "啊，不要~~", 10);
    M[3].setmonster(70, 11, 11, "大嘴乌鸦", "啊！啊！", 20);
    M[4].setmonster(70, 11, 11, "多毛吼猴", "吼，吼，吼，吼吼吼！", 20);
    M[5].setmonster(70, 11, 11, "小跳鼠", "嘤嘤嘤", 20);
    M[6].setmonster(80, 15, 15, "调皮疙瘩", "看啥看", 30);
    M[7].setmonster(80, 16, 16, "金氏斑纹拟蜥", "我要咬西你", 30);
    M[8].setmonster(80, 17, 16, "瞌睡虫", "呼呼", 30);
    M[9].setmonster(100, 20, 16, "斯菲猫", "我肥胖我骄傲", 50);
    system("cls");
    if (x == "M")
        R.printfm();
    else
        R.printfw();
    system("pause");
    tip();
    do
    {
        begin:srand((unsigned)time(0));
        int m, choice3, choice2;
        b:m = rand() % 10;
        if (M[m].getHP() == 0)
            goto b;
        system("cls");
        cout << "==============================" << endl;
        cout << "     怪物出现！是否击倒？" << endl;
        cout << "==============================" << endl;
        M[m].Print();
        cout << "==============================" << endl;
        cout << "请输入您的选择：" << endl;
        cout << "1.攻击  2.逃跑  3.退出游戏" << endl;
        cin >> choice2;
        if (choice2 == 1)
        {
            //选择法师
            if (x == "M")
            {
                do
                {
                    system("cls");
                    cout << "请选择攻击方式：" << endl;
                    cout << "1.普通攻击 " << "  ";
                    cout << "2." << R.getSkillname(3) << "  ";
                    cout << "3." << R.getSkillname(4) << "  ";
                    cout << "4." << R.getSkillname(5) << "  "<<endl;
                    cout << "==============================" << endl;
                    cout << "野怪剩余血量：" << M[m].getHP() << endl;
                    cout << "==============================" << endl;
                    cout << "角色剩余血量：" << R.getHP() << endl;
                    cout << "角色剩余能量：" << R.getRS() << endl;
                    cout << "==============================" << endl;
                    cin >> choice3;
                    if (choice3 == 1)
                    {
                        M[m].subHP(R.getSkillATK(6) - M[m].getDEF());
                        R.hpsub(M[m].getATK() - R.getDEF());
                        R.rssub(R.getSkillRS(6));
                    }
                    else
                    {
                        M[m].subHP(R.getSkillATK(++choice3) - M[m].getDEF());
                        R.hpsub(M[m].getATK() - R.getDEF());
                        R.rssub(R.getSkillRS(choice3));
                    }
                } while (M[m].getHP() > 0 && R.getHP() > 0);
                R.addScore(M[m].getScore());
                cout << "野怪已被击杀！您获得了 " << M[m].getScore() << " 分！" << endl;
                system("pause");
            }
                //选择剑客
            else
            {
                do
                {
                    system("cls");
                    cout << "请选择攻击方式：" << endl;
                    cout << "1.普通攻击 " << "  ";
                    cout << "2." << R.getSkillname(0) << "  ";
                    cout << "3." << R.getSkillname(1) << "  ";
                    cout << "4." << R.getSkillname(2) << "  " << endl;
                    cout << "==============================" << endl;
                    cout << "野怪剩余血量：" << M[m].getHP() << endl;
                    cout << "==============================" << endl;
                    cout << "角色剩余血量：" << R.getHP() << endl;
                    cout << "角色剩余能量：" << R.getRS() << endl;
                    cout << "==============================" << endl;
                    cin >> choice3;
                    if (choice3 == 1)
                    {
                        M[m].subHP(R.getSkillATK(6) - M[m].getDEF());
                        R.hpsub(M[m].getATK() - R.getDEF());
                        R.rssub(R.getSkillRS(6));
                    }
                    else
                    {
                        M[m].subHP(R.getSkillATK(choice3 - 2) - M[m].getDEF());
                        R.hpsub(M[m].getATK() - R.getDEF());
                        R.rssub(R.getSkillRS(choice3 - 2));
                    }
                } while (M[m].getHP() > 0 && R.getHP() > 0);
                R.addScore(M[m].getScore());
                cout << "野怪已被击杀！您获得了 " << M[m].getScore() << " 分！" << endl;
                system("pause");
            }
        }
        else if (choice2 == 2)
            goto begin;
        else
        {
            system("cls");
            a = R.getScore();
            b = R.getName();
            Rank(b,a);
            break;
        }
    } while (R.getHP() != 0 && R.getRS() != 0);
    if (R.getHP() == 0 || R.getRS() == 0)
    {
        cout << "很遗憾！您已经死亡！" << endl;
        system("pause");
        system("cls");
        a = R.getScore();
        b = R.getName();
        Rank(b, a);
    }
}

//修改技能属性
void RPG::changeInfo(int x)
{
    R.getSkill(x);
    int choice5;
    string s1;
    cout << "==============================" << endl;
    cout << "          修改属性" << endl;
    cout << "==============================" << endl;
    cout << "       1.技能名称" << endl;
    cout << "       2.技能攻击力" << endl;
    cout << "       3.技能消耗能量" << endl;
    cout << "       4.嘤嘤嘤，不改了" << endl;
    cout << "==============================" << endl;
    cin >> choice5;
    if (choice5 == 1)
    {
        cout << "请输入技能名称：" << endl;
        cin >> s1;
        R.Skillchangename(x, s1);
    }
    else if (choice5 == 2)
    {
        cout << "请输入技能攻击力：" << endl;
        cin >> choice5;
        R.Skillchangeatk(x, choice5);
    }
    else if (choice5 == 3)
    {
        cout << "请输入技能消耗能量：" << endl;
        cin >> choice5;
        R.Skillchangers(x, choice5);
    }
    system("pause");
}

//输出技能列表
void RPG::printSkill()
{
    R.printfw();
    R.printfm();
}

//输出技能属性
void RPG::printSkillInfo(int x)
{
    R.getSkill(x);
}

//游戏中排名
void RPG::Rank(string x, int y)
{
    string str;
    in1.open("Rankname.txt");
    if (in1)
    {
        int i = 0;
        while (getline(in1, str)&&i<4)
        {
            p[i++].n = str;
        }
    }
    in1.close();

    int j = 0;
    in1.open("Rankscore.txt");
    if (in1&&j<4)
    {
        in1 >> p[j++].s;
    }
    in1.close();

    p[3].s = y;
    p[3].n = x;
    sort(p, p + 4, cmp);
    cout << "******************************" << endl;
    cout << "         看看大家的名次" << endl;
    cout << "******************************" << endl;
    cout << "名次" << setw(12) << "玩家" << setw(14) << "得分" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << " " << i + 1 << setw(14) << p[i].n << setw(14) << p[i].s << endl;
    }
    out1.open("Rankname.txt");
    int k = 0;
    if (out1)
    {
        while (k < 4)
        {
            out1 << p[k++].n << endl;
        }
    }
    out1.close();

    out1.open("Rankscore.txt");
    int f = 0;
    if (out1&&f<4)
    {
        out1 << p[f++].s << " ";
    }
    out1.close();
    system("pause");
}

//主菜单中排名
void RPG::Rank()
{
    string str;
    in1.open("Rankname.txt");
    if (in1)
    {
        int i = 0;
        while (getline(in1, str)&&i<4)
        {
            p[i++].n = str;
        }
    }
    in1.close();

    int j = 0;
    in1.open("Rankscore.txt");
    if (in1&&j<4)
    {
        in1 >> p[j++].s;
    }
    in1.close();

    cout << "******************************" << endl;
    cout << "         看看大家的名次" << endl;
    cout << "******************************" << endl;
    cout << "名次" << setw(12) << "玩家" << setw(14) << "得分" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << " " << i + 1 << setw(14) << p[i].n << setw(14) << p[i].s << endl;
    }
}

//小贴士
void RPG::tip()
{
    string tip[5] = { "当你的血量或能量变为0时，将会判定角色死亡噢！",
                      "注意合理使用技能，提高分数！",
                      "设置里有小彩蛋噢！",
                      "嘤嘤嘤，正在加载中..." ,
                      "当您死亡时，正在攻击的野怪会给您陪葬哟！"};
    system("cls");
    srand((unsigned)time(0));
    int l = rand() % 4;
    cout << "Tip：" << tip[l] << endl << endl;;
    system("pause");
    system("cls");
}
