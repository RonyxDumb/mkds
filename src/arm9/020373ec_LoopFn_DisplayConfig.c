/* Decompiled C draft; module arm9; ROM address 020373ec. No matching claim. */
#include "types.h"
#include "deps/020373ec_LoopFn_DisplayConfig.h"

void LoopFn_DisplayConfig(void)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  code *pcVar7;
  uint uVar8;
  uint uVar9;
  undefined8 uVar10;
  
  uVar10 = Os_GetTick();
  iVar6 = (int)((ulonglong)uVar10 >> 0x20);
  uVar3 = (uint)uVar10;
  pcVar7 = (code *)(*(uint *)(uRam0203748c & 0xfffffffc) >> (uRam0203748c & 3) * 8 |
                   *(uint *)(uRam0203748c & 0xfffffffc) << (uRam0203748c & 3) * -8 + 0x20);
  if (pcVar7 != (code *)0x0) {
    (*pcVar7)(3);
  }
  uVar8 = *(uint *)(uRam02037490 & 0xfffffffc) >> (uRam02037490 & 3) * 8 |
          *(uint *)(uRam02037490 & 0xfffffffc) << (uRam02037490 & 3) * -8 + 0x20;
  uVar1 = uVar8 + 0xc4 & 3;
  uVar4 = *(uint *)(uVar8 + 0xc4 & 0xfffffffc);
  uVar4 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  uVar1 = uVar8 + 200 & 3;
  uVar9 = *(uint *)(uVar8 + 200 & 0xfffffffc);
  lVar2 = (ulonglong)(uVar3 - uVar4) * 64000;
  uVar5 = _ll_udiv((int)lVar2,
                   (iVar6 - ((uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20) +
                            (uint)(uVar3 < uVar4))) * 64000 + (int)((ulonglong)lVar2 >> 0x20),
                   uRam02037494);
  uVar4 = uRam02037490;
  *(undefined4 *)(uVar8 + 0xd0) = uVar5;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar8 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  uVar1 = uVar8 + 0xbc & 3;
  uVar4 = *(uint *)(uVar8 + 0xbc & 0xfffffffc);
  uVar4 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  lVar2 = (ulonglong)(uVar3 - uVar4) * 64000;
  uVar1 = uVar8 + 0xc0 & 3;
  uVar9 = *(uint *)(uVar8 + 0xc0 & 0xfffffffc);
  uVar5 = _ll_udiv((int)lVar2,
                   (iVar6 - ((uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20) +
                            (uint)(uVar3 < uVar4))) * 64000 + (int)((ulonglong)lVar2 >> 0x20),
                   uRam02037494);
  *(undefined4 *)(uVar8 + 0xd4) = uVar5;
  return;
}

