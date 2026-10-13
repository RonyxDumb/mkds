/* Decompiled C draft; module arm9; ROM address 020fd540. No matching claim. */
#include "types.h"
#include "deps/020fd540_func_020fd540.h"

void func_020fd540(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar5;
  ushort *puVar4;
  
  uVar5 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  uVar1 = uVar5 + 0x198 & 3;
  uVar3 = *(uint *)(uVar5 + 0x198 & 0xfffffffc);
  puVar4 = (ushort *)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  *(ushort *)(uVar5 + 0x78) = *(ushort *)(uVar5 + 0x78) | *puRam020fd66c;
  if (puVar4 == (ushort *)0x0) {
    func_020f9ca8(uVar5);
    *(undefined4 *)(uVar5 + 0x1a0) = 1;
  }
  func_020f9114(uVar5);
  StateDualHandler_Create(uVar5 + 0x184,uRam020fd670,4,uVar5);
  StateDualHandler_SetState(uVar5 + 0x184,0);
  *(undefined4 *)(uVar5 + 0x170) = 300;
  *(undefined4 *)(uVar5 + 0x174) = 0;
  *(undefined2 *)(uVar5 + 0x178) = 8;
  uVar2 = uRam020fd678;
  *(undefined4 *)(uVar5 + 0x17c) = uRam020fd674;
  *(undefined4 *)(uVar5 + 0x180) = 0;
  *(undefined4 *)(uVar5 + 0x16c) = 0;
  *(undefined4 *)(uVar5 + 0x134) = uVar2;
  *(undefined4 *)(uVar5 + 0x170) = param_3;
  *(undefined4 *)(uVar5 + 0x130) = 1;
  func_020f30ec(uVar5,3,param_2);
  uVar1 = uVar5 + 0x74 & 3;
  uVar3 = *(uint *)(uVar5 + 0x74 & 0xfffffffc);
  if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x180000) == 0) {
    *(undefined4 *)(uVar5 + 0x120) = uRam020fd67c;
  }
  uVar1 = uRam020fd680;
  if (puVar4 != (ushort *)0x0) {
    puVar4[1] = puVar4[1] & 0xfffd;
    puVar4[1] = puVar4[1] & 0xfff7;
    puVar4[0x33] = 0x1f;
    puVar4[1] = puVar4[1] & 0xfffb;
    if (*puVar4 != uVar1) {
      puVar4[1] = puVar4[1] & 0xfffe;
    }
  }
  *param_1 = 0;
  return;
}

