/* Decompiled C draft; module arm9_ov000; ROM address 0219b27c. No matching claim. */
#include "types.h"
#include "deps/0219b27c_FUN_0219b27c.h"

void FUN_0219b27c(undefined4 param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  byte *pbVar3;
  undefined4 uVar4;
  int unaff_r4;
  uint unaff_r5;
  uint unaff_r7;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  local_2c = 0;
  local_24 = 0;
  iVar2 = FUN_021a141c();
  if (iVar2 == 0) {
    switch(param_2) {
    case 0:
    case 1:
      unaff_r4 = 0;
      break;
    case 2:
    case 3:
      unaff_r4 = 6;
      local_28 = DAT_0219b478;
      break;
    case 4:
      unaff_r4 = 0xb;
      local_28 = DAT_0219b47c;
    }
    if (unaff_r4 == 0) {
      pbVar3 = (byte *)FUN_0219887c(param_1);
      if (pbVar3 == (byte *)0x0) {
        return;
      }
      unaff_r5 = (uint)pbVar3[1];
      unaff_r7 = (uint)((*(uint *)(*DAT_0219b480 + DAT_0219b484) & 1 << unaff_r5) != 0);
      FUN_021a2ff8(unaff_r5);
      if (((*(char *)(*DAT_0219b480 + DAT_0219b488) == '\x02') && (param_2 == 0)) ||
         ((*(char *)(*DAT_0219b480 + DAT_0219b488) == '\x03' && (unaff_r5 == 0)))) {
        local_24 = 1;
      }
      local_2c = FUN_0219b868(unaff_r5);
      *(undefined4 *)(DAT_0219b48c + (uint)*pbVar3 * 4) = 0;
      piVar1 = DAT_0219b480;
      *(char *)(*DAT_0219b480 + DAT_0219b490) = *(char *)(*DAT_0219b480 + DAT_0219b490) + -1;
      *(char *)(*piVar1 + DAT_0219b494) = *(char *)(*piVar1 + DAT_0219b494) + -1;
    }
    iVar2 = *DAT_0219b480;
    if (((*(char *)(iVar2 + 0x2d) == '\0') && (*(int *)(iVar2 + 0x24) == 6)) && (unaff_r7 == 0)) {
      if ((*(char *)(iVar2 + DAT_0219b488) == '\x02') && (unaff_r4 == 0)) {
        FUN_021a1488();
        FUN_021a1798(local_2c);
        return;
      }
    }
    else {
      iVar2 = FUN_021a17bc(unaff_r4,local_28,local_2c);
      if (iVar2 == 0) {
        if (unaff_r4 != 0) {
          FUN_0219c384(unaff_r4,local_28);
          return;
        }
        iVar2 = *DAT_0219b480;
        if (*(char *)(iVar2 + DAT_0219b488) == '\x02') {
          if (*(char *)(iVar2 + 0x2d) == '\0') {
            FUN_021a1488();
          }
          else if (*(char *)(iVar2 + DAT_0219b490) == '\0') {
            FUN_0219d558(1,DAT_0219b498,0);
          }
        }
        else if (*(char *)(iVar2 + DAT_0219b490) == '\0') {
          FUN_0219d558(1,DAT_0219b498,0);
        }
        piVar1 = DAT_0219b480;
        if ((*(char *)(*DAT_0219b480 + DAT_0219b488) == '\0') ||
           (*(char *)(*DAT_0219b480 + DAT_0219b488) == '\x01')) {
          *(undefined1 *)(*DAT_0219b480 + DAT_0219b49c) =
               *(undefined1 *)(*DAT_0219b480 + DAT_0219b494);
          FUN_021a4818(*(undefined4 *)(*piVar1 + DAT_0219b4a0));
        }
        iVar2 = *DAT_0219b480;
        if ((*(int *)(iVar2 + 0x7c) != 0) && (unaff_r7 != 0)) {
          uVar4 = FUN_0219d5e4(local_2c);
          (**(code **)(*DAT_0219b480 + 0x7c))
                    (0,param_2 == 0,local_24,unaff_r5,uVar4,*(undefined4 *)(iVar2 + 0x80));
        }
        iVar2 = *DAT_0219b480;
        if (((*(char *)(iVar2 + 0x2d) != '\0') || (*(char *)(iVar2 + DAT_0219b488) != '\x02')) &&
           (*(char *)(iVar2 + DAT_0219b490) == '\0')) {
          FUN_0219b110();
          FUN_021a1a10();
          FUN_0219b8a8(3);
        }
      }
    }
  }
  return;
}

