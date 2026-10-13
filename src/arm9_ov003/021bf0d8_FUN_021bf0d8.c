/* Decompiled C draft; module arm9_ov003; ROM address 021bf0d8. No matching claim. */
#include "types.h"
#include "deps/021bf0d8_FUN_021bf0d8.h"

void FUN_021bf0d8(void)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined1 auStack_20 [12];
  
  iVar3 = DAT_021bf1c0;
  iVar5 = *DAT_021bf1b8;
  uVar7 = (uint)*(byte *)(DAT_021bf1bc + (uint)*(byte *)(iVar5 + 0x17));
  if (*(char *)(iVar5 + 0x18) == '\0') {
    iVar6 = 0;
    if (*(char *)(iVar5 + 0x16) != -1) {
      return;
    }
    if (uVar7 != 0) {
      do {
        FUN_021d250c((short *)(uintptr_t)(iVar3 + (uint)*(byte *)(iVar6 + DAT_021bf1c4 +
                                                     (uint)*(byte *)(*DAT_021bf1b8 + 0x17) * 2) * 4),
                     (short *)(uintptr_t)(DAT_021bf1c8),(short *)(void *)(auStack_20));
        iVar5 = FUN_021d2a34((ushort *)(void *)(auStack_20));
        if (iVar5 != 0) {
          iVar3 = *DAT_021bf1b8;
          if (*(int *)(iVar3 + 0x10) == 0) {
            bVar1 = *(byte *)(iVar6 + DAT_021bf1cc + (uint)*(byte *)(iVar3 + 0x17) * 2);
            iVar5 = iVar6 * 4;
            uVar4 = FUN_021d1974(*(undefined4 *)(iVar3 + iVar5),0);
            FUN_021d1c3c(0,bVar1 + 1,uVar4);
            iVar3 = (uint)*(byte *)(iVar6 + DAT_021bf1c4 + (uint)*(byte *)(*DAT_021bf1b8 + 0x17) * 2
                                   ) * 4;
            FUN_021d17d4(*(undefined4 *)(*DAT_021bf1b8 + iVar5),0xffffffff,
                         *(undefined2 *)(DAT_021bf1c0 + iVar3),*(undefined2 *)(DAT_021bf1d0 + iVar3)
                        );
            FUN_021d1790(*(undefined4 *)(*DAT_021bf1b8 + iVar5),0xffffffff,1);
            uVar4 = FUN_021d3544(0,DAT_021bf1d4,0,0x6e);
            piVar2 = DAT_021bf1b8;
            *(undefined4 *)(*DAT_021bf1b8 + 0x10) = uVar4;
            *(char *)(*piVar2 + 0x16) = (char)iVar6;
            return;
          }
          break;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < (int)uVar7);
    }
  }
  *(undefined1 *)(*DAT_021bf1b8 + 0x16) = 0xff;
  return;
}

