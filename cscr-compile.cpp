#include "sys.h"
#include "loc.h"

#include <linux/limits.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fstream>
#include <libgen.h>
#include <stdlib.h>

int main(const int argc, const char** argv) {
  string src;
  if (*++argv) {
    src = *argv;
  }

  const string binLoc = getBinLoc(src);

  const string compiler = "/usr/bin/g++ -O2 -o " + binLoc + " libcscr.so -xc++ - ";

  std::ifstream infile(src.c_str());
  string source_contents = "\n";
  string line;
  getline(infile, line);
  while (getline(infile, line)) {
    source_contents += line + "\n";
  }

  char binLoc_dirname_cstr[PATH_MAX];
  binLoc.copy(binLoc_dirname_cstr, sizeof(binLoc_dirname_cstr));

  dirname(binLoc_dirname_cstr);
  const string binLoc_dirname = binLoc_dirname_cstr;
  system(("mkdir -p " + binLoc_dirname).c_str());

  FILE* const file = popen(compiler.c_str(), "w");
  fwrite(source_contents.c_str(),
         sizeof(char),
         source_contents.length(),
         file);
  const int comp_res = pclose(file);

  return WEXITSTATUS(comp_res);
}

