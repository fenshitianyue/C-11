//目的：
//    测试vector的push_back左值数据和emplace_back右值数据的性能比较
//结果：
//    经测试，当数据量比较大的时候，emplace_back明显比push_back快

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
std::string InputPath = "./dict_data";

static int64_t TimeStampMS(){
  struct timeval tv;
  ::gettimeofday(&tv, NULL);
  return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

void BuildWord(const std::string& word){
  WordInfo word_info; 
  word_info.id = dict.size();
  word_info.word = word;
  //dict.push_back(word_info);
  dict.emplace_back(std::move(word_info));
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
  std::cout << "time: " << TimeStampMS() - begin << std::endl;
  file.close();
  std::cout << "Building a successful." << std::endl;
}

int main() {
  BuildDict("./dict_data");
  return 0;
}

