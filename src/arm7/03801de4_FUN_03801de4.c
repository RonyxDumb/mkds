/* Decompiled C draft; module arm7; ROM address 03801de4. No matching claim. */
#include "types.h"
#include "deps/03801de4_FUN_03801de4.h"

void FUN_03801de4(uint *param_1,int param_2,ushort *param_3)

{
  ushort *puVar1;
  undefined2 *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  ushort local_20;
  ushort local_1e;
  ushort local_1c [4];
  
  *param_3 = 0;
  if (param_2 < 0) {
    param_2 = -param_2;
  }
  iVar3 = FUN_0380222c();
  if (iVar3 == 0) {
    *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
               *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) &
               0xfffff000;
    *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
               *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) &
               DAT_03802018;
    *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
               *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) &
               0xfeffffff;
    *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
               *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) &
               0xf9ffffff | 0x6000000;
    *DAT_0380201c = 0;
  }
  else {
    uVar4 = FUN_03802034(&local_20,param_2,0,&local_1e);
    *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
               *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) &
               0xf9ffffff | (uVar4 & 3) << 0x19;
    *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
               *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) &
               0xfffff000 | DAT_03802020 & local_20;
    iVar5 = FUN_03802034(&local_20,param_2,1,local_1c);
    if (iVar5 == 2) {
      uVar4 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
              *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
      *param_1 = uVar4 & 0xf9ffffff | ((uVar4 << 5) >> 0x1e | 2) << 0x19;
    }
    *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
               *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) &
               DAT_03802018 | (DAT_03802020 & local_20) << 0xc;
    puVar1 = DAT_03802028;
    *DAT_03802028 = (ushort)DAT_03802024;
    puVar2 = DAT_0380202c;
    iVar5 = 0;
    do {
      *puVar2 = 0;
      do {
      } while ((*puVar1 & 0x80) != 0);
      iVar5 = iVar5 + 1;
    } while (iVar5 < 0xc);
    *puVar1 = (ushort)DAT_03802030;
    *DAT_0380202c = 0;
    do {
    } while ((*DAT_03802028 & 0x80) != 0);
    if (iVar3 == 2) {
      *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                 *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) &
                 0xf9ffffff | 0x6000000;
    }
    iVar3 = FUN_0380222c();
    if (iVar3 == 0) {
      *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                 *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) &
                 0xfeffffff;
      *DAT_0380201c = 0;
    }
    else if (iVar3 == 1) {
      *param_1 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                 *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20 |
                 0x1000000;
      *DAT_0380201c = 1;
      if (local_1e < local_1c[0]) {
        local_1e = local_1c[0];
      }
      *param_3 = local_1e;
    }
    else if (iVar3 == 2) {
      *param_1 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                 *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20 |
                 0x1000000;
      *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                 *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) &
                 0xf9ffffff | 0x6000000;
      *DAT_0380201c = 0;
    }
    else {
      FUN_037fb000();
    }
  }
  return;
}

