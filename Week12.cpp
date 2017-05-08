// Week12.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "std_lib_facilities.h"
#include <fstream>
#include <map>
using namespace std;


int main()
{
	vector<string> dic;        //def a vector to store words from dictionary;
	ifstream file;
	file.open("D:\\EnglishWords.txt", ios::in);
	if (!file.is_open()) {
		cout << "Opening mistake!" << endl;
		return 0;
	}
	else {
		string str;
		while (getline(file, str)) {
			if (str.empty()) continue;
			else {
				dic.push_back(str);
			}
		}
	}


	int suffix_length;   //length of suffix the user input
	cout << "Please input length of suffix: " << endl;
	cin >> suffix_length;
	int i;
	vector<string> suffix;
	multimap<string, string> map1;
	multimap<int, string> map2;
	for (i = 0;i < dic.size();i++) {
		string t = dic[i];
		if (t.size() < suffix_length) continue;
		else {
			string ts = t.substr(t.size() - suffix_length);
			map1.insert(pair<string, string>(ts, t));
		}
	}
	multimap<string, string>::iterator p;
	for (p = map1.begin();p != map1.end();p++) {
		int amount = map1.count(p->first);
		string d = p->first;
		if (map2.find(amount)== map2.end()) {

		}
		else {
			map2.insert(pair<int, string>(amount, d));
		}
	}

	multimap<int, string>::iterator p2;
	pair<multimap<int, string>::iterator, multimap<int, string>::iterator> ret;
	for (p2 = map2.begin();p2 != map2.end();p2++) {
		cout << p2->first << "=>";
		for (p2 = ret.first;p2 != ret.second;++p2) {
			cout << " " << (*p2).second;
		
		}
		cout << endl;
	}

    return 0;
}

