/* Decompiled C draft; module arm9; ROM address 0200fe7c. No matching claim. */
#include "types.h"
#include "deps/0200fe7c_Os_UnlockVram.h"

void Os_UnlockVram(uint param_1,uint param_2)

{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  
  uVar3 = Os_DisableIrq();
  iVar2 = iRam0200ff00;
  puVar1 = puRam0200fef8;
  uVar8 = param_1 & (*(uint *)((uint)puRam0200fef8 & 0xfffffffc) >> ((uint)puRam0200fef8 & 3) * 8 |
                    *(uint *)((uint)puRam0200fef8 & 0xfffffffc) <<
                    ((uint)puRam0200fef8 & 3) * -8 + 0x20) & uRam0200fefc;
  while( true ) {
    iVar4 = Os_CountLeadingZeroBits(uVar8);
    uVar6 = 0x1f - iVar4;
    if ((int)uVar6 < 0) break;
    uVar5 = (uint)*(ushort *)(iVar2 + uVar6 * 2);
    uVar7 = ~(1 << (uVar6 & 0xff));
    bVar9 = param_2 == uVar5;
    if (bVar9) {
      uVar5 = *(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
              *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20;
    }
    uVar8 = uVar8 & uVar7;
    if (bVar9) {
      *(undefined2 *)(iVar2 + uVar6 * 2) = 0;
      *puVar1 = uVar5 & uVar7;
    }
  }
  Os_RestoreIrq(uVar3);
  return;
}

