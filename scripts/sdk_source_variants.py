"""Explicit source hypotheses; acceptance still requires complete byte identity."""
import re
from pathlib import Path


def source_variant(text, transformations):
    for transformation in transformations:
        if transformation == 'omit_simple_null_returns':
            text = re.sub(r'\bif\s*\(\s*!\s*[A-Za-z_]\w*\s*\)\s*(?:\{\s*return\s+(?:NULL|FALSE|0|-1)\s*;\s*\}|return\s+(?:NULL|FALSE|0|-1)\s*;)', '', text)
        elif transformation in ['unchecked_g3d_dict_accessors', 'unchecked_g3d_dict_accessors_all_units']:
            header = Path(__file__).resolve().parents[1] / 'vendor/nitrosystem/include/nnsys/g3d/binres/res_struct_accessor_inline.h'
            inline = header.read_text()
            pattern = r'if \(dict != NULL && idx < dict->numEntry\) \{(.*?)\} else \{\s*return NULL;\s*\}'
            inline, count = re.subn(pattern, r'\1', inline, flags=re.S)
            if count != 2:
                raise ValueError('Unexpected dictionary accessor header')
            # Keep the pinned headers untouched; embed the explicit historical
            # hypothesis and suppress only the original inline definitions.
            include = '#include <nnsys/g3d/binres/res_struct_accessor.h>'
            inline = inline.replace('#ifndef NNSG3D_BINRES_RES_STRUCT_ACCESSOR_INLINE_H_', '#if 1', 1)
            if transformation == 'unchecked_g3d_dict_accessors':
                if include not in text:
                    raise ValueError('Missing resource accessor include')
                text = '#define NNSG3D_BINRES_RES_STRUCT_ACCESSOR_INLINE_H_\n' + text.replace(include, include + '\n' + inline, 1)
            else:
                text = '#define NNSG3D_BINRES_RES_STRUCT_ACCESSOR_INLINE_H_\n' + include + '\n' + inline + '\n' + text
        else:
            raise ValueError('Unknown source transformation ' + transformation)
    return text
