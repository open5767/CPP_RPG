#include <iostream>
#include "RPG.h"
#include "time.h"
#include "string"
#include "windows.h"

using namespace std;

int num = 6;//������
int isstart;//�Ƿ�ʼ��Ϸ
int skill_ischange;//�Ƿ��޸ļ���
int skill_att;//���ü�������
int skill_id;//ѡ�������
string sex, name, profession;
RPG my;

void Main_menu();//���˵�
void Role_set_menu();//���ý�ɫ

void Skill_set_menu();//�޸ļ�������
void Skill_choice_menu();//ѡ����

int main() {
    do {
        Main_menu();
        cin >> isstart;
        switch (isstart) {
            case 1://��ʼ��Ϸ
                system("cls");
                Role_set_menu();
                system("pause");
                break;
            case 2://���а�
                system("cls");
                my.Rank();
                system("pause");
                break;
            case 3://����
                system("cls");
                Skill_set_menu();
                system("pause");
                break;
            case 4://�˳���Ϸ
                return 0;
            default:
                break;
        }
    } while (isstart != 4);
    return 0;
}

//���˵�
void Main_menu()
{
    system("cls");
    cout << "==============================" << endl;
    cout << "       ���ߴ�½���ְ�" << endl;
    cout << "==============================" << endl;
    cout << "         1.��ʼ��Ϸ" << endl;
    cout << "         2.���а�" << endl;
    cout << "         3.����" << endl;
    cout << "         4.�˳���Ϸ" << endl;
    cout << "==============================" << endl;
    cout << "����������ѡ��" << endl;
}

//���ý�ɫ
void Role_set_menu()
{
    do
    {
        cout << "��ѡ���ɫ�Ա�F-Ů��M-��" << endl;
        cin >> sex;
    } while (sex != "F"&&sex != "M");
    cout << "�������ɫ������������Ӣ�ġ����ĺ����֣�" << endl;
    cin >> name;
    do
    {
        cout << "��ѡ���ɫְҵ��M-��ʦ��W-����" << endl;
        cin >> profession;
    } while (profession != "M"&&profession != "W");
    my.Set(100, 100, 20, 10, sex, name, profession);
    my.Gaming(profession);
}

//С�ʵ������޸ļ�������
void Skill_set_menu()
{
    do
    {
        system("cls");
        cout << "====================" << endl;
        cout << "       С�ʵ�" << endl;
        cout << "====================" << endl;
        cout << "     1.���ü���" << endl;
        cout << "     2.�˳�" << endl;
        cout << "====================" << endl;
        cout << "����������ѡ��" << endl;
        cin >> skill_ischange;
        if (skill_ischange == 1)
        {
            system("cls");
            Skill_choice_menu();
            system("pause");
        }
    } while (skill_ischange != 2);
}

//ѡ����
void Skill_choice_menu()
{
    do
    {
        system("cls");
        cout << "==============================" << endl;
        cout << "           ���ü���" << endl;
        cout << "==============================" << endl;
        cout << "       1.�鿴��������" << endl;
        cout << "       2.�޸ļ�������" << endl;
        cout << "       3.�˳�" << endl;
        cout << "==============================" << endl;
        cout << "����������ѡ��" << endl;
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
                cout <<  endl << endl << "���������ļ�����ţ�" << endl;
                cin >> skill_id;
                while (skill_id < 0 || skill_id > 6)
                {
                    cout << "���������룡" << endl;
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

 