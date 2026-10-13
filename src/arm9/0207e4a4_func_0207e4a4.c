/* Decompiled C draft; module arm9; ROM address 0207e4a4. No matching claim. */
#include "types.h"
#include "deps/0207e4a4_func_0207e4a4.h"

void func_0207e4a4(uint param_1)

{
  uint uVar1;
  uint uVar2;
  int unaff_r4;
  uint uVar3;
  bool bVar4;
  undefined1 auStack_30 [12];
  undefined1 auStack_24 [12];
  
  uVar2 = (*(uint *)(uRam0207e560 & 0xfffffffc) >> (uRam0207e560 & 3) * 8 |
          *(uint *)(uRam0207e560 & 0xfffffffc) << (uRam0207e560 & 3) * -8 + 0x20) + 8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 4) {
    func_0207e668();
  }
  uVar2 = param_1 + 0x90 & 3;
  uVar1 = *(uint *)(param_1 + 0x90 & 0xfffffffc);
  bVar4 = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) == 2;
  uVar2 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  if (bVar4) {
    unaff_r4 = uVar2 + 0x50;
  }
  uVar1 = param_1 + 0x1c & 3;
  uVar3 = *(uint *)(param_1 + 0x1c & 0xfffffffc);
  if (!bVar4) {
    unaff_r4 = uVar2 + 0x138;
  }
  GetDriverMaybeSfxPosition((undefined4 *)(void *)(auStack_30),*(undefined2 *)(param_1 + 4));
  func_0207f6f0(param_1,param_1 + 8,uVar2,uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,(undefined4)(uintptr_t)(auStack_30)
                ,unaff_r4);
  uVar1 = uVar2 + 0x180 & 3;
  uVar2 = *(uint *)(uVar2 + 0x180 & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0) {
    uVar2 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
            *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 0x78;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    func_0204360c(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,1);
    VecFx32_Subtract(param_1 + 0x44,(uint)(uintptr_t)(auStack_30),(int *)(void *)(auStack_24));
    func_01ffd224(param_1,(uint)(uintptr_t)(auStack_24),unaff_r4);
  }
  func_0207ebfc(param_1);
  return;
}

