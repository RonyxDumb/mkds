/* Decompiled C draft; module arm9_ov000; ROM address 021a1ca8. No matching claim. */
#include "types.h"
#include "deps/021a1ca8_FUN_021a1ca8.h"

void FUN_021a1ca8(undefined4 param_1,undefined4 param_2,int param_3,uint param_4,int param_5,
                 char *param_6)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  iVar5 = *DAT_021a1e04;
  if (((iVar5 == 0) || (*(int *)(iVar5 + DAT_021a1e08) != 7)) ||
     (*(char *)(iVar5 + DAT_021a1e0c) != '\0')) {
    thunk_FUN_02198748(param_2,DAT_021a1e10,0xffffffff);
    return;
  }
  iVar5 = FUN_0219b998();
  if (iVar5 == -1) {
    thunk_FUN_02198748(param_2,DAT_021a1e14);
    FUN_021a1a38(6,DAT_021a1e18);
    return;
  }
  iVar2 = *DAT_021a1e04;
  uVar6 = (uint)*(byte *)(iVar2 + 0xd);
  if ((param_3 == *(int *)(iVar2 + uVar6 * 4 + DAT_021a1e1c)) &&
     (param_4 == *(ushort *)(iVar2 + uVar6 * 2 + DAT_021a1e20))) {
LAB_021a1d76:
    iVar2 = *DAT_021a1e04;
    *(undefined4 *)(iVar2 + DAT_021a1e28) = 0;
    *(undefined4 *)(iVar2 + DAT_021a1e2c) = 0;
    iVar2 = thunk_FUN_02198778(param_2,*(undefined4 *)(iVar2 + 8));
    if (iVar2 == 0) {
      FUN_021a1a38(6,DAT_021a1e30);
      return;
    }
    FUN_021a1ac0();
    if (*(char *)(*DAT_021a1e04 + 0xd) == '\0') {
      iVar2 = param_5 >> 1;
      if (DAT_021a1e34 <= param_5 >> 1) {
        iVar2 = DAT_021a1e34;
      }
      *(short *)(*DAT_021a1e04 + DAT_021a1e38) = (short)iVar2;
    }
    puVar3 = (undefined4 *)FUN_0219b958(iVar5);
    puVar4 = (undefined1 *)FUN_0219b8f0(iVar5);
    *puVar3 = param_2;
    piVar1 = DAT_021a1e04;
    *(char *)(*DAT_021a1e04 + 0xd) = *(char *)(*DAT_021a1e04 + 0xd) + '\x01';
    *puVar4 = (char)iVar5;
    puVar4[1] = *(undefined1 *)(*piVar1 + (*(byte *)(*piVar1 + 0xd) - 1) + DAT_021a1e3c);
    *(undefined2 *)(puVar4 + 2) = 0;
    *(undefined4 *)(puVar4 + 4) = 0;
    FUN_021988a4(param_2);
    FUN_0219f544(2);
    return;
  }
  if (*param_6 != '\0') {
    iVar7 = *DAT_021a1e04;
    iVar2 = func_0x0213c074(param_6,0,10);
    piVar1 = DAT_021a1e04;
    if (*(int *)(iVar7 + uVar6 * 4 + 0xf4) == iVar2) {
      *(int *)(*DAT_021a1e04 + uVar6 * 4 + DAT_021a1e1c) = param_3;
      *(short *)(*piVar1 + (uint)*(byte *)(*piVar1 + 0xd) * 2 + DAT_021a1e20) = (short)param_4;
      goto LAB_021a1d76;
    }
  }
  thunk_FUN_02198748(param_2,DAT_021a1e24,0xffffffff);
  return;
}

