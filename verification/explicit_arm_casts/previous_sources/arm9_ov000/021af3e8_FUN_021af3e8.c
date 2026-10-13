/* Decompiled C draft; module arm9_ov000; ROM address 021af3e8. No matching claim. */
#include "types.h"
#include "deps/021af3e8_FUN_021af3e8.h"

void FUN_021af3e8(ushort *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  
  if ((((0x1b < param_2) && (iVar1 = FUN_021b0014(param_1 + 4,DAT_021af4c0), iVar1 != 0)) &&
      (*DAT_021af4c4 != 0)) &&
     (((*param_1 == DAT_021af4c8 && (param_1[1] == 8)) &&
      ((param_1[2] == DAT_021af4cc &&
       ((uVar4 = (int)(uint)param_1[3] >> 8 | (param_1[3] & 0xff) << 8, uVar4 == 1 || (uVar4 == 2)))
       ))))) {
    uVar2 = ((int)(uint)param_1[7] >> 8 | (param_1[7] & 0xff) << 8) << 0x10 |
            (int)(uint)param_1[8] >> 8 | (param_1[8] & 0xff) << 8;
    uVar3 = *DAT_021af4c4;
    bVar5 = uVar3 == (((int)(uint)param_1[0xc] >> 8 | (param_1[0xc] & 0xff) << 8) << 0x10 |
                     (int)(uint)param_1[0xd] >> 8 | (param_1[0xd] & 0xff) << 8);
    if (uVar2 != uVar3) {
      FUN_021afb58(param_1 + 4,uVar2,bVar5);
    }
    if ((uVar4 == 1) && (bVar5)) {
      FUN_021af4d4(param_1);
      return;
    }
    if (((uVar4 == 2) && (bVar5)) && (uVar2 == uVar3)) {
      *DAT_021af4d0 = 1;
    }
  }
  return;
}

