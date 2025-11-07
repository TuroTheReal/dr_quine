#!/usr/bin/env python3
# Outside comment

def my_function():
    """Fonction supplémentaire requise"""
    pass

def main():
    # Inside comment
    code = '#!/usr/bin/env python3\n# Outside comment\n\ndef my_function():\n    """Fonction supplémentaire requise"""\n    pass\n\ndef main():\n    # Inside comment\n    code = {!r}\n    print(code.format(code), end="")\n    my_function()\n\nif __name__ == "__main__":\n    main()'
    print(code.format(code), end="")
    my_function()

if __name__ == "__main__":
    main()