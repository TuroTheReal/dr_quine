#!/usr/bin/env python3
# Grace - Writes its source to Grace_kid.py
# Comment: This is a self-replicating program

FILE = "Grace_kid.py"
CODE = '#!/usr/bin/env python3\n# Grace - Writes its source to Grace_kid.py\n# Comment: This is a self-replicating program\n\nFILE = "Grace_kid.py"\nCODE = {!r}\n\nwith open(FILE, "w") as f:\n    f.write(CODE.format(CODE))\n'

with open(FILE, "w") as f:
    f.write(CODE.format(CODE))
