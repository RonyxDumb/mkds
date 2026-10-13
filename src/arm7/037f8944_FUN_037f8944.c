/* Decompiled C draft; module arm7; ROM address 037f8944. No matching claim. */
#include "types.h"
#include "deps/037f8944_FUN_037f8944.h"

void FUN_037f8944(uint param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  
  iVar3 = DAT_037f89e8;
  puVar2 = DAT_037f89e4;
  iVar1 = DAT_037f89e0;
  iVar5 = 0;
  do {
    if ((param_1 & 1) != 0) {
      if ((iVar5 < 8) || (0xb < iVar5)) {
        if ((iVar5 < 3) || (6 < iVar5)) {
          puVar4 = puVar2;
          if (iVar5 != 0) {
            *(undefined4 *)(iVar1 + iVar5 * 4) = param_2;
            puVar4 = (undefined4 *)0x0;
          }
        }
        else {
          puVar4 = (undefined4 *)((iVar5 + 1) * 0xc + iVar3);
        }
      }
      else {
        puVar4 = (undefined4 *)((iVar5 + -8) * 0xc + iVar3);
      }
      if (puVar4 != (undefined4 *)0x0) {
        *puVar4 = param_2;
        puVar4[2] = 0;
        puVar4[1] = 1;
      }
    }
    param_1 = param_1 >> 1;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x19);
  return;
}

