"""Report a fixed character-selection controller scope, never expand for matches."""
from pathlib import Path
import csv,json
ROOT=Path(__file__).resolve().parents[1]
ROLES={0x2025f90:'Controllo risorse grafiche',0x2026058:'Configurazione blending/display',0x20260e4:'Uscita e distruzione heap',0x2026120:'Controller principale: input e fasi',0x2026910:'Inizializzazione menu',0x2027084:'Aggiornamento parametri delle icone',0x20270d0:'Controllo blocco interazione',0x20270fc:'Dispatcher griglia e cambio selezione',0x2027188:'Dispatcher aggiornamento icone',0x202719c:'Evidenziazione icona',0x20271e8:'Aggiornamento celle selezionate',0x202721c:'Aggiornamento grafica associata',0x202728c:'Aggiornamento parametro grafico',0x20272c0:'Aggiornamento coordinate grafiche',0x20272ec:'Rimozione evidenziazione',0x202734c:'Visibilità icone',0x20273c0:'Avvio transizione di uscita',0x2027424:'Inoltro azione condizionale',0x2027448:'Griglia con 12 personaggi',0x2027648:'Griglia con 11 personaggi',0x2027850:'Griglia con 10 personaggi',0x2027a58:'Griglia con 9 personaggi',0x2027be0:'Griglia con 8 personaggi'}
NAV={0x20270fc,0x2027448,0x2027648,0x2027850,0x2027a58,0x2027be0}
def main():
    proofs={int(r['address'],16):r for p in ['local-byte-exact.tsv','local-linked-byte-exact.tsv'] for r in csv.DictReader((ROOT/'verification'/p).open(),delimiter='\t') if r['module']=='arm9'}
    index={int(r['address'],16):r for r in csv.DictReader((ROOT/'baseline/pseudocode/arm9/index.tsv').open(),delimiter='\t')}
    rows=[]
    for address,role in ROLES.items():
        row=index[address];proof=proofs.get(address)
        rows.append(dict(address=f'0x{address:08x}',name=row['name'],role=role,inventory_bytes=int(row['bytes']),local_byte_exact=proof is not None,subgroup='navigation' if address in NAV else 'controller',source=f"src/arm9/{address:08x}_{row['name']}.c"))
    result={'scope':'Fixed 23-function controller block, 02025f90 through 02027be0; shared UI/SDK dependencies outside scope. Roles inferred from static calls, resources and field accesses, not original names. This scope is not the whole menu dependency closure.',
            'functions':rows,'exact_functions':sum(r['local_byte_exact'] for r in rows),'total_functions':len(rows),'inventory_bytes':sum(r['inventory_bytes'] for r in rows),'exact_inventory_bytes':sum(r['inventory_bytes'] for r in rows if r['local_byte_exact']),
            'navigation_complete_local_matching':all(a in proofs for a in NAV),'full_menu_complete':False,
            'entry_evidence':[{'source':'src/arm9/020cb6c0_func_020cb6c0.c','detail':'States 5,8,15,21 call Maybe_select_character_s; adjacent states call the kart-selection initializer.'},{'source':'src/arm9_ov000/02184950_FUN_02184950.c','detail':'Additional entry calls the same initializer in mode 2.'}],
            'field_evidence':{'0x60':'Current cursor; changed by directional input in 02026120.','0x64':'Previous cursor, passed to 020270fc before/after movement; not a key bitmask.','0x7c':'Number of visible characters; dispatcher selects 8/9/10/11/12.','0x84..0x8a':'Signed destinations for key masks 0x40,0x80,0x10,0x20; -1 prevents movement.'}}
    (ROOT/'verification/character-select-family.json').write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps({k:result[k] for k in ['exact_functions','total_functions','exact_inventory_bytes','inventory_bytes','navigation_complete_local_matching']}))
if __name__=='__main__':main()
