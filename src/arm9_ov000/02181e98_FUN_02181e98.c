/* Decompiled C draft; module arm9_ov000; ROM address 02181e98. No matching claim. */
#include "types.h"
#include "deps/02181e98_FUN_02181e98.h"

void FUN_02181e98(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined1 *puVar6;
  int iVar7;
  int iVar8;
  
  iVar2 = func_0x02036bec(param_1,0x40);
  piVar1 = DAT_02181fb4;
  *DAT_02181fb4 = iVar2;
  *(undefined4 *)(iVar2 + 0x14) = param_1;
  *(undefined4 *)*piVar1 = 0;
  *(undefined4 *)(*piVar1 + 4) = 0;
  *(undefined4 *)(*piVar1 + 0x10) = 0xffffffff;
  iVar2 = func_ov000_021806d4();
  if (iVar2 < 9) {
    if (iVar2 < 8) {
      if (((iVar2 < 3) && (-1 < iVar2)) && ((iVar2 == 0 || (iVar2 == 2)))) {
        *(undefined4 *)(*DAT_02181fb4 + 8) = 0;
      }
    }
    else {
      *(undefined4 *)(*DAT_02181fb4 + 8) = 1;
    }
  }
  else if (iVar2 == 0xd) {
    *(undefined4 *)(*DAT_02181fb4 + 8) = 2;
  }
  piVar1 = DAT_02181fb4;
  *(undefined4 *)(*DAT_02181fb4 + 0xc) = 0;
  *(undefined4 *)(*piVar1 + 0x18) = 1;
  uVar3 = func_0x0204799c(DAT_02181fb8);
  *(undefined4 *)(*DAT_02181fb4 + 0x38) = uVar3;
  uVar3 = func_0x02047a28(DAT_02181fbc);
  *(undefined4 *)(*DAT_02181fb4 + 0x3c) = uVar3;
  FUN_02181df8();
  piVar1 = DAT_02181fb4;
  iVar2 = 0;
  puVar6 = DAT_02181fc0;
  do {
    func_0x02124a98(*puVar6,1,*(undefined4 *)(*piVar1 + 0x20),*(undefined4 *)(*piVar1 + 0x2c));
    puVar6 = puVar6 + 1;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 3);
  uVar3 = func_ov000_021804f4();
  uVar4 = func_ov000_021804e0();
  func_0x020ae6d4(uVar3,uVar4);
  func_0x02124ed0(param_1,*(undefined4 *)(*DAT_02181fb4 + 0x2c),0,(undefined4 *)(uintptr_t)(*DAT_02181fb4 + 0x1c));
  piVar1 = DAT_02181fb4;
  iVar8 = 0;
  piVar5 = DAT_02181fc8;
  iVar2 = DAT_02181fc4;
  do {
    iVar7 = 0;
    if (0 < *piVar5) {
      do {
        *(undefined2 *)(*(int *)(*piVar1 + 0x1c) + (uint)*(byte *)(iVar2 + iVar7) * 0x40 + 4) = 0xdc
        ;
        iVar7 = iVar7 + 1;
      } while (iVar7 < *piVar5);
    }
    iVar2 = iVar2 + 5;
    piVar5 = piVar5 + 1;
    iVar8 = iVar8 + 1;
  } while (iVar8 < 3);
  func_0x0212a910(1,0);
  func_0x021281c8(0xf);
  func_0x0204f7f4();
  return;
}

