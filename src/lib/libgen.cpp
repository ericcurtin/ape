#include <libgen.h>
#include <string.h>

#include "libgen.h"
#include "limits.h"

string apeDirname(string& name) {
  char nameCstr[PATH_MAX];
  strcpy(nameCstr, name.c_str());
  dirname(nameCstr);
  name = nameCstr;

  return name;
}

string apeBasename(string& name) {
  char nameCstr[PATH_MAX];
  strcpy(nameCstr, name.c_str());
  basename(nameCstr);
  name = nameCstr;

  return name;
}

