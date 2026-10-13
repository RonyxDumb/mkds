/* Decompiled C draft; module arm9; ROM address 02078d64. No matching claim. */
#include "types.h"
#include "deps/02078d64_CreateGlobalCE_from_thumb.h"

void CreateGlobalCE_from_thumb(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  SetActiveExecutionContextHeapGroupId_from_thumb(1);
  func_02062860();
  func_02012b20(0);
  *(uint *)(*piRam02078e2c + 0x1c) = *(uint *)(*piRam02078e2c + 0x1c) & 0xfffffff7;
  func_02077bc0(param_1);
  InitializeModelResourceList();
  SetCurrentlyInKartModelMenu(1);
  InitializeGlobalCE_from_thumb(param_1);
  LoadKartAppearTablePointerCE_from_thumb(param_1,0);
  ReadKartModelMenuFile_from_thumb(param_1,uRam02078e30,*piRam02078e34 + 0x18);
  ReadKartModelMenuFile_from_thumb(param_1,uRam02078e38,*piRam02078e34 + 0x1c);
  CreateCEML_from_thumb(param_1);
  piVar1 = piRam02078e34;
  uVar3 = 0;
  do {
    CreateCESex_from_thumb(param_1,*piVar1 + iRam02078e3c + uVar3 * 0x34);
    uVar3 = uVar3 + 1 & 0xffff;
  } while (uVar3 < 2);
  iVar2 = ((int *)*puRam02078e40)[1];
  if (((*(byte *)(iVar2 + 4) & 1) != 0) &&
     (-1 < (int)((uint)*(byte *)(*(int *)*puRam02078e40 + 0x31) << 0x1c))) {
    *(int *)(*piRam02078e34 + iRam02078e44) = iVar2 + 8;
    iVar2 = GetEmblemPalette_from_thumb();
    *(undefined4 *)(*piRam02078e34 + iRam02078e48) = *(undefined4 *)(iVar2 + 0xc);
  }
  SetActiveExecutionContextHeapGroupId_from_thumb(9);
  return;
}

