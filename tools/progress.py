#!/usr/bin/env python3
"""Tracks matching progress over time, per version, and renders its graph and treemap.

  progress.py update   append the current objdiff report to progress/<ver>/history.csv
                       (if it changed), redraw progress/<ver>/progress.svg and
                       progress/<ver>/treemap.svg, rewrite the version's
                       README section between its progress markers
  progress.py check    exit 1 if the report differs from the version's last recorded
                       point (used by .githooks/pre-push)

The version is the configured one (tools/project.py); each version keeps its own history and README section, so
updating one never touches another. Both read build/<ver>/report.json, so run `ninja report` first.

Every percentage is a share of one fixed size: the bytes of the code sections in config/ (kind:code sections of every
module's delinks.txt). objdiff's own total only covers bytes that have a symbol, so it grows whenever a commit names
bytes for the first time (a missed function, a table in .text) and the percentage would drop although nothing got
worse. Measured against the fixed size, progress only moves when matched bytes do.
"""
import argparse
import csv
import json
import re
import sys
from datetime import datetime, timezone
from pathlib import Path
from project import VERSION, configured_version, module_paths, modules  # noqa: E402  (tools/project.py)

ROOT = Path(__file__).resolve().parent.parent
HISTORY = ROOT / "progress" / VERSION / "history.csv"
SVG = ROOT / "progress" / VERSION / "progress.svg"
TREEMAP = ROOT / "progress" / VERSION / "treemap.svg"
README = ROOT / "README.md"
LABELS = {"usa": "USA", "eur": "Europe"}
LABEL = LABELS.get(VERSION, VERSION.upper())
START, END = f"<!-- progress:{VERSION}:start -->", f"<!-- progress:{VERSION}:end -->"
FIELDS = ["date", "matched_code", "complete_code", "total_code", "matched_functions", "total_functions",
          "fuzzy_match_percent"]

# (key, label, light-theme colour, dark-theme colour)
# matched_code: compiled C byte-identical to the original assembly.
# fuzzy_match_percent: objdiff's overall similarity, crediting near-matches too.
# complete_code: code in units built from source and linked into the ROM.
SERIES = [
    ("matched_code", "Matched code", "#2a78d6", "#3987e5"),
    ("fuzzy_match_percent", "Overall accuracy", "#eb6834", "#d95926"),
    ("complete_code", "Linked code", "#1baf7a", "#199e70"),
]


def image_code() -> int:
    """Bytes of every module's code sections (the section lines at the top of its delinks.txt with kind:code)."""
    total = 0
    for module in modules():
        delinks = module_paths(module)[0] / "delinks.txt"
        if not delinks.is_file():
            continue
        for line in delinks.read_text().splitlines():
            if line.strip() and not line[0].isspace():
                break  # the first unit: the section list is over
            f = dict(w.split(":", 1) for w in line.split()[1:] if ":" in w)
            if f.get("kind") == "code":
                total += int(f["end"], 16) - int(f["start"], 16)
    return total


def read_report() -> dict:
    path = ROOT / "build" / VERSION / "report.json"
    if not path.is_file():
        sys.exit(f"{path} missing; run `ninja report` first")
    m = json.loads(path.read_text())["measures"]
    row = {k: int(m.get(k, 0)) for k in FIELDS[1:-1]}
    row["fuzzy_match_percent"] = round(float(m.get("fuzzy_match_percent", 0)), 3)
    return row


def read_history() -> list[dict]:
    if not HISTORY.is_file():
        return []
    with HISTORY.open() as f:
        return [{k: v if k == "date" else float(v) if k == "fuzzy_match_percent" else int(v)
                 for k, v in row.items()} for row in csv.DictReader(f)]


def same(a: dict, b: dict) -> bool:
    return all(a[k] == b[k] for k in FIELDS[1:])


IMAGE_CODE = image_code()


