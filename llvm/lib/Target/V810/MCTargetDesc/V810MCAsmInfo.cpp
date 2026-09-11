#include "V810.h"
#include "V810MCAsmInfo.h"
#include "V810MCExpr.h"
#include "llvm/MC/MCExpr.h"

using namespace llvm;

void V810AsmInfo::anchor() {}

V810AsmInfo::V810AsmInfo(const Triple &TheTriple,
                         const MCTargetOptions &Options)
    : MCAsmInfoELF(Options) {
  CodePointerSize = 4;
  MinInstAlignment = 2;
  MaxInstLength = 4;
  IsLittleEndian = true;
  SupportsDebugInformation = true;
  UsesCFIWithoutEH = true;
}

void V810AsmInfo::printSpecifierExpr(raw_ostream &OS, const MCSpecifierExpr &S) const {
  bool parens = V810MCExpr::printSpecifier(OS, S.getSpecifier());

  if (parens) OS << '(';
  printExpr(OS, *S.getSubExpr());
  if (parens) OS << ')';
}
