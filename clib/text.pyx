import numpy as np

cimport ctext

def write_info(n):
    ctext.text_output(n)

def pyx_test_01():
    cdef double x[100000]
    cdef double out
    arr = np.array(range(100000), dtype=np.float64)
    x = [y for y in arr]
    for i in range(100000):
        out = out + x[i] * x[i]
    out = np.sqrt(out)
    return out

def pyx_test_02():
    arr = np.array(range(100000), dtype=np.float64)
    out = 0.0
    for i in range(100000):
        out = out + arr[i] * arr[i]
    out = np.sqrt(out)
    return out

