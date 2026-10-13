/* Decompiled C draft; module arm9_ov000; ROM address 021af70c. No matching claim. */
#include "types.h"
#include "deps/021af70c_FUN_021af70c.h"

void FUN_021af70c(undefined4 param_1,int param_2,int param_3)

{
  uint *puVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  puVar1 = DAT_021af7dc;
  iVar5 = *(int *)(param_3 + 0x4c);
  *(ushort *)(iVar5 + 0x16) =
       (ushort)(byte)(*DAT_021af7dc >> 0x18) | (ushort)((*DAT_021af7dc >> 0x10) << 8);
  *(ushort *)(iVar5 + 0x18) = (ushort)((*puVar1 & 0xffff) >> 8) | (ushort)((*puVar1 & 0xffff) << 8);
  *(ushort *)(iVar5 + 0x1a) =
       (ushort)(byte)(*(uint *)(param_3 + 0x1c) >> 0x18) |
       (ushort)((*(uint *)(param_3 + 0x1c) >> 0x10) << 8);
  uVar6 = *(uint *)(param_3 + 0x1c) & 0xffff;
  *(ushort *)(iVar5 + 0x1c) = (ushort)(uVar6 >> 8) | (ushort)(uVar6 << 8);
  *(short *)(iVar5 + 0x1e) = (short)DAT_021af7e0;
  uVar6 = param_2 + 8U & 0xffff;
  *(ushort *)(iVar5 + 0x26) = (ushort)(uVar6 >> 8) | (ushort)(uVar6 << 8);
  *(undefined2 *)(iVar5 + 0x20) = *(undefined2 *)(iVar5 + 0x26);
  *(ushort *)(iVar5 + 0x24) = *(ushort *)(param_3 + 0x18) >> 8 | *(ushort *)(param_3 + 0x18) << 8;
  *(ushort *)(iVar5 + 0x22) = *(ushort *)(param_3 + 10) >> 8 | *(ushort *)(param_3 + 10) << 8;
  *(undefined2 *)(iVar5 + 0x28) = 0;
  uVar3 = FUN_021b01b4(iVar5 + 0x16,0x14);
  uVar2 = FUN_021b01b4(param_1,param_2,uVar3);
  iVar4 = FUN_021b01a0(uVar2);
  *(ushort *)(iVar5 + 0x28) = (ushort)((uint)iVar4 >> 8) | (ushort)(iVar4 << 8);
  FUN_021af858(iVar5 + 0x22,8,param_1,param_2,*(undefined4 *)(param_3 + 0x1c),0x11);
  return;
}

