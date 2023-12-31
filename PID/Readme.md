## C++でのPIDコントローラの使い方

### インスタンスの生成

最初に、PIDクラスのインスタンスを生成します。これには、PIDゲイン（`kp`、`ki`、`kd`）を引数として渡します。

```cpp
PID pidController(1.0, 0.1, 0.01);
```

### 内部状態のリセット

PID制御を開始する前や、必要に応じて内部状態（積分項や前回の値）をリセットすることがあります。これは`reset`メソッドで行います。<br>
特に、入力値が不連続の場合(内部処理での値の変更など)がある場合は値が発散する可能性があります。そのような場合はリセットしてください。

```cpp
pidController.reset();
```

### PID制御出力の計算

制御対象からのフィードバック値（`value`）を用いて、PID制御出力を計算します。これは`control`メソッドで行います。

```cpp
float value = 1.0;  // 実際のフィードバック値に置き換えてください
float output = pidController.control(value);
```

`output`には、計算されたPID制御出力が格納されます。これを制御対象に適用してください。
