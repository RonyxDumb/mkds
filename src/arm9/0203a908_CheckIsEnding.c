/* Decompiled C draft; module arm9; ROM address 0203a908. No matching claim. */
#include "types.h"
#include "deps/0203a908_CheckIsEnding.h"

undefined4 CheckIsEnding(uint param_1)

{
  bool bVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar7;
  undefined4 uVar8;
  uint uVar6;
  
  uVar7 = *(uint *)(uRam0203a9d8 & 0xfffffffc) >> (uRam0203a9d8 & 3) * 8 |
          *(uint *)(uRam0203a9d8 & 0xfffffffc) << (uRam0203a9d8 & 3) * -8 + 0x20;
  uVar3 = 0x18;
  uVar6 = uVar7 + 8 & 3;
  uVar5 = *(uint *)(uVar7 + 8 & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  if (uVar6 == 0) {
    if ((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
        *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) == 0x36) {
      uVar3 = 0x19;
    }
  }
  else if (uVar6 == 4) {
    uVar3 = 0x1a;
  }
  uVar8 = 0;
  iVar4 = CheckSavedSecretFlag_from_thumb(uVar3);
  if ((iVar4 != 0) && (0xb4 < param_1)) {
    if ((uRam0203a9e0 & *(ushort *)(iRam0203a9dc + 0x2e0)) == 0) {
      bVar2 = true;
      bVar1 = false;
      if ((*(short *)(iRam0203a9e4 + 0x2e0) == 0) && (*(ushort *)(iRam0203a9e8 + 0x2e0) < 5)) {
        bVar1 = true;
      }
      if ((!bVar1) && (*(short *)(iRam0203a9e4 + 0x2e0) == 0)) {
        bVar2 = false;
      }
      if (!bVar2) {
        return 0;
      }
    }
    uVar8 = 1;
  }
  return uVar8;
}

