/* Decompiled C draft; module arm7; ROM address 03803c90. No matching claim. */
#include "types.h"
#include "deps/03803c90_FUN_03803c90.h"

void FUN_03803c90(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = *(uint *)((uint)DAT_03803d90 & 0xfffffffc) >> ((uint)DAT_03803d90 & 3) * 8 |
          *(uint *)((uint)DAT_03803d90 & 0xfffffffc) << ((uint)DAT_03803d90 & 3) * -8 + 0x20;
  if (uVar3 == 0xffffffff) {
    *DAT_03803d90 =
         (*(uint *)(DAT_03803d94 & 0xfffffffc) >> (DAT_03803d94 & 3) * 8 |
         *(uint *)(DAT_03803d94 & 0xfffffffc) << (DAT_03803d94 & 3) * -8 + 0x20) + 10;
  }
  else if (((*(uint *)((uint)DAT_03803d98 & 0xfffffffc) >> ((uint)DAT_03803d98 & 3) * 8 == 0 &&
             *(uint *)((uint)DAT_03803d98 & 0xfffffffc) << ((uint)DAT_03803d98 & 3) * -8 + 0x20 == 0
            ) && (*(uint *)((uint)DAT_03803d9c & 0xfffffffc) >> ((uint)DAT_03803d9c & 3) * 8 == 0 &&
                  *(uint *)((uint)DAT_03803d9c & 0xfffffffc) << ((uint)DAT_03803d9c & 3) * -8 + 0x20
                  == 0)) &&
          (uVar3 <= (*(uint *)(DAT_03803d94 & 0xfffffffc) >> (DAT_03803d94 & 3) * 8 |
                    *(uint *)(DAT_03803d94 & 0xfffffffc) << (DAT_03803d94 & 3) * -8 + 0x20))) {
    *DAT_03803d90 =
         (*(uint *)(DAT_03803d94 & 0xfffffffc) >> (DAT_03803d94 & 3) * 8 |
         *(uint *)(DAT_03803d94 & 0xfffffffc) << (DAT_03803d94 & 3) * -8 + 0x20) + 10;
    uVar1 = FUN_03803bcc();
    *DAT_03803d9c = uVar1;
    iVar2 = FUN_03803ac0();
    if (iVar2 == 0) {
      if (*(uint *)((uint)DAT_03803da0 & 0xfffffffc) >> ((uint)DAT_03803da0 & 3) * 8 != 0 ||
          *(uint *)((uint)DAT_03803da0 & 0xfffffffc) << ((uint)DAT_03803da0 & 3) * -8 + 0x20 != 0) {
        *DAT_03803d98 = 1;
        return;
      }
      *DAT_03803d9c = 1;
    }
    *DAT_03803da0 = 0;
    if (*(uint *)((uint)DAT_03803d9c & 0xfffffffc) >> ((uint)DAT_03803d9c & 3) * 8 != 0 ||
        *(uint *)((uint)DAT_03803d9c & 0xfffffffc) << ((uint)DAT_03803d9c & 3) * -8 + 0x20 != 0) {
      while (iVar2 = FUN_037fb5f4(0xd,0x11,0), iVar2 != 0) {
        FUN_037f8e04(100);
      }
    }
  }
  return;
}

