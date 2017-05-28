#include "lib/sys.h"
#include "lib/loc.h"
#include "lib/convert.h"

#include <unistd.h>
#include <sys/stat.h>
#include <fstream>
#include <libgen.h>
#include <stdlib.h>
#include <iostream>

using std::cout;

int main(const int, const char** argv) {
  vector<string> argV = toVector(argv);
  if (argV.size() < 2) {
    cout << "ape-make requires at least one argument\n";
    return 1;
  }

  const string src = argV[1];
  const string srcLoc = getSrcLoc(src);
  const string binLoc = getBinLoc(src);

  struct stat bin_stat;
  // If the binary exists check is the binary is newer than the source
  if (!stat(binLoc.c_str(), &bin_stat)) {
    struct stat src_stat;
    stat(srcLoc.c_str(), &src_stat);

    if (bin_stat.st_mtime > src_stat.st_mtime) {
      return 0;
    }
  }

  return sys("ape-compile " + src);
}

