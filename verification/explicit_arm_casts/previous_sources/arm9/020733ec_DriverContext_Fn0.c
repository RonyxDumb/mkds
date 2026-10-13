/* Decompiled C draft; module arm9; ROM address 020733ec. No matching claim. */
#include "types.h"
#include "deps/020733ec_DriverContext_Fn0.h"

void DriverContext_Fn0(int param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  
  GetActiveExecutionContext();
  uVar2 = ExecutionContext_GetHeapHandle();
  *(undefined4 *)(param_1 + 0x230) = uRam02073624;
  DriverContext_PrepareCharacterKartPhysicalParams(param_1);
  DriverContext_SetDriverFlags(param_1);
  uVar6 = param_1 + 0x7cU & 3;
  uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) & 0x10) != 0) {
    uVar6 = param_1 + 0x2ccU & 3;
    uVar3 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
    uVar6 = (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) + 0x10;
    uVar3 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    FX_Div(0x1000,uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20);
    func_0207a73c();
  }
  DriverContext_InitializeSfx(param_1);
  AllocateNewDriverSub208(param_1 + 0x208);
  uVar4 = Mem_AllocateHeap(uVar2,0x158);
  uVar3 = uRam02073628;
  *(undefined4 *)(param_1 + 0x310) = uVar4;
  uVar6 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar6 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
  if ((((*(short *)(uVar6 + 0x70) != 0) || (*(short *)(uVar6 + 0x90) != 0)) &&
      (uVar6 = (uint)*(ushort *)(param_1 + 0x74) * 0x30 +
               (*(uint *)(uRam0207362c & 0xfffffffc) >> (uRam0207362c & 3) * 8 |
               *(uint *)(uRam0207362c & 0xfffffffc) << (uRam0207362c & 3) * -8 + 0x20) + 0x70,
      uVar3 = uVar6 & 3, uVar6 = *(uint *)(uVar6 & 0xfffffffc),
      (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) == 1)) &&
     (uVar6 = param_1 + 0x7cU & 3, uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc),
     *(uint *)(param_1 + 0x7c) = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20 | 2,
     uVar6 = param_1 + 0x7cU & 3, uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc),
     ((uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) & 2) != 0)) {
    uVar6 = 0;
    do {
      if (uVar6 != 0) {
        uVar3 = param_1 + 0x2ccU & 3;
        uVar5 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
        iVar7 = (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) + uVar6 * 4;
        uVar3 = iVar7 + 0x38;
        uVar5 = uVar3 & 3;
        uVar3 = *(uint *)(uVar3 & 0xfffffffc);
        *(uint *)(iVar7 + 0x38) = (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) << 2;
        uVar3 = param_1 + 0x2ccU & 3;
        uVar5 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
        uVar3 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
        iVar7 = uVar3 + uVar6 * 4;
        uVar3 = uVar3 + 0x38;
        uVar5 = uVar3 & 3;
        uVar3 = *(uint *)(uVar3 & 0xfffffffc);
        uVar8 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
        uVar3 = iVar7 + 0x38;
        uVar5 = uVar3 & 3;
        uVar3 = *(uint *)(uVar3 & 0xfffffffc);
        if ((int)uVar8 < (int)(uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20)) {
          *(uint *)(iVar7 + 0x38) = uVar8;
        }
      }
      uVar6 = uVar6 + 1 & 0xffff;
    } while (uVar6 < 0xc);
  }
  *(undefined2 *)(param_1 + 0x2ca) = 0xffff;
  uVar3 = uRam0207362c;
  *(undefined2 *)(param_1 + 0x2c8) = *(undefined2 *)(param_1 + 0x2ca);
  uVar6 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar6 = (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) + 8;
  uVar3 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  if ((uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) == 5) {
    iVar7 = param_1 + 0x1d8;
  }
  else {
    iVar7 = param_1 + 0x1b8;
  }
  if (*(short *)(param_1 + 0x2c8) == -1) {
    uVar6 = param_1 + 0x2ccU & 3;
    uVar3 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
    uVar3 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
    uVar6 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    uVar1 = FindComputeSomeCollisionEntryId
                      (iVar7,(uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) + 0xd000,0x8000,
                       param_1);
    *(undefined2 *)(param_1 + 0x2c8) = uVar1;
  }
  if (*(short *)(param_1 + 0x2ca) == -1) {
    uVar6 = param_1 + 0x2ccU & 3;
    uVar3 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
    uVar3 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
    uVar6 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    uVar6 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
    uVar1 = FindComputeSomeCollisionEntryId
                      (param_1 + 0x1f0,(uVar6 << 0xf) >> 0xc | (uVar6 >> 0x11) << 0x14,0x800,param_1
                      );
    *(undefined2 *)(param_1 + 0x2ca) = uVar1;
  }
  uVar6 = param_1 + 0x44U & 3;
  uVar3 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  *(uint *)(param_1 + 0x44) = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20 | 0x10;
  *(undefined4 *)(param_1 + 0x4d0) = 100;
  uVar6 = param_1 + 0x2ccU & 3;
  uVar3 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
  uVar3 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
  uVar6 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  *(uint *)(param_1 + 0x1d0) = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
  DriverContext_CreateSub450_2(param_1);
  uVar6 = (*(uint *)(uRam0207362c & 0xfffffffc) >> (uRam0207362c & 3) * 8 |
          *(uint *)(uRam0207362c & 0xfffffffc) << (uRam0207362c & 3) * -8 + 0x20) + 8;
  uVar3 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  if ((uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) == 5) {
    uVar4 = Mem_AllocateHeap(uVar2,0xb8);
    *(undefined4 *)(param_1 + 0x514) = uVar4;
    DriverContext_CreateNetworkState(param_1,uVar2);
  }
  iVar7 = IsAwardOrStaffRoll_0();
  if (iVar7 != 0) {
    uVar6 = param_1 + 0x44U & 3;
    uVar3 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    *(uint *)(param_1 + 0x44) = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20 | 0x1000000;
  }
  return;
}

