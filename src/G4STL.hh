#pragma once
#include "globals.hh"
#include "G4SystemOfUnits.hh"
#include "G4TessellatedSolid.hh"


class G4STL {
  public:
        G4STL(const G4double & unit=CLHEP::mm): fUnit(unit), fVerbosity(0) {}

        G4double GetUnit() { return fUnit; }
        void SetUnit(const G4double & unit) { fUnit = unit; }

        G4int GetVerbosity() { return fVerbosity; }
        void SetVerbosity(const G4int & verbosity) { fVerbosity = verbosity; }

        G4TessellatedSolid * Read(
            const G4String & path, const G4String & name="");

  private:
        G4double fUnit;
        G4int fVerbosity;
};
