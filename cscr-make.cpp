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

  return sys(("cscr-compile " + src).c_str());
}

