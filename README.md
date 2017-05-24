# ape [![Build Status](https://travis-ci.org/ericcurtin/ape.svg?branch=master)](https://travis-ci.org/ericcurtin/ape)

## Overview

ape is a tool that allows you to use a compiled language as a scripting
language.

## Building

To build ape, simply run:

  `./build.sh`

ape uses the cmake build system.

## Installing

To install ape, build using steps above and then run:

  `make install`

as the root user to install.

## Using

Once ape is installed, try to execute helloWorld.ape script.

## Writing ape script

Start with:

  `#!/usr/bin/ape`

followed by your C++ code.

## Tools

There are two tools that can be used to compile an ape script.

### ape-compile

ape-compile compiles the script, the location of the binary will be:

  /tmp + "path of ape source"

### ape-make

ape-make compiles the script, if the modification date of the source is more
recent than the binary.

ape-make executes ape-compile.

### ape

ape when executed on it's own, reads STDIN. You can end STDIN by pressing
Ctrl-d. Once this data is read, it is compiled and executed.

ape when given an argument, will pass the file to ape-make.

ape executes ape-make.

## Proposals for enhancement

Open an issue:

  https://github.com/ericcurtin/ape/issues

## Contributing

Open a pull request:

  https://github.com/ericcurtin/ape/pulls

