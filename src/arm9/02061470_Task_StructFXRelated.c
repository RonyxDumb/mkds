/* Decompiled C draft; module arm9; ROM address 02061470. No matching claim. */
#include "types.h"
#include "deps/02061470_Task_StructFXRelated.h"

void Task_StructFXRelated(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  uVar2 = uRam02061528;
  uVar8 = 0;
  uVar7 = (*(uint *)(uRam02061524 & 0xfffffffc) >> (uRam02061524 & 3) * 8 |
          *(uint *)(uRam02061524 & 0xfffffffc) << (uRam02061524 & 3) * -8 + 0x20) + 0x40;
  uVar1 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  do {
    iVar6 = uVar8 * 0x230 + (uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20);
    iVar3 = func_020573c8(uVar8);
    if (iVar3 == 0) {
      uVar4 = iVar6 + 8U & 3;
      uVar5 = *(uint *)(iVar6 + 8U & 0xfffffffc);
      *(uint *)(iVar6 + 8) = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 0xfffffffe;
    }
    else {
      func_02057800(0,uVar8,iVar6);
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
  } while (uVar8 < 10);
  ResetSaveDataHolderTaskPendingFlag_from_thumb();
  *(undefined4 *)
   ((*(uint *)(uRam02061524 & 0xfffffffc) >> (uRam02061524 & 3) * 8 |
    *(uint *)(uRam02061524 & 0xfffffffc) << (uRam02061524 & 3) * -8 + 0x20) + 0x40) = 0;
  return;
}

