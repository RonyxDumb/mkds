/* Decompiled C draft; module arm9; ROM address 0204fcec. No matching claim. */
#include "types.h"
#include "deps/0204fcec_func_0204fcec.h"

undefined4 func_0204fcec(uint param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar1 = *(uint *)(uRam0204fe14 & 0xfffffffc) >> (uRam0204fe14 & 3) * 8 |
          *(uint *)(uRam0204fe14 & 0xfffffffc) << (uRam0204fe14 & 3) * -8 + 0x20;
  uVar4 = 0;
  if (uVar1 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
            *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
  }
  if (uVar3 == 1) {
    uVar4 = 0;
    if ((*(ushort *)(uVar1 + 0x454) & 0x40) == 0) {
      if (((uint)*(byte *)(uVar1 + 0x87) & 1 << (param_1 & 0xff)) != 0) {
        if (param_2 != 0) {
          Mem_CpuCopy8(param_1 * 0x22c + uVar1 + iRam0204fe18,param_2,0x14);
        }
        uVar4 = 1;
      }
    }
    else {
      iVar2 = func_02007e38(param_1);
      if ((((uint)*(byte *)((*(uint *)(uRam0204fe14 & 0xfffffffc) >> (uRam0204fe14 & 3) * 8 |
                            *(uint *)(uRam0204fe14 & 0xfffffffc) << (uRam0204fe14 & 3) * -8 + 0x20)
                           + 0x1696) & 1 << (param_1 & 0xff)) != 0) && (iVar2 != 0)) {
        if (param_2 != 0) {
          Mem_CpuCopy8(iVar2 + 2,param_2,0x14);
        }
        uVar4 = 1;
      }
    }
  }
  else if ((uVar3 == 2) &&
          (uVar4 = 0, ((uint)*(byte *)(uVar1 + 0x43d) & 1 << (param_1 & 0xff)) != 0)) {
    if (param_2 != 0) {
      Mem_CpuCopy8(param_1 * 0x22c + uVar1 + iRam0204fe18,param_2,0x14);
    }
    uVar4 = 1;
  }
  return uVar4;
}

