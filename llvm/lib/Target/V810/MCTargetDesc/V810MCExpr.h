#ifndef LLVM_LIB_TARGET_V810_MCTARGETDESC_V810MCEXPR_H
#define LLVM_LIB_TARGET_V810_MCTARGETDESC_V810MCEXPR_H

#include "V810FixupKinds.h"
#include "llvm/MC/MCExpr.h"

namespace llvm {

class V810MCExpr : public MCSpecifierExpr {
public:
  using Specifier = Spec;

private:
  explicit V810MCExpr(Specifier S, const MCExpr *Expr)
    : MCSpecifierExpr(Expr, S, Expr->getLoc()) {}

public:
  static const V810MCExpr *create(Specifier Kind, const MCExpr *Expr,
                                MCContext &Ctx);

  V810::Fixups getFixupKind() const { return getFixupKind(getSpecifier()); }

  static bool printSpecifier(raw_ostream &OS, Specifier S);
  static V810::Fixups getFixupKind(Specifier S);
};

} // end namespace llvm

#endif