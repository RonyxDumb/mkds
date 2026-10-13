/* Decompiled C draft; module arm9; ROM address 020a6ae4. No matching claim. */
#include "types.h"
#include "deps/020a6ae4_func_020a6ae4.h"

undefined1 func_020a6ae4(int param_1,int param_2,char *param_3,undefined1 *param_4)

{
  uint uVar1;
  char cVar2;
  undefined1 uVar3;
  ushort uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  
  uVar1 = param_2 + 0x180U & 3;
  uVar8 = *(uint *)(param_2 + 0x180U & 0xfffffffc);
  cVar2 = *param_3;
  uVar3 = *param_4;
  if (((uVar8 >> uVar1 * 8 != 0 || uVar8 << uVar1 * -8 + 0x20 != 0) ||
      (uVar1 = param_2 + 0x48U & 3, uVar8 = *(uint *)(param_2 + 0x48U & 0xfffffffc),
      ((uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20) & 0x200) != 0)) ||
     (iVar5 = func_020a1084(*(undefined2 *)(param_2 + 0x74)), iVar5 != 0)) {
    return 0;
  }
  if (cVar2 == '\x01') {
    uVar1 = param_2 + 0x4cU & 3;
    uVar8 = *(uint *)(param_2 + 0x4cU & 0xfffffffc);
    if (((uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20) & 0x400000) != 0) {
      return uVar3;
    }
    uVar1 = param_1 + 0xc0U & 3;
    uVar8 = *(uint *)(param_1 + 0xc0U & 0xfffffffc);
    if (0 < (int)(uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20)) {
      return uVar3;
    }
    *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puRam020a6c5c;
    *(undefined4 *)(param_1 + 0xc0) = 0x19;
    uVar1 = param_2 + 0x80U & 3;
    uVar8 = *(uint *)(param_2 + 0x80U & 0xfffffffc);
    *(uint *)(param_1 + 4) = uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20;
    iVar5 = func_020a23a0(param_2);
    uVar1 = param_2 + 0x84U & 3;
    uVar8 = *(uint *)(param_2 + 0x84U & 0xfffffffc);
    *(uint *)(param_1 + 8) = (uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20) + iVar5 + 0x7800;
    uVar1 = param_2 + 0x88U & 3;
    uVar8 = *(uint *)(param_2 + 0x88U & 0xfffffffc);
    *(uint *)(param_1 + 0xc) = uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20;
    *(undefined4 *)(param_1 + 0xa0) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0x3000;
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0xa8) = 0;
    *(undefined4 *)(param_1 + 0xe0) = 2;
    *(undefined2 *)(param_1 + 200) = *(undefined2 *)(param_2 + 0x74);
    *(undefined2 *)(param_1 + 0xca) = *(undefined2 *)(param_2 + 0x74);
    func_020a10ac(*(undefined2 *)(param_2 + 0x74),1);
    MaybeUpdateDriverBalloonShineCount(*(undefined2 *)(param_2 + 0x74),1);
    uVar4 = *(ushort *)(param_2 + 0x74);
    cVar2 = *(char *)((*(uint *)(uRam020a6c60 & 0xfffffffc) >> (uRam020a6c60 & 3) * 8 |
                      *(uint *)(uRam020a6c60 & 0xfffffffc) << (uRam020a6c60 & 3) * -8 + 0x20) + 0x62
                     );
    uVar6 = func_020a1180();
    uVar7 = func_020a1154(*(undefined2 *)(param_2 + 0x74));
    uVar6 = func_02024974(0,(uint)uVar4 == (int)cVar2,uVar6,uVar7);
    uVar1 = param_1 + 0x94U & 3;
    uVar8 = *(uint *)(param_1 + 0x94U & 0xfffffffc);
    func_0210b98c(uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20,uVar6);
    uVar6 = func_0208b7bc(0x7d,param_1 + 4);
    *(undefined4 *)(param_1 + 0xe4) = uVar6;
    *(undefined4 *)(param_1 + 0xe8) = 0xe;
  }
  return uVar3;
}

