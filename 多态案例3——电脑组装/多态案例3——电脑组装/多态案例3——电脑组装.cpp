#include<iostream>
using namespace std;
//����ͬ�����
//����cpu
class CPU
{
public:
	//����ļ��㺯��
	virtual void calculate() = 0;
};
//�����Կ���
class VideoCard
{
public:
	//�������ʾ����
	virtual void display() = 0;
};
//�����ڴ�����
class Memory
{
public:
	//����Ĵ洢����
	virtual void storage() = 0;
};
//������
class Computer
{
public:
	Computer(CPU* cpu, VideoCard* vc, Memory* mem)
	{
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}
	//�ṩһ�������ĺ���
	void work()
	{
		//����������������������Ľӿ�
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}
	//�ṩ���������ͷ�3���������
	~Computer()
	{
		//�ͷ�CPU���
		if (m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}
		//�ͷ��Կ����
		if (m_vc != NULL)
		{
			delete m_vc;
			m_vc = NULL;
		}
		//�ͷ��ڴ������ָ��
		if (m_mem != NULL)
		{
			delete m_mem;
			m_mem = NULL;
		}
	}
private:
	CPU* m_cpu;//CPU���ָ��
	VideoCard* m_vc;//�Կ����ָ��
	Memory* m_mem;//�ڴ������ָ��
};
//����ĳ���
//Intel
class IntelCPU :public CPU
{
public:
	virtual	 void calculate()
	{
		cout << "Intel��CPU��ʼ������" << endl;
	}
};
class IntelVideoCard :public VideoCard
{
public:
	virtual	 void display()
	{
		cout << "Intel���Կ���ʼ��ʾ��" << endl;
	}
};
class IntelMemory :public Memory
{
public:
	virtual	 void storage()
	{
		cout << "Intel���ڴ�����ʼ�洢��" << endl;
	}
};
//����ĳ���
//Lenovo
class LenovoCPU :public CPU
{
public:
	virtual	 void calculate()
	{
		cout << "Lenovo��CPU��ʼ������" << endl;
	}
};
class LenovoVideoCard :public VideoCard
{
public:
	virtual	 void display()
	{
		cout << "Lenovo���Կ���ʼ��ʾ��" << endl;
	}
};
class LenovoMemory :public Memory
{
public:
	virtual	 void storage()
	{
		cout << "Lenovo���ڴ�����ʼ�洢��" << endl;
	}
};
//��װ����
void test01()
{
	//һ̨�������
	CPU* intelcpu = new IntelCPU;
	VideoCard* videocard = new IntelVideoCard;
	Memory* memory = new IntelMemory;
	//������һ̨����
	Computer* computer1 = new Computer(intelcpu, videocard, memory);
	computer1->work();
	delete computer1;
	cout << "-----------------" << endl;
	//��װ�ڶ�̨����
	Computer* computer2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);
	computer2->work();
	delete computer2;
	cout << "-----------------" << endl;
	//��װ����̨����
	Computer* computer3 = new Computer(new LenovoCPU, new IntelVideoCard, new LenovoMemory);
	computer3->work();
	delete computer3;
}
int main(void)
{
	test01();
	system("pause");
	return 0;
}

