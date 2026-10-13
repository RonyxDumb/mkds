/* Decompiled C draft; module arm9; ROM address 0210a77c. No matching claim. */
#include "types.h"
#include "deps/0210a77c_func_0210a77c.h"

void func_0210a77c(int param_1,int param_2)

{
  uint uVar1;
  undefined1 uVar2;
  longlong lVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  uVar1 = param_1 + 0x44U & 3;
  uVar7 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  if (uVar7 >> uVar1 * 8 == 0 && uVar7 << uVar1 * -8 + 0x20 == 0) {
    iVar5 = param_1 + 0x16c;
  }
  else {
    iVar5 = param_1 + 600;
  }
  uVar1 = iVar5 + 8U & 3;
  uVar7 = *(uint *)(iVar5 + 8U & 0xfffffffc);
  uVar6 = uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0x54U & 3;
  uVar7 = *(uint *)(param_1 + 0x54U & 0xfffffffc);
  uVar2 = *(undefined1 *)(param_2 + 0x1a);
  iVar5 = func_020d3d48(uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20);
  if (iVar5 < 0) {
    uVar1 = -iVar5;
    iVar4 = 0;
    if (uVar1 < uRam0210a868 || -uRam0210a868 == iVar5) {
      if ((uRam0210a874 <= uVar1 && -uRam0210a874 != iVar5) &&
         (uVar1 < uRam0210a868 || -uRam0210a868 == iVar5)) {
        lVar3 = (longlong)
                (int)(*(uint *)(uRam0210a878 & 0xfffffffc) >> (uRam0210a878 & 3) * 8 |
                     *(uint *)(uRam0210a878 & 0xfffffffc) << (uRam0210a878 & 3) * -8 + 0x20) *
                (longlong)(int)((uVar1 + iRam0210a87c) * 0x1000) + 0x800;
        iVar4 = (((int)(((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000) << 4) >>
                 0x10) + ((int)(*(uint *)(uRam0210a86c & 0xfffffffc) >> (uRam0210a86c & 3) * 8 |
                               *(uint *)(uRam0210a86c & 0xfffffffc) <<
                               (uRam0210a86c & 3) * -8 + 0x20) >> 1)) * 0x10000 >> 0x10;
      }
    }
    else {
      iVar4 = (int)((iRam0210a870 +
                    (*(uint *)(uRam0210a86c & 0xfffffffc) >> (uRam0210a86c & 3) * 8 |
                    *(uint *)(uRam0210a86c & 0xfffffffc) << (uRam0210a86c & 3) * -8 + 0x20)) *
                   0x10000) >> 0x10;
    }
    uVar6 = uVar6 - iVar4;
  }
  func_02105b28(param_2,uVar2);
  func_02105b0c(param_2,(int)*(short *)(param_2 + 0x14) + uVar6);
  return;
}

