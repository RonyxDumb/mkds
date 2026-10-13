/* Decompiled C draft; module arm9; ROM address 0200cd28. No matching claim. */
#include "types.h"
#include "deps/0200cd28_Os_AllocateLockId.h"

int Os_AllocateLockId(void)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  
  iVar2 = LZCOUNT(*(uint *)((uint)puRam0200cd78 & 0xfffffffc) >> ((uint)puRam0200cd78 & 3) * 8 |
                  *(uint *)((uint)puRam0200cd78 & 0xfffffffc) <<
                  ((uint)puRam0200cd78 & 3) * -8 + 0x20);
  if (iVar2 == 0x20) {
    puVar3 = puRam0200cd78 + 1;
    iVar2 = LZCOUNT(*(uint *)((uint)puVar3 & 0xfffffffc) >> ((uint)puVar3 & 3) * 8 |
                    *(uint *)((uint)puVar3 & 0xfffffffc) << ((uint)puVar3 & 3) * -8 + 0x20);
    if (iVar2 == 0x20) {
      return iRam0200cd7c;
    }
    iVar1 = 0x60;
  }
  else {
    iVar1 = 0x40;
    puVar3 = puRam0200cd78;
  }
  *puVar3 = (*(uint *)((uint)puVar3 & 0xfffffffc) >> ((uint)puVar3 & 3) * 8 |
            *(uint *)((uint)puVar3 & 0xfffffffc) << ((uint)puVar3 & 3) * -8 + 0x20) &
            ~(0x80000000U >> iVar2);
  return iVar1 + iVar2;
}

