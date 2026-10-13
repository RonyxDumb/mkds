/* Decompiled C draft; module arm9; ROM address 02047f7c. No matching claim. */
#include "types.h"
#include "deps/02047f7c_MountArchiveEntryImpl_from_thumb.h"

void MountArchiveEntryImpl_from_thumb
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  
  iVar1 = *piRam02048034 + iRam02048038;
  SomeStrncpy_0((uint *)(uintptr_t)(iVar1),param_2,0x80);
  *(int *)(iVar1 + 0x8c) = param_1;
  *(undefined4 *)(iVar1 + 0x80) = param_3;
  *(undefined4 *)(iVar1 + 0x84) = param_4;
  *(undefined4 *)(iVar1 + 0x90) = param_5;
  *(undefined4 *)(iVar1 + 0x94) = param_6;
  *(undefined4 *)(iVar1 + 0x9c) = param_7;
  if (*psRam0204803c == 2) {
    if (*(int *)(iVar1 + 0x80) != 0) {
      if (*(int *)(iVar1 + 0x94) == 0) {
        *(int *)(iVar1 + 0x84) = *(int *)(iVar1 + 0x80);
      }
      else {
        iVar1 = (int)*(char *)(iRam02048040 + param_1 * 0x18);
        if (iVar1 != -1) {
          iVar1 = iVar1 * 0xc;
          *(uint *)(*piRam02048034 + iRam02048044 + iVar1) =
               *(uint *)(*piRam02048034 + iRam02048044 + iVar1) & uRam02048048 | uRam0204804c;
        }
        DecompressCurrentMountEntry_from_thumb();
      }
      MountCurrentMountEntry_from_thumb();
      return;
    }
  }
  else {
    if (param_1 == 0x13) {
      DecompressCurrentMountEntry_from_thumb();
    }
    else {
      ReadDecompressCurrentMountEntry_from_thumb();
    }
    MountCurrentMountEntry_from_thumb();
  }
  return;
}

