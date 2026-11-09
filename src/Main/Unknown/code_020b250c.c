#include "Main/Unknown/code_020b250c.h"
#include "Main/Unknown/code_020b252c.h"
#include "Main/Unknown/code_020b24e4.h"
#include "Main/Unknown/unk_021759c0.h"

#pragma thumb on
#pragma optimize_for_size on
BOOL IsGrandPrixLastCourse(void) {
    return ChoisesSGetCurrentMode() == MODE_GRAND_PRIX && GetCourseNumber() == 4;
}
#pragma thumb off
