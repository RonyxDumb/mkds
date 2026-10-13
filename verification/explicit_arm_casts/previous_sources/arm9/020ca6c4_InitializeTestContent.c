/* Decompiled C draft; module arm9; ROM address 020ca6c4. No matching claim. */
#include "types.h"
#include "deps/020ca6c4_InitializeTestContent.h"

void InitializeTestContent(void)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 local_20 [3];
  
  uVar2 = GetActiveExecutionContextHeapHandle_5();
  puVar3 = (undefined4 *)Mem_AllocateHeap(uVar2,0x6c);
  piVar1 = piRam020ca7c4;
  *piRam020ca7c4 = (int)puVar3;
  *puVar3 = 0;
  *(undefined4 *)(*piVar1 + 4) = 1;
  *(undefined4 *)(*piVar1 + 8) = 0;
  *(undefined4 *)(*piVar1 + 0xc) = 0;
  func_020cac9c();
  piVar1 = piRam020ca7c4;
  *(undefined4 *)(*piRam020ca7c4 + 0x24) = 0;
  *(undefined4 *)(*piVar1 + 0x10) = 0;
  *(undefined4 *)(*piVar1 + 0x14) = 0;
  *(undefined4 *)(*piVar1 + 0x18) = 0;
  *(undefined4 *)(*piVar1 + 0x28) = 3;
  uVar2 = func_020b47c0(uRam020ca7c8);
  Gfx_ReadPalette(*piRam020ca7c4 + 0x60,uVar2);
  uVar2 = func_020b47c0(uRam020ca7cc);
  Gfx_ReadCharGraphicsV2(*piRam020ca7c4 + 100,uVar2);
  uVar2 = func_020b47c0(uRam020ca7d0);
  MaybeReadScreenBlock_0(*piRam020ca7c4 + 0x68,uVar2);
  uVar2 = GetLoadedFont_from_thumb(2);
  piVar1 = piRam020ca7c4;
  *(undefined4 *)(*piRam020ca7c4 + 0x2c) = uVar2;
  G2d_Sprite_CreateFromTiles
            (*piVar1 + 0x30,*(undefined4 *)(*(int *)(*piVar1 + 100) + 0x14),0x20,0xc,4);
  iVar5 = *piRam020ca7c4;
  uVar2 = ComputeSomeInterCharacterWidth();
  G2d_Text_Create_0(iVar5 + 0x50,iVar5 + 0x30,*(undefined4 *)(iVar5 + 0x2c),uVar2,0);
  uVar2 = uRam020ca7d8;
  piVar1 = piRam020ca7c4;
  local_20[0] = *puRam020ca7d4;
  local_20[1] = puRam020ca7d4[1];
  local_20[2] = puRam020ca7d4[2];
  for (iVar5 = 0; iVar5 < *(int *)(*piVar1 + 0x28); iVar5 = iVar5 + 1) {
    uVar4 = func_020b47c0(uRam020ca7dc);
    uVar4 = Bmg_GetRawStringPointer_from_thumb(uVar4,local_20[iVar5]);
    G2d_Text_PrintString5(*piVar1 + 0x50,0x90,iVar5 * 0x10 + 9,0xc,uVar2,uVar4);
  }
  return;
}

