#include"orderFile.h"


orderFile::orderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;
	string interval;
	string stuId;
	string stuName;
	string roomId;
	string status;

	this->m_Size = 0;

	while (ifs>>date&&ifs>>interval&&ifs>>stuId&&
		ifs>>stuName&&ifs>>roomId&&ifs>>status)
	{
		
		//cout<< date <<endl;
		//cout<< interval <<endl;
		//cout<< stuId <<endl;
		//cout<< stuName <<endl;
		//cout<< roomId <<endl;
		//cout<< status <<endl;
		//cout << endl;

		string key;
		string val;
		map<string, string>m;

		int pos = date.find(":");
		if (pos != 1)
		{
			key = date.substr(0, pos);
			val = date.substr(pos + 1, date.size() - pos - 1);
			m.insert(make_pair(key, val));
		}
		
		pos = interval.find(":");
		if (pos != 1)
		{
			key = interval.substr(0, pos);
			val = interval.substr(pos + 1, interval.size() - pos - 1);
			m.insert(make_pair(key, val));
		}

		pos = stuId.find(":");
		if (pos != 1)
		{
			key = stuId.substr(0, pos);
			val = stuId.substr(pos + 1, stuId.size() - pos - 1);
			m.insert(make_pair(key, val));
		}

		pos = stuName.find(":");
		if (pos != 1)
		{
			key = stuName.substr(0, pos);
			val = stuName.substr(pos + 1, stuName.size() - pos - 1);
			m.insert(make_pair(key, val));
		}

		pos = roomId.find(":");
		if (pos != 1)
		{
			key = roomId.substr(0, pos);
			val = roomId.substr(pos + 1, roomId.size() - pos - 1);
			m.insert(make_pair(key, val));
		}

		pos = status.find(":");
		if (pos != 1)
		{
			key = status.substr(0, pos);
			val = status.substr(pos + 1, status.size() - pos - 1);
			m.insert(make_pair(key, val));
		}
		this->orderDate.insert(make_pair(this->m_Size, m));
		this->m_Size++;
	}
	ifs.close();

	//for (map<int, map<string, string>>::iterator it = orderDate.begin()
	//	; it != orderDate.end(); it++)
	//{
	//	cout << "ÌõÊýÎª£º" << it->first+1 << " val =" << endl;
	//	for (map<string, string>::iterator mit = (*it).second.begin();
	//		mit != it->second.end(); mit++)
	//	{
	//		cout << "key =" << mit->first << " val =" << mit->second << " ";
	//	}
	//	cout << endl;
	//}

	//system("pause");
	//system("cls");
	//return;
}

void orderFile::updateOrder()
{
	if (this->m_Size == 0)
	{
		return;
	}
	
	
	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	
	for (int i = 0; i < this->m_Size; i++)
	{
		//this->orderDate[i]["originalStatus"] = this->orderDate[i]["status"];
		//if (this->orderDate[i]["status"] != this->orderDate[i]["originalStatus"])
		
			ofs << "date:" << this->orderDate[i]["date"] << " ";
			ofs << "interval:" << this->orderDate[i]["interval"] << " ";
			ofs << "stuId:" << this->orderDate[i]["stuId"] << " ";
			ofs << "stuName:" << this->orderDate[i]["stuName"] << " ";
			ofs << "roomId:" << this->orderDate[i]["roomId"] << " ";
			ofs << "status:" << this->orderDate[i]["status"] << endl;
		
	}
	ofs.close();
}