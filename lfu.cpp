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
		// if(cache.size() == size){
		// 	cache.erase(*nav.begin());
		// 	nav.erase(nav.begin());
		// }
		// cache.insert(pair<string, int>(_address, 1));
		// nav.insert(cache.find(_address));
	}else{
		// cache.at(_address)++;	
		// nav.erase(finded);
		// nav.insert(finded);
	}
}

int LfuCache::operator()(string &_str){
	return cache.at(_str);
}

ostream& operator<<(ostream &_out, LfuCache &_lfumap){
	cout << "Map:" << endl;
	for(auto elem : _lfumap.cache){
		cout << elem.first << " : " << elem.second << endl;
	}
	cout << "Set:" << endl;
	for(auto elem : _lfumap.nav){
		cout << elem->first << " : " << elem->second << endl;
	} 
	return _out;
}