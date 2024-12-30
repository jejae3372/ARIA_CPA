import matplotlib.pyplot as plt
import struct
import os

points = 5830

def bytes_to_float(b):
    return struct.unpack('<f', b)[0]

def read_point(file, trace_num):
    points_list = []
    with open(file, 'rb') as file:
        file.seek(16 + trace_num * points * 4)    #Trace 번호만큼 이동
        for i in range(points):
            points_list.append(bytes_to_float(file.read(4)))
    return points_list
plt.figure(figsize= (40, 8))
pt_list = read_point('CTF-4-ARIA-trace.bin', 0)
plt.plot(pt_list)
plt.savefig('CTF_0_trace')
plt.show()
