/* Decompiled C draft; module arm9_ov001; ROM address 02182bdc. No matching claim. */
#include "types.h"
#include "deps/02182bdc_FUN_02182bdc.h"

void FUN_02182bdc(void)

{
  int iVar1;
  int iVar2;
  longlong *plVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  longlong lVar7;
  undefined8 uVar8;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  iVar1 = func_0x0207a974((short)*(char *)(*DAT_02182d14 + 0x62));
  func_0x02100138(0x68);
  iVar2 = func_0x0209bbfc();
  if (iVar2 != 0) {
    plVar3 = (longlong *)func_0x020d22d0();
    lVar7 = func_0x02133048((int)plVar3[1],*(undefined4 *)((int)plVar3 + 0xc),(int)*plVar3,
                            *(undefined4 *)((int)plVar3 + 4));
    *plVar3 = lVar7 + plVar3[2];
    uVar4 = *(uint *)((int)plVar3 + 4);
    plVar3 = (longlong *)func_0x020d22d0();
    lVar7 = func_0x02133048((int)plVar3[1],*(undefined4 *)((int)plVar3 + 0xc),(int)*plVar3,
                            *(undefined4 *)((int)plVar3 + 4));
    *plVar3 = lVar7 + plVar3[2];
    iVar5 = 0;
    iVar6 = (*(uint *)((int)plVar3 + 4) >> 0x15) + DAT_02182d18;
    *(undefined4 *)(iVar2 + 0xf8) = 5;
    *(undefined4 *)(iVar2 + 0xb0) = DAT_02182d1c;
    *(undefined2 *)(iVar2 + 0xa0) = 0x10;
    *(undefined4 *)(iVar2 + 0xac) = 0x1e;
    if (*(int *)(*DAT_02182d14 + 8) == 4) {
      FUN_02181b54();
      iVar5 = FUN_02181b68();
    }
    *(int *)(iVar2 + 0xe8) = iVar5 + 4;
    *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(iVar1 + 0x80);
    *(int *)(iVar2 + 8) = *(int *)(iVar1 + 0x84) + DAT_02182d20;
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar1 + 0x88);
    iVar1 = (int)(uVar4 >> 0x10) >> 4;
    iVar5 = (int)*(short *)(DAT_02182d24 + iVar1 * 4);
    uVar8 = func_0x02133048(iVar6,iVar6 >> 0x1f,iVar5,iVar5 >> 0x1f);
    *(uint *)(iVar2 + 0x10) = (uint)uVar8 >> 0xc | (int)((ulonglong)uVar8 >> 0x20) << 0x14;
    *(undefined4 *)(iVar2 + 0x14) = DAT_02182d28;
    iVar1 = (int)*(short *)(DAT_02182d24 + (iVar1 * 2 + 1) * 2);
    uVar8 = func_0x02133048(iVar6,iVar6 >> 0x1f,iVar1,iVar1 >> 0x1f);
    *(uint *)(iVar2 + 0x18) = (uint)uVar8 >> 0xc | (int)((ulonglong)uVar8 >> 0x20) << 0x14;
    local_24 = DAT_02182d2c;
    local_20 = 0;
    local_1c = 2;
    local_18 = func_0x020d4ef4();
    func_0x0210b7a8((uint)(uintptr_t)(&local_24));
  }
  return;
}

