/* Decompiled C draft; module arm9_ov000; ROM address 0219fdc8. No matching claim. */
#include "types.h"
#include "deps/0219fdc8_FUN_0219fdc8.h"

undefined4 FUN_0219fdc8(undefined4 param_1,int param_2)

{
  int *piVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined8 uVar6;
  uint local_20;
  undefined4 local_1c;
  uint local_18;
  
  piVar1 = DAT_0219feb8;
  if (param_2 != 0) {
    *(undefined4 *)(*DAT_0219feb8 + DAT_0219febc) = 1;
    iVar5 = *piVar1;
    uVar6 = func_0x0200f5ac();
    *(int *)(iVar5 + DAT_0219fec0) = (int)uVar6;
    *(int *)(iVar5 + DAT_0219fec4) = (int)((ulonglong)uVar6 >> 0x20);
    *(undefined4 *)(iVar5 + 0xf4) = param_1;
    return 0;
  }
  iVar5 = *DAT_0219feb8;
  if (*(char *)(iVar5 + 0x15) == '\0') {
    uVar3 = FUN_0218b480(*(undefined4 *)(iVar5 + 0xe4),0);
    uVar4 = FUN_0218b2a8(uVar3,DAT_0219fec8,0);
    *(undefined4 *)(*DAT_0219feb8 + 0xf4) = uVar4;
    uVar4 = FUN_0218b27c(uVar3);
    *(undefined4 *)(*DAT_0219feb8 + 0x24) = uVar4;
    uVar2 = FUN_0218b260(uVar3);
    piVar1 = DAT_0219feb8;
    *(undefined2 *)(*DAT_0219feb8 + 0xa4) = uVar2;
    *(undefined4 *)(*piVar1 + DAT_0219fecc) = *(undefined4 *)(*piVar1 + 0xf4);
    uVar3 = 1;
  }
  else {
    if (*(char *)(iVar5 + 0x15) == '\x01') {
      *(undefined4 *)(iVar5 + 0xf4) = param_1;
    }
    piVar1 = DAT_0219feb8;
    *(undefined4 *)(*DAT_0219feb8 + DAT_0219fecc) = param_1;
    local_1c = *(undefined4 *)(*piVar1 + 0x1c);
    local_18 = (uint)*(ushort *)(*piVar1 + 0x1a);
    uVar3 = 3;
  }
  piVar1 = DAT_0219feb8;
  *(undefined4 *)(*DAT_0219feb8 + DAT_0219fed4) = DAT_0219fed0;
  iVar5 = *piVar1;
  uVar6 = func_0x0200f5ac();
  *(int *)(iVar5 + DAT_0219fed8) = (int)uVar6;
  *(int *)(iVar5 + DAT_0219fedc) = (int)((ulonglong)uVar6 >> 0x20);
  *(undefined4 *)(iVar5 + DAT_0219febc) = 0;
  if (*(int *)(*DAT_0219feb8 + DAT_0219fee0) == 0) {
    uVar4 = 1;
  }
  else {
    uVar4 = 0xb;
  }
  iVar5 = *DAT_0219feb8;
  local_20 = (uint)*(byte *)(iVar5 + 0x15);
  uVar3 = FUN_021a0ae8(uVar4,param_1,*(undefined4 *)(iVar5 + 0x24),*(undefined2 *)(iVar5 + 0xa4),
                       &local_20,uVar3);
  return uVar3;
}

