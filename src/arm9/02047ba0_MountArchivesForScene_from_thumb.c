/* Decompiled C draft; module arm9; ROM address 02047ba0. No matching claim. */
#include "types.h"
#include "deps/02047ba0_MountArchivesForScene_from_thumb.h"

void MountArchivesForScene_from_thumb(int param_1)

{
  if (((*DAT_02047ce8 != 2) || (param_1 != 6)) || (*(int *)(*DAT_02047cec + 0x74) != 0)) {
    Arc_MountArchive_from_thumb(1,param_1);
  }
  switch(param_1) {
  case 0:
  case 7:
  case 8:
  case 9:
  case 0xb:
  case 0xd:
  case 0xe:
  case 0xf:
    Arc_MountArchive_from_thumb(5,param_1);
    Arc_MountArchive_from_thumb(0x10,param_1);
    return;
  case 1:
  case 0xc:
    Arc_MountArchive_from_thumb(5,param_1);
    Arc_MountArchive_from_thumb(0xe,param_1);
    Arc_MountArchive_from_thumb(0x10,param_1);
    return;
  case 2:
    Arc_MountArchive_from_thumb(0x12,param_1);
    Arc_MountArchive_from_thumb(6,param_1);
    Arc_MountArchive_from_thumb(8,param_1);
    return;
  case 3:
    Arc_MountArchive_from_thumb(0,param_1);
    Arc_MountArchive_from_thumb(5,param_1);
    Arc_MountArchive_from_thumb(0x10,param_1);
    return;
  case 4:
    if (*DAT_02047ce8 != 2) {
      Arc_MountArchive_from_thumb(5,param_1);
      Arc_MountArchive_from_thumb(0x10,param_1);
      return;
    }
    break;
  case 5:
    Arc_MountArchive_from_thumb(5,param_1);
    Arc_MountArchive_from_thumb(0xe,param_1);
    Arc_MountArchive_from_thumb(0x10,param_1);
    return;
  case 6:
    if (*DAT_02047ce8 != 2) {
      Arc_MountArchive_from_thumb(5,param_1);
      Arc_MountArchive_from_thumb(0x10,param_1);
    }
    break;
  case 10:
    Arc_MountArchive_from_thumb(0,param_1);
    Arc_MountArchive_from_thumb(5,param_1);
    Arc_MountArchive_from_thumb(0x10,param_1);
    Arc_MountArchive_from_thumb(0x12,param_1);
    return;
  }
  return;
}

