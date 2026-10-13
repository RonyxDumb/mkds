/* Decompiled C draft; module arm9_ov001; ROM address 021959d8. No matching claim. */
#include "types.h"
#include "deps/021959d8_FUN_021959d8.h"

void FUN_021959d8(void)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  
  if ((*(ushort *)(DAT_02195a3c + 0x2e0) & 2) == 0) {
    bVar2 = false;
    bVar1 = false;
    if ((*(short *)(DAT_02195a40 + 0x2e0) == 0) && (*(ushort *)(DAT_02195a44 + 0x2e0) < 5)) {
      bVar1 = true;
    }
    if (((!bVar1) && (*(short *)(DAT_02195a48 + 0x2e0) == 0)) &&
       (*(short *)(DAT_02195a40 + 0x2e0) != 0)) {
      bVar2 = true;
    }
    if (!bVar2) {
      return;
    }
    iVar3 = func_0x02128210(*(undefined2 *)(DAT_02195a4c + 0x2e0),
                            *(undefined2 *)(DAT_02195a50 + 0x2e0));
    if (iVar3 == 0) {
      return;
    }
  }
  FUN_02196d8c();
  func_0x02128310(0);
  return;
}

