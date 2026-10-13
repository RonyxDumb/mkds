/* Decompiled C draft; module arm9_ov003; ROM address 021c06e0. No matching claim. */
#include "types.h"
#include "deps/021c06e0_FUN_021c06e0.h"

void FUN_021c06e0(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined1 auStack_20 [12];
  
  *(undefined1 *)(*DAT_021c0884 + DAT_021c0888) = 0;
  iVar3 = FUN_021d299c((ushort *)(uintptr_t)(DAT_021c088c));
  uVar2 = DAT_021c0894;
  if (iVar3 != 0) {
    iVar5 = 0;
    iVar3 = DAT_021c0890;
    do {
      FUN_021d250c((short *)(uintptr_t)(iVar3),(short *)(uintptr_t)(uVar2),(short *)(void *)(auStack_20));
      iVar4 = FUN_021d299c((ushort *)(void *)(auStack_20));
      iVar6 = DAT_021c089c;
      piVar1 = DAT_021c0884;
      if (iVar4 != 0) {
        iVar3 = *DAT_021c0884;
        if (*(char *)(iVar3 + DAT_021c0898) != iVar5) {
          return;
        }
        *(undefined1 *)(iVar3 + DAT_021c0888) =
             *(undefined1 *)
              (*(int *)(DAT_021c08a0 + (uint)*(byte *)(iVar3 + DAT_021c089c) * 4) + iVar5);
        if (*(char *)(*piVar1 + iVar6) == '\x01') {
          FUN_021c00ec(0);
        }
        *(char *)(*DAT_021c0884 + DAT_021c08a4) = (char)iVar5;
        FUN_021bffb0();
        return;
      }
      iVar3 = iVar3 + 4;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 0x2f);
    iVar6 = 2;
    iVar3 = DAT_021c08ac;
    iVar5 = DAT_021c08a8;
    do {
      FUN_021d250c((short *)(uintptr_t)(iVar3),(short *)(uintptr_t)(iVar5),(short *)(void *)(auStack_20));
      iVar4 = FUN_021d299c((ushort *)(void *)(auStack_20));
      uVar2 = DAT_021c08b8;
      piVar1 = DAT_021c0884;
      if (iVar4 != 0) {
        if ((int)*(char *)(*DAT_021c0884 + DAT_021c0898) != iVar6 + 0x2f) {
          return;
        }
        *(undefined1 *)(*DAT_021c0884 + DAT_021c0888) = *(undefined1 *)(DAT_021c08b0 + iVar6);
        if (*(char *)(*piVar1 + DAT_021c089c) == '\x01') {
          FUN_021c00ec(0);
        }
        *(char *)(*DAT_021c0884 + DAT_021c08a4) = (char)iVar6 + '/';
        FUN_021bffb0();
        return;
      }
      iVar5 = iVar5 + 4;
      iVar3 = iVar3 + 4;
      iVar6 = iVar6 + 1;
    } while (iVar6 < 4);
    iVar5 = 0;
    iVar3 = DAT_021c08b4;
    do {
      FUN_021d250c((short *)(uintptr_t)(iVar3),(short *)(uintptr_t)(uVar2),(short *)(void *)(auStack_20));
      iVar6 = FUN_021d299c((ushort *)(void *)(auStack_20));
      piVar1 = DAT_021c0884;
      if (iVar6 != 0) {
        if ((int)*(char *)(*DAT_021c0884 + DAT_021c0898) != iVar5 + 0x33) {
          return;
        }
        *(undefined1 *)(*DAT_021c0884 + DAT_021c0888) = *(undefined1 *)(DAT_021c08bc + iVar5);
        *(char *)(*piVar1 + DAT_021c08a4) = (char)(iVar5 + 0x33);
        FUN_021bffb0();
        return;
      }
      iVar3 = iVar3 + 4;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 2);
    FUN_021d250c((short *)(uintptr_t)(DAT_021c08c0),(short *)(uintptr_t)(DAT_021c08c4),(short *)(void *)(auStack_20));
    iVar3 = FUN_021d299c((ushort *)(void *)(auStack_20));
    if (iVar3 == 0) {
      FUN_021d250c((short *)(uintptr_t)(DAT_021c08c8),(short *)(uintptr_t)(DAT_021c08cc),auStack_20);
      iVar3 = FUN_021d299c(auStack_20);
      if ((iVar3 != 0) && (*(char *)(*DAT_021c0884 + DAT_021c0898) == '0')) {
        FUN_021c0680();
        *(undefined1 *)(*DAT_021c0884 + DAT_021c08a4) = 0x30;
        FUN_021bffb0();
      }
    }
    else if (*(char *)(*DAT_021c0884 + DAT_021c0898) == '/') {
      FUN_021c06b0();
      *(undefined1 *)(*DAT_021c0884 + DAT_021c08a4) = 0x2f;
      FUN_021bffb0();
      return;
    }
  }
  return;
}

