/* Decompiled C draft; module arm9; ROM address 0209702c. No matching claim. */
#include "types.h"
#include "deps/0209702c_func_0209702c.h"

undefined1 func_0209702c(undefined2 *param_1,int param_2,byte *param_3,undefined1 *param_4)

{
  undefined1 uVar1;
  byte bVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int local_40;
  int local_3c;
  int local_38;
  undefined4 local_34;
  undefined2 *local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined2 *local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint uVar8;
  
  uVar4 = uRam020974fc;
  uVar5 = 1 << (*(ushort *)(param_2 + 0x74) & 0xff);
  uVar1 = *param_4;
  if (*param_3 - 3 < 2) {
    uVar8 = param_2 + 0x29cU & 3;
    uVar7 = *(uint *)(param_2 + 0x29cU & 0xfffffffc);
    uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
    if ((uVar8 != 1) &&
       ((uVar7 = (uint)(param_1 + 0x58) & 3, uVar6 = *(uint *)((uint)(param_1 + 0x58) & 0xfffffffc),
        uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20, uVar7 == 4 ||
        ((uVar7 == 5 &&
         (uVar7 = (uint)(param_1 + 0x50) & 3, uVar6 = *(uint *)((uint)(param_1 + 0x50) & 0xfffffffc)
         , 0x7800 < (int)(uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20))))))) {
      *(undefined4 *)(param_1 + 8) = 0;
      *(undefined4 *)(param_1 + 10) = 0x3800;
      *(undefined4 *)(param_1 + 0xc) = 0;
      return uVar1;
    }
    if (((uint)*(byte *)(param_1 + 0x84) & uVar5 & 0xff) == 0) {
      uVar7 = (uint)(param_1 + 0x58) & 3;
      uVar6 = *(uint *)((uint)(param_1 + 0x58) & 0xfffffffc);
      uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
      bVar2 = (byte)uVar5;
      if ((uVar7 == 0) || (uVar7 == 3)) {
        *(byte *)(param_1 + 0x84) = *(byte *)(param_1 + 0x84) | bVar2;
        uVar5 = uVar4 & 3;
        uVar4 = *(uint *)(uVar4 & 0xfffffffc);
        uVar5 = (uint)*(ushort *)(param_2 + 0x74) * 0x30 +
                (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x70;
        uVar4 = uVar5 & 3;
        uVar5 = *(uint *)(uVar5 & 0xfffffffc);
        if (((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) != 2) &&
           (uVar5 = (uint)(param_1 + 0x3c) & 3,
           uVar4 = *(uint *)((uint)(param_1 + 0x3c) & 0xfffffffc),
           ((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 4) == 0)) {
          uVar5 = (uint)(param_1 + 0x38) & 3;
          uVar4 = *(uint *)((uint)(param_1 + 0x38) & 0xfffffffc);
          uVar8 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
          uVar5 = iRam02097500 + 0x68U & 3;
          uVar4 = *(uint *)(iRam02097500 + 0x68U & 0xfffffffc);
          if (uVar8 == (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20)) {
            local_2c = 2;
          }
          else {
            uVar5 = iRam02097500 + 0x8cU & 3;
            uVar4 = *(uint *)(iRam02097500 + 0x8cU & 0xfffffffc);
            if (uVar8 == (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20)) {
              local_2c = 3;
            }
            else {
              local_2c = 4;
            }
          }
          local_30 = param_1 + 2;
          local_34 = uRam02097504;
          local_28 = func_020d4ef4();
          func_0210b7a8((uint)(uintptr_t)(&local_34));
        }
        uVar5 = (uint)(param_1 + 0x3c) & 3;
        uVar4 = *(uint *)((uint)(param_1 + 0x3c) & 0xfffffffc);
        *(uint *)(param_1 + 0x3c) =
             uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20 |
             *(uint *)(uRam02097508 & 0xfffffffc) >> (uRam02097508 & 3) * 8 |
             *(uint *)(uRam02097508 & 0xfffffffc) << (uRam02097508 & 3) * -8 + 0x20;
        return 0;
      }
      if ((uVar8 == 1) &&
         ((uVar7 == 4 ||
          (((uVar7 == 5 &&
            (uVar5 = (uint)(param_1 + 0x50) & 3,
            uVar4 = *(uint *)((uint)(param_1 + 0x50) & 0xfffffffc),
            0x7800 < (int)(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20))) || (uVar7 == 1)))))) {
        *(byte *)(param_1 + 0x84) = *(byte *)(param_1 + 0x84) | bVar2;
        if (((param_1[1] & 0x800) == 0) ||
           ((uint)*(ushort *)(param_2 + 0x74) ==
            (int)*(char *)((*(uint *)(uRam020974fc & 0xfffffffc) >> (uRam020974fc & 3) * 8 |
                           *(uint *)(uRam020974fc & 0xfffffffc) << (uRam020974fc & 3) * -8 + 0x20) +
                          0x62))) {
          *(undefined4 *)(param_1 + 0x82) = 1;
          uVar5 = (uint)(param_1 + 0x50) & 3;
          uVar4 = *(uint *)((uint)(param_1 + 0x50) & 0xfffffffc);
          *(uint *)(param_1 + 0x5a) = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
          uVar3 = uRam0209750c;
          uVar5 = (uint)(param_1 + 0x52) & 3;
          uVar4 = *(uint *)((uint)(param_1 + 0x52) & 0xfffffffc);
          *(uint *)(param_1 + 0x5c) = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
          *(undefined4 *)(param_1 + 0x5e) = 0x4000;
          *(undefined4 *)(param_1 + 0x60) = uVar3;
          param_1[0x62] = 0;
          *(undefined4 *)(param_1 + 0x68) = 0;
          *(undefined4 *)(param_1 + 0x6a) = 0x2000;
          *(undefined4 *)(param_1 + 0x6c) = 0xffffffc0;
          *(undefined4 *)(param_1 + 0x6e) = 0x200;
          *(undefined4 *)(param_1 + 0x70) = 0;
          param_1[0x72] = 0;
          *(undefined4 *)(param_1 + 0x78) = 0;
          *(undefined4 *)(param_1 + 0x7a) = 0x1000;
          *(undefined4 *)(param_1 + 0x7c) = 0xffffffd0;
          *(undefined4 *)(param_1 + 0x7e) = 0x800;
          *(undefined4 *)(param_1 + 0x80) = 0x100;
          func_020d26f8((int)(uintptr_t)(param_1),param_2);
          uVar5 = (*(uint *)(uRam020974fc & 0xfffffffc) >> (uRam020974fc & 3) * 8 |
                  *(uint *)(uRam020974fc & 0xfffffffc) << (uRam020974fc & 3) * -8 + 0x20) + 8;
          uVar4 = uVar5 & 3;
          uVar5 = *(uint *)(uVar5 & 0xfffffffc);
          if ((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) == 4) {
            uVar5 = (uint)(param_1 + 2) & 3;
            uVar7 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
            uVar4 = param_2 + 0x80U & 3;
            uVar8 = *(uint *)(param_2 + 0x80U & 0xfffffffc);
            local_40 = (int)((uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) +
                            (uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20)) >> 1;
            uVar5 = (uint)(param_1 + 4) & 3;
            uVar7 = *(uint *)((uint)(param_1 + 4) & 0xfffffffc);
            uVar4 = param_2 + 0x84U & 3;
            uVar8 = *(uint *)(param_2 + 0x84U & 0xfffffffc);
            local_3c = (int)((uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) +
                            (uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20)) >> 1;
            uVar5 = (uint)(param_1 + 6) & 3;
            uVar7 = *(uint *)((uint)(param_1 + 6) & 0xfffffffc);
            uVar4 = param_2 + 0x88U & 3;
            uVar8 = *(uint *)(param_2 + 0x88U & 0xfffffffc);
            local_38 = (int)((uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) +
                            (uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20)) >> 1;
            func_0208b7bc(uRam02097510,(uint)(uintptr_t)(&local_40));
            func_0208b7bc(uRam02097514,(uint)(uintptr_t)(&local_40));
            uVar5 = (*(uint *)(uRam020974fc & 0xfffffffc) >> (uRam020974fc & 3) * 8 |
                    *(uint *)(uRam020974fc & 0xfffffffc) << (uRam020974fc & 3) * -8 + 0x20) + 8;
            uVar4 = uVar5 & 3;
            uVar5 = *(uint *)(uVar5 & 0xfffffffc);
            if ((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) == 4) {
              func_0x0218175c(*param_1);
            }
          }
        }
        if ((param_1[1] & 0x800) == 0) {
          uVar5 = (uint)(param_1 + 0x58) & 3;
          uVar4 = *(uint *)((uint)(param_1 + 0x58) & 0xfffffffc);
          uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
          if (uVar5 == 1) {
            *(undefined4 *)(param_1 + 0x58) = 6;
          }
          else if (uVar5 == 4) {
            *(undefined4 *)(param_1 + 0x58) = 7;
          }
        }
        *(undefined4 *)(param_1 + 8) = 0;
        *(undefined4 *)(param_1 + 10) = 0;
        *(undefined4 *)(param_1 + 0xc) = 0;
        return uVar1;
      }
      if (uVar7 == 1) {
        *(byte *)(param_1 + 0x84) = *(byte *)(param_1 + 0x84) | bVar2;
        if (((param_1[1] & 0x800) == 0) ||
           ((uint)*(ushort *)(param_2 + 0x74) ==
            (int)*(char *)((*(uint *)(uRam020974fc & 0xfffffffc) >> (uRam020974fc & 3) * 8 |
                           *(uint *)(uRam020974fc & 0xfffffffc) << (uRam020974fc & 3) * -8 + 0x20) +
                          0x62))) {
          *(undefined4 *)(param_1 + 0x82) = 1;
          uVar5 = (uint)(param_1 + 0x50) & 3;
          uVar4 = *(uint *)((uint)(param_1 + 0x50) & 0xfffffffc);
          *(uint *)(param_1 + 0x5a) = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
          uVar5 = (uint)(param_1 + 0x52) & 3;
          uVar4 = *(uint *)((uint)(param_1 + 0x52) & 0xfffffffc);
          *(uint *)(param_1 + 0x5c) = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
          *(undefined4 *)(param_1 + 0x5e) = 0;
          *(undefined4 *)(param_1 + 0x60) = 0;
          param_1[0x62] = 0;
          *(undefined4 *)(param_1 + 0x68) = 0;
          *(undefined4 *)(param_1 + 0x6a) = 0x2000;
          *(undefined4 *)(param_1 + 0x6c) = 0xffffffc0;
          *(undefined4 *)(param_1 + 0x6e) = 0x200;
          *(undefined4 *)(param_1 + 0x70) = 0;
          param_1[0x72] = 0;
          *(undefined4 *)(param_1 + 0x78) = 0;
          *(undefined4 *)(param_1 + 0x7a) = 0x1000;
          *(undefined4 *)(param_1 + 0x7c) = 0xffffffd0;
          *(undefined4 *)(param_1 + 0x7e) = 0x800;
          *(undefined4 *)(param_1 + 0x80) = 0x100;
          uVar5 = (uint)(param_1 + 0x3c) & 3;
          uVar4 = *(uint *)((uint)(param_1 + 0x3c) & 0xfffffffc);
          *(uint *)(param_1 + 0x3c) =
               uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20 |
               *(uint *)(uRam02097508 & 0xfffffffc) >> (uRam02097508 & 3) * 8 |
               *(uint *)(uRam02097508 & 0xfffffffc) << (uRam02097508 & 3) * -8 + 0x20;
          uVar5 = (uint)(param_1 + 0x3c) & 3;
          uVar4 = *(uint *)((uint)(param_1 + 0x3c) & 0xfffffffc);
          if (((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 4) == 0) {
            uVar5 = (uint)(param_1 + 0x38) & 3;
            uVar4 = *(uint *)((uint)(param_1 + 0x38) & 0xfffffffc);
            uVar8 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
            uVar5 = iRam02097500 + 0x68U & 3;
            uVar4 = *(uint *)(iRam02097500 + 0x68U & 0xfffffffc);
            if (uVar8 == (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20)) {
              local_1c = 2;
            }
            else {
              uVar5 = iRam02097500 + 0x8cU & 3;
              uVar4 = *(uint *)(iRam02097500 + 0x8cU & 0xfffffffc);
              if (uVar8 == (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20)) {
                local_1c = 3;
              }
              else {
                local_1c = 4;
              }
            }
            local_20 = param_1 + 2;
            local_24 = uRam02097518;
            local_18 = func_020d4ef4();
            func_0210b7a8((uint)(uintptr_t)(&local_24));
          }
        }
        uVar5 = uRam0209751c;
        if ((param_1[1] & 0x800) == 0) {
          *(undefined4 *)(param_1 + 0x58) = 6;
        }
        uVar4 = param_2 + 0xa4U & 3;
        uVar8 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
        uVar4 = uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20;
        *(uint *)(param_1 + 8) =
             (uint)((ulonglong)uVar5 * (ulonglong)uVar4) >> 0xc |
             (((int)uVar4 >> 0x1f) * uVar5 +
             ((int)((ulonglong)uVar5 * (ulonglong)uVar4 >> 0x20) - uVar4)) * 0x100000;
        uVar4 = param_2 + 0xa8U & 3;
        uVar8 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
        uVar4 = uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20;
        *(uint *)(param_1 + 10) =
             (uint)((ulonglong)uVar5 * (ulonglong)uVar4) >> 0xc |
             (((int)uVar4 >> 0x1f) * uVar5 +
             ((int)((ulonglong)uVar5 * (ulonglong)uVar4 >> 0x20) - uVar4)) * 0x100000;
        uVar4 = param_2 + 0xacU & 3;
        uVar8 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
        uVar4 = uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20;
        *(uint *)(param_1 + 0xc) =
             (uint)((ulonglong)uVar5 * (ulonglong)uVar4) >> 0xc |
             (((int)uVar4 >> 0x1f) * uVar5 +
             ((int)((ulonglong)uVar5 * (ulonglong)uVar4 >> 0x20) - uVar4)) * 0x100000;
        *(undefined4 *)(param_1 + 10) = 0x3800;
        return 0xc;
      }
    }
  }
  uVar5 = (uint)(param_1 + 0x3c) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 0x3c) & 0xfffffffc);
  *(uint *)(param_1 + 0x3c) =
       uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20 |
       *(uint *)(uRam02097508 & 0xfffffffc) >> (uRam02097508 & 3) * 8 |
       *(uint *)(uRam02097508 & 0xfffffffc) << (uRam02097508 & 3) * -8 + 0x20;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 10) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  return 0;
}

