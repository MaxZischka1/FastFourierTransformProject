#Claude generated file to generate possible inputs. Bounded random variable test.
import argparse
import numpy as np

# Q1.15: scale by 2^15, saturate (+1.0 isn't representable), two's complement
q15 = lambda x: np.clip(np.round(x * 32768), -32768, 32767).astype(int) & 0xFFFF

p = argparse.ArgumentParser(description="Generate Q1.15 hex samples of sin/cos for the FFT testbench")
p.add_argument("sinFreq", type=float, help="sine frequency in Hz (real part)")
p.add_argument("cosFreq", type=float, help="cosine frequency in Hz (imaginary part)")
p.add_argument("-n", "--samples", type=int, default=16, help="number of samples (default 16)")
p.add_argument("--fs", type=float, default=40.0, help="sample rate in Hz (default 40)")
p.add_argument("--amp", type=float, default=1.0, help="amplitude, 0..1 full scale (default 1.0)")
args = p.parse_args()

t = np.arange(args.samples) / args.fs
re = args.amp * np.sin(2 * np.pi * args.sinFreq * t)
im = args.amp * np.cos(2 * np.pi * args.cosFreq * t)

np.savetxt("inputsRE.hex", q15(re), fmt="%04X")
np.savetxt("inputsIM.hex", q15(im), fmt="%04X")

print(f"{args.samples} samples @ {args.fs} Hz  ->  inputsRE.hex (sin {args.sinFreq} Hz), inputsIM.hex (cos {args.cosFreq} Hz)")
for i, (a, b) in enumerate(zip(re, im)):
    print(f"  {i:2d}  t={t[i]:.4f}  re={a:+.4f} ({q15(a):04X})  im={b:+.4f} ({q15(b):04X})")
