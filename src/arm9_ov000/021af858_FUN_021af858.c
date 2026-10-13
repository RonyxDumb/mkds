/* Decompiled C draft; module arm9_ov000; ROM address 021af858. No matching claim. */
#include "types.h"
#include "deps/021af858_FUN_021af858.h"

void FUN_021af858(int param_1,uint param_2,int param_3,uint param_4,uint param_5,undefined1 param_6)

{
  ushort *puVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 local_1c;
  
  *(undefined1 *)(param_1 + -0x14) = 0x45;
  uVar3 = 0;
  *(undefined1 *)(param_1 + -0x13) = 0;
  puVar1 = DAT_021af9c0;
  *DAT_021af9c0 = *DAT_021af9c0 + 1;
  *(ushort *)(param_1 + -0x10) = *puVar1 >> 8 | *puVar1 << 8;
  *(undefined1 *)(param_1 + -0xc) = 0x80;
  *(undefined1 *)(param_1 + -0xb) = param_6;
  puVar2 = DAT_021af9c4;
  *(ushort *)(param_1 + -8) =
       (ushort)(byte)(*DAT_021af9c4 >> 0x18) | (ushort)((*DAT_021af9c4 >> 0x10) << 8);
  *(ushort *)(param_1 + -6) = (ushort)((*puVar2 & 0xffff) >> 8) | (ushort)((*puVar2 & 0xffff) << 8);
  *(ushort *)(param_1 + -4) = (ushort)(byte)(param_5 >> 0x18) | (ushort)((param_5 >> 0x10) << 8);
  *(ushort *)(param_1 + -2) = (ushort)((param_5 & 0xffff) >> 8) | (ushort)((param_5 & 0xffff) << 8);
  if (DAT_021af9c8 < param_2) {
    iVar4 = param_1;
    if (DAT_021af9c8 < param_2) {
      do {
        FUN_021af9d0(param_1,0,iVar4,DAT_021af9c8,param_5,uVar3 | DAT_021af9cc);
        iVar4 = iVar4 + DAT_021af9c8;
        param_2 = param_2 - DAT_021af9c8;
        uVar3 = uVar3 + 0xb9 & 0xffff;
      } while (DAT_021af9c8 < param_2);
    }
    if (param_2 != 0) {
      if (param_4 == 0) {
        FUN_021af9d0(param_1,0,iVar4,param_2,param_5,uVar3);
      }
      else {
        FUN_021af9d0(param_1,0,iVar4,param_2,param_5,uVar3 | DAT_021af9cc);
      }
      uVar3 = uVar3 + (param_2 >> 3) & 0xffff;
      param_2 = 0;
    }
  }
  local_1c = param_3;
  if (DAT_021af9c8 < param_2 + param_4) {
    do {
      iVar4 = DAT_021af9c8 - param_2;
      FUN_021af9d0(param_1,param_2,local_1c,iVar4,param_5,uVar3 | DAT_021af9cc);
      local_1c = local_1c + iVar4;
      param_4 = param_4 - iVar4;
      uVar3 = uVar3 + 0xb9 & 0xffff;
      param_2 = 0;
    } while (DAT_021af9c8 < param_4);
  }
  if (param_2 + param_4 != 0) {
    FUN_021af9d0(param_1,param_2,local_1c,param_4,param_5,uVar3);
  }
  return;
}

