/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#define GetBootIndicatorPointer GetBootIndicatorPointer_2
#define IsDwc func_020ce784
// PURPOSE: Checks whether the DWC boot indicator is active.
// Probably reads the system boot indicator and accepts only state two.

extern unsigned short *GetBootIndicatorPointer(void);

int IsDwc(void) {
    return *GetBootIndicatorPointer() == 2;
}
