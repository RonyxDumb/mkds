/* Decompiled C draft; module arm9; ROM address 0210a880. No matching claim. */
#include "types.h"
#include "deps/0210a880_func_0210a880.h"

void func_0210a880(int param_1,int param_2,int param_3)

{
  undefined1 uVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  
  uVar6 = param_1 + 0x48cU & 3;
  uVar5 = *(uint *)(param_1 + 0x48cU & 0xfffffffc);
  uVar1 = *(undefined1 *)(param_2 + 0x1a);
  iVar3 = (*(code *)(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20))(param_1 + iRam0210a9f0);
  if (*(char *)(param_2 + 0x18) == '\x02') {
    uVar6 = param_1 + 0x500U & 3;
    uVar5 = *(uint *)(param_1 + 0x500U & 0xfffffffc);
    uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    iVar4 = 0;
    if (uRam0210a9f8 < uVar6) {
      iVar4 = (int)(short)((ushort)(*(uint *)(uRam0210a9fc & 0xfffffffc) >> (uRam0210a9fc & 3) * 8)
                          | (ushort)(*(uint *)(uRam0210a9fc & 0xfffffffc) <<
                                    (uRam0210a9fc & 3) * -8 + 0x20));
    }
    else if ((uRam0210aa00 < uVar6) && (uVar6 <= uRam0210a9f8)) {
      iVar4 = (int)(short)((ushort)(*(uint *)(uRam0210a9fc & 0xfffffffc) >> (uRam0210a9fc & 3) * 8)
                          | (ushort)(*(uint *)(uRam0210a9fc & 0xfffffffc) <<
                                    (uRam0210a9fc & 3) * -8 + 0x20));
    }
  }
  else {
    uVar6 = param_1 + 0x500U & 3;
    uVar5 = *(uint *)(param_1 + 0x500U & 0xfffffffc);
    uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    iVar4 = 0;
    bVar7 = (uint)*(ushort *)(param_1 + 0x74) ==
            (int)*(char *)((*(uint *)(uRam0210a9f4 & 0xfffffffc) >> (uRam0210a9f4 & 3) * 8 |
                           *(uint *)(uRam0210a9f4 & 0xfffffffc) << (uRam0210a9f4 & 3) * -8 + 0x20) +
                          0x62);
    if (uRam0210a9f8 < uVar6) {
      iVar4 = 900;
      if (bVar7) {
        iVar4 = (int)(((*(uint *)(uRam0210a9fc & 0xfffffffc) >> (uRam0210a9fc & 3) * 8 |
                       *(uint *)(uRam0210a9fc & 0xfffffffc) << (uRam0210a9fc & 3) * -8 + 0x20) + 900
                      ) * 0x10000) >> 0x10;
      }
    }
    else if ((uRam0210aa00 < uVar6) && (uVar6 <= uRam0210a9f8)) {
      lVar2 = (longlong)
              (int)(*(uint *)(uRam0210aa04 & 0xfffffffc) >> (uRam0210aa04 & 3) * 8 |
                   *(uint *)(uRam0210aa04 & 0xfffffffc) << (uRam0210aa04 & 3) * -8 + 0x20) *
              (longlong)(int)((uVar6 + iRam0210aa08) * 0x1000) + 0x800;
      uVar5 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000;
      uVar6 = uVar5;
      if (bVar7) {
        uVar6 = uRam0210a9fc;
      }
      iVar4 = (int)(uVar5 << 4) >> 0x10;
      if (bVar7) {
        iVar4 = (iVar4 + ((int)(*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
                               *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) >> 1)) *
                0x10000 >> 0x10;
      }
    }
  }
  func_02105b28(param_2,uVar1);
  func_02105b0c(param_2,(int)*(short *)(param_2 + 0x14) + ((param_3 + iVar3) - iVar4));
  return;
}

