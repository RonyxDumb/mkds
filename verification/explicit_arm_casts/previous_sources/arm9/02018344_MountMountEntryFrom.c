/* Decompiled C draft; module arm9; ROM address 02018344. No matching claim. */
#include "types.h"
#include "deps/02018344_MountMountEntryFrom.h"

undefined4 MountMountEntryFrom(int param_1,char *param_2,int param_3)

{
  int iVar1;
  size_t sVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  uVar7 = 0;
  uVar4 = 0;
  iVar1 = ArcEntry_ValidateNarcHeader(param_3);
  if (iVar1 == 0) {
    return 0;
  }
  uVar3 = param_3 + (uint)*(ushort *)(param_3 + 0xc);
  uVar5 = uVar4;
  uVar8 = uVar7;
  uVar10 = uVar7;
  if (*(ushort *)(param_3 + 0xe) != 0) {
    do {
      uVar9 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
              *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
      uVar4 = uVar5;
      uVar8 = uVar3;
      if ((uVar9 != uRam0201849c) && (uVar4 = uVar3, uVar8 = uVar10, uVar9 != uRam02018498)) {
        uVar4 = uVar5;
      }
      uVar5 = uVar3 + 4 & 3;
      uVar10 = *(uint *)(uVar3 + 4 & 0xfffffffc);
      uVar7 = uVar7 + 1;
      uVar3 = uVar3 + (uVar10 >> uVar5 * 8 | uVar10 << uVar5 * -8 + 0x20);
      uVar5 = uVar4;
      uVar10 = uVar8;
    } while ((int)uVar7 < (int)(uint)*(ushort *)(param_3 + 0xe));
  }
  Fs_Archive_Initialize(param_1);
  *(int *)(param_1 + 0x5c) = param_3;
  *(uint *)(param_1 + 0x60) = uVar8;
  iVar6 = uVar4 + 8;
  *(int *)(param_1 + 100) = iVar6;
  sVar2 = strlen(param_2);
  iVar1 = Fs_RegisterArchive(param_1,param_2,sVar2);
  if (iVar1 == 0) {
    return 0;
  }
  uVar4 = uVar8 + 4 & 3;
  uVar7 = *(uint *)(uVar8 + 4 & 0xfffffffc);
  iVar1 = Fs_Archive_LoadFromFatFnt
                    (param_1,iVar6,(uVar8 + 0xc) - iVar6,
                     (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) - 0xc);
  if (iVar1 != 0) {
    return 1;
  }
  Fs_UnregisterArchive(param_1);
  return 0;
}

