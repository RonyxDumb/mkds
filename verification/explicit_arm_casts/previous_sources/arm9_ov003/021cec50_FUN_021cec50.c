/* Decompiled C draft; module arm9_ov003; ROM address 021cec50. No matching claim. */
#include "types.h"
#include "deps/021cec50_FUN_021cec50.h"

void FUN_021cec50(uint param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined1 auStack_20 [12];
  
  FUN_021d17d4(*(undefined4 *)*DAT_021ced58,0xffffffff,
               *(undefined2 *)(DAT_021ced5c + (uint)*(byte *)((undefined4 *)*DAT_021ced58 + 7) * 4),
               param_1);
  FUN_021d17d4(*(undefined4 *)(*DAT_021ced58 + 4),0xffffffff,
               (uint)*DAT_021ced60 +
               (uint)*(ushort *)(DAT_021ced5c + (uint)*(byte *)(*DAT_021ced58 + 0x1c) * 4),
               param_1 + DAT_021ced60[1]);
  FUN_021cec00(*(undefined4 *)*DAT_021ced58,param_1);
  FUN_021cec00(*(undefined4 *)(*DAT_021ced58 + 4),param_1);
  iVar6 = 0;
  uVar7 = (uint)*(byte *)(*DAT_021ced58 + 0x1c);
  if (*(char *)(DAT_021ced64 + uVar7) != '\0') {
    iVar5 = 0;
    do {
      iVar3 = DAT_021ced68 + uVar7 * 8;
      iVar2 = (uint)*(byte *)(iVar6 + DAT_021ced6c + uVar7 * 2) * 4;
      FUN_021d17d4(*(undefined4 *)(*DAT_021ced58 + iVar5 + 8),0xffffffff,
                   *(undefined2 *)(iVar3 + iVar2),
                   (param_1 + *(ushort *)(iVar3 + iVar2 + 2)) -
                   (uint)*(ushort *)(DAT_021ced5c + uVar7 * 4 + 2));
      FUN_021cec00(*(undefined4 *)(*DAT_021ced58 + iVar5 + 8),param_1);
      iVar5 = iVar5 + 4;
      iVar6 = iVar6 + 1;
      uVar7 = (uint)*(byte *)(*DAT_021ced58 + 0x1c);
    } while (iVar6 < (int)(uint)*(byte *)(DAT_021ced64 + uVar7));
  }
  param_1 = param_1 & 0xff;
  if (param_1 < 0xc0) {
    uVar4 = param_1 + *(ushort *)(DAT_021ced70 + uVar7 * 4);
  }
  else {
    uVar4 = 0;
    param_1 = 0;
  }
  if (0xc0 < uVar4) {
    uVar4 = 0xc0;
  }
  uVar1 = (uint)*(ushort *)(DAT_021ced5c + uVar7 * 4);
  FUN_021d2530(uVar1,param_1,uVar1 + *(ushort *)(DAT_021ced74 + uVar7 * 4),uVar4,auStack_20);
  FUN_021d2658(0,0,auStack_20);
  return;
}

