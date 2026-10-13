/* Decompiled C draft; module arm9_ov000; ROM address 021ae3f0. No matching claim. */
#include "types.h"
#include "deps/021ae3f0_FUN_021ae3f0.h"

void FUN_021ae3f0(byte *param_1,uint param_2)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  int local_18 [2];
  
  uVar4 = ((int)(uint)*(ushort *)(param_1 + 0x10) >> 8 | (*(ushort *)(param_1 + 0x10) & 0xff) << 8)
          << 0x10 | (int)(uint)*(ushort *)(param_1 + 0x12) >> 8 |
                    (*(ushort *)(param_1 + 0x12) & 0xff) << 8;
  if (uVar4 != (((int)(uint)*(ushort *)(param_1 + 0xc) >> 8 |
                (*(ushort *)(param_1 + 0xc) & 0xff) << 8) << 0x10 |
               (int)(uint)*(ushort *)(param_1 + 0xe) >> 8 | (*(ushort *)(param_1 + 0xe) & 0xff) << 8
               )) {
    iVar2 = FUN_021b003c(uVar4);
    if (iVar2 == 0) {
      return;
    }
    if (param_2 < ((int)(uint)*(ushort *)(param_1 + 2) >> 8 | (*(ushort *)(param_1 + 2) & 0xff) << 8
                  )) {
      return;
    }
    iVar2 = FUN_021b0188((undefined4)(uintptr_t)(param_1),(*param_1 & 0xf) << 2);
    if (iVar2 != DAT_021ae510) {
      return;
    }
    if (*DAT_021ae514 ==
        (((int)(uint)*(ushort *)(param_1 + 0x10) >> 8 | (*(ushort *)(param_1 + 0x10) & 0xff) << 8)
         << 0x10 |
        (int)(uint)*(ushort *)(param_1 + 0x12) >> 8 | (*(ushort *)(param_1 + 0x12) & 0xff) << 8)) {
      FUN_021afb58((undefined4)(uintptr_t)(param_1 + -8),
                   ((int)(uint)*(ushort *)(param_1 + 0xc) >> 8 |
                   (*(ushort *)(param_1 + 0xc) & 0xff) << 8) << 0x10 |
                   (int)(uint)*(ushort *)(param_1 + 0xe) >> 8 |
                   (*(ushort *)(param_1 + 0xe) & 0xff) << 8,0);
    }
  }
  pbVar3 = (byte *)FUN_021ae51c(param_1,local_18);
  if (pbVar3 != (byte *)0x0) {
    bVar1 = pbVar3[9];
    if (bVar1 == 0x11) {
      FUN_021ae724();
    }
    else if (*DAT_021ae514 != 0) {
      if (bVar1 == 1) {
        FUN_021af1e4();
      }
      else if (bVar1 == 6) {
        FUN_021ae87c((int)(uintptr_t)(pbVar3),(int)(uintptr_t)(pbVar3 + (*pbVar3 & 0xf) * 4),
                     ((int)(uint)*(ushort *)(pbVar3 + 2) >> 8 |
                     (*(ushort *)(pbVar3 + 2) & 0xff) << 8) + (*pbVar3 & 0xf) * -4);
      }
    }
    if (local_18[0] != 0) {
      (*(code *)*DAT_021ae518)(pbVar3 + -0xe);
    }
  }
  return;
}

