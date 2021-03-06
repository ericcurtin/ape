#include "sys.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdexcept>

int sys(const string& toRun, vector<string> argV) {
  string exe = toRun;
  for(vector<string>::const_iterator it = argV.begin();
      it != argV.end();
      ++it) {
    exe += " " + *it;
  }

  const int ret = system(exe.c_str());
  return WEXITSTATUS(ret);
}

const string qx(const string& toRun) {
  const size_t bufSiz = 128;
  char buf[bufSiz];
  string result;
  FILE* const pipe = popen(toRun.c_str(), "r");
  if (!pipe) {
    throw std::runtime_error("popen() failed!");
  }
  try {
    while (!feof(pipe)) {
      if (fgets(buf, bufSiz, pipe)) {
        result += buf;
      }
    }
  } catch (...) {
    pclose(pipe);
    throw;
  }
  pclose(pipe);
  return result;
}

