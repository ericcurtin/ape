#include <iostream>
#include <stdio.h>
#include <fstream>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <libgen.h>
#include <unistd.h>
#include <sys/stat.h>

using namespace std;

using std::string;
using std::getline;

int main(int argc, char * argv[]) {
    string src;
    if (* ++argv) {
        src = * argv;
    }

    char cwd[PATH_MAX];
    getcwd(cwd, sizeof(cwd));

    string base = "/tmp";

    const string src_loc = string(cwd) + '/' + src;
    const string bin_loc = base + src_loc;

    struct stat bin_stat;
    // If the binary exists check is the binary is newer than the source
    if (!stat(bin_loc.c_str(), & bin_stat)) {
        struct stat src_stat;
        stat(src_loc.c_str(), & src_stat);

        if (bin_stat.st_mtime > src_stat.st_mtime) {
            return system(bin_loc.c_str());
        }
    }

    string compiler = "/usr/bin/g++ -O2 -o " + bin_loc + " -xc++ - ";

    std::ifstream infile(src.c_str());
    string source_contents = "\n";
    string line;
    getline(infile, line);
    while (getline(infile, line)) {
        source_contents += line + "\n";
    }

    char bin_loc_dirname_cstr[PATH_MAX];
    bin_loc.copy(bin_loc_dirname_cstr, sizeof(bin_loc_dirname_cstr));

    dirname(bin_loc_dirname_cstr);
    string bin_loc_dirname = bin_loc_dirname_cstr;
    system(("mkdir -p " + bin_loc_dirname).c_str());

    FILE * file = popen(compiler.c_str(), "w");
    fwrite(source_contents.c_str(),
           sizeof(char),
           source_contents.length(),
           file);
    int comp_res = pclose(file);
    if (comp_res) {
        return WEXITSTATUS(comp_res);
    }

    return system(bin_loc.c_str());
}

