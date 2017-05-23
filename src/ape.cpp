#include "lib/sys.h"
#include "lib/loc.h"
#include "lib/compile.h"
#include "lib/convert.h"

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
  vector<string> argV = toVector(argv);
  if (argV.size() < 2) {
    string srcContents;
    for (string line; getline(cin, line);) {
      srcContents += line + "\n";
    }

    const int compRes = compile(srcContents);
    if (compRes) {
      return compRes;
    }

    return sys("/tmp/ape-exe", argV);
  }
  const string src = argV[1];

  const int makeRes = sys("ape-make " + src);
  if (makeRes) {
    return makeRes;
  }

  const string binLoc = getBinLoc(src);

  return sys(binLoc, argV);
}

