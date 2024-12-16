set -e

cd "/c/git курсач/calculator/Task 2/build"
/usr/bin/cmake.exe --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
