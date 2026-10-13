/* Decompiled C draft; module arm9; ROM address 020a29cc. No matching claim. */
#include "types.h"
#include "deps/020a29cc_func_020a29cc.h"

void func_020a29cc(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  short sVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined4 local_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  G2x_SetBlendAlpha_(uRam020a2dfc,1,0x1f,0x10,0x10);
  uVar6 = *(uint *)(uRam020a2e00 & 0xfffffffc) >> (uRam020a2e00 & 3) * 8 |
          *(uint *)(uRam020a2e00 & 0xfffffffc) << (uRam020a2e00 & 3) * -8 + 0x20;
  func_02010fac(0,(int)*(short *)(uVar6 + 0xfc),(int)*(short *)(uVar6 + 0x100),
                (int)*(short *)(uVar6 + 0x104));
  uVar6 = *(uint *)(uRam020a2e00 & 0xfffffffc) >> (uRam020a2e00 & 3) * 8 |
          *(uint *)(uRam020a2e00 & 0xfffffffc) << (uRam020a2e00 & 3) * -8 + 0x20;
  func_02010fac(1,(int)*(short *)(uVar6 + 0xfe),(int)*(short *)(uVar6 + 0x102),
                (int)*(short *)(uVar6 + 0x106));
  func_02010f98(0,uRam020a2e04);
  func_02010f98(1,uRam020a2e04);
  uVar6 = FX_Div((int)*(short *)(iRam020a2e08 + 0xa8),(int)*(short *)(iRam020a2e08 + 0xaa));
  uVar5 = (uint)((ulonglong)uRam020a2e0c * (ulonglong)uVar6) >> 0xc |
          (((int)uVar6 >> 0x1f) * uRam020a2e0c +
          (int)((ulonglong)uRam020a2e0c * (ulonglong)uVar6 >> 0x20)) * 0x100000;
  uVar6 = -uVar5;
  uVar8 = (uint)((ulonglong)uRam020a2e10 * (ulonglong)uVar6) >> 0xc |
          (((int)uVar6 >> 0x1f) * uRam020a2e10 +
          (int)((ulonglong)uRam020a2e10 * (ulonglong)uVar6 >> 0x20)) * 0x100000;
  if (*(char *)((*(uint *)(uRam020a2e14 & 0xfffffffc) >> (uRam020a2e14 & 3) * 8 |
                *(uint *)(uRam020a2e14 & 0xfffffffc) << (uRam020a2e14 & 3) * -8 + 0x20) + 0x57) ==
      '\0') {
    G3i_FrustumW_(uVar5,uVar6,uVar8,-uVar8,uRam020a2e0c,uRam020a2e18,0x200,0,uRam020a2e1c);
    uVar6 = iRam020a2e20 + 0xfcU & 3;
    uVar5 = *(uint *)(iRam020a2e20 + 0xfcU & 0xfffffffc);
    *(uint *)(iRam020a2e20 + 0xfc) = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0xffffffaf;
  }
  else {
    G3i_FrustumW_(uVar5,uVar6,-uVar8,uVar8,uRam020a2e0c,uRam020a2e18,0x200,0,uRam020a2e1c);
    uVar6 = iRam020a2e20 + 0xfcU & 3;
    uVar5 = *(uint *)(iRam020a2e20 + 0xfcU & 0xfffffffc);
    *(uint *)(iRam020a2e20 + 0xfc) = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0xffffffaf;
  }
  puVar1 = puRam020a2e2c;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_30 = *puRam020a2e24;
  uStack_2c = puRam020a2e24[1];
  uStack_28 = puRam020a2e24[2];
  local_3c = *puRam020a2e28;
  uStack_38 = puRam020a2e28[1];
  uStack_34 = puRam020a2e28[2];
  *puRam020a2e2c = local_3c;
  puVar1[1] = uStack_38;
  puVar1[2] = uStack_34;
  puVar1 = puRam020a2e30;
  *puRam020a2e30 = local_30;
  puVar1[1] = uStack_2c;
  puVar1[2] = uStack_28;
  puVar1 = puRam020a2e34;
  *puRam020a2e34 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  G3i_LookAt_(&local_3c,&local_30,&local_24,0,uRam020a2e38);
  uVar6 = iRam020a2e20 + 0xfcU & 3;
  uVar7 = *(uint *)(iRam020a2e20 + 0xfcU & 0xfffffffc);
  uVar5 = uRam020a2e3c & 3;
  uVar8 = *(uint *)(uRam020a2e3c & 0xfffffffc);
  *(uint *)(iRam020a2e20 + 0xfc) = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) & 0xffffff17;
  DisplayConfig_SetSwapBufferValues(uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20,1,1);
  *(undefined4 *)(iRam020a2e20 + 0xa0) = uRam020a2e40;
  func_02011034();
  if (2 < *(ushort *)
           ((*(uint *)(uRam020a2e00 & 0xfffffffc) >> (uRam020a2e00 & 3) * 8 |
            *(uint *)(uRam020a2e00 & 0xfffffffc) << (uRam020a2e00 & 3) * -8 + 0x20) + 2)) {
    return;
  }
  sVar4 = func_0204a508();
  *(short *)((*(uint *)(uRam020a2e00 & 0xfffffffc) >> (uRam020a2e00 & 3) * 8 |
             *(uint *)(uRam020a2e00 & 0xfffffffc) << (uRam020a2e00 & 3) * -8 + 0x20) + 4) =
       sVar4 * -0x6d;
  sVar4 = func_0204a508();
  uVar5 = uRam020a2e00;
  uVar6 = *(uint *)(uRam020a2e00 & 0xfffffffc) >> (uRam020a2e00 & 3) * 8 |
          *(uint *)(uRam020a2e00 & 0xfffffffc) << (uRam020a2e00 & 3) * -8 + 0x20;
  *(short *)(uVar6 + 8) = sVar4 * -0x36;
  uVar2 = uRam020a2e44;
  *(undefined4 *)(uVar6 + 0x14) = 0;
  *(undefined4 *)(uVar6 + 0x18) = uVar2;
  *(undefined4 *)(uVar6 + 0x1c) = 0;
  *(undefined4 *)(uVar6 + 0x20) = 0x36;
  *(undefined4 *)(uVar6 + 0x24) = 0;
  uVar6 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  Matrix4x3_Identity((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0xcc);
  iVar3 = iRam020a2e48;
  uVar6 = uRam020a2e00;
  uVar5 = *(uint *)(uRam020a2e00 & 0xfffffffc) >> (uRam020a2e00 & 3) * 8 |
          *(uint *)(uRam020a2e00 & 0xfffffffc) << (uRam020a2e00 & 3) * -8 + 0x20;
  if (*(short *)(uVar5 + 2) == 0) {
    uVar8 = uVar5 + 0x114 & 3;
    uVar9 = *(uint *)(uVar5 + 0x114 & 0xfffffffc);
    uVar7 = uVar5 + 0x118 & 3;
    uVar5 = *(uint *)(uVar5 + 0x118 & 0xfffffffc);
    *(uint *)((uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) + 0x5c) =
         uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20;
    uVar8 = *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
            *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20;
    uVar5 = uVar8 + 0x118;
    uVar7 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar10 = uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20;
    uVar8 = uVar8 + 0x108;
    uVar7 = uVar8 & 3;
    uVar9 = *(uint *)(uVar8 & 0xfffffffc);
    uVar5 = uVar10 + 0x20;
    uVar8 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar8 = uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20;
    uVar5 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    uVar5 = (uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) + 4;
    uVar8 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    *(uint *)(uVar10 + 0x28) =
         (uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) +
         (uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20);
    uVar8 = *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
            *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20;
    uVar5 = uVar8 + 0x118;
    uVar7 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar10 = uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20;
    uVar8 = uVar8 + 0x10c;
    uVar7 = uVar8 & 3;
    uVar9 = *(uint *)(uVar8 & 0xfffffffc);
    uVar5 = uVar10 + 0x20;
    uVar8 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar8 = uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20;
    uVar5 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    uVar5 = (uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) + 8;
    uVar8 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    *(uint *)(uVar10 + 0x2c) =
         (uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) +
         (uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20);
    uVar8 = *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
            *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20;
    uVar5 = uVar8 + 0x118;
    uVar7 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar10 = uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20;
    uVar8 = uVar8 + 0x110;
    uVar7 = uVar8 & 3;
    uVar9 = *(uint *)(uVar8 & 0xfffffffc);
    uVar5 = uVar10 + 0x20;
    uVar8 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar8 = uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20;
    uVar5 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    uVar5 = (uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) + 0xc;
    uVar8 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    *(uint *)(uVar10 + 0x30) =
         (uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) +
         (uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20);
    uVar5 = (*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
            *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x11c;
    uVar8 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar7 = uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20;
    uVar5 = uVar7 + 0x20;
    uVar8 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar8 = uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20;
    uVar5 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    uVar5 = (uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) + 4;
    uVar8 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    *(uint *)(uVar7 + 0x28) = uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20;
    uVar5 = (*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
            *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x11c;
    uVar8 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar7 = uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20;
    uVar5 = uVar7 + 0x20;
    uVar8 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar8 = uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20;
    uVar5 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    uVar5 = (uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) + 8;
    uVar8 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    *(uint *)(uVar7 + 0x2c) = (uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20) - 0xcd;
    uVar5 = (*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
            *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x11c;
    uVar8 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar7 = uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20;
    uVar5 = uVar7 + 0x20;
    uVar8 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar8 = uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20;
    uVar5 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    uVar5 = (uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) + 0xc;
    uVar8 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    *(uint *)(uVar7 + 0x30) = (uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20) + iVar3;
    uVar5 = (*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
            *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x120;
    uVar8 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar7 = uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20;
    uVar5 = uVar7 + 0x20;
    uVar8 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar8 = uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20;
    uVar5 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    uVar5 = (uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) + 4;
    uVar8 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    *(uint *)(uVar7 + 0x28) = uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20;
    uVar5 = (*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
            *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x120;
    uVar8 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar7 = uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20;
    uVar5 = uVar7 + 0x20;
    uVar8 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar8 = uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20;
    uVar5 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    uVar5 = (uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) + 8;
    uVar8 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    *(uint *)(uVar7 + 0x2c) = (uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20) - 0xcd;
    uVar6 = (*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
            *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x120;
    uVar5 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar8 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
    uVar6 = uVar8 + 0x20;
    uVar5 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar5 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
    uVar6 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar6 = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0xc;
    uVar5 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    *(uint *)(uVar8 + 0x30) = (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) + iVar3;
    return;
  }
  if (*(short *)(uVar5 + 2) == 1) {
    uVar8 = uVar5 + 0x114 & 3;
    uVar9 = *(uint *)(uVar5 + 0x114 & 0xfffffffc);
    uVar7 = uVar5 + 0x118 & 3;
    uVar5 = *(uint *)(uVar5 + 0x118 & 0xfffffffc);
    *(uint *)((uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) + 0x5c) =
         uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20;
    uVar8 = *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
            *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20;
    uVar5 = uVar8 + 0x118;
    uVar7 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar10 = uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20;
    uVar8 = uVar8 + 0x108;
    uVar7 = uVar8 & 3;
    uVar9 = *(uint *)(uVar8 & 0xfffffffc);
    uVar5 = uVar10 + 0x20;
    uVar8 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar8 = uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20;
    uVar5 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    uVar5 = (uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) + 4;
    uVar8 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    *(uint *)(uVar10 + 0x28) =
         (uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) +
         (uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20);
    uVar8 = *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
            *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20;
    uVar5 = uVar8 + 0x118;
    uVar7 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar10 = uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20;
    uVar8 = uVar8 + 0x10c;
    uVar7 = uVar8 & 3;
    uVar9 = *(uint *)(uVar8 & 0xfffffffc);
    uVar5 = uVar10 + 0x20;
    uVar8 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar8 = uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20;
    uVar5 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    uVar5 = (uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) + 8;
    uVar8 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    *(uint *)(uVar10 + 0x2c) =
         (uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) +
         (uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20);
    uVar5 = *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
            *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20;
    uVar6 = uVar5 + 0x118;
    uVar8 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar9 = uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20;
    uVar5 = uVar5 + 0x110;
    uVar8 = uVar5 & 3;
    uVar7 = *(uint *)(uVar5 & 0xfffffffc);
    uVar6 = uVar9 + 0x20;
    uVar5 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar5 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
    uVar6 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar6 = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0xc;
    uVar5 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    *(uint *)(uVar9 + 0x30) =
         (uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) +
         (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
    return;
  }
  return;
}

