#include "sys.h"
#include "loc.h"

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

int main(const int argc, const char** argv) {
  string src;
  if (*++argv) {
    src = *argv;

    sys(("cscr-make " + src).c_str());

    const string binLoc = getBinLoc(src);
    return sys(binLoc.c_str());    
  }

  return 1;
}

