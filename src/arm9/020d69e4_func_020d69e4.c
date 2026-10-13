/* Decompiled C draft; module arm9; ROM address 020d69e4. No matching claim. */
#include "types.h"
#include "deps/020d69e4_func_020d69e4.h"

bool func_020d69e4(int param_1,ushort *param_2)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = (uint)*param_2;
  iVar4 = 0;
  if (99 < uVar5) {
    do {
      uVar5 = uVar5 - 100;
      iVar4 = iVar4 + 1;
    } while (99 < (int)uVar5);
  }
  uVar3 = iRam020d6a50 + iVar4 * 0x10 + param_1 * 4;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  cVar2 = *(char *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + uVar5);
  if (cVar2 == '\x01') {
    if ((param_2[1] & 0x800) == 0) {
      cVar2 = '\0';
    }
    else {
      cVar2 = '\x02';
    }
  }
  return cVar2 != '\0';
}

