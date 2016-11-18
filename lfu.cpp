#include <iostream>
#include <map>
#include <queue>
#include <vector>

#include "lfu.hpp"

using namespace std;

LfuCache::LfuCache(const size_t _size){
	size = _size;
}

bool LfuCache::find_and_add(const string &_address){
	auto finded = cache.find(_address);
	if(finded == cache.end()){
		if(cache.size() >= size){
			cache.erase(nav.begin()->second);
			nav.erase(nav.begin());
		}
		cache.insert(pair<string, int>(_address, 1));
		nav.insert(pair<int, string>(1, _address));

		return false;
	}else{
		navPop(_address);
		cache.at(_address)++;
		nav.insert(pair<int, string>(cache.at(_address), _address));

		return true;
	}
}

void LfuCache::navPop(string _value){
	for(auto i = nav.begin(); i != nav.end(); i++){
		if(i->second == _value){
			nav.erase(i);
		}
	}
}

ostream& operator<<(ostream &_out, LfuCache &_lfumap){
	cout << "Map:" << endl;
	for(auto elem : _lfumap.cache){
		cout << elem.first << " : " << elem.second << endl;
	}
	cout << "Nav:" << endl;
	for(auto elem : _lfumap.nav){
		cout << elem.first << " : " << elem.second << endl;
	}
	return _out;
}