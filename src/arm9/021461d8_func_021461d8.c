/* Decompiled C draft; module arm9; ROM address 021461d8. No matching claim. */
#include "types.h"
#include "deps/021461d8_func_021461d8.h"

void func_021461d8(uint param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
                  ,undefined4 param_6,int param_7)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  
  uVar3 = uRam021462f0;
  iVar2 = iRam021462ec;
  EnsureCardEnabled();
  uVar4 = Os_DisableIrq();
  uVar1 = iVar2 + 0x114U & 3;
  uVar6 = *(uint *)(iVar2 + 0x114U & 0xfffffffc);
  if (((uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) & 4) != 0) {
    do {
      Os_Thread_Sleep(iVar2 + 0x10c);
      uVar1 = iVar2 + 0x114U & 3;
      uVar6 = *(uint *)(iVar2 + 0x114U & 0xfffffffc);
    } while (((uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) & 4) != 0);
  }
  uVar1 = iVar2 + 0x114U & 3;
  uVar6 = *(uint *)(iVar2 + 0x114U & 0xfffffffc);
  *(uint *)(iVar2 + 0x114) = uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20 | 4;
  *(undefined4 *)(iVar2 + 0x38) = param_5;
  *(undefined4 *)(iVar2 + 0x3c) = param_6;
  Os_RestoreIrq(uVar4);
  uVar6 = uRam021462f4;
  *(uint *)(iVar2 + 0x28) = param_1;
  uVar1 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  *(uint *)(iVar2 + 0x1c) = param_2 + (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20);
  *(undefined4 *)(iVar2 + 0x20) = param_3;
  *(undefined4 *)(iVar2 + 0x24) = param_4;
  if (param_1 < 4) {
    Mem_DmaStop(param_1);
  }
  iVar5 = StructSZ_SomeFn(uVar3);
  if (iVar5 == 0) {
    if (param_7 == 0) {
      uVar1 = iRam021462fc + 4U & 3;
      uVar6 = *(uint *)(iRam021462fc + 4U & 0xfffffffc);
      *(uint *)(iVar2 + 0x104) = uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20;
      task_fn(iVar2);
      return;
    }
    Card_SetTask(uRam021462f8);
    return;
  }
  if (param_7 == 0) {
    func_02146148();
    return;
  }
  return;
}

