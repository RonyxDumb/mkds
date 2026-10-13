/* Decompiled C draft; module arm9; ROM address 0205d27c. No matching claim. */
#include "types.h"
#include "deps/0205d27c_func_0205d27c.h"

char func_0205d27c(byte param_1)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  int iVar6;
  uint uVar5;
  
  uVar1 = *(uint *)(uRam0205d358 & 0xfffffffc) >> (uRam0205d358 & 3) * 8 |
          *(uint *)(uRam0205d358 & 0xfffffffc) << (uRam0205d358 & 3) * -8 + 0x20;
  uVar5 = uVar1 + 8 & 3;
  uVar4 = *(uint *)(uVar1 + 8 & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  iVar3 = *(ushort *)(uVar1 + 0x60) - 1;
  iVar6 = iVar3 >> 0x1f;
  iVar6 = (int)(((((uint)(iVar3 * 0x40000000 + iVar6) >> 0x1e | iVar6 << 2) - iVar6 & 0xff) - 1) *
               0x1000000) >> 0x18;
  if ((((uVar5 == 2) || (uVar5 == 3)) || (uVar5 == 5)) && (iVar6 < 0)) {
    iVar6 = (iVar6 + 4) * 0x1000000 >> 0x18;
  }
  if (((uVar5 == 0) || (uVar5 == 3)) || (uVar5 == 5)) {
    if (iVar6 < 0) {
      cVar2 = *(char *)(uVar1 + 0x3d0) - param_1;
    }
    else {
      cVar2 = *(char *)((uint)param_1 * 10 +
                        iVar6 * 0x50 +
                        (*(uint *)(uRam0205d35c & 0xfffffffc) >> (uRam0205d35c & 3) * 8 |
                        *(uint *)(uRam0205d35c & 0xfffffffc) << (uRam0205d35c & 3) * -8 + 0x20) + 3)
      ;
    }
  }
  else {
    cVar2 = *(char *)(uVar1 + 0x3d0) - param_1;
  }
  if (cVar2 == '\0') {
    cVar2 = *(char *)(uVar1 + 0x3d0) - param_1;
  }
  return cVar2;
}

