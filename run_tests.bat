@ECHO OFF

set BUILD_CFG_FILE=build_config.bat

REM Checking if build target was defined
IF "%~1" == "" (
    ECHO "ERROR: A build target (release|debug) must be passed as the first argument for run_tests script"
    EXIT /B
)

REM Setting up local build configurations
IF EXIST %BUILD_CFG_FILE% (
    CALL %BUILD_CFG_FILE%
) ELSE (
    ECHO ERROR: %BUILD_CFG_FILE% not found
    ECHO Hint: you need to build the game at least once before running tests
    EXIT /B
)

echo.
echo ======= BUILDING GAME =======
echo.
CALL build.bat %1 test

echo.
echo ======= BUILDING TESTS =======
echo.

REM Setting up PATH to avoid missing .dll while running gcc.exe
set PATH=%PATH%;%TOOLCHAIN_PATH%

REM Build artifacts paths
set TEST_INCLUDE_PATHS=-Imunit -Itests -Isrc\include -Itests\include -I%LIBSDL_PATH%\include\SDL2
set TEST_LIBS_PATHS=-L%LIBSDL_PATH%\lib
set TEST_NEEDED_LIBS=-lmingw32 -lSDL2main -lSDL2

REM Setting up default build configurations
set TEST_COMPILATION_PARAMS=-Wall -Wextra -Werror -Wno-implicit-function-declaration -std=c17 -D_TESTS_ENABLED_
set TEST_LINKING_FLAGS=-mconsole

IF /I "%1" == "debug" (
    REM Debug build configurations
    set BUILD_MODE=debug

    set TEST_COMPILATION_PARAMS=%TEST_COMPILATION_PARAMS% -g -D_DEBUG_BUILD_
) ELSE (
    REM Release build configurations
    set BUILD_MODE=release

    set TEST_COMPILATION_PARAMS=%TEST_COMPILATION_PARAMS% -O2
)

REM Tests build cleanup
IF EXIST build\tests\%BUILD_MODE% (
    rmdir /S /Q build\tests\%BUILD_MODE%
)

mkdir build\tests\%BUILD_MODE%

echo Build starting
echo ----------------------------------------
echo build target: %BUILD_MODE%
echo compiler flags: %TEST_COMPILATION_PARAMS%
echo linking flags: %TEST_LINKING_FLAGS%
echo ----------------------------------------

REM Tests compilation
%TOOLCHAIN_PATH%\%C_COMPILER% -c munit\munit.c %TEST_COMPILATION_PARAMS% -o build\tests\%BUILD_MODE%\munit.o
%TOOLCHAIN_PATH%\%C_COMPILER% -c tests\main.c %TEST_INCLUDE_PATHS% %TEST_COMPILATION_PARAMS% -o build\tests\%BUILD_MODE%\main.o
%TOOLCHAIN_PATH%\%C_COMPILER% -c tests\mockups\sdl_mockups.c %TEST_INCLUDE_PATHS% %TEST_COMPILATION_PARAMS% -o build\tests\%BUILD_MODE%\sdl_mockups.o

