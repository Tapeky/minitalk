
import subprocess
import time
import random

caracteres_unicode = [chr(random.randint(0x1F600, 0x1F64F)) for _ in range(50)]

chaine_unicode = ''.join(caracteres_unicode)

print(chaine_unicode)

time.sleep(1)

subprocess.run(["./client_bonus", "727906", chaine_unicode])

time.sleep(1)
