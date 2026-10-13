/* Decompiled C draft; module arm9_ov001; ROM address 0218dadc. No matching claim. */
#include "types.h"
#include "deps/0218dadc_FUN_0218dadc.h"

void FUN_0218dadc(int param_1)

{
  int iVar1;
  int iVar2;
  int unaff_r5;
  int iVar3;
  undefined8 uVar4;
  
  iVar3 = *(int *)(param_1 + 0xa4);
  switch(*(undefined4 *)(param_1 + 0xa8)) {
  case 1:
    unaff_r5 = *(int *)(*(int *)(param_1 + 0xa0) + 0xc0);
    break;
  case 2:
    unaff_r5 = *(int *)(*(int *)(param_1 + 0xa0) + 0xc4);
    break;
  case 3:
    unaff_r5 = *(int *)(*(int *)(param_1 + 0xa0) + 200);
    break;
  case 4:
    unaff_r5 = *(int *)(*(int *)(param_1 + 0xa0) + 0xcc);
  }
  iVar1 = (int)(*(int *)(iVar3 + DAT_0218db9c) + DAT_0218dba0 & 0xffffU) >> 4;
  iVar2 = (int)*(short *)(DAT_0218dba4 + iVar1 * 4);
  uVar4 = func_0x02133048(unaff_r5,unaff_r5 >> 0x1f,iVar2,iVar2 >> 0x1f);
  *(uint *)(param_1 + 4) =
       *(int *)(iVar3 + 4) + ((uint)uVar4 >> 0xc | (int)((ulonglong)uVar4 >> 0x20) << 0x14);
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(*(int *)(param_1 + 0xa4) + 8);
  iVar3 = (int)*(short *)(DAT_0218dba4 + (iVar1 * 2 + 1) * 2);
  uVar4 = func_0x02133048(unaff_r5,unaff_r5 >> 0x1f,iVar3,iVar3 >> 0x1f);
  *(uint *)(param_1 + 0xc) =
       *(int *)(*(int *)(param_1 + 0xa4) + 0xc) +
       ((uint)uVar4 >> 0xc | (int)((ulonglong)uVar4 >> 0x20) << 0x14);
  return;
}

