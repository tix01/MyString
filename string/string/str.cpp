#include "str.h"

str::str() :size(0), arr(nullptr) {};


str::str(char arr[], int size)
{
	this->size = size;
	this->arr = new char[size];
	for (int i = 0; i < size; i++)
	{
		this->arr[i] = arr[i];
	}
}

str::str(const str& other)
{
	this->size = other.size;
	this->arr = new char[other.size];
	for (int i = 0; i < other.size; i++)
	{
		this->arr[i] = other.arr[i];
	}
}

void str::SetString(int r)
{
	this->size = r + 1;
	if (arr != nullptr)
	{
		delete[]arr;
	}
	this->arr = new char[this->size];
	for (int i = 0; i < r; i++)
	{
		cin >> arr[i];
	}
	arr[r] = '\0';
}

void str::GetString()
{
	if (arr != nullptr)
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i];
		}
		cout << endl;
	}

}

void str::insertend(char arr[], int size)
{
	int value, j = 0;
	char* mas = new char[this->size];
	for (int i = 0; i < this->size; i++)
	{
		if (this->arr[i] != '\0')
		{
			mas[i] = this->arr[i];
		}
	}
	delete[]this->arr;
	value = this->size + size + 1;
	this->arr = new char[value];
	for (int i = 0; i < this->size; i++)
	{
		this->arr[i] = mas[i];
	}
	delete[]mas;
	for (int i = this->size - 1; i < value - 1; i++)
	{
		this->arr[i] = arr[j];
		j++;
	}
	this->size = value;
	this->arr[this->size - 1] = '\0';
}

void str::insertstart(char arr[], int size)
{
	int value, j = 0;
	char* mass = new char[this->size];
	for (int i = 0; i < this->size; i++)
	{
		if (this->arr[i] != '\0')
		{
			mass[i] = this->arr[i];
		}
	}
	delete[] this->arr;
	value = this->size + size-1;
	this->arr = new char[value];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] != '\0')
		{
			this->arr[i] = arr[i];
		}
	}
	for (int i = size-1; i < value - 1; i++)
	{
		this->arr[i] = mass[j];
		j++;
	}
	delete[] mass;
	this->size = value;
	this->arr[this->size - 1] = '\0';
}

void str::remuveat(int value)
{
	if (value < this->size)
	{
		int sizemas = value + 1;
		char* mas = new char[sizemas];
		for (int i = 0; i < value; i++)
		{
			mas[i] = this->arr[i];
		}
		delete[] this->arr;
		this->size = sizemas;
		this->arr = new char[this->size];
		for (int i = 0; i < value; i++)
		{
			if (mas[i] != '\0')
			{
				this->arr[i] = mas[i];
			}
		}
		delete[] mas;
		this->arr[value] = '\0';
	}
}

void str::remuveat(int start, int end)
{
	if (end < this->size)
	{
		int value, j = 0;
		value = (this->size) - 1 - (end - start);
		char* mass = new char[value];
		for (int i = 0; i < this->size; i++)
		{
			if (i < start || i > end)
			{
				mass[j] = this->arr[i];
				j++;
			}
		}
		delete[] this->arr;
		this->size = value + 1;
		this->arr = new char[this->size];
		for (int i = 0; i < value; i++)
		{
			this->arr[i] = mass[i];
		}
		delete[] mass;
		this->arr[value] = '\0';
	}
}

void str::Substring(int start, int end)
{
	if (end > this->size)
	{
		end = this->size - 1;
	}
	int value, j = 0;
	value = end - start + 2;
	char* mas = new char[value];
	for (int i = 0; i < this->size; i++)
	{
		if (i >= start && i <= end && arr[i] != '\0')
		{
			mas[j] = this->arr[i];
			j++;
		}
	}
	mas[value - 1] = '\0';
	delete[]this->arr;
	this->size = value;
	this->arr = new char[this->size];
	for (int i = 0; i < value; i++)
	{
		this->arr[i] = mas[i];
	}
	delete[]mas;

}

void str::deletespace()
{
	int value = 0, j = 0, a = 0, b = 0, z, m;
	m = (this->size - b - 1);

	for (int i = 0; i < this->size; i++)
	{
		if (this->arr[i] == 32)
		{
			if (this->arr[i - 1] > 32)
			{
				break;
			}
			value++;
			a++;
		}
	}
	for (int i = this->size - 1; i >= 0; i--)
	{
		if (this->arr[i] == 32)
		{
			if (this->arr[i + 1] > 32)
			{
				break;
			}
			value++;
			b++;
		}
	}
	z = this->size - value;
	char* mass = new char[z];

	for (int i = 0; i < this->size; i++)
	{
		if (i >= a)
		{
			mass[j] = this->arr[i];
			j++;
			if (j == z - 1)
			{
				break;
			}
		}
	}
	delete[]this->arr;
	this->size = z;
	this->arr = new char[this->size];
	for (int i = 0; i < z - 1; i++)
	{
		this->arr[i] = mass[i];
	}
	this->arr[z - 1] = '\0';
}

str str::operator+(const str& other)
{
	int j = 0, value;
	value = this->size + other.size - 1;
	char* mass = new char[value];
	for (int i = 0; i < this->size; i++)
	{
		if (this->arr[i] != '\0')
		{
			mass[i] = this->arr[i];
		}
	}
	for (int i = this->size - 1; i < value; i++)
	{
		mass[i] = other.arr[j];
		j++;
	}
	str temp(mass, value);
	return temp;
}

str& str::operator=(const str& other)
{
	this->size = other.size;
	delete[] this->arr;
	this->arr = new char[this->size];
	for (int i = 0; i < other.size; i++)
	{
		this->arr[i] = other.arr[i];
	}
	return *this;
}

str::~str()
{
	delete[] arr;
}

ostream& operator<<(ostream& os, const str& other)
{
	for (int i = 0; i < other.size; i++)
	{
		os << other.arr[i];
	}
	return os;
}
istream& operator>>(istream& is, str& other)
{
	int i = 0;
	other.arr = new char[256];
	is >> other.arr;
	while (other.arr[i] != '\0')
	{
		i++;
	}
	other.size = i + 1;
	return is;
}