#!/usr/bin/env python3
"""Generate a verified-byte weighted, hierarchical Mario Kart DS progress SVG.
Uses reports/progress-measured.json in repository root if available.
"""
import argparse, json, math
from pathlib import Path
from xml.sax.saxutils import escape

SNAPSHOT = {
'arm9': [[79818,280,512],[81184,348,512],[80666,912,512],[93736,648,512],[78788,80,512],[128034,614,512],[90072,672,512],[89578,398,512],[115656,1376,512],[70340,1148,512],[104680,464,512],[99194,488,512],[80434,362,512],[80427,220,512],[111178,232,512],[13323,54,127]],
'arm9_ov000': [[59225,116,512],[72108,0,512],[43164,0,357]],
'arm9_ov001': [[54180,280,512],[45830,0,332]],
'arm9_ov003': [[54727,36,512],[40242,0,512]],
'arm7': [[57740,0,512],[89352,0,470]]}


def squarify(values, x, y, w, h):
    """Squarified treemap of positive weights, preserving item order."""
    total = sum(values)
    if not total: return [(x,y,0,0)]*len(values)
    areas=[v*w*h/total for v in values]
    result=[]; i=0
    while i < len(areas):
        side=min(w,h)
        if side<=0: result.extend([(x,y,0,0)]*(len(areas)-i));break
        row=[areas[i]];i+=1
        def score(seq):
            s=sum(seq)
            return max(side*side*max(seq)/(s*s), s*s/(side*side*min(seq))) if min(seq)>0 else float('inf')
        while i<len(areas) and score(row+[areas[i]])<=score(row):
            row.append(areas[i]);i+=1
        rsum=sum(row)
        if w>=h:
            rw=rsum/h
            pos=y
            for a in row:
                rh=a/rw if rw else 0
                result.append((x,pos,rw,rh));pos+=rh
            x+=rw;w-=rw
        else:
            rh=rsum/w
            pos=x
            for a in row:
                rw=a/rh if rh else 0
                result.append((pos,y,rw,rh));pos+=rw
            y+=rh;h-=rh
    return result


def main():
    p=argparse.ArgumentParser()
    p.add_argument('--input', default='reports/progress-measured.json')
    p.add_argument('--output', default='docs/progress-treemap.svg')
    a=p.parse_args()
    source=Path(a.input)
    checkpoint_label='snapshot'
    if source.exists():
        original=json.loads(source.read_text(encoding='utf-8'))
        checkpoint_label='checkpoint '+str(original['checkpoint'])
        modules={}
        for m in original['modules']:
            funcs=m['functions'];groups=[]
            for i in range(0,len(funcs),64):
                part=funcs[i:i+64]
                groups.append([sum(int(f[1]) for f in part),sum(int(f[1]) for f in part if f[2]==0),len(part)])
            modules[m['name']]=groups
    else:
        modules=SNAPSHOT
    total=sum(v[0] for m in modules.values() for v in m)
    exact=sum(v[1] for m in modules.values() for v in m)
    functions=sum(v[2] for m in modules.values() for v in m)
    W,H=1200,740
    pieces=[f'<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 {W} {H}" width="{W}" height="{H}" role="img" aria-label="Mario Kart DS local decompilation progress treemap">',
      '<rect width="1200" height="740" rx="14" fill="#0d1117"/>',
      '<style>text{font-family:Inter,Segoe UI,Arial,sans-serif}.heading{fill:#e6edf3;font-weight:700}.light{fill:#9da7b3}.module{fill:#e6edf3;font-weight:700}.tile{fill:#8ea3b9;font-size:10px;pointer-events:none}</style>',
      '<text x="28" y="44" class="heading" font-size="26">Mario Kart DS · Decompilation progress</text>',
      f'<text x="28" y="70" class="light" font-size="14">EUR {checkpoint_label} · {exact:,} / {total:,} verified local byte-exact code bytes · {exact/total*100:.4f}%</text>',
      '<rect x="28" y="91" width="13" height="13" fill="#2ea043"/><text x="47" y="103" class="light" font-size="12">Byte-exact locally</text>',
      '<rect x="206" y="91" width="13" height="13" fill="#303f52"/><text x="225" y="103" class="light" font-size="12">Not byte-exact / unverified</text>',
      '<text x="1170" y="103" text-anchor="end" class="light" font-size="12">Tile area ∝ identified function bytes</text>']
    labels=list(modules)
    weights=[sum(g[0] for g in modules[k]) for k in labels]
    layout=squarify(weights,24,120,1152,557)
    for idx,(name,(mx,my,mw,mh)) in enumerate(zip(labels,layout)):
        if min(mw,mh)<20:continue
        module_bytes=weights[idx]; module_exact=sum(g[1] for g in modules[name]);percent=module_exact/module_bytes*100
        pieces.append(f'<rect x="{mx:.2f}" y="{my:.2f}" width="{mw:.2f}" height="{mh:.2f}" rx="3" fill="#15202c" stroke="#5b7187" stroke-width="1.7"/>')
        tx,ty=mx+6,my+26
        tw,th=mw-12,mh-32
        if tw>0 and th>0:
            groups=modules[name]
            for j,((n,match,count),(x,y,w,h)) in enumerate(zip(groups,squarify([g[0] for g in groups],tx,ty,tw,th))):
                pieces.append(f'<rect x="{x:.2f}" y="{y:.2f}" width="{w:.2f}" height="{h:.2f}" fill="#303f52" stroke="#101b26" stroke-width="1"/>')
                # Show verified fraction by area within each tile; small green squares remain visually honest.
                if match:
                    frac=match/n
                    gw=w*frac
                    pieces.append(f'<rect x="{x:.2f}" y="{y:.2f}" width="{gw:.3f}" height="{h:.2f}" fill="#2ea043"/>')
                if w>56 and h>22:
                    pieces.append(f'<text x="{x+5:.1f}" y="{y+15:.1f}" class="tile">{escape(name)}/{j:03d}</text>')
                pieces.append(f'<title>{escape(name)}/{j:03d} · {n:,} bytes · {match:,} verified ({match/n*100:.3f}%) · {count} functions</title>')
        if mw>100:
            pieces.append(f'<text x="{mx+7:.1f}" y="{my+18:.1f}" class="module" font-size="13">{escape(name.upper())} · {percent:.3f}%</text>')
    pieces += [f'<text x="28" y="707" class="light" font-size="12">{functions:,} identified functions · Colored bytes are local verified matches; compilable nonmatching C is not counted as matching.</text>',
      '<text x="28" y="725" class="light" font-size="12">This is an inventory-weighted local comparison, NOT whole-ROM completion. No full-ROM build is verified.</text>', '</svg>']
    dst=Path(a.output);dst.parent.mkdir(parents=True,exist_ok=True);dst.write_text('\n'.join(pieces)+'\n',encoding='utf-8')
    print(f'Wrote {dst}: {len(labels)} modules, {sum(len(m) for m in modules.values())} units, {exact}/{total} matching bytes')

if __name__=='__main__':main()
