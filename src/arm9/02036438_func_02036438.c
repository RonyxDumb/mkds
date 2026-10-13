/* Decompiled C draft; module arm9; ROM address 02036438. No matching claim. */
#include "types.h"
#include "deps/02036438_func_02036438.h"

void func_02036438(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = Mem_CreateOrphanChildHeap();
  iVar2 = Mem_AllocateHeap(uVar1,uRam0203649c);
  *piRam020364a0 = iVar2;
  CARD_func_0054__mkds_36264(iVar2,uRam0203649c);
  *(undefined4 *)(*piRam020364a0 + iRam020364a4) = uVar1;
  func_020364a8(0,0,0x10,0,0);
  iVar2 = GetGlobal2DObject();
  iVar3 = *(int *)(iVar2 + 0x24);
  iVar2 = GetGlobal2DObject();
  iVar2 = *(int *)(iVar2 + 0x28);
  CopyBgData_Bg1_Bottom(*(undefined4 *)(iVar3 + 0x14),0,*(undefined4 *)(iVar3 + 0x10));
  CopyBgData_Bg3_Bottom(*(undefined4 *)(iVar3 + 0x14),0,*(undefined4 *)(iVar3 + 0x10));
  CopyPaletteBottom(*(undefined4 *)(iVar2 + 0xc),0,*(undefined4 *)(iVar2 + 8));
  return;
}

