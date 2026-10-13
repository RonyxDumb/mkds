/* Decompiled C draft; module arm9; ROM address 02110cc8. No matching claim. */
#include "types.h"
#include "deps/02110cc8_MaybePlayCrowdAmbientNoise.h"

void MaybePlayCrowdAmbientNoise(void)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar2 = (*(uint *)(uRam02110e24 & 0xfffffffc) >> (uRam02110e24 & 3) * 8 |
          *(uint *)(uRam02110e24 & 0xfffffffc) << (uRam02110e24 & 3) * -8 + 0x20) + 0xc;
  uVar3 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if ((uVar2 != 2) && (uVar2 != 0)) {
    return;
  }
  uVar2 = iRam02110e28 + 4U & 3;
  uVar3 = *(uint *)(iRam02110e28 + 4U & 0xfffffffc);
  if ((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) != 2) {
    return;
  }
  func_02106c64();
  iVar4 = func_02110e58();
  uVar2 = iRam02110e2c + 8U & 3;
  uVar3 = *(uint *)(iRam02110e2c + 8U & 0xfffffffc);
  uVar2 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  uVar3 = 0xff;
  if (iVar4 == 0) {
    uVar3 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
            *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
  }
  else if (iVar4 == 1) {
    uVar3 = uVar2 + 4 & 3;
    uVar2 = *(uint *)(uVar2 + 4 & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  }
  else if (iVar4 == 2) {
    uVar3 = uVar2 + 8 & 3;
    uVar2 = *(uint *)(uVar2 + 8 & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  }
  func_0210d614(uRam02110e30,uVar3,0);
  puVar1 = puRam02110e38;
  uVar3 = *(uint *)(uRam02110e24 & 0xfffffffc) >> (uRam02110e24 & 3) * 8 |
          *(uint *)(uRam02110e24 & 0xfffffffc) << (uRam02110e24 & 3) * -8 + 0x20;
  *puRam02110e34 = 1;
  *puVar1 = 1;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar2 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  if (uVar2 == 0x14) {
    uVar3 = uRam02110e44;
    if ((iVar4 != 0) && (iVar4 != 1)) {
      uVar3 = uRam02110e48;
    }
  }
  else if (uVar2 == 0x19) {
    uVar3 = uRam02110e4c;
    if ((iVar4 != 0) && (iVar4 != 1)) {
      uVar3 = uRam02110e50;
    }
  }
  else {
    uVar3 = 0xffffffff;
    if (((uVar2 == 0x22) && (uVar3 = uRam02110e3c, iVar4 != 0)) && (iVar4 != 1)) {
      uVar3 = uRam02110e40;
    }
  }
  if (0x7fffffff < uVar3) {
    return;
  }
  func_02108e38();
  NNSi_MaybeSndPlayerStartSeq(uRam02110e54,0,uVar3 & 0xffff);
  return;
}

