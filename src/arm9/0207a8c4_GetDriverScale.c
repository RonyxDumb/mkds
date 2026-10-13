/* Decompiled C draft; module arm9; ROM address 0207a8c4. No matching claim. */
#include "types.h"
#include "deps/0207a8c4_GetDriverScale.h"

void GetDriverScale(undefined4 *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = param_2 * iRam0207a8ec +
          (*(uint *)(uRam0207a8e8 & 0xfffffffc) >> (uRam0207a8e8 & 3) * 8 |
          *(uint *)(uRam0207a8e8 & 0xfffffffc) << (uRam0207a8e8 & 3) * -8 + 0x20);
  uVar2 = *(undefined4 *)(iVar1 + 0xc0);
  uVar3 = *(undefined4 *)(iVar1 + 0xc4);
  *param_1 = *(undefined4 *)(iVar1 + 0xbc);
  param_1[1] = uVar2;
  param_1[2] = uVar3;
  return;
}

