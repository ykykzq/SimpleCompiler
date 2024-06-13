#!/bin/bash

# 源文件夹路径
SOURCE_DIR="."

# 目标文件夹路径
DEST_DIR="./source"

# 创建目标文件夹（如果不存在）
mkdir -p "$DEST_DIR"

# 复制源文件夹下的所有文件和文件夹到目标文件夹
cp -r "$SOURCE_DIR"/* "$DEST_DIR"

# 删除目标文件夹中除了 .h、.cpp、.I、.y 之外的文件
find "$DEST_DIR" -type f ! \( -name "*.h" -o -name "*.cpp" -o -name "*.I" -o -name "*.y" \) -delete

# 删除目标文件夹下的tests文件夹
rm -rf "$DEST_DIR/tests"

# 删除目标文件夹下的tests文件夹
rm -rf "$DEST_DIR/cmake-build-debug"

# 压缩目标文件夹为 zip 格式
zip -r "${DEST_DIR}.zip" "$DEST_DIR"

# 删除目标文件夹
rm -rf "$DEST_DIR"

echo "文件夹已成功复制、清理并压缩为 ${DEST_DIR}.zip"