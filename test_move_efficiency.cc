#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <utility>
#include <sys/time.h>

struct WordInfo{
  int64_t id;
  std::string word; 
};

std::vector<WordInfo> dict;
//dict_data文件包含100 000行数据
std::string InputPath = "./dict_data";

static int64_t TimeStampMS(){
  struct timeval tv;
  ::gettimeofday(&tv, NULL);
  return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

//创建一个临时对象初始化后插入到vector中
void BuildWord(const std::string& word){
  WordInfo word_info; 
  word_info.id = dict.size();
  word_info.word = word;
  dict.push_back(word_info); //测试 push_back
  //dict.emplace_back(std::move(word_info)); //测试 emplace_back
}

void BuildDict(const std::string& input_path){
  std::ifstream file(input_path.data());
  if(!file.is_open()){
    std::cout << "Open file faild!!!" << std::endl;
    exit(EXIT_FAILURE);
  }
  std::string line;
  int64_t begin = TimeStampMS();
  while(std::getline(file, line)){
    BuildWord(line);   
  }
  std::cout << "time: " << TimeStampMS() - begin << "ms" << std::endl;
  file.close();
  std::cout << "Building a successful." << std::endl;
}

int main() {
  BuildDict("./dict_data");
  return 0;
}
