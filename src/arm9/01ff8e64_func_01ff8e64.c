/* Decompiled C draft; module arm9; ROM address 01ff8e64. No matching claim. */
#include "types.h"
#include "deps/01ff8e64_func_01ff8e64.h"

void func_01ff8e64(uint *param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar6;
  code *pcVar7;
  uint uVar5;
  
  Mem_CpuFastMemorySet(0,param_1,0x188);
  param_1[0x31] = 1;
  param_1[2] = 1;
  iVar1 = iRam01ff8fec;
  uVar5 = (uint)(param_2 + 0xc) & 3;
  uVar4 = *(uint *)((uint)(param_2 + 0xc) & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  if (uVar5 == 0) {
    uVar5 = (uint)(param_2 + 1) & 3;
    uVar4 = *(uint *)((uint)(param_2 + 1) & 0xfffffffc);
    uVar6 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
    uVar5 = uVar6 + 4;
    uVar4 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    *param_1 = uVar6 + (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20);
  }
  else {
    *param_1 = uVar5;
  }
  param_1[1] = (uint)param_2;
  iVar2 = iRam01ff8ff0;
  uVar5 = (uint)(param_2 + 1) & 3;
  uVar4 = *(uint *)((uint)(param_2 + 1) & 0xfffffffc);
  param_1[0x35] = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x40;
  iVar3 = iRam01ff8ff4;
  uVar5 = (uint)(param_2 + 1) & 3;
  uVar4 = *(uint *)((uint)(param_2 + 1) & 0xfffffffc);
  uVar6 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar5 = uVar6 + 8;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  param_1[0x36] = uVar6 + (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20);
  uVar5 = (uint)(param_2 + 1) & 3;
  uVar4 = *(uint *)((uint)(param_2 + 1) & 0xfffffffc);
  uVar6 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar5 = uVar6 + 0xc;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  param_1[0x37] = uVar6 + (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20);
  uVar5 = (uint)(param_2 + 1) & 3;
  uVar4 = *(uint *)((uint)(param_2 + 1) & 0xfffffffc);
  uVar5 = iVar1 + (uint)*(byte *)((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x15) * 4;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  param_1[0x3a] = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  uVar5 = (uint)(param_2 + 1) & 3;
  uVar4 = *(uint *)((uint)(param_2 + 1) & 0xfffffffc);
  uVar5 = iVar2 + (uint)*(byte *)((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x15) * 4;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  param_1[0x3b] = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  uVar5 = (uint)(param_2 + 1) & 3;
  uVar4 = *(uint *)((uint)(param_2 + 1) & 0xfffffffc);
  uVar5 = iVar3 + (uint)*(byte *)((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x16) * 4;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  param_1[0x3c] = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  uVar5 = (uint)(param_2 + 1) & 3;
  uVar4 = *(uint *)((uint)(param_2 + 1) & 0xfffffffc);
  uVar5 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x1c;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  param_1[0x38] = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  uVar5 = (uint)(param_2 + 1) & 3;
  uVar4 = *(uint *)((uint)(param_2 + 1) & 0xfffffffc);
  uVar5 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x20;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  param_1[0x39] = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  uVar5 = (uint)(param_2 + 8) & 3;
  uVar4 = *(uint *)((uint)(param_2 + 8) & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  if ((uVar5 != 0) && ((byte)param_2[9] < 0x20)) {
    param_1[(byte)param_2[9] + 3] = uVar5;
    *(undefined1 *)((int)param_1 + (byte)param_2[9] + 0x8c) = *(undefined1 *)((int)param_2 + 0x25);
  }
  if (((*(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
       *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20) & 1) != 0) {
    uVar5 = (uint)(param_1 + 2) & 3;
    uVar4 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
    param_1[2] = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20 | 0x80;
  }
  if (((*(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
       *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20) & 2) != 0) {
    uVar5 = (uint)(param_1 + 2) & 3;
    uVar4 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
    param_1[2] = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20 | 0x100;
  }
  if (((*(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
       *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20) & 4) != 0) {
    uVar5 = (uint)(param_1 + 2) & 3;
    uVar4 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
    param_1[2] = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20 | 0x200;
  }
  if (((*(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
       *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20) & 8) != 0) {
    uVar5 = (uint)(param_1 + 2) & 3;
    uVar4 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
    param_1[2] = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20 | 0x400;
  }
  uVar5 = (uint)(param_2 + 10) & 3;
  uVar4 = *(uint *)((uint)(param_2 + 10) & 0xfffffffc);
  pcVar7 = (code *)(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20);
  if (pcVar7 != (code *)0x0) {
    (*pcVar7)(param_1);
  }
  func_01ff8ff8((uint)(uintptr_t)(param_1));
  *param_2 = (*(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
             *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20) & 0xfffffffe;
  return;
}

