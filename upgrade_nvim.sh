#!/usr/bin/env bash

set -e

# 检查当前 nvim 版本
if command -v nvim >/dev/null 2>&1; then
    CURRENT_VERSION=$(nvim --version | head -n 1 | awk '{print $2}')
    echo "当前 Neovim 版本: $CURRENT_VERSION"
else
    echo "未检测到已安装的 Neovim"
    CURRENT_VERSION="0.0.0"
fi

# 版本比较函数
version_lt() {
    [ "$(printf '%s\n' "$1" "$2" | sort -V | head -n1)" != "$2" ]
}

# 如果版本 < 0.12，则升级
if version_lt "$CURRENT_VERSION" "0.12.0"; then
    echo "正在升级 Neovim 到最新版本..."

    # 下载最新的 Linux 64 位预编译包
    wget -q https://github.com/neovim/neovim/releases/latest/download/nvim-linux64.tar.gz -O /tmp/nvim-linux64.tar.gz

    # 解压并安装到 /opt/nvim
    sudo rm -rf /opt/nvim
    sudo tar xzvf /tmp/nvim-linux64.tar.gz -C /opt/

    # 建立软链接
    sudo ln -sf /opt/nvim-linux64/bin/nvim /usr/local/bin/nvim

    echo "Neovim 已升级完成 ✅"
else
    echo "Neovim 已经是 0.12 或更高版本，无需升级 ✅"
fi

# 显示最终版本
nvim --version | head -n 1