def pct(row: dict, key: str) -> float:
    """A share of the fixed code size. objdiff's fuzzy percentage is over its own total, so it is turned back into
    credited bytes first (bytes without a symbol carry no credit either way)."""
    if key == "fuzzy_match_percent":
        return row[key] * row["total_code"] / IMAGE_CODE if IMAGE_CODE else 0.0
    return 100 * row[key] / IMAGE_CODE if IMAGE_CODE else 0.0


def nice_ceiling(v: float) -> float:
    for c in (1, 2, 5, 10, 20, 25, 50, 75, 100):
        if v <= c:
            return c
    return 100


def _theme_css(light: bool) -> str:
    surface, text, muted, grid = ("#fcfcfb", "#52514e", "#898781", "#e1e0d9") if light else \
                                 ("#1a1a19", "#c3c2b7", "#898781", "#2c2c2a")
    css = f".bg{{fill:{surface}}}.grid{{stroke:{grid}}}.muted{{fill:{muted}}}.lbl{{fill:{text}}}"
    for i, (_, _, lc, dc) in enumerate(SERIES):
        c = lc if light else dc
        css += f".ln{i}{{stroke:{c}}}.dot{i}{{fill:{c};stroke:{surface}}}"
    return css


BREAK_GAP = 3600  # seconds; longer pauses between points are collapsed
BREAK_WIDTH = 1800  # seconds of x axis a collapsed pause takes up


def active_times(stamps: list[float]) -> tuple[list[float], list[int]]:
    """Maps timestamps onto working time: a pause longer than BREAK_GAP counts as BREAK_WIDTH, so days without
    work don't stretch the x axis. Also returns the indices of points that follow such a break."""
    times, breaks = [0.0], []
    for i in range(1, len(stamps)):
        gap = stamps[i] - stamps[i - 1]
        if gap > BREAK_GAP:
            gap = BREAK_WIDTH
            breaks.append(i)
        times.append(times[-1] + gap)
    return times, breaks


