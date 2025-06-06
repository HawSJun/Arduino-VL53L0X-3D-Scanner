import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv(r"c:\Source\Arduino-VL53L0X-3D-Scanner\1일차\pwm_servo_log.csv")

plt.style.use("ggplot")
plt.figure(figsize=(12, 6))

plt.plot(df["Angle"], df["X_pos"], label="X Servo", color='blue', linewidth=2, marker='o', markevery=10)
plt.plot(df["Angle"], df["Y_pos"], label="Y Servo", color='red', linewidth=2, marker='x', markevery=10)

plt.title("Servo PWM Pulse vs Angle", fontsize=16)
plt.xlabel("Angle (Degrees)", fontsize=12)
plt.ylabel("PWM Pulse Value", fontsize=12)

plt.legend(fontsize=12)
plt.grid(True, linestyle='--', alpha=0.5)
plt.tight_layout()
plt.show()
