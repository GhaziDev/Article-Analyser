#include<iostream>
#include<string>
#include<thread>
#include<chrono>
#include<filesystem>
#include "articleanalyser.h"
int main() {
	std::string path;
	std::cout << "Please enter the full path : ";
	std::cin >> path;
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
	while (true) {
		if (!std::filesystem::exists(path)) {
			std::cout << "Please enter the correct full path : ";
			getline(std::cin, path);

		}
		else if (std::filesystem::path(path).extension()!=".txt") {
			std::cout << "Please enter the correct full path : ";
			getline(std::cin, path);

		}

		else {
			break;
		}


	}
	ArticleAnalyser aa(path);
	auto start = std::chrono::steady_clock::now();
	std::thread length(&ArticleAnalyser::words_len,aa);
	std::thread sholo(&ArticleAnalyser::short_long,aa);
	std::thread com(&ArticleAnalyser::common_word,aa);
	length.join();
	sholo.join();
	com.join();
	auto end = std::chrono::steady_clock::now();
	auto result = end - start;
	std::cout<<"Execution Time : "<<std::chrono::duration <double, std::milli>(result).count() << " ms" <<std:: endl;
}