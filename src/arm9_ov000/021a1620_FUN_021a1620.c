/* Decompiled C draft; module arm9_ov000; ROM address 021a1620. No matching claim. */
#include "types.h"
#include "deps/021a1620_FUN_021a1620.h"

undefined4 FUN_021a1620(int param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar4 = *DAT_021a1740;
  if (iVar4 != 0) {
    uVar2 = *(undefined4 *)(iVar4 + param_1 * 4 + 0xf4);
    *(uint *)(iVar4 + DAT_021a1744) =
         *(uint *)(iVar4 + DAT_021a1744) & ~(1 << (uint)*(byte *)(iVar4 + param_1 + DAT_021a1748));
    FUN_021a15b0();
    piVar1 = DAT_021a1740;
    if (param_1 < param_2 + -1) {
      iVar4 = 0;
      if (0 < param_2 - param_1) {
        do {
          iVar7 = param_1 + iVar4;
          iVar3 = iVar7 + 1;
          iVar6 = iVar3 * 4;
          iVar5 = iVar7 * 4;
          *(undefined4 *)(*piVar1 + iVar5 + 0x24) = *(undefined4 *)(*piVar1 + iVar6 + 0x24);
          *(undefined2 *)(*piVar1 + iVar7 * 2 + 0xa4) = *(undefined2 *)(*piVar1 + iVar3 * 2 + 0xa4);
          *(undefined4 *)(*piVar1 + iVar5 + 0xf4) = *(undefined4 *)(*piVar1 + iVar6 + 0xf4);
          *(undefined4 *)(*piVar1 + iVar5 + DAT_021a174c) =
               *(undefined4 *)(*piVar1 + iVar6 + DAT_021a174c);
          *(undefined2 *)(*piVar1 + iVar7 * 2 + DAT_021a1750) =
               *(undefined2 *)(*piVar1 + iVar3 * 2 + DAT_021a1750);
          *(undefined1 *)(*piVar1 + iVar7 + DAT_021a1748) =
               *(undefined1 *)(*piVar1 + iVar3 + DAT_021a1748);
          iVar4 = iVar4 + 1;
        } while (iVar4 < param_2 - param_1);
      }
    }
    piVar1 = DAT_021a1740;
    if (0 < param_2) {
      param_2 = param_2 + -1;
      iVar4 = param_2 * 4;
      *(undefined4 *)(*DAT_021a1740 + iVar4 + 0x24) = 0;
      *(undefined2 *)(*piVar1 + param_2 * 2 + 0xa4) = 0;
      *(undefined4 *)(*piVar1 + iVar4 + 0xf4) = 0;
      *(undefined4 *)(*piVar1 + iVar4 + DAT_021a174c) = 0;
      *(undefined2 *)(*piVar1 + param_2 * 2 + DAT_021a1750) = 0;
      *(undefined1 *)(*piVar1 + param_2 + DAT_021a1748) = 0;
    }
    return uVar2;
  }
  return 0;
}

