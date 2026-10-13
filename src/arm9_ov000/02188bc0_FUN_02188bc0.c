/* Decompiled C draft; module arm9_ov000; ROM address 02188bc0. No matching claim. */
#include "types.h"
#include "deps/02188bc0_FUN_02188bc0.h"

uint FUN_02188bc0(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  if ((*(short *)(param_1 + 10) != 0x20) || (uVar2 = FUN_02188c1c(), (int)uVar2 < 1)) {
    iVar4 = 0;
    if (0 < param_2) {
      uVar1 = *(ushort *)(param_1 + 10);
      do {
        if (((uVar1 & 0xff) == (ushort)*(byte *)(param_3 + 3)) &&
           (iVar3 = func_0x0213a038(param_1 + 0xc,param_3 + 4,uVar1), iVar3 == 0)) {
          return (uint)*(byte *)(param_3 + 1);
        }
        param_3 = param_3 + 0x24;
        iVar4 = iVar4 + 1;
      } while (iVar4 < param_2);
    }
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

