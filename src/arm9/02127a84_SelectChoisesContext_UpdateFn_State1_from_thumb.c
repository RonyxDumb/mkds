/* Decompiled C draft; module arm9; ROM address 02127a84. No matching claim. */
#include "types.h"
#include "deps/02127a84_SelectChoisesContext_UpdateFn_State1_from_thumb.h"

void SelectChoisesContext_UpdateFn_State1_from_thumb(void)

{
  ushort uVar1;
  ushort uVar2;
  bool bVar3;
  bool bVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  piVar5 = piRam02127c54;
  uVar1 = *(ushort *)(iRam02127c4c + 0x2e0);
  uVar2 = *(ushort *)(iRam02127c50 + 0x2e0);
  iVar6 = *piRam02127c54;
  if (*(int *)(iVar6 + 0x28) != 0) {
    *(undefined4 *)(iVar6 + 8) = 0;
    *(undefined4 *)(*piVar5 + 0x28) = 0;
    return;
  }
  bVar3 = false;
  bVar4 = false;
  iVar8 = -1;
  if ((*(short *)(iRam02127c58 + 0x2e0) == 0) && (*(ushort *)(iRam02127c5c + 0x2e0) < 5)) {
    bVar3 = true;
  }
  if (((!bVar3) && (*(short *)(iRam02127c60 + 0x2e0) == 0)) &&
     (*(short *)(iRam02127c58 + 0x2e0) != 0)) {
    bVar4 = true;
  }
  if (bVar4) {
    if (((uVar1 < *pbRam02127c64) || (pbRam02127c64[1] < uVar1)) ||
       ((uVar2 < pbRam02127c64[2] || (pbRam02127c64[3] < uVar2)))) {
      bVar3 = false;
    }
    else {
      bVar3 = true;
    }
    if (bVar3) {
      iVar8 = 0;
    }
    if (((uVar1 < pbRam02127c64[4]) || (pbRam02127c64[5] < uVar1)) ||
       ((uVar2 < pbRam02127c64[6] || (pbRam02127c64[7] < uVar2)))) {
      bVar3 = false;
    }
    else {
      bVar3 = true;
    }
    if (bVar3) {
      iVar8 = 1;
    }
  }
  uVar1 = *(ushort *)(iRam02127c68 + 0x2e0);
  if (((uVar1 & 1) == 0) && (iVar8 == -1)) {
    if ((uVar1 & 2) == 0) {
      if (((uVar1 & 0x40) == 0) || (*(int *)(iVar6 + 0x18) != 1)) {
        if (((uVar1 & 0x80) != 0) && (*(int *)(iVar6 + 0x18) == 0)) {
          *(undefined4 *)(iVar6 + 0x18) = 1;
          SelectChoisesContext_UpdateGraphics_from_thumb();
          if (*(int *)(*piRam02127c54 + iRam02127c6c) != 0) {
            MaybePlaySomeSseqFromSarc0(0);
          }
        }
      }
      else {
        *(undefined4 *)(iVar6 + 0x18) = 0;
        SelectChoisesContext_UpdateGraphics_from_thumb();
        if (*(int *)(*piRam02127c54 + iRam02127c6c) != 0) {
          MaybePlaySomeSseqFromSarc0(0);
          return;
        }
      }
    }
    else {
      *(undefined4 *)(iVar6 + 0x20) = 1;
      piVar5 = piRam02127c54;
      *(undefined4 *)(*piRam02127c54 + 0xc) = 0xb;
      *(undefined4 *)(*piVar5 + 8) = 2;
      iVar6 = *piVar5;
      if ((*(int *)(iVar6 + iRam02127c6c) != 0) &&
         (uVar7 = *(uint *)(iVar6 + iRam02127c74), uVar7 != 0xffffffff)) {
        MaybePlaySomeSseqFromSarc0(uVar7 & 0xffff);
        return;
      }
    }
  }
  else {
    if ((iVar8 == -1) || (*(int *)(iVar6 + 0x18) == iVar8)) {
      func_02127d28();
    }
    else {
      *(int *)(iVar6 + 0x18) = iVar8;
      SelectChoisesContext_UpdateGraphics_from_thumb();
    }
    piVar5 = piRam02127c54;
    *(undefined4 *)(*piRam02127c54 + 8) = 2;
    iVar6 = *piVar5;
    if ((*(int *)(iVar6 + iRam02127c6c) != 0) &&
       (uVar7 = *(uint *)(iVar6 + *(int *)(iVar6 + 0x18) * 4 + iRam02127c70), uVar7 != 0xffffffff))
    {
      MaybePlaySomeSseqFromSarc0(uVar7 & 0xffff);
      return;
    }
  }
  return;
}

