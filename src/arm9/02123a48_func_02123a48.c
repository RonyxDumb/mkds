/* Decompiled C draft; module arm9; ROM address 02123a48. No matching claim. */
#include "types.h"
#include "deps/02123a48_func_02123a48.h"

void func_02123a48(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  WriteSaveFriendCodes();
  uVar1 = DAT_02124080;
  switch(param_1) {
  case 0:
    Mem_CpuFill8((uint *)(uintptr_t)((*(uint *)(DAT_02124080 & 0xfffffffc) >> (DAT_02124080 & 3) * 8 |
                 *(uint *)(DAT_02124080 & 0xfffffffc) << (DAT_02124080 & 3) * -8 + 0x20) +
                 DAT_02124084),0,0x60);
    Mem_CpuFill8((uint *)(uintptr_t)((*(uint *)(DAT_02124080 & 0xfffffffc) >> (DAT_02124080 & 3) * 8 |
                 *(uint *)(DAT_02124080 & 0xfffffffc) << (DAT_02124080 & 3) * -8 + 0x20) +
                 DAT_02124088),0,0x110);
    Mem_CpuFill8((uint *)(uintptr_t)((*(uint *)(DAT_02124080 & 0xfffffffc) >> (DAT_02124080 & 3) * 8 |
                 *(uint *)(DAT_02124080 & 0xfffffffc) << (DAT_02124080 & 3) * -8 + 0x20) + 0x1d00),0,
                 0x110);
    uVar1 = DAT_02124080;
    uVar3 = 0;
    uVar6 = *(uint *)(DAT_02124080 & 0xfffffffc) >> (DAT_02124080 & 3) * 8 |
            *(uint *)(DAT_02124080 & 0xfffffffc) << (DAT_02124080 & 3) * -8 + 0x20;
    if (*(char *)(uVar6 + 0x1f53) != '\0') {
      do {
        uVar6 = func_0x0219bb50();
        if (uVar3 == uVar6) {
          uVar5 = *(uint *)(DAT_0212408c & 0xfffffffc) >> (DAT_0212408c & 3) * 8 |
                  *(uint *)(DAT_0212408c & 0xfffffffc) << (DAT_0212408c & 3) * -8 + 0x20;
          uVar6 = uVar5 & 3;
          uVar5 = *(uint *)(uVar5 & 0xfffffffc);
          uVar6 = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0x44;
          uVar5 = uVar6 & 3;
          uVar6 = *(uint *)(uVar6 & 0xfffffffc);
          *(uint *)((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + uVar3 * 0x244 +
                   0x454) = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
          uVar5 = *(uint *)(DAT_0212408c & 0xfffffffc) >> (DAT_0212408c & 3) * 8 |
                  *(uint *)(DAT_0212408c & 0xfffffffc) << (DAT_0212408c & 3) * -8 + 0x20;
          uVar6 = uVar5 & 3;
          uVar5 = *(uint *)(uVar5 & 0xfffffffc);
          uVar6 = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0x48;
          uVar5 = uVar6 & 3;
          uVar6 = *(uint *)(uVar6 & 0xfffffffc);
          *(uint *)((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + uVar3 * 0x244 +
                   0x458) = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
          iVar4 = GetGlobalCA_from_thumb();
          *(undefined4 *)(uVar3 * 0x18 + iVar4 + 8) = 0;
        }
        else {
          func_0x021a3264(uVar3,uVar3 * 0x244 +
                                (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                                *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x21c,
                          0x244);
          iVar4 = GetGlobalCA_from_thumb();
          *(undefined4 *)(uVar3 * 0x18 + iVar4 + 8) = 3;
        }
        iVar4 = GetGlobalCA_from_thumb();
        *(undefined4 *)(iVar4 + uVar3 * 0x18) = 0xffffffff;
        iVar4 = GetGlobalCA_from_thumb();
        *(undefined4 *)(iVar4 + uVar3 * 0x18 + 4) = 0xffffffff;
        iVar4 = GetGlobalCA_from_thumb();
        *(undefined4 *)(iVar4 + 0xd0) = 0;
        iVar4 = uVar3 * 0x44;
        *(undefined4 *)
         ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + iVar4 + 0x1e40) = 0xffffffff;
        uVar3 = uVar3 + 1 & 0xff;
        *(undefined4 *)
         ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + iVar4 + 0x1e44) = 0xffffffff;
        *(undefined4 *)
         ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + iVar4 + 0x1e48) = 0;
        *(undefined4 *)
         ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + iVar4 + 0x1d30) = 0xffffffff;
        *(undefined4 *)
         ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + iVar4 + 0x1d34) = 0xffffffff;
        *(undefined4 *)
         ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + iVar4 + 0x1d38) = 0;
        uVar6 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
      } while (uVar3 < *(byte *)(uVar6 + 0x1f53));
    }
    *(undefined4 *)(uVar6 + 0x1980) = 0;
    uVar2 = DAT_02124090;
    uVar6 = DAT_02124080;
    *(undefined1 *)
     ((*(uint *)(DAT_02124080 & 0xfffffffc) >> (DAT_02124080 & 3) * 8 |
      *(uint *)(DAT_02124080 & 0xfffffffc) << (DAT_02124080 & 3) * -8 + 0x20) + 0x19aa) = 0;
    uVar1 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    *(undefined1 *)((uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) + 0x19ab) = 0;
    func_0x021a323c(uVar2);
    iVar4 = func_0x0219bb50();
    uVar2 = Os_GetTick();
    *(undefined4 *)
     (iVar4 * 0x244 +
      (*(uint *)(DAT_02124080 & 0xfffffffc) >> (DAT_02124080 & 3) * 8 |
      *(uint *)(DAT_02124080 & 0xfffffffc) << (DAT_02124080 & 3) * -8 + 0x20) + 0x45c) = uVar2;
    func_02122684();
    *(undefined4 *)
     ((*(uint *)(DAT_02124080 & 0xfffffffc) >> (DAT_02124080 & 3) * 8 |
      *(uint *)(DAT_02124080 & 0xfffffffc) << (DAT_02124080 & 3) * -8 + 0x20) + 0x1950) = 0;
    iVar4 = func_0x0219bb50();
    SetGlobalCA81_from_thumb
              (*(undefined1 *)
                ((*(uint *)(DAT_02124080 & 0xfffffffc) >> (DAT_02124080 & 3) * 8 |
                 *(uint *)(DAT_02124080 & 0xfffffffc) << (DAT_02124080 & 3) * -8 + 0x20) + iVar4 +
                0x1f4e));
    SetGlobalCA82_from_thumb
              (*(undefined1 *)
                ((*(uint *)(DAT_02124080 & 0xfffffffc) >> (DAT_02124080 & 3) * 8 |
                 *(uint *)(DAT_02124080 & 0xfffffffc) << (DAT_02124080 & 3) * -8 + 0x20) + 0x1f53));
    return;
  case 1:
    func_02122684();
    uVar1 = DAT_02124080;
    uVar6 = 0;
    *(undefined1 *)
     ((*(uint *)(DAT_02124080 & 0xfffffffc) >> (DAT_02124080 & 3) * 8 |
      *(uint *)(DAT_02124080 & 0xfffffffc) << (DAT_02124080 & 3) * -8 + 0x20) + 0x1f52) = 0;
    uVar3 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
            *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
    if (*(char *)(uVar3 + 0x1f53) != '\0') {
      do {
        if (((uint)*(byte *)(uVar3 + 0x1f55) & 1 << uVar6) != 0) {
          *(char *)(uVar3 + 0x1f52) = *(char *)(uVar3 + 0x1f52) + '\x01';
        }
        uVar3 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
        uVar6 = uVar6 + 1 & 0xff;
      } while (uVar6 < *(byte *)(uVar3 + 0x1f53));
    }
    iVar4 = func_0x0219bb50();
    SetGlobalCA81_from_thumb
              (*(undefined1 *)
                ((*(uint *)(DAT_02124080 & 0xfffffffc) >> (DAT_02124080 & 3) * 8 |
                 *(uint *)(DAT_02124080 & 0xfffffffc) << (DAT_02124080 & 3) * -8 + 0x20) + iVar4 +
                0x1f4e));
    SetGlobalCA82_from_thumb
              (*(undefined1 *)
                ((*(uint *)(DAT_02124080 & 0xfffffffc) >> (DAT_02124080 & 3) * 8 |
                 *(uint *)(DAT_02124080 & 0xfffffffc) << (DAT_02124080 & 3) * -8 + 0x20) + 0x1f52));
    return;
  case 2:
    uVar6 = 0;
    if (*(char *)((*(uint *)(DAT_02124080 & 0xfffffffc) >> (DAT_02124080 & 3) * 8 |
                  *(uint *)(DAT_02124080 & 0xfffffffc) << (DAT_02124080 & 3) * -8 + 0x20) + 0x1f53)
        != '\0') {
      do {
        uVar3 = func_0x0219bb50();
        if ((uVar6 != uVar3) &&
           (uVar3 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20,
           ((uint)*(byte *)(uVar3 + 0x1f55) & 1 << uVar6) != 0)) {
          func_0x021a3264(uVar6,uVar6 * 0x44 + uVar3 + 0x1d00,0x44);
        }
        iVar4 = GetGlobalCA_from_thumb();
        *(undefined4 *)(iVar4 + 0xd0) = 0;
        iVar4 = uVar6 * 0x44;
        *(undefined4 *)
         ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + iVar4 + 0x1e48) = 0;
        uVar6 = uVar6 + 1 & 0xff;
        *(undefined4 *)
         ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + iVar4 + 0x1d38) = 0;
      } while (uVar6 < *(byte *)((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                                 *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x1f53)
              );
    }
    func_0x021a323c(DAT_02124090);
    uVar1 = DAT_02124080;
    *(undefined4 *)
     ((*(uint *)(DAT_02124080 & 0xfffffffc) >> (DAT_02124080 & 3) * 8 |
      *(uint *)(DAT_02124080 & 0xfffffffc) << (DAT_02124080 & 3) * -8 + 0x20) + 0x1950) = 7;
    *(undefined4 *)
     ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
      *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x1980) = 0;
    *(undefined1 *)
     ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
      *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x19aa) = 0;
    *(undefined1 *)
     ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
      *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x19ab) = 0;
    func_02122684();
    uVar1 = DAT_02124080;
    uVar6 = 0;
    *(undefined1 *)
     ((*(uint *)(DAT_02124080 & 0xfffffffc) >> (DAT_02124080 & 3) * 8 |
      *(uint *)(DAT_02124080 & 0xfffffffc) << (DAT_02124080 & 3) * -8 + 0x20) + 0x1f52) = 0;
    uVar3 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
            *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
    if (*(char *)(uVar3 + 0x1f53) != '\0') {
      do {
        if (((uint)*(byte *)(uVar3 + 0x1f55) & 1 << uVar6) != 0) {
          *(char *)(uVar3 + 0x1f52) = *(char *)(uVar3 + 0x1f52) + '\x01';
        }
        uVar3 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
        uVar6 = uVar6 + 1 & 0xff;
      } while (uVar6 < *(byte *)(uVar3 + 0x1f53));
    }
    iVar4 = func_0x0219bb50();
    SetGlobalCA81_from_thumb
              (*(undefined1 *)
                ((*(uint *)(DAT_02124080 & 0xfffffffc) >> (DAT_02124080 & 3) * 8 |
                 *(uint *)(DAT_02124080 & 0xfffffffc) << (DAT_02124080 & 3) * -8 + 0x20) + iVar4 +
                0x1f4e));
    SetGlobalCA82_from_thumb
              (*(undefined1 *)
                ((*(uint *)(DAT_02124080 & 0xfffffffc) >> (DAT_02124080 & 3) * 8 |
                 *(uint *)(DAT_02124080 & 0xfffffffc) << (DAT_02124080 & 3) * -8 + 0x20) + 0x1f52));
    return;
  case 3:
    uVar6 = 0;
    if (*(char *)((*(uint *)(DAT_02124080 & 0xfffffffc) >> (DAT_02124080 & 3) * 8 |
                  *(uint *)(DAT_02124080 & 0xfffffffc) << (DAT_02124080 & 3) * -8 + 0x20) + 0x1f53)
        != '\0') {
      do {
        uVar3 = func_0x0219bb50();
        if ((uVar6 != uVar3) &&
           (uVar3 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20,
           ((uint)*(byte *)(uVar3 + 0x1f55) & 1 << uVar6) != 0)) {
          func_0x021a3264(uVar6,uVar6 * 0x44 + uVar3 + 0x1d00,0x44);
        }
        *(undefined4 *)
         ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x1980) = 0;
        *(undefined1 *)
         ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x19aa) = 0;
        *(undefined1 *)
         ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x19ab) = 0;
        iVar4 = GetGlobalCA_from_thumb();
        *(undefined4 *)(iVar4 + uVar6 * 0x18) = 0xffffffff;
        iVar4 = GetGlobalCA_from_thumb();
        *(undefined4 *)(iVar4 + uVar6 * 0x18 + 4) = 0xffffffff;
        iVar4 = GetGlobalCA_from_thumb();
        *(undefined4 *)(iVar4 + 0xd0) = 0;
        iVar4 = uVar6 * 0x44;
        *(undefined4 *)
         ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + iVar4 + 0x1e40) = 0xffffffff;
        uVar6 = uVar6 + 1 & 0xff;
        *(undefined4 *)
         ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + iVar4 + 0x1e44) = 0xffffffff;
        *(undefined4 *)
         ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + iVar4 + 0x1e48) = 0;
        *(undefined4 *)
         ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + iVar4 + 0x1e50) = 0;
        *(undefined4 *)
         ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + iVar4 + 0x1d30) = 0xffffffff;
        *(undefined4 *)
         ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + iVar4 + 0x1d34) = 0xffffffff;
        *(undefined4 *)
         ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + iVar4 + 0x1d38) = 0;
        *(undefined4 *)
         ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + iVar4 + 0x1d40) = 0;
      } while (uVar6 < *(byte *)((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                                 *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x1f53)
              );
    }
    func_0x021a323c(DAT_02124090);
    *(undefined4 *)
     ((*(uint *)(DAT_02124080 & 0xfffffffc) >> (DAT_02124080 & 3) * 8 |
      *(uint *)(DAT_02124080 & 0xfffffffc) << (DAT_02124080 & 3) * -8 + 0x20) + 0x1950) = 3;
  }
  return;
}

