#include "unistd.h"
#include "limits.h"

#include <unistd.h>

string apeGetcwd() {
  char tmp[PATH_MAX];
  getcwd(tmp, PATH_MAX);

  return string(tmp);
}

