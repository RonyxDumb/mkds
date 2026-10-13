/* Decompiled C draft; module arm9; ROM address 020536e0. No matching claim. */
#include "types.h"
#include "deps/020536e0_func_020536e0.h"

void func_020536e0(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  
  uVar2 = uRam02053738;
  uVar3 = uRam02053734;
  *(undefined4 *)
   ((*(uint *)(uRam02053734 & 0xfffffffc) >> (uRam02053734 & 3) * 8 |
    *(uint *)(uRam02053734 & 0xfffffffc) << (uRam02053734 & 3) * -8 + 0x20) + 0xc) = 1;
  *(undefined4 *)
   ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
    *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x10) = 1;
  uVar3 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
          *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x14;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  iVar4 = StructWM_SomeFn(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,uVar2,2);
  if (iVar4 != 2) {
    *(undefined4 *)
     ((*(uint *)(uRam02053734 & 0xfffffffc) >> (uRam02053734 & 3) * 8 |
      *(uint *)(uRam02053734 & 0xfffffffc) << (uRam02053734 & 3) * -8 + 0x20) + 0x10) = 0;
  }
  return;
}

