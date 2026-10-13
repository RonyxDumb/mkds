/* Decompiled C draft; module arm9; ROM address 0212e7b4. No matching claim. */
#include "types.h"
#include "deps/0212e7b4_Sound_LoadGroupImpl.h"

int Sound_LoadGroupImpl(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined1 *puVar5;
  uint uVar6;
  
  uVar2 = Sound_GetGroupInfoEntry();
  if (uVar2 == 0) {
    return 1;
  }
  uVar6 = 0;
  if (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 != 0 ||
      *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20 != 0) {
    puVar5 = (undefined1 *)(uVar2 + 4);
    do {
      switch(*puVar5) {
      case 0:
        uVar1 = (uint)(puVar5 + 4) & 3;
        uVar3 = *(uint *)((uint)(puVar5 + 4) & 0xfffffffc);
        iVar4 = NNSi_SndArcLoadSeq(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,puVar5[1],param_2
                                   ,1);
        if (iVar4 != 0) {
          return iVar4;
        }
        break;
      case 1:
        uVar1 = (uint)(puVar5 + 4) & 3;
        uVar3 = *(uint *)((uint)(puVar5 + 4) & 0xfffffffc);
        iVar4 = Sound_GetSbnkPointer
                          (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,puVar5[1],param_2,1);
        if (iVar4 != 0) {
          return iVar4;
        }
        break;
      case 2:
        uVar1 = (uint)(puVar5 + 4) & 3;
        uVar3 = *(uint *)((uint)(puVar5 + 4) & 0xfffffffc);
        iVar4 = Sound_GetSwarPointer
                          (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,puVar5[1],param_2,1);
        if (iVar4 != 0) {
          return iVar4;
        }
        break;
      case 3:
        uVar1 = (uint)(puVar5 + 4) & 3;
        uVar3 = *(uint *)((uint)(puVar5 + 4) & 0xfffffffc);
        iVar4 = Sound_GetSarcPointer
                          (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,puVar5[1],param_2,1);
        if (iVar4 != 0) {
          return iVar4;
        }
      }
      uVar6 = uVar6 + 1;
      puVar5 = puVar5 + 8;
    } while (uVar6 < (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                     *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20));
  }
  return 0;
}

