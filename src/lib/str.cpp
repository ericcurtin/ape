#include "str.h"

#include <string.h>

int startsWith(const string& str, const string& subStr) {
  return strncmp(str.c_str(), subStr.c_str(), subStr.size());
}

