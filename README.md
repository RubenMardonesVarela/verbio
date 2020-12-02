# VERBIO TEST

Executable that takes a string as a paramter and prints the same string, but converting the words that represents numbers in digits.


Compilation
-------------

The build sytem is cmake. It has been compiled and tested under linux distribution, but it could also be compiled and run under windows. To buid it with the make: 

mkdir build

cd build

cmake ..

cmake --build

Run Application
-----------------

cd build/src

./verbio_run "your paragraph" (the paragraph must be passed as parameter in quotes)

Run unit test
-------------------

There are some unit tests that can be run to test different cases

cd build/test

./verbio_test
