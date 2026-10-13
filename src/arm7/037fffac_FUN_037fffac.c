/* Decompiled C draft; module arm7; ROM address 037fffac. No matching claim. */
#include "types.h"
#include "deps/037fffac_FUN_037fffac.h"

void FUN_037fffac(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  iVar1 = FUN_038005c8();
  if (iVar1 != 0) {
    *(undefined4 *)(DAT_03800048 + 0xc) = 1;
    uVar2 = (*(uint *)((uint)PTR_DAT_0380004c & 0xfffffffc) >> ((uint)PTR_DAT_0380004c & 3) * 8 |
            *(uint *)((uint)PTR_DAT_0380004c & 0xfffffffc) <<
            ((uint)PTR_DAT_0380004c & 3) * -8 + 0x20) + 0x24;
    uVar3 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    FUN_038006f0((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 1 + param_3);
    FUN_03800350(param_1,3);
    FUN_03800538(param_2,0,param_3,PTR_LAB_03800050);
    FUN_03800610(0,0);
    puVar4 = (undefined4 *)
             (*(uint *)((uint)PTR_DAT_0380004c & 0xfffffffc) >> ((uint)PTR_DAT_0380004c & 3) * 8 |
             *(uint *)((uint)PTR_DAT_0380004c & 0xfffffffc) <<
             ((uint)PTR_DAT_0380004c & 3) * -8 + 0x20);
    if ((*(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 == 0 &&
         *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20 == 0) &&
       (uVar2 = DAT_03800048 + 0xcU & 3, uVar3 = *(uint *)(DAT_03800048 + 0xcU & 0xfffffffc),
       uVar3 >> uVar2 * 8 == 0 && uVar3 << uVar2 * -8 + 0x20 == 0)) {
      *puVar4 = 1;
    }
  }
  return;
}

