/* Decompiled C draft; module arm9_ov000; ROM address 0218cef4. No matching claim. */
#include "types.h"
#include "deps/0218cef4_FUN_0218cef4.h"

undefined4 FUN_0218cef4(char *param_1)

{
  char cVar1;
  undefined4 extraout_r1;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0;
  cVar1 = *param_1;
  while (uVar3 = (uint)cVar1, uVar3 != 0) {
    if ((-1 < (int)uVar3) && ((int)uVar3 < 0x80)) {
      uVar3 = (uint)*(byte *)(DAT_0218cf28 + uVar3);
    }
    iVar2 = DAT_0218cf2c * iVar2 + uVar3;
    param_1 = param_1 + 1;
    cVar1 = *param_1;
  }
  func_0x02133274(iVar2);
  return extraout_r1;
}

