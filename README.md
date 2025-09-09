# Rắn săn mồi - Nhóm 8

## Quy trình làm việc với các nhánh

### Các nhánh hiện có:
- **main**: Nhánh chính.
- **PhuNam/GiaoDien**: Nhánh giao diện do Phú Nam phát triển.
- **ChauGiang/ChucNang**: Nhánh chức năng do Châu Giang phát triển.
- **DucAnh/ChucNang**: Nhánh chức năng do Đức Anh phát triển.
- **MinhTien/ChucNang**: Nhánh chức năng do Minh Tiến phát triển.

### Hướng dẫn merge và xử lý conflict:
1. **Chuyển sang nhánh `main`:**
    ```bash
    git checkout main
    ```

2. **Merge nhánh cần thiết vào `main`:**
    ```bash
    git merge <tên_nhánh>
    ```
    - Nếu có conflict, mở các file bị conflict, chỉnh sửa và giải quyết xung đột.
    - Sau khi xử lý xong, đánh dấu conflict đã được giải quyết:

    ```bash
    git add <file_bị_conflict>
    ```
    - Hoàn tất merge:

    ```bash
    git commit
    ```

3. **Cập nhật nhánh làm việc với thay đổi từ `main`:**
    ```bash
    git checkout <tên_nhánh_làm_việc>
    git pull origin main
    ```

### Lưu ý:
- Luôn kiểm tra trạng thái nhánh trước khi thực hiện các thao tác:
  ```bash
  git status
  ```
- Đảm bảo code được kiểm tra kỹ trước khi merge vào `main`.
- Thường xuyên cập nhật nhánh làm việc với nhánh `main` để tránh xung đột lớn.
