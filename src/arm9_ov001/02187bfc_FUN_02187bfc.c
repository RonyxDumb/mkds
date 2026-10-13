/* Decompiled C draft; module arm9_ov001; ROM address 02187bfc. No matching claim. */
#include "types.h"
#include "deps/02187bfc_FUN_02187bfc.h"

void FUN_02187bfc(int param_1,int param_2)

{
  if (*(int *)(param_1 + DAT_02187c44) != 0) {
    if (*(int *)(*(int *)(param_1 + DAT_02187c44) + 0x54) < DAT_02187c48) {
      func_0x020fd494();
      return;
    }
    if (param_2 != 0) {
      func_0x020fd540();
      return;
    }
    func_0x020fd540();
  }
  return;
}