def render_svg(rows: list[dict]) -> str:
    W, H = 720, 300
    L, R, T, B = 48, 176, 24, 36
    pw, ph = W - L - R, H - T - B
    dates = [datetime.fromisoformat(r["date"]) for r in rows]
    times, breaks = active_times([d.timestamp() for d in dates])
    t0, t1 = times[0], times[-1]
    ymax = nice_ceiling(max(pct(r, k) for r in rows for k, *_ in SERIES))

    def x(t):
        return L + (pw / 2 if t1 == t0 else (t - t0) / (t1 - t0) * pw)

    def y(v):
        return T + ph - v / ymax * ph

    out = [
        f'<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 {W} {H}" width="{W}" height="{H}" '
        f'role="img" aria-label="Decompilation progress over time ({LABEL})">',
        "<style>",
        _theme_css(light=True),
        "@media (prefers-color-scheme: dark){" + _theme_css(light=False) + "}",
        "text{font:12px -apple-system,BlinkMacSystemFont,'Segoe UI',Helvetica,Arial,sans-serif}",
        "</style>",
        f'<rect class="bg" width="{W}" height="{H}" rx="6"/>',
    ]
    for i in range(5):
        v = ymax * i / 4
        out.append(f'<line x1="{L}" x2="{L + pw}" y1="{y(v):.1f}" y2="{y(v):.1f}" class="grid" stroke-width="1"/>')
        out.append(f'<text x="{L - 8}" y="{y(v) + 4:.1f}" class="muted" text-anchor="end">{v:g}%</text>')
    # Collapsed pauses: a dashed rule midway through the gap.
    for i in breaks:
        bx = (x(times[i - 1]) + x(times[i])) / 2
        out.append(f'<line x1="{bx:.1f}" x2="{bx:.1f}" y1="{T}" y2="{T + ph}" class="grid" stroke-width="1" '
                   f'stroke-dasharray="3 3"/>')
    # Date labels (local time) at the start of each work session that begins a new day. The first and the latest
    # day always show; a day in between is skipped if its label would overlap one already placed.
    starts, seen = [], set()
    for i in [0, *breaks]:
        day = dates[i].astimezone().date()
        if day not in seen:
            seen.add(day)
            starts.append((i, day))
    # Only the first label carries the year; the rest are month-day, which keeps them narrow enough to fit.
    spans = []
    for k, (i, day) in enumerate(starts):
        text, w = (f"{day:%Y-%m-%d}", 72) if k == 0 else (f"{day:%m-%d}", 36)
        lx = x(times[i])
        anchor = "start" if lx < L + w / 2 else "end" if lx > L + pw - w / 2 else "middle"
        left = lx if anchor == "start" else lx - w if anchor == "end" else lx - w / 2
        spans.append((left, left + w, lx, anchor, text, k in (0, len(starts) - 1)))
    placed = [sp for sp in spans if sp[5]]
    for sp in spans:
        if not sp[5] and all(sp[1] + 8 <= q[0] or sp[0] >= q[1] + 8 for q in placed):
            placed.append(sp)
    for _, _, lx, anchor, text, _ in sorted(placed):
        out.append(f'<text class="muted" x="{lx:.1f}" y="{H - 12}" text-anchor="{anchor}">{text}</text>')

    # Lines first, then end dots with surface rings, then direct labels (nudged apart).
    ends = []
    for i, (key, label, *_) in enumerate(SERIES):
        pts = [(x(t), y(pct(r, key))) for t, r in zip(times, rows)]
        if len(pts) > 1:
            d = " ".join(f"{px:.1f},{py:.1f}" for px, py in pts)
            out.append(f'<polyline points="{d}" fill="none" class="ln{i}" stroke-width="2" '
                       f'stroke-linejoin="round" stroke-linecap="round"/>')
        ends.append([pts[-1][1], i, label, pct(rows[-1], key), pts[-1][0]])
    for ey, i, _, _, ex in ends:
        out.append(f'<circle cx="{ex:.1f}" cy="{ey:.1f}" r="4" class="dot{i}" stroke-width="2"/>')
    # Stack labels upward from the lowest so they never collide or drop below the plot.
    ends.sort(reverse=True)
    ends[0][0] = min(ends[0][0], T + ph)
    for j in range(1, len(ends)):
        ends[j][0] = min(ends[j][0], ends[j - 1][0] - 16)
    # If the stack ran above the plot (all series near the top), move it down so the top label is not clipped.
    if ends[-1][0] < T:
        for e in ends:
            e[0] += T - ends[-1][0]
    for ly, i, label, v, _ in ends:
        out.append(f'<line x1="{L + pw + 10}" x2="{L + pw + 22}" y1="{ly:.1f}" y2="{ly:.1f}" class="ln{i}" stroke-width="2"/>')
        out.append(f'<text class="lbl" x="{L + pw + 28}" y="{ly + 4:.1f}">{label} {v:.2f}%</text>')
    out.append("</svg>")
    return "\n".join(out) + "\n"


TILE_FUNCTIONS = 64  # functions per treemap tile, in address order


def function_states() -> dict[str, list[tuple[int, str]]]:
    """Per module, (size, state) of every function in address order; state is 'linked' (in a complete unit),
    'matched' (100% in objdiff) or 'todo'."""
    report = json.loads((ROOT / "build" / VERSION / "report.json").read_text())
    state = {}
    for unit in report["units"]:
        linked = unit.get("metadata", {}).get("complete", False)
        for fn in unit.get("functions", []):
            if fn.get("fuzzy_match_percent", 0) >= 100:
                state[fn["name"]] = "linked" if linked else "matched"
    out = {}
    for module in modules():
        path = module_paths(module)[0] / "symbols.txt"
        if not path.is_file():
            continue
        fns = []
        for line in path.read_text().splitlines():
            m = re.match(r"(\S+) kind:function\(\w+,size=0x([0-9a-f]+)\) addr:0x([0-9a-f]+)", line)
            if m:
                fns.append((int(m.group(3), 16), int(m.group(2), 16), state.get(m.group(1), "todo")))
        if fns:
            out[module] = [(size, st) for _, size, st in sorted(fns)]
    return out


