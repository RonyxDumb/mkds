/* Decompiled C draft; module arm9; ROM address 020be15c. No matching claim. */
#include "types.h"
#include "deps/020be15c_func_020be15c.h"

undefined4 func_020be15c(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 unaff_r4;
  int iVar5;
  
  iVar2 = func_020b1cf4();
  if (iVar2 == 0) {
    uVar3 = (*(uint *)(uRam020be2e0 & 0xfffffffc) >> (uRam020be2e0 & 3) * 8 |
            *(uint *)(uRam020be2e0 & 0xfffffffc) << (uRam020be2e0 & 3) * -8 + 0x20) + 8;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) == 2) &&
       (iVar2 = func_020a100c(param_1), iVar2 != 0)) {
      unaff_r4 = 0x24;
    }
    else {
      uVar3 = (*(uint *)(uRam020be2e0 & 0xfffffffc) >> (uRam020be2e0 & 3) * 8 |
              *(uint *)(uRam020be2e0 & 0xfffffffc) << (uRam020be2e0 & 3) * -8 + 0x20) + 8;
      uVar1 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) == 2) &&
         (iVar2 = func_020a1084(param_1), iVar2 != 0)) {
        unaff_r4 = 0xc9;
      }
      else {
        uVar3 = (*(uint *)(uRam020be2e0 & 0xfffffffc) >> (uRam020be2e0 & 3) * 8 |
                *(uint *)(uRam020be2e0 & 0xfffffffc) << (uRam020be2e0 & 3) * -8 + 0x20) + 8;
        uVar1 = uVar3 & 3;
        uVar3 = *(uint *)(uVar3 & 0xfffffffc);
        if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) == 2) ||
           (iVar2 = IsRacerFinishedRace(param_1), iVar2 == 0)) {
          uVar4 = *(uint *)(uRam020be2e4 & 0xfffffffc) >> (uRam020be2e4 & 3) * 8 |
                  *(uint *)(uRam020be2e4 & 0xfffffffc) << (uRam020be2e4 & 3) * -8 + 0x20;
          iVar2 = uVar4 + param_1 * 0xc;
          uVar3 = iVar2 + 0xfc;
          uVar1 = uVar3 & 3;
          uVar3 = *(uint *)(uVar3 & 0xfffffffc);
          uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
          if (uVar3 == 0) {
            uVar3 = uVar4 + param_1 * 4 + 0x40;
            uVar1 = uVar3 & 3;
            uVar3 = *(uint *)(uVar3 & 0xfffffffc);
            if ((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) == 0x13) {
              uVar3 = (*(uint *)(uRam020be2f0 & 0xfffffffc) >> (uRam020be2f0 & 3) * 8 |
                      *(uint *)(uRam020be2f0 & 0xfffffffc) << (uRam020be2f0 & 3) * -8 + 0x20) +
                      param_1 * 0x210;
              uVar1 = uVar3 & 3;
              uVar3 = *(uint *)(uVar3 & 0xfffffffc);
              if ((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) == 1) {
                unaff_r4 = 0x16;
              }
              else {
                unaff_r4 = 0xc9;
              }
            }
            else {
              unaff_r4 = func_020b8220(param_1);
            }
          }
          else {
            iVar5 = uVar3 - 1;
            if (iVar5 - iRam020be2ec *
                        ((int)((longlong)iRam020be2e8 * (longlong)iVar5 >> 0x21) - (iVar5 >> 0x1f))
                < 6) {
              unaff_r4 = 0xc9;
            }
            else {
              uVar3 = uVar4 + 0x100 + param_1 * 0xc;
              uVar1 = uVar3 & 3;
              uVar3 = *(uint *)(uVar3 & 0xfffffffc);
              if ((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) == 5) {
                uVar3 = iVar2 + 0x104;
                uVar1 = uVar3 & 3;
                uVar3 = *(uint *)(uVar3 & 0xfffffffc);
                uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
                if (uVar3 == 1) {
                  unaff_r4 = 0x11;
                }
                else if (uVar3 == 2) {
                  unaff_r4 = 0x12;
                }
                else if (uVar3 == 3) {
                  unaff_r4 = 0x13;
                }
              }
              else {
                unaff_r4 = func_020b8220(param_1);
              }
            }
          }
        }
        else {
          unaff_r4 = 0x24;
        }
      }
    }
  }
  else {
    unaff_r4 = 0x25;
  }
  return unaff_r4;
}

