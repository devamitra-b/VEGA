# PZEM-004T v3.0

This document explains how to connect and test the PZEM-004T energy meter.

## Measured parameters
- Voltage (V)
- Current (A)
- Power (W)
- Energy (Wh)
- Frequency (Hz)
- Power Factor

## Typical wiring (example)
> WARNING: PZEM must be connected to a live circuit. Take proper safety precautions.

Example connections used in tests (subject to final board pinout):
```
PZEM TX -> GPIO27 (controller RX)
PZEM RX -> GPIO16 (controller TX)
PZEM 5V -> 5V
PZEM GND -> GND
```
Note: UART TX/RX should be crossed (PZEM TX -> MCU RX).

## Example JSON payload
```json
{
  "voltage": 230.5,
  "current": 2.45,
  "power": 450.2,
  "energy": 12.8,
  "frequency": 50.0,
  "powerFactor": 0.98
}
```

## Troubleshooting
- "PZEM communication failed!" — check the wiring, cross TX/RX, ensure common ground, verify power supply.
- Check that the PZEM library matches the module version (v3.0).
- Test with a minimal example sketch that only reads and prints values to serial before integrating communications.

## Safety
- Work on de-energized circuits when possible.
- Use proper insulated probes and follow local electrical safety regulations.

TODO
- Add sample firmware snippets and measured sample output from a working unit.
