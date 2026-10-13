/* Decompiled C draft; module arm9; ROM address 0207f668. No matching claim. */
#include "types.h"
#include "deps/0207f668_func_0207f668.h"

void func_0207f668(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar2;
  
  uVar1 = (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
          *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) + 0x18;
  uVar3 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  puVar2 = (undefined4 *)(uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20);
  uVar4 = puVar2[1];
  uVar5 = puVar2[2];
  *(undefined4 *)(param_1 + 0x44) = *puVar2;
  *(undefined4 *)(param_1 + 0x48) = uVar4;
  *(undefined4 *)(param_1 + 0x4c) = uVar5;
  uVar1 = param_3 + 0x48U & 3;
  uVar3 = *(uint *)(param_3 + 0x48U & 0xfffffffc);
  if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x40000000) == 0) {
    uVar1 = GetSomeTimeOrDuration();
    if (0xb4 < uVar1) {
      uVar1 = param_1 + 0x90U & 3;
      uVar3 = *(uint *)(param_1 + 0x90U & 0xfffffffc);
      if ((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) == 2) {
        uVar4 = puRam0207f6ec[1];
        uVar5 = puRam0207f6ec[2];
        *(undefined4 *)(param_1 + 0x60) = *puRam0207f6ec;
        *(undefined4 *)(param_1 + 100) = uVar4;
        *(undefined4 *)(param_1 + 0x68) = uVar5;
        *(undefined4 *)(param_1 + 0x74) = 0;
      }
      else {
        func_0207e944(param_1);
      }
    }
    VecFx32_Add(param_1 + 0x44,param_1 + 0x60,param_1 + 0x44);
    return;
  }
  return;
}

