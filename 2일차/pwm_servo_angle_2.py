import pandas as pd
import matplotlib.pyplot as plt

csv_file = r"c:\Source\Arduino-VL53L0X-3D-Scanner\2일차\pwm_servo_log_2.csv"

df = pd.read_csv(csv_file)

# 그래프
plt.figure(figsize=(10, 6))
plt.plot(df['time_ms'], df['x_angle'], label='X Axis (CH 0)')
plt.plot(df['time_ms'], df['y_angle'], label='Y Axis (CH 1)', linestyle='--')

plt.title("Servo Motor Movement Over Time")
plt.xlabel("Time (ms)")
plt.ylabel("Angle (degrees)")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.show()
