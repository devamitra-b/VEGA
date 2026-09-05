# Cloud communication

This page outlines recommended approaches to forward aggregated data from the central node to a cloud service.

## Transport options
- MQTT: lightweight publish/subscribe; good for time-series ingestion.
- REST API (HTTPS): simple and easy to integrate with many backends.
- WebSocket: if real-time two-way communication is required.

## Suggested architecture
- Central node acts as an MQTT client (or pushes via HTTPS) to a broker or API.
- Cloud components ingest and persist data into a time-series database (InfluxDB, TimescaleDB) or generic DB (Postgres) depending on analytics needs.
- Backend offers an authenticated API used by GlowGrid to fetch current and historical data.

## Security
- Use TLS for connections (MQTT over TLS or HTTPS).
- Use token-based authentication (JWT or API keys) for device and dashboard access.

## Example payload (MQTT JSON)
```json
{"topic":"vega/node/NODE_01/telemetry","payload":{"voltage":230.5,"current":2.3,"power":420.5,"ts":"2026-08-29T12:34:56Z"}}
```
TODO
- Add example cloud receiver (small Node.js express + MQTT bridge) under `examples/` in a future PR.
