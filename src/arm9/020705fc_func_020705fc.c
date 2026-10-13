/* Decompiled C draft; module arm9; ROM address 020705fc. No matching claim. */
#include "types.h"
#include "deps/020705fc_func_020705fc.h"

void func_020705fc(int param_1,int param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  uint local_70;
  uint local_6c;
  uint local_68;
  undefined4 local_64;
  undefined4 uStack_60;
  undefined4 local_5c;
  undefined1 auStack_58 [36];
  undefined1 auStack_34 [12];
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  
  DriverContext_SomeFn_1(param_1,1);
  *(undefined4 *)(param_1 + 0x260) = 0x3000;
  uVar8 = *(uint *)(uRam0207087c & 0xfffffffc) >> (uRam0207087c & 3) * 8 |
          *(uint *)(uRam0207087c & 0xfffffffc) << (uRam0207087c & 3) * -8 + 0x20;
  uVar4 = uVar8 + 0xfc & 3;
  uVar2 = *(uint *)(uVar8 + 0xfc & 0xfffffffc);
  uVar5 = uVar8 + 0x34 & 3;
  uVar3 = *(uint *)(uVar8 + 0x34 & 0xfffffffc);
  iVar7 = (uint)*(ushort *)((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) + param_2 * 2) * 0x1c;
  uVar4 = (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) + iVar7;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  local_70 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar4 = uVar8 + 0x34 & 3;
  uVar5 = *(uint *)(uVar8 + 0x34 & 0xfffffffc);
  uVar4 = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) + iVar7 + 4;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  local_6c = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar4 = uVar8 + 0x34 & 3;
  uVar5 = *(uint *)(uVar8 + 0x34 & 0xfffffffc);
  uVar4 = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) + iVar7 + 8;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  local_68 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar4 = uVar8 + 0xfc & 3;
  uVar2 = *(uint *)(uVar8 + 0xfc & 0xfffffffc);
  uVar5 = uVar8 + 0x34 & 3;
  uVar3 = *(uint *)(uVar8 + 0x34 & 0xfffffffc);
  uVar4 = (uint)*(ushort *)((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) + param_2 * 2) * 0x1c
          + (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) + 0x10;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  iVar7 = (int)((((int)uVar4 >> 0x1f) * uRam02070880 +
                 uVar4 * 0xb6 + (int)((ulonglong)uRam02070880 * (ulonglong)uVar4 >> 0x20) +
                (uint)(0x7fffffff < (uint)((ulonglong)uRam02070880 * (ulonglong)uVar4))) * 0x10 >>
               0x10) >> 4;
  MTX_RotY33__from_thumb
            ((undefined4 *)(void *)(auStack_58),(int)*(short *)(iRam02070884 + iVar7 * 4),
             (int)*(short *)(iRam02070884 + (iVar7 * 2 + 1) * 2));
  MTX_MultVec33(uRam02070888,(uint)(uintptr_t)(auStack_58),&local_64);
  uVar4 = (*(uint *)(uRam0207088c & 0xfffffffc) >> (uRam0207088c & 3) * 8 |
          *(uint *)(uRam0207088c & 0xfffffffc) << (uRam0207088c & 3) * -8 + 0x20) + 8;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if ((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) == 2) {
    VecFx32_Subtract((uint)(uintptr_t)(&local_70),param_1 + 0x80,(int *)(void *)(auStack_34));
    func_020a21bc(*(undefined2 *)(param_1 + 0x74),(int)(uintptr_t)(auStack_34));
  }
  *(uint *)(param_1 + 0x80) = local_70;
  *(uint *)(param_1 + 0x84) = local_6c;
  *(uint *)(param_1 + 0x88) = local_68;
  *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x80);
  *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(param_1 + 0x88);
  *(uint *)(param_1 + 0x98) = *(uint *)(param_1 + 0x8c);
  *(undefined4 *)(param_1 + 0x9c) = *(undefined4 *)(param_1 + 0x90);
  *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(param_1 + 0x94);
  *(undefined4 *)(param_1 + 0x2a8) = 0x5000;
  *(undefined4 *)(param_1 + 0x50) = local_64;
  *(undefined4 *)(param_1 + 0x54) = uStack_60;
  *(undefined4 *)(param_1 + 0x58) = local_5c;
  *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(param_1 + 0x6c) = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(param_1 + 0x58);
  uVar4 = func_02148538(local_64,local_5c);
  puVar1 = puRam02070894;
  *(short *)(param_1 + 0x236) =
       (short)((int)((uint)((ulonglong)uRam02070890 * (ulonglong)uVar4) >> 0xc |
                    (((int)uVar4 >> 0x1f) * uRam02070890 +
                    (int)((ulonglong)uRam02070890 * (ulonglong)uVar4 >> 0x20)) * 0x100000) >> 0xc);
  local_28 = *puVar1;
  uStack_24 = puVar1[1];
  uStack_20 = puVar1[2];
  func_01ffd190((uint)(uintptr_t)(&local_28),*(undefined2 *)(param_1 + 0x236),(uint *)(uintptr_t)(param_1 + 0xe0));
  uVar4 = param_1 + 0x7cU & 3;
  uVar5 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if ((((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 1) != 0) &&
     (func_02076a5c(),
     ((*(uint *)(uRam02070898 & 0xfffffffc) >> (uRam02070898 & 3) * 8 |
      *(uint *)(uRam02070898 & 0xfffffffc) << (uRam02070898 & 3) * -8 + 0x20) & 1) != 0)) {
    func_02108ea0(0);
    uVar5 = GetSomeSndPlayer();
    uVar4 = iRam0207089c + 0xcU & 3;
    uVar2 = *(uint *)(iRam0207089c + 0xcU & 0xfffffffc);
    if (uVar2 >> uVar4 * 8 != 0 || uVar2 << uVar4 * -8 + 0x20 != 0) {
      if (*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 != 0 ||
          *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20 != 0) {
        func_0212c6f0(uVar5,0);
      }
      if (*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 != 0 ||
          *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20 != 0) {
        func_0212c6f0(uVar5,0);
      }
      NNSi_MaybeSndPlayerStartSeq(uVar5,0,uRam020708a0);
    }
  }
  uVar4 = param_1 + 0x7cU & 3;
  uVar5 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 2) != 0) {
    uVar4 = (*(uint *)(uRam0207088c & 0xfffffffc) >> (uRam0207088c & 3) * 8 |
            *(uint *)(uRam0207088c & 0xfffffffc) << (uRam0207088c & 3) * -8 + 0x20) + 8;
    uVar5 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    if ((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) == 2) {
      uVar6 = func_02040da8(param_2);
      uVar4 = param_1 + 0x310U & 3;
      uVar5 = *(uint *)(param_1 + 0x310U & 0xfffffffc);
      func_02089754(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20,uVar6);
      return;
    }
    return;
  }
  return;
}