def squarify(weights: list[float], x: float, y: float, w: float, h: float) -> list[tuple[float, float, float, float]]:
    """Squarified treemap: rectangles for the weights, in order, filling (x, y, w, h)."""
    total = sum(weights)
    areas = [v * w * h / total for v in weights] if total else [0.0] * len(weights)
    rects, i = [], 0

    def worst(row, side):
        s = sum(row)
        return max(side * side * max(row) / (s * s), s * s / (side * side * min(row))) if min(row) > 0 else 1e9

    while i < len(areas):
        side = min(w, h)
        row = [areas[i]]
        i += 1
        while i < len(areas) and side > 0 and worst(row + [areas[i]], side) <= worst(row, side):
            row.append(areas[i])
            i += 1
        thick = sum(row) / side if side > 0 else 0
        pos = y if w >= h else x
        for a in row:
            length = a / thick if thick else 0
            rects.append((x, pos, thick, length) if w >= h else (pos, y, length, thick))
            pos += length
        if w >= h:
            x, w = x + thick, w - thick
        else:
            y, h = y + thick, h - thick
    return rects


def render_treemap() -> str:
    """Every function of the ROM as area: one box per module, tiles of TILE_FUNCTIONS functions in address order,
    each filled left to right by its linked and matched share."""
    states = function_states()
    W, H, T = 720, 420, 56
    colors = {k: (lc, dc) for k, _, lc, dc in SERIES}
    light = ".bg{fill:#fcfcfb}.lbl{fill:#52514e}.muted{fill:#898781}.todo{fill:#e1e0d9}.gap{stroke:#fcfcfb}" + \
        f".matched{{fill:{colors['matched_code'][0]}}}.linked{{fill:{colors['complete_code'][0]}}}"
    dark = ".bg{fill:#1a1a19}.lbl{fill:#c3c2b7}.muted{fill:#898781}.todo{fill:#2c2c2a}.gap{stroke:#1a1a19}" + \
        f".matched{{fill:{colors['matched_code'][1]}}}.linked{{fill:{colors['complete_code'][1]}}}"
    out = [
        f'<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 {W} {H}" width="{W}" height="{H}" '
        f'role="img" aria-label="Matched and linked code by module ({LABEL})">',
        f"<style>{light}@media (prefers-color-scheme: dark){{{dark}}}"
        "text{font:12px -apple-system,BlinkMacSystemFont,'Segoe UI',Helvetica,Arial,sans-serif}"
        ".head{font-weight:600}</style>",
        f'<rect class="bg" width="{W}" height="{H}" rx="6"/>',
        f'<text class="lbl head" x="16" y="24">{LABEL}: function bytes by module</text>',
        f'<text class="muted" x="{W - 16}" y="24" text-anchor="end">area: function size; '
        f'% after a module: its function bytes matched</text>',
    ]
    lx = 16
    for key, label in (("linked", "Linked"), ("matched", "Matched, not linked yet"), ("todo", "Not matched")):
        out.append(f'<rect class="{key}" x="{lx}" y="36" width="10" height="10" rx="2"/>')
        out.append(f'<text class="muted" x="{lx + 15}" y="45">{label}</text>')
        lx += 15 + 6.1 * len(label) + 18
    names = sorted(states, key=lambda m: -sum(s for s, _ in states[m]))
    boxes = squarify([sum(s for s, _ in states[m]) for m in names], 16, T, W - 32, H - T - 16)
    for name, (bx, by, bw, bh) in zip(names, boxes):
        fns = states[name]
        tiles = [fns[i:i + TILE_FUNCTIONS] for i in range(0, len(fns), TILE_FUNCTIONS)]
        head = 18 if bh > 40 and bw > 30 else 0
        for tile, (tx, ty, tw, th) in zip(tiles, squarify([sum(s for s, _ in t) for t in tiles],
                                                          bx + 2, by + 2 + head, bw - 4, bh - 4 - head)):
            n = sum(s for s, _ in tile) or 1
            out.append(f'<rect class="todo gap" x="{tx:.1f}" y="{ty:.1f}" width="{tw:.1f}" height="{th:.1f}" '
                       f'stroke-width="2"/>')
            fx = tx
            for key in ("linked", "matched"):
                part = tw * sum(s for s, st in tile if st == key) / n
                if part > 0:
                    out.append(f'<rect class="{key}" x="{fx:.1f}" y="{ty + 1:.1f}" width="{part:.2f}" '
                               f'height="{max(th - 2, 0):.1f}"/>')
                    fx += part
        if head:
            m = sum(s for s, st in fns if st != "todo")
            n = sum(s for s, _ in fns)
            label = f"{name} {100 * m / n:.1f}%" if bw > 7 * len(name) + 48 else name
            out.append(f'<text class="lbl" x="{bx + 4:.1f}" y="{by + 15:.1f}">{label}</text>')
    out.append("</svg>")
    return "\n".join(out) + "\n"


