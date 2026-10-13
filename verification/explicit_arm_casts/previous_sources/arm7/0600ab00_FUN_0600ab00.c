/* Decompiled C draft; module arm7; ROM address 0600ab00. No matching claim. */
#include "types.h"
#include "deps/0600ab00_FUN_0600ab00.h"

undefined4 FUN_0600ab00(uint param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = *(uint *)(DAT_0600aba8 & 0xfffffffc) >> (DAT_0600aba8 & 3) * 8 |
          *(uint *)(DAT_0600aba8 & 0xfffffffc) << (DAT_0600aba8 & 3) * -8 + 0x20;
  if (param_1 < 0x81) {
    if (param_1 != 0) {
      if ((*(ushort *)(uVar1 + 0x3e6) & 1) == 0) {
        uVar3 = uVar1 + 0x3e0 & 3;
        uVar4 = *(uint *)(uVar1 + 0x3e0 & 0xfffffffc);
        thunk_FUN_037fb230(param_2,uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20,param_1 + 1);
      }
      else {
        uVar3 = uVar1 + 0x3e0 & 3;
        uVar4 = *(uint *)(uVar1 + 0x3e0 & 0xfffffffc);
        uVar4 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
        FUN_060096e4(uVar4,0xff);
        for (uVar3 = 0; uVar4 = uVar4 + 1, uVar3 < param_1; uVar3 = uVar3 + 1) {
          uVar2 = FUN_060096c4(param_2);
          FUN_060096e4(uVar4,uVar2);
          param_2 = param_2 + 1;
        }
      }
    }
    *(short *)(uVar1 + 0x3e4) = (short)param_1;
    *(undefined2 *)(uVar1 + 1000) = 1;
    uVar2 = 0;
  }
  else {
    uVar2 = 4;
  }
  return uVar2;
}

