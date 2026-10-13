/* Decompiled C draft; module arm9; ROM address 0207e35c. No matching claim. */
#include "types.h"
#include "deps/0207e35c_func_0207e35c.h"

void func_0207e35c(uint param_1)

{
  uint uVar1;
  int unaff_r4;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  undefined1 auStack_30 [12];
  undefined1 auStack_24 [12];
  
  uVar3 = param_1 + 0x90 & 3;
  uVar1 = *(uint *)(param_1 + 0x90 & 0xfffffffc);
  bVar4 = (uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) == 2;
  uVar3 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  if (bVar4) {
    unaff_r4 = uVar3 + 0x50;
  }
  uVar1 = param_1 + 0x1c & 3;
  uVar2 = *(uint *)(param_1 + 0x1c & 0xfffffffc);
  if (!bVar4) {
    unaff_r4 = uVar3 + 0x138;
  }
  GetDriverMaybeSfxPosition((undefined4 *)(void *)(auStack_30),*(undefined2 *)(param_1 + 4));
  func_0207f6f0(param_1,param_1 + 8,uVar3,uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,(undefined4)(uintptr_t)(auStack_30)
                ,unaff_r4);
  uVar1 = uVar3 + 0x180 & 3;
  uVar3 = *(uint *)(uVar3 + 0x180 & 0xfffffffc);
  if (uVar3 >> uVar1 * 8 == 0 && uVar3 << uVar1 * -8 + 0x20 == 0) {
    uVar3 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
            *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 0x78;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    func_0204360c(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,1);
    VecFx32_Subtract(param_1 + 0x44,(uint)(uintptr_t)(auStack_30),(int *)(void *)(auStack_24));
    func_01ffd224(param_1,(uint)(uintptr_t)(auStack_24),unaff_r4);
  }
  func_0207ebfc(param_1);
  return;
}

