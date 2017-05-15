#include "sys.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdexcept>

const int sys(const char* const toRun) {
  const int cscr = system(toRun);
  return WEXITSTATUS(cscr);
}

const string qx(const char* const toRun) {
  const size_t bufSiz = 128;
  char buf[bufSiz];
  string result = "";
  FILE* const pipe = popen(toRun, "r");
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

