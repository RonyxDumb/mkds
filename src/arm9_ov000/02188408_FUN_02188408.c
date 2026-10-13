/* Decompiled C draft; module arm9_ov000; ROM address 02188408. No matching claim. */
#include "types.h"
#include "deps/02188408_FUN_02188408.h"

undefined4 FUN_02188408(void)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  iVar6 = *DAT_0218848c;
  iVar4 = iVar6 + DAT_02188490;
  bVar1 = *(byte *)(iVar6 + DAT_02188494);
  if (5 < *(byte *)(iVar6 + DAT_02188498)) {
    return 1;
  }
  uVar5 = 0;
  bVar2 = *(byte *)(iVar6 + DAT_0218849c);
  if (bVar2 != 0) {
    do {
      if (((uVar5 != bVar1) && (*(byte *)(iVar6 + uVar5 * 4 + DAT_021884a0) < 6)) &&
         (iVar3 = func_0x0213a038(iVar4 + (uint)bVar1 * 0xc0,iVar6 + DAT_02188490 + uVar5 * 0xc0,
                                  *(undefined2 *)(iVar6 + uVar5 * 0xc0 + DAT_021884a4)), iVar3 == 0)
         ) {
        return 2;
      }
      uVar5 = uVar5 + 1 & 0xff;
    } while (uVar5 < bVar2);
  }
  return 1;
}

