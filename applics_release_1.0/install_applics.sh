#!/bin/bash
set -e

if [ "$EUID" -ne 0 ]; then
  echo "Запустите через sudo: sudo ./install_applics.sh"
  exit 1
fi

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"

install -m 755 "$SCRIPT_DIR/applics" /usr/local/bin/applics

echo "Готово: /usr/local/bin/applics"
echo "Проверьте: applics"
