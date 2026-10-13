/* Decompiled C draft; module arm9; ROM address 02142c98. No matching claim. */
#include "types.h"
#include "deps/02142c98_Wm_InitializeImpl.h"

undefined4 Wm_InitializeImpl(int *param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  ushort *puVar2;
  uint *puVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined2 *puVar8;
  
  puVar2 = puRam02142e60;
  if (*puRam02142e60 != 0) {
    return 3;
  }
  *puRam02142e60 = 1;
  if (param_1 == (int *)0x0) {
    *puVar2 = (ushort)(param_1 != (int *)0x0);
    return 6;
  }
  if (3 < param_2) {
    *puVar2 = 0;
    return 6;
  }
  if (((uint)param_1 & 0x1f) == 0) {
    func_0214d5b8(0);
    iVar5 = Fifo_IsHandlerReady(10,1);
    if (iVar5 != 0) {
      DC_InvalidateRangeNoClean((uint)(uintptr_t)(param_1),param_3);
      Mem_DmaFill32(param_2,(undefined4)(uintptr_t)(param_1),0,param_3);
      puVar3 = puRam02142e64;
      *puRam02142e64 = (uint)param_1;
      *param_1 = (int)(param_1 + 0x80);
      uVar6 = *(uint *)((uint)puVar3 & 0xfffffffc) >> ((uint)puVar3 & 3) * 8 |
              *(uint *)((uint)puVar3 & 0xfffffffc) << ((uint)puVar3 & 3) * -8 + 0x20;
      *(uint *)(uVar6 + 4) =
           (*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
           *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x300;
      uVar7 = *(uint *)((uint)puVar3 & 0xfffffffc) >> ((uint)puVar3 & 3) * 8 |
              *(uint *)((uint)puVar3 & 0xfffffffc) << ((uint)puVar3 & 3) * -8 + 0x20;
      uVar6 = uVar7 + 4;
      uVar1 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      *(uint *)(uVar7 + 0xc) = (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) + 0x800;
      uVar7 = *(uint *)((uint)puVar3 & 0xfffffffc) >> ((uint)puVar3 & 3) * 8 |
              *(uint *)((uint)puVar3 & 0xfffffffc) << ((uint)puVar3 & 3) * -8 + 0x20;
      uVar6 = uVar7 + 0xc;
      uVar1 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      *(uint *)(uVar7 + 0x10) = (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) + 0x100;
      Wm_DisableCallbackControl();
      uVar6 = 0;
      *(short *)((*(uint *)((uint)puRam02142e64 & 0xfffffffc) >> ((uint)puRam02142e64 & 3) * 8 |
                 *(uint *)((uint)puRam02142e64 & 0xfffffffc) <<
                 ((uint)puRam02142e64 & 3) * -8 + 0x20) + 0x14) = (short)param_2;
      do {
        func_0214358c(uVar6 & 0xffff,0,0);
        uVar6 = uVar6 + 1;
      } while ((int)uVar6 < 0x10);
      Os_MessageQueue_Initialize((uint *)(uintptr_t)(uRam02142e68),uRam02142e6c,10);
      uVar4 = uRam02142e68;
      iVar5 = 0;
      puVar8 = puRam02142e70;
      do {
        *puVar8 = 0x8000;
        DC_SomeClean((uint)(uintptr_t)(puVar8),2);
        Os_MessageQueue_Send(uVar4,(undefined4)(uintptr_t)(puVar8),1);
        iVar5 = iVar5 + 1;
        puVar8 = puVar8 + 0x80;
      } while (iVar5 < 10);
      Fifo_RegisterHandler(10,uRam02142e74);
      return 0;
    }
    *puRam02142e60 = 0;
    return 4;
  }
  *puVar2 = 0;
  return 6;
}

