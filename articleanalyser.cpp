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
	std::vector<std::string>vec = read_file();
	std::string str;
	for (int i = 0; i < vec.size()-1 ; i++) {
		if (std::count(vec.begin(), vec.end(), vec[i]) > std::count(vec.begin(), vec.end(), vec[i + 1])) {
			str = vec[i];


		}
	}
	if (str == "") {
		std::cout << "There is no most common word " << std::endl;
	}
	else{
		std::cout << "Most common word : " << str << std::endl;
	}
}


