/* Decompiled C draft; module arm9; ROM address 02110754. No matching claim. */
#include "types.h"
#include "deps/02110754_func_02110754.h"

void func_02110754(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  
  iVar1 = iRam0211082c;
  uVar5 = iRam0211082c + 0x78U & 3;
  uVar2 = *(uint *)(iRam0211082c + 0x78U & 0xfffffffc);
  if (uVar2 >> uVar5 * 8 == 0 && uVar2 << uVar5 * -8 + 0x20 == 0) {
    uVar5 = iRam0211082c + 0x74U & 3;
    uVar2 = *(uint *)(iRam0211082c + 0x74U & 0xfffffffc);
    uVar3 = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20;
    uVar5 = iRam0211082c + uVar3 * 4;
    uVar2 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar5 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
    if (uVar5 != 0xd) {
      uVar2 = iRam0211082c + uVar3 * 4 + 0x38;
      uVar3 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      uVar2 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      uVar4 = 3;
      if (uVar5 == 0xc) {
        if (uVar2 == 0) {
          uVar5 = 0x47;
        }
        else {
          uVar5 = 0x48;
        }
        uVar4 = 0;
      }
      else {
        uVar5 = uVar2 + uVar5 * 2 & 0xffff;
      }
      NNSi_MaybeSndPlayerStartSeq(uRam02110830,uVar4,uVar5);
      if (*(uint *)(uRam02110830 & 0xfffffffc) >> (uRam02110830 & 3) * 8 != 0 ||
          *(uint *)(uRam02110830 & 0xfffffffc) << (uRam02110830 & 3) * -8 + 0x20 != 0) {
        func_02105b28(uRam02110830,0x3c);
      }
      uVar5 = iVar1 + 0x74U & 3;
      uVar2 = *(uint *)(iVar1 + 0x74U & 0xfffffffc);
      *(undefined4 *)(iRam0211082c + (uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) * 4) = 0xd;
      uVar5 = iVar1 + 0x74U & 3;
      uVar2 = *(uint *)(iVar1 + 0x74U & 0xfffffffc);
      *(undefined4 *)(iRam02110834 + (uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) * 4) = 2;
      *(undefined4 *)(iVar1 + 0x78) = 0x19;
      uVar5 = iVar1 + 0x74U & 3;
      uVar2 = *(uint *)(iVar1 + 0x74U & 0xfffffffc);
      *(uint *)(iVar1 + 0x74) = (uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) + 1;
      uVar5 = iVar1 + 0x74U & 3;
      uVar2 = *(uint *)(iVar1 + 0x74U & 0xfffffffc);
      uVar5 = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20;
      if (uVar5 == 0xe) {
        uVar5 = 0;
      }
      *(uint *)(iVar1 + 0x74) = uVar5;
    }
  }
  uVar5 = iVar1 + 0x78U & 3;
  uVar2 = *(uint *)(iVar1 + 0x78U & 0xfffffffc);
  uVar5 = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20;
  if (0 < (int)uVar5) {
    *(uint *)(iVar1 + 0x78) = uVar5 - 1;
  }
  return;
}

