#include<iostream>
#include<string>
#include<regex>
#include<vector>
#include<map>
#include<fstream>
#include<filesystem>
#include "articleanalyser.h"
ArticleAnalyser::ArticleAnalyser(std::string path) {
	this->path = path;
}
std::vector<std::string>ArticleAnalyser::read_file() {
	std::ifstream file(this->path);
	std::string str, str2,str4;
	std::vector<std::string>vec;
	if (file.tellg() == 0) {
		std::terminate();
	}
	while (file >> str) {
		str2 += str + " ";
	}
	//removing all punctutations using regex.
	std::regex exp("[^a-zA-Z\\s]");
	std::string result = std::regex_replace(str2, exp, "");
	//writing the text into new file
	for (auto i : result) {
		if (i == ' ') {
			vec.push_back(str4);
			str4 = "";
		}

		else {
			str4 += i;
		}
	}
	return vec;

}
void ArticleAnalyser::words_len() {
	std::filesystem::create_directory("C:/data");
	std::vector<std::string>vec = read_file();
	std::fstream csv_file;
	std::map<std::string, int>dict;
	std::vector<std::string>row;
	std::vector<int>column;
	for (auto i : vec) {
		dict[i] = i.size();

	}
	dict.erase(" ");
	csv_file.open("C:/data/data.csv", std::ios::out);
	csv_file << "Words" <<","<<"Length"<<"\n";
	for (auto i : dict) {
		row.push_back(i.first);
		column.push_back(i.second);
		csv_file << i.first <<","<< i.second << "\n";
	}
}
void ArticleAnalyser::short_long() {
	std::vector<std::string>vec = read_file();
	std::sort(vec.begin(), vec.end(), [](const std::string& first, const std::string& scnd) {
		return (first.size() < scnd.size());

		});

	std::cout << "Shortest word : " << vec[1] << std::endl;
	std::cout << "Longest word : " << vec[vec.size() - 1] << std::endl;
	std::cout <<std::endl;

}
void ArticleAnalyser::common_word() {
	std::vector<std::pair<std::string,int>>hashmap;
	std::map<std::string,int>mp;
	std::vector<std::string>vec = read_file();
	std::string str;
	for (auto i : vec) {
		if (mp[i]) {
			mp[i] += 1;
		}
		else {
			mp[i] = 1;
		}
	}
	for(auto i:mp){
		hashmap.push_back(i);
	}
	std::sort(hashmap.begin(),hashmap.end(),[](std::pair<std::string,int>val1,std::pair<std::string,int>val2){return val1.second>val2.second;});
	for(auto i:hashmap){
		str+=i.first;
		break;
	}

	if (str == "") {
		std::cout << "There is no most common word " << std::endl;
	}
	else{
		std::cout << "Most common word : " << str << std::endl;
	}
}


