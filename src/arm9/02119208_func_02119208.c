/* Decompiled C draft; module arm9; ROM address 02119208. No matching claim. */
#include "types.h"
#include "deps/02119208_func_02119208.h"

void func_02119208(void)

{
  int iVar1;
  
  iVar1 = func_02127788();
  if (iVar1 != 0) {
    func_02119a38();
    if (*psRam02119258 == 2) {
      iVar1 = func_02127794();
      if (iVar1 != -1) {
        if (iVar1 == 0) {
          NNSi_MaybeSndPlayerStartSeq(uRam0211925c,0,7);
          return;
        }
        if (iVar1 != 1) {
          return;
        }
      }
      NNSi_MaybeSndPlayerStartSeq(uRam0211925c,0,0x10);
    }
  }
  return;
}

