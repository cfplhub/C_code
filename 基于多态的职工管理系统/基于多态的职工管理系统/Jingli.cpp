#include"Jingli.h"

Jingli::Jingli(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DepId = dId;
}




void Jingli::showInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->getDepName()
		<< "\t��λְ������ϰ彻�������񣬲��·���Ա����" << endl;

}

string Jingli::getDepName()
{
	return string("����");

}