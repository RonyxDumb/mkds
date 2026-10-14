/* Decompiled C draft; module arm9; ROM address 02004c20. No matching claim. */
#include "types.h"
#include "deps/02004c20_Fs_File_FindPath.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void Fs_File_FindPath(int param_1,char *param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  uint local_28;
  undefined4 local_24;
  uint local_20;
  
  if ((*param_2 == '/') || (*param_2 == '\\')) {
    local_28 = *(uint *)((uint)puRam02004d7c & 0xfffffffc) >> ((uint)puRam02004d7c & 3) * 8 |
               *(uint *)((uint)puRam02004d7c & 0xfffffffc) << ((uint)puRam02004d7c & 3) * -8 + 0x20;
    local_20 = 0;
    local_24 = 0;
    param_2 = param_2 + 1;
  }
  else {
    local_28 = *puRam02004d7c;
    local_24 = puRam02004d7c[1];
    local_20 = puRam02004d7c[2];
    iVar4 = 0;
    do {
      cVar2 = param_2[iVar4];
      if (((cVar2 == '\0') || (cVar2 == '/')) || (cVar2 == '\\')) break;
      if (cVar2 == ':') {
        local_28 = Fs_FindArchiveByMountName(param_2,iVar4);
        if (local_28 == 0) {
          return;
        }
        uVar1 = local_28 + 0x1c & 3;
        uVar3 = *(uint *)(local_28 + 0x1c & 0xfffffffc);
        if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 2) == 0) {
          return;
        }
        local_20 = 0;
                    /* WARNING: Ignoring partial resolution of indirect */
        MKDS_SLICE_2(local_24,2) = 0;
                    /* WARNING: Ignoring partial resolution of indirect */
        MKDS_SLICE_2(local_24,0) = 0;
        param_2 = param_2 + iVar4 + 1;
        if ((*param_2 == '/') || (*param_2 == '\\')) {
          param_2 = param_2 + 1;
        }
        break;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 4);
  }
  *(uint *)(param_1 + 8) = local_28;
  *(char **)(param_1 + 0x3c) = param_2;
  *(uint *)(param_1 + 0x30) = local_28;
  *(uint *)(param_1 + 0x34) = local_24;
  *(uint *)(param_1 + 0x38) = local_20;
  if (param_4 == 0) {
    *(undefined4 *)(param_1 + 0x40) = 0;
    *(undefined4 *)(param_1 + 0x44) = param_3;
  }
  else {
    *(undefined4 *)(param_1 + 0x40) = 1;
    *(int *)(param_1 + 0x44) = param_4;
  }
  Fs_File_SendOperation((uint *)(uintptr_t)(param_1),4);
  return;
}

