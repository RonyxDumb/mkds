/* Decompiled C draft; module arm9; ROM address 020f11f0. No matching claim. */
#include "types.h"
#include "deps/020f11f0_func_020f11f0.h"

undefined4 func_020f11f0(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  int iVar2;
  
  uVar1 = func_02061f90();
  if ((uVar1 < *(byte *)((*(uint *)(uRam020f1254 & 0xfffffffc) >> (uRam020f1254 & 3) * 8 |
                         *(uint *)(uRam020f1254 & 0xfffffffc) << (uRam020f1254 & 3) * -8 + 0x20) +
                        0x3d0)) && (iVar2 = func_020f1258(param_1,uVar1,0,param_2), iVar2 != 0)) {
    return 1;
  }
  return 0;
}

