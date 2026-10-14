/* Decompiled C draft; module arm9; ROM address 021057f0. No matching claim. */
#include "types.h"
#include "deps/021057f0_func_021057f0.h"

void func_021057f0(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined2 *puVar3;
  undefined4 uVar4;
  
  puVar3 = DAT_02105930;
  puVar2 = DAT_0210592c;
  puVar1 = DAT_02105928;
  uVar4 = 0xff;
  *DAT_02105924 = param_1;
  *puVar1 = 0;
  *puVar2 = 0;
  *puVar3 = 0xff;
  if (param_1 != 3) {
    return;
  }
  switch(param_2) {
  case 0:
    break;
  case 1:
    *puVar3 = 1;
    uVar4 = 0x25;
    break;
  case 2:
    *puVar3 = 2;
    uVar4 = 0x26;
    break;
  case 3:
    *puVar3 = 3;
    uVar4 = 0x27;
    break;
  case 4:
    *puVar3 = 4;
    uVar4 = 0x28;
    break;
  case 5:
    *puVar3 = 5;
    uVar4 = 0x29;
    break;
  case 6:
    *puVar3 = 6;
    uVar4 = 0x25;
    break;
  case 7:
    *puVar3 = 7;
    uVar4 = 0x17;
  }
  Sound_MaybeRestoreHeapState
            (*(uint *)(DAT_02105934 & 0xfffffffc) >> (DAT_02105934 & 3) * 8 |
             *(uint *)(DAT_02105934 & 0xfffffffc) << (DAT_02105934 & 3) * -8 + 0x20,
             *(uint *)(DAT_02105938 & 0xfffffffc) >> (DAT_02105938 & 3) * 8 |
             *(uint *)(DAT_02105938 & 0xfffffffc) << (DAT_02105938 & 3) * -8 + 0x20);
  Sound_Context_GetMaybeSavedFrameHeapStateId
            (*(uint *)(DAT_02105934 & 0xfffffffc) >> (DAT_02105934 & 3) * 8 |
             *(uint *)(DAT_02105934 & 0xfffffffc) << (DAT_02105934 & 3) * -8 + 0x20);
  Sound_LoadSbnk(uVar4,*(uint *)(DAT_02105934 & 0xfffffffc) >> (DAT_02105934 & 3) * 8 |
                       *(uint *)(DAT_02105934 & 0xfffffffc) << (DAT_02105934 & 3) * -8 + 0x20);
  Sound_LoadSbnk(0x2a,*(uint *)(DAT_02105934 & 0xfffffffc) >> (DAT_02105934 & 3) * 8 |
                      *(uint *)(DAT_02105934 & 0xfffffffc) << (DAT_02105934 & 3) * -8 + 0x20);
  Sound_LoadSarc(4,*(uint *)(DAT_02105934 & 0xfffffffc) >> (DAT_02105934 & 3) * 8 |
                   *(uint *)(DAT_02105934 & 0xfffffffc) << (DAT_02105934 & 3) * -8 + 0x20);
  return;
}

