/* Decompiled C draft; module arm9; ROM address 02109468. No matching claim. */
#include "types.h"
#include "deps/02109468_func_02109468.h"

void func_02109468(void)

{
  longlong lVar1;
  bool bVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int local_238;
  int iStack_234;
  int iStack_230;
  uint local_228;
  int local_224;
  int iStack_220;
  int iStack_21c;
  uint local_214;
  int local_210;
  int iStack_20c;
  int iStack_208;
  uint local_200;
  int local_1fc;
  int iStack_1f8;
  int iStack_1f4;
  uint local_1ec;
  int local_1e8;
  int iStack_1e4;
  int iStack_1e0;
  uint local_1d8;
  
  iVar5 = GetCurrentSceneId();
  piVar3 = piRam0210a484;
  if ((iVar5 == 2) &&
     (uVar6 = (*(uint *)(uRam0210a474 & 0xfffffffc) >> (uRam0210a474 & 3) * 8 |
              *(uint *)(uRam0210a474 & 0xfffffffc) << (uRam0210a474 & 3) * -8 + 0x20) + 0xc,
     uVar7 = uVar6 & 3, uVar6 = *(uint *)(uVar6 & 0xfffffffc),
     (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) == 2)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  local_238 = *piRam0210a478;
  iStack_234 = piRam0210a478[1];
  iStack_230 = piRam0210a478[2];
  iVar5 = piRam0210a478[3];
  uVar6 = (uint)(piRam0210a478 + 4) & 3;
  uVar7 = *(uint *)((uint)(piRam0210a478 + 4) & 0xfffffffc);
  local_228 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
  if (bVar2) {
    local_238 = iRam0210a47c;
    iStack_234 = iRam0210a480;
    iStack_230 = 0x2f;
    local_228 = 0x5f;
  }
  piRam0210a484[4] = local_228;
  *piVar3 = local_238;
  piVar3[1] = iStack_234;
  piVar3[2] = iStack_230;
  piVar3[3] = iVar5;
  iVar5 = FX_Div((iStack_230 - local_228) * 0x1000,(iStack_234 - iVar5) * 0x1000);
  piRam0210a484[5] = iVar5;
  iVar5 = FX_Div(iStack_230 << 0xc,(iStack_234 - local_238) * 0x1000);
  piVar3 = piRam0210a484;
  piRam0210a484[6] = iVar5;
  uVar6 = (uint)(piVar3 + 3) & 3;
  uVar7 = *(uint *)((uint)(piVar3 + 3) & 0xfffffffc);
  iVar5 = FX_Div(uRam0210a488,(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) * 0x1000 + 0x36000);
  piVar3 = piRam0210a484;
  piRam0210a484[7] = iVar5;
  piVar4 = piRam0210a490;
  lVar1 = (ulonglong)uRam0210a48c * (ulonglong)(uint)(local_238 * 0x1000);
  uVar6 = (uint)lVar1;
  iVar5 = (int)(uVar6 + 0x800 >> 0xc |
               ((local_238 * 0x1000 >> 0x1f) * uRam0210a48c + (int)((ulonglong)lVar1 >> 0x20) +
               (uint)(0xfffff7ff < uVar6)) * 0x100000) >> 0xc;
  piVar3[8] = iVar5 * iVar5;
  piVar3 = piRam0210a494;
  local_224 = *piVar4;
  iStack_220 = piVar4[1];
  iStack_21c = piVar4[2];
  iVar5 = piVar4[3];
  uVar6 = (uint)(piVar4 + 4) & 3;
  uVar7 = *(uint *)((uint)(piVar4 + 4) & 0xfffffffc);
  local_214 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
  if (bVar2) {
    local_224 = iRam0210a47c;
    iStack_220 = iRam0210a480;
    iStack_21c = 0x2f;
    local_214 = 0x5f;
  }
  piRam0210a494[4] = local_214;
  *piVar3 = local_224;
  piVar3[1] = iStack_220;
  piVar3[2] = iStack_21c;
  piVar3[3] = iVar5;
  iVar5 = FX_Div((iStack_21c - local_214) * 0x1000,(iStack_220 - iVar5) * 0x1000);
  piRam0210a494[5] = iVar5;
  iVar5 = FX_Div(iStack_21c << 0xc,(iStack_220 - local_224) * 0x1000);
  piVar3 = piRam0210a494;
  piRam0210a494[6] = iVar5;
  uVar6 = (uint)(piVar3 + 3) & 3;
  uVar7 = *(uint *)((uint)(piVar3 + 3) & 0xfffffffc);
  iVar5 = FX_Div(uRam0210a488,(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) * 0x1000 + 0x36000);
  piVar3 = piRam0210a494;
  piRam0210a494[7] = iVar5;
  piVar4 = piRam0210a498;
  lVar1 = (ulonglong)uRam0210a48c * (ulonglong)(uint)(local_224 * 0x1000);
  uVar6 = (uint)lVar1;
  iVar5 = (int)(uVar6 + 0x800 >> 0xc |
               ((local_224 * 0x1000 >> 0x1f) * uRam0210a48c + (int)((ulonglong)lVar1 >> 0x20) +
               (uint)(0xfffff7ff < uVar6)) * 0x100000) >> 0xc;
  piVar3[8] = iVar5 * iVar5;
  piVar3 = piRam0210a484;
  local_210 = *piVar4;
  iStack_20c = piVar4[1];
  iStack_208 = piVar4[2];
  iVar5 = piVar4[3];
  uVar6 = (uint)(piVar4 + 4) & 3;
  uVar7 = *(uint *)((uint)(piVar4 + 4) & 0xfffffffc);
  local_200 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
  if (bVar2) {
    local_210 = iRam0210a49c;
    iStack_20c = iRam0210a4a0;
    iStack_208 = 0x2f;
    local_200 = 0x5f;
  }
  piRam0210a484[0xd] = local_200;
  piVar3[9] = local_210;
  piVar3[10] = iStack_20c;
  piVar3[0xb] = iStack_208;
  piVar3[0xc] = iVar5;
  iVar5 = FX_Div((iStack_208 - local_200) * 0x1000,(iStack_20c - iVar5) * 0x1000);
  piRam0210a484[0xe] = iVar5;
  iVar5 = FX_Div(iStack_208 << 0xc,(iStack_20c - local_210) * 0x1000);
  piVar3 = piRam0210a484;
  piRam0210a484[0xf] = iVar5;
  uVar6 = (uint)(piVar3 + 0xc) & 3;
  uVar7 = *(uint *)((uint)(piVar3 + 0xc) & 0xfffffffc);
  iVar5 = FX_Div(uRam0210a488,(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) * 0x1000 + 0x36000);
  piVar3 = piRam0210a484;
  piRam0210a484[0x10] = iVar5;
  piVar4 = piRam0210a4a4;
  lVar1 = (ulonglong)uRam0210a48c * (ulonglong)(uint)(local_210 * 0x1000);
  uVar6 = (uint)lVar1;
  iVar5 = (int)(uVar6 + 0x800 >> 0xc |
               ((local_210 * 0x1000 >> 0x1f) * uRam0210a48c + (int)((ulonglong)lVar1 >> 0x20) +
               (uint)(0xfffff7ff < uVar6)) * 0x100000) >> 0xc;
  piVar3[0x11] = iVar5 * iVar5;
  piVar3 = piRam0210a484;
  local_1fc = *piVar4;
  iStack_1f8 = piVar4[1];
  iStack_1f4 = piVar4[2];
  iVar5 = piVar4[3];
  uVar6 = (uint)(piVar4 + 4) & 3;
  uVar7 = *(uint *)((uint)(piVar4 + 4) & 0xfffffffc);
  local_1ec = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
  if (bVar2) {
    local_1fc = iRam0210a47c;
    iStack_1f8 = iRam0210a480;
    iStack_1f4 = 0x2f;
    local_1ec = 0x5f;
  }
  piRam0210a484[0x16] = local_1ec;
  piVar3[0x12] = local_1fc;
  piVar3[0x13] = iStack_1f8;
  piVar3[0x14] = iStack_1f4;
  piVar3[0x15] = iVar5;
  iVar5 = FX_Div((iStack_1f4 - local_1ec) * 0x1000,(iStack_1f8 - iVar5) * 0x1000);
  piRam0210a484[0x17] = iVar5;
  iVar5 = FX_Div(iStack_1f4 << 0xc,(iStack_1f8 - local_1fc) * 0x1000);
  piVar3 = piRam0210a484;
  piRam0210a484[0x18] = iVar5;
  uVar6 = (uint)(piVar3 + 0x15) & 3;
  uVar7 = *(uint *)((uint)(piVar3 + 0x15) & 0xfffffffc);
  iVar5 = FX_Div(uRam0210a488,(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) * 0x1000 + 0x36000);
  piVar3 = piRam0210a484;
  piRam0210a484[0x19] = iVar5;
  piVar4 = piRam0210a4a8;
  lVar1 = (ulonglong)uRam0210a48c * (ulonglong)(uint)(local_1fc * 0x1000);
  uVar6 = (uint)lVar1;
  iVar5 = (int)(uVar6 + 0x800 >> 0xc |
               ((local_1fc * 0x1000 >> 0x1f) * uRam0210a48c + (int)((ulonglong)lVar1 >> 0x20) +
               (uint)(0xfffff7ff < uVar6)) * 0x100000) >> 0xc;
  piVar3[0x1a] = iVar5 * iVar5;
  piVar3 = piRam0210a484;
  local_1e8 = *piVar4;
  iStack_1e4 = piVar4[1];
  iStack_1e0 = piVar4[2];
  iVar5 = piVar4[3];
  uVar6 = (uint)(piVar4 + 4) & 3;
  uVar7 = *(uint *)((uint)(piVar4 + 4) & 0xfffffffc);
  local_1d8 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
  if (bVar2) {
    local_1e8 = iRam0210a47c;
    iStack_1e4 = iRam0210a480;
    iStack_1e0 = 0x2f;
    local_1d8 = 0x5f;
  }
  piRam0210a484[0x1f] = local_1d8;
  piVar3[0x1b] = local_1e8;
  piVar3[0x1c] = iStack_1e4;
  piVar3[0x1d] = iStack_1e0;
  piVar3[0x1e] = iVar5;
  iVar5 = FX_Div((iStack_1e0 - local_1d8) * 0x1000,(iStack_1e4 - iVar5) * 0x1000);
  piRam0210a484[0x20] = iVar5;
  iVar5 = FX_Div(iStack_1e0 << 0xc,(iStack_1e4 - local_1e8) * 0x1000);
  piVar3 = piRam0210a484;
  piRam0210a484[0x21] = iVar5;
  uVar6 = (uint)(piVar3 + 0x1e) & 3;
  uVar7 = *(uint *)((uint)(piVar3 + 0x1e) & 0xfffffffc);
  iVar5 = FX_Div(uRam0210a488,(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) * 0x1000 + 0x36000);
  piVar3 = piRam0210a484;
  piRam0210a484[0x22] = iVar5;
  piVar4 = piRam0210a4ac;
  lVar1 = (ulonglong)uRam0210a48c * (ulonglong)(uint)(local_1e8 * 0x1000);
  uVar6 = (uint)lVar1;
  iVar5 = (int)(uVar6 + 0x800 >> 0xc |
               ((local_1e8 * 0x1000 >> 0x1f) * uRam0210a48c + (int)((ulonglong)lVar1 >> 0x20) +
               (uint)(0xfffff7ff < uVar6)) * 0x100000) >> 0xc;
  piVar3[0x23] = iVar5 * iVar5;
  iVar5 = *piVar4;
  iVar8 = piVar4[1];
  iVar9 = piVar4[2];
  iVar10 = piVar4[3];
  uVar6 = (uint)(piVar4 + 4) & 3;
  uVar7 = *(uint *)((uint)(piVar4 + 4) & 0xfffffffc);
  uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
  piVar3[0x24] = iVar5;
  piVar3[0x28] = uVar6;
  piVar3[0x27] = iVar10;
  piVar3[0x25] = iVar8;
  piVar3[0x26] = iVar9;
  iVar10 = FX_Div((iVar9 - uVar6) * 0x1000,(iVar8 - iVar10) * 0x1000);
  piVar3[0x29] = iVar10;
  iVar10 = FX_Div(iVar9 << 0xc,(iVar8 - iVar5) * 0x1000);
  piVar3[0x2a] = iVar10;
  uVar6 = (uint)(piVar3 + 0x27) & 3;
  uVar7 = *(uint *)((uint)(piVar3 + 0x27) & 0xfffffffc);
  iVar10 = FX_Div(uRam0210a488,(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) * 0x1000 + 0x36000)
  ;
  piVar3[0x2b] = iVar10;
  piVar4 = piRam0210a4b0;
  lVar1 = (ulonglong)uRam0210a48c * (ulonglong)(uint)(iVar5 * 0x1000);
  uVar6 = (uint)lVar1;
  iVar5 = (int)(uVar6 + 0x800 >> 0xc |
               ((iVar5 * 0x1000 >> 0x1f) * uRam0210a48c + (int)((ulonglong)lVar1 >> 0x20) +
               (uint)(0xfffff7ff < uVar6)) * 0x100000) >> 0xc;
  piVar3[0x2c] = iVar5 * iVar5;
  iVar5 = *piVar4;
  iVar8 = piVar4[1];
  iVar9 = piVar4[2];
  iVar10 = piVar4[3];
  uVar6 = (uint)(piVar4 + 4) & 3;
  uVar7 = *(uint *)((uint)(piVar4 + 4) & 0xfffffffc);
  uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
  piVar3[0x2d] = iVar5;
  piVar3[0x31] = uVar6;
  piVar3[0x30] = iVar10;
  piVar3[0x2e] = iVar8;
  piVar3[0x2f] = iVar9;
  iVar10 = FX_Div((iVar9 - uVar6) * 0x1000,(iVar8 - iVar10) * 0x1000);
  piVar3[0x32] = iVar10;
  iVar10 = FX_Div(iVar9 << 0xc,(iVar8 - iVar5) * 0x1000);
  piVar3[0x33] = iVar10;
  uVar6 = (uint)(piVar3 + 0x30) & 3;
  uVar7 = *(uint *)((uint)(piVar3 + 0x30) & 0xfffffffc);
  iVar10 = FX_Div(uRam0210a488,(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) * 0x1000 + 0x36000)
  ;
  piVar3[0x34] = iVar10;
  piVar4 = piRam0210a4b4;
  lVar1 = (ulonglong)uRam0210a48c * (ulonglong)(uint)(iVar5 * 0x1000);
  uVar6 = (uint)lVar1;
  iVar5 = (int)(uVar6 + 0x800 >> 0xc |
               ((iVar5 * 0x1000 >> 0x1f) * uRam0210a48c + (int)((ulonglong)lVar1 >> 0x20) +
               (uint)(0xfffff7ff < uVar6)) * 0x100000) >> 0xc;
  piVar3[0x35] = iVar5 * iVar5;
  iVar5 = *piVar4;
  iVar8 = piVar4[1];
  iVar9 = piVar4[2];
  iVar10 = piVar4[3];
  uVar6 = (uint)(piVar4 + 4) & 3;
  uVar7 = *(uint *)((uint)(piVar4 + 4) & 0xfffffffc);
  uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
  piVar3[0x36] = iVar5;
  piVar3[0x3a] = uVar6;
  piVar3[0x39] = iVar10;
  piVar3[0x37] = iVar8;
  piVar3[0x38] = iVar9;
  iVar10 = FX_Div((iVar9 - uVar6) * 0x1000,(iVar8 - iVar10) * 0x1000);
  piVar3[0x3b] = iVar10;
  iVar10 = FX_Div(iVar9 << 0xc,(iVar8 - iVar5) * 0x1000);
  piVar3[0x3c] = iVar10;
  uVar6 = (uint)(piVar3 + 0x39) & 3;
  uVar7 = *(uint *)((uint)(piVar3 + 0x39) & 0xfffffffc);
  iVar10 = FX_Div(uRam0210a488,(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) * 0x1000 + 0x36000)
  ;
  piVar3[0x3d] = iVar10;
  piVar4 = piRam0210a4b8;
  lVar1 = (ulonglong)uRam0210a48c * (ulonglong)(uint)(iVar5 * 0x1000);
  uVar6 = (uint)lVar1;
  iVar5 = (int)(uVar6 + 0x800 >> 0xc |
               ((iVar5 * 0x1000 >> 0x1f) * uRam0210a48c + (int)((ulonglong)lVar1 >> 0x20) +
               (uint)(0xfffff7ff < uVar6)) * 0x100000) >> 0xc;
  piVar3[0x3e] = iVar5 * iVar5;
  iVar5 = *piVar4;
  iVar8 = piVar4[1];
  iVar9 = piVar4[2];
  iVar10 = piVar4[3];
  uVar6 = (uint)(piVar4 + 4) & 3;
  uVar7 = *(uint *)((uint)(piVar4 + 4) & 0xfffffffc);
  uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
  piVar3[0x3f] = iVar5;
  piVar3[0x43] = uVar6;
  piVar3[0x42] = iVar10;
  piVar3[0x40] = iVar8;
  piVar3[0x41] = iVar9;
  iVar10 = FX_Div((iVar9 - uVar6) * 0x1000,(iVar8 - iVar10) * 0x1000);
  piVar3[0x44] = iVar10;
  iVar10 = FX_Div(iVar9 << 0xc,(iVar8 - iVar5) * 0x1000);
  piVar3[0x45] = iVar10;
  uVar6 = (uint)(piVar3 + 0x42) & 3;
  uVar7 = *(uint *)((uint)(piVar3 + 0x42) & 0xfffffffc);
  iVar10 = FX_Div(uRam0210a488,(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) * 0x1000 + 0x36000)
  ;
  piVar3[0x46] = iVar10;
  piVar4 = piRam0210a4bc;
  lVar1 = (ulonglong)uRam0210a48c * (ulonglong)(uint)(iVar5 * 0x1000);
  uVar6 = (uint)lVar1;
  iVar5 = (int)(uVar6 + 0x800 >> 0xc |
               ((iVar5 * 0x1000 >> 0x1f) * uRam0210a48c + (int)((ulonglong)lVar1 >> 0x20) +
               (uint)(0xfffff7ff < uVar6)) * 0x100000) >> 0xc;
  piVar3[0x47] = iVar5 * iVar5;
  iVar5 = *piVar4;
  iVar8 = piVar4[1];
  iVar9 = piVar4[2];
  iVar10 = piVar4[3];
  uVar6 = (uint)(piVar4 + 4) & 3;
  uVar7 = *(uint *)((uint)(piVar4 + 4) & 0xfffffffc);
  uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
  piVar3[0x48] = iVar5;
  piVar3[0x4c] = uVar6;
  piVar3[0x4b] = iVar10;
  piVar3[0x49] = iVar8;
  piVar3[0x4a] = iVar9;
  iVar10 = FX_Div((iVar9 - uVar6) * 0x1000,(iVar8 - iVar10) * 0x1000);
  piVar3[0x4d] = iVar10;
  iVar10 = FX_Div(iVar9 << 0xc,(iVar8 - iVar5) * 0x1000);
  piVar3[0x4e] = iVar10;
  uVar6 = (uint)(piVar3 + 0x4b) & 3;
  uVar7 = *(uint *)((uint)(piVar3 + 0x4b) & 0xfffffffc);
  iVar10 = FX_Div(uRam0210a488,(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) * 0x1000 + 0x36000)
  ;
  piVar3[0x4f] = iVar10;
  piVar4 = piRam0210a4c0;
  lVar1 = (ulonglong)uRam0210a48c * (ulonglong)(uint)(iVar5 * 0x1000);
  uVar6 = (uint)lVar1;
  iVar5 = (int)(uVar6 + 0x800 >> 0xc |
               ((iVar5 * 0x1000 >> 0x1f) * uRam0210a48c + (int)((ulonglong)lVar1 >> 0x20) +
               (uint)(0xfffff7ff < uVar6)) * 0x100000) >> 0xc;
  piVar3[0x50] = iVar5 * iVar5;
  iVar5 = *piVar4;
  iVar8 = piVar4[1];
  iVar9 = piVar4[2];
  iVar10 = piVar4[3];
  uVar6 = (uint)(piVar4 + 4) & 3;
  uVar7 = *(uint *)((uint)(piVar4 + 4) & 0xfffffffc);
  uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
  piVar3[0x51] = iVar5;
  piVar3[0x55] = uVar6;
  piVar3[0x54] = iVar10;
  piVar3[0x52] = iVar8;
  piVar3[0x53] = iVar9;
  iVar10 = FX_Div((iVar9 - uVar6) * 0x1000,(iVar8 - iVar10) * 0x1000);
  piVar3[0x56] = iVar10;
  iVar10 = FX_Div(iVar9 << 0xc,(iVar8 - iVar5) * 0x1000);
  piVar3[0x57] = iVar10;
  uVar6 = (uint)(piVar3 + 0x54) & 3;
  uVar7 = *(uint *)((uint)(piVar3 + 0x54) & 0xfffffffc);
  iVar10 = FX_Div(uRam0210a488,(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) * 0x1000 + 0x36000)
  ;
  piVar3[0x58] = iVar10;
  piVar4 = piRam0210a4c4;
  lVar1 = (ulonglong)uRam0210a48c * (ulonglong)(uint)(iVar5 * 0x1000);
  uVar6 = (uint)lVar1;
  iVar5 = (int)(uVar6 + 0x800 >> 0xc |
               ((iVar5 * 0x1000 >> 0x1f) * uRam0210a48c + (int)((ulonglong)lVar1 >> 0x20) +
               (uint)(0xfffff7ff < uVar6)) * 0x100000) >> 0xc;
  piVar3[0x59] = iVar5 * iVar5;
  iVar5 = *piVar4;
  iVar8 = piVar4[1];
  iVar9 = piVar4[2];
  iVar10 = piVar4[3];
  uVar6 = (uint)(piVar4 + 4) & 3;
  uVar7 = *(uint *)((uint)(piVar4 + 4) & 0xfffffffc);
  uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
  piVar3[0x5a] = iVar5;
  piVar3[0x5e] = uVar6;
  piVar3[0x5d] = iVar10;
  piVar3[0x5b] = iVar8;
  piVar3[0x5c] = iVar9;
  iVar10 = FX_Div((iVar9 - uVar6) * 0x1000,(iVar8 - iVar10) * 0x1000);
  piVar3[0x5f] = iVar10;
  iVar10 = FX_Div(iVar9 << 0xc,(iVar8 - iVar5) * 0x1000);
  piVar3[0x60] = iVar10;
  uVar6 = (uint)(piVar3 + 0x5d) & 3;
  uVar7 = *(uint *)((uint)(piVar3 + 0x5d) & 0xfffffffc);
  iVar10 = FX_Div(uRam0210a488,(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) * 0x1000 + 0x36000)
  ;
  piVar3[0x61] = iVar10;
  piVar4 = piRam0210a4c8;
  lVar1 = (ulonglong)uRam0210a48c * (ulonglong)(uint)(iVar5 * 0x1000);
  uVar6 = (uint)lVar1;
  iVar5 = (int)(uVar6 + 0x800 >> 0xc |
               ((iVar5 * 0x1000 >> 0x1f) * uRam0210a48c + (int)((ulonglong)lVar1 >> 0x20) +
               (uint)(0xfffff7ff < uVar6)) * 0x100000) >> 0xc;
  piVar3[0x62] = iVar5 * iVar5;
  iVar5 = *piVar4;
  iVar8 = piVar4[1];
  iVar9 = piVar4[2];
  iVar10 = piVar4[3];
  uVar6 = (uint)(piVar4 + 4) & 3;
  uVar7 = *(uint *)((uint)(piVar4 + 4) & 0xfffffffc);
  uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
  piVar3[99] = iVar5;
  piVar3[0x67] = uVar6;
  piVar3[0x66] = iVar10;
  piVar3[100] = iVar8;
  piVar3[0x65] = iVar9;
  iVar10 = FX_Div((iVar9 - uVar6) * 0x1000,(iVar8 - iVar10) * 0x1000);
  piVar3[0x68] = iVar10;
  iVar10 = FX_Div(iVar9 << 0xc,(iVar8 - iVar5) * 0x1000);
  piVar3[0x69] = iVar10;
  uVar6 = (uint)(piVar3 + 0x66) & 3;
  uVar7 = *(uint *)((uint)(piVar3 + 0x66) & 0xfffffffc);
  iVar10 = FX_Div(uRam0210a488,(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) * 0x1000 + 0x36000)
  ;
  piVar3[0x6a] = iVar10;
  piVar4 = piRam0210a4cc;
  lVar1 = (ulonglong)uRam0210a48c * (ulonglong)(uint)(iVar5 * 0x1000);
  uVar6 = (uint)lVar1;
  iVar5 = (int)(uVar6 + 0x800 >> 0xc |
               ((iVar5 * 0x1000 >> 0x1f) * uRam0210a48c + (int)((ulonglong)lVar1 >> 0x20) +
               (uint)(0xfffff7ff < uVar6)) * 0x100000) >> 0xc;
  piVar3[0x6b] = iVar5 * iVar5;
  iVar5 = *piVar4;
  iVar8 = piVar4[1];
  iVar9 = piVar4[2];
  iVar10 = piVar4[3];
  uVar6 = (uint)(piVar4 + 4) & 3;
  uVar7 = *(uint *)((uint)(piVar4 + 4) & 0xfffffffc);
  uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
  piVar3[0x6c] = iVar5;
  piVar3[0x70] = uVar6;
  piVar3[0x6f] = iVar10;
  piVar3[0x6d] = iVar8;
  piVar3[0x6e] = iVar9;
  iVar10 = FX_Div((iVar9 - uVar6) * 0x1000,(iVar8 - iVar10) * 0x1000);
  piVar3[0x71] = iVar10;
  iVar10 = FX_Div(iVar9 << 0xc,(iVar8 - iVar5) * 0x1000);
  piVar3[0x72] = iVar10;
  uVar6 = (uint)(piVar3 + 0x6f) & 3;
  uVar7 = *(uint *)((uint)(piVar3 + 0x6f) & 0xfffffffc);
  iVar10 = FX_Div(uRam0210a488,(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) * 0x1000 + 0x36000)
  ;
  piVar3[0x73] = iVar10;
  piVar4 = piRam0210a4d0;
  lVar1 = (ulonglong)uRam0210a48c * (ulonglong)(uint)(iVar5 * 0x1000);
  uVar6 = (uint)lVar1;
  iVar5 = (int)(uVar6 + 0x800 >> 0xc |
               ((iVar5 * 0x1000 >> 0x1f) * uRam0210a48c + (int)((ulonglong)lVar1 >> 0x20) +
               (uint)(0xfffff7ff < uVar6)) * 0x100000) >> 0xc;
  piVar3[0x74] = iVar5 * iVar5;
  iVar5 = *piVar4;
  iVar8 = piVar4[1];
  iVar9 = piVar4[2];
  iVar10 = piVar4[3];
  uVar6 = (uint)(piVar4 + 4) & 3;
  uVar7 = *(uint *)((uint)(piVar4 + 4) & 0xfffffffc);
  uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
  piVar3[0x75] = iVar5;
  piVar3[0x79] = uVar6;
  piVar3[0x78] = iVar10;
  piVar3[0x76] = iVar8;
  piVar3[0x77] = iVar9;
  iVar10 = FX_Div((iVar9 - uVar6) * 0x1000,(iVar8 - iVar10) * 0x1000);
  piVar3[0x7a] = iVar10;
  iVar10 = FX_Div(iVar9 << 0xc,(iVar8 - iVar5) * 0x1000);
  piVar3[0x7b] = iVar10;
  uVar6 = (uint)(piVar3 + 0x78) & 3;
  uVar7 = *(uint *)((uint)(piVar3 + 0x78) & 0xfffffffc);
  iVar10 = FX_Div(uRam0210a488,(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) * 0x1000 + 0x36000)
  ;
  piVar3[0x7c] = iVar10;
  piVar4 = piRam0210a4d4;
  lVar1 = (ulonglong)uRam0210a48c * (ulonglong)(uint)(iVar5 * 0x1000);
  uVar6 = (uint)lVar1;
  iVar5 = (int)(uVar6 + 0x800 >> 0xc |
               ((iVar5 * 0x1000 >> 0x1f) * uRam0210a48c + (int)((ulonglong)lVar1 >> 0x20) +
               (uint)(0xfffff7ff < uVar6)) * 0x100000) >> 0xc;
  piVar3[0x7d] = iVar5 * iVar5;
  iVar5 = *piVar4;
  iVar8 = piVar4[1];
  iVar9 = piVar4[2];
  iVar10 = piVar4[3];
  uVar6 = (uint)(piVar4 + 4) & 3;
  uVar7 = *(uint *)((uint)(piVar4 + 4) & 0xfffffffc);
  uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
  piVar3[0x7e] = iVar5;
  piVar3[0x82] = uVar6;
  piVar3[0x81] = iVar10;
  piVar3[0x7f] = iVar8;
  piVar3[0x80] = iVar9;
  iVar10 = FX_Div((iVar9 - uVar6) * 0x1000,(iVar8 - iVar10) * 0x1000);
  piVar3[0x83] = iVar10;
  iVar10 = FX_Div(iVar9 << 0xc,(iVar8 - iVar5) * 0x1000);
  piVar3[0x84] = iVar10;
  uVar6 = (uint)(piVar3 + 0x81) & 3;
  uVar7 = *(uint *)((uint)(piVar3 + 0x81) & 0xfffffffc);
  iVar10 = FX_Div(uRam0210a488,(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) * 0x1000 + 0x36000)
  ;
  piVar3[0x85] = iVar10;
  piVar4 = piRam0210a4d8;
  lVar1 = (ulonglong)uRam0210a48c * (ulonglong)(uint)(iVar5 * 0x1000);
  uVar6 = (uint)lVar1;
  iVar5 = (int)(uVar6 + 0x800 >> 0xc |
               ((iVar5 * 0x1000 >> 0x1f) * uRam0210a48c + (int)((ulonglong)lVar1 >> 0x20) +
               (uint)(0xfffff7ff < uVar6)) * 0x100000) >> 0xc;
  piVar3[0x86] = iVar5 * iVar5;
  iVar5 = *piVar4;
  iVar8 = piVar4[1];
  iVar9 = piVar4[2];
  iVar10 = piVar4[3];
  uVar6 = (uint)(piVar4 + 4) & 3;
  uVar7 = *(uint *)((uint)(piVar4 + 4) & 0xfffffffc);
  uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
  piVar3[0x87] = iVar5;
  piVar3[0x8b] = uVar6;
  piVar3[0x8a] = iVar10;
  piVar3[0x88] = iVar8;
  piVar3[0x89] = iVar9;
  iVar10 = FX_Div((iVar9 - uVar6) * 0x1000,(iVar8 - iVar10) * 0x1000);
  piVar3[0x8c] = iVar10;
  iVar10 = FX_Div(iVar9 << 0xc,(iVar8 - iVar5) * 0x1000);
  piVar3[0x8d] = iVar10;
  uVar6 = (uint)(piVar3 + 0x8a) & 3;
  uVar7 = *(uint *)((uint)(piVar3 + 0x8a) & 0xfffffffc);
  iVar10 = FX_Div(uRam0210a488,(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) * 0x1000 + 0x36000)
  ;
  piVar3[0x8e] = iVar10;
  lVar1 = (ulonglong)uRam0210a48c * (ulonglong)(uint)(iVar5 * 0x1000);
  uVar6 = (uint)lVar1;
  iVar5 = (int)(uVar6 + 0x800 >> 0xc |
               ((iVar5 * 0x1000 >> 0x1f) * uRam0210a48c + (int)((ulonglong)lVar1 >> 0x20) +
               (uint)(0xfffff7ff < uVar6)) * 0x100000) >> 0xc;
  piVar3[0x8f] = iVar5 * iVar5;
  return;
}

