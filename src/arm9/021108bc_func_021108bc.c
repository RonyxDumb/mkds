/* Decompiled C draft; module arm9; ROM address 021108bc. No matching claim. */
#include "types.h"
#include "deps/021108bc_func_021108bc.h"

void func_021108bc(int param_1)

{
  uint *puVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int unaff_r6;
  
  puVar1 = puRam02110a50;
  uVar3 = uRam02110a48;
  if (2 < param_1) {
    if (param_1 < 6) {
      uVar3 = 0x1f8;
    }
    else {
      uVar3 = 0xffffffff;
    }
  }
  uVar5 = (*(uint *)((uint)puRam02110a50 & 0xfffffffc) >> ((uint)puRam02110a50 & 3) * 8 |
          *(uint *)((uint)puRam02110a50 & 0xfffffffc) << ((uint)puRam02110a50 & 3) * -8 + 0x20) + 1;
  *pbRam02110a4c = *pbRam02110a4c + 1;
  *puVar1 = uVar5;
  if (uVar3 != 0xffffffff) {
    if (1 < uVar5) {
      if ((*pbRam02110a54 & 1) == 0) {
        uVar2 = 3;
      }
      else {
        uVar2 = 2;
      }
      uVar5 = func_02108e6c(uVar2);
      if (0x13 < (*(uint *)((uint)puRam02110a50 & 0xfffffffc) >> ((uint)puRam02110a50 & 3) * 8 |
                 *(uint *)((uint)puRam02110a50 & 0xfffffffc) <<
                 ((uint)puRam02110a50 & 3) * -8 + 0x20)) {
        *pbRam02110a4c = 0;
      }
      if (*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 != 0 ||
          *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20 != 0) {
        func_0212c6f0(uVar5,0);
      }
      NNSi_MaybeSndPlayerStartSeq(uVar5,0,uVar3 & 0xffff);
      *pbRam02110a54 = *pbRam02110a54 + 1;
      if (uVar5 != 0) {
        uVar4 = (uint)*pbRam02110a4c;
        uVar3 = iRam02110a5c *
                (int)((ulonglong)((longlong)iRam02110a58 * (longlong)(int)uVar4) >> 0x20);
        iVar6 = uVar4 - uVar3;
        if (uVar4 == uVar3) {
          unaff_r6 = 0;
        }
        else if (iVar6 == 1) {
          if (param_1 < 3) {
            unaff_r6 = 0x40;
          }
          else {
            unaff_r6 = -0x40;
          }
        }
        else if (iVar6 == 2) {
          if (param_1 < 3) {
            unaff_r6 = 0x80;
          }
          else {
            unaff_r6 = -0x80;
          }
        }
        if ((param_1 == 1) || (param_1 == 4)) {
          unaff_r6 = unaff_r6 + -0x100;
        }
        else if ((param_1 == 2) || (param_1 == 5)) {
          unaff_r6 = unaff_r6 + -0x200;
        }
        func_02105b0c(uVar5,unaff_r6);
      }
      *puRam02110a50 = 0;
      return;
    }
    return;
  }
  return;
}

