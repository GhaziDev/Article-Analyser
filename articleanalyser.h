#pragma once
#include<string>
#include<vector>
#include<map>
class ArticleAnalyser {
public:
	std::string path;
	ArticleAnalyser(std::string );
	std::vector<std::string>read_file();
	void words_len();
    void short_long();
	void common_word();
	


};