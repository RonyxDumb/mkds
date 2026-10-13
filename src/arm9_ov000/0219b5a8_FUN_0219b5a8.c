/* Decompiled C draft; module arm9_ov000; ROM address 0219b5a8. No matching claim. */
#include "types.h"
#include "deps/0219b5a8_FUN_0219b5a8.h"

void FUN_0219b5a8(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if ((param_1 == 0) && (param_2 != 0)) {
    if (*(int *)(*DAT_0219b678 + DAT_0219b67c) == 0) {
      FUN_021a1a10();
      FUN_0219b8a8(3);
    }
  }
  else if (param_1 == 0) {
    FUN_0219b8a8(6);
    iVar3 = 0;
    iVar2 = *DAT_0219b678;
    iVar4 = iVar2;
    do {
      if (*(int *)(iVar2 + 0x30) == *(int *)(iVar4 + DAT_0219b684)) {
        *(undefined1 *)(*DAT_0219b678 + 0x2c) =
             *(undefined1 *)(*DAT_0219b678 + iVar3 + DAT_0219b688);
        break;
      }
      iVar4 = iVar4 + 4;
      iVar3 = iVar3 + 1;
    } while (iVar3 <= (int)(uint)*(byte *)(iVar2 + DAT_0219b680));
  }
  uVar1 = FUN_0219b844(*DAT_0219b678 + DAT_0219b688,*(byte *)(*DAT_0219b678 + DAT_0219b680) + 1);
  *(undefined4 *)(*DAT_0219b678 + DAT_0219b68c) = uVar1;
  FUN_021a15b0();
  iVar4 = *DAT_0219b678;
  if ((*(char *)(iVar4 + DAT_0219b690) != '\x02') && (*(char *)(iVar4 + DAT_0219b690) != '\x03')) {
    (**(code **)(iVar4 + 0x6c))(param_1,param_2,*(undefined4 *)(iVar4 + 0x70));
    return;
  }
  (**(code **)(*DAT_0219b678 + 0x74))
            (param_1,param_2,param_3,param_4,param_5,*(undefined4 *)(*DAT_0219b678 + 0x78));
  return;
}

