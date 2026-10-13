/* Decompiled C draft; module arm9; ROM address 0214d5c4. No matching claim. */
#include "types.h"
#include "deps/0214d5c4_FIFONotEmptyIRQHandler.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FIFONotEmptyIRQHandler(void)

{
  uint uVar1;
  uint uVar2;
  ushort *puVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  uint uVar7;
  undefined4 local_28;
  code *pcVar8;
  
  puVar5 = puRam0214d6e4;
  iVar4 = iRam0214d6e0;
  puVar3 = puRam0214d6dc;
  while( true ) {
    if ((*puVar3 & 0x4000) == 0) {
      Os_DisableIrq();
      if ((*puVar3 & 0x100) == 0) {
        local_28 = _DAT_04100000;
        Os_RestoreIrq();
        iVar6 = 0;
      }
      else {
        Os_RestoreIrq();
        iVar6 = -4;
      }
    }
    else {
      *puVar3 = *puVar3 | 0xc000;
      iVar6 = -3;
    }
    if (iVar6 == -4) break;
    if (iVar6 != -3) {
      uVar2 = local_28 & 0x1f;
      if (uVar2 != 0) {
        uVar7 = iVar4 + uVar2 * 4;
        uVar1 = uVar7 & 3;
        uVar7 = *(uint *)(uVar7 & 0xfffffffc);
        pcVar8 = (code *)(uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20);
        if (pcVar8 == (code *)0x0) {
          if (-1 < (int)(local_28 << 0x1a)) {
            local_28 = local_28 | 0x20;
            if ((*puVar3 & 0x4000) == 0) {
              Os_DisableIrq();
              if ((*puVar3 & 2) == 0) {
                *puVar5 = local_28;
                Os_RestoreIrq();
              }
              else {
                Os_RestoreIrq();
              }
            }
            else {
              *puVar3 = *puVar3 | 0xc000;
            }
          }
        }
        else {
          (*pcVar8)(uVar2,local_28 >> 6,(local_28 << 0x1a) >> 0x1f);
        }
      }
    }
  }
  return;
}

