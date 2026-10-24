#include "Main/Unknown/code_0208b6b0.h"

void func_0208b710(u32 param_1) {
    u32 uVar1;
    u8 auStack_10[8];
    uVar1 = (*(UnkWordFunc *) (*(u32 *) (((u32) ((u32) (&data_0217b050))))))(auStack_10, 0);
    func_020184e4((int) (uVar1), (int) (param_1));
    return;
}

void func_0208b6d0(u32 *param_1) {
    u32 uVar1;
    u8 auStack_10[8];
    uVar1 = (*(UnkWordFunc *) (*(u32 *) (((u32) ((u32) (&data_0217b050))))))(auStack_10, 0);
    func_020184e4((int) (uVar1), (int) (*(u32 *) ((u32) param_1)));
    *param_1 = 0;
    return;
}

void func_0208b6b0(unsigned int p0) {
    *(unsigned int *) ((unsigned char *) (unsigned int) ((
                           (unsigned int) *(const unsigned int *) ((unsigned char *) (unsigned int) (p0) + 0))) +
                       36) =
        (unsigned int) ((
            (((((unsigned int) *(
                  const unsigned int *) ((unsigned char *) (unsigned int) (((unsigned int) *(
                                             const unsigned int *) ((unsigned char *) (unsigned int) (p0) + 0))) +
                                         36))) &
              ~(0x1u))) |
            (0x1u)));
    *(unsigned int *) ((unsigned char *) (unsigned int) (p0) + 0) = (unsigned int) (0x0u);
}
