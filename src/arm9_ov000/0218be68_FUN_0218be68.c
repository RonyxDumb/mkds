/* Decompiled C draft; module arm9_ov000; ROM address 0218be68. No matching claim. */
#include "types.h"
#include "deps/0218be68_FUN_0218be68.h"

undefined4 FUN_0218be68(int param_1,undefined4 *param_2,int param_3)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  int local_54 [16];
  
  if (param_3 < 0xb) {
    return 4;
  }
  iVar5 = FUN_0218d2a8(param_1,*param_2,*(undefined2 *)(param_2 + 1));
  if (iVar5 != -1) {
    uVar6 = FUN_0218d218(param_1);
    uVar4 = *(uint *)((int)param_2 + 6);
    uVar2 = DAT_0218bf64 >> 0x18;
    uVar3 = DAT_0218bf68 >> 8;
    uVar8 = uVar4 >> 8 & DAT_0218bf6c;
    bVar1 = *(byte *)((int)param_2 + 10);
    iVar9 = (int)param_2 + 0xb;
    iVar5 = 0;
    piVar10 = local_54;
    for (param_3 = param_3 + -0xb; ((iVar5 < (int)(uint)bVar1 && (iVar5 < 0x10)) && (0 < param_3));
        param_3 = param_3 - iVar7) {
      iVar7 = FUN_0218d0c8(iVar9,param_3);
      if (iVar7 == -1) {
        return 4;
      }
      *piVar10 = iVar9;
      piVar10 = piVar10 + 1;
      iVar9 = iVar9 + iVar7;
      iVar5 = iVar5 + 1;
    }
    if (*(code **)(param_1 + DAT_0218bf70) == (code *)0x0) {
      return 0;
    }
    (**(code **)(param_1 + DAT_0218bf70))
              (param_1,uVar6,(uVar4 & uVar2) << 0x18 | (uVar4 & uVar3) << 8 | uVar4 >> 0x18 | uVar8,
               iVar5,local_54,*(undefined4 *)(param_1 + DAT_0218bf74));
  }
  return 0;
}

