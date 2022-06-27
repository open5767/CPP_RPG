//
// Created by KAI on 2022/6/26.
//

#include "Monster.h"
#include "string"
#include "iostream"

using namespace std;


void Monster::setmonster(int hp, int atk, int def, string name, string talk, int score)
{
    HP = hp;
    ATK = atk;
    DEF = def;
    NAME = name;
    TALK = talk;
    SCORE = score;
}

//���Ұ����Ϣ
void Monster::Print()
{
    cout << "���" << NAME << endl;
    cout << "Ѫ����" << HP << endl;
    cout << "��������" << ATK << endl;
    cout << "��������" << DEF << endl;
    cout << "��ɱ�ɵ÷�����" << SCORE << endl << endl;
    cout << TALK << endl;
}

//Ѫ������
void Monster::subHP(int x)
{
    HP -= x;
    if (HP<0)
        HP = 0;
}

//�鿴Ѫ��
int Monster::getHP()
{
    return HP;
}

//�鿴������
int Monster::getATK()
{
    return ATK;
}

//�鿴������
int Monster::getDEF()
{
    return DEF;
}

//�鿴����
int Monster::getScore()
{
    return SCORE;
}