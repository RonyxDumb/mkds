/* Decompiled C draft; module arm9_ov001; ROM address 0218e38c. No matching claim. */
#include "types.h"
#include "deps/0218e38c_FUN_0218e38c.h"

void FUN_0218e38c(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined8 uVar5;
  
  iVar1 = -*(int *)(*(int *)(param_1 + 0xa0) + 0x24);
  iVar4 = (int)*(short *)(DAT_0218e450 + ((int)(uint)*(ushort *)(param_2 + DAT_0218e44c) >> 4) * 4);
  uVar5 = func_0x02133048(iVar1,iVar1 >> 0x1f,iVar4,iVar4 >> 0x1f);
  *(uint *)(param_1 + 0x10) = (uint)uVar5 >> 0xc | (int)((ulonglong)uVar5 >> 0x20) << 0x14;
  *(undefined4 *)(param_1 + 0x14) = 0;
  iVar1 = -*(int *)(*(int *)(param_1 + 0xa0) + 0x24);
  iVar4 = (int)*(short *)(DAT_0218e450 +
                         (((int)(uint)*(ushort *)(param_2 + DAT_0218e44c) >> 4) * 2 + 1) * 2);
  uVar5 = func_0x02133048(iVar1,iVar1 >> 0x1f,iVar4,iVar4 >> 0x1f);
  *(uint *)(param_1 + 0x18) = (uint)uVar5 >> 0xc | (int)((ulonglong)uVar5 >> 0x20) << 0x14;
  FUN_021829ac(*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218e454));
  FUN_0218ead0(param_1);
  *(undefined4 *)(param_1 + DAT_0218e458) = 0;
  FUN_02188200(param_1,DAT_0218e45c);
  FUN_0218e860(param_1);
  *(undefined4 *)(param_1 + 0xa8) = 0;
  func_0x020d2774(param_1,DAT_0218e460);
  puVar2 = (undefined4 *)(param_1 + DAT_0218e464);
  *puVar2 = *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xc);
  puVar3 = (undefined4 *)(param_1 + DAT_0218e468);
  *puVar3 = *puVar2;
  puVar2 = (undefined4 *)(param_1 + DAT_0218e46c);
  *puVar2 = *puVar3;
  *(undefined4 *)(param_1 + DAT_0218e470) = *puVar2;
  return;
}

