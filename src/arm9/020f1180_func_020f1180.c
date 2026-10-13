/* Decompiled C draft; module arm9; ROM address 020f1180. No matching claim. */
#include "types.h"
#include "deps/020f1180_func_020f1180.h"

bool func_020f1180(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  int iVar2;
  ushort uVar3;
  int iVar4;
  
  iVar4 = 0;
  uVar3 = (ushort)*(byte *)((*(uint *)(uRam020f11ec & 0xfffffffc) >> (uRam020f11ec & 3) * 8 |
                            *(uint *)(uRam020f11ec & 0xfffffffc) << (uRam020f11ec & 3) * -8 + 0x20)
                           + 0x3d0);
  uVar1 = 0;
  if (uVar3 != 0) {
    do {
      iVar2 = func_020f1258(param_1,uVar1,iVar4,param_2);
      if (iVar2 != 0) {
        iVar4 = iVar2;
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < uVar3);
  }
  return iVar4 != 0;
}

