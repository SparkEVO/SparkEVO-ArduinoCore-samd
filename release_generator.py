import tarfile
import os
import hashlib
import mmap
import argparse

parser = argparse.ArgumentParser("SparkEVO Arduino Package generator")
parser.add_argument("version", help="Package version")
args = parser.parse_args()

def sha256sum(filename):
    h  = hashlib.sha256()
    b  = bytearray(128*1024)
    mv = memoryview(b)
    with open(filename, 'rb', buffering=0) as f:
        for n in iter(lambda : f.readinto(mv), 0):
            h.update(mv[:n])
    return h.hexdigest()


version = args.version

# update platform.txt
platform = open("platform.txt.source", "rt");
platform_str = platform.read()
platform_str = platform_str.replace('[[VERSION]]', str(version))
platform.close()
platform = open("platform.txt", "wt");
platform.write(platform_str)
platform.close()

tarname = "SparkEVO-ArduinoCore-samd-" + version + ".tar.gz"
if os.path.exists(tarname):
    os.remove(tarname)

with tarfile.open(tarname,"w:gz", dereference=True, format=tarfile.GNU_FORMAT) as tar:
    files = os.listdir(".")
    for file in files:
        if file.startswith(".git") or file.endswith(".tar.gz") or file == "ArduinoCore-API" or file == ".":
            continue
        tar.add(file, arcname="SparkEVO-ArduinoCore-samd/" + os.path.basename(file), recursive=True)
    # add API module
    tar.add("ArduinoCore-API/api", arcname="SparkEVO-ArduinoCore-samd/cores/arduino/api", recursive=True)

print()
print("\"name\": \"SparkEVO SAMD Boards\",")
print("\"architecture\": \"samd\",")
print("\"version\": \"" + version + "\",")
print("\"category\": \"SparkEVO\",")
print("\"help\": {\"online\": \"https://sparkevo.racing/\"},")
print("\"url\": \"https://sparkevo.racing/resources/internal/arduino-board-index/boards/" + tarname + "\",")
print("\"archiveFileName\": \"" + tarname + "\",")
print("\"checksum\": \"SHA-256:" + sha256sum(tarname) + "\",")
print("\"size\": \"" + str(os.path.getsize(tarname)) + "\",")
print()