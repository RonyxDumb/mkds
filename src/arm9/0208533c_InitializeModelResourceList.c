/* Batch reconstruction: complete local bytes verified; full-ROM linking and caller ABI remain unverified. */
/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#define IntrusiveListWrapper_InitializeEmpty IntrusiveListWrapper_InitializeEmpty
#define data_0217aeb0 data_0217aeb0
extern void IntrusiveListWrapper_InitializeEmpty(void *a1, int a2);
extern int data_0217aeb0;

void InitializeModelResourceList(void)
{
    IntrusiveListWrapper_InitializeEmpty(&data_0217aeb0, 0x0);
}
