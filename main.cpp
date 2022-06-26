#include <iostream>
#include "RPG.h"
#include "time.h"
#include "string"
#include "windows.h"
#pragma once;
using namespace std;

int num = 6;//技能
int option1;//是否开始游戏
int option2;//是否修改技能
int option3;//设置技能属性
int option4;//选择技能序号
string sex;
string name;
string profession;
RPG my;

void menu1();//主菜单
void menu2();//设置角色

void menu3();//嘿嘿嘿
void menu4();//设置技能

int main() {
    do {
        menu1();
        cin >> option1;
        switch (option1) {
            case 1:
                system("cls");
                menu2();
                system("pause");
                break;
            case 2:
                system("cls");
                my.Rank();
                system("pause");
                break;
            case 3:
                system("cls");
                menu3();
                system("pause");
                break;
            case 4:
                return 0;
            default:
                break;
        }
    } while (option1 != 4);
    return 0;
}

//主菜单
void menu1()
{
    system("cls");
    cout << "==============================" << endl;
    cout << "     奇幻冒险文字版RPG游戏" << endl;
    cout << "==============================" << endl;
    cout << "         1.开始游戏" << endl;
    cout << "         2.排行榜" << endl;
    cout << "         3.设置" << endl;
    cout << "         4.退出游戏" << endl;
    cout << "==============================" << endl;
    cout << "请输入您的选择：" << endl;
}

//设置角色
void menu2()
{
    do
    {
        cout << "请选择角色性别：F-女，M-男" << endl;
        cin >> sex;
    } while (sex != "F"&&sex != "M");
    cout << "请输入角色姓名：（仅限英文、中文和数字）" << endl;
    cin >> name;
    do
    {
        cout << "请选择角色职业：M-法师，W-剑客" << endl;
        cin >> profession;
    } while (profession != "M"&&profession != "W");
    my.Set(100, 100, 20, 10, sex, name, profession);
    my.Gaming(profession);
}

//小彩蛋——修改属性
void menu3()
{
    do
    {
        system("cls");
        cout << "====================" << endl;
        cout << "       小彩蛋" << endl;
        cout << "====================" << endl;
        cout << "     1.设置技能" << endl;
        cout << "     2.退出" << endl;
        cout << "====================" << endl;
        cout << "请输入您的选择：" << endl;
        cin >> option2;
        if (option2 == 1)
        {
            system("cls");
            menu4();
            system("pause");
        }
    } while (option2 != 2);
}

//修改技能属性
void menu4()
{
    do
    {
        system("cls");
        cout << "==============================" << endl;
        cout << "           设置技能" << endl;
        cout << "==============================" << endl;
        cout << "       1.查看技能属性" << endl;
        cout << "       2.修改技能属性" << endl;
        cout << "       3.退出" << endl;
        cout << "==============================" << endl;
        cout << "请输入您的选择：" << endl;
        cin >> option3;
        switch (option3)
        {
            case 1:
                system("cls");
                my.printSkill();
                system("pause");
                break;
            case 2:
                system("cls");
                my.printSkill();
                cout <<  endl << endl << "请输入所改技能序号：" << endl;
                cin >> option4;
                while (option4 < 0 || option4 > 6)
                {
                    cout << "请重新输入！" << endl;
                    cin >> option4;
                }
                my.changeInfo(--option4);
                system("pause");
                break;
            default:
                break;
        }
    } while (option3 != 3);
}
