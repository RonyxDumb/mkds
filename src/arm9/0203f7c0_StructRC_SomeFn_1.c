/* Decompiled C draft; module arm9; ROM address 0203f7c0. No matching claim. */
#include "types.h"
#include "deps/0203f7c0_StructRC_SomeFn_1.h"

int StructRC_SomeFn_1(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,
                     int param_5,int param_6)

{
  uint uVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = (*(uint *)(uRam0203f918 & 0xfffffffc) >> (uRam0203f918 & 3) * 8 |
          *(uint *)(uRam0203f918 & 0xfffffffc) << (uRam0203f918 & 3) * -8 + 0x20) + 0x44;
  uVar1 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  sVar2 = *(short *)(param_5 * 0x24 + (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + 0x1e);
  iVar3 = DriverStatus_SomeFn_0();
  if (iVar3 != 0) {
    return (int)(short)param_5;
  }
  if (param_6 != 0) {
    iVar3 = -1;
    if (sVar2 == -1) {
      iVar3 = StructRC_SomeFn_1(param_1,param_2,param_3,param_4);
      return iVar3;
    }
    iVar4 = 0;
    uVar5 = (*(uint *)(uRam0203f918 & 0xfffffffc) >> (uRam0203f918 & 3) * 8 |
            *(uint *)(uRam0203f918 & 0xfffffffc) << (uRam0203f918 & 3) * -8 + 0x20) + 0x4c;
    uVar1 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    do {
      if (*(char *)(param_4 * 0xc + (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + iVar4 + 7)
          != -1) {
        iVar3 = StructRC_SomeFn_1(param_1,param_2,param_3);
        if (iVar3 != -1) {
          return iVar3;
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 3);
    return iVar3;
  }
  return -1;
}

