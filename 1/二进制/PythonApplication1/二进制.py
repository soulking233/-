import struct
import os
if __name__ == '__main__':
    filepath='C:\\Users\\86176\\Desktop\\项目一（二版）\\二进制\\e1.bin'
    desktop_path = "C:\\Users\\86176\\Desktop\\项目一（二版）\\二进制\\" 
    full_path = desktop_path + 'o1' + '.txt'
    file = open(full_path, 'w')
    binfile = open(filepath, 'rb') #打开二进制文件
    size = os.path.getsize(filepath) #获得文件大小
    for i in range(size):
        data = binfile.read(1)
        num = struct.unpack('B', data)
        file.write(str(num[0]))
    binfile.close()

