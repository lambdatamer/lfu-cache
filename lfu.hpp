#pragma once

#include <iostream>
#include <map>
#include <set>

using namespace std;

template<typename T>
class Compare{
public:
	bool operator()(T a, T b){
		return a->second < b->second;
	}
};

class LfuCache{
private:
	int size;
	map<string, int> cache;
	multimap<int, string> nav;
	void navPop(string _value);
public:
	LfuCache(const size_t _size); 
	bool find_and_add(const string &_address);
	friend ostream& operator<<(ostream &_out, LfuCache &_lfumap);
};