%TOOLCHAIN_PATH%\%C_COMPILER% -c tests\utils\datastructure\list_test_setups.c %TEST_INCLUDE_PATHS% %TEST_COMPILATION_PARAMS% -o build\tests\%BUILD_MODE%\list_test_setups.o
%TOOLCHAIN_PATH%\%C_COMPILER% -c tests\utils\datastructure\list_test_utils.c %TEST_INCLUDE_PATHS% %TEST_COMPILATION_PARAMS% -o build\tests\%BUILD_MODE%\list_test_utils.o
%TOOLCHAIN_PATH%\%C_COMPILER% -c tests\utils\datastructure\list_tests.c %TEST_INCLUDE_PATHS% %TEST_COMPILATION_PARAMS% -o build\tests\%BUILD_MODE%\list_tests.o
%TOOLCHAIN_PATH%\%C_COMPILER% -c tests\utils\datastructure\list_create_tests.c %TEST_INCLUDE_PATHS% %TEST_COMPILATION_PARAMS% -o build\tests\%BUILD_MODE%\list_create_tests.o
%TOOLCHAIN_PATH%\%C_COMPILER% -c tests\utils\datastructure\list_destroy_tests.c %TEST_INCLUDE_PATHS% %TEST_COMPILATION_PARAMS% -o build\tests\%BUILD_MODE%\list_destroy_tests.o
%TOOLCHAIN_PATH%\%C_COMPILER% -c tests\utils\datastructure\list_getter_tests.c %TEST_INCLUDE_PATHS% %TEST_COMPILATION_PARAMS% -o build\tests\%BUILD_MODE%\list_getter_tests.o
%TOOLCHAIN_PATH%\%C_COMPILER% -c tests\utils\datastructure\list_find_tests.c %TEST_INCLUDE_PATHS% %TEST_COMPILATION_PARAMS% -o build\tests\%BUILD_MODE%\list_find_tests.o
%TOOLCHAIN_PATH%\%C_COMPILER% -c tests\utils\datastructure\list_insert_tests.c %TEST_INCLUDE_PATHS% %TEST_COMPILATION_PARAMS% -o build\tests\%BUILD_MODE%\list_insert_tests.o
%TOOLCHAIN_PATH%\%C_COMPILER% -c tests\utils\datastructure\list_remove_tests.c %TEST_INCLUDE_PATHS% %TEST_COMPILATION_PARAMS% -o build\tests\%BUILD_MODE%\list_remove_tests.o

%TOOLCHAIN_PATH%\%C_COMPILER% -c tests\core\system\timer\timer_test_setups.c %TEST_INCLUDE_PATHS% %TEST_COMPILATION_PARAMS% -o build\tests\%BUILD_MODE%\timer_test_setups.o
%TOOLCHAIN_PATH%\%C_COMPILER% -c tests\core\system\timer\timer_tests.c %TEST_INCLUDE_PATHS% %TEST_COMPILATION_PARAMS% -o build\tests\%BUILD_MODE%\timer_tests.o
%TOOLCHAIN_PATH%\%C_COMPILER% -c tests\core\system\timer\timer_all_tests.c %TEST_INCLUDE_PATHS% %TEST_COMPILATION_PARAMS% -o build\tests\%BUILD_MODE%\timer_all_tests.o

set BUILD_OBJECTS_NEEDED_BY_TEST=   build\%BUILD_MODE%\log.o^
                                    build\tests\%BUILD_MODE%\munit.o^
                                    build\tests\%BUILD_MODE%\main.o^
                                    build\tests\%BUILD_MODE%\sdl_mockups.o^
                                    build\%BUILD_MODE%\list.o^
                                    build\%BUILD_MODE%\timer.o^
                                    build\tests\%BUILD_MODE%\list_test_setups.o^
                                    build\tests\%BUILD_MODE%\list_test_utils.o^
                                    build\tests\%BUILD_MODE%\list_tests.o^
                                    build\tests\%BUILD_MODE%\list_create_tests.o^
                                    build\tests\%BUILD_MODE%\list_destroy_tests.o^
                                    build\tests\%BUILD_MODE%\list_getter_tests.o^
                                    build\tests\%BUILD_MODE%\list_find_tests.o^
                                    build\tests\%BUILD_MODE%\list_insert_tests.o^
                                    build\tests\%BUILD_MODE%\list_remove_tests.o^
                                    build\tests\%BUILD_MODE%\timer_test_setups.o^
                                    build\tests\%BUILD_MODE%\timer_tests.o^
                                    build\tests\%BUILD_MODE%\timer_all_tests.o

REM Tests linking
%TOOLCHAIN_PATH%\%C_COMPILER%   %BUILD_OBJECTS_NEEDED_BY_TEST%^
                                %TEST_LIBS_PATHS%^
                                %TEST_NEEDED_LIBS%^
                                %TEST_LINKING_FLAGS%^
                                -o build\tests\%BUILD_MODE%\tests.exe

IF EXIST install\tests\%BUILD_MODE% (
    rmdir /S /Q install\tests\%BUILD_MODE%
)

mkdir install\tests\%BUILD_MODE%

REM Moving test binary
copy /B /Y build\tests\%BUILD_MODE%\tests.exe install\tests\%BUILD_MODE%
copy /B /Y %LIBSDL_PATH%\bin\SDL2.dll install\tests\%BUILD_MODE%

echo.
echo ======= RUNNING TESTS =======
echo.
install\tests\%BUILD_MODE%\tests.exe --color always