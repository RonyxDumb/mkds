/* Decompiled C draft; module arm9; ROM address 020222ec. No matching claim. */
#include "types.h"
#include "deps/020222ec_func_020222ec.h"

bool func_020222ec(int *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  bool bVar4;
  ushort *puVar3;
  
  uVar1 = (uint)(param_1 + 6) & 3;
  uVar2 = *(uint *)((uint)(param_1 + 6) & 0xfffffffc);
  puVar3 = (ushort *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  bVar4 = param_2 < *puVar3;
  if (bVar4) {
    puVar3 = puVar3 + 6;
    uVar1 = (uint)puVar3 & 3;
    uVar2 = *(uint *)((uint)puVar3 & 0xfffffffc);
    *param_1 = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + param_2 * 8;
  }
  return bVar4;
}

