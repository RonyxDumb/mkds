/* Decompiled C draft; module arm9; ROM address 02061220. No matching claim. */
#include "types.h"
#include "deps/02061220_func_02061220.h"

void func_02061220(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  
  uVar2 = *(uint *)(uRam0206124c & 0xfffffffc) >> (uRam0206124c & 3) * 8 |
          *(uint *)(uRam0206124c & 0xfffffffc) << (uRam0206124c & 3) * -8 + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar3 = PlayerProfileInfo_GetProfileId_from_thumb
                    ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0x4c);
  PrintfUll_from_thumb((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),param_1);
  return;
}

