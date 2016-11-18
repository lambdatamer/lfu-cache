#include <iostream>
#include <limits>

#include "lfu.hpp"

using namespace std;

void purge(){
	cin.clear();
	cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
}

int main(){
	string answer;
	int size;
	bool exist = false;
	LfuCache *lfu;

	while(true){
		cout << ">:";
		cin >> answer;

		if(answer == "help"){
			cout << "\tkey <key>\tCreates <key> or increases <key> value in the cache\n" << endl;
			cout << "\tlist\t\tPrints up the cache\n" << endl;
			cout << "\tcreate <size>\tCreates the cache\n" << endl;
			cout << "\tdelete\t\tDeletes the cache\n" << endl;
			cout << "\texit\t\tExit program\n" << endl;
		}else if(answer.substr(0, 4) == "exit"){
			return 0;

		}else if(answer.substr(0, 6) == "create"){
			if(exist){
				cout << "LFU Cache already exist." << endl;
			}else{
				if(!(cin >> size) || size < 1){
					cout << "Incorrect value! It must be number greater than 0." << endl;
					purge();
				}else{
					lfu = new LfuCache(size);
					exist = true;
					cout << "Created." << endl;
				}
			}

		}else if(answer.substr(0, 3) == "key"){
			if(exist){
				cin >> answer;
				lfu->find_and_add(answer);
			}else{
				cout << "LFU Cache doesn't exist." << endl;
				purge();
			}

		}else if(answer.substr(0, 4) == "list"){
			if(exist){
				cout << *lfu << endl;
			}else{
				cout << "LFU Cache doesn't exist." << endl;
				purge();
			}

		}else if(answer.substr(0, 6) == "delete"){
			if(exist){
				delete lfu;
				lfu = nullptr;
				exist = false;
				cout << "Deleted." << endl;
			}else{
				cout << "LFU Cache doesn't exist." << endl;
				purge();
			}

		}else{
			cout << "Unknown command.\nType 'help' to see awailable commands." << endl;
			purge();
		}

	}
}