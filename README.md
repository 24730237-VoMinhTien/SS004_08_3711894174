# 📘 Tài liệu Kỹ thuật Game Rắn Săn Mồi (JavaScript/HTML5 Canvas)

## I. Giới thiệu
**Snake Game** là một trò chơi cổ điển được xây dựng trên nền tảng **HTML5**, **CSS**, và **JavaScript**. Trò chơi sử dụng **Canvas** để vẽ các đối tượng và **JavaScript** để xử lý logic trò chơi. Người chơi điều khiển con rắn ăn thức ăn, và tránh va vào tường hoặc cơ thể của chính mình.

Trò chơi chạy theo **game loop** liên tục: nhận input → cập nhật trạng thái rắn/mồi → vẽ lại giao diện.

---

## II. Cấu trúc mã nguồn
- **index.html**: Cấu trúc HTML cơ bản của trang web, bao gồm canvas để vẽ trò chơi và các phần tử như nút reset và điểm số.  
- **style.css**: Các quy tắc CSS để tạo kiểu cho giao diện trò chơi.  
- **index.js**: JavaScript để xử lý logic trò chơi, bao gồm việc di chuyển rắn, tạo thức ăn, kiểm tra va chạm và xử lý các sự kiện.

---

## III. Cấu trúc dữ liệu và biến toàn cục

- **gameBoard**: Tham chiếu đến phần tử canvas để vẽ trò chơi.
- **ctx**: Ngữ cảnh vẽ 2D của canvas.
- **scoreText**: Phần tử chứa điểm số.
- **resetBtn**: Nút reset trò chơi.
- **xVelocity, yVelocity**: Vận tốc của con rắn theo chiều ngang và chiều dọc.
- **foodX, foodY**: Tọa độ của mồi.
- **score**: Điểm của trò chơi.
- **snake**: Mảng chứa các phần của thân rắn, mỗi phần có tọa độ `x` và `y`.

---

## IV. Các nhóm hàm chính

### 1. **Giao diện trò chơi (index.js)**

- `clearBoard()`
- `drawFood()`
- `drawSnake()`
- `displayGameOver()`

### 2. **Quản lý điều khiển (index.js)**

- `changeDirection(event)`

### 3. **Menu & Vòng lặp chính (index.js)**

- `showMenu()`
- `gameStart()`
- `nextTick()`

### 4. **Hàm xử lý rắn (index.js)**

- `moveSnake()`
- `checkGameOver()`
- `resetGame()`

---

## V. Quy trình kiểm thử

1. **Va chạm tường**: Đảm bảo rằng rắn không đi ra ngoài biên giới của trò chơi và trò chơi kết thúc khi rắn va chạm với biên.
2. **Cắn thân**: Kiểm tra tính năng kiểm tra va chạm giữa đầu rắn và các đoạn thân rắn.
3. **Ăn mồi**: Khi con rắn ăn mồi, nó sẽ dài thêm một đoạn và điểm số tăng lên.
4. **Tốc độ**: Kiểm tra sự thay đổi tốc độ của rắn khi chơi ở các cấp độ khác nhau.
5. **Hiển thị**: Đảm bảo rằng các đối tượng như khung, điểm số, rắn, và mồi được vẽ chính xác.
6. **Menu**: Kiểm tra tính năng di chuyển trong menu và đảm bảo rằng người chơi có thể bắt đầu trò chơi hoặc thoát ra.

---

## VI. Các cải tiến và mở rộng

- **Tốc độ thay đổi**: Bạn có thể thêm tính năng thay đổi tốc độ rắn dựa trên cấp độ, giúp trò chơi thêm thử thách.
- **Âm thanh**: Thêm âm thanh khi ăn mồi, thắng cuộc hoặc thua cuộc để làm cho trò chơi thêm phần thú vị.
- **Chế độ nhiều người chơi**: Bạn có thể mở rộng trò chơi để hỗ trợ nhiều người chơi điều khiển các con rắn khác nhau.

