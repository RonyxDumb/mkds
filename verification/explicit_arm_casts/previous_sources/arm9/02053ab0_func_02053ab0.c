/* Decompiled C draft; module arm9; ROM address 02053ab0. No matching claim. */
#include "types.h"
#include "deps/02053ab0_func_02053ab0.h"

void func_02053ab0(void)

{
  undefined1 uVar1;
  undefined2 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined2 *puVar9;
  
  func_0204a52c();
  uVar3 = *(uint *)(uRam02053cf8 & 0xfffffffc) >> (uRam02053cf8 & 3) * 8 |
          *(uint *)(uRam02053cf8 & 0xfffffffc) << (uRam02053cf8 & 3) * -8 + 0x20;
  uVar4 = uVar3 + 4 & 3;
  uVar6 = *(uint *)(uVar3 + 4 & 0xfffffffc);
  uVar7 = uVar3 + 0x15c4 & 3;
  uVar8 = *(uint *)(uVar3 + 0x15c4 & 0xfffffffc);
  puVar9 = (undefined2 *)(uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20);
  if ((uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) == 8) {
    *(undefined1 *)((int)puVar9 + 5) = *(undefined1 *)(uVar3 + 0x15f7);
  }
  else {
    *(undefined1 *)((int)puVar9 + 5) = 0;
  }
  uVar4 = *(uint *)(uRam02053cf8 & 0xfffffffc) >> (uRam02053cf8 & 3) * 8 |
          *(uint *)(uRam02053cf8 & 0xfffffffc) << (uRam02053cf8 & 3) * -8 + 0x20;
  if (uVar4 == 0) {
    uVar7 = 0;
  }
  else {
    uVar7 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
            *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
  }
  if (uVar7 == 1) {
    uVar1 = *(undefined1 *)(uVar4 + 0x1eac);
  }
  else {
    uVar1 = 0;
  }
  *(undefined1 *)(puVar9 + 2) = uVar1;
  uVar2 = func_02043a20();
  *puVar9 = uVar2;
  uVar7 = uRam02053cf8;
  uVar6 = 0;
  *(byte *)(puVar9 + 3) = *(byte *)(puVar9 + 3) & 0x80;
  *(undefined1 *)((int)puVar9 + 7) = 0;
  uVar4 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar3 = uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20;
  uVar4 = uVar3 + 4 & 3;
  uVar7 = *(uint *)(uVar3 + 4 & 0xfffffffc);
  if ((uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) == 9) {
    if (uVar3 != 0) {
      uVar6 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
              *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
    }
    if (uVar6 == 1) {
      iVar5 = HasAAFlag8();
      if (iVar5 == 0) {
        *(byte *)(puVar9 + 3) = *(byte *)(puVar9 + 3) & 0xfb;
      }
      else {
        *(byte *)(puVar9 + 3) = *(byte *)(puVar9 + 3) & 0x80 | *(byte *)(puVar9 + 3) & 0x7f | 4;
      }
    }
  }
  uVar4 = *(uint *)(uRam02053cf8 & 0xfffffffc) >> (uRam02053cf8 & 3) * 8 |
          *(uint *)(uRam02053cf8 & 0xfffffffc) << (uRam02053cf8 & 3) * -8 + 0x20;
  if (uVar4 == 0) {
    uVar7 = 0;
  }
  else {
    uVar7 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
            *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
  }
  if ((uVar7 != 1) || ((*(byte *)(uVar4 + 0x8b) & 1) != 0)) {
    if (*(char *)(uVar4 + 0x15ec) == '\0') {
      *(byte *)(puVar9 + 3) = *(byte *)(puVar9 + 3) & 0x80 | *(byte *)(puVar9 + 3) & 0x7f | 1;
      *(byte *)(puVar9 + 3) = *(byte *)(puVar9 + 3) & 0xfd;
    }
    else {
      *(byte *)(puVar9 + 3) = *(byte *)(puVar9 + 3) & 0x80 | *(byte *)(puVar9 + 3) & 0x7f | 2;
      *(byte *)(puVar9 + 3) = *(byte *)(puVar9 + 3) & 0xfe;
    }
  }
  uVar4 = (*(uint *)(uRam02053cfc & 0xfffffffc) >> (uRam02053cfc & 3) * 8 |
          *(uint *)(uRam02053cfc & 0xfffffffc) << (uRam02053cfc & 3) * -8 + 0x20) + 0x30;
  uVar7 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  *(byte *)(puVar9 + 3) =
       *(byte *)(puVar9 + 3) & 0x7f |
       (byte)(((int)((uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) << 0x1c) >> 0x1f & 1U) << 7);
  uVar2 = func_02046c10();
  uVar7 = uRam02053cf8;
  puVar9[1] = uVar2;
  uVar4 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar7 = uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20;
  uVar4 = uVar7 + 0x15bc;
  uVar3 = uVar4 & 3;
  uVar6 = *(uint *)(uVar4 & 0xfffffffc);
  uVar7 = uVar7 + 0x15c0;
  uVar4 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  iVar5 = func_02144c6c(uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20,puVar9,
                        uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20);
  if ((iVar5 == 0) &&
     (uVar3 = *(uint *)(uRam02053cf8 & 0xfffffffc) >> (uRam02053cf8 & 3) * 8 |
              *(uint *)(uRam02053cf8 & 0xfffffffc) << (uRam02053cf8 & 3) * -8 + 0x20,
     uVar4 = uVar3 + 4, uVar7 = uVar4 & 3, uVar4 = *(uint *)(uVar4 & 0xfffffffc),
     (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) == 8)) {
    *(undefined1 *)(uVar3 + 0x15f7) = 0;
  }
  *(int *)((*(uint *)(uRam02053cf8 & 0xfffffffc) >> (uRam02053cf8 & 3) * 8 |
           *(uint *)(uRam02053cf8 & 0xfffffffc) << (uRam02053cf8 & 3) * -8 + 0x20) + 0x15f0) = iVar5
  ;
  return;
}

