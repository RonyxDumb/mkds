/* Decompiled C draft; module arm9; ROM address 020fe694. No matching claim. */
#include "types.h"
#include "deps/020fe694_func_020fe694.h"

undefined1 *
func_020fe694(undefined4 param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4)

{
  uint uVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  
  puVar2 = puRam020fe714;
  puRam020fe714[1] = param_2;
  puVar2[2] = param_3;
  puVar2[3] = param_4;
  uVar3 = GetSomeTimeOrDuration();
  uVar1 = uRam020fe718 & 3;
  uVar5 = *(uint *)(uRam020fe718 & 0xfffffffc);
  *puRam020fe714 = uVar3;
  if ((*(ushort *)((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + 0x724) < 4) ||
     (iVar4 = func_0205ad44(), iVar4 == 0)) {
    func_020fea84(param_1,3,puRam020fe714,4);
  }
  else {
    func_0205a858(param_1,3,puRam020fe714,4);
  }
  return puRam020fe714;
}

