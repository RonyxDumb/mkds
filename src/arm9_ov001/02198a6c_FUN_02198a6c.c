/* Decompiled C draft; module arm9_ov001; ROM address 02198a6c. No matching claim. */
#include "types.h"
#include "deps/02198a6c_FUN_02198a6c.h"

void FUN_02198a6c(void)

{
  undefined *puVar1;
  int iVar2;
  byte *pbVar3;
  undefined *puVar4;
  int local_2c;
  byte *local_28;
  undefined1 *local_24;
  int local_20;
  int local_18;
  
  puVar1 = PTR_data_ov001_02198b54;
  local_2c = 0;
  local_28 = PTR_data_ov001_02198b44;
  local_24 = PTR_data_ov001_02198b48;
  local_18 = 0;
  local_20 = 0;
  pbVar3 = PTR_data_ov001_02198b50;
  puVar4 = PTR_data_ov001_02198b4c;
  do {
    iVar2 = *(int *)puVar1;
    if ((local_2c == *(int *)(iVar2 + 8)) && (*(int *)(iVar2 + 0x38) != 0)) {
      *(undefined4 *)(*(int *)(iVar2 + 0x58) + (uint)*local_28 * 0x40) = 1;
      iVar2 = *(int *)puVar1;
      func_0x02124100(*local_24,0xe,*(undefined4 *)(iVar2 + 0x84),*(undefined4 *)(iVar2 + 0x58),
                      *(undefined4 *)(iVar2 + 0x78));
      iVar2 = local_20;
      if (*pbVar3 != 0) {
        do {
          func_0x02124a20(puVar4[iVar2],0xe,*(undefined4 *)(*(int *)puVar1 + 0x60),
                          *(undefined4 *)(*(int *)puVar1 + 0x78));
          iVar2 = iVar2 + 1;
        } while (iVar2 < (int)(uint)*pbVar3);
      }
    }
    else {
      *(undefined4 *)(*(int *)(iVar2 + 0x58) + (uint)*local_28 * 0x40) = 0;
      iVar2 = *(int *)puVar1;
      func_0x02124100(*local_24,0xf,*(undefined4 *)(iVar2 + 0x84),*(undefined4 *)(iVar2 + 0x58),
                      *(undefined4 *)(iVar2 + 0x78));
      iVar2 = local_18;
      if (*pbVar3 != 0) {
        do {
          func_0x02124a20(puVar4[iVar2],0xf,*(undefined4 *)(*(int *)puVar1 + 0x60),
                          *(undefined4 *)(*(int *)puVar1 + 0x78));
          iVar2 = iVar2 + 1;
        } while (iVar2 < (int)(uint)*pbVar3);
      }
    }
    local_28 = local_28 + 1;
    local_24 = local_24 + 1;
    puVar4 = puVar4 + 3;
    pbVar3 = pbVar3 + 1;
    local_2c = local_2c + 1;
  } while (local_2c < 3);
  return;
}

