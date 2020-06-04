import subprocess
import os

commond = "pip3 list --outdated"

print('Getting information of outdated modules, please wait...')
print()

outdatelist = subprocess.Popen(commond, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True).stdout.readlines()
updatelist = []

for i in outdatelist:
    i = str(i, encoding='utf-8')
    print(i, end='')
    i = i[:i.find(' ')]
    updatelist.append(i)

c = 1
total = len(updatelist)
if updatelist :
    for j in updatelist :
        print('\n', c, '/', total, ' upgrading ', j, sep='')
        c += 1
        tempcmd = "pip3 install --upgrade -i https://mirrors.aliyun.com/pypi/simple " + j
        os.system(tempcmd)
    print('All modules have been updated.')
else :
    print('All modules have the latest version.')

