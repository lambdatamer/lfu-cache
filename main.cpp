#include <iostream>

#include "lfu.hpp"

using namespace std;

int main(){
	string answer;
	int size;
	bool cacheExist = false;
	
	cout << "Enter size:\n>:";
	cin >> size;

	auto lfu = new LfuCache(size);
	bool exist = true;

	while(true){
		cout << ">:";
		cin >> answer;

		if(answer == "help"){
			cout << "help" << endl;

		}else if(answer.substr(0, 4) == "exit"){
			return 0;

		}else if(answer.substr(0, 6) == "create"){
			if(exist){
				cout << "LFU Cache already exist." << endl;
			}else{
				cin >> size;
				lfu = new LfuCache(size);
				exist = true;
				cout << "Created." << endl;
			}

		}else if(answer.substr(0, 3) == "key"){
			if(exist){
				cin >> answer;
				lfu->find_and_add(answer);
			}else{
				cout << "LFU Cache doesn't exist." << endl;
			}

		}else if(answer.substr(0, 4) == "list"){
			if(exist){
				cout << *lfu << endl;
			}else{
				cout << "LFU Cache doesn't exist." << endl;
			}

		}else if(answer.substr(0, 6) == "delete"){
			if(exist){
				delete lfu;
				lfu = nullptr;
				exist = false;
				cout << "Deleted." << endl;
			}else{
				cout << "LFU Cache doesn't exist." << endl;
			}

		}else if(answer.substr(0, 4) == "find"){
			if(exist){
				cin >> answer;
				cout << (*lfu)(answer) << endl;
			}else{
				cout << "LFU Cache doesn't exist." << endl;
			}

		}else{
			cout << "Unknown command.\nType 'help' to see awailable commands." << endl;
		}
	}
}