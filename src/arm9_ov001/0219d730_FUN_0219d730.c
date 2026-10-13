/* Decompiled C draft; module arm9_ov001; ROM address 0219d730. No matching claim. */
#include "types.h"
#include "deps/0219d730_FUN_0219d730.h"

void FUN_0219d730(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int local_2c;
  int local_28;
  int local_20;
  int local_18;
  
  piVar1 = DAT_0219d80c;
  local_2c = 0;
  local_28 = DAT_0219d800;
  local_18 = 0;
  local_20 = 0;
  piVar3 = DAT_0219d808;
  iVar4 = DAT_0219d804;
  do {
    iVar2 = *piVar1;
    if ((local_2c == *(int *)(iVar2 + 8)) && (*(int *)(iVar2 + 0x24) != 0)) {
      *(undefined4 *)(*(int *)(iVar2 + 0x34) + (uint)*(byte *)(local_28 + 1) * 0x40) = 1;
      if (local_2c == 1) {
        iVar2 = *piVar1;
        func_0x02124100(0,0xe,*(undefined4 *)(iVar2 + 0x4c),*(undefined4 *)(iVar2 + 0x34),
                        *(undefined4 *)(iVar2 + 0x44));
      }
      iVar2 = local_20;
      if (0 < *piVar3) {
        do {
          func_0x02124a20(*(undefined1 *)(iVar4 + iVar2),0xe,*(undefined4 *)(*piVar1 + 0x38),
                          *(undefined4 *)(*piVar1 + 0x44));
          iVar2 = iVar2 + 1;
        } while (iVar2 < *piVar3);
      }
    }
    else {
      *(undefined4 *)(*(int *)(iVar2 + 0x34) + (uint)*(byte *)(local_28 + 1) * 0x40) = 0;
      if (local_2c == 1) {
        iVar2 = *piVar1;
        func_0x02124100(0,0xf,*(undefined4 *)(iVar2 + 0x4c),*(undefined4 *)(iVar2 + 0x34),
                        *(undefined4 *)(iVar2 + 0x44));
      }
      iVar2 = local_18;
      if (0 < *piVar3) {
        do {
          func_0x02124a20(*(undefined1 *)(iVar4 + iVar2),0xf,*(undefined4 *)(*piVar1 + 0x38),
                          *(undefined4 *)(*piVar1 + 0x44));
          iVar2 = iVar2 + 1;
        } while (iVar2 < *piVar3);
      }
    }
    local_28 = local_28 + 0xb;
    iVar4 = iVar4 + 2;
    piVar3 = piVar3 + 1;
    local_2c = local_2c + 1;
  } while (local_2c < 2);
  return;
}

