/* Decompiled C draft; module arm9; ROM address 02037abc. No matching claim. */
#include "types.h"
#include "deps/02037abc_SetGlobalDisplayConfig.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SetGlobalDisplayConfig(int param_1)

{
  uint *puVar1;
  ushort *puVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  uint uVar5;
  ushort *puVar6;
  uint uVar7;
  uint uVar8;
  
  *piRam020380b4 = param_1;
  MaybePrepareVram();
  Mem_CpuFastMemorySet(0xc0,0x7000000,0x400);
  Mem_CpuFastMemorySet(0xc0,uRam020380b8,0x400);
  Mem_CpuFastMemorySet(0,&DAT_05000000,0x400);
  Mem_CpuFastMemorySet(0,uRam020380bc,0x400);
  if (*(short *)((*(uint *)((uint)piRam020380b4 & 0xfffffffc) >> ((uint)piRam020380b4 & 3) * 8 |
                 *(uint *)((uint)piRam020380b4 & 0xfffffffc) <<
                 ((uint)piRam020380b4 & 3) * -8 + 0x20) + 0xe) != 0) {
    func_02149b20();
  }
  if (*(short *)((*(uint *)((uint)piRam020380b4 & 0xfffffffc) >> ((uint)piRam020380b4 & 3) * 8 |
                 *(uint *)((uint)piRam020380b4 & 0xfffffffc) <<
                 ((uint)piRam020380b4 & 3) * -8 + 0x20) + 0x10) != 0) {
    func_021499b4();
  }
  if (*(short *)((*(uint *)((uint)piRam020380b4 & 0xfffffffc) >> ((uint)piRam020380b4 & 3) * 8 |
                 *(uint *)((uint)piRam020380b4 & 0xfffffffc) <<
                 ((uint)piRam020380b4 & 3) * -8 + 0x20) + 0x12) != 0) {
    func_021498a0();
  }
  if (*(short *)((*(uint *)((uint)piRam020380b4 & 0xfffffffc) >> ((uint)piRam020380b4 & 3) * 8 |
                 *(uint *)((uint)piRam020380b4 & 0xfffffffc) <<
                 ((uint)piRam020380b4 & 3) * -8 + 0x20) + 0x14) != 0) {
    GX_SetBankForOBJExtPltt();
  }
  if (*(short *)((*(uint *)((uint)piRam020380b4 & 0xfffffffc) >> ((uint)piRam020380b4 & 3) * 8 |
                 *(uint *)((uint)piRam020380b4 & 0xfffffffc) <<
                 ((uint)piRam020380b4 & 3) * -8 + 0x20) + 0x16) != 0) {
    func_021495e4();
  }
  if (*(short *)((*(uint *)((uint)piRam020380b4 & 0xfffffffc) >> ((uint)piRam020380b4 & 3) * 8 |
                 *(uint *)((uint)piRam020380b4 & 0xfffffffc) <<
                 ((uint)piRam020380b4 & 3) * -8 + 0x20) + 0x18) != 0) {
    func_021494f0();
  }
  if (*(short *)((*(uint *)((uint)piRam020380b4 & 0xfffffffc) >> ((uint)piRam020380b4 & 3) * 8 |
                 *(uint *)((uint)piRam020380b4 & 0xfffffffc) <<
                 ((uint)piRam020380b4 & 3) * -8 + 0x20) + 0x1a) != 0) {
    func_021493b0();
  }
  if (*(short *)((*(uint *)((uint)piRam020380b4 & 0xfffffffc) >> ((uint)piRam020380b4 & 3) * 8 |
                 *(uint *)((uint)piRam020380b4 & 0xfffffffc) <<
                 ((uint)piRam020380b4 & 3) * -8 + 0x20) + 0x1c) != 0) {
    func_0214922c();
  }
  if (*(short *)((*(uint *)((uint)piRam020380b4 & 0xfffffffc) >> ((uint)piRam020380b4 & 3) * 8 |
                 *(uint *)((uint)piRam020380b4 & 0xfffffffc) <<
                 ((uint)piRam020380b4 & 3) * -8 + 0x20) + 0x1e) != 0) {
    func_021491b0();
  }
  if (*(short *)((*(uint *)((uint)piRam020380b4 & 0xfffffffc) >> ((uint)piRam020380b4 & 3) * 8 |
                 *(uint *)((uint)piRam020380b4 & 0xfffffffc) <<
                 ((uint)piRam020380b4 & 3) * -8 + 0x20) + 0x20) != 0) {
    GX_SetBankForSubBGExtPltt();
  }
  if (*(short *)((*(uint *)((uint)piRam020380b4 & 0xfffffffc) >> ((uint)piRam020380b4 & 3) * 8 |
                 *(uint *)((uint)piRam020380b4 & 0xfffffffc) <<
                 ((uint)piRam020380b4 & 3) * -8 + 0x20) + 0x22) != 0) {
    GX_SetBankForSubOBJExtPltt();
  }
  if (*(short *)((*(uint *)((uint)piRam020380b4 & 0xfffffffc) >> ((uint)piRam020380b4 & 3) * 8 |
                 *(uint *)((uint)piRam020380b4 & 0xfffffffc) <<
                 ((uint)piRam020380b4 & 3) * -8 + 0x20) + 0x24) != 0) {
    func_02039b94();
  }
  if (*(short *)((*(uint *)((uint)piRam020380b4 & 0xfffffffc) >> ((uint)piRam020380b4 & 3) * 8 |
                 *(uint *)((uint)piRam020380b4 & 0xfffffffc) <<
                 ((uint)piRam020380b4 & 3) * -8 + 0x20) + 0x26) != 0) {
    GX_SetBankForLCDC();
  }
  ConfigureDispcntDisplay
            (*(undefined2 *)(param_1 + 6),*(undefined2 *)(param_1 + 8),*(undefined2 *)(param_1 + 10)
             ,*(uint *)(uRam020380c0 & 0xfffffffc) >> (uRam020380c0 & 3) * 8 |
              *(uint *)(uRam020380c0 & 0xfffffffc) << (uRam020380c0 & 3) * -8 + 0x20);
  _DAT_04000000 = _DAT_04000000 & 0xffffe0ff | (uint)*(ushort *)(param_1 + 2) << 8;
  SetDispcntSubBgMode(*(undefined2 *)(param_1 + 0xc));
  *puRam020380c4 =
       (*(uint *)((uint)puRam020380c4 & 0xfffffffc) >> ((uint)puRam020380c4 & 3) * 8 |
       *(uint *)((uint)puRam020380c4 & 0xfffffffc) << ((uint)puRam020380c4 & 3) * -8 + 0x20) &
       0xffffe0ff | (uint)*(ushort *)(param_1 + 4) << 8;
  if (*(short *)(param_1 + 10) == 1) {
    G3X_Initialize();
    G3X_InitializeTable();
    G3X_InitializeMatrixStack();
    puVar3 = puRam020380d0;
    puVar2 = puRam020380c8;
    *puRam020380c8 = *puRam020380c8 & (ushort)uRam020380cc;
    puVar1 = puRam020380d8;
    puVar4 = puRam020380d4;
    *puVar2 = *puVar2 & 0xcfff | 0x10;
    uVar5 = uRam020380dc;
    *puVar2 = *puVar2 & 0xcfff | 4;
    *puVar3 = 0;
    *puVar2 = *puVar2 & 0xcfff | 8;
    *puVar4 = 0;
    uVar8 = param_1 + 0x6cU & 3;
    uVar7 = *(uint *)(param_1 + 0x6cU & 0xfffffffc);
    uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
    *puVar1 = (uint)*(byte *)(uVar8 + 2) | (uint)*(byte *)(uVar8 + 3) << 1;
    uVar8 = param_1 + 0x6cU & 3;
    uVar7 = *(uint *)(param_1 + 0x6cU & 0xfffffffc);
    uVar8 = (uint)*(ushort *)(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20);
    G3X_SetClearColor(uVar5 & uVar8,(int)(uVar8 & 0x8000) >> 0xf,uVar5,0x3f,0);
  }
  puVar2 = puRam020380e0;
  if ((*(ushort *)(param_1 + 2) & 1) != 0) {
    *puRam020380e0 = *puRam020380e0 & 0xfffc | *(ushort *)(param_1 + 0x28);
    if (*(short *)(param_1 + 0x2a) == 0) {
      *puVar2 = *puVar2 & 0xffbf;
    }
    else {
      *puVar2 = *puVar2 | 0x40;
    }
    if (*(short *)(param_1 + 10) == 1) {
      G3X_SetHOffset(0);
    }
    else {
      *puRam020380e4 = 0;
      *puRam020380e0 =
           *puRam020380e0 & 0x43 | *(short *)(param_1 + 0x2c) << 0xe |
           *(short *)(param_1 + 0x2e) << 7 | *(short *)(param_1 + 0x30) << 8 |
           *(short *)(param_1 + 0x32) << 2 | *(short *)(param_1 + 0x34) << 0xd;
    }
  }
  if ((*(ushort *)(param_1 + 4) & 1) != 0) {
    *puRam020380e8 = 0;
    puVar2 = puRam020380ec;
    *puRam020380ec = *puRam020380ec & 0xfffc | *(ushort *)(param_1 + 0x70);
    puVar6 = puRam020380ec;
    if (*(short *)(param_1 + 0x72) == 0) {
      *puVar2 = *puVar2 & 0xffbf;
    }
    else {
      *puVar2 = *puVar2 | 0x40;
    }
    *puVar6 = *puVar6 & 0x43 | *(short *)(param_1 + 0x74) << 0xe | *(short *)(param_1 + 0x76) << 7 |
              *(short *)(param_1 + 0x78) << 8 | *(short *)(param_1 + 0x7a) << 2 |
              *(short *)(param_1 + 0x7c) << 0xd;
  }
  if ((*(ushort *)(param_1 + 2) & 2) != 0) {
    *puRam020380f0 = 0;
    puVar2 = puRam020380f4;
    *puRam020380f4 = *puRam020380f4 & 0xfffc | *(ushort *)(param_1 + 0x38);
    puVar6 = puRam020380f4;
    if (*(short *)(param_1 + 0x3a) == 0) {
      *puVar2 = *puVar2 & 0xffbf;
    }
    else {
      *puVar2 = *puVar2 | 0x40;
    }
    *puVar6 = *puVar6 & 0x43 | *(short *)(param_1 + 0x3c) << 0xe | *(short *)(param_1 + 0x3e) << 7 |
              *(short *)(param_1 + 0x40) << 8 | *(short *)(param_1 + 0x42) << 2 |
              *(short *)(param_1 + 0x44) << 0xd;
  }
  if ((*(ushort *)(param_1 + 4) & 2) != 0) {
    *puRam020380f8 = 0;
    puVar2 = puRam020380fc;
    *puRam020380fc = *puRam020380fc & 0xfffc | *(ushort *)(param_1 + 0x80);
    puVar6 = puRam020380fc;
    if (*(short *)(param_1 + 0x82) == 0) {
      *puVar2 = *puVar2 & 0xffbf;
    }
    else {
      *puVar2 = *puVar2 | 0x40;
    }
    *puVar6 = *puVar6 & 0x43 | *(short *)(param_1 + 0x84) << 0xe | *(short *)(param_1 + 0x86) << 7 |
              *(short *)(param_1 + 0x88) << 8 | *(short *)(param_1 + 0x8a) << 2 |
              *(short *)(param_1 + 0x8c) << 0xd;
  }
  if ((*(ushort *)(param_1 + 2) & 4) != 0) {
    SetGlobalDisplayConfig_Bg2(param_1 + 0x48,1);
  }
  if ((*(ushort *)(param_1 + 4) & 4) != 0) {
    SetGlobalDisplayConfig_Bg2(param_1 + 0x90,0);
  }
  if ((*(ushort *)(param_1 + 2) & 8) != 0) {
    SetGlobalDisplayConfig_Bg3(param_1 + 0x58,1);
  }
  if ((*(ushort *)(param_1 + 4) & 8) != 0) {
    SetGlobalDisplayConfig_Bg3(param_1 + 0xa0,0);
  }
  puVar1 = puRam020380c4;
  if ((*(ushort *)(param_1 + 2) & 0x10) != 0) {
    _DAT_04000000 =
         (_DAT_04000000 & uRam02038100 | (uint)*(ushort *)(param_1 + 0x68)) & uRam02038104 |
         (uint)*(ushort *)(param_1 + 0x6a);
  }
  if ((*(ushort *)(param_1 + 4) & 0x10) != 0) {
    *puRam020380c4 =
         (*(uint *)((uint)puRam020380c4 & 0xfffffffc) >> ((uint)puRam020380c4 & 3) * 8 |
         *(uint *)((uint)puRam020380c4 & 0xfffffffc) << ((uint)puRam020380c4 & 3) * -8 + 0x20) &
         uRam02038100 | (uint)*(ushort *)(param_1 + 0xb0);
    *puVar1 = (*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
              *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) & 0xffffff9f |
              (uint)*(ushort *)(param_1 + 0xb2);
  }
  *puRam02038108 = *puRam02038108 | 0x8000;
  return;
}

