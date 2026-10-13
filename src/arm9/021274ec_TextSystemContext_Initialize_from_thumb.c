/* Decompiled C draft; module arm9; ROM address 021274ec. No matching claim. */
#include "types.h"
#include "deps/021274ec_TextSystemContext_Initialize_from_thumb.h"

undefined4 TextSystemContext_Initialize_from_thumb(undefined4 param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  byte *pbVar8;
  int iVar9;
  int local_2c;
  
  uVar6 = param_2[4];
  iVar2 = Mem_AllocateHeap(param_1,uRam021276d8);
  *piRam021276dc = iVar2;
  if (param_2[1] != 0) {
    *(undefined4 *)(iVar2 + 0x44) = 1;
  }
  if (param_2[2] != 0) {
    *(undefined4 *)(*piRam021276dc + 0x48) = 1;
  }
  if (param_2[3] != 0) {
    *(undefined4 *)(*piRam021276dc + 0x4c) = 1;
  }
  *(undefined4 *)(*piRam021276dc + 0x50) = 1;
  TextSystemContext_InitializeBg_from_thumb();
  uVar6 = TextSystemContext_LoadGraphics_from_thumb(uVar6);
  iVar7 = 0;
  iVar9 = 0;
  iVar2 = 0;
  local_2c = 0;
  pbVar8 = pbRam021276e0;
  do {
    if ((((iVar7 != 1) || (*(int *)(*piRam021276dc + 0x44) != 0)) &&
        ((iVar7 != 2 || (*(int *)(*piRam021276dc + 0x48) != 0)))) &&
       ((iVar7 != 3 || (*(int *)(*piRam021276dc + 0x4c) != 0)))) {
      uVar3 = Mem_AllocateHeap(param_1,(uint)pbVar8[1] * (uint)*pbVar8 * 0x20);
      *(undefined4 *)(*piRam021276dc + iVar9 + iRam021276e4) = uVar3;
      G2d_Sprite_CreateFromTiles
                (*piRam021276dc + iRam021276e8 + iVar2,
                 *(undefined4 *)(*piRam021276dc + iVar9 + iRam021276e4),*pbVar8,pbVar8[1],4);
      iVar4 = *piRam021276dc + iRam021276e8 + iVar2;
      (**(code **)(iVar4 + 0x18))(iVar4,0);
      uVar3 = *param_2;
      iVar4 = *piRam021276dc + iRam021276ec;
      iVar5 = iVar4 + local_2c;
      *(int *)(iVar4 + local_2c) = *piRam021276dc + iRam021276e8 + iVar2;
      *(undefined4 *)(iVar5 + 4) = uVar3;
      *(undefined4 *)(iVar5 + 8) = 1;
      *(undefined4 *)(iVar5 + 0xc) = 1;
    }
    pbVar8 = pbVar8 + 2;
    iVar9 = iVar9 + 4;
    iVar2 = iVar2 + 0x20;
    local_2c = local_2c + 0x10;
    iVar7 = iVar7 + 1;
  } while (iVar7 < 7);
  TextSystemContext_DisableAllSprites_from_thumb();
  piVar1 = piRam021276dc;
  iVar7 = 0;
  *(undefined4 *)*piRam021276dc = 0;
  *(undefined4 *)(*piVar1 + 4) = 0;
  *(undefined4 *)(*piVar1 + 8) = 0;
  *(undefined4 *)(*piVar1 + 0xc) = 0;
  *(undefined4 *)(*piVar1 + 0x10) = 0;
  *(undefined4 *)(*piVar1 + 0x14) = 0;
  *(undefined4 *)(*piVar1 + 0x18) = 0;
  *(undefined4 *)(*piVar1 + 0x1c) = 0;
  *(undefined4 *)(*piVar1 + 0x20) = 0;
  *(undefined4 *)(*piVar1 + 0x24) = 0;
  *(undefined4 *)(*piVar1 + iRam021276f0) = 0;
  *(undefined4 *)(*piVar1 + iRam021276f4) = 0;
  *(undefined4 *)(*piVar1 + iRam021276f8) = 0;
  *(undefined4 *)(*piVar1 + iRam021276fc) = 0;
  *(undefined4 *)(*piVar1 + 0x34) = 0;
  *(undefined4 *)(*piVar1 + 0x38) = 0;
  *(undefined4 *)(*piVar1 + 0x30) = 0;
  *(undefined4 *)(*piVar1 + iRam02127700) = 0;
  *(undefined4 *)(*piVar1 + iRam02127704) = 5;
  *(undefined4 *)(*piVar1 + iRam02127708) = 0x10;
  *(undefined4 *)(*piVar1 + iRam0212770c) = 0x23;
  iVar2 = iRam02127710;
  iVar4 = 0;
  iVar9 = 0;
  do {
    *(undefined4 *)(*piVar1 + iVar4 + iRam02127714) = 0xffffff40;
    *(undefined4 *)(*piVar1 + iVar4 + iRam02127718) = 0;
    *(undefined4 *)(*piVar1 + iVar4 + iVar2) = 0;
    iVar4 = iVar4 + 4;
    iVar7 = iVar7 + 1;
  } while (iVar7 < 2);
  *(undefined4 *)(*piVar1 + iRam0212771c) = 0x19;
  *(undefined4 *)(*piVar1 + iRam02127720) = 0x1a;
  *(undefined4 *)(*piVar1 + iRam02127724) = 0;
  iVar7 = iRam0212772c;
  iVar2 = iRam02127728;
  piVar1 = piRam021276dc;
  iVar4 = 0;
  do {
    *(undefined4 *)(*piVar1 + iVar4 + iVar2) = 6;
    *(undefined4 *)(*piVar1 + iVar4 + iVar7) = 10;
    iVar4 = iVar4 + 4;
    iVar9 = iVar9 + 1;
  } while (iVar9 < 2);
  *(undefined4 *)(*piVar1 + iRam02127730) = 0;
  return uVar6;
}

