@ECHO OFF

REM Setting up local build configurations
CALL build_config.bat

REM Build cleanup
rmdir /S /Q build
mkdir build

REM Compilation
%TOOLCHAIN_PATH%\%C_COMPILER% -c src\core\main.c -I%LIBSDL_PATH%\include\SDL2 -Wall -Wextra -Werror -std=c17 -o build\main.o
%TOOLCHAIN_PATH%\%C_COMPILER% -c src\core\video\window.c -I%LIBSDL_PATH%\include\SDL2 -Wall -Wextra -Werror -std=c17 -o build\window.o

REM Linking
%TOOLCHAIN_PATH%\%C_COMPILER% build\main.o build\window.o -L%LIBSDL_PATH%\lib -mwindows -lmingw32 -lSDL2main -lSDL2 -o build\brenoGame.exe

REM Installation cleanup
rmdir /S /Q install
mkdir install

REM Installing
copy /B /Y %LIBSDL_PATH%\bin\SDL2.dll install
copy /B /Y build\brenoGame.exe install