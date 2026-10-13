/* Decompiled C draft; module arm9_ov001; ROM address 02180610. No matching claim. */
#include "types.h"
#include "deps/02180610_func_ov001_02180610.h"

void func_ov001_02180610(void)

{
  undefined2 uVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined2 *puVar7;
  undefined2 *puVar8;
  undefined2 local_40 [22];
  
  puVar7 = local_40;
  iVar5 = 0x14;
  puVar8 = puRam02180718;
  do {
    uVar1 = *puVar8;
    puVar8 = puVar8 + 1;
    *puVar7 = uVar1;
    puVar7 = puVar7 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  uVar3 = func_ov001_021807e4();
  puVar4 = (undefined4 *)func_0x02036bec(uVar3,uRam0218071c);
  piVar2 = piRam02180720;
  *piRam02180720 = (int)puVar4;
  *puVar4 = 0;
  *(undefined4 *)(*piVar2 + 4) = 1;
  *(undefined4 *)(*piVar2 + 8) = 1;
  func_ov001_02180ccc(*piVar2 + 0xa8);
  func_ov001_02180cb4(*piRam02180720 + iRam02180724);
  uVar3 = func_ov001_021807e4();
  uVar3 = func_0x02038d88(uVar3,(undefined4)(uintptr_t)(local_40));
  func_ov001_021807a8(uVar3,0,0,0,0,4,0,0);
  func_ov001_02180774(uVar3,2,0,0,0,0xe,1);
  func_ov001_02180740(uVar3,2,0,0,0,4,4);
  func_0x02037abc(uVar3);
  uVar3 = func_0x020b403c(0);
  *(undefined4 *)(*piRam02180720 + 0xc) = uVar3;
  uVar3 = func_0x020b403c(1);
  *(undefined4 *)(*piRam02180720 + 0x10) = uVar3;
  uVar3 = func_0x020b403c(2);
  piVar2 = piRam02180720;
  *(undefined4 *)(*piRam02180720 + 0x14) = uVar3;
  iVar5 = 0;
  do {
    iVar6 = *piVar2;
    func_0x02023408(iVar6 + 0x18 + iVar5 * 0x20,iVar6 + 0xa8,0x20,0x18,4);
    iVar6 = *piVar2;
    func_ov001_02180728((undefined4 *)(uintptr_t)(iVar6 + 0x78 + iVar5 * 0x10),iVar6 + 0x18 + iVar5 * 0x20,
                        *(undefined4 *)(iVar6 + iVar5 * 4 + 0xc),0,0);
    iVar5 = iVar5 + 1;
  } while (iVar5 < 3);
  func_0x020ca6c4();
  return;
}

