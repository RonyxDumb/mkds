/* Decompiled C draft; module arm9; ROM address 0201e4e4. No matching claim. */
#include "types.h"
#include "deps/0201e4e4_func_0201e4e4.h"

void func_0201e4e4(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = iRam0201e53c;
  iVar2 = iRam0201e538;
  piVar1 = piRam0201e534;
  iVar4 = (*(uint *)((uint)piRam0201e534 & 0xfffffffc) >> ((uint)piRam0201e534 & 3) * 8 |
          *(uint *)((uint)piRam0201e534 & 0xfffffffc) << ((uint)piRam0201e534 & 3) * -8 + 0x20) *
          iRam0201e538 + iRam0201e53c;
  *piRam0201e534 = iVar4;
  *param_1 = iVar4 >> 8;
  iVar3 = (*(uint *)((uint)piVar1 & 0xfffffffc) >> ((uint)piVar1 & 3) * 8 |
          *(uint *)((uint)piVar1 & 0xfffffffc) << ((uint)piVar1 & 3) * -8 + 0x20) * iVar2 + iVar3;
  *piVar1 = iVar3;
  param_1[1] = iVar3 >> 8;
  param_1[2] = 0;
  VecFx32_Normalize(param_1,param_1);
  return;
}

