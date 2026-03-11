# Project: Vidar

## Build and test instructions

Configure
```
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
```
Build
```
cmake --build build
```
Run all tests
```
ctest --test-dir build --output-on-failure
```

### Optional:

List discovered tests
```
ctest --test-dir build -N
```

Run a single test by name pattern
```
ctest --test-dir build -R VidarUpdateTest --output-on-failure
```