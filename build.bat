@ECHO OFF

set BUILD_CFG_FILE=build_config.bat

REM Setting up local build configurations
IF EXIST %BUILD_CFG_FILE% (
    CALL %BUILD_CFG_FILE%
) ELSE (
    REM Creating build config file because it was not found
    ECHO REM Path to bin folder of your toolchain>> %BUILD_CFG_FILE%
    ECHO set TOOLCHAIN_PATH=>> %BUILD_CFG_FILE%
    ECHO.>> %BUILD_CFG_FILE%
    ECHO REM Compiler within bin folder of your toolchain to be called for>> %BUILD_CFG_FILE%
    ECHO REM compliing and linking the project>> %BUILD_CFG_FILE%
    ECHO set C_COMPILER=>> %BUILD_CFG_FILE%
    ECHO.>> %BUILD_CFG_FILE%
    ECHO REM Path to your installation of SDL2 and SDL2_ttf extension libs>> %BUILD_CFG_FILE%
    ECHO REM containing bin, include and lib folders>> %BUILD_CFG_FILE%
    ECHO set LIBSDL_PATH=>> %BUILD_CFG_FILE%
    ECHO set LIBSDLTTF_PATH=>> %BUILD_CFG_FILE%

    ECHO %BUILD_CFG_FILE% created. Fill up the file envs and build again
    EXIT /B
)

REM Setting up PATH to avoid missing .dll while running gcc.exe
set PATH=%PATH%;%TOOLCHAIN_PATH%

REM Setting up default build configurations
set BUILD_COMPILE_FLAGS=-Wall -Wextra -Werror -std=c17
set BUILD_COMPILE_DEFINES=
set BUILD_LINKING_FLAGS=-mwindows
set BUILD_COMPILE_INCLUDE_PATHS=-I%LIBSDL_PATH%\include\SDL2 -I%LIBSDLTTF_PATH%\include\SDL2 -Isrc\include

IF /I "%1" == "debug" (
    REM Debug build configurations
    set BUILD_MODE=debug
    set BUILD_COMPILE_FLAGS=%BUILD_COMPILE_FLAGS% -g
    set BUILD_COMPILE_DEFINES=%BUILD_COMPILE_DEFINES% -D_DEBUG_BUILD_
    set BUILD_LINKING_FLAGS=%BUILD_LINKING_FLAGS% -mconsole
) ELSE (
    REM Release build configurations
    set BUILD_MODE=release
    set BUILD_COMPILE_FLAGS=%BUILD_COMPILE_FLAGS% -O2
)

REM Build cleanup
IF EXIST build\%BUILD_MODE% (
    rmdir /S /Q build\%BUILD_MODE%
)

mkdir build\%BUILD_MODE%

echo Build starting
echo ----------------------------------------
echo build target: %BUILD_MODE%
echo compiler flags: %BUILD_COMPILE_FLAGS%
echo linking flags: %BUILD_LINKING_FLAGS%
echo ----------------------------------------

REM Game binary building

REM Game binary compilation
%TOOLCHAIN_PATH%\%C_COMPILER% -c src\core\main.c %BUILD_COMPILE_INCLUDE_PATHS% %BUILD_COMPILE_FLAGS% %BUILD_COMPILE_DEFINES% -o build\%BUILD_MODE%\main.o
%TOOLCHAIN_PATH%\%C_COMPILER% -c src\utils\log\log.c %BUILD_COMPILE_INCLUDE_PATHS% %BUILD_COMPILE_FLAGS% %BUILD_COMPILE_DEFINES% -o build\%BUILD_MODE%\log.o
%TOOLCHAIN_PATH%\%C_COMPILER% -c src\utils\datastructure\list.c %BUILD_COMPILE_INCLUDE_PATHS% %BUILD_COMPILE_FLAGS% %BUILD_COMPILE_DEFINES% -o build\%BUILD_MODE%\list.o
%TOOLCHAIN_PATH%\%C_COMPILER% -c src\core\input\events.c %BUILD_COMPILE_INCLUDE_PATHS% %BUILD_COMPILE_FLAGS% %BUILD_COMPILE_DEFINES% -o build\%BUILD_MODE%\events.o
%TOOLCHAIN_PATH%\%C_COMPILER% -c src\core\input\keyboard.c %BUILD_COMPILE_INCLUDE_PATHS% %BUILD_COMPILE_FLAGS% %BUILD_COMPILE_DEFINES% -o build\%BUILD_MODE%\keyboard.o
%TOOLCHAIN_PATH%\%C_COMPILER% -c src\core\video\video.c %BUILD_COMPILE_INCLUDE_PATHS% %BUILD_COMPILE_FLAGS% %BUILD_COMPILE_DEFINES% -o build\%BUILD_MODE%\video.o
%TOOLCHAIN_PATH%\%C_COMPILER% -c src\core\video\window.c %BUILD_COMPILE_INCLUDE_PATHS% %BUILD_COMPILE_FLAGS% %BUILD_COMPILE_DEFINES% -o build\%BUILD_MODE%\window.o

REM Game binary linking
%TOOLCHAIN_PATH%\%C_COMPILER%   build\%BUILD_MODE%\main.o^
                                build\%BUILD_MODE%\log.o^
                                build\%BUILD_MODE%\list.o^
                                build\%BUILD_MODE%\events.o^
                                build\%BUILD_MODE%\keyboard.o^
                                build\%BUILD_MODE%\video.o^
                                build\%BUILD_MODE%\window.o^
                                -L%LIBSDL_PATH%\lib -L%LIBSDLTTF_PATH%\lib^
                                -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf^
                                %BUILD_LINKING_FLAGS%^
                                -o build\%BUILD_MODE%\brenoGame.exe

REM Installation cleanup
rmdir /S /Q install\%BUILD_MODE%
mkdir install\%BUILD_MODE%
mkdir install\%BUILD_MODE%\res
mkdir install\%BUILD_MODE%\res\fonts

REM Installing
REM Moving build binary and needed libraries
copy /B /Y %LIBSDL_PATH%\bin\SDL2.dll install\%BUILD_MODE%
copy /B /Y %LIBSDLTTF_PATH%\bin\*.dll install\%BUILD_MODE%
copy /B /Y build\%BUILD_MODE%\brenoGame.exe install\%BUILD_MODE%

REM Moving resources files
copy /B /Y resources\fonts\*.ttf install\%BUILD_MODE%\res\fonts