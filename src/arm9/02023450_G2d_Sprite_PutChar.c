/* Decompiled C draft; module arm9; ROM address 02023450. No matching claim. */
#include "types.h"
#include "deps/02023450_G2d_Sprite_PutChar.h"

int G2d_Sprite_PutChar(int param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5,
                      undefined2 param_6)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  char *local_20;
  int local_1c;
  
  uVar2 = NFTR_GetTileIndexForCharacter(param_2,param_6);
  if (uVar2 == uRam0202350c) {
    uVar2 = (uint)*(ushort *)
                   ((*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
                    *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) + 2);
  }
  local_20 = (char *)NFTR_GetCharacterWidthTileEntry(param_2,uVar2);
  uVar3 = (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
          *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) + 8;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  local_1c = uVar2 * *(ushort *)(uVar3 + 2) + uVar3 + 8;
  uVar2 = param_1 + 0x14U & 3;
  uVar3 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  (*(code *)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20))
            (param_1,param_2,param_3 + *local_20,param_4,param_5,&local_20);
  if (*(short *)(param_2 + 8) == 0) {
    iVar4 = (int)local_20[2];
  }
  else {
    iVar4 = (int)*local_20 + (uint)(byte)local_20[1];
  }
  return iVar4;
}

