/* Decompiled C draft; module arm9; ROM address 02045bd4. No matching claim. */
#include "types.h"
#include "deps/02045bd4_func_02045bd4.h"

undefined4 func_02045bd4(void)

{
  uint uVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uStack_30;
  undefined2 local_2c;
  undefined2 local_2a;
  
  bVar2 = *(byte *)((*(uint *)(uRam02045ec4 & 0xfffffffc) >> (uRam02045ec4 & 3) * 8 |
                    *(uint *)(uRam02045ec4 & 0xfffffffc) << (uRam02045ec4 & 3) * -8 + 0x20) + 0x62);
  iVar4 = GetSomeRacerPosition((short)(char)bVar2);
  *(int *)((*(uint *)(uRam02045ec8 & 0xfffffffc) >> (uRam02045ec8 & 3) * 8 |
           *(uint *)(uRam02045ec8 & 0xfffffffc) << (uRam02045ec8 & 3) * -8 + 0x20) + 0x7c) =
       iVar4 + -1;
  uVar5 = func_0205d190();
  uVar1 = uRam02045ec8;
  uVar9 = uRam02045ec4;
  *(undefined4 *)
   ((*(uint *)(uRam02045ec8 & 0xfffffffc) >> (uRam02045ec8 & 3) * 8 |
    *(uint *)(uRam02045ec8 & 0xfffffffc) << (uRam02045ec8 & 3) * -8 + 0x20) + 0x80) = uVar5;
  iVar11 = (uint)bVar2 * 0x30;
  uVar10 = (*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
           *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + iVar11 + 0x68;
  uVar7 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  *(uint *)((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
            *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x90) =
       uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20;
  uVar10 = (*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
           *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + 4;
  uVar7 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  *(uint *)((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
            *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x84) =
       uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20;
  uVar10 = (*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
           *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + 0x10;
  uVar7 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  *(uint *)((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
            *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x88) =
       uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20;
  *(int *)((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
           *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x8c) =
       (int)*(char *)((*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                      *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + 0x57);
  uVar5 = Int32ToInt8();
  iVar4 = GetSomeLUMaxIndex();
  iVar6 = Int32ToInt8(uVar5);
  uVar1 = uRam02045ec8;
  uVar9 = uRam02045ec4;
  *(undefined2 *)
   ((*(uint *)(uRam02045ec8 & 0xfffffffc) >> (uRam02045ec8 & 3) * 8 |
    *(uint *)(uRam02045ec8 & 0xfffffffc) << (uRam02045ec8 & 3) * -8 + 0x20) + 0xa8) =
       *(undefined2 *)
        (iVar4 * 0x50 +
         (*(uint *)(uRam02045ecc & 0xfffffffc) >> (uRam02045ecc & 3) * 8 |
         *(uint *)(uRam02045ecc & 0xfffffffc) << (uRam02045ecc & 3) * -8 + 0x20) + iVar6 * 10);
  uVar10 = (*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
           *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + iVar11 + 0x6c;
  uVar7 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  uVar12 = 0;
  *(uint *)((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
            *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x94) =
       uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20;
  do {
    func_0205d7c8(&local_2c,
                  (short)*(char *)((*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                                   *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + 0x62)
                  ,uVar12);
    iVar4 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
            *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + uVar12 * 4;
    *(undefined2 *)(iVar4 + 0x98) = local_2c;
    uVar12 = uVar12 + 1 & 0xff;
    *(undefined2 *)(iVar4 + 0x9a) = local_2a;
  } while (uVar12 < 4);
  uVar7 = GetSomeRacerPosition
                    ((short)*(char *)((*(uint *)(uRam02045ec4 & 0xfffffffc) >>
                                       (uRam02045ec4 & 3) * 8 |
                                      *(uint *)(uRam02045ec4 & 0xfffffffc) <<
                                      (uRam02045ec4 & 3) * -8 + 0x20) + 0x62));
  uVar10 = uRam02045ec4;
  if (3 < uVar7) {
    return 0;
  }
  *(undefined4 *)
   ((*(uint *)(uRam02045ec4 & 0xfffffffc) >> (uRam02045ec4 & 3) * 8 |
    *(uint *)(uRam02045ec4 & 0xfffffffc) << (uRam02045ec4 & 3) * -8 + 0x20) + 0x1e8) = 0x34;
  uVar7 = 0;
  *(undefined4 *)
   ((*(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
    *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20) + 500) = 5;
  uStack_30 = 0;
  do {
    uVar9 = uStack_30;
    if (*(char *)((*(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
                  *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20) + 0x3d0) != '\0') {
      do {
        iVar4 = GetSomeRacerPosition(uVar9 & 0xffff);
        if (uVar7 + 1 == iVar4) break;
        uVar9 = (int)((uVar9 + 1) * 0x1000000) >> 0x18;
      } while ((int)uVar9 <
               (int)(uint)*(byte *)((*(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
                                    *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20) +
                                   0x3d0));
    }
    iVar4 = (uVar9 & 0xffff) * 0x30 +
            (*(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
            *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20);
    uVar9 = iVar4 + 0x68;
    uVar1 = uVar9 & 3;
    uVar8 = *(uint *)(uVar9 & 0xfffffffc);
    uVar9 = iVar4 + 0x6c;
    uVar12 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    StructCO_ConfigureRacerDefault
              (uVar7,uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20,
               uVar9 >> uVar12 * 8 | uVar9 << uVar12 * -8 + 0x20,1);
    uVar7 = uVar7 + 1 & 0xff;
    uVar9 = uRam02045ec4;
    uVar1 = uRam02045ec8;
    if (2 < uVar7) {
      for (; uRam02045ec4 = uVar9, uRam02045ec8 = uVar1, uVar7 < 8; uVar7 = uVar7 + 1 & 0xff) {
        StructCO_ConfigureRacerDefault(uVar7,uVar7,uVar7 * 3,4);
        uVar9 = uRam02045ec4;
        uVar1 = uRam02045ec8;
      }
      uVar10 = 0;
      do {
        iVar4 = GetSomeRacerPosition(uVar10);
        iVar6 = uVar10 * 0x30;
        uVar10 = uVar10 + 1 & 0xff;
        uVar7 = (*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + iVar6 + 0x6c;
        uVar12 = uVar7 & 3;
        uVar7 = *(uint *)(uVar7 & 0xfffffffc);
        *(uint *)((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                  *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + (iVar4 + -1) * 4 +
                 0xcc) = uVar7 >> uVar12 * 8 | uVar7 << uVar12 * -8 + 0x20;
        uVar7 = (*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + iVar6 + 0x68;
        uVar12 = uVar7 & 3;
        uVar7 = *(uint *)(uVar7 & 0xfffffffc);
        *(uint *)((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                  *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + (iVar4 + -1) * 4 +
                 0xac) = uVar7 >> uVar12 * 8 | uVar7 << uVar12 * -8 + 0x20;
      } while (uVar10 < 8);
      cVar3 = GetSomeRacerPosition
                        ((short)*(char *)((*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                                          *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20)
                                         + 0x62));
      *(char *)((*(uint *)(uRam02045ec4 & 0xfffffffc) >> (uRam02045ec4 & 3) * 8 |
                *(uint *)(uRam02045ec4 & 0xfffffffc) << (uRam02045ec4 & 3) * -8 + 0x20) + 0x24b) =
           cVar3 + -1;
      return 1;
    }
  } while( true );
}

