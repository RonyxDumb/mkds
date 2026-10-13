/* Decompiled C draft; module arm9_ov001; ROM address 0218cbdc. No matching claim. */
#include "types.h"
#include "deps/0218cbdc_FUN_0218cbdc.h"

void FUN_0218cbdc(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined8 uVar5;
  
  if (*(int *)(param_2 + DAT_0218cd48) == 1) {
    if (*(int *)(param_1 + DAT_0218cd4c) < 1) {
      uVar4 = *(uint *)(param_1 + DAT_0218cd54);
      iVar1 = func_0x02148714(*(int *)(param_2 + 0x80) - *(int *)(param_1 + 4),
                              *(int *)(param_2 + 0x88) - *(int *)(param_1 + 0xc));
      uVar2 = iVar1 - uVar4 & 0xffff;
      if (DAT_0218cd58 < (int)uVar2) {
        uVar2 = uVar2 - DAT_0218cd5c;
      }
      if ((int)uVar2 < 1) {
        iVar1 = *(int *)(*(int *)(param_1 + 0xa0) + 0xfc);
        iVar3 = (int)*(short *)(DAT_0218cd64 + ((int)((uVar4 & 0xffff) - DAT_0218cd60) >> 4) * 4);
        uVar5 = func_0x02133048(iVar1,iVar1 >> 0x1f,iVar3,iVar3 >> 0x1f);
        *(uint *)(param_1 + 0x10) = (uint)uVar5 >> 0xc | (int)((ulonglong)uVar5 >> 0x20) << 0x14;
        *(undefined4 *)(param_1 + 0x14) = 0;
        iVar1 = *(int *)(*(int *)(param_1 + 0xa0) + 0xfc);
        iVar3 = (int)*(short *)(DAT_0218cd64 +
                               (((int)((*(uint *)(param_1 + DAT_0218cd54) & 0xffff) - DAT_0218cd60)
                                >> 4) * 2 + 1) * 2);
        uVar5 = func_0x02133048(iVar1,iVar1 >> 0x1f,iVar3,iVar3 >> 0x1f);
        *(uint *)(param_1 + 0x18) = (uint)uVar5 >> 0xc | (int)((ulonglong)uVar5 >> 0x20) << 0x14;
      }
      else {
        iVar1 = *(int *)(*(int *)(param_1 + 0xa0) + 0xfc);
        iVar3 = (int)*(short *)(DAT_0218cd64 + ((int)((uVar4 & 0xffff) + DAT_0218cd60) >> 4) * 4);
        uVar5 = func_0x02133048(iVar1,iVar1 >> 0x1f,iVar3,iVar3 >> 0x1f);
        *(uint *)(param_1 + 0x10) = (uint)uVar5 >> 0xc | (int)((ulonglong)uVar5 >> 0x20) << 0x14;
        *(undefined4 *)(param_1 + 0x14) = 0;
        iVar1 = *(int *)(*(int *)(param_1 + 0xa0) + 0xfc);
        iVar3 = (int)*(short *)(DAT_0218cd64 +
                               (((int)((*(uint *)(param_1 + DAT_0218cd54) & 0xffff) + DAT_0218cd60)
                                >> 4) * 2 + 1) * 2);
        uVar5 = func_0x02133048(iVar1,iVar1 >> 0x1f,iVar3,iVar3 >> 0x1f);
        *(uint *)(param_1 + 0x18) = (uint)uVar5 >> 0xc | (int)((ulonglong)uVar5 >> 0x20) << 0x14;
      }
      *(undefined4 *)(param_1 + DAT_0218cd50) = 0xc;
      func_0x02073fb0(*(uint *)(param_1 + 0x78) & DAT_0218cd68,DAT_0218cd6c);
      *(uint *)(param_1 + 0x78) = *(uint *)(param_1 + 0x78) | *DAT_0218cd70;
      func_0x020d26ec(param_2,DAT_0218cd74);
    }
    else {
      *(undefined4 *)(param_1 + DAT_0218cd50) = 0xc;
    }
  }
  else {
    *(undefined4 *)(param_1 + DAT_0218cd50) = 10;
    func_0x02073fb0(*(uint *)(param_1 + 0x78) & DAT_0218cd68,DAT_0218cd6c);
    *(uint *)(param_1 + 0x78) = *(uint *)(param_1 + 0x78) | *DAT_0218cd70;
    func_0x020d26ec(param_2,DAT_0218cd78);
  }
  FUN_02188200(param_1,DAT_0218cd7c);
  return;
}

