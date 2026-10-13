/* Decompiled C draft; module arm9; ROM address 02053094. No matching claim. */
#include "types.h"
#include "deps/02053094_func_02053094.h"

void func_02053094(uint param_1)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  uVar4 = uRam02053294;
  *(undefined4 *)
   ((*(uint *)(uRam02053294 & 0xfffffffc) >> (uRam02053294 & 3) * 8 |
    *(uint *)(uRam02053294 & 0xfffffffc) << (uRam02053294 & 3) * -8 + 0x20) + 0xc) = 4;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  *(undefined4 *)((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) + 0x10) = 1;
  uVar4 = func_02143280();
  uVar3 = uRam02053294;
  if (uVar4 == 0) {
    *(undefined4 *)
     ((*(uint *)(uRam02053294 & 0xfffffffc) >> (uRam02053294 & 3) * 8 |
      *(uint *)(uRam02053294 & 0xfffffffc) << (uRam02053294 & 3) * -8 + 0x20) + 0x10) = 0;
    *(undefined4 *)
     ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
      *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 8) = 3;
    *(undefined4 *)
     ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
      *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x10) = 0;
  }
  else if (uVar4 == 0x8000) {
    *(undefined4 *)
     ((*(uint *)(uRam02053294 & 0xfffffffc) >> (uRam02053294 & 3) * 8 |
      *(uint *)(uRam02053294 & 0xfffffffc) << (uRam02053294 & 3) * -8 + 0x20) + 0x10) = 0;
    *(undefined4 *)
     ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
      *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 8) = 8;
    *(undefined4 *)
     ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
      *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x10) = 0;
  }
  uVar3 = uRam02053294;
  if (param_1 == 0) {
    iVar6 = 1;
    uVar4 = *(uint *)(uRam02053294 & 0xfffffffc) >> (uRam02053294 & 3) * 8 |
            *(uint *)(uRam02053294 & 0xfffffffc) << (uRam02053294 & 3) * -8 + 0x20;
    *(byte *)(uVar4 + 0x89) = *(byte *)(uVar4 + 0x89) & 0xf0 | 1;
    uVar4 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
            *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
    *(byte *)(uVar4 + 0x89) = *(byte *)(uVar4 + 0x89) & 0xf | 0x10;
    do {
      iVar1 = iVar6 * 2;
      iVar6 = iVar6 + 1;
      *(undefined2 *)
       ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
        *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + iVar1 + 0x8c) = 0xffff;
    } while (iVar6 < 0xe);
    param_1 = 1;
  }
  else {
    uVar5 = *(uint *)(uRam02053294 & 0xfffffffc) >> (uRam02053294 & 3) * 8 |
            *(uint *)(uRam02053294 & 0xfffffffc) << (uRam02053294 & 3) * -8 + 0x20;
    bVar2 = *(byte *)(uVar5 + 0x89);
    if ((bVar2 & 0xf) < 7) {
      *(byte *)(uVar5 + 0x89) = bVar2 & 0xf0 | (bVar2 & 0xf) + 1 & 0xf;
    }
    else {
      param_1 = param_1 + 1 & 0xffff;
      *(byte *)(uVar5 + 0x89) = bVar2 & 0xf0 | 1;
      while ((1 << (param_1 - 1 & 0xff) & uVar4) == 0) {
        param_1 = param_1 + 1 & 0xffff;
        if (0xe < param_1) {
          uVar7 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                  *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
          uVar5 = ((uint)*(byte *)(uVar7 + 0x89) << 0x18) >> 0x1c;
          if (1 < uVar5) {
            *(undefined4 *)(uVar7 + 0x10) = 0;
            return;
          }
          *(byte *)(uVar7 + 0x89) = *(byte *)(uVar7 + 0x89) & 0xf | (byte)((uVar5 + 1 & 0xf) << 4);
          uVar5 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                  *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
          param_1 = 1;
          *(byte *)(uVar5 + 0x89) = *(byte *)(uVar5 + 0x89) & 0xf0 | 1;
        }
      }
    }
  }
  iVar6 = func_0214544c(uRam02053298,3,0x11,param_1);
  if (iVar6 == 2) {
    return;
  }
  func_020533a0();
  return;
}

