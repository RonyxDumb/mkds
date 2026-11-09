#include "Main/Unknown/code_020b3278.h"
#include "Main/Unknown/code_020b252c.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_020b1de4.h"

#pragma thumb on
#pragma optimize_for_size on
// In mode 5 the sequence index is always 4, whatever the selected value.
void StartChoisesSSelectedValueSeq(void) {
    if (func_020b252c() == 5) {
        StartChoisesSValueSeq(4);
    } else {
        switch (gChoisesS->mSelectedValue) {
            case 0:
            case 8:
                StartChoisesSValueSeq(0);
                break;
            case 1:
            case 3:
                StartChoisesSValueSeq(1);
                break;
            case 2:
            case 7:
            case 10:
                StartChoisesSValueSeq(5);
                break;
            case 4:
            case 5:
            case 6:
                StartChoisesSValueSeq(2);
                break;
            case 9:
                StartChoisesSValueSeq(3);
                break;
        }
    }
}
#pragma thumb off
