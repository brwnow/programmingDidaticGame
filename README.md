# Programming Didatic Game Project

Simple game with a didatic pupose of helping my brother learn programming and versioning

# Building
## Linux
Not available yet

## Windows
In the first run of `build.bat` script a file named `build_config.bat` will be created. This is the file where to configure your local enviroment for the build.

You have to set in `build_config.bat` the following variables:
* `TOOLCHAIN_PATH` is the path to the toolchain you are using to build the project
* `C_COMPILER` is the command to call for compiling each source of the projecto (example `gcc`)
* `LIBSDL_PATH` the path to your local installation of libsdl, containing bin, include and lib folders
* `LIBSDLTTF_PATH` the path to your local installation of libsdlttf
