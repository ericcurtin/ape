#include "convert.h"

#include <sstream>
#include <stdio.h>

using std::istringstream;

vector<string> toVector(const string& str) {
  string word;
  vector<string> ret;

  for(istringstream iss(str); iss >> word;) {
      ret.push_back(word);
  }

  return ret;
}

vector<string> toVector(const char** charv) {
  vector<string> ret;

  for (; *charv; ++charv) {
    ret.push_back(*charv);
  }

  return ret;
}

