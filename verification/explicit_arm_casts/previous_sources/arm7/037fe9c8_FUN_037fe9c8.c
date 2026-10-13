/* Decompiled C draft; module arm7; ROM address 037fe9c8. No matching claim. */
#include "types.h"
#include "deps/037fe9c8_FUN_037fe9c8.h"

void FUN_037fe9c8(uint param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar4;
  
  iVar1 = DAT_037fea60;
  iVar6 = 0;
  do {
    iVar7 = iVar1 + iVar6 * 0x24;
    if ((int)((uint)*(byte *)(iVar1 + iVar6 * 0x24) << 0x1f) < 0) {
      for (iVar5 = 0; iVar5 < 0x10; iVar5 = iVar5 + 1) {
        iVar2 = FUN_037fe2e4(iVar7,iVar5);
        if (((iVar2 != 0) &&
            (uVar4 = iVar2 + 0x28U & 3, uVar3 = *(uint *)(iVar2 + 0x28U & 0xfffffffc),
            uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20, param_1 <= uVar4)) &&
           (uVar4 <= param_2)) {
          FUN_037fe230(iVar7);
          break;
        }
      }
    }
    iVar6 = iVar6 + 1;
    if (0xf < iVar6) {
      return;
    }
  } while( true );
}

