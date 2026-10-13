/* Decompiled C draft; module arm9; ROM address 020d6968. No matching claim. */
#include "types.h"
#include "deps/020d6968_func_020d6968.h"

bool func_020d6968(int param_1,ushort *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  uVar8 = (uint)*param_2;
  iVar6 = 0;
  if (99 < uVar8) {
    do {
      uVar8 = uVar8 - 100;
      iVar6 = iVar6 + 1;
    } while (99 < (int)uVar8);
  }
  uVar1 = (uint)(param_2 + 0x4c) & 3;
  uVar7 = *(uint *)((uint)(param_2 + 0x4c) & 0xfffffffc);
  uVar3 = iVar6 * 0x38 + iRam020d69e0 + param_1 * 4;
  uVar2 = uVar3 & 3;
  uVar5 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = (uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20) + 0x20;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  cVar4 = *(char *)((uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) + uVar8);
  if ((((param_2[1] & 0x800) != 0) && (cVar4 == '\x01')) &&
     (uVar3 >> uVar1 * 8 != 0 || uVar3 << uVar1 * -8 + 0x20 != 0)) {
    cVar4 = '\x02';
  }
  return cVar4 != '\0';
}

