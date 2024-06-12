#pragma once
#include<iostream>
using namespace std;
template<class T>
class Myarray
{
public:

	Myarray() {};
	Myarray(int capacity)
	{
		this->m_capacity = capacity;
		this->m_size = 0;
		this->pAddress = new T[this->m_capacity];
	}

	Myarray(const Myarray& arr)
	{
		//if (this->pAddress != NULL)
		//{

		//	delete[] this->pAddress;
		//	this->m_size = 0;
		//	this->m_capacity = 0;
		//	this->pAddress = NULL;
		//}

		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;
		this->pAddress = new T[arr.m_capacity];
		for (int i = 0; i < this->m_size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	Myarray& operator=(const Myarray& arr)
	{
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_size = 0;
			this->m_capacity = 0;
		}

		this->m_size = arr.m_size;
		this->m_capacity = arr.m_capacity;
		this->pAddress = new T[arr.m_capacity];
		for (int i = 0; i < this->m_size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}

	void pushback(const T& val)
	{
		if (this->m_size == this->m_capacity)
		{
			if (this->m_size == this->m_capacity)
			{
				// �������������Կ�����չ���������
				// �����Ҽ�ʾ����һ�����ݲ��ԣ�����Ը�����Ҫ���е���
				int newCapacity = this->m_capacity * 2; // ����Ϊԭ��������
				T* newAddress = new T[newCapacity]; // ����������

				// ��ԭ�����е�Ԫ�ظ��Ƶ���������
				for (int i = 0; i < this->m_size; i++)
				{
					newAddress[i] = this->pAddress[i];
				}

				delete[] this->pAddress; // �ͷ�ԭ������ڴ�
				this->pAddress = newAddress; // ����ָ��
				this->m_capacity = newCapacity; // ��������
			}
		}
		this->pAddress[this->m_size] = val;
		this->m_size++;
	}

	void popback(const T& val)
	{
		if (this->m_size == 0)
		{
			return;
		}

		this->m_size--;
	}

	T& operator[](int dex)
	{
		return this->pAddress[dex];
	}

	int getsize()
	{
		return this->m_size;
	}


	int getcapacity()
	{
		return this->m_capacity;
	}




	~Myarray()
	{
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->m_size = 0;
			this->m_capacity = 0;
			this->pAddress = NULL;
		}
	}

	
private:
	T* pAddress;
	int m_size;
	int m_capacity;

};