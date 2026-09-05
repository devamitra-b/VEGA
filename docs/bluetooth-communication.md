# Bluetooth communication

This document describes the Bluetooth / BLE design considerations for the VegaThan project and recommended implementation patterns.

## Roles
- ETS IoT Sender: BLE Peripheral (advertise and expose a characteristic with telemetry)
- Vega Receiver: BLE Central (scan, connect, read/subscribe to characteristic)

## Data format
- Use a compact JSON or binary TLV format. Example JSON:

```json
{"node_id":"NODE_01","voltage":230.5,"current":2.3,"power":420.5,"ts":"2026-08-29T12:34:56Z"}
```

## Connection strategy
- Advertise from the sensor node with a unique name (e.g. VEGA_NODE_01).
- The receiver scans for known names or UUIDs and connects.
- Use notification/indications for telemetry push from peripheral to central.

## Error handling
- Implement reconnection logic and exponential backoff.
- Heartbeat messages or keepalive counters help detect stale connections.

## Security (prototype)
- BLE pairing and bonding can be considered later. Keep data short and avoid sending sensitive info in plaintext unless the network is trusted.

TODO
- Add example Arduino/ESP32 BLE peripheral and central code snippets.
