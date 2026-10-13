/* Decompiled C draft; module arm9_ov003; ROM address 021ce920. No matching claim. */
#include "types.h"
#include "deps/021ce920_FUN_021ce920.h"

undefined4 FUN_021ce920(undefined4 param_1)

{
  int *piVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined8 uVar9;
  undefined1 auStack_60 [4];
  undefined1 auStack_5c [20];
  ushort local_48;
  
  iVar3 = FUN_021d283c(DAT_021ce9f8,0x20);
  piVar1 = DAT_021ce9fc;
  *DAT_021ce9fc = iVar3;
  *(undefined4 *)(iVar3 + DAT_021cea00) = param_1;
  iVar3 = *piVar1;
  uVar9 = func_0x0200f5ac();
  *(int *)(iVar3 + DAT_021cea04) = (int)uVar9;
  *(int *)(iVar3 + DAT_021cea08) = (int)((ulonglong)uVar9 >> 0x20);
  iVar4 = func_0x02143e10(iVar3,DAT_021cea0c,3);
  iVar3 = DAT_021cea10;
  piVar1 = DAT_021ce9fc;
  if (iVar4 == 2) {
    do {
      func_0x02143520(*piVar1 + iVar3);
      iVar4 = *piVar1;
    } while (*(short *)(iVar4 + iVar3) != 2);
    puVar7 = (undefined4 *)(iVar4 + DAT_021cea18);
    iVar3 = 8;
    puVar8 = DAT_021cea14;
    do {
      uVar5 = *puVar8;
      uVar6 = puVar8[1];
      puVar8 = puVar8 + 2;
      *puVar7 = uVar5;
      puVar7[1] = uVar6;
      puVar7 = puVar7 + 2;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    *puVar7 = *puVar8;
    *(int *)(iVar4 + DAT_021cea18) = iVar4 + DAT_021cea1c;
    uVar2 = func_0x02143090();
    *(undefined2 *)(*DAT_021ce9fc + DAT_021cea20) = uVar2;
    func_0x0200fddc(auStack_60);
    func_0x0214d1fc((ushort *)(uintptr_t)(DAT_021cea24),(uint *)(uintptr_t)(*DAT_021ce9fc + DAT_021cea28),8);
    piVar1 = DAT_021ce9fc;
    *(undefined1 *)(*DAT_021ce9fc + DAT_021cea2c) = 1;
    func_0x0214d1fc((ushort *)(void *)(auStack_5c),(uint *)(uintptr_t)(*piVar1 + DAT_021cea30),(uint)local_48 << 1);
    iVar3 = FUN_021ce8ec();
    if (iVar3 != 0) {
      uVar5 = FUN_021d3544(0,DAT_021cea34,0,0x78);
      *(undefined4 *)(*DAT_021ce9fc + DAT_021cea38) = uVar5;
      return 1;
    }
  }
  FUN_021d2808(DAT_021ce9fc);
  return 0;
}

