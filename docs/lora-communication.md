# LoRa communication

This document provides guidance for using LoRa radios in the VegaThan project. It distinguishes between raw LoRa (simple radio packets) and LoRaWAN (protocol stack) and recommends best practices for prototypes.

## Key concepts
- Frequency bands: use region-appropriate frequencies (e.g., 868MHz EU, 915MHz US, 433MHz in some regions).
- Spreading factor, bandwidth, and coding rate determine range and airtime.
- Node IDs: each sensor node must include a unique identifier.

## Raw LoRa vs LoRaWAN
- Raw LoRa: point-to-point packets between nodes and a gateway. Simpler for prototypes.
- LoRaWAN: stack with network/server infrastructure; useful when scaling with public/managed networks.

## Example packet format (JSON)
```json
{"node_id":"NODE_01","voltage":230.5,"current":2.3,"power":420.5,"ts":"2026-08-29T12:34:56Z"}
```

## Troubleshooting
- Ensure both endpoints are configured for same frequency and parameters.
- Watch for packet collisions and airtime limits.
- Use CRC and simple sequence numbers to detect packet loss or duplication.

TODO
- Add example sketches using SX1276 and Ebyte modules, including wiring and serial debug.
