import json

with open('CoreKeeperWorld.json', 'r') as f:
    data = json.load(f)

def extract_m_code(data, m_codes):
    if isinstance(data, dict):
        for key, value in data.items():
            if key == "m_Code":
                m_codes.append(value)
            else:
                extract_m_code(value, m_codes)
    elif isinstance(data, list):
        for item in data:
            extract_m_code(item, m_codes)

m_codes = []
extract_m_code(data, m_codes)

assert len(m_codes) == 2

import base64

b = base64.b64decode(m_codes[0])
with open(f'CoreKeeperWorld.dxbc', 'wb') as f:
    f.write(b)

b = base64.b64decode(m_codes[1])
with open(f'CoreKeeperWorld.spv', 'wb') as f:
    f.write(b)