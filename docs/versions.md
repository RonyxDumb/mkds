# The European version

## Complete European build, 2026-11-16

The European ROM (SHA-1 `ce97d9b43f0d3ca0d48b781983e8a16f6393378f`) is rebuilt byte for byte from the same named
source tree as USA: every unit that is complete for USA is complete for Europe, **11,498 of 11,498 functions** match
and 1,882,966 bytes of code (99.83%) are linked, the same as USA. `ninja check` passes for both versions, and
`tools/check_calls.py`, `check_callees.py`, `check_strings.py`, `check_signatures.py` and `check_protos.py` report
no differences on Europe.

`config/eur/` was carried over from the completed European configuration of the earlier, unnamed tree. Every object
was matched to its USA counterpart by address (shared names, then the targets of corresponding relocations in
matching functions, then the layout between them), and then takes the USA name and kind; unit ranges are the USA
units moved to the European addresses of their boundaries. Relocations into the middle of an object use the object
and an addend, as for USA.

Regional differences in the source, each under `#ifdef version_EUR`:

| Where | Europe |
| --- | --- |
| `OS_GetInitArenaLo` | the main arena starts at `0x021da340` (USA `0x021da300`) |
| `BuildInfo` | the cleared range ends at `0x021804e0`, the end of `.bss` (USA `0x021804c0`) |
| `FillStartupWork` | `mRegion` is 2 (USA 1) |
| `LoadOverlayAndRunDWCUtility` | passes 0 as the last argument of `RunMainLoop` (USA `0x20`) |
| `TCPIP_STACK_TOP` | `gOverlayExpHeapBuffer + 0xdfa0` (USA `+ 0xdf80`) |
| `LookupWiFiVSSettingMessageIndex` | returns 6 for setting 2 in language 0 or 1 |
| `LoadAndQueueEndingSceneData` | loads the `_02` logo graphics (USA `_01`) |
| Title screen | loads `title_true_m1_EU.NSCR` / `title_m1_EU.NSCR` |
| Logo scene | the sub screen shows `allRightsReserved_s*` instead of the ESRB screen |
| `bios_calls.s` | the BIOS stubs of the secure area sit at other addresses, in another order |

`tools/expand_incbin.py` keeps only the configured version's `#ifdef version_<VER>` branch of an assembly file, so
each version's filler bytes come from its own ROM.

## Shared-source validation on Europe, 2026-10-29

Checked on 2026-10-29, starting at `9cc5b2a7` and the European ROM with SHA-1
`ce97d9b43f0d3ca0d48b781983e8a16f6393378f`.

### Results

The USA configuration registers 2,713 C translation units, representing 7,549 functions. Building those same
sources for Europe gives **7,254 fully matching functions, covering 958,670 bytes**. These totals equal the latest
committed USA progress point. The 295 remaining functions in these units are not 100% matches; this check does
not establish that they are regional differences. A fresh USA ROM build was not run.

The European configuration was missing 725 of the main module's source units and one ITCM unit. Registering
these 726 units adds 3,488 verified matching functions. Another 168 matching functions are in source units
registered only for Europe.

| European measurement | Before | After |
| --- | ---: | ---: |
| Matching functions | 3,934 | 7,422 |
| Matching code | 278,314 bytes (14.76%) | 964,162 bytes (51.12%) |
| Linked source code | 59,640 bytes (3.16%) | 59,640 bytes (3.16%) |

No previously reported function's matching score decreased. Of the newly registered units, 567 have every
function matching. New units remain unlinked: an object-level match and a successful ROM rebuild with the
existing linked units do not prove that a pending unit's data layout is ready for linking.

### Regional addresses

After the secure area, all 7,676 main-module functions have the same addresses, instruction modes, sizes and
order in the two symbol configurations. This provided candidate ranges; actual compiled code was compared
with the European original through objdiff. Matching also checks the referenced addresses and strings with the
repository tools, since relocated branch and pointer bytes are masked during instruction comparison.

Data addresses cannot be copied with one regional offset. Corresponding relocation sites in the original
European code establish the data addresses, including:

- The data range for `src/Main/Unknown/code_020bb5ec.c` is `0x0216910c–0x02169134` in Europe, versus
  `0x02169104–0x0216912c` in USA.
- The shared pointer named `data_0217ae80` lives at `0x0217ae80` in Europe and `0x0217ae60` in USA. Its old
  source name selected the unrelated European symbol at `0x0217ae60`.
- Seventeen shared data names now use the European reference addresses. The USA symbol addresses, kinds,
  sizes and attributes are unchanged.
- Eight additional European data symbols identify referenced tables in the main module and overlays 0 and 1.

The nonmatching draft `func_020e0764` also shares its two result paths, bringing its four helper-call sites down
to the original's two. Its code is now `0x43c` bytes against the original's `0x448`, and its similarity improves
from 36.27% to 63.80%. It remains excluded from the fully matching count.

### Reproduce

Use the pinned tools described in `INSTALL.md`, including wibo `1.2.0-8-g420a75b` and CodeWarrior `1.2/base`.

```sh
python3 tools/configure.py eur
ninja report check
python3 tools/check_calls.py
python3 tools/check_callees.py
python3 tools/check_strings.py
python3 tools/check_signatures.py
python3 tools/check_protos.py
python3 tools/check_units.py
python3 tools/progress.py check
```

The European ROM rebuild and symbol check pass. Calls/pointers, callee sets, strings, signatures and missing
prototypes each report zero differences or problems; every source unit passes the range check. All previously
matching functions remain matching, and no reported function's score decreases.
