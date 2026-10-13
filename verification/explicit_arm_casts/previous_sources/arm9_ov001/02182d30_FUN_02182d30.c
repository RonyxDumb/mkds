/* Decompiled C draft; module arm9_ov001; ROM address 02182d30. No matching claim. */
#include "types.h"
#include "deps/02182d30_FUN_02182d30.h"

void FUN_02182d30(void)

{
  int iVar1;
  int iVar2;
  longlong *plVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  longlong lVar8;
  undefined8 uVar9;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  iVar1 = func_0x0207a974((short)*(char *)(*DAT_02182e68 + 0x62));
  func_0x02100138(0x68);
  iVar2 = func_0x0209bbfc();
  if (iVar2 != 0) {
    plVar3 = (longlong *)func_0x020d22d0();
    lVar8 = func_0x02133048((int)plVar3[1],*(undefined4 *)((int)plVar3 + 0xc),(int)*plVar3,
                            *(undefined4 *)((int)plVar3 + 4));
    *plVar3 = lVar8 + plVar3[2];
    uVar4 = *(uint *)((int)plVar3 + 4);
    plVar3 = (longlong *)func_0x020d22d0();
    lVar8 = func_0x02133048((int)plVar3[1],*(undefined4 *)((int)plVar3 + 0xc),(int)*plVar3,
                            *(undefined4 *)((int)plVar3 + 4));
    *plVar3 = lVar8 + plVar3[2];
    iVar5 = (*(uint *)((int)plVar3 + 4) >> 0x15) + DAT_02182e6c;
    *(undefined4 *)(iVar2 + 0xf8) = 3;
    *(undefined4 *)(iVar2 + 0xb0) = DAT_02182e70;
    *(undefined2 *)(iVar2 + 0xa0) = 0x10;
    *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(iVar1 + 0x80);
    *(int *)(iVar2 + 8) = *(int *)(iVar1 + 0x84) + DAT_02182e74;
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar1 + 0x88);
    iVar6 = (int)(uVar4 >> 0x10) >> 4;
    iVar7 = (int)*(short *)(DAT_02182e78 + iVar6 * 4);
    uVar9 = func_0x02133048(iVar5,iVar5 >> 0x1f,iVar7,iVar7 >> 0x1f);
    *(uint *)(iVar2 + 0x10) =
         *(int *)(iVar1 + 0xa4) + ((uint)uVar9 >> 0xc | (int)((ulonglong)uVar9 >> 0x20) << 0x14);
    *(int *)(iVar2 + 0x14) = *(int *)(iVar1 + 0xa8) + DAT_02182e7c;
    iVar6 = (int)*(short *)(DAT_02182e78 + (iVar6 * 2 + 1) * 2);
    uVar9 = func_0x02133048(iVar5,iVar5 >> 0x1f,iVar6,iVar6 >> 0x1f);
    *(uint *)(iVar2 + 0x18) =
         *(int *)(iVar1 + 0xac) + ((uint)uVar9 >> 0xc | (int)((ulonglong)uVar9 >> 0x20) << 0x14);
    *(ushort *)(iVar2 + 2) = *(ushort *)(iVar2 + 2) & 0xfffe;
    local_24 = DAT_02182e80;
    local_20 = 0;
    local_1c = 2;
    local_18 = func_0x020d4ef4();
    func_0x0210b7a8(&local_24);
  }
  return;
}

