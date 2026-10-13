/* Decompiled C draft; module arm9; ROM address 0207e268. No matching claim. */
#include "types.h"
#include "deps/0207e268_func_0207e268.h"

void func_0207e268(void)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  short *psVar6;
  int iVar7;
  uint uVar8;
  
  iVar7 = func_020853dc();
  uVar5 = uRam0207e348;
  uVar4 = uRam0207e340;
  puVar3 = puRam0207e338;
  uVar2 = uRam0207e334;
  if (iVar7 == 0) {
    *puRam0207e330 = uRam0207e32c;
    *puVar3 = uVar2;
  }
  else if (iVar7 == 1) {
    *puRam0207e330 = uRam0207e33c;
    *puVar3 = uVar4;
  }
  else {
    *puRam0207e330 = uRam0207e344;
    *puVar3 = uVar5;
  }
  psVar6 = psRam0207e350;
  uVar8 = *(uint *)(uRam0207e34c & 0xfffffffc) >> (uRam0207e34c & 3) * 8 |
          *(uint *)(uRam0207e34c & 0xfffffffc) << (uRam0207e34c & 3) * -8 + 0x20;
  *psRam0207e350 = 3;
  iVar7 = (uint)*(byte *)(uVar8 + 0x3d0) - (uint)*(byte *)(uVar8 + 0x3d1);
  if ((1 < iVar7) && (iVar7 < 4)) {
    *psVar6 = (short)iVar7 + -1;
  }
  uVar8 = iRam0207e354 + iVar7 * 4;
  uVar1 = uVar8 & 3;
  uVar8 = *(uint *)(uVar8 & 0xfffffffc);
  *puRam0207e358 = uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20;
  return;
}

