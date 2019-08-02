# G4STL
_Import binary STL files in Geant4_


This is a Work In Progess. Currently the `Read` functionality is only
implemented for binary STL files. Basic usage is the following:
```
#include "G4STL.hh"
...
{
        G4STL stl;
        G4TessellatedSolid * solid = stl.Read("/path/to/file.stl");
}
```

## Installation

The `G4STL` library and the [test program](test/read.cc) can be compiled with
CMake using the provided [`CMakeLists.txt`](CMakeLists.txt), e.g. as:

```
cd geant-stl
mkdir -p build && cd build
cmake ..
make install
```

The default installation is done to the source directory, i.e. `geant-stl` in
the previous example.
