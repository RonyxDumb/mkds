/* Decompiled C draft; module arm9; ROM address 020fe7a0. No matching claim. */
#include "types.h"
#include "deps/020fe7a0_func_020fe7a0.h"

undefined1 * func_020fe7a0(undefined4 param_1,byte param_2,int param_3,undefined1 param_4)

{
  uint uVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  
  puVar2 = puRam020fe820;
  puRam020fe820[1] = param_4;
  puVar2[2] = param_2 | (byte)(param_3 << 4);
  uVar3 = GetSomeTimeOrDuration();
  uVar1 = uRam020fe824 & 3;
  uVar5 = *(uint *)(uRam020fe824 & 0xfffffffc);
  *puRam020fe820 = uVar3;
  if ((*(ushort *)((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + 0x724) < 3) ||
     (iVar4 = func_0205ad44(), iVar4 == 0)) {
    func_020fea84(param_1,2,puRam020fe820,3);
  }
  else {
    func_0205a858(param_1,2,puRam020fe820,3);
  }
  return puRam020fe820;
}