def readme_section(rows: list[dict]) -> str:
    r = rows[-1]
    fn = f"{r['matched_functions']:,} / {r['total_functions']:,}"
    rel = f"progress/{VERSION}"
    return "\n".join([
        START,
        f"![{LABEL}: function bytes by module]({rel}/treemap.svg)",
        "",
        "| Measure | Progress |",
        "|---|---|",
        f"| Matched code | {pct(r, 'matched_code'):.2f}% ({r['matched_code']:,} / {IMAGE_CODE:,} bytes) |",
        f"| Linked code (complete units) | {pct(r, 'complete_code'):.2f}% ({r['complete_code']:,} bytes) |",
        f"| Overall accuracy (fuzzy) | {pct(r, 'fuzzy_match_percent'):.2f}% |",
        f"| Matched functions | {fn} |",
        "",
        *([("All code is linked from this repository's source and the ROM matches byte for byte. See "
            "[docs/decompiling.md](docs/decompiling.md) for functions objdiff scores below 100% with identical "
            "code."), ""] if r["complete_code"] == IMAGE_CODE else []),
        f"_Last updated {r['date'][:10]}. Over time: [graph]({rel}/progress.svg), "
        f"[`{rel}/history.csv`]({rel}/history.csv)._",
        END,
    ])


def main() -> None:
    p = argparse.ArgumentParser()
    p.add_argument("cmd", choices=["update", "check"])
    a = p.parse_args()

    built = configured_version()
    if built and built != VERSION:
        sys.exit(f"DECOMP_VERSION is {VERSION} but build.ninja builds {built}: unset it, or configure {VERSION}.")
    cur = read_report()
    rows = read_history()

    if a.cmd == "check":
        if not rows or not same(rows[-1], cur):
            sys.exit(f"{LABEL} progress is out of date: run `ninja report && python3 tools/progress.py update` "
                     "and commit.")
        return

    if not rows or not same(rows[-1], cur):
        rows.append({"date": datetime.now(timezone.utc).isoformat(timespec="seconds"), **cur})
        HISTORY.parent.mkdir(exist_ok=True)
        with HISTORY.open("w", newline="") as f:
            wr = csv.DictWriter(f, FIELDS)
            wr.writeheader()
            wr.writerows(rows)
    SVG.write_text(render_svg(rows))
    TREEMAP.write_text(render_treemap())

    text = README.read_text()
    if START in text and END in text:
        text = text[:text.index(START)] + readme_section(rows) + text[text.index(END) + len(END):]
    else:
        text = text.rstrip() + f"\n\n## Progress: {LABEL}\n" + readme_section(rows) + "\n"
    README.write_text(text)
    print(f"{LABEL}: matched {pct(rows[-1], 'matched_code'):.2f}%, "
          f"overall {pct(rows[-1], 'fuzzy_match_percent'):.2f}%, "
          f"linked {pct(rows[-1], 'complete_code'):.2f}% ({len(rows)} points)")


if __name__ == "__main__":
    main()
