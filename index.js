class SnakeGame {
    constructor(gameBoard, scoreText, resetBtn) {
        this.gameBoard = gameBoard;
        this.ctx = gameBoard.getContext("2d");
        this.scoreText = scoreText;
        this.resetBtn = resetBtn;

        this.gameWidth = gameBoard.width;
        this.gameHeight = gameBoard.height;

        this.boardBackground = "white";
        this.snakeColor = "lightgreen";
        this.snakeBorder = "black";
        this.foodColor = "red";
        this.unitSize = 25;

        this.xVelocity = this.unitSize;
        this.yVelocity = 0;
        this.foodX;
        this.foodY;
        this.score = 0;
        this.snake = [
            // Kích thước ban đầu
            { x: this.unitSize * 4, y: 0 },
            { x: this.unitSize * 3, y: 0 },
            { x: this.unitSize * 2, y: 0 },
            { x: this.unitSize, y: 0 },
            { x: 0, y: 0 }
        ];

        this.running = false;

        window.addEventListener("keydown", this.changeDirection.bind(this));
        this.resetBtn.addEventListener("click", this.resetGame.bind(this));
    }

    gameStart() {
        this.running = true;
        this.scoreText.textContent = this.score;
        this.createFood();
        this.drawFood();
        this.nextTick();
    }

    nextTick() {
        if (this.running) {
            setTimeout(() => {
                this.clearBoard();
                this.drawFood();
                this.moveSnake();
                this.drawSnake();
                this.checkGameOver();
                this.nextTick();
            }, 75);
        } else {
            this.displayGameOver();
        }
    }

    clearBoard() {
        this.ctx.fillStyle = this.boardBackground;
        this.ctx.fillRect(0, 0, this.gameWidth, this.gameHeight);
    }

    createFood() {
        const randomFood = (min, max) => {
            const randNum = Math.round((Math.random() * (max - min) + min) / this.unitSize) * this.unitSize;
            return randNum;
        }
        this.foodX = randomFood(0, this.gameWidth - this.unitSize);
        this.foodY = randomFood(0, this.gameHeight - this.unitSize);
    }

    drawFood() {
        this.ctx.fillStyle = this.foodColor;
        this.ctx.fillRect(this.foodX, this.foodY, this.unitSize, this.unitSize);
    }

    moveSnake() {
        const head = { x: this.snake[0].x + this.xVelocity, y: this.snake[0].y + this.yVelocity };
        this.snake.unshift(head);

        if (this.snake[0].x == this.foodX && this.snake[0].y == this.foodY) {
            this.score += 1;
            this.scoreText.textContent = this.score;
            this.createFood();
        } else {
            this.snake.pop();
        }
    }

    drawSnake() {
        this.ctx.fillStyle = this.snakeColor;
        this.ctx.strokeStyle = this.snakeBorder;
        this.snake.forEach(snakePart => {
            this.ctx.fillRect(snakePart.x, snakePart.y, this.unitSize, this.unitSize);
            this.ctx.strokeRect(snakePart.x, snakePart.y, this.unitSize, this.unitSize);
        });
    }

    changeDirection(event) {
        const keyPressed = event.key;
        const LEFT = 'a';
        const UP = 'w';
        const RIGHT = 'd';
        const DOWN = 's';

        const goingUp = (this.yVelocity == -this.unitSize);
        const goingDown = (this.yVelocity == this.unitSize);
        const goingRight = (this.xVelocity == this.unitSize);
        const goingLeft = (this.xVelocity == -this.unitSize);

        switch (true) {
            case (keyPressed == LEFT && !goingRight):
                this.xVelocity = -this.unitSize;
                this.yVelocity = 0;
                break;
            case (keyPressed == UP && !goingDown):
                this.xVelocity = 0;
                this.yVelocity = -this.unitSize;
                break;
            case (keyPressed == RIGHT && !goingLeft):
                this.xVelocity = this.unitSize;
                this.yVelocity = 0;
                break;
            case (keyPressed == DOWN && !goingUp):
                this.xVelocity = 0;
                this.yVelocity = this.unitSize;
                break;
        }
    }

    checkGameOver() {
        switch (true) {
            case (this.snake[0].x < 0):
            case (this.snake[0].x >= this.gameWidth):
            case (this.snake[0].y < 0):
            case (this.snake[0].y >= this.gameHeight):
                this.running = false;
                break;
        }

        for (let i = 1; i < this.snake.length; i++) {
            if (this.snake[i].x == this.snake[0].x && this.snake[i].y == this.snake[0].y) {
                this.running = false;
            }
        }
    }

    displayGameOver() {
        this.ctx.font = "50px MV Boli";
        this.ctx.fillStyle = "black";
        this.ctx.textAlign = "center";
        this.ctx.fillText("GAME OVER!", this.gameWidth / 2, this.gameHeight / 2);
        this.running = false;
    }

    resetGame() {
        this.score = 0;
        this.xVelocity = this.unitSize;
        this.yVelocity = 0;
        this.snake = [
            { x: this.unitSize * 4, y: 0 },
            { x: this.unitSize * 3, y: 0 },
            { x: this.unitSize * 2, y: 0 },
            { x: this.unitSize, y: 0 },
            { x: 0, y: 0 }
        ];
        this.gameStart();
    }

    showMenu() {
        const menu = document.getElementById('menu');
        const startBtn = document.getElementById('startBtn');
        const quitBtn = document.getElementById('quitBtn');

        startBtn.addEventListener('click', () => {
            menu.style.display = 'none';
            document.getElementById('gameBoard').style.display = 'block';
            document.getElementById('scoreText').style.display = 'block';
            document.getElementById('resetBtn').style.display = 'block';
            this.gameStart();
        });

        quitBtn.addEventListener('click', () => {
            window.close();
        });
    }
}

const gameBoard = document.querySelector("#gameBoard");
const scoreText = document.querySelector("#scoreText");
const resetBtn = document.querySelector("#resetBtn");
const game = new SnakeGame(gameBoard, scoreText, resetBtn);

game.showMenu();
