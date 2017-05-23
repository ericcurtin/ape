#include "lib/sys.h"
#include "lib/loc.h"
#include "lib/compile.h"
#include "lib/limits.h"
#include "lib/convert.h"

#include <unistd.h>
#include <sys/stat.h>
#include <fstream>
#include <libgen.h>
#include <stdlib.h>

using std::ifstream;

int main(const int, const char** argv) {
  vector<string> argV = toVector(argv);
  if (argV.size() < 2) {
    printf("ape-compile requires at least one argument %lu\n", argV.size());
    return 1;
  }

  const string src = argV[1];
  const string binLoc = getBinLoc(src);

  ifstream infile(src.c_str());
  string srcContents = "\n";
  string line;
  getline(infile, line);
  while (getline(infile, line)) {
    srcContents += line + "\n";
  }

  char binLoc_dirname_cstr[PATH_MAX];
  binLoc.copy(binLoc_dirname_cstr, sizeof(binLoc_dirname_cstr));

  dirname(binLoc_dirname_cstr);
  const string binLoc_dirname = binLoc_dirname_cstr;
  sys("mkdir -p " + binLoc_dirname);

  return compile(srcContents, binLoc);
}

