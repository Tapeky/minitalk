import time
import subprocess

chaine = "abc" * 25000

print(chaine)

time.sleep(1)

subprocess.run(["./client_bonus", "727191", chaine])

time.sleep(1)
