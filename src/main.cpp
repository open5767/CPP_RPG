#include <iostream>
#include "RPG.h"
#include "time.h"
#include "string"
#include "windows.h"

using namespace std;

int num = 6;//技能数
int isstart;//是否开始游戏
int skill_ischange;//是否修改技能
int skill_att;//设置技能属性
int skill_id;//选择技能序号
string sex, name, profession;
RPG my;

void Main_menu();//主菜单
void Role_set_menu();//设置角色

void menu3();//嘿嘿嘿
void menu4();//设置技能

int main() {
    do {
        Main_menu();
        cin >> isstart;
        switch (isstart) {
            case 1://开始游戏
                system("cls");
                Role_set_menu();
                system("pause");
                break;
            case 2://排行榜
                system("cls");
                my.Rank();
                system("pause");
                break;
            case 3://设置
                system("cls");
                menu3();
                system("pause");
                break;
            case 4://退出游戏
                return 0;
            default:
                break;
        }
    } while (isstart != 4);
    return 0;
}

//主菜单
void Main_menu()
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
void Role_set_menu()
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
        cin >> skill_ischange;
        if (skill_ischange == 1)
        {
            system("cls");
            menu4();
            system("pause");
        }
    } while (skill_ischange != 2);
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
        cin >> skill_att;
        switch (skill_att)
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
                cin >> skill_id;
                while (skill_id < 0 || skill_id > 6)
                {
                    cout << "请重新输入！" << endl;
                    cin >> skill_id;
                }
                my.changeInfo(--skill_id);
                system("pause");
                break;
            default:
                break;
        }
    } while (skill_att != 3);
}

 