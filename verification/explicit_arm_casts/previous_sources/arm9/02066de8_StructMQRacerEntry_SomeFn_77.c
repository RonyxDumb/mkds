/* Decompiled C draft; module arm9; ROM address 02066de8. No matching claim. */
#include "types.h"
#include "deps/02066de8_StructMQRacerEntry_SomeFn_77.h"

void StructMQRacerEntry_SomeFn_77(int param_1)

{
  int iVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar6;
  undefined1 auStack_38 [48];
  uint uVar5;
  
  iVar1 = iRam02066fcc;
  *(short *)(param_1 + 0x5a0) = *(short *)(param_1 + 0x5a0) + *psRam02066fc8;
  *(int *)(param_1 + 0x5a4) =
       (int)*(short *)(iVar1 + ((int)(uint)*(ushort *)(param_1 + 0x5a0) >> 4) * 4);
  uVar5 = param_1 + 0x594U & 3;
  uVar4 = *(uint *)(param_1 + 0x594U & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  if ((int)uVar5 < 1) goto LAB_02066ec4;
  lVar2 = (longlong)(int)uVar5 *
          (longlong)
          (int)(*(uint *)(uRam02066fd0 & 0xfffffffc) >> (uRam02066fd0 & 3) * 8 |
               *(uint *)(uRam02066fd0 & 0xfffffffc) << (uRam02066fd0 & 3) * -8 + 0x20) + 0x800;
  *(uint *)(param_1 + 0x594) = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000;
  uVar5 = param_1 + 0x594U & 3;
  uVar4 = *(uint *)(param_1 + 0x594U & 0xfffffffc);
  *(uint *)(param_1 + 0x594) = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) - 100;
  uVar5 = param_1 + 0x44U & 3;
  uVar4 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  if (((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 0x10) == 0) {
LAB_02066e80:
    uVar5 = param_1 + 0x594U & 3;
    uVar4 = *(uint *)(param_1 + 0x594U & 0xfffffffc);
    uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
    lVar2 = (ulonglong)uRam02066fd4 * (ulonglong)uVar5;
    uVar4 = (uint)lVar2;
    *(uint *)(param_1 + 0x594) =
         uVar4 + 0x800 >> 0xc |
         (((int)uVar5 >> 0x1f) * uRam02066fd4 + (int)((ulonglong)lVar2 >> 0x20) +
         (uint)(0xfffff7ff < uVar4)) * 0x100000;
  }
  else {
    uVar5 = param_1 + 0x2a8U & 3;
    uVar4 = *(uint *)(param_1 + 0x2a8U & 0xfffffffc);
    uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
    if ((int)uVar5 < 1) {
      uVar5 = -uVar5;
    }
    if ((int)uVar5 < 0x3000) goto LAB_02066e80;
  }
  uVar5 = param_1 + 0x594U & 3;
  uVar4 = *(uint *)(param_1 + 0x594U & 0xfffffffc);
  if ((int)(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) < 0) {
    *(undefined4 *)(param_1 + 0x594) = 0;
  }
LAB_02066ec4:
  uVar5 = param_1 + 0x594U & 3;
  uVar3 = *(uint *)(param_1 + 0x594U & 0xfffffffc);
  uVar4 = param_1 + 0x59cU & 3;
  uVar6 = *(uint *)(param_1 + 0x59cU & 0xfffffffc);
  uVar4 = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
  lVar2 = (longlong)
          (int)((int)*(short *)(param_1 + 0x598) * (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20)
               - uVar4) *
          (longlong)
          (int)(*(uint *)(uRam02066fd8 & 0xfffffffc) >> (uRam02066fd8 & 3) * 8 |
               *(uint *)(uRam02066fd8 & 0xfffffffc) << (uRam02066fd8 & 3) * -8 + 0x20) + 0x800;
  *(uint *)(param_1 + 0x59c) =
       uVar4 + ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000);
  uVar5 = param_1 + 0x59cU & 3;
  uVar6 = *(uint *)(param_1 + 0x59cU & 0xfffffffc);
  uVar4 = param_1 + 0x5a4U & 3;
  uVar3 = *(uint *)(param_1 + 0x5a4U & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) *
          (longlong)
          (int)(*(uint *)(uRam02066fdc & 0xfffffffc) >> (uRam02066fdc & 3) * 8 |
               *(uint *)(uRam02066fdc & 0xfffffffc) << (uRam02066fdc & 3) * -8 + 0x20) + 0x800;
  iVar1 = (int)(((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000) *
                (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0x800 >> 0xc & 0xffff) >> 4;
  MTX_RotY43__from_thumb
            (auStack_38,(int)*(short *)(iRam02066fcc + iVar1 * 4),
             (int)*(short *)(iRam02066fcc + (iVar1 * 2 + 1) * 2));
  MTX_Concat43(auStack_38,param_1 + 0x150,param_1 + 0x184);
  uVar5 = param_1 + 0x59cU & 3;
  uVar4 = *(uint *)(param_1 + 0x59cU & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  if ((int)uVar5 < 1) {
    uVar5 = -uVar5;
  }
  if ((int)uVar5 < 0x29) {
    uVar5 = param_1 + 0x4cU & 3;
    uVar4 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    *(uint *)(param_1 + 0x4c) = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 0xfdffffff;
    *(undefined2 *)(param_1 + 0x5a0) = 0;
    *(undefined4 *)(param_1 + 0x5a4) = 0;
    *(undefined4 *)(param_1 + 0x594) = 0;
    *(undefined2 *)(param_1 + 0x598) = 0;
    return;
  }
  return;
}

