#include <libgen.h>
#include <string.h>

#include "libgen.h"
#include "limits.h"

string apeDirname(const string& name) {
  char nameCstr[PATH_MAX];
  strcpy(nameCstr, name.c_str());

  return dirname(nameCstr);
}

string apeBasename(const string& name) {
  char nameCstr[PATH_MAX];
  strcpy(nameCstr, name.c_str());

  return basename(nameCstr);
}

