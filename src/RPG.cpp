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
    M[0].setmonster(60, 11, 11, "��С��", "��ã�", 10);
    M[1].setmonster(60, 11, 11, "СƤƤ", "���� ����", 10);
    M[2].setmonster(60, 11, 11, "������", "������Ҫ~~", 10);
    M[3].setmonster(70, 11, 11, "������ѻ", "��������", 20);
    M[4].setmonster(70, 11, 11, "��ë���", "�𣬺𣬺𣬺���", 20);
    M[5].setmonster(70, 11, 11, "С����", "������", 20);
    M[6].setmonster(80, 15, 15, "��Ƥ���", "��ɶ��", 30);
    M[7].setmonster(80, 16, 16, "���ϰ�������", "��Ҫҧ����", 30);
    M[8].setmonster(80, 17, 16, "�˯��", "����", 30);
    M[9].setmonster(100, 20, 16, "˹��è", "�ҷ����ҽ���", 50);
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
        cout << "     ������֣��Ƿ������" << endl;
        cout << "==============================" << endl;
        M[m].Print();
        cout << "==============================" << endl;
        cout << "����������ѡ��" << endl;
        cout << "1.����  2.����  3.�˳���Ϸ" << endl;
        cin >> choice2;
        if (choice2 == 1)
        {
            //ѡ��ʦ
            if (x == "M")
            {
                do
                {
                    system("cls");
                    cout << "��ѡ�񹥻���ʽ��" << endl;
                    cout << "1.��ͨ���� " << "  ";
                    cout << "2." << R.getSkillname(3) << "  ";
                    cout << "3." << R.getSkillname(4) << "  ";
                    cout << "4." << R.getSkillname(5) << "  "<<endl;
                    cout << "==============================" << endl;
                    cout << "Ұ��ʣ��Ѫ����" << M[m].getHP() << endl;
                    cout << "==============================" << endl;
                    cout << "��ɫʣ��Ѫ����" << R.getHP() << endl;
                    cout << "��ɫʣ��������" << R.getRS() << endl;
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
                cout << "Ұ���ѱ���ɱ��������� " << M[m].getScore() << " �֣�" << endl;
                system("pause");
            }
                //ѡ�񽣿�
            else
            {
                do
                {
                    system("cls");
                    cout << "��ѡ�񹥻���ʽ��" << endl;
                    cout << "1.��ͨ���� " << "  ";
                    cout << "2." << R.getSkillname(0) << "  ";
                    cout << "3." << R.getSkillname(1) << "  ";
                    cout << "4." << R.getSkillname(2) << "  " << endl;
                    cout << "==============================" << endl;
                    cout << "Ұ��ʣ��Ѫ����" << M[m].getHP() << endl;
                    cout << "==============================" << endl;
                    cout << "��ɫʣ��Ѫ����" << R.getHP() << endl;
                    cout << "��ɫʣ��������" << R.getRS() << endl;
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
                cout << "Ұ���ѱ���ɱ��������� " << M[m].getScore() << " �֣�" << endl;
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
        cout << "���ź������Ѿ�������" << endl;
        system("pause");
        system("cls");
        a = R.getScore();
        b = R.getName();
        Rank(b, a);
    }
}

//�޸ļ�������
void RPG::changeInfo(int x)
{
    R.getSkill(x);
    int choice5;
    string s1;
    cout << "==============================" << endl;
    cout << "          �޸�����" << endl;
    cout << "==============================" << endl;
    cout << "       1.��������" << endl;
    cout << "       2.���ܹ�����" << endl;
    cout << "       3.������������" << endl;
    cout << "       4.�����ӣ�������" << endl;
    cout << "==============================" << endl;
    cin >> choice5;
    if (choice5 == 1)
    {
        cout << "�����뼼�����ƣ�" << endl;
        cin >> s1;
        R.Skillchangename(x, s1);
    }
    else if (choice5 == 2)
    {
        cout << "�����뼼�ܹ�������" << endl;
        cin >> choice5;
        R.Skillchangeatk(x, choice5);
    }
    else if (choice5 == 3)
    {
        cout << "�����뼼������������" << endl;
        cin >> choice5;
        R.Skillchangers(x, choice5);
    }
    system("pause");
}

//��������б�
void RPG::printSkill()
{
    R.printfw();
    R.printfm();
}

//�����������
void RPG::printSkillInfo(int x)
{
    R.getSkill(x);
}

//��Ϸ������
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
    cout << "         ������ҵ�����" << endl;
    cout << "******************************" << endl;
    cout << "����" << setw(12) << "���" << setw(14) << "�÷�" << endl;
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

//���˵�������
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
    cout << "         ������ҵ�����" << endl;
    cout << "******************************" << endl;
    cout << "����" << setw(12) << "���" << setw(14) << "�÷�" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << " " << i + 1 << setw(14) << p[i].n << setw(14) << p[i].s << endl;
    }
}

//С��ʿ
void RPG::tip()
{
    string tip[5] = { "�����Ѫ����������Ϊ0ʱ�������ж���ɫ�����ޣ�",
                      "ע�����ʹ�ü��ܣ���߷�����",
                      "��������С�ʵ��ޣ�",
                      "�����ӣ����ڼ�����..." ,
                      "��������ʱ�����ڹ�����Ұ�ֻ��������Ӵ��"};
    system("cls");
    srand((unsigned)time(0));
    int l = rand() % 4;
    cout << "Tip��" << tip[l] << endl << endl;;
    system("pause");
    system("cls");
}
