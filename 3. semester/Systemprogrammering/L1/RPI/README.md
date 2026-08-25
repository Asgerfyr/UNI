# Headless Linux SSH Container

This setup starts a minimal Debian Linux container without a desktop environment and exposes SSH on port `2222`.

## Start the container

```bash
docker compose up --build -d
```

## Show the container IP / connection info

```bash
docker compose logs headless-linux
```

The logs print the container IP and SSH details.

## Connect from the host

```bash
ssh dev@localhost -p 2222
```

Default password:

```bash
password123
```

You can also connect by the container IP shown in the logs:

```bash
ssh dev@<container-ip> -p 2222
```

## Stop the container

```bash
docker compose down
```

## Useful note

The container is headless on purpose, so there is no desktop environment. It is intended for shell access and command-line work only.
