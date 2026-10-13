/* Decompiled C draft; module arm9; ROM address 020727d4. No matching claim. */
#include "types.h"
#include "deps/020727d4_DriverContext_Fn7.h"

void DriverContext_Fn7(int param_1)

{
  undefined4 *puVar1;
  undefined2 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined1 auStack_30 [12];
  undefined1 auStack_24 [12];
  undefined1 auStack_18 [4];
  int iStack_14;
  
  uVar4 = param_1 + 0x7cU & 3;
  uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0x20) != 0) {
    func_02041bb0((undefined4)(uintptr_t)(auStack_30),(undefined4)(uintptr_t)(auStack_18),*(undefined2 *)(param_1 + 0x74));
    *(short *)(param_1 + 0x236) = (short)((uint)(iStack_14 * 0xb6) >> 0xc);
    func_01ffd190(uRam02072924,*(undefined2 *)(param_1 + 0x236),(uint *)(uintptr_t)(param_1 + 0xe0));
    func_01ffcd84((int *)(uintptr_t)(param_1 + 0x120),param_1 + 0xe0);
    GetMQRacerVector333(param_1,(uint *)(void *)(auStack_24));
    StructMQRacerEntry_SomeFn_63(param_1,(undefined4 *)(void *)(auStack_30),(uint)(uintptr_t)(auStack_24),0);
    uVar4 = (*(uint *)(uRam02072928 & 0xfffffffc) >> (uRam02072928 & 3) * 8 |
            *(uint *)(uRam02072928 & 0xfffffffc) << (uRam02072928 & 3) * -8 + 0x20) + 8;
    uVar3 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    if ((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) == 5) {
      iVar5 = param_1 + 0x1d8;
    }
    else {
      iVar5 = param_1 + 0x1b8;
    }
    if (*(short *)(param_1 + 0x2c8) == -1) {
      uVar4 = param_1 + 0x2ccU & 3;
      uVar3 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
      uVar3 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
      uVar4 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      uVar2 = FindComputeSomeCollisionEntryId
                        (iVar5,(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0xd000,0x8000,
                         param_1);
      *(undefined2 *)(param_1 + 0x2c8) = uVar2;
    }
    if (*(short *)(param_1 + 0x2ca) == -1) {
      uVar4 = param_1 + 0x2ccU & 3;
      uVar3 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
      uVar3 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
      uVar4 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
      uVar2 = FindComputeSomeCollisionEntryId
                        (param_1 + 0x1f0,(uVar4 << 0xf) >> 0xc | (uVar4 >> 0x11) << 0x14,0x800,
                         param_1);
      *(undefined2 *)(param_1 + 0x2ca) = uVar2;
    }
    puVar1 = puRam0207292c;
    uVar4 = param_1 + 0x7cU & 3;
    uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    *(uint *)(param_1 + 0x7c) = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20 | 0x80;
    uVar4 = param_1 + 0x7cU & 3;
    uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    *(uint *)(param_1 + 0x7c) = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0xffffff9f;
    uVar6 = puVar1[1];
    uVar7 = puVar1[2];
    *(undefined4 *)(param_1 + 0xbc) = *puVar1;
    *(undefined4 *)(param_1 + 0xc0) = uVar6;
    *(undefined4 *)(param_1 + 0xc4) = uVar7;
    return;
  }
  return;
}

