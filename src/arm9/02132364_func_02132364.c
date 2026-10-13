/* Decompiled C draft; module arm9; ROM address 02132364. No matching claim. */
#include "types.h"
#include "deps/02132364_func_02132364.h"

undefined8 func_02132364(int param_1,undefined4 param_2)

{
  uint *puVar1;
  uint uVar2;
  undefined4 in_lr;
  undefined8 uVar3;
  
  puVar1 = (uint *)GetAlphaFlagsRef();
  uVar2 = *(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
          *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20;
  if ((uVar2 & 0x100) == 0) {
    *puVar1 = uVar2 | 1;
    return CONCAT44(param_2,~(param_1 >> 0x1f) + 0x80000000);
  }
  uVar3 = func_02134238(param_1,uRam021323bc,puVar1,uVar2,in_lr);
  return uVar3;
}

