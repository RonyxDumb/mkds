/* Decompiled C draft; module arm9; ROM address 021177c0. No matching claim. */
#include "types.h"
#include "deps/021177c0_func_021177c0.h"

void func_021177c0(void)

{
  int iVar1;
  
  func_02118414();
  iVar1 = func_021277ac();
  if (iVar1 != 0) {
    iVar1 = func_02127794();
    if (iVar1 != -1) {
      if (iVar1 == 0) {
        func_021185ec();
        *(undefined4 *)(*piRam02117810 + 0x88) = 1;
        func_02118024();
        func_021282c8();
        return;
      }
      if (iVar1 != 1) {
        return;
      }
    }
    func_021181b8();
  }
  return;
}

