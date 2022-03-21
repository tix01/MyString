#pragma once
#include <iostream>

using namespace std;
class str
{
	int size;
	char* arr;
public:
	str();
	str(char arr[], int size);
	str(const str& other);
	void SetString(int r);
	void GetString();
	void insertend(char arr[], int size);
	void insertstart(char arr[], int size);
	void remuveat(int value);
	void remuveat(int start, int end);
	void Substring(int start, int end);
	void deletespace();
	str operator+(const str& other);
	str& operator=(const str& other);
	~str();
	friend ostream& operator<<(ostream& os, const str& other);
	friend istream& operator>>(istream& is, str& other);

};

