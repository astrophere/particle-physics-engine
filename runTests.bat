g++ -std=c++17 ^
 -Igoogletest/googletest/include ^
 -Igoogletest/googletest ^
 src/vector3D.cpp ^
 tests/test_vector3d.cpp ^
 googletest/googletest/src/gtest-all.cc ^
 -o runTests.exe

runTests.exe --gtest_output=xml:test_results.xml > test_output.log