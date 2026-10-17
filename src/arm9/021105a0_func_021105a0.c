/* Batch reconstruction: complete local bytes verified; full-ROM linking and caller ABI remain unverified. */
/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#define data_0217d26c data_0217d26c
// PURPOSE: Resets each entry in the global CY object list.
// The list contains ten fixed-size objects.
// Each object is passed to its dedicated reset routine.

typedef struct StructCY {
    char bytes[0x8];
} StructCY;

extern StructCY data_0217d26c[];
extern void func_0210e03c(StructCY *object);

void func_021105a0(void)
{
    int i;

    for (i = 0; i < 0x7; i++) {
        func_0210e03c(&data_0217d26c[i]);
    }
}
