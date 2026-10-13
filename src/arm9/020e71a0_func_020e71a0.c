/* Decompiled C draft; module arm9; ROM address 020e71a0. No matching claim. */
#include "types.h"
#include "deps/020e71a0_func_020e71a0.h"

void func_020e71a0(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  bool bVar6;
  undefined8 uVar7;
  uint uVar5;
  
  uVar5 = param_1 + 0x94U & 3;
  uVar4 = *(uint *)(param_1 + 0x94U & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  if ((*(ushort *)(param_1 + 2) & 2) == 0) {
    uVar4 = param_1 + 0x78U & 3;
    uVar2 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
    *(uint *)(uVar5 + 0x40) = (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 0x3fffffe0;
    uVar7 = func_020d4ddc();
    iVar3 = (int)((ulonglong)uVar7 >> 0x20);
    bVar6 = (int)uVar7 == 0;
    if (bVar6) {
      iVar3 = 1;
    }
    if (!bVar6) {
      iVar3 = 0;
    }
    bVar6 = (*(ushort *)(uVar5 + 0x34) & 1) != 0;
    if ((iVar3 == 0) || (bVar6)) {
      if (iVar3 != 0) {
        return;
      }
      if (!bVar6) {
        return;
      }
    }
    StructMQRacerEntry_SomeFn_47(uVar5,2,1);
    return;
  }
  uVar1 = func_020d4ef4(param_1 + 4);
  *(undefined4 *)(uVar5 + 0x40) = uVar1;
  iVar3 = func_020d4d60(param_1);
  if (iVar3 != 0) {
    uVar4 = param_1 + 0x78U & 3;
    uVar2 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
    *(uint *)(param_1 + 0x78) =
         uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20 |
         *(uint *)(uRam020e72c8 & 0xfffffffc) >> (uRam020e72c8 & 3) * 8 |
         *(uint *)(uRam020e72c8 & 0xfffffffc) << (uRam020e72c8 & 3) * -8 + 0x20;
    if ((*(ushort *)(uVar5 + 0x34) & 1) != 0) {
      StructMQRacerEntry_SomeFn_47(uVar5,2,1);
      return;
    }
    return;
  }
  if ((*(ushort *)(uVar5 + 0x34) & 1) == 0) {
    StructMQRacerEntry_SomeFn_47(uVar5,2,1);
    return;
  }
  return;
}

