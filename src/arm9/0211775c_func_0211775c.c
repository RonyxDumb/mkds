/* Decompiled C draft; module arm9; ROM address 0211775c. No matching claim. */
#include "types.h"
#include "deps/0211775c_func_0211775c.h"

void func_0211775c(void)

{
  int iVar1;
  
  func_02118414();
  iVar1 = func_02127788();
  if (iVar1 != 0) {
    func_02118038();
    if ((((*psRam0211779c == 2) && (iVar1 = func_02127794(), iVar1 != -1)) && (iVar1 != 0)) &&
       (iVar1 == 1)) {
      NNSi_MaybeSndPlayerStartSeq(uRam021177a0,0,0xf);
    }
  }
  return;
}

