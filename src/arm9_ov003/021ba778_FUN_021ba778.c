/* Decompiled C draft; module arm9_ov003; ROM address 021ba778. No matching claim. */
#include "types.h"
#include "deps/021ba778_FUN_021ba778.h"

void FUN_021ba778(int param_1,uint *param_2)

{
  ushort uVar1;
  ushort *puVar2;
  uint uVar3;
  int iVar4;
  
  *param_2 = (uint)*(ushort *)(param_1 + 10);
  func_0x0214cffc(param_1 + 0xc,(int)(uintptr_t)(param_2 + 1),0x20);
  param_2[9] = (uint)*(ushort *)(param_1 + 0x36);
  func_0x0214cffc(param_1 + 4,(int)(uintptr_t)(param_2 + 0xc),6);
  uVar3 = 0;
  iVar4 = 0;
  puVar2 = DAT_021ba814;
  do {
    if ((*(ushort *)(param_1 + 0x30) & *puVar2) != 0) {
      *(char *)((int)param_2 + uVar3 + 0x3c) = (char)puVar2[1];
      if ((*(ushort *)(param_1 + 0x2e) & *puVar2) != 0) {
        *(byte *)((int)param_2 + uVar3 + 0x3c) = *(byte *)((int)param_2 + uVar3 + 0x3c) | 0x80;
      }
      uVar3 = uVar3 + 1;
    }
    puVar2 = puVar2 + 2;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0xc);
  param_2[0xe] = uVar3;
  param_2[0x13] = (uint)*(ushort *)(param_1 + 0x32);
  uVar1 = *(ushort *)(param_1 + 0x2c) & 3;
  if (uVar1 == 1) {
    param_2[0x14] = 1;
    return;
  }
  if (uVar1 == 2) {
    param_2[0x14] = 2;
    return;
  }
  param_2[0x14] = 0;
  return;
}

