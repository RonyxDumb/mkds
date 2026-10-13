/* Decompiled C draft; module arm9; ROM address 02128058. No matching claim. */
#include "types.h"
#include "deps/02128058_SelectChoisesContext_Initialize_from_thumb.h"

undefined4
SelectChoisesContext_Initialize_from_thumb(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 local_24;
  undefined4 local_20;
  
  iVar2 = Mem_AllocateHeap(param_1,uRam0212817c);
  *piRam02128180 = iVar2;
  if (*psRam02128184 == 2) {
    *(undefined4 *)(iVar2 + iRam02128188) = 0;
    *puRam0212818c =
         *puRam0212818c & uRam02128194 | ((*puRam0212818c & uRam02128190) >> 8 & 0xfffffffe) << 8;
    local_24 = param_3;
  }
  else {
    SelectChoisesContext_InitializeBg_from_thumb();
    local_24 = SelectChoisesContext_LoadGraphics_from_thumb(param_3);
    *(undefined4 *)(*piRam02128180 + iRam02128188) = 1;
  }
  iVar6 = 0;
  local_20 = 0;
  iVar2 = 0;
  iVar7 = 0;
  do {
    uVar3 = Mem_AllocateHeap(param_1,uRam02128198);
    *(undefined4 *)(*piRam02128180 + iVar6 + iRam0212819c) = uVar3;
    G2d_Sprite_CreateFromTiles
              (*piRam02128180 + iRam021281a0 + iVar2,
               *(undefined4 *)(*piRam02128180 + iVar6 + iRam0212819c),0x20,2,4);
    iVar4 = *piRam02128180 + iRam021281a0 + iVar2;
    (**(code **)(iVar4 + 0x18))(iVar4,0);
    uVar3 = ComputeSomeInterCharacterWidth();
    iVar4 = *piRam02128180 + iRam021281a4;
    iVar5 = iVar4 + iVar7;
    *(int *)(iVar4 + iVar7) = *piRam02128180 + iRam021281a0 + iVar2;
    *(undefined4 *)(iVar5 + 4) = param_2;
    *(undefined4 *)(iVar5 + 8) = uVar3;
    *(undefined4 *)(iVar5 + 0xc) = 0;
    iVar6 = iVar6 + 4;
    iVar2 = iVar2 + 0x20;
    iVar7 = iVar7 + 0x10;
    local_20 = local_20 + 1;
  } while (local_20 < 2);
  func_021281b4();
  piVar1 = piRam02128180;
  *(undefined4 *)*piRam02128180 = 1;
  *(undefined4 *)(*piVar1 + 4) = 0;
  *(undefined4 *)(*piVar1 + 8) = 0;
  *(undefined4 *)(*piVar1 + 0xc) = 0;
  *(undefined4 *)(*piVar1 + 0x10) = 0;
  *(undefined4 *)(*piVar1 + 0x14) = 1;
  *(undefined4 *)(*piVar1 + 0x24) = 0;
  *(undefined4 *)(*piVar1 + 0x28) = 0;
  *(undefined4 *)(*piVar1 + 0x1c) = 0;
  *(undefined4 *)(*piVar1 + 0x20) = 0;
  *(undefined4 *)(*piVar1 + iRam021281a8) = 7;
  *(undefined4 *)(*piVar1 + iRam021281ac) = 0x10;
  *(undefined4 *)(*piVar1 + iRam021281b0) = 0x10;
  return local_24;
}

