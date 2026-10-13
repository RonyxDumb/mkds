/* Decompiled C draft; module arm9; ROM address 020e7ed0. No matching claim. */
#include "types.h"
#include "deps/020e7ed0_E7Fn2_9.h"

void E7Fn2_9(void)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  puVar1 = puRam020e7f90;
  uVar3 = *(uint *)((uint)piRam020e7f88 & 0xfffffffc) >> ((uint)piRam020e7f88 & 3) * 8 |
          *(uint *)((uint)piRam020e7f88 & 0xfffffffc) << ((uint)piRam020e7f88 & 3) * -8 + 0x20;
  if (uVar3 == 0) {
    uVar3 = *(uint *)(uRam020e7f8c & 0xfffffffc) >> (uRam020e7f8c & 3) * 8 |
            *(uint *)(uRam020e7f8c & 0xfffffffc) << (uRam020e7f8c & 3) * -8 + 0x20;
    uVar4 = *(undefined4 *)(uVar3 + 0x84);
    uVar5 = *(undefined4 *)(uVar3 + 0x88);
    *puRam020e7f90 = *(undefined4 *)(uVar3 + 0x80);
    puVar1[1] = uVar4;
    puVar1[2] = uVar5;
  }
  else {
    iVar2 = uVar3 - 1;
    *piRam020e7f88 = iVar2;
    uVar4 = uRam020e7f98;
    if (iVar2 < 1) {
      *(undefined2 *)(iRam020e7f94 + 0x18) = 0;
      StateDualHandler_SetState(uVar4,5);
    }
  }
  iVar2 = func_0203c5e4();
  if (iVar2 != 0) {
    iVar2 = func_020e6b48();
    uVar4 = puRam020e7f90[1];
    uVar5 = puRam020e7f90[2];
    *(undefined4 *)(iVar2 + 0x24) = *puRam020e7f90;
    *(undefined4 *)(iVar2 + 0x28) = uVar4;
    *(undefined4 *)(iVar2 + 0x2c) = uVar5;
    func_02147288(uRam020e7f9c,iVar2,uRam020e7fa0);
    return;
  }
  func_02147288(uRam020e7f9c,uRam020e7fa4,uRam020e7fa0);
  return;
}

