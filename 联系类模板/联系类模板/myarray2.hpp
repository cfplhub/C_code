#pragma once
#include<iostream>
using namespace std;

template<class T>
class Myarray
{
	
public:

	Myarray(int capacity)
	{
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];

	}

	Myarray(const Myarray& arr)
	{
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}

	}

	Myarray& operator=(const Myarray &arr)
	{
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}

		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}

		return *this;
	}

	T& operator[]( int index)
	{
		return this->pAddress[index];
	}

	int getSize()
	{
		return this->m_Size;
	}

	int getcapacity()
	{
		return this->m_Capacity;
	}

	void PushBack(const T &val)
	{
		if (this->m_Capacity == this->m_Size)
		{
			return;
		}

		this->pAddress[this->m_Size] = val;


		this->m_Size++;
	}

	void PopBack()
	{
		if (this->m_Size==0)
		{
			return;
		}

		this->m_Size--;
	}

	~Myarray()
	{
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			pAddress = NULL;
		}
	}



private:
	int m_Size;
	int m_Capacity;
	T* pAddress;
};
