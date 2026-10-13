/* Decompiled C draft; module arm9; ROM address 020eb7e0. No matching claim. */
#include "types.h"
#include "deps/020eb7e0_func_020eb7e0.h"

char func_020eb7e0(uint param_1,int param_2,char *param_3,char *param_4)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  if (((*param_3 == '\x03') &&
      (uVar2 = (*(uint *)(uRam020eb8e8 & 0xfffffffc) >> (uRam020eb8e8 & 3) * 8 |
               *(uint *)(uRam020eb8e8 & 0xfffffffc) << (uRam020eb8e8 & 3) * -8 + 0x20) + 8,
      uVar3 = uVar2 & 3, uVar2 = *(uint *)(uVar2 & 0xfffffffc),
      (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) != 1)) &&
     ((uVar2 = param_2 + 0x29cU & 3, uVar3 = *(uint *)(param_2 + 0x29cU & 0xfffffffc),
      (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) == 1 ||
      (uVar2 = param_2 + 0x2a4U & 3, uVar3 = *(uint *)(param_2 + 0x2a4U & 0xfffffffc),
      0x3000 < (int)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20))))) {
    func_020ebef8(param_1,param_2 + 0xa4);
    if ((*(uint *)((uint)puRam020eb8ec & 0xfffffffc) >> ((uint)puRam020eb8ec & 3) * 8 |
        *(uint *)((uint)puRam020eb8ec & 0xfffffffc) << ((uint)puRam020eb8ec & 3) * -8 + 0x20) ==
        param_1) {
      *puRam020eb8ec = 0;
    }
    *(undefined2 *)(param_1 + 0x90) = 1;
    uVar1 = uRam020eb8f0;
    *(undefined2 *)(param_1 + 0x92) = 1;
    func_020d26ec(param_2,uVar1);
    uVar2 = param_1 + 0x78 & 3;
    uVar3 = *(uint *)(param_1 + 0x78 & 0xfffffffc);
    *(uint *)(param_1 + 0x78) =
         uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20 |
         *(uint *)(uRam020eb8f4 & 0xfffffffc) >> (uRam020eb8f4 & 3) * 8 |
         *(uint *)(uRam020eb8f4 & 0xfffffffc) << (uRam020eb8f4 & 3) * -8 + 0x20;
    func_020d26f8(param_1,param_2);
    uVar2 = param_1 + 0x78 & 3;
    uVar3 = *(uint *)(param_1 + 0x78 & 0xfffffffc);
    if (((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) & 3) == 0) {
      if (*param_4 == '\0') {
        func_0208b498(0x31,param_1 + 4,*(undefined2 *)(param_2 + 0x74),0x1000);
        func_0208b498(0x32,param_1 + 4,*(undefined2 *)(param_2 + 0x74),0x1000);
      }
      else {
        func_0208b7bc(0x31,param_1 + 4);
        func_0208b7bc(0x32,param_1 + 4);
      }
    }
  }
  return *param_4;
}

