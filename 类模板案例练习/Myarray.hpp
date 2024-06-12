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
				// 数组已满，可以考虑扩展数组的容量
				// 这里我简单示范了一种扩容策略，你可以根据需要进行调整
				int newCapacity = this->m_capacity * 2; // 扩容为原来的两倍
				T* newAddress = new T[newCapacity]; // 创建新数组

				// 将原数组中的元素复制到新数组中
				for (int i = 0; i < this->m_size; i++)
				{
					newAddress[i] = this->pAddress[i];
				}

				delete[] this->pAddress; // 释放原数组的内存
				this->pAddress = newAddress; // 更新指针
				this->m_capacity = newCapacity; // 更新容量
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