/* Decompiled C draft; module arm9_ov001; ROM address 0219a258. No matching claim. */
#include "types.h"
#include "deps/0219a258_FUN_0219a258.h"

void FUN_0219a258(void)

{
  bool bVar1;
  int iVar2;
  bool bVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  
  puVar4 = (undefined2 *)(DAT_0219a2d0 + 0x2e0);
  puVar5 = (undefined2 *)(DAT_0219a2d4 + 0x2e0);
  func_0x0201ea84(*(undefined4 *)(*DAT_0219a2d8 + 0x14),*(undefined2 *)(DAT_0219a2d4 + 0x2e0),
                  *(undefined2 *)(DAT_0219a2d0 + 0x2e0));
  if ((*(ushort *)(DAT_0219a2dc + 0x2e0) & 2) == 0) {
    bVar3 = false;
    bVar1 = false;
    if ((*(short *)(DAT_0219a2e0 + 0x2e0) == 0) && (*(ushort *)(DAT_0219a2e4 + 0x2e0) < 5)) {
      bVar1 = true;
    }
    if (((!bVar1) && (*(short *)(DAT_0219a2e8 + 0x2e0) == 0)) &&
       (*(short *)(DAT_0219a2e0 + 0x2e0) != 0)) {
      bVar3 = true;
    }
    if (!bVar3) {
      return;
    }
    iVar2 = func_0x02128210(*puVar5,*puVar4);
    if (iVar2 == 0) {
      return;
    }
  }
  FUN_0219ad7c();
  func_0x02128310(0);
  return;
}

