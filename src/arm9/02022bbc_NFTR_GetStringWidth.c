/* Decompiled C draft; module arm9; ROM address 02022bbc. No matching claim. */
#include "types.h"
#include "deps/02022bbc_NFTR_GetStringWidth.h"

int NFTR_GetStringWidth(uint param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  int iVar6;
  undefined4 local_28 [2];
  code *pcVar5;
  
  uVar1 = param_1 + 4 & 3;
  uVar4 = *(uint *)(param_1 + 4 & 0xfffffffc);
  pcVar5 = (code *)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
  iVar6 = 0;
  local_28[0] = param_3;
  iVar2 = (*pcVar5)(local_28);
  uVar1 = uRam02022c7c;
  while ((iVar2 != 0 && (iVar2 != 10))) {
    uVar4 = NFTR_GetTileIndexForCharacter(param_1);
    if (uVar4 == uVar1) {
      uVar4 = (uint)*(ushort *)
                     ((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                      *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 2);
    }
    pcVar3 = (char *)NFTR_GetCharacterWidthTileEntry(param_1,uVar4);
    if (*(short *)(param_1 + 8) == 0) {
      iVar2 = (int)pcVar3[2];
    }
    else {
      iVar2 = (int)*pcVar3 + (uint)(byte)pcVar3[1];
    }
    iVar6 = iVar6 + param_2 + iVar2;
    iVar2 = (*pcVar5)(local_28);
  }
  if (param_4 != (undefined4 *)0x0) {
    if (iVar2 != 10) {
      local_28[0] = 0;
    }
    *param_4 = local_28[0];
  }
  if (0 < iVar6) {
    iVar6 = iVar6 - param_2;
  }
  return iVar6;
}

