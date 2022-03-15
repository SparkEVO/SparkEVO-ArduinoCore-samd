import tarfile
import os
import hashlib
import mmap

def sha256sum(filename):
    h  = hashlib.sha256()
    b  = bytearray(128*1024)
    mv = memoryview(b)
    with open(filename, 'rb', buffering=0) as f:
        for n in iter(lambda : f.readinto(mv), 0):
            h.update(mv[:n])
    return h.hexdigest()


version = "1.0.0"
tarname = "SparkEVO-ArduinoCore-samd-" + version + ".tar.gz"
if os.path.exists(tarname):
    os.remove(tarname)

with tarfile.open(tarname,"w:gz", format=tarfile.GNU_FORMAT) as tar:
    files = os.listdir(".")
    for file in files:
        if file.startswith(".git") or file.endswith(".tar.gz") or file == ".":
            continue
        tar.add(file, arcname="SparkEVO-ArduinoCore-samd/" + os.path.basename(file), recursive=True)
    

print("\"checksum\": \"SHA-256:" + sha256sum(tarname) + "\",")
print("\"size\": \"" + str(os.path.getsize(tarname)) + "\",")