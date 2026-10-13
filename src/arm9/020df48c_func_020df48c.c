/* Decompiled C draft; module arm9; ROM address 020df48c. No matching claim. */
#include "types.h"
#include "deps/020df48c_func_020df48c.h"

void func_020df48c(undefined4 param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  if (*(ushort *)(param_2 + 0x110) != uRam020df580) {
    iVar2 = func_020d84e4(param_2 + 0x108);
    if ((iVar2 != 0) &&
       (uVar1 = param_2 + 0x124U & 3, uVar3 = *(uint *)(param_2 + 0x124U & 0xfffffffc),
       *(short *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0x10) != 0)) {
      func_020d859c(param_2 + 0x108,0,1);
    }
    func_020d8c74(param_2 + 0x108,param_2 + 4);
    uVar1 = param_2 + 0x124U & 3;
    uVar3 = *(uint *)(param_2 + 0x124U & 0xfffffffc);
    if ((*(char *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0xd) == '\0') ||
       (uVar1 = param_2 + 0x128U & 3, uVar3 = *(uint *)(param_2 + 0x128U & 0xfffffffc),
       *(char *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0xd) == '\0')) {
      *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) & 0xffdf;
    }
    else {
      *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) | *puRam020df584;
    }
    uVar1 = param_2 + 8U & 3;
    uVar3 = *(uint *)(param_2 + 8U & 0xfffffffc);
    *(uint *)(param_2 + 8) =
         (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) +
         (*(uint *)(uRam020df588 & 0xfffffffc) >> (uRam020df588 & 3) * 8 |
         *(uint *)(uRam020df588 & 0xfffffffc) << (uRam020df588 & 3) * -8 + 0x20);
    uVar1 = param_2 + 8U & 3;
    uVar3 = *(uint *)(param_2 + 8U & 0xfffffffc);
    *(uint *)(param_2 + 8) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0x10000;
  }
  if (*(short *)(param_2 + 0xb0) == 0) {
    func_020e5668(param_2 + 0xb4,param_2 + 4);
  }
  func_020debec(param_1,param_2);
  return;
}

