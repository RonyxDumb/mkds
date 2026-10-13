/* Decompiled C draft; module arm9; ROM address 020fe8ac. No matching claim. */
#include "types.h"
#include "deps/020fe8ac_func_020fe8ac.h"

undefined1 * func_020fe8ac(int param_1)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar2 = param_1 * 0xa8 +
          (*(uint *)(uRam020fe94c & 0xfffffffc) >> (uRam020fe94c & 3) * 8 |
          *(uint *)(uRam020fe94c & 0xfffffffc) << (uRam020fe94c & 3) * -8 + 0x20) + 0x4c;
  uVar4 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar5 = (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 0xff;
  uVar1 = GetSomeTimeOrDuration();
  uVar2 = uRam020fe950 & 3;
  uVar4 = *(uint *)(uRam020fe950 & 0xfffffffc);
  *puRam020fe954 = uVar1;
  if (((uint)*(ushort *)((uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) + 0x724) <
       (uVar5 + 1 & 0xff)) || (iVar3 = func_0205ad44(), iVar3 == 0)) {
    func_020fea84(param_1,0,puRam020fe954,uVar5 + 1 & 0xff);
  }
  else {
    func_0205a858(param_1,0,puRam020fe954,uVar5 + 1 & 0xff);
  }
  return puRam020fe954;
}

