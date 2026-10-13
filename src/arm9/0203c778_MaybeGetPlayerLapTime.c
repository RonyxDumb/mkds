/* Decompiled C draft; module arm9; ROM address 0203c778. No matching claim. */
#include "types.h"
#include "deps/0203c778_MaybeGetPlayerLapTime.h"

void MaybeGetPlayerLapTime
               (int param_1,int param_2,undefined1 *param_3,undefined1 *param_4,undefined2 *param_5)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1 * 0x8c +
          (*(uint *)(uRam0203c7c8 & 0xfffffffc) >> (uRam0203c7c8 & 3) * 8 |
          *(uint *)(uRam0203c7c8 & 0xfffffffc) << (uRam0203c7c8 & 3) * -8 + 0x20) + 0x20;
  iVar2 = iVar1 + (param_2 + -1) * 4;
  *param_3 = *(undefined1 *)(iVar2 + 2);
  *param_4 = *(undefined1 *)(iVar2 + 3);
  *param_5 = *(undefined2 *)(iVar1 + (param_2 + -1) * 4);
  return;
}

