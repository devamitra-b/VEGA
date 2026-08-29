# GlowGrid Dashboard

GlowGrid is the web-based PWA dashboard used to view telemetry and device status.

## Roles
- Patrol: simplified UI focused on device status, area maps, and alerts.
- Electrician: detailed technical view with electrical parameters and maintenance tools.

## Features
- Real-time telemetry (voltage, current, power, energy, frequency, power factor).
- Offline map support (Leaflet / cached tiles) and node mapping.
- Role-based entry: user chooses Patrol or Electrician on login.
- Theme system, alerting, and simple maintenance workflows.

## Current status
- Prototype: a single-file PWA exists at `web-dashboard/glowgrid-pwa/index.html`.

## Next steps / TODO
- Split the single-file PWA into `css/`, `js/`, and `assets/` for maintainability.
- Add API hooks to a cloud backend for live telemetry.
- Add proper SVG icons and brand assets under `assets/icons/`.
