@ECHO OFF

REM Setting up local build configurations
CALL build_config.bat

REM Setting up build configurations
set BUILD_COMPILE_FLAGS=-O2
set BUILD_LINKING_FLAGS=-mwindows

IF /I "%BUILD_MODE%" == "debug" (
    set BUILD_MODE=debug
    set BUILD_COMPILE_FLAGS=-D_DEBUG_BUILD_ -g
    set BUILD_LINKING_FLAGS=-mconsole -mwindows
) ELSE (
    set BUILD_MODE=release
)

REM Build cleanup
rmdir /S /Q build\%BUILD_MODE%
mkdir build\%BUILD_MODE%

echo Building starting
echo build target: %BUILD_MODE%
echo compiler flags: %BUILD_COMPILE_FLAGS%
echo linking flags: %BUILD_LINKING_FLAGS%
echo ----------------------------------------

REM Compilation
%TOOLCHAIN_PATH%\%C_COMPILER% -c src\core\main.c -I%LIBSDL_PATH%\include\SDL2 -I%LIBSDLTTF_PATH%\include\SDL2 -Isrc\include %BUILD_COMPILE_FLAGS% -Wall -Wextra -Werror -std=c17 -o build\%BUILD_MODE%\main.o
%TOOLCHAIN_PATH%\%C_COMPILER% -c src\utils\log\log.c -I%LIBSDL_PATH%\include\SDL2 -I%LIBSDLTTF_PATH%\include\SDL2 -Isrc\include %BUILD_COMPILE_FLAGS% -Wall -Wextra -Werror -std=c17 -o build\%BUILD_MODE%\log.o
%TOOLCHAIN_PATH%\%C_COMPILER% -c src\core\input\events.c -I%LIBSDL_PATH%\include\SDL2 -I%LIBSDLTTF_PATH%\include\SDL2 -Isrc\include %BUILD_COMPILE_FLAGS% -Wall -Wextra -Werror -std=c17 -o build\%BUILD_MODE%\events.o
%TOOLCHAIN_PATH%\%C_COMPILER% -c src\core\input\keyboard.c -I%LIBSDL_PATH%\include\SDL2 -I%LIBSDLTTF_PATH%\include\SDL2 -Isrc\include %BUILD_COMPILE_FLAGS% -Wall -Wextra -Werror -std=c17 -o build\%BUILD_MODE%\keyboard.o
%TOOLCHAIN_PATH%\%C_COMPILER% -c src\core\video\video.c -I%LIBSDL_PATH%\include\SDL2 -I%LIBSDLTTF_PATH%\include\SDL2 -Isrc\include %BUILD_COMPILE_FLAGS% -Wall -Wextra -Werror -std=c17 -o build\%BUILD_MODE%\video.o
%TOOLCHAIN_PATH%\%C_COMPILER% -c src\core\video\window.c -I%LIBSDL_PATH%\include\SDL2 -I%LIBSDLTTF_PATH%\include\SDL2 -Isrc\include %BUILD_COMPILE_FLAGS% -Wall -Wextra -Werror -std=c17 -o build\%BUILD_MODE%\window.o

REM Linking
%TOOLCHAIN_PATH%\%C_COMPILER% build\%BUILD_MODE%\main.o build\%BUILD_MODE%\log.o build\%BUILD_MODE%\events.o build\%BUILD_MODE%\keyboard.o build\%BUILD_MODE%\video.o build\%BUILD_MODE%\window.o -L%LIBSDL_PATH%\lib -L%LIBSDLTTF_PATH%\lib %BUILD_LINKING_FLAGS% -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -o build\%BUILD_MODE%\brenoGame.exe

REM Installation cleanup
rmdir /S /Q install\%BUILD_MODE%
mkdir install\%BUILD_MODE%
mkdir install\%BUILD_MODE%\res
mkdir install\%BUILD_MODE%\res\fonts

REM Installing
REM Moving build binary and needed libraries
copy /B /Y %LIBSDL_PATH%\bin\SDL2.dll install\%BUILD_MODE%
copy /B /Y %LIBSDLTTF_PATH%\bin\SDL2_ttf.dll install\%BUILD_MODE%
copy /B /Y %LIBSDLTTF_PATH%\bin\libfreetype-6.dll install\%BUILD_MODE%
copy /B /Y %LIBSDLTTF_PATH%\bin\zlib1.dll install\%BUILD_MODE%
copy /B /Y build\%BUILD_MODE%\brenoGame.exe install\%BUILD_MODE%

REM Moving resources files
copy /B /Y resources\fonts\AlexBrush-Regular.ttf install\%BUILD_MODE%\res\fonts