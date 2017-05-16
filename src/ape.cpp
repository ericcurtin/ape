#include "sys.h"
#include "loc.h"
#include "compile.h"

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <libgen.h>
#include <unistd.h>
#include <sys/stat.h>

using std::string;
using std::getline;
using std::cin;

int main(const int, const char** argv) {
  if (*++argv) {
    const string src = *argv;

    sys("ape-make " + src);

    const string binLoc = getBinLoc(src);
    return sys(binLoc);    
  }

  string srcContents;
  for (string line; getline(cin, line);) {
    srcContents += line + "\n";
  }

  const int compRes = compile(srcContents);
  if (compRes) {
    return compRes;
  }

  return sys("/tmp/ape-exe");
}

