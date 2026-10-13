/* Decompiled C draft; module arm9; ROM address 0211ac24. No matching claim. */
#include "types.h"
#include "deps/0211ac24_func_0211ac24.h"

void func_0211ac24(void)

{
  int iVar1;
  
  iVar1 = func_02127788();
  if (iVar1 != 0) {
    func_0211b9ec();
    iVar1 = func_02127794();
    if (iVar1 != -1) {
      if (iVar1 == 0) {
        NNSi_MaybeSndPlayerStartSeq(uRam0211ac6c,0,7);
        return;
      }
      if (iVar1 != 1) {
        return;
      }
    }
    NNSi_MaybeSndPlayerStartSeq(uRam0211ac6c,0,0x10);
  }
  return;
}

