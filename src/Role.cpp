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

//���캯��
Role::Role(int hp, int rs, int atk, int def, string sex, string name, string profession)
{
    HP = hp;//��ɫѪ��
    RS = rs;//��ɫ����
    ATK = atk;//��ɫ������
    DEF = def;//��ɫ������
    Sex = sex;//��ɫ�Ա�
    Name = name;//�������
    Profession = profession;//��ɫְҵ
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

//������Ϣ
void Role::setData(int hp, int rs, int atk, int def, string sex, string name, string profession)
{
    HP = hp;//��ɫѪ��
    RS = rs;//��ɫ����
    ATK = atk;//��ɫ������
    DEF = def;//��ɫ������
    Sex = sex;//��ɫ�Ա�
    Name = name;//�������
    Profession = profession;//��ɫְҵ
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

//�鿴�����˺�
int Role::getSkillATK(int x)
{
    if (x == 6)
        return ATK;
    return S[x].geta();
}

//�鿴������������
int Role::getSkillRS(int x)
{
    if (x == 6)
        return 0;
    return S[x].geth();
}

//�鿴��������
string Role::getSkillname(int x)
{
    return S[x].getSkillName();
}

//Ѫ������
void Role::hpsub(int x)
{
    HP -= x;
    if (HP<0)
        HP = 0;
}
//��������
void Role::rssub(int x)
{
    RS -= x;
    if (RS<0)
        RS = 0;
}

//��������
void Role::addScore(int x)
{
    Score += x;
}

//��ӡ��ʦ����
void Role::printfm()
{
    int j = 4;
    cout << endl << "��ʦ���ܡ���" << endl;
    for (int i = 3; i<6; i++)
    {
        cout << j++ << ":" << endl;
        S[i].printSkillInfo();
    }
}

//��ӡ���ͼ���
void Role::printfw()
{
    int j = 1;
    cout << "���ͼ��ܡ���" << endl;
    for (int i = 0; i<3; i++)
    {
        cout << j++ << ":";
        S[i].printSkillInfo();
    }
}

//��ü�������
void Role::getSkill(int x)
{
    S[x].printSkillInfo();
}

//�鿴����
int Role::getScore()
{
    return Score;
}

//�鿴�Ա�
string Role::getSex()
{
    return Sex;
}

//�鿴����
string Role::getName()
{
    return Name;
}

//�鿴ְҵ
string Role::getProfession()
{
    return Profession;
}

//�鿴Ѫ��
int Role::getHP()
{
    return HP;
}

//�鿴����
int Role::getRS()
{
    return RS;
}

//�鿴������
int Role::getATK()
{
    return ATK;
}

//�鿴������
int Role::getDEF()
{
    return DEF;
}

//�޸ļ��ܹ�����
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
    cout << "��ϲ�㣡�޸ĳɹ����¾���Ϸ������ЧŶ��" << endl;
}

//�޸ļ�������
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
    cout << "��ϲ�㣡�޸ĳɹ����¾���Ϸ������ЧŶ��" << endl;
}

//�޸ļ�������
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
    cout << "��ϲ�㣡�޸ĳɹ����¾���Ϸ������ЧŶ��" << endl;
}