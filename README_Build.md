# Building/Testing
Currently we only support Bazel and expect/use C++17.
	```
1. Build the library Eventuals with:
```
bazel build :eventuals
```
After the running command above the new directory "bazel-bin" in your project folder is created which includes eventuals.lib.

2. Build the tests with:
```
bazel build test:eventuals
```
Build and run the tests with:
```
bazel test test:eventuals
```