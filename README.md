# Programming Didatic Game Project

Simple game with a didatic pupose of helping my brother learn programming and versioning

# Building
## Linux
Not available yet

## Windows
First you need to create a local build configuration file in the project root named `build_config.bat`. You must copy the template bellow to your file

```
REM Path to bin folder of your toolchain
set TOOLCHAIN_PATH=

REM Compiler within bin folder of your toolchain to be called for
REM compliing and linking the project
set C_COMPILER=

REM Path to your installation of SDL2 and SDL2_ttf extension libs
REM containing bin, include and lib folders
set LIBSDL_PATH=
set LIBSDLTTF_PATH=
```

Where:
* `TOOLCHAIN_PATH` is the path to the toolchain you are using to build the project
* `C_COMPILER` is the command to call for compiling each source of the projecto (example `gcc`)
* `LIBSDL_PATH` the path to your local installation of libsdl, containing bin, include and lib folders
* `LIBSDLTTF_PATH` the path to your local installation of libsdlttf