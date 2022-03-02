# Micropython for OWL

The micropython interpreter is compiled into an OWL patch, which is loaded on the OWL hardware.
Then text is exchanged with the REPL over MIDI SysEx messages.
This is typically done through a webmidi page, so that you have a textbox for writing in.

## Hardware Access

There's an `owl` package available that provides access to (some) hardware functions. This is very much work-in-progress. 

Current draft interface:
```
import owl
owl.print(text, x, y)
owl.print(text, y)
owl.print(text)
owl.plot(x, y) # set pixel
owl.plot(x, y, colour) # set pixel to colour (0 or 1 for monochrome screens)
owl.parameter(id) # get parameter value
owl.parameter(id, value) # set parameter value (number or boolean)
owl.parameter(id, iterator) # set parameter with iterator (at block rate)
owl.button(id) # get button value
owl.button(id, value) # set button value (number or boolean)
owl.input(ch); // get sample value
owl.output(ch, value) # set DC audio output value
owl.output(ch, iterator) # set audio output with iterator (at audio rate)
owl.SR # sample rate constant
owl.BR # block rate constant
owl.BS # block size constant
```

## Examples

Example sawtooth oscillator:
```
freq = 440
gain = 0.5
def saw():
 ph = 0
 while True:
  yield ph*gain
  ph += (2 * freq) / 48000
  if ph >= 1:
   ph -= 2
owl.output(0, saw()) # assign iterator to first output channel
```
In this example, the freq and gain variables can be changed on-the-fly from the REPL.

Also compiled in is [math](https://docs.circuitpython.org/en/latest/shared-bindings/math/index.html) and [ulab](https://docs.circuitpython.org/en/latest/shared-bindings/ulab/).

Output audio using an iterator over an array:
```
def cycle(p):
    try:
        len(p)
    except TypeError:
        cache = []
        for i in p:
            yield i
            cache.append(i)
        p = cache
    while p:
        yield from p
freq = 440
len = int(48000/freq)
a = [math.sin(2 * math.pi * x / len) for x in range(0, len)]
owl.output(0, cycle(a))
```

or, using `ulab`:
```
from ulab import numpy as np
a = np.array(range(1000))/1000 - 1
owl.output(0, cycle(a))
```

## Building
To build with ulab, which adds about 90k to binary:
```
make clean && make USER_C_MODULES=../../../ulab CROSS=1 staticlib
```
Install with:
```
cp build/libmicropython-*.a Somewhere/OwlProgram/Libraries/
```
Then build MicroPythonPatch, e.g. with:

```
make PATCHSOURCE=SomeWhere/micropython/owl PATCHNAME=MicroPython clean
```

## Examples

### Sawtooth Oscillator

```
freq = 440
gain = 0.5
def saw():
 ph = 0
 while True:
  yield ph*gain
  ph += (2 * freq) / 48000
  if ph >= 1:
   ph -= 2
owl.output(0, saw())
```

### Table Oscillator

```
def cycle(p):
    try:
        len(p)
    except TypeError:
        cache = []
        for i in p:
            yield i
            cache.append(i)
        p = cache
    while p:
        yield from p
freq = 440
len = int(48000/freq) # length of a single cycle
a = [math.sin(2 * math.pi * x / len) for x in range(0, len)]
owl.output(0, cycle(a))
```

Using ulab to create a sawtooth oscillator:

```
from ulab import numpy as np

a = np.array(range(1000))/1000 - 1
owl.output(0, cycle(a))
```

### Audio Gain Control

```
def attenuator(ch, gain):
 while True:
  yield owl.input(ch)*gain

owl.output(0, attenuator(0, 0.5))
```

### Screen

```
owl.clear()
for i in range(0, 60, 6):
  owl.print("yo", i*2, i+8)
```

```
import random
owl.clear()
owl.draw(10, 10, 118, 10)
owl.draw(10, 60, 118, 60)
owl.draw(10, 10, 10, 60)
owl.draw(118, 10, 118, 60)
for i in range(1000):
  owl.plot(random.randint(10, 118), random.randint(10, 60))
```
