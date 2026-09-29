#Claude generated file to generate set WROM values.

import numpy as np

N = 16

k = np.arange(N // 2)
w = np.exp(-2j * np.pi * k / N)

# Q1.15: scale by 2^15, saturate (+1.0 isn't representable), two's complement
q15 = lambda x: np.clip(np.round(x * 32768), -32768, 32767).astype(int) & 0xFFFF

np.savetxt("twiddleRE.hex", q15(w.real), fmt="%04X")
np.savetxt("twiddleIM.hex", q15(w.imag), fmt="%04X")
