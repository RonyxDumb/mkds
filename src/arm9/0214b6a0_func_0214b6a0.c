/* Decompiled C draft; module arm9; ROM address 0214b6a0. No matching claim. */
#include "types.h"
#include "deps/0214b6a0_func_0214b6a0.h"

void func_0214b6a0(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(uRam0214b71c & 0xfffffffc) >> (uRam0214b71c & 3) * 8 |
          *(uint *)(uRam0214b71c & 0xfffffffc) << (uRam0214b71c & 3) * -8 + 0x20;
  iVar1 = ((*(uint *)(uRam0214b714 & 0xfffffffc) >> (uRam0214b714 & 3) * 8 |
           *(uint *)(uRam0214b714 & 0xfffffffc) << (uRam0214b714 & 3) * -8 + 0x20) + param_2) -
          (*(uint *)(uRam0214b718 & 0xfffffffc) >> (uRam0214b718 & 3) * 8 |
          *(uint *)(uRam0214b718 & 0xfffffffc) << (uRam0214b718 & 3) * -8 + 0x20);
  if (uVar2 != 0xffffffff) {
    func_0214c990(uVar2,param_1,iVar1,param_3,0,0);
    return;
  }
  Mem_CpuCopy32(param_1,iVar1,param_3,param_3);
  return;
}

