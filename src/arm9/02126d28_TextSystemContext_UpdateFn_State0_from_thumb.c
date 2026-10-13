/* Decompiled C draft; module arm9; ROM address 02126d28. No matching claim. */
#include "types.h"
#include "deps/02126d28_TextSystemContext_UpdateFn_State0_from_thumb.h"

void TextSystemContext_UpdateFn_State0_from_thumb(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  ushort *puVar9;
  int iVar10;
  byte *pbVar11;
  int iVar12;
  uint uVar13;
  undefined4 local_3c [10];
  
  piVar1 = piRam02126e70;
  if (*(int *)(*piRam02126e70 + 0x34) != 0) {
    iVar10 = 0;
    iVar8 = 0;
    puVar7 = local_3c;
    do {
      if (iVar10 < 7) {
        if (*(int *)(*piVar1 + iVar8 + iRam02126e74) == 0) {
          *puVar7 = 0;
        }
        else {
          *puVar7 = 1;
        }
      }
      else if (*(int *)(*piVar1 + iVar8 + 4) == 0) {
        *puVar7 = 0;
      }
      else {
        *(undefined4 *)(*piVar1 + iVar8 + 4) = 0;
        *(undefined4 *)(*piVar1 + iVar8 + -4) = 1;
        *puVar7 = 1;
      }
      iVar8 = iVar8 + 4;
      puVar7 = puVar7 + 1;
      iVar10 = iVar10 + 1;
    } while (iVar10 < 9);
    TextSystemContext_LoadEnabledSpritesAndAnimations_from_thumb(local_3c);
    AllocateReserveTEQSub(10,0,*piRam02126e70 + 0x54,uRam02126e78);
    AllocateReserveTEQSub(0x18,0,*piRam02126e70 + iRam02126e7c,uRam02126e78);
    piVar1 = piRam02126e70;
    *(undefined4 *)(*piRam02126e70 + 4) = 1;
    iVar4 = 0;
    *(undefined4 *)(*piVar1 + 0xc) = 0;
    iVar10 = iRam02126e84;
    iVar8 = iRam02126e80;
    iVar6 = 0;
    do {
      iVar12 = *piVar1 + iVar6;
      *(undefined4 *)(iVar12 + iVar10) = *(undefined4 *)(iVar12 + iVar8);
      iVar3 = iRam02126e8c;
      iVar12 = iRam02126e88;
      piVar2 = piRam02126e70;
      iVar6 = iVar6 + 4;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 2);
    iVar8 = 0;
    iVar10 = 0;
    do {
      *(undefined4 *)(*piVar2 + iVar10 + iVar3) = *(undefined4 *)(*piVar2 + iVar10 + iVar12);
      iVar10 = iVar10 + 4;
      iVar8 = iVar8 + 1;
    } while (iVar8 < 2);
    uVar13 = 0;
    iVar8 = 0;
    puVar9 = puRam02126e94;
    pbVar11 = pbRam02126e90;
    do {
      iVar10 = *piRam02126e70 + iVar8;
      if (*(int *)(iVar10 + iRam02126e74) != 0) {
        uVar5 = 0x14;
        if (uVar13 < 2) {
          uVar5 = 6;
        }
        AllocateReserveTEQSub
                  (uVar5,(*(int *)(iVar10 + iRam02126e98) + (uint)*puVar9) * 0x20,
                   *(undefined4 *)(iVar10 + iRam02126e9c),(uint)pbVar11[1] * (uint)*pbVar11 * 0x20);
      }
      iVar8 = iVar8 + 4;
      pbVar11 = pbVar11 + 2;
      puVar9 = puVar9 + 1;
      uVar13 = uVar13 + 1;
    } while ((int)uVar13 < 7);
    if (0 < *(int *)(*piRam02126e70 + 0x28)) {
      TextSystemContext_ReloadButtonGraphics_from_thumb();
    }
    iVar8 = *piRam02126e70;
    if (((*(int *)(iVar8 + 0x18) == 0) && (*(int *)(iVar8 + 0x1c) == 0)) &&
       (*(uint *)(iVar8 + iRam02126ea0) != 0xffffffff)) {
      NNSi_MaybeSndPlayerStartSeq(uRam02126ea4,0,*(uint *)(iVar8 + iRam02126ea0) & 0xffff);
    }
  }
  return;
}

