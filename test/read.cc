#include "G4STL.hh"


int main(int argc, char * argv[])
{
        if (argc < 2) {
                G4cerr << "error: missing STL file" << G4endl;
                exit(EXIT_FAILURE);
        }

        G4STL stl;
        stl.SetVerbosity(1);

        G4TessellatedSolid * solid = stl.Read(argv[1]);
        solid->DisplayAllocatedMemory();
        delete solid;

        exit(EXIT_SUCCESS);
}
