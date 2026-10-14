/* Decompiled C draft; module arm9; ROM address 01ff9144. No matching claim. */
#include "types.h"
#include "deps/01ff9144_func_01ff9144.h"

void func_01ff9144(uint param_1,uint param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  if ((0xff < param_2) &&
     ((*(uint *)(uRam01ff9200 & 0xfffffffc) >> (uRam01ff9200 & 3) * 8 |
      *(uint *)(uRam01ff9200 & 0xfffffffc) << (uRam01ff9200 & 3) * -8 + 0x20) != 0xffffffff)) {
    func_01ff9234();
    puVar2 = puRam01ff9208;
    uVar1 = uRam01ff9204 & 3;
    uVar3 = *(uint *)(uRam01ff9204 & 0xfffffffc);
    *puRam01ff9208 = 1;
    if (uVar3 >> uVar1 * 8 != 0 || uVar3 << uVar1 * -8 + 0x20 != 0) {
      func_0214ccd4(*(uint *)(uRam01ff9200 & 0xfffffffc) >> (uRam01ff9200 & 3) * 8 |
                    *(uint *)(uRam01ff9200 & 0xfffffffc) << (uRam01ff9200 & 3) * -8 + 0x20,param_1,
                    param_2,uRam01ff920c,(undefined4)(uintptr_t)(puVar2));
      return;
    }
    func_0214ced0(*(uint *)(uRam01ff9200 & 0xfffffffc) >> (uRam01ff9200 & 3) * 8 |
                  *(uint *)(uRam01ff9200 & 0xfffffffc) << (uRam01ff9200 & 3) * -8 + 0x20,param_1,
                  param_2,uRam01ff920c,(undefined4)(uintptr_t)(puVar2));
    return;
  }
  func_01ff9048(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20,param_1 + 4,
                (param_2 >> 2) - 1);
  return;
}

