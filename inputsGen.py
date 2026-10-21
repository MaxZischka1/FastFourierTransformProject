#Claude generated file to generate possible inputs. Bounded random variable test.
# `inputsGen.py` writes `inputsRE.hex` (sine, real) and `inputsIM.hex` (cosine, imaginary):
#     python3 inputsGen.py <sinFreq> <cosFreq> [-n 16] [--fs 40] [--amp 1.0] [-b 16] [--unsigned]
# Default is Q1.15 signed two's complement for the FFT testbenches.
# `-b 12 --unsigned` gives offset-binary ADC codes, what adcSpi parses over SPI.
import argparse
import numpy as np

p = argparse.ArgumentParser(description="Generate hex sin/cos samples for the FFT testbenches")
p.add_argument("sinFreq", type=float, help="sine frequency in Hz (real part)")
p.add_argument("cosFreq", type=float, help="cosine frequency in Hz (imaginary part)")
p.add_argument("-n", "--samples", type=int, default=16, help="number of samples (default 16)")
p.add_argument("--fs", type=float, default=40.0, help="sample rate in Hz (default 40)")
p.add_argument("--amp", type=float, default=1.0, help="amplitude, 0..1 full scale (default 1.0)")
p.add_argument("-b", "--bits", type=int, default=16, help="word width in bits, 4..16 (default 16)")
p.add_argument("--unsigned", action="store_true", help="offset binary centred at mid scale, as the ADC drives the SPI")
args = p.parse_args()

if not 4 <= args.bits <= 16:
    p.error("bits must be between 4 and 16")

fullScale = 2**(args.bits - 1) - 1
midScale = 2**(args.bits - 1)
digits = -(-args.bits // 4)

if args.unsigned:
    code = lambda x: (np.clip(np.round(x * fullScale), -fullScale, fullScale) + midScale).astype(int)
else:
    code = lambda x: np.clip(np.round(x * fullScale), -fullScale, fullScale).astype(int) & (2**args.bits - 1)

t = np.arange(args.samples) / args.fs
re = args.amp * np.sin(2 * np.pi * args.sinFreq * t)
im = args.amp * np.cos(2 * np.pi * args.cosFreq * t)

np.savetxt("inputsRE.hex", code(re), fmt=f"%0{digits}X")
np.savetxt("inputsIM.hex", code(im), fmt=f"%0{digits}X")

print(f"{args.samples} samples @ {args.fs} Hz, {args.bits}-bit {'offset binary' if args.unsigned else 'signed Q1.' + str(args.bits - 1)}")
print(f"  -> inputsRE.hex (sin {args.sinFreq} Hz), inputsIM.hex (cos {args.cosFreq} Hz)")
for i, (a, b) in enumerate(zip(re, im)):
    print(f"  {i:2d}  t={t[i]:.4f}  re={a:+.4f} ({code(a):0{digits}X})  im={b:+.4f} ({code(b):0{digits}X})")
