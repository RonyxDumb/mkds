/* Decompiled C draft; module arm7; ROM address 060054cc. No matching claim. */
#include "types.h"
#include "deps/060054cc_FUN_060054cc.h"

void FUN_060054cc(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined2 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  short *psVar8;
  undefined1 auStack_218 [516];
  
  iVar2 = FUN_06000680();
  uVar1 = iVar2 + 0x154cU & 3;
  uVar3 = *(uint *)(iVar2 + 0x154cU & 0xfffffffc);
  uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  psVar8 = (short *)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  if ((*psVar8 == 9) || (*psVar8 == 10)) {
    uVar5 = thunk_FUN_037faf70();
    uVar1 = (uint)(psVar8 + 6) & 3;
    uVar6 = *(uint *)((uint)(psVar8 + 6) & 0xfffffffc);
    psVar8[6] = 0;
    psVar8[7] = 0;
    uVar3 = iVar2 + 0x154cU & 3;
    uVar7 = *(uint *)(iVar2 + 0x154cU & 0xfffffffc);
    thunk_FUN_037fabc0((uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) + 0xd0);
    FUN_06000154();
    if (*psVar8 == 10) {
      *psVar8 = 8;
    }
    else if (*psVar8 == 9) {
      *psVar8 = 7;
    }
    thunk_FUN_037faf84(uVar5);
    iVar2 = FUN_06002274(auStack_218,0);
    if (*(short *)(iVar2 + 4) == 0) {
      iVar2 = FUN_060025fc(auStack_218,7);
      if (*(short *)(iVar2 + 4) == 0) {
        psVar8[0x45] = 0;
        if ((uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) == 1) {
          FUN_06006d24(DAT_060055fc);
        }
        puVar4 = (undefined2 *)thunk_FUN_03807424();
        *puVar4 = 0x10;
        puVar4[1] = 0;
        thunk_FUN_038074cc();
      }
      else {
        FUN_06005490(0x104);
      }
    }
    else {
      FUN_06005490(DAT_060055f8);
    }
  }
  else {
    puVar4 = (undefined2 *)thunk_FUN_03807424();
    *puVar4 = 0x10;
    puVar4[1] = 3;
    thunk_FUN_038074cc();
  }
  return;
}

