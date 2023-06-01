# Project

See Canvas for lab details.

```bash
cmake -B build
cmake --build build
./build/MyProject # or .\build\Debug\MyProject.exe
./build/tests # or .\build\Debug\tests.exe
```

For faster builds:
```bash
cmake --build build -j 4 # recommended to put number of cores here
```
