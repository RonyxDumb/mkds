/* Decompiled C draft; module arm9_ov001; ROM address 02181274. No matching claim. */
#include "types.h"
#include "deps/02181274_func_ov001_02181274.h"

void func_ov001_02181274(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  func_0x020364e8();
  uVar3 = func_0x020364e0();
  puVar4 = (undefined4 *)func_0x02036b74(uVar3,0x30,0x20);
  piVar7 = piRam021813f0;
  *piRam021813f0 = (int)puVar4;
  *puVar4 = param_1;
  *(undefined4 *)(*piVar7 + 4) = param_2;
  *(undefined4 *)(*piVar7 + 8) = param_3;
  func_0x020364e8();
  uVar3 = func_0x020364e0();
  uVar3 = func_0x02036b74(uVar3,*(int *)(*piRam021813f0 + 8) << 1,0x20);
  *(undefined4 *)(*piRam021813f0 + 0x18) = uVar3;
  func_0x020364e8();
  uVar3 = func_0x020364e0();
  iVar5 = func_0x02133068(*(undefined4 *)(*piRam021813f0 + 4),8);
  uVar3 = func_0x02036b74(uVar3,iVar5 * iVar5,0x20);
  piVar7 = piRam021813f0;
  *(undefined4 *)(*piRam021813f0 + 0x1c) = uVar3;
  piVar7 = (int *)*piVar7;
  iVar5 = func_0x02133068(piVar7[1],8);
  iVar8 = *piVar7;
  iVar6 = func_0x02133068(iVar8,8);
  uVar1 = func_0x02133068(iVar8 * iVar6,8);
  func_0x0214d168(piVar7[7],uVar1,iVar5 * iVar5);
  iVar6 = 0;
  iVar8 = *(int *)*piRam021813f0;
  iVar5 = func_0x02133068(iVar8,8);
  if (0 < iVar5) {
    do {
      iVar9 = 0;
      if (0 < iVar5) {
        do {
          iVar10 = *piRam021813f0;
          iVar5 = func_0x02133068(*(int *)(iVar10 + 4) * iVar6,8);
          cVar2 = func_0x02133068(iVar8 * iVar6,8);
          *(char *)(*(int *)(iVar10 + 0x1c) + iVar9 + iVar5) = (char)iVar9 + cVar2;
          iVar9 = iVar9 + 1;
          iVar8 = *(int *)*piRam021813f0;
          iVar5 = func_0x02133068(iVar8,8);
        } while (iVar9 < iVar5);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar5);
  }
  func_0x020364e8();
  uVar3 = func_0x020364e0();
  uVar3 = func_0x02036b74(uVar3,*(int *)*piRam021813f0 * *(int *)*piRam021813f0 + 0x40,0x20);
  *(undefined4 *)(*piRam021813f0 + 0x20) = uVar3;
  func_0x020364e8();
  uVar3 = func_0x020364e0();
  uVar3 = func_0x02036b74(uVar3,*(int *)*piRam021813f0 * *(int *)*piRam021813f0 + 0x40,0x20);
  *(undefined4 *)(*piRam021813f0 + 0x24) = uVar3;
  func_0x020364e8();
  uVar3 = func_0x020364e0();
  uVar3 = func_0x02036b74(uVar3,*(int *)*piRam021813f0 * *(int *)*piRam021813f0,0x20);
  *(undefined4 *)(*piRam021813f0 + 0x28) = uVar3;
  func_0x020364e8();
  uVar3 = func_0x020364e0();
  uVar3 = func_0x02036b74(uVar3,*(int *)*piRam021813f0 * *(int *)*piRam021813f0 * 2,0x20);
  *(undefined4 *)(*piRam021813f0 + 0x2c) = uVar3;
  return;
}

