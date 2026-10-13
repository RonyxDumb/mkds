/* Decompiled C draft; module arm9; ROM address 02061588. No matching claim. */
#include "types.h"
#include "deps/02061588_TaskFunction_StructYE.h"

void TaskFunction_StructYE(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  uVar2 = uRam02061640;
  uVar8 = 0;
  uVar7 = (*(uint *)(uRam0206163c & 0xfffffffc) >> (uRam0206163c & 3) * 8 |
          *(uint *)(uRam0206163c & 0xfffffffc) << (uRam0206163c & 3) * -8 + 0x20) + 0x40;
  uVar1 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  do {
    iVar6 = uVar8 * 0x30 + (uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20);
    iVar3 = MaybeHasPersonalGhostForCourse_from_thumb(uVar8);
    if (iVar3 == 0) {
      uVar4 = iVar6 + 8U & 3;
      uVar5 = *(uint *)(iVar6 + 8U & 0xfffffffc);
      *(uint *)(iVar6 + 8) = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 0xfffffffe;
    }
    else {
      func_0205786c(1,uVar8,iVar6);
      uVar4 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
              *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0xc;
      uVar5 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      if (uVar4 >> uVar5 * 8 != 0 || uVar4 << uVar5 * -8 + 0x20 != 0) {
        func_02145d38();
      }
      uVar4 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
              *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 4;
      uVar5 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      if (uVar4 >> uVar5 * 8 != 0 || uVar4 << uVar5 * -8 + 0x20 != 0) {
        uVar4 = iVar6 + 8U & 3;
        uVar5 = *(uint *)(iVar6 + 8U & 0xfffffffc);
        *(uint *)(iVar6 + 8) = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 0xfffffffe;
      }
    }
    uVar8 = uVar8 + 1 & 0xff;
  } while (uVar8 < 0x20);
  *(undefined4 *)
   ((*(uint *)(uRam0206163c & 0xfffffffc) >> (uRam0206163c & 3) * 8 |
    *(uint *)(uRam0206163c & 0xfffffffc) << (uRam0206163c & 3) * -8 + 0x20) + 0x40) = 0;
  ResetSaveDataHolderTaskPendingFlag_from_thumb();
  return;
}

