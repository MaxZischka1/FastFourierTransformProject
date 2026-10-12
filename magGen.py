import argparse

N = 16

def toInt16(x):
    x &= 0xFFFF
    return x - 0x10000 if x & 0x8000 else x

def toInt32(x):
    x &= 0xFFFFFFFF
    return x - 0x100000000 if x & 0x80000000 else x

def readHex(path):
    with open(path) as f:
        return [toInt16(int(line, 16)) for line in f if line.strip()]

def fft(inRe, inIm, wRe, wIm):
    re = list(inRe)
    im = list(inIm)
    i = N
    while i >= 2:
        half = i // 2
        for k in range(0, N, i):
            for j in range(half):
                index = j * (N // i)
                addRe = toInt16((re[k+j] + re[k+j+half]) >> 1)
                addIm = toInt16((im[k+j] + im[k+j+half]) >> 1)
                subRe = toInt16((re[k+j] - re[k+j+half]) >> 1)
                subIm = toInt16((im[k+j] - im[k+j+half]) >> 1)
                if i == 2:
                    multRe, multIm = subRe, subIm
                elif i == 4:
                    if index == 0:
                        multRe, multIm = subRe, subIm
                    else:
                        multRe, multIm = subIm, toInt16(-subRe)
                else:
                    multRe = toInt16(toInt32(subRe*wRe[index] - subIm*wIm[index]) >> 15)
                    multIm = toInt16(toInt32(subRe*wIm[index] + subIm*wRe[index]) >> 15)
                re[k+j], im[k+j] = addRe, addIm
                re[k+j+half], im[k+j+half] = multRe, multIm
        i //= 2
    return re, im

p = argparse.ArgumentParser(description="Run the fixed point FFT model and write its outputs as magToBin stimulus")
p.add_argument("--inRe", default="inputsRE.hex", help="FFT real input samples (default inputsRE.hex)")
p.add_argument("--inIm", default="inputsIM.hex", help="FFT imaginary input samples (default inputsIM.hex)")
p.add_argument("--wRe", default="twiddleRE.hex", help="twiddle real values (default twiddleRE.hex)")
p.add_argument("--wIm", default="twiddleIM.hex", help="twiddle imaginary values (default twiddleIM.hex)")
p.add_argument("--outRe", default="fftOutRE.hex", help="generated real stimulus (default fftOutRE.hex)")
p.add_argument("--outIm", default="fftOutIM.hex", help="generated imaginary stimulus (default fftOutIM.hex)")
args = p.parse_args()

inRe = readHex(args.inRe)
inIm = readHex(args.inIm)
wRe = readHex(args.wRe)
wIm = readHex(args.wIm)

if len(inRe) != N or len(inIm) != N:
    raise SystemExit(f"need {N} samples, got {len(inRe)} in {args.inRe} and {len(inIm)} in {args.inIm}")
if len(wRe) != N//2 or len(wIm) != N//2:
    raise SystemExit(f"need {N//2} twiddles, got {len(wRe)} in {args.wRe} and {len(wIm)} in {args.wIm}")

outRe, outIm = fft(inRe, inIm, wRe, wIm)

with open(args.outRe, "w") as f:
    f.write("".join(f"{v & 0xFFFF:04X}\n" for v in outRe))
with open(args.outIm, "w") as f:
    f.write("".join(f"{v & 0xFFFF:04X}\n" for v in outIm))

print(f"{N} FFT outputs from {args.inRe}, {args.inIm}, {args.wRe}, {args.wIm}  ->  {args.outRe}, {args.outIm}")
for n, (a, b) in enumerate(zip(outRe, outIm)):
    print(f"  {n:2d}  re={a & 0xFFFF:04X} ({a:+6d})  im={b & 0xFFFF:04X} ({b:+6d})")
