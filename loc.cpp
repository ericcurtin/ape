#include "loc.h"

#if __linux__
  #include <linux/limits.h>
#else
  #include <sys/syslimits.h>
#endif

#include <unistd.h>

const string getSrcLoc(const string& src) {
  static string srcLoc;
  if (srcLoc.empty()) {
    char cwd[PATH_MAX];
    getcwd(cwd, sizeof(cwd));
    srcLoc = string(cwd) + '/' + src;
  }

  return srcLoc;
}

const string getBinLoc(const string& src) {
  return "/tmp" + getSrcLoc(src);
}

