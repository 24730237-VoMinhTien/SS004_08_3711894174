# 📘 Tài liệu Kỹ thuật Game Rắn Săn Mồi (JavaScript/HTML5 Canvas)

## I. Giới thiệu
**Game Rắn Săn Mồi** là một trò chơi cổ điển phổ biến, được xây dựng trên nền tảng **HTML5**, **CSS** và **JavaScript**. Trò chơi sử dụng **Canvas** để vẽ các đối tượng như rắn, mồi và nền, đồng thời xử lý các thao tác của người chơi như điều hướng rắn. Trong game, người chơi điều khiển con rắn để ăn mồi, mỗi lần ăn sẽ làm rắn dài ra, đồng thời tránh va vào tường hoặc chính thân mình.

Game hoạt động theo vòng lặp (game loop): nhận lệnh điều khiển → cập nhật trạng thái → vẽ lại giao diện.

https://github.com/24730237-VoMinhTien/SS004_08_3711894174/blob/PhuNam/GiaoDien/image/img2.jpg
---

## II. Cấu trúc mã nguồn
- **index.html**: Giao diện chính, chứa phần canvas để vẽ game, cùng các nút và hiển thị điểm số.
- **style.css**: Các quy tắc CSS để bố trí, định dạng giao diện cho dễ nhìn và thân thiện.
- **index.js**: Các đoạn mã JavaScript chính để điều khiển game, xử lý chuyển động, tạo mồi, kiểm tra va chạm và các chức năng khác.

---

## III. Các biến và cấu trúc dữ liệu chính

- **gameBoard**: Tham chiếu đến phần tử `<canvas>` để vẽ game.
- **ctx**: Ngữ cảnh vẽ 2D của canvas.
- **scoreText**: Phần tử hiển thị điểm số.
- **resetBtn**: Nút để bắt đầu lại game.
- **xVelocity, yVelocity**: Vận tốc của rắn theo trục X và Y.
- **foodX, foodY**: Vị trí của mồi trên bàn chơi.
- **score**: Điểm số của người chơi.
- **snake**: Mảng chứa các phần của thân rắn, mỗi phần có tọa độ `x`, `y`.

---

## IV. Các hàm chính trong mã

### 1. Giao diện và vẽ trò chơi
- `clearBoard()`: Xóa phần vẽ cũ để chuẩn bị vẽ mới.
- `drawFood()`: Vẽ mồi trên canvas.
- `drawSnake()`: Vẽ rắn theo các phần của nó.
- `displayGameOver()`: Hiện thông báo kết thúc trò chơi khi thua.

### 2. Điều khiển và phản hồi
- `changeDirection(event)`: Xử lý sự kiện bàn phím để đổi hướng di chuyển của rắn.

### 3. Quản lý vòng lặp và trạng thái game
- `showMenu()`: Hiển thị màn hình giới thiệu hoặc menu chính.
- `gameStart()`: Khởi động trò chơi.
- `nextTick()`: Hàm chạy liên tục theo chu kỳ, cập nhật trạng thái và vẽ lại.

### 4. Quản lý rắn
- `moveSnake()`: Tính toán vị trí mới của rắn dựa trên hướng di chuyển.
- `checkGameOver()`: Kiểm tra xem rắn có va vào tường hoặc chính thân không.
- `resetGame()`: Khởi động lại trạng thái ban đầu của game.

---

## V. Các bước kiểm thử chính

1. **Va chạm tường**: Đảm bảo trò chơi kết thúc khi rắn chạm biên giới.
2. **Va chạm thân**: Kiểm tra khả năng phát hiện va chạm của đầu rắn với các phần thân.
3. **Ăn mồi**: Khi rắn ăn mồi, rắn dài ra và điểm số tăng.
4. **Tốc độ**: Thử điều chỉnh tốc độ để kiểm tra độ khó.
5. **Vẽ đúng**: Đảm bảo các đối tượng được vẽ chính xác, rõ ràng.
6. **Giao diện**: Kiểm tra menu, nút bấm, hiển thị điểm số, trạng thái trò chơi.

---

## VI. Các ý tưởng mở rộng và nâng cao

- **Thay đổi tốc độ**: Tăng dần tốc độ rắn theo điểm hoặc cấp độ.
- **Âm thanh**: Thêm các hiệu ứng âm thanh khi ăn mồi, va chạm hoặc chiến thắng.
- **Chế độ nhiều người chơi**: Mở rộng để nhiều người cùng chơi, điều khiển nhiều rắn khác nhau.!
