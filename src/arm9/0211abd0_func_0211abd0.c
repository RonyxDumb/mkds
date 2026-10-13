/* Decompiled C draft; module arm9; ROM address 0211abd0. No matching claim. */
#include "types.h"
#include "deps/0211abd0_func_0211abd0.h"

void func_0211abd0(void)

{
  int iVar1;
  
  iVar1 = func_021277ac();
  if (iVar1 != 0) {
    iVar1 = func_02127794();
    if (iVar1 != -1) {
      if (iVar1 == 0) {
        func_0211b9d8();
        *(undefined4 *)(*piRam0211ac20 + 0xb8) = 1;
        func_0202b7c0(3);
        func_021282c8();
        return;
      }
      if (iVar1 != 1) {
        return;
      }
    }
    func_0211ba98();
  }
  return;
}

