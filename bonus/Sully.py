#!/usr/bin/env python3
import os
import sys
import subprocess

def main():
    i = 5
    code = '#!/usr/bin/env python3\nimport os\nimport sys\nimport subprocess\n\ndef main():\n    i = {}\n    code = {!r}\n    if i >= 0:\n        if os.path.exists("Sully_5.py"):\n            i -= 1\n        filename = f"Sully_{{i}}.py"\n        with open(filename, "w") as f:\n            f.write(code.format(i, code))\n        if i > 0:\n            subprocess.run([sys.executable, filename])\n\nif __name__ == "__main__":\n    main()\n'
    if i >= 0:
        if os.path.exists("Sully_5.py"):
            i -= 1
        filename = f"Sully_{i}.py"
        with open(filename, "w") as f:
            f.write(code.format(i, code))
        if i > 0:
            subprocess.run([sys.executable, filename])

if __name__ == "__main__":
    main()
