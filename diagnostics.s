# RUN: not llvm-mc %s -arch=v810 -filetype=obj -o /dev/null 2>&1 | FileCheck %s

target:
    .rept  16777217
    nop
    .endr
    jr target