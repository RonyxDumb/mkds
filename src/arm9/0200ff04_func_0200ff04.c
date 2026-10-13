/* Decompiled C draft; module arm9; ROM address 0200ff04. No matching claim. */
#include "types.h"
#include "deps/0200ff04_func_0200ff04.h"

undefined4 func_0200ff04(uint param_1,uint param_2)

{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  uVar3 = Os_DisableIrq();
  iVar5 = iRam0200ffd0;
  uVar7 = param_1 & (*(uint *)((uint)puRam0200ffcc & 0xfffffffc) >> ((uint)puRam0200ffcc & 3) * 8 |
                    *(uint *)((uint)puRam0200ffcc & 0xfffffffc) <<
                    ((uint)puRam0200ffcc & 3) * -8 + 0x20);
  do {
    iVar4 = Os_CountLeadingZeroBits(uVar7);
    iVar2 = iRam0200ffd0;
    puVar1 = puRam0200ffcc;
    uVar6 = 0x1f - iVar4;
    if ((int)uVar6 < 0) {
      param_1 = param_1 & uRam0200ffd4;
      while( true ) {
        iVar5 = Os_CountLeadingZeroBits(param_1);
        uVar7 = 0x1f - iVar5;
        if ((int)uVar7 < 0) break;
        uVar6 = *(uint *)((uint)puVar1 & 0xfffffffc);
        *(short *)(iVar2 + uVar7 * 2) = (short)param_2;
        *puVar1 = uVar6 >> ((uint)puVar1 & 3) * 8 | uVar6 << ((uint)puVar1 & 3) * -8 + 0x20 |
                  1 << (uVar7 & 0xff);
        param_1 = param_1 & ~(1 << (uVar7 & 0xff));
      }
      Os_RestoreIrq(uVar3);
      return 1;
    }
    uVar7 = uVar7 & ~(1 << (uVar6 & 0xff));
  } while (param_2 == *(ushort *)(iVar5 + uVar6 * 2));
  Os_RestoreIrq(uVar3);
  return 0;
}

