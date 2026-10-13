/* Decompiled C draft; module arm9; ROM address 02047db8. No matching claim. */
#include "types.h"
#include "deps/02047db8_MountCurrentMountEntry_from_thumb.h"

void MountCurrentMountEntry_from_thumb(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *piRam02047e00 + iRam02047e04;
  iVar2 = *piRam02047e00 + *(int *)(iVar3 + 0x8c) * 0x70;
  if ((*(int *)(iVar3 + 0x84) != 0) &&
     (iVar1 = MountMountEntryFrom(iVar2,*(undefined4 *)(iRam02047e08 + *(int *)(iVar3 + 0x8c) * 4)),
     iVar1 != 0)) {
    *(undefined4 *)(iVar2 + 0x68) = 1;
    *(undefined4 *)(iVar2 + 0x6c) = *(undefined4 *)(iVar3 + 0x84);
  }
  return;
}

