#!/bin/bash
set -e

/usr/sbin/sshd -D &

echo "=== Linux SSH container ready ==="
if command -v ip >/dev/null 2>&1; then
    echo "Container IP: $(ip -4 addr show scope global 2>/dev/null | awk '/inet / {print $2}' | cut -d/ -f1 | head -n 1)"
fi
if command -v hostname >/dev/null 2>&1; then
    echo "Hostname: $(hostname)"
fi

echo "SSH login: ssh dev@<container-ip> -p 2222"
echo "Default password: password123"

tail -f /dev/null
