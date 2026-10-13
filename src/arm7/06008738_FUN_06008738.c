/* Decompiled C draft; module arm7; ROM address 06008738. No matching claim. */
#include "types.h"
#include "deps/06008738_FUN_06008738.h"

undefined2 FUN_06008738(uint param_1)

{
  uint *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined1 auStack_10 [4];
  undefined4 local_c;
  
  uVar5 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  *DAT_06008904 = uVar5;
  local_c = 0;
  thunk_FUN_037fb278(0,uVar5,DAT_06008908);
  uVar2 = thunk_FUN_037f8a1c();
  puVar1 = DAT_06008904;
  *(undefined4 *)
   ((*(uint *)((uint)DAT_06008904 & 0xfffffffc) >> ((uint)DAT_06008904 & 3) * 8 |
    *(uint *)((uint)DAT_06008904 & 0xfffffffc) << ((uint)DAT_06008904 & 3) * -8 + 0x20) + 0x314) =
       uVar2;
  uVar5 = param_1 + 0x18 & 3;
  uVar6 = *(uint *)(param_1 + 0x18 & 0xfffffffc);
  *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
            *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 0x30c) =
       uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
  uVar5 = param_1 + 0x1c & 3;
  uVar6 = *(uint *)(param_1 + 0x1c & 0xfffffffc);
  *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
            *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 0x310) =
       (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) >> 1;
  uVar7 = *(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
          *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20;
  uVar5 = uVar7 + 0x310;
  uVar6 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  if (uVar5 >> uVar6 * 8 == 0 && uVar5 << uVar6 * -8 + 0x20 == 0) {
    *(undefined4 *)(uVar7 + 0x310) = 0xffffffff;
  }
  FUN_06008d48(param_1 + 0x20);
  FUN_060186e8();
  *DAT_0600890c = *DAT_0600890c | 2;
  *DAT_06008910 = 0x30;
  puVar1 = DAT_06008904;
  *(undefined4 *)
   ((*(uint *)((uint)DAT_06008904 & 0xfffffffc) >> ((uint)DAT_06008904 & 3) * 8 |
    *(uint *)((uint)DAT_06008904 & 0xfffffffc) << ((uint)DAT_06008904 & 3) * -8 + 0x20) + 0x68c) = 3
  ;
  uVar5 = (uint)puVar1 & 3;
  uVar6 = *(uint *)((uint)puVar1 & 0xfffffffc);
  FUN_06018844(0x3c,2,(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) + DAT_06008914);
  FUN_06018844(0x3e,2,(*(uint *)((uint)DAT_06008904 & 0xfffffffc) >> ((uint)DAT_06008904 & 3) * 8 |
                      *(uint *)((uint)DAT_06008904 & 0xfffffffc) <<
                      ((uint)DAT_06008904 & 3) * -8 + 0x20) + 0x690);
  puVar1 = DAT_06008904;
  uVar5 = param_1 + 0x10 & 3;
  uVar6 = *(uint *)(param_1 + 0x10 & 0xfffffffc);
  *(uint *)((*(uint *)((uint)DAT_06008904 & 0xfffffffc) >> ((uint)DAT_06008904 & 3) * 8 |
            *(uint *)((uint)DAT_06008904 & 0xfffffffc) << ((uint)DAT_06008904 & 3) * -8 + 0x20) +
           0x308) = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
  uVar5 = param_1 + 0x14 & 3;
  uVar8 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
  uVar6 = (uint)puVar1 & 3;
  uVar7 = *(uint *)((uint)puVar1 & 0xfffffffc);
  *(uint *)((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) + 0x304) =
       uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20;
  uVar5 = param_1 + 0x30 & 3;
  uVar6 = *(uint *)(param_1 + 0x30 & 0xfffffffc);
  uVar2 = thunk_FUN_03806d38(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20,0x1c);
  uVar5 = param_1 + 0x2c & 3;
  uVar6 = *(uint *)(param_1 + 0x2c & 0xfffffffc);
  FUN_0600bd44(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20,uVar2);
  FUN_06008c0c();
  FUN_0600f118();
  FUN_0600f54c();
  FUN_0600e3c4();
  FUN_06009aa0();
  iVar3 = FUN_060188f4((uint *)(void *)(auStack_10));
  if (iVar3 == 0) {
    FUN_06009d3c();
    FUN_0600c258();
    FUN_0600ace4();
    FUN_06009d04();
    FUN_06009b04();
    FUN_0600c0d4();
    FUN_0600bddc();
    FUN_06009c94();
    FUN_0600b218();
    FUN_0600ad78();
  }
  else {
    uVar5 = *(uint *)((uint)DAT_06008904 & 0xfffffffc) >> ((uint)DAT_06008904 & 3) * 8 |
            *(uint *)((uint)DAT_06008904 & 0xfffffffc) << ((uint)DAT_06008904 & 3) * -8 + 0x20;
    *(ushort *)(uVar5 + 0x33e) = *(ushort *)(uVar5 + 0x33e) | 0x80;
  }
  uVar5 = param_1 + 8 & 3;
  uVar8 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar6 = param_1 + 0xc & 3;
  uVar4 = *(uint *)(param_1 + 0xc & 0xfffffffc);
  uVar7 = param_1 + 4 & 3;
  uVar9 = *(uint *)(param_1 + 4 & 0xfffffffc);
  thunk_FUN_037f92d0((*(uint *)((uint)DAT_06008904 & 0xfffffffc) >> ((uint)DAT_06008904 & 3) * 8 |
                     *(uint *)((uint)DAT_06008904 & 0xfffffffc) <<
                     ((uint)DAT_06008904 & 3) * -8 + 0x20) + 0x18,DAT_06008918,0,
                     uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20,
                     uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20,
                     uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20);
  thunk_FUN_037f9054((*(uint *)((uint)DAT_06008904 & 0xfffffffc) >> ((uint)DAT_06008904 & 3) * 8 |
                     *(uint *)((uint)DAT_06008904 & 0xfffffffc) <<
                     ((uint)DAT_06008904 & 3) * -8 + 0x20) + 0x18);
  FUN_0600c434();
  return *(undefined2 *)
          ((*(uint *)((uint)DAT_06008904 & 0xfffffffc) >> ((uint)DAT_06008904 & 3) * 8 |
           *(uint *)((uint)DAT_06008904 & 0xfffffffc) << ((uint)DAT_06008904 & 3) * -8 + 0x20) +
          0x33e);
}

