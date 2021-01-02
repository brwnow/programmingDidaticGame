# Programming Didatic Game Project

Simple game with a didatic pupose of helping my brother learn programming and versioning

# Documentation generating

First install doxygen and add its binaries path to PATH env in order to be possibile calling it from the command line.
  
Navigate to the root path of the project and run `doxygen doc/Doxyfile`. The project documentation will be generated at `doc/Generated`. Open the file `index.html` to access the documentation

# Testing

In order to run tests, you must call the `run_tests.bat` script, which has a single positional parameter, that is the build target and must be release or debug.
  
Its recommended running this script through git bash terminal or WSL one, so the test result is colored and easier to check if all tests have passed.

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
  
The `build.bat` script receive a positional parameter, the first one, which sets the build target to `release` or `debug`. If none build target is passed, `release` is the default one.
  
On success, the game binary and its dependencies are moved to `install`, to the folder of the selected build target `release`|`debug`
