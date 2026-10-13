/* Decompiled C draft; module arm9; ROM address 0206302c. No matching claim. */
#include "types.h"
#include "deps/0206302c_func_0206302c.h"

void func_0206302c(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar2 = uRam020631ac;
  uVar3 = *(uint *)(uRam020631a8 & 0xfffffffc) >> (uRam020631a8 & 3) * 8 |
          *(uint *)(uRam020631a8 & 0xfffffffc) << (uRam020631a8 & 3) * -8 + 0x20;
  *(undefined4 *)(uRam020631ac + 0xe0) = 0;
  *(undefined4 *)(uVar2 + 0xe4) = 0;
  *(undefined4 *)(uVar2 + 0xe8) = 0;
  *(undefined4 *)(uVar2 + 0xec) = 0;
  *(undefined2 *)(uVar2 + 0xf0) = 0;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if ((int)uVar4 < 0x1e) {
    if ((int)uVar4 < 0x1b) {
      if (uVar4 != 0x12) goto LAB_020630a4;
    }
    else if (uVar4 != 0x1b) {
      if (uVar4 == 0x1d) {
        *(undefined4 *)(uVar2 + 0xec) = 1;
      }
      goto LAB_020630a4;
    }
  }
  else if (uVar4 != 0x2d) goto LAB_020630a4;
  *(undefined4 *)(uRam020631ac + 0xe0) = 1;
LAB_020630a4:
  uVar2 = uRam020631ac;
  uVar4 = uRam020631ac + 0xe0 & 3;
  uVar3 = *(uint *)(uRam020631ac + 0xe0 & 0xfffffffc);
  if (uVar3 >> uVar4 * 8 == 0 && uVar3 << uVar4 * -8 + 0x20 == 0) {
    uVar4 = (*(uint *)(uRam020631ac & 0xfffffffc) >> (uRam020631ac & 3) * 8 |
            *(uint *)(uRam020631ac & 0xfffffffc) << (uRam020631ac & 3) * -8 + 0x20) + 4;
    uVar2 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    Maybe_helper_013044(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20,1);
  }
  else {
    uVar8 = 0;
    uVar4 = (*(uint *)(uRam020631ac & 0xfffffffc) >> (uRam020631ac & 3) * 8 |
            *(uint *)(uRam020631ac & 0xfffffffc) << (uRam020631ac & 3) * -8 + 0x20) + 4;
    uVar3 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar4 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
    if (*(char *)(uVar4 + 0x18) != '\0') {
      do {
        iVar5 = func_02013314(uVar4,uVar8);
        if (iVar5 != 0) {
          uVar3 = uVar2 + 0xe4 & 3;
          uVar7 = *(uint *)(uVar2 + 0xe4 & 0xfffffffc);
          uVar1 = uVar2 + 0xe8 & 3;
          uVar6 = *(uint *)(uVar2 + 0xe8 & 0xfffffffc);
          *(uint *)(uVar2 + 0xe4) =
               uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20 | 1 << (uVar8 & 0xff);
          *(uint *)(uVar2 + 0xe8) =
               uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20 | (1 << (uVar8 & 0xff)) >> 0x1f;
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 < *(byte *)(uVar4 + 0x18));
    }
  }
  uVar2 = uRam020631ac;
  uVar4 = uRam020631ac + 4 & 3;
  uVar3 = *(uint *)(uRam020631ac + 4 & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if (uVar4 == 0) {
    return;
  }
  uVar3 = uRam020631ac + 0xec & 3;
  uVar8 = *(uint *)(uRam020631ac + 0xec & 0xfffffffc);
  if (uVar8 >> uVar3 * 8 == 0 && uVar8 << uVar3 * -8 + 0x20 == 0) {
    return;
  }
  uVar4 = uVar4 + 4;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar4 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  uVar3 = 0;
  if (*(char *)(uVar4 + 0x18) != '\0') {
    do {
      iVar5 = func_02013314(uVar4,uVar3);
      if (iVar5 != 0) {
        *(ushort *)(uVar2 + 0xf0) = *(ushort *)(uVar2 + 0xf0) | (ushort)(1 << (uVar3 & 0xff));
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(byte *)(uVar4 + 0x18));
    return;
  }
  return;
}

