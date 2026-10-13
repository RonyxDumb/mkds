/* Decompiled C draft; module arm9; ROM address 020a5608. No matching claim. */
#include "types.h"
#include "deps/020a5608_func_020a5608.h"

void func_020a5608(int param_1,int param_2)

{
  uint uVar1;
  ushort uVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  
  func_02100138(0x6a);
  iVar4 = func_0209bbfc();
  if (iVar4 != 0) {
    *(ushort *)(iVar4 + 2) = *(ushort *)(iVar4 + 2) | *puRam020a5738;
    *(ushort *)(iVar4 + 2) = *(ushort *)(iVar4 + 2) & 0xffdf;
    uVar1 = param_1 + 0x80U & 3;
    uVar7 = *(uint *)(param_1 + 0x80U & 0xfffffffc);
    *(uint *)(iVar4 + 4) = uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20;
    uVar1 = param_1 + 0x84U & 3;
    uVar7 = *(uint *)(param_1 + 0x84U & 0xfffffffc);
    *(uint *)(iVar4 + 8) = uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20;
    uVar1 = param_1 + 0x88U & 3;
    uVar7 = *(uint *)(param_1 + 0x88U & 0xfffffffc);
    *(uint *)(iVar4 + 0xc) = uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20;
    *(undefined4 *)(iVar4 + 0x10) = 0;
    *(undefined4 *)(iVar4 + 0x14) = 0x1000;
    *(undefined4 *)(iVar4 + 0x18) = 0;
    *(undefined2 *)(iVar4 + 200) = *(undefined2 *)(param_1 + 0x74);
    *(undefined2 *)(iVar4 + 0xca) = *(undefined2 *)(param_2 + 0x74);
    *(undefined4 *)(iVar4 + 0xa0) = 0;
    *(undefined4 *)(iVar4 + 0xa4) = 0;
    *(undefined4 *)(iVar4 + 0xa8) = 0;
    *(undefined4 *)(iVar4 + 0xc0) = 0;
    *(undefined4 *)(iVar4 + 0xe0) = 3;
    uVar5 = *(undefined4 *)(param_2 + 0x84);
    uVar6 = *(undefined4 *)(param_2 + 0x88);
    *(undefined4 *)(iVar4 + 0xcc) = *(undefined4 *)(param_2 + 0x80);
    *(undefined4 *)(iVar4 + 0xd0) = uVar5;
    *(undefined4 *)(iVar4 + 0xd4) = uVar6;
    if (param_2 == param_1) {
      *(undefined4 *)(iVar4 + 0xd8) = 0;
    }
    else {
      *(undefined4 *)(iVar4 + 0xd8) = uRam020a573c;
    }
    *(undefined4 *)(iVar4 + 0xdc) = 0;
    *(undefined4 *)(iVar4 + 0xc4) = 0xffffffff;
    func_020a1218(1);
    uVar2 = *(ushort *)(param_1 + 0x74);
    cVar3 = *(char *)((*(uint *)(uRam020a5740 & 0xfffffffc) >> (uRam020a5740 & 3) * 8 |
                      *(uint *)(uRam020a5740 & 0xfffffffc) << (uRam020a5740 & 3) * -8 + 0x20) + 0x62
                     );
    uVar5 = func_020a1180();
    uVar6 = func_020a1154(*(undefined2 *)(param_1 + 0x74));
    uVar5 = func_02024974(1,(uint)uVar2 == (int)cVar3,uVar5,uVar6);
    uVar1 = iVar4 + 0x94U & 3;
    uVar7 = *(uint *)(iVar4 + 0x94U & 0xfffffffc);
    func_0210b98c(uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20,uVar5);
    return;
  }
  return;
}

