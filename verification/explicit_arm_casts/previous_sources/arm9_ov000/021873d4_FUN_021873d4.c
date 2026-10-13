/* Decompiled C draft; module arm9_ov000; ROM address 021873d4. No matching claim. */
#include "types.h"
#include "deps/021873d4_FUN_021873d4.h"

undefined4 FUN_021873d4(undefined1 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  func_0x0214d168(param_1,0,DAT_02187464);
  *(undefined4 *)(param_1 + DAT_02187468) = 0xffffffff;
  uVar2 = param_2[1];
  *(undefined4 *)(param_1 + 4) = *param_2;
  *(undefined4 *)(param_1 + 8) = uVar2;
  uVar2 = param_2[3];
  *(undefined4 *)(param_1 + 0xc) = param_2[2];
  *(undefined4 *)(param_1 + 0x10) = uVar2;
  uVar2 = param_2[5];
  *(undefined4 *)(param_1 + 0x14) = param_2[4];
  *(undefined4 *)(param_1 + 0x18) = uVar2;
  uVar2 = param_2[7];
  *(undefined4 *)(param_1 + 0x1c) = param_2[6];
  *(undefined4 *)(param_1 + 0x20) = uVar2;
  iVar1 = (**(code **)(param_1 + 0x14))
                    (DAT_0218746c,DAT_02187470,*(code **)(param_1 + 0x14),param_2 + 8);
  piVar3 = (int *)(param_1 + DAT_02187474);
  *piVar3 = iVar1;
  if (*piVar3 == 0) {
    *(undefined4 *)(param_1 + 0x24) = 1;
    return 1;
  }
  iVar1 = (**(code **)(param_1 + 0x14))(DAT_02187478,DAT_0218747c);
  piVar3 = (int *)(param_1 + DAT_02187480);
  *piVar3 = iVar1;
  if (*piVar3 == 0) {
    *(undefined4 *)(param_1 + 0x24) = 1;
    return 1;
  }
  FUN_021868d0(param_1,*param_2);
  uVar2 = FUN_02186c74(param_1);
  *(undefined4 *)(param_1 + 0x24) = uVar2;
  if (*(int *)(param_1 + 0x24) == 0) {
    *param_1 = 0xff;
  }
  return *(undefined4 *)(param_1 + 0x24);
}

