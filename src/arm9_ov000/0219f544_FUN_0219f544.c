/* Decompiled C draft; module arm9_ov000; ROM address 0219f544. No matching claim. */
#include "types.h"
#include "deps/0219f544_FUN_0219f544.h"

void FUN_0219f544(undefined4 param_1)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  undefined4 uVar8;
  undefined4 local_24;
  uint local_20;
  uint local_1c;
  undefined4 local_18;
  
  iVar3 = DAT_0219f880;
  piVar2 = DAT_0219f87c;
  uVar8 = 3;
  bVar1 = false;
  switch(param_1) {
  case 0:
    iVar6 = *DAT_0219f87c;
    if ((int)(uint)*(byte *)(iVar6 + DAT_0219f880) < (int)(*(byte *)(iVar6 + 0xd) - 1)) {
      *(undefined4 *)(iVar6 + DAT_0219f884) = 0xd;
      iVar6 = *piVar2;
      pbVar4 = (byte *)(iVar6 + iVar3);
      local_24 = *(undefined4 *)(iVar6 + (*pbVar4 + 1) * 4 + 0xf4);
      local_20 = *pbVar4 + 1;
      local_1c = (uint)*(byte *)(iVar6 + *pbVar4 + 1 + DAT_0219f888);
      local_18 = *(undefined4 *)(iVar6 + (*pbVar4 + 1) * 4 + 0x24);
      uVar8 = 5;
    }
    else {
      *(undefined1 *)(iVar6 + 0x17) = 0;
      *(undefined4 *)(*piVar2 + 0x20) = 0;
      FUN_021a4818(*(undefined4 *)(*piVar2 + 0x10));
      iVar3 = *DAT_0219f87c;
      if (*(char *)(iVar3 + 0x15) == '\0') {
        *(undefined4 *)(iVar3 + DAT_0219f884) = 3;
      }
      else if (*(char *)(iVar3 + 0x15) == '\x01') {
        *(undefined4 *)(iVar3 + DAT_0219f884) = 4;
      }
      else {
        *(undefined4 *)(iVar3 + DAT_0219f884) = 10;
      }
      piVar2 = DAT_0219f87c;
      *(undefined1 *)(*DAT_0219f87c + DAT_0219f880) = 0;
      iVar3 = *piVar2;
      if ((*(char *)(iVar3 + 0x15) == '\x02') || (*(char *)(iVar3 + 0xd) == *(char *)(iVar3 + 0x16))
         ) {
        if (*(char *)(iVar3 + 0x15) == '\x02') {
          iVar3 = *DAT_0219f87c;
          *(undefined4 *)(iVar3 + DAT_0219f88c) =
               *(undefined4 *)(iVar3 + (uint)*(byte *)(iVar3 + 0xd) * 4 + 0xf4);
        }
        else {
          *(undefined4 *)(iVar3 + DAT_0219f88c) = 0;
          *(undefined4 *)(*DAT_0219f87c + 0xf4) = *(undefined4 *)(*DAT_0219f87c + DAT_0219f890);
        }
        piVar2 = DAT_0219f87c;
        *(undefined4 *)(*DAT_0219f87c + DAT_0219f884) = 0x10;
        *(undefined4 *)(*piVar2 + DAT_0219f894) = 0;
        iVar3 = DAT_0219f888;
        iVar5 = 1;
        iVar6 = *piVar2;
        if (*(char *)(iVar6 + 0xd) != '\0') {
          do {
            FUN_0219ef68(*(undefined1 *)(iVar6 + iVar5 + iVar3),2);
            iVar5 = iVar5 + 1;
            iVar6 = *piVar2;
          } while (iVar5 <= (int)(uint)*(byte *)(iVar6 + 0xd));
        }
      }
      else {
        local_24 = 0;
        local_20 = (uint)*(byte *)(iVar3 + 0xd);
        local_1c = (uint)*(byte *)(iVar3 + (uint)*(byte *)(iVar3 + 0xd) + DAT_0219f888);
        if (*(char *)(iVar3 + 0x15) == '\0') {
          *(undefined4 *)(iVar3 + 0xe8) = 2;
          uVar7 = func_0x0200f5ac();
          *(undefined8 *)(*DAT_0219f87c + 0xec) = uVar7;
        }
        else if (*(char *)(iVar3 + 0x15) == '\x01') {
          FUN_0219fbec(1);
        }
      }
      iVar6 = *DAT_0219f87c;
      if (*(char *)(iVar6 + 0x15) != '\x02') {
        bVar1 = true;
      }
    }
    if (*(int *)(iVar6 + DAT_0219f884) != 0x10) {
      iVar6 = *DAT_0219f87c;
      iVar3 = iVar6 + (uint)*(byte *)(iVar6 + 0xd) * 4;
      FUN_021a0ae8(8,*(undefined4 *)(iVar3 + 0xf4),*(undefined4 *)(iVar3 + 0x24),
                   *(undefined2 *)(iVar6 + (uint)*(byte *)(iVar6 + 0xd) * 2 + 0xa4),&local_24,uVar8)
      ;
      iVar3 = FUN_0219fee4();
      if (iVar3 != 0) {
        return;
      }
      *(undefined1 *)(*DAT_0219f87c + DAT_0219f898) = 0;
    }
    break;
  case 1:
    *(undefined4 *)(*DAT_0219f87c + DAT_0219f884) = 1;
    iVar3 = *piVar2;
    if (*(char *)(iVar3 + 0x15) == '\x03') {
      *(undefined4 *)(iVar3 + DAT_0219f88c) =
           *(undefined4 *)(iVar3 + (uint)*(byte *)(iVar3 + 0xd) * 4 + 0xf4);
    }
    bVar1 = true;
    break;
  case 2:
    *(undefined4 *)(*DAT_0219f87c + DAT_0219f884) = 1;
    iVar3 = *piVar2;
    if ((*(char *)(iVar3 + 0x15) == '\0') || (*(char *)(iVar3 + 0x15) == '\x01')) {
      *(undefined1 *)(iVar3 + 0x17) = 1;
      *(undefined4 *)(*DAT_0219f87c + 0x20) = *(undefined4 *)(*DAT_0219f87c + DAT_0219f890);
    }
    iVar3 = *DAT_0219f87c;
    if (1 < *(byte *)(iVar3 + 0xd)) {
      FUN_021a0ae8(9,*(undefined4 *)(iVar3 + 0xf4),*(undefined4 *)(iVar3 + 0x24),
                   *(undefined2 *)(iVar3 + 0xa4),iVar3 + 0xf4 + (*(byte *)(iVar3 + 0xd) - 1) * 4,1,3
                  );
      iVar3 = FUN_0219fee4();
      if (iVar3 != 0) {
        return;
      }
    }
    break;
  case 3:
    *(undefined4 *)(*DAT_0219f87c + DAT_0219f884) = 1;
    *(undefined4 *)(*piVar2 + DAT_0219f88c) = 0;
    bVar1 = true;
    break;
  case 4:
    if (*(char *)(*DAT_0219f87c + 0x15) != '\x02') {
      FUN_0219d558(2,DAT_0219f89c,0);
    }
    iVar6 = *DAT_0219f87c;
    iVar3 = *(int *)(iVar6 + DAT_0219f88c);
    uVar8 = FUN_0219d5e4();
    (**(code **)(*DAT_0219f87c + DAT_0219f8a4))
              (0,0,iVar3 == 0,0,uVar8,*(undefined4 *)(iVar6 + DAT_0219f8a0));
    iVar3 = *DAT_0219f87c;
    if ((*(char *)(iVar3 + 0x15) == '\0') || (*(char *)(iVar3 + 0x15) == '\x01')) {
      FUN_021a104c();
    }
    else {
      if (*(int *)(iVar3 + 0xe4) != 0) {
        FUN_0218b64c();
        *(undefined4 *)(*DAT_0219f87c + 0xe4) = 0;
      }
      FUN_0219b110();
      if (*(char *)(*DAT_0219f87c + 0x15) == '\x02') {
        FUN_021a1488();
        iVar3 = FUN_0219e608();
        if (iVar3 != 0) {
          return;
        }
        if (*DAT_0219f8a8 == '\x01') {
          DAT_0219f8a8[1] = '\x01';
        }
        *(undefined4 *)(*DAT_0219f87c + DAT_0219f884) = 10;
      }
      else {
        *(undefined4 *)(*DAT_0219f87c + DAT_0219f884) = 1;
      }
      *(undefined4 *)(*DAT_0219f87c + DAT_0219f88c) = 0;
    }
    *(undefined1 *)(*DAT_0219f87c + DAT_0219f8ac) = 0;
  }
  if ((bVar1) && (*(char *)(*DAT_0219f87c + 0x15) != '\x03')) {
    FUN_0218b48c(*(undefined4 *)(*DAT_0219f87c + 0xe4));
  }
  return;
}

