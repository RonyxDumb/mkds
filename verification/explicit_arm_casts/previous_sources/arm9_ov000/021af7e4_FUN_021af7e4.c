/* Decompiled C draft; module arm9_ov000; ROM address 021af7e4. No matching claim. */
#include "types.h"
#include "deps/021af7e4_FUN_021af7e4.h"

void FUN_021af7e4(undefined4 param_1,undefined4 param_2,int param_3)

{
  short sVar1;
  short *psVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = *(int *)(param_3 + 0x4c);
  *(undefined2 *)(iVar6 + 0x22) = 8;
  *(short *)(iVar6 + 0x26) = (short)*(undefined4 *)(DAT_021af850 + 4);
  *(undefined2 *)(iVar6 + 0x24) = 0;
  psVar2 = DAT_021af854;
  sVar1 = *DAT_021af854;
  *(short *)(param_3 + 10) = sVar1;
  *psVar2 = *psVar2 + 1;
  *(short *)(iVar6 + 0x28) = sVar1;
  uVar4 = FUN_021b01b4(iVar6 + 0x22,8,0);
  uVar3 = FUN_021b01b4(param_1,param_2,uVar4);
  iVar5 = FUN_021b01a0(uVar3);
  *(ushort *)(iVar6 + 0x24) = (ushort)((uint)iVar5 >> 8) | (ushort)(iVar5 << 8);
  FUN_021af858(iVar6 + 0x22,8,param_1,param_2,*(undefined4 *)(param_3 + 0x1c),1);
  return;
}

