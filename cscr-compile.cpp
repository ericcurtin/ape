#include "sys.h"
#include "loc.h"
#include "compile.h"

#include <linux/limits.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fstream>
#include <libgen.h>
#include <stdlib.h>

int main(const int argc, const char** argv) {
  if (!*++argv) {
    printf("csrc-compile requires at least one argument\n");
    return 1;
  }

  const string src = *argv;
  const string binLoc = getBinLoc(src);

  std::ifstream infile(src.c_str());
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

