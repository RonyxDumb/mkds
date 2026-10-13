/* Decompiled C draft; module arm9; ROM address 02043c14. No matching claim. */
#include "types.h"
#include "deps/02043c14_MaybeResetInput.h"

void MaybeResetInput(void)

{
  undefined2 uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  uVar3 = uRam02043d04;
  iVar6 = iRam02043d00;
  iVar8 = 0;
  uVar1 = (undefined2)uRam02043d08;
  do {
    iVar7 = iVar8 * 0x5c + iVar6;
    StructCY_SomeFn((undefined2 *)(uintptr_t)(iVar7));
    StructCY_SomeFn_0(iVar7,uVar3,0x1e,10);
    *(undefined4 *)(iVar7 + 0x3c) = 0;
    *(undefined2 *)(iVar7 + 0x40) = 0;
    *(undefined4 *)(iVar7 + 0x44) = 0;
    *(undefined2 *)(iVar7 + 0x42) = uVar1;
    StructCYB_SomeFn(iVar7 + 0x28);
    StructCYA_SomeFn((undefined2 *)(uintptr_t)(iVar7 + 0x48));
    uVar4 = uRam02043d0c;
    iVar7 = iRam02043d00;
    iVar8 = iVar8 + 1;
  } while (iVar8 < 10);
  uVar2 = uRam02043d0c & 3;
  uVar5 = *(uint *)(uRam02043d0c & 0xfffffffc);
  *(undefined4 *)(iRam02043d00 + 0x31c) = 5;
  *(undefined4 *)(iVar7 + 0x378) = 6;
  iVar6 = 0;
  *(undefined4 *)((uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) + 8) = 0;
  uVar2 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  *(undefined4 *)((uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) + 0xc) = 0;
  uVar3 = uRam02043d04;
  do {
    StructCY_SomeFn((undefined2 *)(uintptr_t)(iVar7));
    *(undefined2 *)(iVar7 + 0x40) = 0;
    StructCY_SomeFn_0(iVar7,uVar3,0x1e,10);
    iVar6 = iVar6 + 1;
    iVar7 = iVar7 + 0x5c;
  } while (iVar6 < 10);
  return;
}

