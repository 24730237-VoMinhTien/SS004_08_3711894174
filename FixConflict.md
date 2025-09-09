# Rắn Săn Mồi - Nhóm 8

## Quy Trình Làm Việc Với Các Nhánh

### 1. Các Nhánh Hiện Có
- **main**: Nhánh chính.
- **PhuNam/GiaoDien**: Nhánh giao diện do Phú Nam phát triển.
- **ChauGiang/ChucNang**: Nhánh chức năng do Châu Giang phát triển.
- **DucAnh/ChucNang**: Nhánh chức năng do Đức Anh phát triển.
- **MinhTien/ChucNang**: Nhánh chức năng do Minh Tiến phát triển.

---

### 2. Hướng Dẫn Merge Và Xử Lý Conflict

#### Bước 1: Chuyển Sang Nhánh `main`
```bash
git checkout main
```

#### Bước 2: Merge Nhánh `ChauGiang/ChucNang` Vào `main`
```bash
git merge ChauGiang/ChucNang
```
- Nếu có conflict:
    - Mở các file bị conflict, chỉnh sửa và giải quyết xung đột.
    - Đánh dấu conflict đã được giải quyết:
        ```bash
        git add <file_bị_conflict>
        ```
    - Hoàn tất merge:
        ```bash
        git commit
        ```

#### Bước 3: Cập Nhật Nhánh `PhuNam/GiaoDien` Với Thay Đổi Từ `main`
```bash
git checkout PhuNam/GiaoDien
git pull origin main
```

---

### 3. Lưu Ý
- Luôn kiểm tra trạng thái nhánh trước khi thực hiện các thao tác:
    ```bash
    git status
    ```
- Đảm bảo code được kiểm tra kỹ trước khi merge vào `main`.
- Thường xuyên cập nhật nhánh làm việc với nhánh `main` để tránh xung đột lớn.

---