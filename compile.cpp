#include "compile.h"

#include <stdio.h>
#include <sys/wait.h>

int compile(const string& toCompile, const string& binLoc) {
  const string compiler = "/usr/bin/g++ -O2 -o " + binLoc + " libcscr.so -xc++ - ";
  FILE* const file = popen(compiler.c_str(), "w");
  fwrite(toCompile.c_str(), sizeof(char), toCompile.length(), file);
  const int compRes = pclose(file);

  return WEXITSTATUS(compRes);
}

