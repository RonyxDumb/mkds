/* Decompiled C draft; module arm9_ov000; ROM address 021a2768. No matching claim. */
#include "types.h"
#include "deps/021a2768_FUN_021a2768.h"

int FUN_021a2768(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  if (*(int *)(*DAT_021a283c + 0x10) != 0) {
    return 0;
  }
  *(undefined4 *)(*DAT_021a283c + DAT_021a2840) = param_1;
  iVar5 = 0;
  do {
    iVar4 = *DAT_021a283c;
    uVar2 = FUN_021988d8((undefined4 *)(uintptr_t)(**(undefined4 **)(iVar4 + 4)));
    uVar3 = FUN_021988e4(**(undefined4 **)(iVar4 + 4));
    iVar4 = FUN_021a4a08((undefined4 *)(uintptr_t)(*DAT_021a283c + 0x10),uVar2,uVar3,*(undefined4 *)(iVar4 + DAT_021a2860),
                         *(undefined4 *)(iVar4 + DAT_021a2844),1,1,DAT_021a2848,DAT_021a284c,
                         DAT_021a2850,DAT_021a2854,DAT_021a2858,DAT_021a285c,0);
    piVar1 = DAT_021a283c;
    if (iVar4 == 0) break;
    if ((iVar4 != 3) || (iVar5 == 4)) {
      FUN_0219e4e8(iVar4);
      return iVar4;
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 5);
  *(undefined4 *)(*DAT_021a283c + 0x1c) = 0;
  *(undefined2 *)(*piVar1 + 0x1a) = 0;
  FUN_021a49cc(*(undefined4 *)(*piVar1 + 0x10),DAT_021a2864);
  FUN_021a49f4(*(undefined4 *)(*DAT_021a283c + 0x10),DAT_021a2868);
  FUN_021a49e0(*(undefined4 *)(*DAT_021a283c + 0x10),DAT_021a286c);
  FUN_021a4818(*(undefined4 *)(*DAT_021a283c + 0x10));
  return iVar4;
}

