#include"Jingli.h"

Jingli::Jingli(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DepId = dId;
}




void Jingli::showInfo()
{
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << this->getDepName()
		<< "\t岗位职责：完成老板交给的任务，并下发给员工。" << endl;

}

string Jingli::getDepName()
{
	return string("经理");

}