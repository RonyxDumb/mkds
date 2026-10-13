/* Decompiled C draft; module arm9; ROM address 0212edac. No matching claim. */
#include "types.h"
#include "deps/0212edac_func_0212edac.h"

undefined4 func_0212edac(int param_1)

{
  uint uVar1;
  byte *pbVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  Sound_GetActiveSdat();
  iVar5 = 0;
  do {
    pbVar2 = (byte *)Sound_GetPlayerInfoEntry(iVar5);
    if (pbVar2 != (byte *)0x0) {
      func_0212c7b8(iVar5,*pbVar2);
      func_0212c7a0(iVar5,*(undefined2 *)(pbVar2 + 2));
      uVar1 = (uint)(pbVar2 + 4) & 3;
      uVar3 = *(uint *)((uint)(pbVar2 + 4) & 0xfffffffc);
      if (((uVar3 >> uVar1 * 8 != 0 || uVar3 << uVar1 * -8 + 0x20 != 0) && (param_1 != 0)) &&
         (iVar6 = 0, *pbVar2 != 0)) {
        do {
          uVar1 = (uint)(pbVar2 + 4) & 3;
          uVar3 = *(uint *)((uint)(pbVar2 + 4) & 0xfffffffc);
          iVar4 = func_0212c700(iVar5,param_1,uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
          if (iVar4 == 0) {
            return 0;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < (int)(uint)*pbVar2);
      }
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x20);
  return 1;
}

