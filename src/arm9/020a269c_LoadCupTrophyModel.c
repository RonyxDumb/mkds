/* Decompiled C draft; module arm9; ROM address 020a269c. No matching claim. */
#include "types.h"
#include "deps/020a269c_LoadCupTrophyModel.h"

void LoadCupTrophyModel(int param_1,uint param_2)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  uint uVar11;
  uint uVar12;
  
  GetActiveExecutionContext();
  uVar5 = ExecutionContext_GetHeapHandle();
  iVar6 = Mem_AllocateHeap(uVar5,0x124);
  piVar2 = piRam020a299c;
  *piRam020a299c = iVar6;
  *(short *)(iVar6 + 2) = (short)param_2;
  uVar8 = (uint)piVar2 & 3;
  uVar7 = *(uint *)((uint)piVar2 & 0xfffffffc);
  *(short *)(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) = (short)param_1;
  if ((param_1 < 9) && (param_2 < 3)) {
    uVar8 = iRam020a29a0 + param_1 * 4;
    uVar7 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    uVar5 = find_buf_fn_from_thumb(uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20);
    uVar8 = iRam020a29a4 + param_1 * 4;
    uVar7 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    uVar9 = find_buf_fn_from_thumb(uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20);
    iVar3 = iRam020a29ac;
    piVar2 = piRam020a299c;
    iVar6 = param_1 * 2;
    *(undefined2 *)
     ((*(uint *)((uint)piRam020a299c & 0xfffffffc) >> ((uint)piRam020a299c & 3) * 8 |
      *(uint *)((uint)piRam020a299c & 0xfffffffc) << ((uint)piRam020a299c & 3) * -8 + 0x20) + 0xfc)
         = *(undefined2 *)(iRam020a29a8 + iVar6);
    iVar4 = iRam020a29b0;
    *(undefined2 *)
     ((*(uint *)((uint)piVar2 & 0xfffffffc) >> ((uint)piVar2 & 3) * 8 |
      *(uint *)((uint)piVar2 & 0xfffffffc) << ((uint)piVar2 & 3) * -8 + 0x20) + 0x100) =
         *(undefined2 *)(iVar3 + iVar6);
    iVar3 = iRam020a29b4;
    *(undefined2 *)
     ((*(uint *)((uint)piVar2 & 0xfffffffc) >> ((uint)piVar2 & 3) * 8 |
      *(uint *)((uint)piVar2 & 0xfffffffc) << ((uint)piVar2 & 3) * -8 + 0x20) + 0x104) =
         *(undefined2 *)(iVar4 + iVar6);
    iVar4 = iRam020a29b8;
    *(undefined2 *)
     ((*(uint *)((uint)piVar2 & 0xfffffffc) >> ((uint)piVar2 & 3) * 8 |
      *(uint *)((uint)piVar2 & 0xfffffffc) << ((uint)piVar2 & 3) * -8 + 0x20) + 0xfe) =
         *(undefined2 *)(iVar3 + iVar6);
    iVar3 = iRam020a29bc;
    *(undefined2 *)
     ((*(uint *)((uint)piVar2 & 0xfffffffc) >> ((uint)piVar2 & 3) * 8 |
      *(uint *)((uint)piVar2 & 0xfffffffc) << ((uint)piVar2 & 3) * -8 + 0x20) + 0x102) =
         *(undefined2 *)(iVar4 + iVar6);
    *(undefined2 *)
     ((*(uint *)((uint)piVar2 & 0xfffffffc) >> ((uint)piVar2 & 3) * 8 |
      *(uint *)((uint)piVar2 & 0xfffffffc) << ((uint)piVar2 & 3) * -8 + 0x20) + 0x106) =
         *(undefined2 *)(iVar3 + iVar6);
    iVar6 = iRam020a29c0;
    *(undefined4 *)
     ((*(uint *)((uint)piVar2 & 0xfffffffc) >> ((uint)piVar2 & 3) * 8 |
      *(uint *)((uint)piVar2 & 0xfffffffc) << ((uint)piVar2 & 3) * -8 + 0x20) + 0x108) = 0;
    uVar8 = iVar6 + param_1 * 4;
    uVar7 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    *(uint *)((*(uint *)((uint)piVar2 & 0xfffffffc) >> ((uint)piVar2 & 3) * 8 |
              *(uint *)((uint)piVar2 & 0xfffffffc) << ((uint)piVar2 & 3) * -8 + 0x20) + 0x10c) =
         uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    iVar6 = iRam020a29c4;
    *(undefined4 *)
     ((*(uint *)((uint)piVar2 & 0xfffffffc) >> ((uint)piVar2 & 3) * 8 |
      *(uint *)((uint)piVar2 & 0xfffffffc) << ((uint)piVar2 & 3) * -8 + 0x20) + 0x110) = 0xffffe000;
    uVar8 = iVar6 + param_1 * 4;
    uVar7 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    *(uint *)((*(uint *)((uint)piVar2 & 0xfffffffc) >> ((uint)piVar2 & 3) * 8 |
              *(uint *)((uint)piVar2 & 0xfffffffc) << ((uint)piVar2 & 3) * -8 + 0x20) + 0x114) =
         uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    Model_CreateFromNsbmd
              ((*(uint *)((uint)piVar2 & 0xfffffffc) >> ((uint)piVar2 & 3) * 8 |
               *(uint *)((uint)piVar2 & 0xfffffffc) << ((uint)piVar2 & 3) * -8 + 0x20) + 0x28,uVar5)
    ;
    StructML_SomeFn_8((*(uint *)((uint)piRam020a299c & 0xfffffffc) >> ((uint)piRam020a299c & 3) * 8
                      | *(uint *)((uint)piRam020a299c & 0xfffffffc) <<
                        ((uint)piRam020a299c & 3) * -8 + 0x20) + 0x28,3);
    if (*(char *)((*(uint *)(uRam020a29c8 & 0xfffffffc) >> (uRam020a29c8 & 3) * 8 |
                  *(uint *)(uRam020a29c8 & 0xfffffffc) << (uRam020a29c8 & 3) * -8 + 0x20) + 0x57) ==
        '\0') {
      Model_SetCullMode((*(uint *)((uint)piRam020a299c & 0xfffffffc) >>
                         ((uint)piRam020a299c & 3) * 8 |
                        *(uint *)((uint)piRam020a299c & 0xfffffffc) <<
                        ((uint)piRam020a299c & 3) * -8 + 0x20) + 0x28,2);
    }
    else {
      Model_SetCullMode((*(uint *)((uint)piRam020a299c & 0xfffffffc) >>
                         ((uint)piRam020a299c & 3) * 8 |
                        *(uint *)((uint)piRam020a299c & 0xfffffffc) <<
                        ((uint)piRam020a299c & 3) * -8 + 0x20) + 0x28,1);
    }
    GetActiveExecutionContext();
    uVar10 = ExecutionContext_GetHeapHandle();
    uVar8 = *(uint *)((uint)piRam020a299c & 0xfffffffc) >> ((uint)piRam020a299c & 3) * 8 |
            *(uint *)((uint)piRam020a299c & 0xfffffffc) << ((uint)piRam020a299c & 3) * -8 + 0x20;
    Animation_CreateFrom(2,uVar8 + 0x94,uVar8 + 0x28,1,uVar10,uVar5);
    GetActiveExecutionContext();
    uVar5 = ExecutionContext_GetHeapHandle();
    Animation_RegisterAll
              ((*(uint *)((uint)piRam020a299c & 0xfffffffc) >> ((uint)piRam020a299c & 3) * 8 |
               *(uint *)((uint)piRam020a299c & 0xfffffffc) << ((uint)piRam020a299c & 3) * -8 + 0x20)
               + 0x94,uVar9,uVar5);
    Animation_SetAt((*(uint *)((uint)piRam020a299c & 0xfffffffc) >> ((uint)piRam020a299c & 3) * 8 |
                    *(uint *)((uint)piRam020a299c & 0xfffffffc) <<
                    ((uint)piRam020a299c & 3) * -8 + 0x20) + 0x94,0);
    uVar8 = *(uint *)((uint)piRam020a299c & 0xfffffffc) >> ((uint)piRam020a299c & 3) * 8 |
            *(uint *)((uint)piRam020a299c & 0xfffffffc) << ((uint)piRam020a299c & 3) * -8 + 0x20;
    if (*(ushort *)(uVar8 + 2) == 0) {
      uVar5 = FUN_02132440(0);
      func_021329f8(uVar5,0x3f000000);
    }
    else {
      uVar5 = FUN_02132440((uint)*(ushort *)(uVar8 + 2) << 0xc);
      func_02131234(0x3f000000,uVar5);
    }
    uVar5 = func_021322c8();
    *(undefined4 *)(uVar8 + 0xa0) = uVar5;
    uVar7 = uVar8 + 0xb0 & 3;
    uVar11 = *(uint *)(uVar8 + 0xb0 & 0xfffffffc);
    uVar1 = uVar8 + 0xa0 & 3;
    uVar12 = *(uint *)(uVar8 + 0xa0 & 0xfffffffc);
    uVar8 = (uVar11 >> uVar7 * 8 | uVar11 << uVar7 * -8 + 0x20) +
            (uint)*(ushort *)(uVar8 + 0xae) * 4;
    uVar7 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    *(uint *)(uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20) =
         uVar12 >> uVar1 * 8 | uVar12 << uVar1 * -8 + 0x20;
    GetActiveExecutionContext();
    ExecutionContext_GetHeapHandle();
    SomeEffectFileStuff();
    if (param_2 == 0) {
      uVar5 = func_0208b7bc();
      *(undefined4 *)
       ((*(uint *)((uint)piRam020a299c & 0xfffffffc) >> ((uint)piRam020a299c & 3) * 8 |
        *(uint *)((uint)piRam020a299c & 0xfffffffc) << ((uint)piRam020a299c & 3) * -8 + 0x20) +
       0x118) = uVar5;
      uVar5 = func_0208b7bc(4);
      *(undefined4 *)
       ((*(uint *)((uint)piRam020a299c & 0xfffffffc) >> ((uint)piRam020a299c & 3) * 8 |
        *(uint *)((uint)piRam020a299c & 0xfffffffc) << ((uint)piRam020a299c & 3) * -8 + 0x20) +
       0x11c) = uVar5;
      uVar5 = func_0208b7bc(5);
      *(undefined4 *)
       ((*(uint *)((uint)piRam020a299c & 0xfffffffc) >> ((uint)piRam020a299c & 3) * 8 |
        *(uint *)((uint)piRam020a299c & 0xfffffffc) << ((uint)piRam020a299c & 3) * -8 + 0x20) +
       0x120) = uVar5;
    }
    else if (param_2 == 1) {
      uVar5 = func_0208b7bc();
      *(undefined4 *)
       ((*(uint *)((uint)piRam020a299c & 0xfffffffc) >> ((uint)piRam020a299c & 3) * 8 |
        *(uint *)((uint)piRam020a299c & 0xfffffffc) << ((uint)piRam020a299c & 3) * -8 + 0x20) +
       0x118) = uVar5;
    }
  }
  func_020a29cc();
  return;
}

