/* Decompiled C draft; module arm9; ROM address 0206ff50. No matching claim. */
#include "types.h"
#include "deps/0206ff50_func_0206ff50.h"

void func_0206ff50(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 uStack_38;
  int iStack_34;
  undefined4 uStack_30;
  undefined4 auStack_2c [4];
  
  uVar2 = uRam02070370;
  uVar6 = param_1 + 0x7cU & 3;
  uVar1 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar1 >> uVar6 * 8 | uVar1 << uVar6 * -8 + 0x20) & 0x400) != 0) {
    return;
  }
  if ((param_2 & 0x8000) != 0) {
    uVar6 = param_1 + 0x180U & 3;
    uVar2 = *(uint *)(param_1 + 0x180U & 0xfffffffc);
    if ((uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) == 6) {
      return;
    }
    uVar1 = func_020d59f8(0x8000);
    uVar6 = (*(uint *)(uRam02070370 & 0xfffffffc) >> (uRam02070370 & 3) * 8 |
            *(uint *)(uRam02070370 & 0xfffffffc) << (uRam02070370 & 3) * -8 + 0x20) + 8;
    uVar2 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20;
    if ((uVar6 != 2) && (uVar6 != 4)) {
      uVar6 = param_1 + 0x48U & 3;
      uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
      *(uint *)(param_1 + 0x48) = uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20 | 0x10000;
      DriverContext_SomeFn_1(param_1,0);
      return;
    }
    func_020705fc(param_1,((uVar1 & 0xe0) << 0xb) >> 0x10);
    return;
  }
  uVar6 = param_1 + 0x48U & 3;
  uVar1 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  if (((uVar1 >> uVar6 * 8 | uVar1 << uVar6 * -8 + 0x20) & 0x800) == 0) {
    uVar6 = param_1 + 0x48U & 3;
    uVar1 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
    *(uint *)(param_1 + 0x48) = uVar1 >> uVar6 * 8 | uVar1 << uVar6 * -8 + 0x20 | 0x800;
    uVar6 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar6 = (uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) + 8;
    uVar2 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    if ((uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) == 2) {
      uVar3 = GetCourseCpoiRespawnId(0);
    }
    else {
      uVar3 = GetCourseCpoiRespawnId
                        (*(undefined2 *)
                          ((uint)*(ushort *)(param_1 + 0x74) * 0x8c +
                           (*(uint *)(uRam02070374 & 0xfffffffc) >> (uRam02070374 & 3) * 8 |
                           *(uint *)(uRam02070374 & 0xfffffffc) << (uRam02070374 & 3) * -8 + 0x20) +
                          0x46));
    }
    *(undefined4 *)(param_1 + 0x3c4) = uVar3;
    uVar6 = param_1 + 0x7cU & 3;
    uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if (((((uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) & 1) != 0) &&
        (uVar2 = *(uint *)(uRam02070370 & 0xfffffffc) >> (uRam02070370 & 3) * 8 |
                 *(uint *)(uRam02070370 & 0xfffffffc) << (uRam02070370 & 3) * -8 + 0x20,
        uVar6 = uVar2 & 3, uVar2 = *(uint *)(uVar2 & 0xfffffffc),
        (uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) == 0x1d)) &&
       (((*(uint *)(uRam02070378 & 0xfffffffc) >> (uRam02070378 & 3) * 8 |
         *(uint *)(uRam02070378 & 0xfffffffc) << (uRam02070378 & 3) * -8 + 0x20) & 1) != 0)) {
      func_02108ea0(0);
      uVar2 = GetSomeSndPlayer();
      uVar6 = iRam0207037c + 0xcU & 3;
      uVar1 = *(uint *)(iRam0207037c + 0xcU & 0xfffffffc);
      if (uVar1 >> uVar6 * 8 != 0 || uVar1 << uVar6 * -8 + 0x20 != 0) {
        if (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 != 0 ||
            *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20 != 0) {
          func_0212c6f0(uVar2,0);
        }
        if (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 != 0 ||
            *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20 != 0) {
          func_0212c6f0(uVar2,0);
        }
        NNSi_MaybeSndPlayerStartSeq(uVar2,0,uRam02070380);
      }
    }
  }
  if ((param_2 & 0xc00) == 0) {
    return;
  }
  uVar6 = param_1 + 0x48U & 3;
  uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  if (((uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) & 0x1000) != 0) {
    return;
  }
  func_020c4ab8(*(undefined2 *)(param_1 + 0x74));
  uVar2 = uRam02070384;
  uVar6 = param_1 + 0x48U & 3;
  uVar1 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  *(uint *)(param_1 + 0x48) = uVar1 >> uVar6 * 8 | uVar1 << uVar6 * -8 + 0x20 | 0x41000;
  uVar6 = param_1 + 0x48U & 3;
  uVar1 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  *(uint *)(param_1 + 0x48) = (uVar1 >> uVar6 * 8 | uVar1 << uVar6 * -8 + 0x20) & uVar2;
  *(undefined2 *)(param_1 + 0x238) = 0;
  *(undefined2 *)(param_1 + 0x538) = 0;
  *(undefined2 *)(param_1 + 0x23c) = 0;
  uVar6 = param_1 + 0x7cU & 3;
  uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) & 1) != 0) {
    uVar6 = param_1 + 0x4cU & 3;
    uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    if ((((uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) & 0x10000000) == 0) &&
       (uVar6 = param_1 + 0x48U & 3, uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc),
       ((uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) & 0x4000000) == 0)) {
      func_02074854();
    }
    func_02055c5c();
  }
  uVar6 = param_1 + 0x4cU & 3;
  uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if (((uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) & 0x10000000) != 0) {
    uVar6 = param_1 + 0x4cU & 3;
    uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    *(uint *)(param_1 + 0x4c) = (uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) & 0xefffffff;
    func_0210515c(*(undefined2 *)(param_1 + 0x74));
    uVar6 = param_1 + 0x7cU & 3;
    uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if (((uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) & 1) != 0) {
      func_02074854();
    }
    *(undefined4 *)(param_1 + 0x4c8) = 0x1000;
    *(undefined4 *)(param_1 + 0x3dc) = 0xffffffff;
    iVar7 = 0;
    *(undefined4 *)(param_1 + 0x29c) = 0;
    uVar6 = param_1 + 0x590U & 3;
    uVar2 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
    uVar6 = (uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) + 0x58;
    uVar2 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    if (uVar6 >> uVar2 * 8 == 0 && uVar6 << uVar2 * -8 + 0x20 == 0) {
      auStack_2c[0] = *puRam02070388;
      auStack_2c[1] = puRam02070388[1];
      auStack_2c[2] = puRam02070388[2];
      do {
        uVar3 = func_0208b7bc(auStack_2c[iVar7],param_1 + 0x80);
        func_02081f10(uVar3,*(undefined2 *)(param_1 + 0x74),0x14);
        iVar7 = iVar7 + 1;
      } while (iVar7 < 3);
    }
    func_020815dc(*(undefined2 *)(param_1 + 0x74));
    DriverContext_MaybeQueuePlaySfx(param_1,0xfd,0x7f,0);
  }
  func_020f00f0((uint)*(ushort *)(param_1 + 0x74) * 0x210 +
                (*(uint *)(uRam0207038c & 0xfffffffc) >> (uRam0207038c & 3) * 8 |
                *(uint *)(uRam0207038c & 0xfffffffc) << (uRam0207038c & 3) * -8 + 0x20));
  if ((param_2 & 0x400) == 0) {
    uVar1 = func_020d59f8(0x800);
    uVar6 = param_1 + 0x3f8U & 3;
    uVar2 = *(uint *)(param_1 + 0x3f8U & 0xfffffffc);
    *(uint *)(param_1 + 0x4bc) = uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20;
    uVar6 = param_1 + 0x4cU & 3;
    uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    *(uint *)(param_1 + 0x4c) = uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20 | 0x200000;
    uVar2 = param_1 + 0x7cU & 3;
    uVar5 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    uVar6 = ((uVar1 & 0xe0) << 0xb) >> 0x10;
    if (((uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) & 1) != 0) {
      func_02075d08(1);
    }
    uVar3 = uRam02070394;
    if ((uVar6 + iRam02070390 & 0xffff) < 2) {
      uStack_38 = *(undefined4 *)(param_1 + 0x80);
      iStack_34 = *(undefined4 *)(param_1 + 0x84);
      uStack_30 = *(undefined4 *)(param_1 + 0x88);
      if (uVar6 == 1) {
        uVar6 = param_1 + 0x48U & 3;
        uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
        uVar3 = 0xce;
        *(uint *)(param_1 + 0x48) = uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20 | 0x800000;
      }
      else {
        uVar6 = param_1 + 0x48U & 3;
        uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
        *(uint *)(param_1 + 0x48) = uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20 | 0x1000000;
      }
      uVar6 = param_1 + 0x84U & 3;
      uVar2 = *(uint *)(param_1 + 0x84U & 0xfffffffc);
      iStack_34 = func_020d3d48(uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20);
      uVar6 = param_1 + 0x84U & 3;
      uVar2 = *(uint *)(param_1 + 0x84U & 0xfffffffc);
      iStack_34 = (uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) - iStack_34;
      uVar6 = param_1 + 0x7cU & 3;
      uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
      func_0208d978(&uStack_38,((uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) & 1) != 0);
      uVar6 = param_1 + 0x4cU & 3;
      uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
      *(uint *)(param_1 + 0x4c) = uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20 | 0x4000000;
      DriverContext_MaybeQueuePlaySfx(param_1,uVar3,0x7f,0);
      *(undefined4 *)(param_1 + 200) = 0;
    }
    uVar6 = param_1 + 0x3ccU & 3;
    uVar2 = *(uint *)(param_1 + 0x3ccU & 0xfffffffc);
    StructMQRacerEntry_SomeFn_5(param_1,uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20,0);
    return;
  }
  uVar2 = func_020d59f8(0x400);
  uVar6 = param_1 + 0x48U & 3;
  uVar1 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  *(uint *)(param_1 + 0x48) = uVar1 >> uVar6 * 8 | uVar1 << uVar6 * -8 + 0x20 | 0x2000;
  puVar4 = (uint *)(param_1 + 0x48);
  if ((uVar2 & 0xe0) == 0x80) {
    *puVar4 = *(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
              *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20 | 0x800000;
  }
  return;
}

