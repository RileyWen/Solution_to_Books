#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <functional>
using namespace std;
int main()
{
  ifstream fin("./word.txt");
  map<string, size_t> word_count;
  string word;
  while (fin >> word)
    ++word_count[word];

  typedef function<bool(pair<string, size_t>, pair<string, size_t>)> CmpType;
  CmpType Cmp = [](pair<string, size_t> a, pair<string, size_t> b) {
    return a.second > b.second;
  };

  set<pair<string, size_t>, CmpType> word_freq(word_count.begin(), word_count.end(), Cmp);
  for (auto element : word_freq)
    cout << element.first << " " << element.second << endl;
  return 0;
}