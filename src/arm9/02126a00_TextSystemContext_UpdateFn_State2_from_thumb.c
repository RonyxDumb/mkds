/* Decompiled C draft; module arm9; ROM address 02126a00. No matching claim. */
#include "types.h"
#include "deps/02126a00_TextSystemContext_UpdateFn_State2_from_thumb.h"

void TextSystemContext_UpdateFn_State2_from_thumb(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  bool bVar3;
  int *piVar4;
  int iVar5;
  bool bVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  
  if (*(int *)(*piRam02126c58 + iRam02126c5c) == 0) {
    param_1 = 8;
  }
  else if (*(int *)(*piRam02126c58 + iRam02126c5c) == 1) {
    param_1 = GetDirectInputUnitIndex();
  }
  param_1 = param_1 * 0x5c;
  uVar1 = *(ushort *)(iRam02126c60 + param_1);
  iVar5 = *piRam02126c58;
  uVar7 = *(int *)(iVar5 + iRam02126c64) + (uint)*(ushort *)(iRam02126c68 + param_1);
  if ((int)uVar7 < 0) {
    uVar7 = 0xff;
  }
  if (0xff < (int)uVar7) {
    uVar7 = 0xff;
  }
  uVar7 = uVar7 & 0xffff;
  if (*(int *)(iVar5 + 0x38) != 0) {
    *(undefined4 *)(iVar5 + 4) = 4;
    return;
  }
  iVar9 = *(int *)(iVar5 + 0x28);
  if (iVar9 < 1) {
    return;
  }
  bVar6 = false;
  iVar8 = -1;
  if (iVar9 == 2) {
    bVar3 = false;
    if ((*(short *)(iRam02126c6c + param_1) == 0) && (*(ushort *)(iRam02126c70 + param_1) < 5)) {
      bVar3 = true;
    }
    if (((!bVar3) && (*(short *)(iRam02126c74 + param_1) == 0)) &&
       (*(short *)(iRam02126c6c + param_1) != 0)) {
      bVar6 = true;
    }
    if (bVar6) {
      if (((uVar1 < *(byte *)(iRam02126c78 + 0x14)) || (*(byte *)(iRam02126c78 + 0x15) < uVar1)) ||
         ((uVar7 < *(byte *)(iRam02126c78 + 0x16) || (*(byte *)(iRam02126c78 + 0x17) < uVar7)))) {
        bVar6 = false;
      }
      else {
        bVar6 = true;
      }
      if (bVar6) {
        iVar8 = 0;
      }
      if (((uVar1 < *(byte *)(iRam02126c78 + 0x18)) || (*(byte *)(iRam02126c78 + 0x19) < uVar1)) ||
         ((uVar7 < *(byte *)(iRam02126c78 + 0x1a) || (*(byte *)(iRam02126c78 + 0x1b) < uVar7)))) {
        bVar6 = false;
      }
      else {
        bVar6 = true;
      }
      if (bVar6) {
        iVar8 = 1;
      }
    }
  }
  uVar2 = *(ushort *)(iRam02126c7c + param_1);
  if ((uVar2 & 1) == 0) {
    bVar3 = false;
    bVar6 = false;
    if ((*(short *)(iRam02126c6c + param_1) == 0) && (*(ushort *)(iRam02126c70 + param_1) < 5)) {
      bVar6 = true;
    }
    if (((!bVar6) && (*(short *)(iRam02126c74 + param_1) == 0)) &&
       (*(short *)(iRam02126c6c + param_1) != 0)) {
      bVar3 = true;
    }
    if ((bVar3) && (iVar9 == 1)) {
      if (((uVar1 < *(byte *)(iRam02126c78 + 0x10)) ||
          ((*(byte *)(iRam02126c78 + 0x11) < uVar1 || (uVar7 < *(byte *)(iRam02126c78 + 0x12))))) ||
         (*(byte *)(iRam02126c78 + 0x13) < uVar7)) {
        bVar6 = false;
      }
      else {
        bVar6 = true;
      }
      if (bVar6) goto LAB_02126b84;
    }
    if (iVar8 == -1) {
      if (iVar9 != 2) {
        return;
      }
      if (((uVar2 & 0x20) != 0) && (*(int *)(iVar5 + 0x2c) == 1)) {
        *(undefined4 *)(iVar5 + 0x2c) = 0;
        TextSystemContext_ReloadButtonGraphics_from_thumb();
        MaybePlaySomeSseqFromSarc0(0);
        return;
      }
      if ((uVar2 & 0x10) == 0) {
        return;
      }
      if (*(int *)(iVar5 + 0x2c) != 0) {
        return;
      }
      *(undefined4 *)(iVar5 + 0x2c) = 1;
      TextSystemContext_ReloadButtonGraphics_from_thumb();
      MaybePlaySomeSseqFromSarc0(0);
      return;
    }
  }
LAB_02126b84:
  if (iVar9 == 1) {
    TextSystemContext_ReloadButtonGraphics2_from_thumb();
  }
  else if ((iVar8 == -1) || (*(int *)(iVar5 + 0x2c) == iVar8)) {
    TextSystemContext_ReloadButtonGraphics2_from_thumb();
  }
  else {
    *(int *)(iVar5 + 0x2c) = iVar8;
    TextSystemContext_ReloadButtonGraphics_from_thumb();
  }
  piVar4 = piRam02126c58;
  *(undefined4 *)(*piRam02126c58 + 4) = 3;
  iVar5 = *piVar4;
  if ((*(int *)(iVar5 + 0x28) == 2) && (*(int *)(iVar5 + 0x2c) == 1)) {
    if (*(uint *)(iVar5 + iRam02126c80) != 0xffffffff) {
      NNSi_MaybeSndPlayerStartSeq(uRam02126c84,0,*(uint *)(iVar5 + iRam02126c80) & 0xffff);
    }
  }
  else if (*(uint *)(iVar5 + iRam02126c88) != 0xffffffff) {
    NNSi_MaybeSndPlayerStartSeq(uRam02126c84,0,*(uint *)(iVar5 + iRam02126c88) & 0xffff);
  }
  *(undefined4 *)(*piRam02126c58 + iRam02126c8c) = 1;
  return;
}

