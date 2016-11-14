#pragma once

#include <iostream>
#include <map>

using namespace std;

template<typename T>
class Compare{
public:
	bool operator()(T a, T b){
		cout << a->second << " > " << b->second << " : " << (a->second > b->second) << endl;
		return a->second < b->second;
	}
};

class LfuCache{
private:
	int size;
	map<string, int> cache;
	// set<
	// 	map<string, int>::iterator,  
	// 	Compare<map<string, int>::iterator>
	// > nav;
public:
	LfuCache(const size_t _size); 
	bool find_and_add(const string &_address);
	int operator()(string &_str);
	friend ostream& operator<<(ostream &_out, LfuCache &_lfumap);
};