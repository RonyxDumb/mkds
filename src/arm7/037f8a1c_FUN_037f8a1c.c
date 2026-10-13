/* Decompiled C draft; module arm7; ROM address 037f8a1c. No matching claim. */
#include "types.h"
#include "deps/037f8a1c_FUN_037f8a1c.h"

int FUN_037f8a1c(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  
  uVar3 = 0;
  uVar1 = 0x80000000;
  while ((((*(uint *)((uint)DAT_037f8aac & 0xfffffffc) >> ((uint)DAT_037f8aac & 3) * 8 |
           *(uint *)((uint)DAT_037f8aac & 0xfffffffc) << ((uint)DAT_037f8aac & 3) * -8 + 0x20) &
          uVar1) == 0 && (uVar3 = uVar3 + 1, uVar3 != 0x20))) {
    uVar1 = uVar1 >> 1;
  }
  if (uVar3 == 0x20) {
    puVar4 = DAT_037f8aac + 1;
    uVar3 = 0;
    uVar1 = 0x80000000;
    while ((((*(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
             *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20) & uVar1) == 0
           && (uVar3 = uVar3 + 1, uVar3 != 0x20))) {
      uVar1 = uVar1 >> 1;
    }
    if (uVar3 == 0x20) {
      return DAT_037f8ab0;
    }
    iVar2 = 0xa0;
  }
  else {
    iVar2 = 0x80;
    puVar4 = DAT_037f8aac;
  }
  *puVar4 = (*(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
            *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20) &
            ~(0x80000000U >> (uVar3 & 0xff));
  return iVar2 + uVar3;
}

